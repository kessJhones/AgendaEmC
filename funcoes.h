typedef struct elementoAgenda
{
    char nome[101];
    char telefoneCelular[11];
    char endereco[101];
    unsigned int CEP[10];
    char dataNascimento[11];
    struct elementoAgenda *proximo;
    struct elementoAgenda *anterior;

}contato;

FILE* abriArquivo(char *);

contato* criaElemento(contato*);

void preencheContato(contato*,char*);

void libera(contato *);

void excluiElemento(contato *);