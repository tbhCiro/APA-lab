#include <stdio.h>
#include "item.h"

FILE *f1;
FILE *f2;

int n_element();
Item Init_bag();
Item InsertionSort();
void Stampa_bag();
void Greedy_mano(int n , int i, Item *t ,int somma, float kg , float peso);
void Greedy_stiva(int n, int i ,Item *t,float kg,float peso);
int Compare();
