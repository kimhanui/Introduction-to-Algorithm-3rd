#include <stdio.h>
int main()
{
    int A[4] = {1, 0, 1, 1};
    int B[4] = {1, 1, 0, 1};
    int C[5];
    int tmp=0;
    for (int i = 3; i >= 0; i--)
    {
        C[i + 1] = (A[i] + B[i] + tmp) % 2;
        tmp =(A[i] + B[i] + tmp) / 2;
    }
    C[0] = tmp;
    for (int i = 0; i < 5; i++)
    {
        printf("%d", C[i]);
    }
}
