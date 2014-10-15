#include <stdio.h>

int main(){
		
	int n,fact=0;
	printf("inserisci un numero");
	scanf("%d",&n);
	
	if(n==1)
		return 0;
	fact=2;
	while(n % fact != 0)
		fact=fact+1;
		
	return(fact == n);
}
