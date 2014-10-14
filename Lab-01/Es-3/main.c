#define N 30

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fperiodica(char *stringa); //prototipo della funzione


int main(void)
{
	char str[N];
	int F;
	
	printf("Programma che Cerca Periodicità Nella stringa , Digitare Stop per Uscire\n");
	
	while(strcmp(str,"stop")){
		
	printf("Stringa? ");
	scanf("%s",str);
	
		if(strlen(str) >= N)
			printf("Lunghezza Stringa > %d \n",N);
		else{
			F=fperiodica(str);	
			switch(F){
			case -1: printf("\nLa Stringa %s non è periodica.\n",str);break;
			case 0: printf("\nProgramma Terminato.\n");break;
			default: printf("\nLa Stringa %s è Periodica (Periodo %d).\n",str,F);break;
			}
		
		}	
		
	}
return 0;
}

int fperiodica(char *stringa)
{
	
	int flag=0,conta=0,i,m=2;
		
	if(strcmp(stringa,"stop")==0)  //se la stringa è stop , ritorna come valore 0 
			return 0;
		
	if(strlen(stringa)==1) 	//se la stringa è lunga 1 , ritorna -1
		return -1;
				
	for(i=0;i<strlen(stringa);i++)	//scandisco il vettore stringa per vedere se tutti gli elementi sono uguali 
		if(stringa[0]!=stringa[i])
			flag=1;

	while(strlen(stringa) % m !=0)	//Se la lunghezza della stringa è un numero primo può essere solo Periodica 1 o non Periodica
		m=m+1;							//Quindi vedo se il numero è primo				
	if(strlen(stringa)==m && flag==1)	//Se è un numero primo e non è una stringa di caratteri tutti uguali,allora non è Periodica
		return -1;						//la variabile m ha una doppia funzione. Per i numeri non primi è il minimo numero di Periodicità
	else if(flag==0)					//Se è un numero primo e ha tutti i caratteri uguali , Allora periodica di Periodo 1
		return m=1;
	
	i=0;
		while(m < (strlen(stringa)) - i){  //finche m è minore della lunghezza della stringa -i es "abcabcabc" lung stringa = 9 m minimo=3 
			if(strlen(stringa) % m ==0){	//la lunghezza della stringa deve essere divisibile per m , altrimenti non ho un numero finito di sottostringhe 
				if(stringa[i]!=stringa[i+m]){  //confronto carattere per carattere					
					conta++;
					i=0;						
					m=m+1;				//se un carattere è diverso , aumento il numero del periodo
				}else{
					conta=-1;			
					i++;
				}	
			}else{					
				m=m+1;					//anche nel caso in cui la lunghezza non sia divisibile per m
				i=0;
			}
		}
				
		if(conta==-1)					//se la conta è rimasta un numero fisso , ritorna m
			return m;
		else
			return -1;					//se no , non è periodico , ritorna -1
}
/* Note Aggiuntive:
 Ho adoperato questo tipo di soluzione perchè N non è molto grande
 e posso escludere subito , senza particolari calcoli , le stringhe con lunghezza "prima". 
 */
