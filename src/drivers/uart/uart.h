/*
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 * uart.h
 * Copyright (C) 2015 Joshua Moyerman
 */
#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "UARTDriver.h"

#define UARTDriver_UART1
#define UARTDriver_UART2

  typedef struct UARTDriver_Config_s {
    uint8_t uartNum;
    uint32_t baud;
    void (*write)(char);
    char (*read)(void);
  } UARTDriver_Config_t;

#ifdef UARTDriver_UART1
  void UARTDriver_U1Init(uint32_t baud);
  void UARTDriver_U1WriteChar(char c);
  char UARTDriver_U1ReadChar();
#endif
#ifdef UARTDriver_UART2
  void UARTDriver_U2Init(uint32_t baud);
  void UARTDriver_U2WriteChar(char c);
  char UARTDriver_U2ReadChar();
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

