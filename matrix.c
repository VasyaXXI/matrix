#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define MAXSTRINGS 10
#define MINSTRINGS 5
#define MAXCOLUMNS 10
#define MINCOLUMNS 5
#define MAXMAS 100
#define MINMAS -100

int main()
{
    int n, m, i, j, minn, minm, max;
    srand(time(NULL));
    n = rand()%(MAXCOLUMNS - MINCOLUMNS + 1) + MINCOLUMNS;  /*SET RANDOM NUMBER OF COLUMNS*/
    m = rand()%(MAXSTRINGS - MINSTRINGS + 1) + MINCOLUMNS;  /*SET RANDOM NUMBER OF STRINGS*/
    int x[m][n];
    int y[m];
    int z[m-1][n-1];
    max = MAXMAS;
    for(i = 0; i<m; i++)    /*RANDOMLY SPECIFY THE UNITS OF ARRAY X*/
    {
        for(j = 0; j<n; j++)
        {
                x[i][j] = rand()%(MAXMAS - MINMAS + 1) + MINMAS;
        }
    }
    printf("PRIMARY MATRIX\n");
    for(i = 0; i<m; i++)    /*DISPLAY THE VALUES OF ARRAY X*/
    {
        for(j = 0; j<n; j++)
        {
            printf("%4d ", x[i][j]);
        }
    printf("\n");
    }
    printf("\n");
    /**/

    /*SHIFTING OF FIRST AND LAST STRINGS, WITH REVERSE VALUE*/
    printf("PRIMARY MATRIX WITH SHIFTING OF FIRST AND LAST STRINGS, WITH REVERSE VALUE\n");
    for(i = 0; i<n; i++)  /*MOVEMENT FIRST STRING IN SINGLE-STRING ARRAY*/
    {
        y[n-i] = x[0][i];
    }
    for(i = 0; i<n; i++)  /*SHIFTING FIRST AND LAST STRINGS, WITH REVERSE VALUE*/
    {
        x[0][i] = x[m-1][n-i-1];
    }
    for(i = 0; i<n; i++)  /*TRANSFER OF DATA FROM SINGLE-STRING ARRAY TO LAST STRING OF ARRAY X, WITH REVERSE VALUE*/
    {
        x[m-1][i] = y[i+1];
    }
    for(i = 0; i<m; i++)  /*DISPLAY THE NEW VALUES OF ARRAY X*/
    {
        for(j = 0; j<n; j++)
        {
            printf("%4d ", x[i][j]);
        }
    printf("\n");
    }
    printf("\n");
    /**/

    /*FINDING COORDINATES OF MINIMUM VALUE OF MASSIVE*/
    for(i = 0; i<m; i++)
    {
        for(j = 0; j<n; j++)
        {
            if(x[i][j] < max)
            {
                max = x[i][j];
                minn = j;
                minm = i;
            }
        }
    }
    /**/

    /*FILLING MATRIX Z OF VALUES OF MATRIX X WITHOUT INDICATED STRING AND COLUMN*/
    printf("MATRIX WITHOUT SRING AND COLUMN WITH MIN VALUE\n");
    for(i = 0; i<minm; i++)
    {
       for(j = 0; j<minn; j++)
       {
          z[i][j] = x[i][j];
       }
    }
    for(i = 0; i<m; i++)
    {
        for(j = minn+1; j<n; j++)
        {
            z[i][j-1] = x[i][j];
        }
    }
    for(i = minm+1; i<m; i++)
    {
        for(j = 0; j<n; j++)
        {
            z[i-1][j] = x[i][j];
        }
    }
    for(i = 0; i<minm; i++)
    {
       for(j = minn+1; j<n; j++)
       {
          z[i][j-1] = x[i][j];
       }
    }
    for(i = 0; i<m-1; i++)  /*DISPLAY THE VALUES OF ARRAY Z*/
    {
        for(j = 0; j<n-1; j++)
        {
            printf("%4d ", z[i][j]);
        }
    printf("\n");
    }
    /**/

    /**/
    char c;
    int a = 0;
    int col = 0;
    int new_mas[n-1][10];
    i = j = 0;
    printf("\nENTER MATRIX WITH %d STRINGS\n\n", n-1);
    while((c = getchar()) !='.')
    {
        if(c>='0' && c<='9')
            a = a*10 + c - '0';
        if(c==' ')
        {
            new_mas[i][j] = a;
            a = 0;
            j++;
        }
        if(c==',')
        {
            new_mas[i][j] = a;
            a = 0;
            i++;
            j = 0;
        }
    }
    col = j;
    printf("\n");
    /**/

    /*MATRIX MULTIPLICATION*/
    printf("RESULT OF MATRIX MILTIPLICATION\n");
    int k;
    int mult_mas[m-1][col];
    for(i = 0; i < m-1; i++)
    {
        for(j = 0; j < col; j++)
        {
            mult_mas[i][j] = 0;
            for(k = 0; k < n-1; k++)
                (mult_mas[i][j] += z[i][k] * new_mas[k][j]);
            printf("%6d", mult_mas[i][j]);
        }
        printf("\n");
    }
    return 0;
}
