#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100
#define MAX_PRODUTOS 50
#define MAX_PEDIDOS 100
#define MAX_MUSICAS 50

typedef struct {
    char nome[100];
    int idade;
    char email[100];
    char telefone[20];
    char endereco[200];
    char UF[3];
} Cliente;

typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

typedef struct {
    int id;
    int cliente_id;
    int produto_id;
    char status[20];
} Pedido;

typedef struct {
    char titulo[50];
    char artista[50];
} Musica;

Cliente clientes[MAX_CLIENTES];
Produto produtos[MAX_PRODUTOS];
Pedido pedidos[MAX_PEDIDOS];
Musica musicas[MAX_MUSICAS];

int numClientes = 0;
int numProdutos = 0;
int numPedidos = 0;
int numMusicas = 0;

// Funções de cadastro
int verificarClienteExistente(char nome[]) {
int i;
    for ( i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].nome, nome) == 0) {
            return i;  // Retorna o índice do cliente encontrado
        }
    }
    return -1; // Cliente não encontrado
}

void cadastrarCliente() {
    system("cls");
		
    if (numClientes < MAX_CLIENTES) {
        printf("Adicionar novo cliente:\n");
        printf("Nome: ");
        scanf("%s", clientes[numClientes].nome);
        printf("Idade: ");
        scanf("%d", &clientes[numClientes].idade);
        printf("Email: ");
        scanf("%s", clientes[numClientes].email);
        printf("Telefone: ");
        scanf("%s", clientes[numClientes].telefone);
        printf("Endereço: ");
        getchar(); // Limpa o buffer do teclado
        fgets(clientes[numClientes].endereco, sizeof(clientes[numClientes].endereco), stdin);
        printf("UF: ");
        scanf("%s", clientes[numClientes].UF);
        numClientes++;
    } else {
        printf("Limite máximo de clientes atingido.\n");
    }
    system("cls");
}

void listarClientesEstado(char estado[]) {
	
	
	int i;
	
    printf("Clientes no Estado %s:\n", estado);
    // Adicione aqui a lógica para listar clientes de um determinado estado
    // Exemplo:
    for (i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].UF, estado) == 0) {
            printf("Nome: %s, Idade: %d, Email: %s, Telefone: %s, Endereço: %s, UF: %s\n", clientes[i].nome, clientes[i].idade, clientes[i].email, clientes[i].telefone, clientes[i].endereco, clientes[i].UF);
        }
    }
    
}

void realizarPedido(int cliente_id) {
	
    if (cliente_id < 0) {
        printf("Cliente não encontrado. Faça o cadastro primeiro.\n");
        return;
    }

    printf("Realizando Pedido:\n");

    int continuarPedido = 1;
    while (continuarPedido) {
        // Implemente a lógica para mostrar os produtos disponíveis e permitir que o cliente faça pedidos
        // ...

        // Exemplo:
        printf("1. Café\n");
        printf("2. Lanche\n");
        printf("3. Sobremesa\n");
        printf("Escolha o produto (1-3): ");
        int opcaoProduto;
        scanf("%d", &opcaoProduto);

        if (opcaoProduto >= 1 && opcaoProduto <= 3) {
            // Registre o pedido
            pedidos[numPedidos].id = numPedidos + 1;
            pedidos[numPedidos].cliente_id = cliente_id;
            pedidos[numPedidos].produto_id = opcaoProduto;
            strcpy(pedidos[numPedidos].status, "Em andamento");
            numPedidos++;
            printf("Pedido adicionado ao carrinho.\n");

            printf("Deseja adicionar mais produtos? (1 - Sim, 0 - Finalizar): ");
            scanf("%d", &continuarPedido);
        } else {
            printf("Opção inválida.\n");
        }
    }

    printf("Pedido finalizado. Seu número de pedido (senha) é: %d\n", numPedidos);
}

void cadastrarPrestadorServico() {
    // Implemente a lógica para cadastrar prestadores de serviços
    // ...
}

// ... outras funções conforme necessário

int main() {
    int opcao;
    char nomeCliente[50];
    do {
        printf("\nMenu:\n");
        printf("1. Fazer Pedido\n");
        printf("2. Cadastrar Cliente\n");
        printf("3. Cadastrar Prestador de Serviço\n");
        printf("4. Listar os clientes de um determinado estado\n");
        printf("0. Sair\n");
        printf("Escolha a opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            	system("cls");
            	
                printf("Informe seu nome: ");
                scanf("%s", nomeCliente);
                int indiceCliente = verificarClienteExistente(nomeCliente);
                if (indiceCliente >= 0) {
                    realizarPedido(indiceCliente);
                } else {
                    printf("Cliente não encontrado. Deseja cadastrar? (1 - Sim, 0 - Não): ");
                    int cadastrarNovoCliente;
                    scanf("%d", &cadastrarNovoCliente);
                    if (cadastrarNovoCliente == 1) {
                        cadastrarCliente();
                    } else {
                        printf("Operação cancelada.\n");
                    }
                }
                break;
            case 2:
                cadastrarCliente();
                break;
            case 3:
                cadastrarPrestadorServico();
                break;
            case 4:
				{
					system("cls");
					
                   	char estado[3];
                    printf("Digite o estado: ");
                    scanf("%s", estado);
                    listarClientesEstado(estado);
					}     
				break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
