#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>
#include <limits.h>
void verificare(void *p)
{
    if (p)
        return;
    printf("Nu s-a putut aloca memorie/deschide fisierul\n");
    exit(0);
}
void conversie(char v[])
{
    char nume_dir[DIM] = "trenuri/";
    strcat(nume_dir, v);
    strcpy(v, nume_dir);
}
char **alocare_loc()
{
    //ALOC DIN 10 in 10
    int i;
    if (LOC == NULL)
        LOC = malloc(10 * sizeof(char *));
    else
        LOC = realloc(LOC, (N + 10) * sizeof(char *));

    for (i = N; i < N + 10; i++)
        LOC[i] = malloc(DIM * sizeof(char));
    return LOC;
}
int adaugare(char *loc, int *cost)
{
    int i;
    for (i = 0; i < strlen(loc); i++)
        if (loc[i] == ',')
        {
            *cost = atoi(&loc[i + 1]);
            loc[i] = '\0';
            break;
        }
    if (N)
        for (i = 0; i < N; i++)
        {
            if (strcmp(loc, LOC[i]) == 0)
                return i;
        }
    if ((N + 1) % 10 == 0 || N == 0)
        LOC = alocare_loc(); //Alocam memorie daca n ajunge la multiplu de 10
    strcpy(LOC[N++], loc);
    return N - 1;
}

int **alocare()
{
    int **A;
    A = calloc(MAX_ORASE, sizeof(int *));
    for (int i = 0; i < MAX_ORASE; i++)
        A[i] = calloc(MAX_ORASE, sizeof(int));
    verificare(A);
    return A;
}
int *drum_minim(int **a,int s,int **t)
{
 int *f,*d,INF=INT_MAX/2;
    f=calloc(N,sizeof(int));
    *t=calloc(N,sizeof(int));
    d=calloc(N,sizeof(int));
    int i,j;
    for (i = 0; i < N; i++)
    {
        f[i] = 0;
        d[i] = a[s][i];
    }

    f[s] = 1;
    d[s] = 0;
    d[0] = INF; // pentru determinarea nodului cu costul minim
    for (int k = 0; k < N-1; ++k)
    {
        int pmax = 0;
        for (i = 0; i < N; ++i)
            if (f[i] == 0 && d[i] < d[pmax])
                pmax = i;

        if (pmax > -1)
        {
            f[pmax] = 1;
            for (i = 0; i < N; ++i)
                if (f[i] == 0 && d[pmax]!=INF && d[i] > d[pmax] + a[pmax][i])
                    {
                        d[i] = d[pmax] + a[pmax][i];
                        (*t)[i]=pmax;
                    }
        }
    }
    return d;
}