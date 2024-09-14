#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h> // Necessário para usar pow()

// valor escrito 5465636E6F336C6F67696120646120496E666F726D6187C66F2E003333333333333333333333333333333333333333333333
// valor de b que foi dado 3

// Constantes para o cálculo da função
#define A0 186.752
#define A1 -148.235
#define A2 34.5049
#define A3 -3.5091
#define A4 0.183166
#define A5 -0.00513554
#define A6 0.0000735464
#define A7 -4.22038e-7

// Função que calcula o valor da posição do caractere com base na fórmula f(x, b)
double calcular_valor_caractere(int posicao, double b) {
    double valor_da_posicao ;
    for(i = 1; i = 50; i++){
        valor_da_posicao[i] = round(A0 + (A1 + b) * posicao[i]
                            + A2 * pow(posicao[i], 2)
                            + A3 * pow(posicao[i], 3)
                            + A4 * pow(posicao[i], 4)
                            + A5 * pow(posicao[i], 5)
                            + A6 * pow(posicao[i], 6)
                            + A7 * pow(posicao[i], 7));

    printf("Valor da posição %i = %f\n", posicao[i], valor_da_posicao[i]);
    
    return valor_da_posicao; // Retorna o valor para validação
    }
}

// Função para separar pares de caracteres e aplicar a validação com base na posição
void SepararPares(const char *str, double b) {
    char pares_mensagem[51];
    int tamanho_da_mensagem = strlen(str);
    int quantidade_pares = 0;

    for (int i = 0; i < tamanho_da_mensagem - 1; i += 2) {
        int posicao = i / 2 + 1; // Definindo a posição correta
        double valor_encontrado_na_posicao = calcular_valor_caractere(posicao, b);

        // Se o valor da posição for 0, ignora o caractere
        if (valor_encontrado_na_posicao == 0) {
            continue; // Pula o processamento desse caractere
        }

        // Processa o par de caracteres
        pares_mensagem[quantidade_pares * 2] = str[i];
        pares_mensagem[quantidade_pares * 2 + 1] = str[i + 1];
        quantidade_pares++;
    }
    pares_mensagem[quantidade_pares * 2] = '\0'; // Adiciona o terminador nulo

    // Exibe a mensagem filtrada
    printf("Mensagem convertida: %s\n", pares_mensagem);
}

// Função que converte string hexadecimal para ASCII
void ConverterHexParaASCII(const char *mensagem, char *ascii_str) {
    size_t tamanho_mensagem = strlen(mensagem);
    size_t i;

    for (i = 0; i < tamanho_mensagem; i += 2) {
        char mensagem_em_pares[3] = {mensagem[i], mensagem[i + 1], '\0'};
        long int value = strtol(mensagem_em_pares, NULL, 16);
        ascii_str[i / 2] = (char)value;
    }
    ascii_str[i / 2] = '\0'; // Adiciona o terminador nulo
}

int main() {
    // Configura o ambiente para suportar caracteres em português
    setlocale(LC_ALL, "pt_BR.UTF-8");

    char mensagem[101];
    char ascii_mensagem[51];
    double valor_b;

    // Mensagem criptografada que o usuário vai escrever
    printf("Escreva a mensagem criptografada de até 100 dígitos: ");
    fgets(mensagem, sizeof(mensagem), stdin);

    // Remove o caractere de nova linha, se presente
    mensagem[strcspn(mensagem, "\n")] = '\0';

    // Solicita o valor de b
    printf("Informe o valor de b: ");
    scanf("%lf", &valor_b);

    // Converte a mensagem hexadecimal para ASCII
    ConverterHexParaASCII(mensagem, ascii_mensagem);

    // Separa a mensagem convertida em pares e aplica a função de validação
    SepararPares(ascii_mensagem, valor_b);

    return 0;
}
