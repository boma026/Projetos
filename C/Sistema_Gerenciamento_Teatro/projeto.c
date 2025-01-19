#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int reservado;
    int fileira;
    int numero;
    char NomeCompleto[100];
}assento;

typedef struct {
    assento** assentos;
    int numero_linhas;
    int numero_colunas;
}teatro;

assento** inicializarMatriz(int numLinhas, int numColunas){
    if (numLinhas > 26 || numColunas > 99){
        printf("Matriz fora dos limites, coloque o número de linhas até 26 e o de colunas até 99.");
        return NULL;
    }

    assento **matriz = (assento**)malloc(numLinhas * sizeof(assento*));

    for (int i = 0; i < numLinhas; i++){
        matriz[i] = (assento*)malloc(numColunas * sizeof(assento)); 

        for (int j = 0; j < numColunas; j++){
            matriz[i][j].reservado = 0;
            matriz[i][j].fileira = i;
            matriz[i][j].numero = j;
            strcpy(matriz[i][j].NomeCompleto, "");
        }
    }
    return matriz;
}

teatro criarTeatro(int numLinhas, int numColunas){
    teatro novoTeatro;

    novoTeatro.assentos = inicializarMatriz(numLinhas, numColunas);
    
    if (novoTeatro.assentos == NULL) {
        
        novoTeatro.numero_linhas = 0;
        novoTeatro.numero_colunas = 0;
    } else {
        novoTeatro.numero_linhas = numLinhas;
        novoTeatro.numero_colunas = numColunas;
    }

    return novoTeatro;
}

void exibirTeatro(teatro Teatro) {
    printf("  "); 
    for (int coluna = 1; coluna <= Teatro.numero_colunas; coluna++) {
        printf("%2d ", coluna);
    }
    printf("\n");

    for (int i = 0; i < Teatro.numero_linhas; i++) {
        printf("%c ", 'A' + i);

        for (int j = 0; j < Teatro.numero_colunas; j++) {
            if (Teatro.assentos[i][j].reservado) {
                printf("[X] ");
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

void liberarMartiz(assento **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int reservarAssento(teatro t, int linha, int coluna, char *nome) {
    linha--; 
    coluna--;

    if (linha >= 0 && linha < t.numero_linhas && coluna >= 0 && coluna < t.numero_colunas) {

        if (!t.assentos[linha][coluna].reservado) {
            t.assentos[linha][coluna].reservado = 1;
            strcpy(t.assentos[linha][coluna].NomeCompleto, nome);
            printf("Assento na linha %d, coluna %d reservado com sucesso.\n", linha + 1, coluna + 1);
            return 1;
        } else {
            printf("Erro: Assento na linha %d, coluna %d já está reservado.\n", linha + 1, coluna + 1);
            return 0;
        }
    } else {
        printf("Erro: Assento fora dos limites da matriz.\n");
        return 0;
    }
}


int reservarAssentosConsecutivos(teatro t, int linha, int coluna, int n, char *nome) {
    linha--; 
    coluna--;

    if (linha >= 0 && linha < t.numero_linhas && coluna >= 0 && coluna < t.numero_colunas) {

        for (int i = coluna; i < coluna + n; i++) {
            if (i >= t.numero_colunas || t.assentos[linha][i].reservado) {
                printf("Erro: Assento na linha %d, coluna %d ou subsequente já está reservado.\n", linha + 1, i + 1);
                return 0;
            }
        }

        for (int i = coluna; i < coluna + n; i++) {
            t.assentos[linha][i].reservado = 1;
            strcpy(t.assentos[linha][i].NomeCompleto, nome);
        }

        printf("Assentos na linha %d, coluna %d a coluna %d reservados com sucesso.\n", linha + 1, coluna + 1, coluna + n);
        return 1;
    } else {
        printf("Erro: Assento fora dos limites da matriz.\n");
        return 0;
    }
}
assento *reservarAssentoPeloSistema(teatro t, char *nome) {
    for (int i = 0; i < t.numero_linhas; i++) {
        for (int j = 0; j < t.numero_colunas; j++) {

            if (!t.assentos[i][j].reservado) {
                t.assentos[i][j].reservado = 1;
                strcpy(t.assentos[i][j].NomeCompleto, nome);
                return &(t.assentos[i][j]);
            }
        }
    }
    
    return NULL;
}

assento **reservarAssentosConsecutivosPeloSistema(teatro t, int n, char *nome) {
    for (int i = 0; i < t.numero_linhas; i++) {
        for (int j = 0; j <= t.numero_colunas - n; j++) {
            int assentosLivres = 1;
            for (int k = 0; k < n; k++) {
                if (t.assentos[i][j + k].reservado) {
                    assentosLivres = 0;
                    break;
                }
            }

            if (assentosLivres) {

                assento **assentosReservados = (assento **)malloc(n * sizeof(assento *));
                for (int k = 0; k < n; k++) {
                    t.assentos[i][j + k].reservado = 1;
                    strcpy(t.assentos[i][j + k].NomeCompleto, nome);
                    assentosReservados[k] = &(t.assentos[i][j + k]);
                }
                return assentosReservados;
            }
        }
    }
    return NULL;
}

int cancelarReserva(teatro t, int linha, int coluna) {
    linha--; 
    coluna--;

    if (linha >= 0 && linha < t.numero_linhas && coluna >= 0 && coluna < t.numero_colunas) {
        if (t.assentos[linha][coluna].reservado) {
            t.assentos[linha][coluna].reservado = 0;
            strcpy(t.assentos[linha][coluna].NomeCompleto, "");
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
int cancelarReservas(teatro t, char *nome) {
    int reservasCanceladas = 0;

    for (int i = 0; i < t.numero_linhas; i++) {
        for (int j = 0; j < t.numero_colunas; j++) {
            if (strcmp(t.assentos[i][j].NomeCompleto, nome) == 0 && t.assentos[i][j].reservado) {

                t.assentos[i][j].reservado = 0;
                strcpy(t.assentos[i][j].NomeCompleto, "");
                reservasCanceladas++;

            }
        }
    }

    return reservasCanceladas;
}

int cancelarTodasAsReservas(teatro t) {
    int reservasCanceladas = 0;

    for (int i = 0; i < t.numero_linhas; i++) {
        for (int j = 0; j < t.numero_colunas; j++) {
            if (t.assentos[i][j].reservado) {
   
                t.assentos[i][j].reservado = 0;
                strcpy(t.assentos[i][j].NomeCompleto, "");
                reservasCanceladas++;
            }
        }
    }

    return reservasCanceladas;
}

int verificarDisponibilidade(teatro t, int linha, int coluna) {
    linha--; 
    coluna--;

    if (linha >= 0 && linha < t.numero_linhas && coluna >= 0 && coluna < t.numero_colunas) {
        return !t.assentos[linha][coluna].reservado;
    } else {
        return 0;
    }
}

void consultarAssentosConsecutivos(teatro t, int n) {
    for (int i = 0; i < t.numero_linhas; i++) {
        int inicioIntervalo = -1;
        int assentosDisponiveis = 0;

        for (int j = 0; j < t.numero_colunas; j++) {
            if (!t.assentos[i][j].reservado) {
                if (inicioIntervalo == -1) {
                    inicioIntervalo = j;
                }
                assentosDisponiveis++;
            } else {
                if (assentosDisponiveis >= n) {
                    printf("Intervalo na linha %c de coluna %d a coluna %d\n", 'A' + i, inicioIntervalo + 1, j);
                }

                inicioIntervalo = -1;
                assentosDisponiveis = 0;
            }
        }

        if (assentosDisponiveis >= n) {
            printf("Intervalo na linha %c de coluna %d a coluna %d\n", 'A' + i, inicioIntervalo + 1, t.numero_colunas);
        }
    }
}

void exibirInformacoes(teatro t) {
    int reservasTotais = 0;
    int espacosLivres = 0;
    int maiorSequenciaLivre = 0;
    int sequenciaAtual = 0;

    for (int i = 0; i < t.numero_linhas; i++) {
        for (int j = 0; j < t.numero_colunas; j++) {
            if (t.assentos[i][j].reservado) {
                reservasTotais++;
                sequenciaAtual = 0;
            } else {
                espacosLivres++;
                sequenciaAtual++;
                if (sequenciaAtual > maiorSequenciaLivre) {
                    maiorSequenciaLivre = sequenciaAtual;
                }
            }
        }
    }

    printf("Numero total de reservas: %d\n", reservasTotais);
    printf("Numero total de espaços livres: %d\n", espacosLivres);
    printf("Maior sequencia livre de assentos: %d\n", maiorSequenciaLivre);
    printf("Matriz de assentos:\n");
    for (int i = 0; i < t.numero_linhas; i++) {
        for (int j = 0; j < t.numero_colunas; j++) {
            if (t.assentos[i][j].reservado) {
                printf("[X] "); 
            } else {
                printf("[ ] ");  // Assento livre
            }
        }
        printf("\n");
    }
}

int salvarEstado(teatro t, char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 0;
    }

    fprintf(arquivo, "%d %d\n", t.numero_linhas, t.numero_colunas);

    for (int i = 0; i < t.numero_linhas; i++) {
        for (int j = 0; j < t.numero_colunas; j++) {
            fprintf(arquivo, "%d %s ", t.assentos[i][j].reservado, t.assentos[i][j].NomeCompleto);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    return 1;
}

teatro carregarEstado(char *nomeArquivo) {
    teatro t;

    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        t.numero_linhas = 0;
        t.numero_colunas = 0;
        t.assentos = NULL;
        return t;
    }

    fscanf(arquivo, "%d %d", &t.numero_linhas, &t.numero_colunas);

    t.assentos = (assento **)malloc(t.numero_linhas * sizeof(assento *));
    for (int i = 0; i < t.numero_linhas; i++) {
        t.assentos[i] = (assento *)malloc(t.numero_colunas * sizeof(assento));
        for (int j = 0; j < t.numero_colunas; j++) {
            fscanf(arquivo, "%d %s", &t.assentos[i][j].reservado, t.assentos[i][j].NomeCompleto);
        }
    }

    fclose(arquivo);
    return t;
}
void mostraLista(){
    printf("0. Sair do programa\n");
    printf("1. Salvar estado\n");
    printf("2. Carregar estado\n");
    printf("3. Visualizar\n");
    printf("4. Reservar assento especifico\n");
    printf("5. Reservar assentos consecutivos especificos\n");
    printf("6. Reservar assento pelo sistema\n");
    printf("7. Reservar assentos consecutivos pelo sistema\n");
    printf("8. Cancelar reserva de um assento\n");
    printf("9. Cancelar reservas de uma pessoa\n");
    printf("10. Cancelar todas as reservas\n");
    printf("11. Verificar disponibilidade\n");
    printf("12. Consultar assentos consecutivos\n");
    printf("13. Exibir informacoes\n");
}

int main(){
    int numLinhas,numColunas, operacao;
    printf("Digite as linhas e colunas da matriz do teatro: \n");
    scanf("%d %d", &numLinhas, &numColunas);
    teatro meuTeatro = criarTeatro(numLinhas, numColunas);
    printf("\nEscolha uma das opcoes a seguir:\n");
    while(1){
        mostraLista();
        printf("Digite o numero da operacao: ");
        scanf("%d", &operacao);
        switch (operacao){
            case 0:
                printf("saindo do programa.\n");
                return 0;
            case 1:{
                char nomeArquivo[100];
                printf("Digite o nome do arquivo: ");
                scanf("%s", nomeArquivo);
                salvarEstado(meuTeatro, nomeArquivo);
                break;
            }
            case 2: {
                char nomeArquivo[100];
                printf("Digite o nome do arquivo: ");
                scanf("%s", nomeArquivo);
                meuTeatro = carregarEstado(nomeArquivo);
                break;
            }
            
            case 3:{
                exibirTeatro(meuTeatro);
                break;
            }
            case 4:{
                 int linha, coluna;
                char nome[100];
                printf("Digite linha, coluna e nome: ");
                scanf("%d %d %s", &linha, &coluna, nome);
                reservarAssento(meuTeatro, linha, coluna, nome);
                break;
            }
             case 5: {
                int linha, coluna, numAssentos;
                char nome[100];
                printf("Digite linha, coluna, numero de assentos e nome: ");
                scanf("%d %d %d %s", &linha, &coluna, &numAssentos, nome);
                reservarAssentosConsecutivos(meuTeatro, linha, coluna, numAssentos, nome);
                break;
            }
            case 6: {
                char nome[100];
                printf("Digite o nome: ");
                scanf("%s", nome);
                reservarAssentoPeloSistema(meuTeatro, nome);
                break;
            }
            case 7: {
                int numAssentos;
                char nome[100];
                printf("Digite o numero de assentos e nome: ");
                scanf("%d %s", &numAssentos, nome);
                reservarAssentosConsecutivosPeloSistema(meuTeatro, numAssentos, nome);
                break;
            }
            case 8: {
                int linha, coluna;
                printf("Digite linha e coluna: ");
                scanf("%d %d", &linha, &coluna);
                cancelarReserva(meuTeatro, linha, coluna);
                break;
            }
             case 9: {
                char nome[100];
                printf("Digite o nome: ");
                scanf("%s", nome);
                int reservasCanceladas = cancelarReservas(meuTeatro, nome);
                printf("%d reserva(s) cancelada(s) para %s.\n", reservasCanceladas, nome);
                break;
            }
            
            case 10:{
                cancelarTodasAsReservas(meuTeatro);
                break;
            }
             case 11: {
                int linha, coluna;
                printf("Digite linha e coluna: ");
                scanf("%d %d", &linha, &coluna);
                int disponivel = verificarDisponibilidade(meuTeatro, linha, coluna);
                if (disponivel) {
                    printf("Assento disponível.\n");
                } else {
                    printf("Assento reservado.\n");
                }
                break;
            }
             case 12: {
                int numAssentos;
                printf("Digite o numero mínimo de assentos: ");
                scanf("%d", &numAssentos);
                consultarAssentosConsecutivos(meuTeatro, numAssentos);
                break;
            }
            case 13:{
                exibirInformacoes(meuTeatro);
                break;
            }
            default:
                printf("Operacao invalida. Tente novamente.\n");
        }
    }
    return 0;
}




