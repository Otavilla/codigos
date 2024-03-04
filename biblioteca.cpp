#include<stdio.h>
#define N 10

struct livro {
    char titulo[100], autor[100];
    int paginas;

    void ler(){
        printf("Digite o titulo do livro: ");
        scanf("%[^\n]%*c", titulo);
        printf("Digite o autor do livro: ");
        scanf("%[^\n]%*c", autor);
        printf("Digite a quantidade de paginas do livro: ");
        scanf("%d%*c", &paginas);
        printf("\n");
    }

    void imprimir(){
        printf("Titulo: %s\n", titulo);
        printf("Autor: %s\n", autor);
        printf("Quantidade de paginas: %d\n", paginas);
        printf("\n");

    }
};

struct biblioteca {
    int i = 0, q, m = 0;
    livro l[N];
    char *npag;

    void cadastro(){
        int i = 0;
        do {
        printf("Qual a quantidade de itens para cadastro: ");
        scanf("%d%*c", &q);
        if (q > 10){
            printf("ERROR: A quantidade de itens nao pode ser maior que 10 tente um valor menor.\n\n");
        }
        } while (q > 10);

        for(i = 0; i < q; i++)
        {
            l[i].ler();
        }

    }

        void maior(){
        for(i = 0; i < q; i++)
        {
            if(l[i].paginas > m){
                m = l[i].paginas;
                npag = l[i].titulo;
            }
        }
    }

    void listarlivros(){
        for(i = 0; i < q; i++)
        {
            l[i].imprimir();
        }
        printf("O livro com mais paginas e %s com %d paginas. \n\n", npag, m);
    }
};

int main() {
    biblioteca b;
    int opcao = 0;

    do {
    printf("MENU PRINCIPAL\n");
    printf("1 - Cadastrar Livros\n");
    printf("2 - Listar Livros Cadastrados\n");
    printf("3 - SAIR\n");

    scanf("%d", &opcao);
    if (opcao == 1){
    b.cadastro();
    } else if(opcao == 2){
    b.maior();
    b.listarlivros();
    }
    } while (opcao != 3);

    return 0;
}

