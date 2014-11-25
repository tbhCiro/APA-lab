typedef struct coda *Item;

static int conta;

struct dati{
	char *nome;
}dati;

struct coda{
	struct dati *p;
	int head,tail;

}coda;

Item t;
