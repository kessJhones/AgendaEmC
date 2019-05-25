#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"funcoes.h"
#define INICIO NULL
#define FIM NULL

//Abre o arquivo 
FILE* abriArquivo(char *arquivo)
{
    FILE *a;
    //Abre arquivo
    a = fopen("contatos.txt","a+");
    if(a==NULL)
        exit(1);
    return a;
}

//cria elemento na lista
contato* criaElemento(contato* lista)
{
    char nome[]={"joao normal"};
    contato *elem;
    //Aloca elemento
    elem = (contato*)malloc(sizeof(contato));
    if(elem==NULL){
        exit(-1);
    }

    //Inseri no inicio da lista
    if(lista==INICIO){
        elem->anterior = INICIO;
        elem->proximo = FIM;
    }
    else if(lista->anterior==INICIO) 
    {
        elem->anterior = INICIO;
        elem->proximo = lista;
        lista->anterior = elem;
    }
    else if(lista->proximo==FIM)
    {
        elem->proximo = FIM;
        lista->proximo = elem;
        elem->anterior = lista; 
    }
    else
    {
        elem->proximo = lista;
        elem->anterior = lista->anterior;
        lista->anterior = elem->anterior;
    }

    preencheContato(elem,nome);

    return elem;
}

//Preenche os dados do contato
void preencheContato(contato* cont,char *nome)
{
    strcmp(cont->nome,nome);

    do{
        getchar();
        printf("Telefone (no formato xxxxx-xxxx):");
        scanf("%[^\n]",cont->telefoneCelular);
    }while(cont->telefoneCelular[5]!='-' && strlen(cont->telefoneCelular)!=10);

    getchar();
    printf("Endereco:");
    scanf("%[^\n]",cont->endereco);

    getchar();
    printf("CEP:");
    scanf("%u",&cont->CEP);

   do{
        getchar();
        printf("Data de nascimento(no formato dd/mm/aaaa):");
        scanf("%[^\n]",cont->dataNascimento);
    }while(cont->dataNascimento[2]!='/' || cont->dataNascimento[5]!='/' && strlen(cont->dataNascimento)!=10);
}

void excluiElemento(contato* elem)
{
    contato* aux;

    if(elem->anterior==INICIO)
    {
        aux = elem->proximo;
        aux->anterior = INICIO;
        free(elem); 
    }
    else if(elem->proximo=FIM)
    {
        aux = elem->anterior;
        aux->proximo = FIM;
        free(elem);
    }
    else 
    {
        aux = elem->anterior;
        aux->proximo = elem->proximo;
        aux = elem->proximo;
        aux->proximo = elem->proximo;
        free(elem);
    }
}

//Libera a lista
void libera(contato *l)
{
    contato *atual;

    for(atual = l; atual->proximo != FIM; l = atual)
    {
        atual = atual->proximo;
        free(l);
    }
    free(atual);
}