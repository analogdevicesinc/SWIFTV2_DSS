/******************************************************************************
 *
 * Copyright (C) 2022-2023 Maxim Integrated Products, Inc. All Rights Reserved.
 * (now owned by Analog Devices, Inc.),
 * Copyright (C) 2023 Analog Devices, Inc. All Rights Reserved. This software
 * is proprietary to Analog Devices, Inc. and its licensors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/

    .syntax unified
    .arch armv7-m
    .text   
    .thumb
    .thumb_func
    .align 2
    .globl   Backup_Handler
    .type    Backup_Handler %function
Backup_Handler:
    /* Wait for VregB to reach its setpoint */
    LDR     R0, =0x40004400
buck_wait:    
    LDR     R1, [R0, #64]
    LSLS    R1, R1, #30
    BPL.N   buck_wait
    /* Switch back to VcoreB */
    LDR     R0, =0x40006C00
    LDR     R1, [R0, #16]
    BIC.W   R1, R1, #6
    STR     R1, [R0, #16]
    /* Jump to Reset_Handler */
    LDR     R0, =0x4000684C
    LDR     R1, [R0]
    BX      R1
    