#define N 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int numeri[N]={5,6,7,8};	
	int i,j,k;
	int n;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			for(k=0;k<N;k++){
					n=numeri[i]*100 + numeri[j]*10 + numeri[k];
					if(n%7==0)
						printf("%d\n",n);
			}
	return 0;
}
