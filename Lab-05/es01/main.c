#include <stdio.h>
#include <stdlib.h>

void conversione(int num, int base , int resto);

int main (void){
	
	int num,base;
	int resto=0;
	printf("Inserisci un umero in base 10: ");
	scanf("%d",&num);
	printf("Inserisci la base di conversione: ");
	scanf("%d",&base);
	conversione(num,base,resto);	
	return 0;	
}
void conversione(int num,int base,int resto){
	if(num != 0){	
		conversione(num/base,base,num%base);
		printf("%d ",num%base);
	}
}
