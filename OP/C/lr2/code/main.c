#include <stdio.h>

///ввод массива arr длины n.
void input_arr(float a[], const size_t n)
{
    for (size_t i = 0; i < n; ++i)
        scanf("%f", &a[i]);
}

///вывод проивзольного количества идущих подряд элементов
///массива arr длины n начинающегося с bgn и
///оканчивающегося на end.
void output_arr_frg(const float a[], const size_t bgn, const size_t end)
{
    for (size_t i = bgn; i <= end; i++)
    {
        printf("%f ",a[i]);
    }
}

///возвращает длину максимального количества идущих подряд
///положительных членов массива a длины n.
///Побочный эффект: в bgn помещается индекс начала фрагмента.
size_t get_len_mx_amnt_pstv_elms(const float a[], const size_t n, size_t *bgn)
{
    size_t i = 0,
           b,
           e = 0,
           t = 0,
           max = 0;

    while ((i < n) && (t <= (n - e)))
    {
        if (a[i] > 0)
        {
            b = e = i;

            while ((a[i+1] > 0) && (i + 1 < n))
                e = ++i;

            t = e - b;

            if (t >= max)
            {
                max = t;
                *bgn = b;
            }
        }

        i++;
    }

    return max;
}

int main()
{
    printf("Input length of numbers sequence\n");
    size_t n;
    scanf("%ud", &n);

    float a[n];
    printf("Input elements of numbers sequence\n");
    input_arr(a, n);

    size_t bgn = 0,
           frag_len;

    frag_len = get_len_mx_amnt_pstv_elms(a, n, &bgn);

    if ((bgn == 0) && (frag_len == 0) && (a[0] < 0))
    {
        printf("There is no such fragment");
    }
    else
    {
        printf("Length of fragment is %u\n", frag_len+1);
        output_arr_frg(a, bgn, bgn + frag_len);
    }
}
