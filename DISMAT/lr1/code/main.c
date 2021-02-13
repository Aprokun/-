#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isElemIn(const int arr[], int n, int elem)
{
    size_t i = 1;
    while (i <= n)
    {
        if (elem == arr[i])
            return true;

        ++i;
    }

    return false;
}

int *unionArrays(const int arr1[], size_t n1, const int arr2[], size_t n2)
{
    int *res = (int*)calloc(n1+n2, sizeof(int));

    for (size_t i = 0; i < n1; i++)
    {
        res[i] = arr1[i];
    }

    for (size_t i = 0; i < n2; i++)
    {
        if (isElemIn(res, n1, arr2[i]) == false)
        {
            res[i+n1] = arr2[i];
        }
    }

    return res;
}

int *inters(const int arr1[], size_t n1, const int arr2[], size_t n2)
{
    int *res = (int*)calloc(n1,sizeof(int));

    for (size_t i = 0; i < n1; i++)
    {
        if (isElemIn(arr2,n2,arr1[i]))
            res[i] = arr1[i];
    }

    return res;
}

int main() {
    int a[] = {2,5,6,7,9}, b[] = {1,4,5,9}, c[] = {3,7,8,10};

    int arr1[] = {3,4,7,8,9,12};

    int *p = unionArrays(a, 5, c, 4);
    int *p1 = inters(a,5,b,4);

    for (size_t i = 0; i < 13; i++)
    {
        if (p[i] != 0)
            printf("%i ",p[i]);
    }

    printf("\n");

    for (size_t i = 0; i < 6; i++)
    {
        if (p1[i] != 0)
            printf("%i ",p1[i]);
    }
}
