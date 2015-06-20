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
 * piclib.h
 * Copyright (C) 2015 Joshua Moyerman
 */

#ifndef PICLIB_H
#define	PICLIB_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>

  typedef struct PICLIB_Config_s {
    uint32_t sysFrequency;
  } PICLIB_Config_t;

#ifdef	__cplusplus
}
#endif

#endif	/* PICLIB_H */

