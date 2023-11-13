#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CLIENTES 100
#define MAX_PRESTADORES 100
#define MAX_SERVICOS 100

typedef struct {
    char nome[100];
    int idade;
    char email[100];
    char telefone[20];
    char endereco[200];
    char UF[3];
} Consumidor;

typedef struct {
    char nome[100];
    char enderecoEletronico[100];
    char email[100];
    char telefone[20];
    char endereco[200];
    char UF[3];
} PrestadorServico;

typedef struct {
    char detalhamento[200];
    char data[20];
    float preco;
} Servico;

typedef struct {
    char descricao[100];
    char tipo[50];
    Consumidor consumidor;
    float valorServico;
    PrestadorServico prestadorServico;
} ProdutoCafeteria;

ProdutoCafeteria produtos[MAX_SERVICOS];
Consumidor clientes[MAX_CLIENTES];
PrestadorServico prestadores[MAX_PRESTADORES];

int numClientes = 0;
int numPrestadores = 0;
int numServicos = 0;

void adicionarCliente() {
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

void adicionarPrestador() {
	system("cls");
	
    if (numPrestadores < MAX_PRESTADORES) {
        printf("Adicionar novo prestador de serviço:\n");
        printf("Nome: ");
        scanf("%s", prestadores[numPrestadores].nome);
        printf("Endereço Eletrônico: ");
        scanf("%s", prestadores[numPrestadores].enderecoEletronico);
        printf("Email: ");
        scanf("%s", prestadores[numPrestadores].email);
        printf("Telefone: ");
        scanf("%s", prestadores[numPrestadores].telefone);
        printf("Endereço: ");
        scanf("%s", prestadores[numPrestadores].endereco);
        printf("UF: ");
        scanf("%s", prestadores[numPrestadores].UF);
        numPrestadores++;
    } else {
        printf("Limite máximo de prestadores atingido.\n");
    }
    system("cls");
}

void listarTiposServicos() {
    printf("Tipos de Serviços Disponíveis:\n");
    // Adicione aqui a lógica para listar os tipos de serviços
    // Exemplo:
    printf("- Café\n");
    printf("- Chá\n");
    printf("- Sobremesa\n");
}

void listarClientes() {
	system("cls");
	
	int i;
	
    printf("Lista de Clientes:\n");
    
    for (i = 0; i < numClientes; i++) {
        printf("Nome: %s, Idade: %d, Email: %s, Telefone: %s, Endereço: %s, UF: %s\n", clientes[i].nome, clientes[i].idade, clientes[i].email, clientes[i].telefone, clientes[i].endereco, clientes[i].UF);
    }
    system("cls");
}

void listarPrestadores() {
	
	int i;
	
    printf("Lista de Prestadores de Serviços:\n");
    // Adicione aqui a lógica para listar todos os prestadores de serviços
    // Exemplo:
    for (i = 0; i < numPrestadores; i++) {
        printf("Nome: %s, Endereço Eletrônico: %s, Email: %s, Telefone: %s, Endereço: %s, UF: %s\n", prestadores[i].nome, prestadores[i].enderecoEletronico, prestadores[i].email, prestadores[i].telefone, prestadores[i].endereco, prestadores[i].UF);
    }
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

void listarPrestadoresServico(char tipo[]) {
	
	int i;
	
    printf("Prestadores de Serviço do Tipo %s:\n", tipo);
    // Adicione aqui a lógica para listar os prestadores de serviço de um determinado tipo
    // Exemplo:
    for (i = 0; i < numPrestadores; i++) {
        // Lógica para verificar o tipo de serviço
        // if (strcmp(prestadores[i].tipoServico, tipo) == 0) {
        //     printf("Nome: %s, Endereço Eletrônico: %s, Email: %s, Telefone: %s, Endereço: %s, UF: %s\n", prestadores[i].nome, prestadores[i].enderecoEletronico, prestadores[i].email, prestadores[i].telefone, prestadores[i].endereco, prestadores[i].UF);
        // }
    }
}

void estadoServicoMaisCaro() {
    printf("Estado(s) com o serviço mais caro:\n");
    // Adicione aqui a lógica para identificar o(s) estado(s) onde está registrado o serviço mais caro
    // Exemplo:
    // Encontre o serviço mais caro
    // Imprima o estado associado a esse serviço
}

void listarServicosCrescente() {
    printf("Serviços em ordem crescente de valor:\n");
    // Adicione aqui a lógica para listar todos os serviços em ordem crescente de valor
    // Exemplo:
    // Ordenar os serviços com base no valor
    // Imprimir os serviços em ordem crescente de valor
}

void listarClientesCrescenteNome() {
    printf("Clientes em ordem crescente de nome:\n");
    // Adicione aqui a lógica para listar todos os clientes em ordem crescente de nome
    // Exemplo:
    // Ordenar os clientes com base no nome
    // Imprimir os clientes em ordem alfabética de nome
}

int main() {
    int opcao;
    
    do {
    	
        printf("\nSelecione uma opção:\n");
        printf("1. Adicionar novo cliente\n");
        printf("2. Listar todas os clientes\n");
        printf("3. Listar todos os prestadores de serviços\n");
        printf("4. Listar os clientes de um determinado estado\n");
        printf("5. Listar os prestadores serviço de um determinado tipo\n");
        printf("6. Apresentar o(s) estado(s) onde está registrado o serviço mais caro\n");
        printf("7. Listar todos os serviços em ordem crescente de valor\n");
        printf("8. Listar todos os clientes em ordem crescente de nome\n");
        printf("9. Listar todos os tipos de serviços\n");
        printf("10. Adicionar novo prestador de serviço\n");
        printf("11. Sair\n");
        scanf("%d", &opcao);
        
system("cls");

        switch(opcao) {
            case 1:
                adicionarCliente();
                break;
            case 2:
                listarClientes();
                break;
            case 3:
                listarPrestadores();
                break;
            case 4:
                   {
                   	char estado[3];
                    printf("Digite o estado: ");
                    scanf("%s", estado);
                    listarClientesEstado(estado);
					} 
                break;
            case 5:
                   {
                   	char tipo[50];
                    printf("Digite o tipo de serviço: ");
                    scanf("%s", tipo);
                    listarPrestadoresServico(tipo);
					} 
                break;
            case 6:
                estadoServicoMaisCaro();
                break;
            case 7:
                listarServicosCrescente();
                break;
            case 8:
                listarClientesCrescenteNome();
                break;
            case 9:
                listarTiposServicos();
                break;
            case 10:
                adicionarPrestador();
                break;
            case 11:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
        
        
        
    } while (opcao != 11);

    return 0;
}
