#pragma once
#include "quantum.h"


// single half test
#define layout_left_split_cluster( \
  k00,      k01,    k02,    k03,    k04,    k05, \
  k10,      k11,    k12,    k13,    k14,    k15, \
  k20,      k21,    k22,    k23,    k24,    k25, \
  k30,      k31,    k32,    k33,    k34,    k35, \
                    k41,    k42,    k43,    k44 \
) \
{ \
  {k00,     k01,    k02,    k03,    k04,    k05}, \
  {k10,     k11,    k12,    k13,    k14,    k15}, \
  {k20,     k21,    k22,    k23,    k24,    k25}, \
  {k30,     k31,    k32,    k33,    k34,    k35}, \
  {KC_NO,   KC_NO,  k41,    k42,    k43,    k44} \
}


// Both halves
#define LAYOUT( \
    L00,    L01,    L02,    L03,    L04,    L05,    R00,    R01,    R02,    R03,    R04,    R05, \
    L10,    L11,    L12,    L13,    L14,    L15,    R10,    R11,    R12,    R13,    R14,    R15, \
    L20,    L21,    L22,    L23,    L24,    L25,    R20,    R21,    R22,    R23,    R24,    R25, \
    L30,    L31,    L32,    L33,    L34,    L35,    R30,    R31,    R32,    R33,    R34,    R35, \
                    L40,    L41,    L42,    L43,    R40,    R41,    R42,    R43 \
) \
{ \
    {   L00,        L01,        L02,        L03,        L04,        L05,    }, \
    {   L10,        L11,        L12,        L13,        L14,        L15,    }, \
    {   L20,        L21,        L22,        L23,        L24,        L25,    }, \
    {   L30,        L31,        L32,        L33,        L34,        L35,    }, \
    {   KC_NO,      KC_NO,      L40,        L41,        L42,        L43,    }, \
    {   R00,        R01,        R02,        R03,        R04,        R05     }, \
    {   R10,        R11,        R12,        R13,        R14,        R15     }, \
    {   R20,        R21,        R22,        R23,        R24,        R25     }, \
    {   R30,        R31,        R32,        R33,        R34,        R35     }, \
    {   R40,        R41,        R42,        R43,        KC_NO,      KC_NO   }  \
}
