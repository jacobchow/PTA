#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAXN 1000000
clock_t start, stop;
double duration;
double func1(int n, double a[], double x)
{
    double p = a[0];
    for (int i = 1; i < n; i++)
    {
        p += (a[i] * pow(x, i));
    }
    return p;
}
double func2(int n, double a[], double x)
{
    double p = a[n];
    for (int i = n; i > 0; i--)
    {
        p = a[i - 1] + x * p;
    }
    return p;
}
int main()
{
    double a[MAXN];
    for (int i = 0; i < MAXN; i++)
        a[i] = (double)i;

    start = clock();
    func1(MAXN - 1, a, 1.1);
    stop = clock();
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("duration1: %f\n", duration);

    start = clock();
    func2(MAXN - 1, a, 1.1);
    stop = clock();
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("duration2: %f\n", duration);
    return 0;
}