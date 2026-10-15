// Copyright 2022 Steven Karrmann (@skarrmann)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


/* Serial communication */
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

/* Split master detection: RP2040 has no VBUS sense, so SPLIT_USB_DETECT is on
 * and a half powered without a host (e.g. by a monitor hub in USB standby)
 * decides it is the slave and disconnects USB for good. The watchdog reboots
 * any slave half that never hears from a master, so it retries until a host
 * appears. */
#define SPLIT_WATCHDOG_ENABLE
