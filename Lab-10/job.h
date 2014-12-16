#include <stdio.h>
#include "item.h"

FILE *f1,*f2,*f3;


int numjob();
int numris();
void Init_job();
Item InsertionSort();
void Greedy_job(int pos , int n , int i, Item *t , float somma, float peso);
void Stampa_job();
