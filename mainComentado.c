#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Definição de constantes para limites de array
#define MAX_CLIENTES 100
#define MAX_PRODUTOS 50
#define MAX_PEDIDOS 100
#define MAX_SERVICOS 50

// Definição da estrutura Cliente
typedef struct {
    char nome[100];
    int idade;
    char email[100];
    char telefone[20];
    char endereco[200];
    char UF[3];
} Cliente;

// Definição da estrutura Produto
typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

// Definição da estrutura Pedido
typedef struct {
    int id;
    int cliente_id;
    int produto_id;
    char status[20];
} Pedido;

// Definição da estrutura Servico
typedef struct {
    int id;
    char tipo[50];
    float valor;
} Servico;

// Declaração de arrays para armazenar dados
Cliente clientes[MAX_CLIENTES];
Produto produtos[MAX_PRODUTOS];
Pedido pedidos[MAX_PEDIDOS];
Servico servicos[MAX_SERVICOS];

// Variáveis para rastrear o número de itens em cada array
int numClientes = 0;
int numProdutos = 0;
int numPedidos = 0;
int numServicos = 0;

// Função para verificar se um cliente já existe
int verificarClienteExistente(char nome[]) {
    int i;
    for (i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].nome, nome) == 0) {
            return i;  // Retorna o índice do cliente encontrado
        }
    }
    return -1; // Cliente não encontrado
}

// Função para cadastrar um novo cliente
void cadastrarCliente() {
    system("cls");  // Limpa a tela (funciona apenas no Windows)
	
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
    system("cls");  // Limpa a tela após a operação (funciona apenas no Windows)
}

// Função para listar clientes de um determinado estado
void listarClientesEstado(char estado[]) {
    int i;
    
    printf("Clientes no Estado %s:\n", estado);
    
    for (i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].UF, estado) == 0) {
            printf("Nome: %s, Idade: %d, Email: %s, Telefone: %s, Endereço: %s, UF: %s\n", clientes[i].nome, clientes[i].idade, clientes[i].email, clientes[i].telefone, clientes[i].endereco, clientes[i].UF);
        }
    }
}

// Função para realizar um pedido
void realizarPedido(int cliente_id) {
    if (cliente_id < 0) {
        printf("Cliente não encontrado. Faça o cadastro primeiro.\n");
        return;
    }

    printf("Realizando Pedido:\n");

    int continuarPedido = 1;
    while (continuarPedido) {
        // Lógica para mostrar os produtos disponíveis e permitir que o cliente faça pedidos
        // Exemplo:
        printf("1. Café\n");
        printf("2. Lanche\n");
        printf("3. Sobremesa\n");
        printf("Escolha o produto (1-3): ");
        int opcaoProduto;
        scanf("%d", &opcaoProduto);

        if (opcaoProduto >= 1 && opcaoProduto <= 3) {
            // Registra o pedido
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

// Função para cadastrar um prestador de serviço
void cadastrarPrestadorServico() {
    system("cls");
    
    printf("Cadastro de Prestador de Serviço:\n");
    printf("Tipo de Serviço: ");
    scanf("%s", servicos[numServicos].tipo);
    printf("Valor: ");
    scanf("%f", &servicos[numServicos].valor);
    servicos[numServicos].id = numServicos + 1;
    numServicos++;
    printf("Prestador de Serviço cadastrado com sucesso!\n");
}

// Função para listar prestadores de serviço de um determinado tipo
void listarPrestadoresServicoTipo() {
    system("cls");
    
    int i;
    char tipo[50];
    printf("Informe o tipo de serviço para listar os prestadores: ");
    scanf("%s", tipo);

    int prestadoresEncontrados = 0;

    for (i = 0; i < numServicos; i++) {
        if (strcmp(servicos[i].tipo, tipo) == 0) {
            if (prestadoresEncontrados == 0) {
                printf("\nPrestadores de Serviço do Tipo %s:\n", tipo);
                printf("%-5s %-20s %-10s\n", "ID", "Tipo de Serviço", "Valor");
                printf("---------------------------------------\n");
            }
            printf("%-5d %-20s %-10.2f\n", servicos[i].id, servicos[i].tipo, servicos[i].valor);
            prestadoresEncontrados++;
        }
    }

    if (prestadoresEncontrados == 0) {
        printf("Nenhum prestador de serviço encontrado do tipo %s.\n", tipo);
    }
}

// Função para listar todos os prestadores de serviço
void listarTodosPrestadoresServico() {
    system("cls");
    
    int i;
    
    if (numServicos == 0) {
        printf("Nenhum prestador de serviço cadastrado.\n");
        return;
    }

    printf("\nLista de Todos os Prestadores de Serviço:\n");
    printf("%-5s %-20s %-10s\n", "ID", "Tipo de Serviço", "Valor");
    printf("---------------------------------------\n");

    for (i = 0; i < numServicos; i++) {
        printf("%-5d %-20s %-10.2f\n", servicos[i].id, servicos[i].tipo, servicos[i].valor);
    }
}

// Função para listar serviços em ordem crescente de valor
void listarServicosOrdemCrescenteValor() {
    system("cls");
    
    int i, j;
    
    if (numServicos == 0) {
        printf("Nenhum serviço cadastrado.\n");
        return;
    }

    // Ordenação por bubble sort
    for (i = 0; i < numServicos - 1; i++) {
        for (j = 0; j < numServicos - i - 1; j++) {
            if (servicos[j].valor > servicos[j + 1].valor) {
                // Troca os elementos se estiverem fora de ordem
                Servico temp = servicos[j];
                servicos[j] = servicos[j + 1];
                servicos[j + 1] = temp;
            }
        }
    }

    printf("\nLista de Serviços em Ordem Crescente de Valor:\n");
    printf("%-5s %-20s %-10s\n", "ID", "Tipo de Serviço", "Valor");
    printf("---------------------------------------\n");

    for (i = 0; i < numServicos; i++) {
        printf("%-5d %-20s %-10.2f\n", servicos[i].id, servicos[i].tipo, servicos[i].valor);
    }
}

// Função para listar clientes em ordem crescente de nome
void listarClientesOrdemCrescenteNome() {
    system("cls");
    
    int i, j;
    
    if (numClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    // Ordenação por bubble sort
    for (i = 0; i < numClientes - 1; i++) {
        for (j = 0; j < numClientes - i - 1; j++) {
            if (strcmp(clientes[j].nome, clientes[j + 1].nome) > 0) {
                // Troca os elementos se estiverem fora de ordem
                Cliente temp = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = temp;
            }
        }
    }

    printf("\nLista de Clientes em Ordem Crescente de Nome:\n");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < numClientes; i++) {
        printf("%-20s\n", clientes[i].nome);
    }
}

// Função principal
int main() {
    setlocale(LC_ALL, "");  // Configura a localidade para a padrão do sistema
    
    int opcao;
    char nomeCliente[50];
    
    do {
        printf("\nMenu:\n");
        printf("1. Fazer Pedido\n");
        printf("2. Cadastrar Cliente\n");
        printf("3. Cadastrar Prestador de Serviço\n");
        printf("4. Listar os Clientes de um Determinado Estado\n");
        printf("5. Listar os Prestadores de Serviço de um Determinado Tipo\n");
        printf("6. Listar Todos os Prestadores de Serviço\n");
        printf("7. Listar Serviços em Ordem Crescente de Valor\n");
        printf("8. Listar Clientes em Ordem Crescente de Nome\n");
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
	    case 5:
		listarPrestadoresServicoTipo();
		break;
	    case 6:
                listarTodosPrestadoresServico();
                break;
            case 7:     
		listarServicosOrdemCrescenteValor();
                break;
            case 8:
                listarClientesOrdemCrescenteNome();
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
