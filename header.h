#include <stdio.h>
#include <string.h>
#define DIM 35
#define MAX_ORASE 1000
char **LOC;
int N,v[1000];
char **alocare_loc();
int adaugare(char *loc,int *cost);
void verificare(void *p);
void conversie(char v[]);
int **alocare();
int bfs(int x,int **A,FILE *f);
void dfs(int k,int **A,FILE *f);
int *drum_minim(int **a,int s,int **t);