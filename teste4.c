#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> // Inclui a biblioteca para usar a função pow e round

// Definição dos coeficientes da fórmula
#define A0 186.752
#define A1 -148.235
#define A2 34.5049
#define A3 -3.5091
#define A4 0.183166
#define A5 -0.00513554
#define A6 0.0000735464
#define A7 -4.22038e-7

// Função que separa pares de caracteres da string convertida e retorna a string em pares
void SepararPares(const char *str, char *pares_mensagem) {
    int len = strlen(str);
    int quantidade_pares = 0;

    for (int i = 0; i < len; i += 2) { // Percorre a string de 2 em 2
    
        
        pares_mensagem[quantidade_pares * 2] = str[i];
        pares_mensagem[quantidade_pares * 2 + 1] = str[i + 1];
        pares_mensagem[quantidade_pares * 2 + 2] = '\0'; // Adiciona o terminador nulo
        quantidade_pares++;
    }

   
}

// Função que converte string hexadecimal para ASCII
void ConverterHexParaASCII(const char *hex_str, char *ascii_str) {
    size_t len = strlen(hex_str);
    size_t i;

    for (i = 0; i < len; i += 2) {
        char hex_pair[3] = { hex_str[i], hex_str[i + 1], '\0' };
        long int value = strtol(hex_pair, NULL, 16);
        ascii_str[i / 2] = (char)value;
    }
    ascii_str[len / 2] = '\0'; // Adiciona o terminador nulo
}

// Função para realizar cálculos com base no valor de b
// Função para realizar cálculos com base no valor de b
void CalculoIndices(int b, const char *pares_mensagem,const char *str) {
    for (int posicao = 1; posicao <= 50; posicao++) { // Começa em 1 e vai até 50
        if (str[posicao - 1] == '0' && str[posicao] == '0') {
            printf("\nPar '00' encontrado. Parando a leitura.\n");
            break; // Interrompe a leitura quando encontrar "00"
        }
        // Calcula o valor da posição com base na fórmula
        double valor_da_posicao = round(A0 + (A1 + b) * posicao
                            + A2 * pow(posicao, 2)
                            + A3 * pow(posicao, 3)
                            + A4 * pow(posicao, 4)
                            + A5 * pow(posicao, 5)
                            + A6 * pow(posicao, 6)
                            + A7 * pow(posicao, 7));
        
        // Verifica se o caractere da posição é '0' e para a execução se for
        if (pares_mensagem[posicao - 1] == '0') { // Ajusta índice para o array (começa em 0)
            break;
        }
        else if (str[posicao - 1] == '0' && str[posicao] == '0') {
            printf("\nPar '00' encontrado. Parando a leitura.\n");
            break; // Interrompe a leitura quando encontrar "00"
        }
        // Se o valor da posição for 0, a posição será ignorada
        else if (valor_da_posicao == 0) {
            continue;
        }

        // Exibe o caractere da mensagem para a posição correspondente
        printf("%c", pares_mensagem[posicao - 1]);
        
    }
    
}

int main() {
    char mensagem[101];
    char ascii_mensagem[51];
    char pares_mensagem[51]; // Para armazenar os pares de caracteres
    int b;

    // Mensagem criptografada que o usuário vai escrever
    printf("Escreva a mensagem criptografada de até 100 dígitos: ");
    fgets(mensagem, sizeof(mensagem), stdin);

    // Remove o caractere de nova linha, se presente
    mensagem[strcspn(mensagem, "\n")] = '\0';

    // Converte a mensagem hexadecimal para ASCII
    ConverterHexParaASCII(mensagem, ascii_mensagem);

    // Separa a mensagem convertida em pares
    SepararPares(ascii_mensagem, pares_mensagem);

    // Exibe a mensagem convertida sem ignorar caracteres
    printf("Mensagem convertida sem ignorar caracteres: %s\n", ascii_mensagem);

    // Solicita o valor de b
    printf("Escreva o valor de b: ");
    scanf("%d", &b);
    
    printf("Mensagem final: ");
    // Função para realizar cálculos com b
    CalculoIndices(b, pares_mensagem,ascii_mensagem);

    return 0;
}