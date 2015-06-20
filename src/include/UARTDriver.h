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
 * UARTDriver.h
 * Copyright (C) 2015 Joshua Moyerman
 */

#ifndef UARTDRIVER_H
#define	UARTDRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>

#define UARTDriver_UART1
#define UARTDriver_UART2

  uint8_t UARTDriver_Init(uint8_t uartNum, uint32_t baud);
  void UARTDriver_WriteString(char *s);
  char *UARTDriver_GetLine(char *s, uint16_t len);
  void UARTDriver_WriteChar(char c);
  char UARTDriver_ReadChar(void);

#ifdef	__cplusplus
}
#endif

#endif	/* UARTDRIVER_H */

