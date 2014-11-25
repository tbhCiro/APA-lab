#define N 5
#define M 16
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stampa(char vocali[] , char consonanti[] , int n , int o , int p , int q);
void voc(char vocali[] , int n , int a);
void cons(char consonanti[] , int n , int b);

int main(int argc , char *argv[]){
	char vocali[N]={'a','e','i','o','u'};
	char consonanti[M]={'b','c','d','f','g','h','l','m','n','p','q','r','s','t','v','z'};
	int n=0,o=0,p=0,q=0;			
	stampa(vocali,consonanti,n,o,p,q);
	
	return 0;
}
int stampa(char vocali[] , char consonanti[] , int n , int o , int p , int q){
	if(q<N){	
		printf("%c%c%c%c\n",consonanti[n],vocali[o],consonanti[p],vocali[q]);	
		stampa(vocali,consonanti,n,o,p,q+1);	
	}
	if(p<M-1)
		stampa(vocali,consonanti,n,o,p+1,0);
	if(o<N-1)
		stampa(vocali,consonanti,n,o+1,0,0);
	if(n<M-1)
		stampa(vocali,consonanti,n+1,0,0,0);
	else
		stampa(vocali,consonanti,1000,1000,1000,1000);	
	
	return 0;
}
