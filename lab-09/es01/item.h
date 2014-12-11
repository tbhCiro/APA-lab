#define M 30
typedef struct oggetti *Item;
struct oggetti {
	
	char nome[M];
	float peso;
	int indice;
	int flag;
	
};
Item *t;
