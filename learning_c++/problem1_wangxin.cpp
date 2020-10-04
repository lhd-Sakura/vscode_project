#include <math.h>
#include <stdio.h>
int main()
{
    float a, b, c, disc, p, g;
    printf("请输入变量a，b，c的值：");
    scanf("%f,%f,%f", &a, &b, &c);
    disc = b * b - 4 * a * c;
    p = -b / (2 * a);
    g = sqrt(disc) / (2 * a);
    printf("x1=%7.4f,x2=%7.4f\n", p + g, p - g);
    printf("\n");
    return 0;
}
