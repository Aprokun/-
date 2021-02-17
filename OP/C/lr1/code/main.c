#include <stdio.h>

///ввод массива
void input_arr(float arr[], const size_t n)
{
    for (size_t i = 0; i < n; ++i)
        scanf("%f",&arr[i]);
}

///выбор фрагмента (начало фрагмента и конец фрагмента) с максимальным
///количеством идущих подряд положительных чисел.
void slct_mx_aff_frg(const float arr[],const size_t n, int rng_arr[])
{
    size_t i = 0;
    int b = 0, e = 0, max = -1;

    while ((i < n) && ((e - b) <= (n - e)))
    {
        if (arr[i] > 0)
        {
            b = e = i;

            while ((arr[i + 1] > 0) && (i + 1 < n))
                e = ++i;

            if ((e - b) > max)
            {
                max = e - b;
                rng_arr[0] = b;
                rng_arr[1] = e;
            }
        }

        i++;
    }
}

///вывод массива.
void output_arr_frg(const float arr[], const size_t bgn, const size_t end)
{
    for (int i = bgn; i <= end; i++) {
        printf("%2.1f ",arr[i]);
    }
}

int main()
{
   printf("Input length of numbers sequence\n");
   size_t n;
   scanf("%ud",&n);

   float arr[n];
   printf("Input elements of numbers sequence\n");
   input_arr(arr, n);

   int rng_vals[] = {0, 0};

   slct_mx_aff_frg(arr, n, rng_vals);

   if ((rng_vals[0] == 0) && (rng_vals[1] == 0) && (arr[0] < 0))
       printf("There is no such fragment");
   else
   {
       printf("Length of fragment is %u\n",(rng_vals[1]-rng_vals[0]+1));
       output_arr_frg(arr,rng_vals[0],rng_vals[1]);
   }
}
