/*
 * Copyright (c) 2026 Linumiz
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef RH850_CORE_G4KH_H
#define RH850_CORE_G4KH_H

#include "rh850_sysreg.h"

/* RH850G4KH core facts, plain constants for C and asm */
#define RH850_CORE_G4KH           1

/* FPU single and double precision, no FXU */
#define RH850_CORE_HAS_FPU        1
#define RH850_CORE_HAS_FPU_DP     1
#define RH850_CORE_HAS_FXU        0
/* SYNCE waits for pending FPI exceptions */
#define RH850_CORE_HAS_SYNCE      1

/* FPSR fields; FS = 1 is the reset value */
#define RH850_FPSR_CC_SHIFT       24
#define RH850_FPSR_IF             0x00400000
#define RH850_FPSR_RM_SHIFT       18
#define RH850_FPSR_RM_MASK        0x000c0000
#define RH850_FPSR_RM_RN          0 /* to nearest */
#define RH850_FPSR_RM_RZ          1 /* toward 0 */
#define RH850_FPSR_RM_RP          2 /* toward +inf */
#define RH850_FPSR_RM_RM          3 /* toward -inf */
#define RH850_FPSR_FS             0x00020000
#define RH850_FPSR_XC_MASK        0x0000fc00
#define RH850_FPSR_XP_MASK        0x0000001f

/* FPEC.FPIVD: an imprecise FPU exception is pending */
#define RH850_CORE_HAS_FPEC       1
#define RH850_SR_FPEC             11, 0
#define RH850_FPEC_FPIVD          0x00000001

/* 16 EI priority levels, INTCFG.EPL fixed to 0 */
#define RH850_CORE_PRIO_LEVELS    16

/* PLMR: PLM = n masks priority numbers >= n, 10H masks none */
#define RH850_SR_PLMR             14, 2
#define RH850_CORE_PLMR_ALL       0x10
/* Core-neutral names for the port */
#define RH850_CORE_MASK_SR        RH850_SR_PLMR
#define RH850_CORE_MASK_NONE      RH850_CORE_PLMR_ALL
#define RH850_CORE_MASK( prio )    ( prio )

/* PE number in PEID bits 4:0 */
#define RH850_SR_PEID             0, 2

/* Memory error and register bank registers */
#define RH850_SR_MEA              6, 2
#define RH850_SR_MEI              8, 2
#define RH850_SR_RBIP             18, 2

/* MPU: 24 areas, indexed through MPIDX */
#define RH850_CORE_MPU_ENTRIES    24
#define RH850_CORE_MPU_INDEXED    1
#define RH850_SR_MCA              8, 5
#define RH850_SR_MCS              9, 5
#define RH850_SR_MCR              11, 5
#define RH850_SR_MCI              12, 5
#define RH850_SR_MPIDX            16, 5
#define RH850_SR_MPLA             20, 5
#define RH850_SR_MPUA             21, 5
#define RH850_SR_MPAT             22, 5
#define RH850_SR_MPID0            24, 5
#define RH850_SR_MPID1            25, 5
#define RH850_SR_MPID2            26, 5
#define RH850_SR_MPID3            27, 5
#define RH850_SR_MPID4            28, 5
#define RH850_SR_MPID5            29, 5
#define RH850_SR_MPID6            30, 5
#define RH850_SR_MPID7            31, 5

/* Instruction cache operation registers */
#define RH850_SR_ICTAGL           16, 4
#define RH850_SR_ICTAGH           17, 4
#define RH850_SR_ICDATL           18, 4
#define RH850_SR_ICDATH           19, 4
#define RH850_SR_ICERR            28, 4

#endif /* RH850_CORE_G4KH_H */
