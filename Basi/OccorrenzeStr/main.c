#define N 17
#include <stdio.h>

int main(){
	
		char vettore[N]={'a','b','b','b','b','c','c','d','d','d','e','e','e','e','e','e','e'};
		char appoggio;
		int appoggio2=0;
		int i,j=0;
		int indice,min=0;
		
		while(j<N){
			appoggio=vettore[j];
			for(i=0;i<N;i++){
				if(vettore[i]==appoggio)
					appoggio2++;
			}
			if(appoggio2 > min){	
				min = appoggio2;
				indice = j;
			}
			appoggio2=0;	
			j++;
		}
		printf("l'occasione più lunga è il carattere %c , che si ripete %d volte",vettore[indice],min);
		return 0;
}
