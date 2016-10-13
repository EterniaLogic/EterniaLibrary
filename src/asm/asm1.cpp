//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------
#include "asm1.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void cpuid(unsigned info, unsigned *eax, unsigned *ebx, unsigned *ecx, unsigned *edx) {
    __asm__(
        "xchg %%ebx, %%edi;" /* 32bit PIC: don't clobber ebx */
        "cpuid;"
        "xchg %%ebx, %%edi;"
        :"=a" (*eax), "=D" (*ebx), "=c" (*ecx), "=d" (*edx)
        :"0" (info)
    );
}

void testASM() {
    unsigned int eax, ebx, ecx, edx;
    int i;

    for (i = 0; i < 500000; ++i) {
        cpuid(i, &eax, &ebx, &ecx, &edx);
        if(eax > 0 || ebx > 0 || ecx > 0 || edx > 0)
            printf("[TestASM] eax=%i: %#010x %#010x %#010x %#010x\n", i, eax, ebx, ecx, edx);
    }
}
