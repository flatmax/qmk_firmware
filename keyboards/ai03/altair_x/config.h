/* Copyright 2024 ai03 Design Studio */
/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

// /* VBUS-routed pin for upstream detection */
// #define USB_VBUS_PIN GP0

/* RP2040- and hardware-specific config */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64

#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP0     // USART TX pin
#define SERIAL_USART_RX_PIN GP1     // USART RX pin
