#include <stdio.h>
int main()
{
    int a[6]= {1, 2, 4, 6, 8, 9};
    int b[8]= {3, 11, 14, 17, 19, 20, 22, 25};
    int c[20];
    int i, j, k;
    i = j = k = 0;
    while(i < 6 && j < 8)
    {
        if(a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while(i < 6)
        c[k++] = a[i++];
    while(j < 8)
        c[k++] = b[j++];
    printf("Merged Array: ");
    for(i = 0; i < k; i++)
        printf("%d ", c[i]);
    return 0;
}

