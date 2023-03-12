#include <stdio.h>

int main()
{
    float g = 10.2;
    void *vp =&g;
    float f = *(float *)vp;
    printf("%f", f);
}