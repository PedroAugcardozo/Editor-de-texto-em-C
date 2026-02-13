struct listaPalavra{
	listaPalavra *ant, *prox;;
	char letra;
};typedef struct listaPalavra ListaPalavra;
struct listaPrin{
	int num;
	listaPrin *botton, *top;
	listaPalavra *lista;
};typedef struct listaPrin ListaPrin;

void iniciarListaPrin(listaPrin **L);
void iniciarListaPalavra(listaPalavra **L);
char filaPrinVazia(listaPrin *L);
char filaPalavraVazia(listaPalavra *L);
void retirarFilaPrin(listaPrin **L);
void retirarFilaPalavra(listaPalavra **L);
void inserirFilaPrin(listaPrin **L);
void inserirFilaPalavra(listaPalavra **L);

void iniciarListaPrin(listaPrin **L){
	*L = NULL;
}
void iniciarListaPalavra(listaPalavra **L){
	*L = NULL;
}

char filaPrinVazia(listaPrin *L){
	return L == NULL;
}

char filaPalavraVazia(listaPalavra *L){
	
}

