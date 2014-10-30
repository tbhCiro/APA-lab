#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct studenti{
	
	char *nome;
	char *sesso;
	int  *data;
		
};

void InsertionSortS(struct studenti *stn, int *data , int n);
int main(int argc , char *argv[]){

	if(argc!=4){
		printf("Numero Argomenti non valido");
		return -1;		
	}
	
	FILE *f1;
	FILE *f2;
	FILE *f3;
		
	f1=fopen(argv[1],"r");
	f2=fopen(argv[2],"w");
	f3=fopen(argv[3],"w");
		
	if(!(f1 && f2 && f3)){
		printf("Errore Apertura File");
		return -1;
	}
			
	struct studenti *stn;
	int num;
	int i,j=0;
	char app[35 + 1];
	int *conta,conta2=0;
	int *dataunita;
	
	fscanf(f1,"%d",&num);
	conta=malloc( num * sizeof(int));
	i=0;
	while(!feof(f1)){
		fscanf(f1,"%s",app);
		conta2 = conta2 + strlen(app);
		if(i%3==0){
			conta[j]++;
			j++;
		}
		i++;
	}
	fseek(f1,1,0);
	dataunita=malloc((1) *  num * sizeof(int));
	stn=malloc(conta2 * sizeof(char));
		
	for(i=0;i<num;i++){
		stn[i].nome=malloc((conta[i]+1) * sizeof(char));
		stn[i].data=malloc((10+1) * sizeof(int));
		stn[i].sesso=malloc((1+1) * sizeof(char));
		fscanf(f1,"%s %d/%d/%d %s",stn[i].nome,&stn[i].data[0],&stn[i].data[1],&stn[i].data[2],stn[i].sesso);
		dataunita[i]=(stn[i].data[0]) + (stn[i].data[1] * pow(10,2)) + (stn[i].data[2] * pow(10,4));
		printf("DBG: nome--> %s , data--> %d %d %d  , sesso--> %s 	\n",stn[i].nome,stn[i].data[0],stn[i].data[1],stn[i].data[2],stn[i].sesso);	
	}	
	InsertionSortS(stn,&*dataunita,num);
		
	for(i=0;i<num;i++)
		printf("data--> %d %d %d\n",stn[i].data[0],stn[i].data[1],stn[i].data[2]);
	
	for(i=0;i<num;i++){
			if(strcmp(stn[i].sesso,"F"))
				fprintf(f2,"%s %d/%d/%d %s\n",stn[i].nome,stn[i].data[0],stn[i].data[1],stn[i].data[2],stn[i].sesso);
			else
				fprintf(f3,"%s %d/%d/%d %s\n",stn[i].nome,stn[i].data[0],stn[i].data[1],stn[i].data[2],stn[i].sesso);
		}
		free(conta);
		free(dataunita);
		for(i=0;i<num;i++){
			free(stn[i].nome);
			free(stn[i].data);
			free(stn[i].sesso);
		}
		free(stn);
return 0;
}
void InsertionSortS(struct studenti *stn ,int *data ,int n)
{
	int i,j,x,y,z,k;
	for(i=1;i<=n-1;i++){
		x =	data[i];
		y = stn[i].data[0];
		z = stn[i].data[1];
		k = stn[i].data[2];
		j= i -1;
		while(j>= 0 && x < data[j]){
			data[j+1]=data[j];
			stn[j+1].data[0]= stn[j].data[0];
			stn[j+1].data[1]= stn[j].data[1];
			stn[j+1].data[2]= stn[j].data[2];
			j--;
		}
			data[j+1]=x;
			stn[j+1].data[0]= y;
			stn[j+1].data[1]= z;
			stn[j+1].data[2]= k;
	}	
}
