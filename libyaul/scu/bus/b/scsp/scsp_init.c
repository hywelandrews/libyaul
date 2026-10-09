/*
 * Copyright (c) Israel Jacquez
 * See LICENSE for details.
 *
 * Israel Jacquez <mrkotfw@gmail.com>
 */

#include <scsp.h>

#include "scsp-internal.h"

void
__scsp_init(void)
{
    /* Disable all sound CPU interrupts (SCIEB[10:0]) */
    scsp_scieb_set(0x0000);

    /* Disable all main CPU interrupts (MCIEB[10:0]) */
    scsp_mcieb_set(0x0000);

    /* Clear all sound CPU interrupt pending bits (SCIRE[10:0]) */
    scsp_scire_set(0x07FF);

    /* Clear all main CPU interrupt pending bits (MCIRE[10:0]) */
    scsp_mcire_set(0x07FF);
}
