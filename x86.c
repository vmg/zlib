#include "x86.h"

int x86_cpu_has_sse2;
int x86_cpu_has_sse42;
int x86_cpu_has_pclmulqdq;

void x86_check_features(void)
{
    unsigned eax, ebx, ecx, edx;

    eax = 1;
    __asm__ __volatile__ (
        "cpuid\n\t"
    : "+a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx)
    );

    x86_cpu_has_sse2 = edx & 0x4000000;
    x86_cpu_has_sse42= ecx & 0x100000;
    x86_cpu_has_pclmulqdq = ecx & 0x2;
}
