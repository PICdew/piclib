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
 * arch.h
 * Copyright (C) 2015 Joshua Moyerman
 */

#ifndef ARCH_H
#define ARCH_H

#ifdef	__cplusplus
extern "C" {
#endif

#if defined(__XC16__)
#include "pic24/pic24.h"
#elif defined(__XC32__)
#include "pic32_stk/pic32_stk.h"
#endif

#ifdef	__cplusplus
}
#endif

#endif