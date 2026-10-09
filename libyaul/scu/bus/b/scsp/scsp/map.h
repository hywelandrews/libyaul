/*
 * Copyright (c) Israel Jacquez
 * See LICENSE for details.
 *
 * Israel Jacquez <mrkotfw@gmail.com>
 */

#ifndef _YAUL_SCSP_MAP_H_
#define _YAUL_SCSP_MAP_H_

#include <sys/cdefs.h>

#include <assert.h>
#include <stdint.h>

/// @addtogroup MEMORY_MAP
/// @defgroup MEMORY_MAP_SCSP_IO_REGISTERS SCSP I/O
/// @ingroup MEMORY_MAP
/// @{

/// @brief SCSP slot stride in bytes.
#define SCSP_SLOT_STRIDE            0x0020UL
/// @brief SCSP slot stride in bytes (alias).
#define SCSP_SLOT_SIZE              0x0020UL

/// @brief SCSP slot register word 0 (offset within slot).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SLOT_KYONEX            0x0000UL
/// @brief SCSP slot register word 0 alias.
#define SCSP_SLOT_SA_HI             0x0000UL

/// @brief SCSP slot register word 1 (offset within slot).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SLOT_SA                0x0002UL
/// @brief SCSP slot register word 1 alias.
#define SCSP_SLOT_SA_LO             0x0002UL

/// @brief SCSP slot register word 2 (offset within slot).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SLOT_LSA               0x0004UL

/// @brief SCSP slot register word 3 (offset within slot).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SLOT_LEA               0x0006UL

/// @brief SCSP slot register word 4 (offset within slot).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SLOT_D2R               0x0008UL
/// @brief SCSP slot register word 4 alias.
#define SCSP_SLOT_EG1               0x0008UL

/// @brief SCSP slot register word 5 (offset within slot).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SLOT_RR                0x000AUL
/// @brief SCSP slot register word 5 alias.
#define SCSP_SLOT_EG2               0x000AUL

/// @brief SCSP slot register word 6 (offset within slot).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SLOT_TL                0x000CUL

/// @brief SCSP slot register word 7 (offset within slot).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SLOT_MDL               0x000EUL

/// @brief SCSP slot register word 8 (offset within slot).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SLOT_OCT_FNS           0x0010UL
/// @brief SCSP slot register word 8 alias.
#define SCSP_SLOT_FNS               0x0010UL

/// @brief SCSP slot register word 9 (offset within slot).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SLOT_LFO               0x0012UL
/// @brief SCSP slot register word 9 alias.
#define SCSP_SLOT_LFORE             0x0012UL

/// @brief SCSP slot register word 10 (offset within slot).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SLOT_ISEL              0x0014UL
/// @brief SCSP slot register word 10 alias.
#define SCSP_SLOT_IMXL              0x0014UL

/// @brief SCSP slot register word 11 (offset within slot).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SLOT_DISDL             0x0016UL
/// @brief SCSP slot register word 11 alias.
#define SCSP_SLOT_PAN               0x0016UL

/// @brief SCSP common control register MVOL word.
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_MVOL                   0x0400UL
/// @brief SCSP common control register MVOL word alias.
#define SCSP_CMN_MVOL               0x0400UL
/// @brief SCSP common control register MVOL word alias.
#define MVOL                        0x0400UL

/// @brief SCSP common control register RBL/RBP word.
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_RBL_RBP                0x0402UL
/// @brief SCSP common control register RBL alias.
#define SCSP_RBL                    0x0402UL
/// @brief SCSP common control register RBP alias.
#define SCSP_RBP                    0x0402UL
/// @brief SCSP common control register RBL alias.
#define RBL                         0x0402UL
/// @brief SCSP common control register RBP alias.
#define RBP                         0x0402UL

/// @brief SCSP common control register MIBUF word.
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_MIBUF                  0x0404UL
/// @brief SCSP common control register MIDI IN alias.
#define SCSP_MIDI_IN                0x0404UL
/// @brief SCSP common control register MIBUF alias.
#define MIBUF                       0x0404UL

/// @brief SCSP common control register MOBUF word.
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_MOBUF                  0x0406UL
/// @brief SCSP common control register MIDI OUT alias.
#define SCSP_MIDI_OUT               0x0406UL
/// @brief SCSP common control register MOBUF alias.
#define MOBUF                       0x0406UL

/// @brief SCSP common control register MSLC / CA word.
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_MSLC                   0x0408UL
/// @brief SCSP common control register CA alias.
#define SCSP_CA                     0x0408UL
/// @brief SCSP common control register MSLC alias.
#define MSLC                        0x0408UL
/// @brief SCSP common control register CA alias.
#define CA                          0x0408UL

/// @brief SCSP common control register DMEA[15:1] word.
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_DMEA_LO                0x0412UL
/// @brief SCSP common control register DMEA alias.
#define SCSP_DMEA                   0x0412UL
/// @brief SCSP common control register DMEA alias.
#define DMEA                        0x0412UL

/// @brief SCSP common control register DMEA[19:16] and DRGA[11:1] word.
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_DRGA                   0x0414UL
/// @brief SCSP common control register DMEA high alias.
#define SCSP_DMEA_HI                0x0414UL
/// @brief SCSP common control register DRGA alias.
#define DRGA                        0x0414UL

/// @brief SCSP common control register DTLG and DMA control word.
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_DTLG                   0x0416UL
/// @brief SCSP common control register DMA control alias.
#define SCSP_DMA_CTRL               0x0416UL
/// @brief SCSP common control register DTLG alias.
#define DTLG                        0x0416UL

/// @brief SCSP common control register Timer A word.
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_TIMA                   0x0418UL
/// @brief SCSP common control register TACTL alias.
#define SCSP_TACTL                  0x0418UL
/// @brief SCSP common control register TIMA alias.
#define TIMA                        0x0418UL
/// @brief SCSP common control register TACTL alias.
#define TACTL                       0x0418UL

/// @brief SCSP common control register Timer B word.
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_TIMB                   0x041AUL
/// @brief SCSP common control register TBCTL alias.
#define SCSP_TBCTL                  0x041AUL
/// @brief SCSP common control register TIMB alias.
#define TIMB                        0x041AUL
/// @brief SCSP common control register TBCTL alias.
#define TBCTL                       0x041AUL

/// @brief SCSP common control register Timer C word.
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_TIMC                   0x041CUL
/// @brief SCSP common control register TCCTL alias.
#define SCSP_TCCTL                  0x041CUL
/// @brief SCSP common control register TIMC alias.
#define TIMC                        0x041CUL
/// @brief SCSP common control register TCCTL alias.
#define TCCTL                       0x041CUL

/// @brief SCSP common control register Sound CPU Interrupt Enable (SCIEB).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SCIEB                  0x041EUL
/// @brief SCSP common control register SCIEB alias.
#define SCIEB                       0x041EUL

/// @brief SCSP common control register Sound CPU Interrupt Pending (SCIPD).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SCIPD                  0x0420UL
/// @brief SCSP common control register SCIPD alias.
#define SCIPD                       0x0420UL

/// @brief SCSP common control register Sound CPU Interrupt Reset (SCIRE).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SCIRE                  0x0422UL
/// @brief SCSP common control register SCIRE alias.
#define SCIRE                       0x0422UL

/// @brief SCSP common control register Sound CPU Interrupt Level 0 (SCILV0).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SCILV0                 0x0424UL
/// @brief SCSP common control register SCILV0 alias.
#define SCILV0                      0x0424UL

/// @brief SCSP common control register Sound CPU Interrupt Level 1 (SCILV1).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SCILV1                 0x0426UL
/// @brief SCSP common control register SCILV1 alias.
#define SCILV1                      0x0426UL

/// @brief SCSP common control register Sound CPU Interrupt Level 2 (SCILV2).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_SCILV2                 0x0428UL
/// @brief SCSP common control register SCILV2 alias.
#define SCILV2                      0x0428UL

/// @brief SCSP common control register Main CPU Interrupt Enable (MCIEB).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_MCIEB                  0x042AUL
/// @brief SCSP common control register MCIEB alias.
#define MCIEB                       0x042AUL

/// @brief SCSP common control register Main CPU Interrupt Pending (MCIPD).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_MCIPD                  0x042CUL
/// @brief SCSP common control register MCIPD alias.
#define MCIPD                       0x042CUL

/// @brief SCSP common control register Main CPU Interrupt Reset (MCIRE).
/// @see SCSP
/// @see MEMORY_WRITE, MEMORY_READ
#define SCSP_MCIRE                  0x042EUL
/// @brief SCSP common control register MCIRE alias.
#define MCIRE                       0x042EUL

/// @brief SCSP sound data stack area base offset.
#define SCSP_SOUND_STACK            0x0600UL
/// @brief SCSP sound data stack area base offset alias.
#define SCSP_STACK                  0x0600UL

/// @brief SCSP DSP COEF area base offset.
#define SCSP_DSP_COEF               0x0700UL
/// @brief SCSP DSP COEF area base offset alias.
#define SCSP_COEF                   0x0700UL

/// @brief SCSP DSP MADRS area base offset.
#define SCSP_DSP_MADRS              0x0780UL
/// @brief SCSP DSP MADRS area base offset alias.
#define SCSP_MADRS                  0x0780UL

/// @brief SCSP DSP micro program area base offset.
#define SCSP_DSP_MPRO               0x0800UL
/// @brief SCSP DSP micro program area base offset alias.
#define SCSP_DSP_PROGRAM            0x0800UL

/// @brief SCSP DSP internal buffer area base offset.
#define SCSP_DSP_RAM                0x0C00UL
/// @brief SCSP DSP internal buffer area base offset alias.
#define SCSP_DSP_BUFFER             0x0C00UL

/* Interrupt bit positions */
#define SCSP_INT_BIT_INT0N          0
#define SCSP_INT_BIT_INT1N          1
#define SCSP_INT_BIT_INT2N          2
#define SCSP_INT_BIT_MIDI_IN        3
#define SCSP_INT_BIT_DMA_END        4
#define SCSP_INT_BIT_CPU_MANUAL     5
#define SCSP_INT_BIT_TIMER_A        6
#define SCSP_INT_BIT_TIMER_B        7
#define SCSP_INT_BIT_TIMER_C        8
#define SCSP_INT_BIT_MIDI_OUT       9
#define SCSP_INT_BIT_SAMPLE         10

/* Interrupt bit masks */
#define SCSP_INT_INT0N              (1U << 0)
#define SCSP_INT_INT1N              (1U << 1)
#define SCSP_INT_INT2N              (1U << 2)
#define SCSP_INT_MIDI_IN            (1U << 3)
#define SCSP_INT_DMA_END            (1U << 4)
#define SCSP_INT_CPU_MANUAL         (1U << 5)
#define SCSP_INT_TIMER_A            (1U << 6)
#define SCSP_INT_TIMER_B            (1U << 7)
#define SCSP_INT_TIMER_C            (1U << 8)
#define SCSP_INT_MIDI_OUT           (1U << 9)
#define SCSP_INT_SAMPLE             (1U << 10)

#define SCSP_INT_MASK_INT0N         (1U << 0)
#define SCSP_INT_MASK_INT1N         (1U << 1)
#define SCSP_INT_MASK_INT2N         (1U << 2)
#define SCSP_INT_MASK_MIDI_IN       (1U << 3)
#define SCSP_INT_MASK_DMA_END       (1U << 4)
#define SCSP_INT_MASK_CPU_MANUAL    (1U << 5)
#define SCSP_INT_MASK_TIMER_A       (1U << 6)
#define SCSP_INT_MASK_TIMER_B       (1U << 7)
#define SCSP_INT_MASK_TIMER_C       (1U << 8)
#define SCSP_INT_MASK_MIDI_OUT      (1U << 9)
#define SCSP_INT_MASK_SAMPLE        (1U << 10)

/// @brief SCSP slot I/O registers (12 words, 0x18 bytes).
typedef struct scsp_slot_regs {
    union {
        /// @brief SCSP slot I/O register buffer.
        uint16_t buffer[12];
        /// @brief SCSP slot I/O register raw buffer.
        uint16_t raw[12];

        struct {
            /* 0x00 */
            uint16_t :3;
            uint16_t kyonex:1;
            uint16_t kyonb:1;
            uint16_t sbctl:2;
            uint16_t ssctl:2;
            uint16_t lpctl:2;
            uint16_t pcm8b:1;
            uint16_t sa_high:4;

            /* 0x02 */
            union {
                uint16_t sa;
                uint16_t sa_low;
            };

            /* 0x04 */
            uint16_t lsa;

            /* 0x06 */
            uint16_t lea;

            /* 0x08 */
            uint16_t d2r:5;
            uint16_t d1r:5;
            uint16_t eghold:1;
            uint16_t ar:5;

            /* 0x0A */
            uint16_t :1;
            uint16_t lpslnk:1;
            uint16_t krs:4;
            uint16_t dl:5;
            uint16_t rr:5;

            /* 0x0C */
            uint16_t :6;
            uint16_t stwinh:1;
            uint16_t sdir:1;
            uint16_t tl:8;

            /* 0x0E */
            uint16_t mdl:4;
            uint16_t mdxsl:6;
            uint16_t mdysl:6;

            /* 0x10 */
            uint16_t :1;
            uint16_t oct:4;
            uint16_t :1;
            uint16_t fns:10;

            /* 0x12 */
            uint16_t lfore:1;
            uint16_t lfof:5;
            uint16_t plfows:2;
            uint16_t plfos:3;
            uint16_t alfows:2;
            uint16_t alfos:3;

            /* 0x14 */
            uint16_t :9;
            uint16_t isel:4;
            uint16_t imxl:3;

            /* 0x16 */
            uint16_t disdl:3;
            uint16_t dipan:5;
            uint16_t efsdl:3;
            uint16_t efpan:5;
        } __packed;
    };
} __aligned(2) __packed scsp_slot_regs_t;

static_assert(sizeof(scsp_slot_regs_t) == 0x18);

/// @brief SCSP common control I/O registers (24 words, 0x30 bytes).
typedef struct scsp_cmn_regs {
    union {
        /// @brief SCSP common control I/O register buffer.
        uint16_t buffer[24];
        /// @brief SCSP common control I/O register raw buffer.
        uint16_t raw[24];

        struct {
            /* 0x400 */
            uint16_t :6;
            uint16_t mem4mb:1;
            uint16_t dac18b:1;
            uint16_t :4;
            uint16_t mvol:4;

            /* 0x402 */
            uint16_t :7;
            uint16_t rbl:2;
            uint16_t rbp:7;

            /* 0x404 */
            uint16_t :3;
            uint16_t mofull:1;
            uint16_t moemp:1;
            uint16_t miovf:1;
            uint16_t mifull:1;
            uint16_t miemp:1;
            uint16_t mibuf:8;

            /* 0x406 */
            uint16_t :8;
            uint16_t mobuf:8;

            /* 0x408 */
            uint16_t mslc:5;
            uint16_t ca:4;
            uint16_t :7;

            /* 0x40A - 0x410: reserved */
            unsigned int :16;
            unsigned int :16;
            unsigned int :16;
            unsigned int :16;

            /* 0x412 */
            uint16_t dmea_low:15;
            uint16_t :1;

            /* 0x414 */
            uint16_t dmea_high:4;
            uint16_t drga:11;
            uint16_t :1;

            /* 0x416 */
            uint16_t :1;
            uint16_t dgate:1;
            uint16_t ddir:1;
            uint16_t dexe:1;
            uint16_t dtlg:11;
            uint16_t :1;

            /* 0x418 */
            uint16_t :5;
            uint16_t tactl:3;
            uint16_t tima:8;

            /* 0x41A */
            uint16_t :5;
            uint16_t tbctl:3;
            uint16_t timb:8;

            /* 0x41C */
            uint16_t :5;
            uint16_t tcctl:3;
            uint16_t timc:8;

            /* 0x41E */
            uint16_t :5;
            uint16_t scieb:11;

            /* 0x420 */
            uint16_t :5;
            uint16_t scipd:11;

            /* 0x422 */
            uint16_t :5;
            uint16_t scire:11;

            /* 0x424 */
            uint16_t :8;
            uint16_t scilv0:8;

            /* 0x426 */
            uint16_t :8;
            uint16_t scilv1:8;

            /* 0x428 */
            uint16_t :8;
            uint16_t scilv2:8;

            /* 0x42A */
            uint16_t :5;
            uint16_t mcieb:11;

            /* 0x42C */
            uint16_t :5;
            uint16_t mcipd:11;

            /* 0x42E */
            uint16_t :5;
            uint16_t mcire:11;
        } __packed;
    };
} __aligned(2) __packed scsp_cmn_regs_t;

static_assert(sizeof(scsp_cmn_regs_t) == 0x30);

/// @brief SCSP I/O register map.
typedef union scsp_ioregs {
    /// @brief SCSP I/O register buffer.
    uint16_t buffer[536];

    struct {
        struct {
            /// @brief SCSP slot registers.
            scsp_slot_regs_t regs;
            uint16_t reserved[4];
        } slots[32];

        /// @brief SCSP common control registers.
        scsp_cmn_regs_t cmn;
    };
} __aligned(2) __packed scsp_ioregs_t;

static_assert(sizeof(scsp_ioregs_t) == 0x430);

/// @}

#endif /* !_YAUL_SCSP_MAP_H_ */
