#define N 36

typedef struct nodo4 *lista4;


struct voti4
{
	int crediti4;
	float media4;	
	
}voti4;

struct nodo4
{
	lista4 prec4;
	char nome4[N];
	char cognome4[N];
	char matricola4[N];
	struct voti4 voto4;
	lista4 succ4;
	
}nodo4;

lista4 t4 ,first4,a4,tmp4,tmp5;


void Nelementi4(int conta4);
lista4 InsPosizione4(lista4 t4 , lista4 first4 , int conta4 , lista4 a4 , lista4 tmp4); 
void Stampa4(lista4 t4, lista4 first4 , int conta4);
lista4 Insert4(lista4 t4);
void Destroy4(lista4 t4);
lista4 EstrTesta3(lista4 t4 , lista4 first4 , int conta4);
