/*
* Copyright 2024 BeanBoards & OLKB (github.com/C44Supra & github.com/olkb)
* SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

#include_next <mcuconf.h>

#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 TRUE
