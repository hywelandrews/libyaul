/*
 * Copyright (c) 2012-2019 Israel Jacquez
 * See LICENSE for details.
 *
 * Israel Jacquez <mrkotfw@gmail.com>
 */

#ifndef _VDP_H_
#define _VDP_H_

#include <vdp1.h>
#include <vdp2.h>

__BEGIN_DECLS

#define VDP1_SYNC_INTERVAL_60HZ         (0)
#define VDP1_SYNC_INTERVAL_VARIABLE     (-1)

#define VDP1_SYNC_MODE_ERASE_CHANGE     (0x00)
#define VDP1_SYNC_MODE_CHANGE_ONLY      (0x01)
#define VDP1_SYNC_MODE_MASK             (0x01)

#define vdp_sync_vblank_in_clear() do {                                        \
        vdp_sync_vblank_in_set(NULL);                                          \
} while (false)

#define vdp_sync_vblank_out_clear() do {                                       \
        vdp_sync_vblank_out_set(NULL);                                         \
} while (false)

typedef void (*vdp1_sync_callback)(void *);

typedef void (*vdp_sync_callback)(void *);

extern void vdp_sync(void);

extern void vdp1_sync_interval_set(const int8_t);
extern uint8_t vdp1_sync_mode_get(void);
extern void vdp1_sync_mode_set(const uint8_t);

extern void vdp1_sync_cmdt_put(const vdp1_cmdt_t *, const uint16_t,
    const uint16_t, vdp1_sync_callback, void *);

extern void vdp1_sync_cmdt_list_put(const vdp1_cmdt_list_t *,
    const uint16_t, vdp1_sync_callback, void *);

extern void vdp1_sync_cmdt_orderlist_put(const vdp1_cmdt_orderlist_t *,
    vdp1_sync_callback, void *);

extern bool vdp1_sync_rendering(void);

extern void vdp2_sync_commit(void);

extern void vdp_sync_vblank_in_set(vdp_sync_callback);
extern void vdp_sync_vblank_out_set(vdp_sync_callback);

extern int8_t vdp_sync_user_callback_add(vdp_sync_callback, void *);
extern void vdp_sync_user_callback_remove(const uint8_t);
extern void vdp_sync_user_callback_clear(void);

__END_DECLS

#endif /* !_VDP_H_ */
