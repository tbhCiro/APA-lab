#define N 36

typedef struct nodo *lista;


struct voti
{
	int crediti;
	float media;	
	
}voti;

struct nodo
{
	lista prec;
	char nome[N];
	char cognome[N];
	char matricola[N];
	struct voti voto;
	lista succ;
	
}nodo;

lista t ,first ,last ,a , tmp;
void Nelementi(int conta);
lista InsCoda(lista t , lista first , int conta , lista a );
lista InsTesta(lista t , lista first , int conta); 
void Stampa(lista t , lista first , int conta , lista last);
lista Insert(lista t);
lista SearchDestroy(int scelta3 , lista t , lista first , int flag2 , lista a , lista tmp);
void Destroy(lista t);
lista Canc(lista t , lista first , lista a);



