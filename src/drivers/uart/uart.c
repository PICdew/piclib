/*
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 * uart.c
 * Copyright (C) 2015 Joshua Moyerman
 */

#include "uart.h"

#include <xc.h>
#include <string.h>

#include "piclib.h"

#define BACKSPACE 0x08

extern PICLIB_Config_t PICLIB_config;
UARTDriver_Config_t UART_config;

uint8_t UARTDriver_Init(uint8_t uart, uint32_t baud) {
  memset(&UART_config, 0, sizeof (UART_config));
  switch (uart) {
#ifdef UARTDriver_UART1
    case 1:
      UARTDriver_U1Init(baud);
      break;
#endif
#ifdef UARTDriver_UART2
    case 2:
      UARTDriver_U2Init(baud);
      break;
#endif
    default:
      return -1;
      break;
  }
  return 0;
}

void UARTDriver_WriteString(char *s) {
  while (*s) {
    UARTDriver_WriteChar(*s++);
  }
}

char *UARTDriver_GetLine(char *s, uint16_t len) {
  char *p = s;
  do {
    *s = UARTDriver_ReadChar();
    if (!((BACKSPACE == *s) && (s == p))) {
      UARTDriver_WriteChar(*s);
    }
    else {
      continue;
    }
    if ((BACKSPACE == *s) && (s > p)) {
      UARTDriver_WriteChar(' ');
      UARTDriver_WriteChar(BACKSPACE);
      len++;
      s--;
      continue;
    } else if ('\n' == *s) {
      continue;
    } else if ('\r' == *s) {
      break;
    }
    s++;
    len--;
  } while (len > 1);
  *s = 0;
  return p;
}

void UARTDriver_WriteChar(char c) {
  if (UART_config.write) {
    UART_config.write(c);
  }
}

char UARTDriver_ReadChar(void) {
  if (UART_config.read) {
    return UART_config.read();
  }
  return -1;
}

#ifdef UARTDriver_UART1

void UARTDriver_U1Init(uint32_t baud) {
  U1MODE = 0x8008;
  U1STA = 0x400;
  U1BRG = (PICLIB_config.sysFrequency / 8 / baud);
  UART_config.uartNum = 1;
  UART_config.read = UARTDriver_U1ReadChar;
  UART_config.write = UARTDriver_U1WriteChar;
}

void UARTDriver_U1WriteChar(char c) {
  while (U1STAbits.UTXBF);
  U1TXREG = c;
}

char UARTDriver_U1ReadChar(void) {
  while (!U1STAbits.URXDA);
  return U1RXREG;
}
#endif

#ifdef UARTDriver_UART2

void UARTDriver_U2Init(uint32_t baud) {
  U2MODE = 0x8008;
  U2STA = 0x400;
  U2BRG = (PICLIB_config.sysFrequency / 8 / baud);
  UART_config.uartNum = 2;
  UART_config.read = UARTDriver_U2ReadChar;
  UART_config.write = UARTDriver_U2WriteChar;
}

void UARTDriver_U2WriteChar(char c) {
  while (U2STAbits.UTXBF);
  U2TXREG = c;
}

char UARTDriver_U2ReadChar(void) {
  while (!U2STAbits.URXDA);
  return U2RXREG;
}
#endif