#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"funcoes.h"
#define INICIO NULL
#define FIM NULL

int main()
{
    FILE *dados;
    int opcao;
    contato *lista = INICIO;  
    char arquivo[]="contatos.txt";

    dados = abriArquivo(arquivo);
    
    do
    {   
        printf("\nEscolha uma opção\n");
        printf("1 - Inserir novo contato\n");
        printf("2 - Remover registros que contenham certa string no nome\n");
        printf("3 - Visualizar registros que contenham certa string no nome\n");
        printf("4 - Visualizar elementos\n");
        printf("0 - Sair\n");
        scanf("%d",&opcao); 

        switch(opcao)
        {
        case 1:
            lista = criaElemento(lista);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }

        printf("\e[H\e[2J");

    } while (opcao!=0);

    fclose(dados);
    libera(lista);
    
    return 0;
}