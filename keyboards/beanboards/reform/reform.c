/* Copyright 2022 Jose Pablo Ramirez <jp.ramangulo@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "reform.h"

/*
led_config_t g_led_config = { {
    // Key Matrix to LED Index
    {9, NO_LED, NO_LED, 8, NO_LED, NO_LED, NO_LED, 7, NO_LED, NO_LED, 6, NO_LED, NO_LED, 5},
    {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
    {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
    {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
    {0, NO_LED, NO_LED, 1, NO_LED, NO_LED, NO_LED, 2, NO_LED, NO_LED, 3, NO_LED, NO_LED, 4},
}, {
    // LED Index Physical location
    {0,64},{56,64},{112,64},{168,64},{224,64},{224,0},{168,0},{112,0},{56,0},{0,0}
}, {
    // LED Index to Flag
    LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL
} };
*/

led_config_t g_led_config = { {
    // Key Matrix to LED Index
    {0,              1,              2,              3,              4,              5,              6,              7,              8,              9,             10,             11,             12,             13,             14},
    {29,            28,             27,             26,             25,             24,             23,             22,             21,             20,             19,             18,             17,             16,             15},
    {30,            31,             32,             33,             34,             35,             36,             37,             38,             39,             40,             41,             42,             43,             44},
    {59,            58,             57,             56,             55,             54,             53,             52,             51,             50,             49,             48,             47,             46,             45},
    {60,            61,             62,             63,             64,             65,             66,             67,             68,             69,             70,             71,             72,             73,             74},
    {89,            88,             87,             86,             85,             84,             83,             82,             81,             80,             79,             78,             77,             76,             75}
}, {
    // LED Index Physical location
    {0,0},          {17,0},         {34,0},         {51,0},         {68,0},         {85,0},         {102,0},        {112,0},        {122,0},        {139,0},        {156,0},        {173,0},        {190,0},        {207,0},        {224,0},
    {224,13},       {207,13},       {190,13},       {173,13},       {156,13},       {139,13},       {122,13},       {112,13},       {102,13},       {85,13},        {68,13},        {51,13},        {34,13},        {17,13},        {0,13},
    {0,26},         {17,26},        {34,26},        {51,26},        {68,26},        {85,26},        {102,26},       {112,26},       {122,26},       {139,26},       {156,26},       {173,26},       {190,26},       {207,26},       {224,26},
    {224,38},       {207,38},       {190,38},       {173,38},       {156,38},       {139,38},       {122,38},       {112,38},       {102,38},       {85,38},        {68,38},        {51,38},        {34,38},        {17,38},        {0,38},
    {0,51},         {17,51},        {34,51},        {51,51},        {68,51},        {85,51},        {102,51},       {112,51},       {122,51},       {139,51},       {156,51},       {173,51},       {190,51},       {207,51},       {224,51},
    {224,64},       {207,64},       {190,64},       {173,64},       {156,64},       {139,64},       {122,64},       {112,64},       {102,64},       {85,64},        {68,64},        {51,64},        {34,64},        {17,64},        {0,64}
}, {
    // LED Index to Flag
    LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,
    LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,
    LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,
    LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,
    LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,
    LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL,   LED_FLAG_ALL
} };
