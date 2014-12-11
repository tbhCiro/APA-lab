#define N 4 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bag.h"

int n_element(){
	int n;
	fscanf(f1,"%d",&n);
	return n;
}
Item Init_bag(Item *t){
	fscanf(f1,"%s",(*t)->nome); //printf("%s ",t->nome);
	fscanf(f1,"%f",&(*t)->peso);//printf("%f ",t->peso);
	fscanf(f1,"%d",&(*t)->indice);//printf("%d \n",t->indice);
	(*t)->flag = 0; 
return *t;
}

void Stampa_bag(Item t){
	printf("%s ",t->nome);
	printf("%.2f ",t->peso);
	printf("%d ",t->indice);
	printf("%d \n",t->flag);
}

Item InsertionSort(int a , Item *t , int l , int r){
	Item x;
	x=malloc(sizeof(Item));
	int i,j;
	r=r-1;
	
	for(i=l+1;i<=r;i++)
	{
		x=t[i];
		j=i-1;
		while(j>=l && Compare(a,t[j],x)==0){		//funzione Compare che confronta , a turno , il peso e l'importanza
			t[j+1] = t[j];
			j--;
		}
		t[j+1]= x;
	}
	return *t;
}
void Greedy_mano(int n , int i, Item *t ,int somma, float kg , float peso){
	if(i<n){
		kg = kg + (float) t[i]->peso; 		
		//somma=somma + (float)t[i]->indice;
		if(kg<=peso){	
			t[i]->flag=1;
			fprintf(f2,"Peso %.2f - Importanza %d - Nome: %s \n",t[i]->peso,t[i]->indice,t[i]->nome);	
		}
		else{
			kg = kg - (float)t[i]->peso; 		
			//somma=somma - (float)t[i]->indice;
		}	
		Greedy_mano(n,i+1,t,somma,kg,peso);
	}
}
int Compare(int a , Item t , Item x ){
	if(a==0){
		if(x->indice > t->indice)
			return 0;
		else 
			return 1;
	}
	else
		if (x->peso > t->peso)
			return 0;
		else
			return 1;
}
void Greedy_stiva(int n, int i ,Item *t,float kg,float peso){
	if(i<n){
		kg = kg + (float) t[i]->peso; 		
		if(kg<=N && t[i]->flag==0){	
			t[i]->flag=1;
			fprintf(f2,"Peso %.2f - Importanza %d - Nome: %s \n",t[i]->peso,t[i]->indice,t[i]->nome);	
		}
		else{
			kg = kg - (float)t[i]->peso; 		
		}	
		Greedy_stiva(n,i+1,t,kg,peso);
	}
}

 
