#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_non_ordinata.h"
#include "pila.h"
#include "coda.h"
#include "coda_prioritaria.h"


//instruzioni per i prossimi lab: ADT completo! , struct in un item.c e item.h 


int main()
{
	int scelta;
	int scelta2;
	int scelta3;
	int conta=0;
	int flag2;
	t=NULL ,first=NULL ,last=NULL , a=NULL , tmp=NULL;
		
	do{
		system("clear");
		printf("Scegli un tipo di lista");
		printf("\n1. Lista non ordinata");
		printf("\n2. Pila");
		printf("\n3. Coda");
		printf("\n4. Coda Prioritaria");	
		printf("\n5. Uscita");
		printf("\n: ");
		scanf("%d",&scelta);	
		if(scelta==1){
			do{
				printf("\nScegli Comando (lista non ordinata)");
				printf("\n1. Visualizza Cardinalità");
				printf("\n2. Inserimento in Testa");
				printf("\n3. Inserimento in Coda");
				printf("\n4. Ricerca per Chiave");
				printf("\n5. Estrazione elementi per Chiave");
				printf("\n6. Stampa lista");
				printf("\n7. Distruzione Lista");
				printf("\n8: Ritorna al menù");
				printf("\n: ");
				scanf("%d",&scelta2);
				switch(scelta2){
					case 1:	Nelementi(conta); break;
					case 2:		
						t=malloc(sizeof *t);
						t=Insert(t);
						first=InsTesta(t,first,conta);
						if(conta==0)
							a=first;
						conta++;
					break;
					case 3:			
						t=malloc(sizeof *t);
						t=Insert(t);
					
						if(conta==0){
							first=InsCoda(t,first,conta,a);
							a = first;
						}
						else
							a=InsCoda(t,first,conta,a);
						conta++;
					break;
					case 4:		
						printf("\n Ricerca per: ");
						printf("\n1. Ricerca per Nome");
						printf("\n2. Ricerca per Cognome");
						printf("\n3. Ricerca per Matricola");
						printf("\n4. Ricerca per Crediti");
						printf("\n5. Ricerca per Media");
						printf("\n: ");
						scanf("%d",&scelta3);
						first=SearchDestroy(scelta3 ,t,first,flag2=0,a,tmp);
					break;
					case 5:			
						printf("\n Cancellazione per: ");
						printf("\n1. Ricerca per Nome");
						printf("\n2. Ricerca per Cognome");
						printf("\n3. Ricerca per Matricola");
						printf("\n4. Ricerca per Crediti");
						printf("\n5. Ricerca per Media");
						printf("\n: ");
						scanf("%d",&scelta3);
						first=SearchDestroy(scelta3 ,t,first,flag2=1,a,tmp);
						conta--;
					break;
					case 6:	Stampa(t,first,conta,last); break;
					case 7:			
						t=first;
						Destroy(t);
						//first=NULL;
						free(a);
						//free(first);
						free(tmp);
						free(last);
						conta=0;
					break;
				}
			}while(scelta2!=8);
			
						
		}else if(scelta==2){
			int conta2=0;
			do{
				printf("\nScegli Comando (pila)");
				printf("\n1. Visualizza Cardinalità");
				printf("\n2. Inserimento in Testa");
				printf("\n3. Estrazione elementi in testa");
				printf("\n4. Stampa lista");
				printf("\n5. Distruzione Lista");
				printf("\n6: Ritorna al menù");
				printf("\n: ");
				scanf("%d",&scelta2);
				
				switch(scelta2){
					case 1: Nelementi2(conta2); break; 
					case 2:
						t2=malloc(sizeof *t2);
						t2=Insert2(t2);
						first2=InsTesta2(t2,first2,conta2);
						conta2++;	
					break;
					case 3:
						first2=EstrTesta(t2,first2,conta2);
						conta2--;
					break;
					case 4: Stampa2(t2,first2,conta2); break;
					case 5:
						Destroy2(t2);
						conta2=0;
						
					break;	
				}
			}while(scelta2!=6);
			
			
		}else if(scelta==3){
			int conta3=0;
			do{	
				printf("\nScegli Comando (coda)");
				printf("\n1. Visualizza Cardinalità");
				printf("\n2. Inserimento in coda");
				printf("\n3. Estrazione elementi  in testa");
				printf("\n4. Stampa lista");
				printf("\n5. Distruzione Lista");
				printf("\n6: Ritorna al menù");
				printf("\n: ");
				scanf("%d",&scelta2);
					
				switch(scelta2){
					case 1: Nelementi3(conta3); break; 
					case 2:
						t3=malloc(sizeof *t3);
						t3=Insert3(t3);
					
						if(conta3==0){
							first3=InsCoda3(t3,first3,conta3,a3);
							a3 = first3;
						}
						else
							a3=InsCoda3(t3,first3,conta3,a3);
						conta3++;	
					break;
					case 3:
						first3=EstrTesta2(t3,first3,conta3);
						conta3--;
					break;
					case 4: Stampa3(t3,first3,conta3); break;
					case 5:
						Destroy3(t3);
						conta3=0;
						free(a3);
					break;	
				}	
			}while(scelta2!=6);
		
		}else if(scelta==4){
			int conta4=0;
			do{
				
				printf("\nScegli Comando (coda a priorita')");
				printf("\n1. Visualizza Cardinalità");
				printf("\n2. Inserimento nella posizione con priorità");
				printf("\n3. Estrazione elementi per priorità massima");
				printf("\n4. Stampa lista");
				printf("\n5. Distruzione Lista");
				printf("\n6: Ritorna al menù");
				printf("\n: ");
				scanf("%d",&scelta2);
				
				switch(scelta2){
					case 1: Nelementi4(conta4); break; 
					case 2:	 
					
						tmp4=malloc(sizeof *tmp4);
						t4=malloc(sizeof *t4);
						t4=Insert4(t4);
						if(conta4==0){		//caso lista vuota
							first4=InsPosizione4(t4,first4,conta4,a4,tmp4);
							a4 = first4;
						}
						else
							{
								tmp5=malloc(sizeof *tmp5);
								tmp5=InsPosizione4(t4,first4,conta4,a4,tmp4);	//chiamata a funzione
								
								/* questa parte dovrebbe aprire una funzione che resituisce 3 valori di ritorno , 
								 * ho diviso l'inserimento in 4 casi: Inserimento su lista vuota , Inserimento in Testa , 
								 * Inserimento in coda , Inserimento ordinato. Siccome non è implementata del tutto in maniera corretta
								 * Ho comunque consegnato questa parte dell'esercizio , e spiegato qua , in modo teorico , come dovrebbe funzionare l'inserimento
								 *  */
								if(tmp5==tmp4){
									if(a4==tmp5){
										t4->succ4=first4;
										t4->succ4->prec4 = t4;
										first4=t4;				//ins in testa , restituisce il nuovo primo elemento 
									}
									else{
										a4->succ4 = t4;			//ins in coda , modifica l'elemento rappresentante la coda (a4)
										t4->prec4 = a4;
										a4=t4;		
									}
								}
								else{	
										tmp5->prec4->succ4=t4;
										t4->prec4=tmp5->prec4;
										t4->succ4=tmp5;			//ins ordinato , inserimento del valore inserito , aggiunstando il puntatore a successivo/precedente
										tmp5->prec4=t4;	
									}	
							}
						conta4++;
					break;
					case 3: 				
						first4=EstrTesta3(t4,first4,conta4);
						conta4--;
					break;
					case 4: Stampa4(t4,first4,conta4); break;
					case 5: 
						Destroy4(t4);
						conta4=0;
						free(a4);		
					break;
				}
		}while(scelta2!=5);
	}		
	}while(scelta!=5);
	return 0;
}
