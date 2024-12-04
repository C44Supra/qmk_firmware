/*
* Copyright 2024 BeanBoards & OLKB (github.com/C44Supra & github.com/olkb)
* SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

#include_next <halconf.h>

#undef HAL_USE_I2C
#define HAL_USE_I2C TRUE
