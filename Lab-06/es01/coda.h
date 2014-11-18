#define N 36

typedef struct nodo3 *lista3;

struct voti3
{
	int crediti3;
	float media3;	
	
}voti3;

struct nodo3
{
	lista3 prec3;
	char nome3[N];
	char cognome3[N];
	char matricola3[N];
	struct voti3 voto3;
	lista3 succ3;
}nodo3;

lista3 t3 ,first3  ,a3 ;


void Nelementi3(int conta3);
void Stampa3(lista3 t3, lista3 first3 , int conta3);
lista3 Insert3(lista3 t3);
void Destroy3(lista3 t3);
lista3 EstrTesta2(lista3 t3 , lista3 first3 , int conta3);
lista3 InsCoda3(lista3 t3 , lista3 first ,int conta3 , lista3 a3);
