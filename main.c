#include <stdio.h>
#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    FILE *all = NULL, *f = NULL,*H,*ORADEA, *gr,*ad;
    char rute[DIM], loc[DIM];
    int **A, **B, i, j, x = EOF, y = EOF, S = 0, *g, costX, costY, COST_MIN[3], COST_MAX[3], Max = 0, *t;
    COST_MIN[0] = INT_MAX;
    COST_MAX[0] = INT_MIN;
     ad = fopen("input2.txt","wt");
    /*
        A graful orientat
        B graful neorientat
    */
    A = alocare();
    B = alocare();

    all = fopen("_all_files.txt", "rt");
    verificare(all);
    while (fscanf(all, "%s", rute) == 1)
    {
        conversie(rute); //   trenuri/78.txt
        //printf("%s\n",rute);
        f = fopen(rute, "rt");
        verificare(f);
        x = EOF;
        y = EOF; //EOF == -1
        while (fgets(loc, DIM, f))
        {
            x = adaugare(loc, &costX);
            if (x != EOF && y != EOF)
            {
                fprintf(ad,"%d %d %d\n", y, x,costX-costY);
                if (!A[x][y] || A[x][y] > costX - costY)
                    A[x][y] = costX - costY;

                if (!B[x][y] || B[x][y] > costX - costY)
                {
                    B[x][y] = costX - costY;
                    B[y][x] = costX - costY;
                }

                if (costX - costY < COST_MIN[0])
                {
                    COST_MIN[0] = costX - costY;
                    COST_MIN[1] = x;
                    COST_MIN[2] = y;
                }
                if (costX - costY > COST_MAX[0])
                {
                    COST_MAX[0] = costX - costY;
                    COST_MAX[1] = x;
                    COST_MAX[2] = y;
                }
            }
            y = x;
            costY = costX;
        }
        fclose(f);
    }
    gr = fopen("locatii.dat","wb");

    for(i=0;i<N;i++)
        fwrite(LOC[i],sizeof(char),DIM,gr);
    
    /*
    i = 0;
    printf("Numarul total al statiilor: %d\n\n", N);
    H = fopen("afisare.txt", "wt");
    for (i = 0; i < N; i++)
    {
        fprintf(H, "%s\n", LOC[i]);
    }
    printf("Distanta minima:%s - %s (%dkm)\n",
           LOC[COST_MIN[1]], LOC[COST_MIN[2]], COST_MIN[0]);
    printf("Distanta maxima:%s - %s (%dkm)\n",
           LOC[COST_MAX[1]], LOC[COST_MAX[2]], COST_MAX[0]);
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            S += B[i][j];
    printf("Cale ferata: %d\n", S / 2);
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (i != j && B[i][j] == 0)
                B[i][j] = INT_MAX / 2;

    g = drum_minim(B, adaugare("Bucuresti Nord", 0), &t);
    printf("%d\n", g[adaugare("Buzau", 0)]);
    x = adaugare("Buzau", 0);
    printf("%s ", LOC[x]);
    j = x;
    do
    {
        j = t[j];
        printf("<-%s ", LOC[j]);
    } while (j != 0);

    for (i = 0; i < N; i++)
        if (g[i] != INT_MAX / 2 && g[i] > Max)
        {
            Max = g[i];
            j = i;
        }
    printf("\nCea mai indepartata statie: %s - %dkm\n", LOC[j], Max);
    int p,u;
    Max=0;
    for(i=0;i<N;i++)
    {
        g=drum_minim(B,i,&t);
        for(j=0;j<N;j++)
        {
            if(g[j]!=INT_MAX/2 && g[j]>Max)
            {
                Max=g[j];
                p=i;
                u=j;
            }
        }
    }
    printf("%s - %s %d\n",LOC[p],LOC[u],Max);
    g = drum_minim(B, 0, &t);
    x = adaugare("Oradea", 0);
    ORADEA=fopen("bucN_oradea.txt","wt");
    while (g[x] != INT_MAX / 2)
    {
        j = x;
         fprintf(ORADEA,"%s",LOC[x]);
        do
        {
            j = t[j];
            fprintf(ORADEA,"<-%s ", LOC[j]);
            B[x][j]=INT_MAX/2;
            B[j][x]=INT_MAX/2;
        } while (j != 0);
        fprintf(ORADEA,"\n\n\n");
        g = drum_minim(B, 0, &t);
    }
    */

    
    return 0;
}