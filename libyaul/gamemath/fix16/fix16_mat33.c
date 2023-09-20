/*
 * Copyright (c) 2013-2014
 * See LICENSE for details.
 *
 * Mattias Jansson
 * Israel Jacquez <mrkotfw@gmail.com>
 */

#include <scu/map.h>
#include <string.h>

#include <gamemath/angle.h>
#include <gamemath/fix16/fix16_mat33.h>
#include <gamemath/fix16/fix16_trig.h>

static void _mat33_row_transpose(const fix16_t *arr, fix16_vec3_t *m0);

void
fix16_mat33_zero(fix16_mat33_t *m0)
{
    fix16_t *arr_ptr;
    arr_ptr = m0->arr;

    *arr_ptr++ = FIX16_ZERO;
    *arr_ptr++ = FIX16_ZERO;
    *arr_ptr++ = FIX16_ZERO;
    *arr_ptr++ = FIX16_ZERO;
    *arr_ptr++ = FIX16_ZERO;
    *arr_ptr++ = FIX16_ZERO;
    *arr_ptr++ = FIX16_ZERO;
    *arr_ptr++ = FIX16_ZERO;
    *arr_ptr   = FIX16_ZERO;
}

void
fix16_mat33_identity(fix16_mat33_t *m0)
{
    fix16_t *arr_ptr;
    arr_ptr = m0->arr;

    *arr_ptr++ = FIX16_ONE;  /* M[0,0] (0) */
    *arr_ptr++ = FIX16_ZERO;
    *arr_ptr++ = FIX16_ZERO;
    *arr_ptr++ = FIX16_ZERO;
    *arr_ptr++ = FIX16_ONE;  /* M[1,1] (4) */
    *arr_ptr++ = FIX16_ZERO;
    *arr_ptr++ = FIX16_ZERO;
    *arr_ptr++ = FIX16_ZERO;
    *arr_ptr   = FIX16_ONE;  /* M[2,2] (8) */
}

void
fix16_mat33_dup(const fix16_mat33_t *m0, fix16_mat33_t *result)
{
    const fix16_t *arr_ptr;
    arr_ptr = m0->arr;

    fix16_t *result_arr_ptr;
    result_arr_ptr = result->arr;

    *result_arr_ptr++ = *arr_ptr++;
    *result_arr_ptr++ = *arr_ptr++;
    *result_arr_ptr++ = *arr_ptr++;
    *result_arr_ptr++ = *arr_ptr++;

    *result_arr_ptr++ = *arr_ptr++;
    *result_arr_ptr++ = *arr_ptr++;
    *result_arr_ptr++ = *arr_ptr++;
    *result_arr_ptr++ = *arr_ptr++;

    *result_arr_ptr   = *arr_ptr;
}

void
fix16_mat33_transpose(const fix16_mat33_t * __restrict m0,
    fix16_mat33_t * __restrict result)
{
    result->frow[0][0] = m0->frow[0][0];
    result->frow[0][1] = m0->frow[1][0];
    result->frow[0][2] = m0->frow[2][0];

    result->frow[1][0] = m0->frow[0][1];
    result->frow[1][1] = m0->frow[1][1];
    result->frow[1][2] = m0->frow[2][1];

    result->frow[2][0] = m0->frow[0][2];
    result->frow[2][1] = m0->frow[1][2];
    result->frow[2][2] = m0->frow[2][2];
}

void
fix16_mat33_lookat(const fix16_vec3_t *from, const fix16_vec3_t *to,
    const fix16_vec3_t *up, fix16_mat33_t *result)
{
    /* normalize(forward)
     * right = normalize(cross(forward, up))
     * up = cross(forward, right) */

    fix16_vec3_t * const basis_forward = &result->row[2];
    fix16_vec3_sub(to, from, basis_forward);
    fix16_vec3_normalize(basis_forward);

    fix16_vec3_t * const basis_right = &result->row[0];
    fix16_vec3_cross(basis_forward, up, basis_right);
    fix16_vec3_normalize(basis_right);

    fix16_vec3_t * const basis_up = &result->row[1];
    fix16_vec3_cross(basis_forward, basis_right, basis_up);
    fix16_vec3_normalize(basis_up);
}

void
fix16_mat33_mul(const fix16_mat33_t *m0, const fix16_mat33_t *m1,
    fix16_mat33_t *result)
{
    fix16_vec3_t transposed_row;

    const fix16_vec3_t * const m00 = &m0->row[0];
    const fix16_vec3_t * const m01 = &m0->row[1];
    const fix16_vec3_t * const m02 = &m0->row[2];

    _mat33_row_transpose(&m1->arr[0], &transposed_row);
    result->frow[0][0] = fix16_vec3_dot(m00, &transposed_row);
    result->frow[1][0] = fix16_vec3_dot(m01, &transposed_row);
    result->frow[2][0] = fix16_vec3_dot(m02, &transposed_row);

    _mat33_row_transpose(&m1->arr[1], &transposed_row);
    result->frow[0][1] = fix16_vec3_dot(m00, &transposed_row);
    result->frow[1][1] = fix16_vec3_dot(m01, &transposed_row);
    result->frow[2][1] = fix16_vec3_dot(m02, &transposed_row);

    _mat33_row_transpose(&m1->arr[2], &transposed_row);
    result->frow[0][2] = fix16_vec3_dot(m00, &transposed_row);
    result->frow[1][2] = fix16_vec3_dot(m01, &transposed_row);
    result->frow[2][2] = fix16_vec3_dot(m02, &transposed_row);
}

void
fix16_mat33_vec3_mul(const fix16_mat33_t *m0, const fix16_vec3_t *v,
    fix16_vec3_t *result)
{
    result->x = fix16_vec3_dot(&m0->row[0], v);
    result->y = fix16_vec3_dot(&m0->row[1], v);
    result->z = fix16_vec3_dot(&m0->row[2], v);
}

void
fix16_mat33_x_rotate(const fix16_mat33_t *m0, angle_t angle,
    fix16_mat33_t *result)
{
    fix16_t sin_value;
    fix16_t cos_value;

    fix16_sincos(angle, &sin_value, &cos_value);

    const fix16_t m01 = m0->frow[0][1];
    const fix16_t m02 = m0->frow[0][2];
    const fix16_t m11 = m0->frow[1][1];
    const fix16_t m12 = m0->frow[1][2];
    const fix16_t m21 = m0->frow[2][1];
    const fix16_t m22 = m0->frow[2][2];

    result->frow[0][1] =  fix16_mul(m01, cos_value) + fix16_mul(m02, sin_value);
    result->frow[0][2] = -fix16_mul(m01, sin_value) + fix16_mul(m02, cos_value);

    result->frow[1][1] =  fix16_mul(m11, cos_value) + fix16_mul(m12, sin_value);
    result->frow[1][2] = -fix16_mul(m11, sin_value) + fix16_mul(m12, cos_value);

    result->frow[2][1] =  fix16_mul(m21, cos_value) + fix16_mul(m22, sin_value);
    result->frow[2][2] = -fix16_mul(m21, sin_value) + fix16_mul(m22, cos_value);
}

void
fix16_mat33_y_rotate(const fix16_mat33_t *m0, angle_t angle,
    fix16_mat33_t *result)
{
    fix16_t sin_value;
    fix16_t cos_value;

    fix16_sincos(angle, &sin_value, &cos_value);

    const fix16_t m00 = m0->frow[0][0];
    const fix16_t m02 = m0->frow[0][2];
    const fix16_t m10 = m0->frow[1][0];
    const fix16_t m12 = m0->frow[1][2];
    const fix16_t m20 = m0->frow[2][0];
    const fix16_t m22 = m0->frow[2][2];

    result->frow[0][0] = fix16_mul(m00, cos_value) - fix16_mul(m02, sin_value);
    result->frow[0][2] = fix16_mul(m00, sin_value) + fix16_mul(m02, cos_value);
    result->frow[1][0] = fix16_mul(m10, cos_value) - fix16_mul(m12, sin_value);
    result->frow[1][2] = fix16_mul(m10, sin_value) + fix16_mul(m12, cos_value);
    result->frow[2][0] = fix16_mul(m20, cos_value) - fix16_mul(m22, sin_value);
    result->frow[2][2] = fix16_mul(m20, sin_value) + fix16_mul(m22, cos_value);
}

void
fix16_mat33_z_rotate(const fix16_mat33_t *m0, angle_t angle,
    fix16_mat33_t *result)
{
    fix16_t sin_value;
    fix16_t cos_value;

    fix16_sincos(angle, &sin_value, &cos_value);

    const fix16_t m00 = m0->frow[0][0];
    const fix16_t m01 = m0->frow[0][1];
    const fix16_t m10 = m0->frow[1][0];
    const fix16_t m11 = m0->frow[1][1];
    const fix16_t m20 = m0->frow[2][0];
    const fix16_t m21 = m0->frow[2][1];

    result->frow[0][0] =  fix16_mul(m00, cos_value) + fix16_mul(m01, sin_value);
    result->frow[0][1] = -fix16_mul(m00, sin_value) + fix16_mul(m01, cos_value);
    result->frow[1][0] =  fix16_mul(m10, cos_value) + fix16_mul(m11, sin_value);
    result->frow[1][1] = -fix16_mul(m10, sin_value) + fix16_mul(m11, cos_value);
    result->frow[2][0] =  fix16_mul(m20, cos_value) + fix16_mul(m21, sin_value);
    result->frow[2][1] = -fix16_mul(m20, sin_value) + fix16_mul(m21, cos_value);
}

void
fix16_mat33_rotation_create(angle_t rx, angle_t ry, angle_t rz,
    fix16_mat33_t *result)
{
    fix16_t sx;
    fix16_t cx;

    fix16_sincos(rx, &sx, &cx);

    fix16_t sy;
    fix16_t cy;

    fix16_sincos(ry, &sy, &cy);

    fix16_t sz;
    fix16_t cz;

    fix16_sincos(rz, &sz, &cz);

    const fix16_t sxsy = fix16_mul(sx, sy);
    const fix16_t cxsy = fix16_mul(cx, sy);

    result->frow[0][0] = fix16_mul(   cy, cz);
    result->frow[0][1] = fix16_mul( sxsy, cz) + fix16_mul(cx, sz);
    result->frow[0][2] = fix16_mul(-cxsy, cz) + fix16_mul(sx, sz);
    result->frow[1][0] = fix16_mul(  -cy, sz);
    result->frow[1][1] = fix16_mul(-sxsy, sz) + fix16_mul(cx, cz);
    result->frow[1][2] = fix16_mul( cxsy, sz) + fix16_mul(sx, cz);
    result->frow[2][0] = sy;
    result->frow[2][1] = fix16_mul(  -sx, cy);
    result->frow[2][2] = fix16_mul(   cx, cy);
}

size_t
fix16_mat33_str(const fix16_mat33_t *m0, char *buffer, int32_t decimals)
{
    char *buffer_ptr;
    buffer_ptr = buffer;

    for (uint32_t i = 0; i < 3; i++) {
        *buffer_ptr++ = '|';
        buffer_ptr += fix16_vec3_str(&m0->row[i], buffer_ptr, decimals);
        *buffer_ptr++ = '|';
        *buffer_ptr++ = '\n';
    }
    *buffer_ptr = '\0';

    return (buffer_ptr - buffer);
}

static void
_mat33_row_transpose(const fix16_t *arr, fix16_vec3_t *m0)
{
    m0->x = arr[0];
    m0->y = arr[3];
    m0->z = arr[6];
}