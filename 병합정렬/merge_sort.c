#include <stdio.h>
#include <stdlib.h>
void merge(int *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(sizeof(int) * (n1 + 1));
    int *R = (int *)malloc(sizeof(int) * (n2 + 1));

    L[n1] = 2147483647, R[n2] = 2147483647; // 무한대를 대신해서 int형 최댓값 대입

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0;

    for (int k = left; k <= right; k++)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i = i + 1;
        }
        else
        {
            arr[k] = R[j];
            j = j + 1;
        }
    }
    free(L), free(R);
}
void mergesort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main()
{
    int A[8] = {3, 41, 52, 26, 38, 57, 9, 49};
    mergesort(A, 0, 7);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}