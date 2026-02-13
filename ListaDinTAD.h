struct listaPalavra{
	ListaPalavra *ant, *prox;;
	char letra;
};typedef struct listaPalavra ListaPalavra;
struct listaPrin{
	int num;
	ListaPrin *botton, *top;
	ListaPalavra *lista;
};typedef struct listaPrin ListaPrin;

void iniciarListaPrin(ListaPrin **L);
void iniciarListaPalavra(ListaPalavra **L);
char filaPrinVazia(ListaPrin **L);
char filaPalavraVazia(ListaPalavra **L);
void retirarFilaPrin(ListaPrin **L);
void retirarFilaPalavra(ListaPalavra **L);
void inserirFilaPrin(ListaPrin **L);
void inserirFilaPalavra(ListaPalavra **L);

void iniciarListaPrin(ListaPrin **L){
	*L = malloc(sizeof(ListaPrin));
	*L.num = 0;
	*L.botton = NULL;
	*L.top = NULL;
	*L.lista = NULL;
}
