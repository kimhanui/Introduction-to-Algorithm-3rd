#include <stdio.h>
void insertion_sort(int *arr, int len)
{
    int key, i;
    for (int j = 1; j < len; j++)
    {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key) //key보다 큰 원소는 뒤로보냄
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}
int main()
{
    int A[6] = {5, 2, 4, 6, 1, 3};
    insertion_sort(A, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}