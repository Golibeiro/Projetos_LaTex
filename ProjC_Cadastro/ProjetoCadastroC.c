#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar dados de um produto
struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
};

// Funcao para cadastrar produtos
void cadastrarProdutos(struct Produto *produtos, int quantidade) {
    for (int i = 0; i < quantidade; i++) {

        printf("\n----------------------------------------\n");
        printf("CADASTRO DO PRODUTO %d\n", i + 1);
        printf("----------------------------------------\n");
        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);

        getchar();
        // Remove o '\n' deixado pelo scanf

        printf("Nome: ");
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);

        // Remove o '\n' do final da string
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';

        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
        printf("Quantidade disponivel: ");
        scanf("%d", &produtos[i].quantidade);
    }
}

void listarProdutos(struct Produto *produtos, int quantidade) {
    printf("\n\n----------------------------------------\n");
    printf("PRODUTOS CADASTRADOS\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < quantidade; i++) {
        float valorEstoque = produtos[i].preco * produtos[i].quantidade;

        printf("\n----- PRODUTO %d -----\n", i + 1);
        printf("Codigo: %d\n", produtos[i].codigo);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preco: R$ %.2f\n", produtos[i].preco);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("Valor em estoque: R$ %.2f\n", valorEstoque);
    }
}

// Funcao para exibir resumo
void exibirResumo(struct Produto *produtos, int quantidade) {
    float valorTotal = 0.0;
    float maiorPreco = produtos[0].preco;
    int indiceMaisCaro = 0;

    for (int i = 0; i < quantidade; i++) {
        valorTotal += produtos[i].preco * produtos[i].quantidade;

        if (produtos[i].preco > maiorPreco) {
            maiorPreco = produtos[i].preco;
            indiceMaisCaro = i;
        }
    }

    printf("\n\n----------------------------------------\n");
    printf("RESUMO DO ESTOQUE\n");
    printf("----------------------------------------\n");
    printf("Valor total do estoque: R$ %.2f\n", valorTotal);
    printf("Produto mais caro sera: %s\n", produtos[indiceMaisCaro].nome);
    printf("O preco do produto mais caro: R$ %.2f\n", maiorPreco);
}

int main() {
    struct Produto *produtos;
    int quantidade;

    printf("----------------------------------------\n");
    printf("SISTEMA DE CADASTRO DE PRODUTOS\n");
    printf("----------------------------------------\n");
    printf("Quantos produtos deseja cadastrar (1 a 10)? ");
    scanf("%d", &quantidade);

    if (quantidade < 1 || quantidade > 10) {
        printf("Erro: quantidade invalida.\n");
        return 1;
    }

    // Alocacao dinamica
    produtos = malloc(quantidade * sizeof(struct Produto));

    if (produtos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    cadastrarProdutos(produtos, quantidade);
    listarProdutos(produtos, quantidade);
    exibirResumo(produtos, quantidade);

    free(produtos);
    produtos = NULL;

    return 0;
}