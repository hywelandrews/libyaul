/*
 * No copyright.
 */

#ifndef SEGA3D_INTERNAL_H_
#define SEGA3D_INTERNAL_H_

#include <stdint.h>

#include "sega3d.h"

#include <vdp1/cmdt.h>

#define MATRIX_STACK_MAX        (32)
#define SORT_Z_RANGE            (256)
#define PACKET_SIZE             (4096)
#define VERTEX_POOL_SIZE        (1024)
#define DISPLAY_LEVEL_COUNT     (8)
#define FAR_Z                   toFIXED(1024.0f)
#define MIN_FOV_ANGLE           (DEGtoANG(60.0f))
#define MAX_FOV_ANGLE           (DEGtoANG(120.0f))

typedef enum {
        FLAGS_NONE        = 0,
        FLAGS_INITIALIZED = 1 << 0,
        FLAGS_FOG_ENABLED = 1 << 1,
} flags_t;

typedef enum {
        TLIST_FLAGS_NONE,
        TLIST_FLAGS_USER_ALLOCATED = 1 << 0,
        TLIST_FLAGS_ALLOCATED      = 1 << 1
} tlist_flags_t;

typedef enum {
        CLIP_FLAGS_NONE   = 0,
        CLIP_FLAGS_NEAR   = 1 << 0,
        CLIP_FLAGS_FAR    = 1 << 1,
        CLIP_FLAGS_LEFT   = 1 << 2,
        CLIP_FLAGS_RIGHT  = 1 << 3,
        CLIP_FLAGS_TOP    = 1 << 4,
        CLIP_FLAGS_BOTTOM = 1 << 5,
        CLIP_FLAGS_SIDE   = 1 << 6
} clip_flags_t;

typedef struct {
        FIXED point_z;
        int16_vec2_t screen;
        clip_flags_t clip_flags;
} __aligned(16) transform_proj_t;

static_assert(sizeof(transform_proj_t) == 16);

typedef struct {
        int16_t cached_sw_2;           /* Cached half of screen width */
        int16_t cached_sh_2;           /* Cached half of screen height */
        uint16_t vertex_count;         /* Current vertex count */
        uint16_t polygon_count;        /* Current polygon count */
        uint16_t index;                /* Current polygon index */
        FIXED z_center;                /* Z center of the current polygon */
        const transform_proj_t *polygon[4]; /* Pointers to the pool that make up the current polygon */

        const sega3d_object_t *object; /* Current object */
        const void *pdata;             /* Current PDATA */

        vdp1_cmdt_orderlist_t *current_orderlist;
        vdp1_cmdt_orderlist_t *orderlist;
        vdp1_cmdt_t *current_cmdt;
} __aligned(16) transform_t;

static_assert(sizeof(transform_t) == 64);

typedef struct {
        fix16_plane_t near_plane;
        fix16_plane_t far_plane;
        fix16_plane_t left_plane;
        fix16_plane_t right_plane;
        fix16_plane_t top_plane;
        fix16_plane_t bottom_plane;
} __packed __aligned(4) clip_planes_t;

static_assert(sizeof(clip_planes_t) == (6 * sizeof(fix16_plane_t)));

typedef struct sort_single {
        void *packet;
        struct sort_single *next_single;
} __aligned(8) sort_single_t;

typedef struct {
        sort_single_t *first_single;
} __aligned(4) sort_list_t;

typedef void (*iterate_fn)(sort_single_t *);

typedef struct {
        flags_t flags;

        sega3d_fog_t * const fog;
        sega3d_info_t * const info;
        transform_t * const transform;
        transform_proj_t * const transform_proj_pool;
        MATRIX * const clip_camera;
        clip_planes_t * const clip_planes;
        MATRIX * const matrices;
        sort_list_t * const sort_list;
        sort_single_t * const sort_single_pool;
} __aligned(16) state_t;

extern state_t * const _internal_state;

#endif /* SEGA3D_INTERNAL_H_ */
