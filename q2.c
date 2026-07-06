#include <stdio.h>

int main()
{
    int a[] = {0, 1, 2, 0, 1, 2, 1, 0};
    int n = 8;
    int low = 0, mid = 0, high = n - 1;
    int temp, i;

    while(mid <= high)
    {
        if(a[mid] == 0)
        {
            temp = a[low];
            a[low] = a[mid];
            a[mid] = temp;

            low++;
            mid++;
        }
        else if(a[mid] == 1)
        {
            mid++;
        }
        else
        {
            temp = a[mid];
            a[mid] = a[high];
            a[high] = temp;

            high--;
        }
    }

    printf("Sorted Array:\n");

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
