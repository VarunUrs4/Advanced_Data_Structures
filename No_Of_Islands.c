#include <stdio.h>
int main()
{
    int n,i,j,k;
    printf ("Ënter no. of nodes:");
    scanf ("%d", &n);
    int a[n][n];
    printf ("Ënter adjacency matrix:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf ("%d", &a[i][j]);
    }
    int count = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                printf ("Island %d\n", (count+1));
                printf ("(%d, %d)\n", i, j);
                count++;
                a[i][j] = -999;
                if (i != 0 && a[i-1][j] == 1)
                {
                    a[i-1][j] = -999;
                }
                if (i != 0 && j != (n-1) && a[i-1][j+1] == 1)
                {
                    a[i-1][j+1] = -999;
                    printf ("(%d, %d)\n", i-1, j+1);
                }
                if (j != (n-1) && a[i][j+1] == 1)
                {
                    a[i][j+1] = -999;
                    printf ("(%d, %d)\n", i, j+1);
                }
                if (i != (n-1) && j != (n-1) && a[i+1][j+1] == 1)
                {
                    a[i+1][j+1] = -999;
                    printf ("(%d, %d)\n", i+1, j+1);
                }
                if (i != (n-1) && a[i+1][j] == 1)
                {
                    a[i+1][j] = -999;
                    printf ("(%d, %d)\n", i+1, j);
                }
                if (i != (n-1) && j != 0 && a[i+1][j-1] == 1)
                {
                     a[i+1][j-1] = -999;
                    printf ("(%d, %d)\n", i+1, j-1);
                }
                if (j != 0 && a[i][j-1] == 1)
                {
                    a[i][j-1] = -999;
                    printf ("(%d, %d)\n", i, j-1);
                }
                if (i != 0 && j != 0 && a[i-1][j-1] == 1)
                {
                    a[i-1][j-1] = -999;
                    printf ("(%d, %d)\n", i-1, j-1);
                }
            }
        }
    }

    printf ("No. of islands: %d", count);
}
