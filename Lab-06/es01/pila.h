#define N 36

typedef struct nodo2 *lista2;


struct voti2
{
	int crediti2;
	float media2;	
	
}voti2;

struct nodo2
{
	lista2 prec2;
	char nome2[N];
	char cognome2[N];
	char matricola2[N];
	struct voti2 voto2;
	lista2 succ2;
	
}nodo2;

lista2 t2 ,first2;


void Nelementi2(int conta2);
lista2 InsTesta2(lista2 t2 , lista2 first2 , int conta2); 
void Stampa2(lista2 t2, lista2 first2 , int conta2);
lista2 Insert2(lista2 t2);
void Destroy2(lista2 t2);
lista2 EstrTesta(lista2 t2 , lista2 first2 , int conta2);
