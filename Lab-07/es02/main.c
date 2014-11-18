#define N 5
#define M 16
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc , char *argv[]){
	if(argc != 2) return -1;
	FILE *f1;
	f1=fopen(argv[1],"w");
	if(!f1) return -1;
	int i,j,k,l;
	char vocali[N]={'a','e','i','o','u'};
	char consonanti[M]={'b','c','d','f','g','h','l','m','n','p','q','r','s','t','v','z'};
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			for(k=0;k<M;k++)
				for(l=0;l<N;l++)
					fprintf(f1,"%c%c%c%c\n",consonanti[i],vocali[j],consonanti[k],vocali[l]);		
	return 0;
}
