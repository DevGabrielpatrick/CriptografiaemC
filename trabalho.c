#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 // mensagem que o usuario vai escrever 5465636E6F336C6f67696120646120496E666f726D6187C66F2E003333333333333333333333333333333333333333333333
void SepararPares(const char *str) {
    char pares_mensagem[51]; 
    int len = strlen(str);
    int quantidade_pares = 0;
    for (int i = 0; i < len - 1; i += 2) {
        quantidade_pares++;
        pares_mensagem[i] = str[i];
        pares_mensagem[i + 1] = str[i + 1];
        pares_mensagem[i + 2] = '\0'; // Adiciona o terminador nulo
        printf("\nPar numero %i, mensagem: %c%c\n", quantidade_pares, pares_mensagem[i], pares_mensagem[i + 1]);
    }
}

void ConverterHexParaASCII(const char *hex_str, char *ascii_str) {
    size_t len = strlen(hex_str);
    size_t i;
    for (i = 0; i < len; i += 2) {
        char hex_pair[3] = { hex_str[i], hex_str[i + 1], '\0' };
        long int value = strtol(hex_pair, NULL, 16);
        ascii_str[i / 2] = (char)value;
    }
    ascii_str[i / 2] = '\0'; // Adiciona o terminador nulo
}

int main() {
    char mensagem[101];
    char ascii_mensagem[51];

    // Mensagem criptografada que o usuário vai escrever
    printf("Escreva a mensagem criptografada de até 100 dígitos: ");
    fgets(mensagem, sizeof(mensagem), stdin);

    // Remove o caractere de nova linha, se presente
    mensagem[strcspn(mensagem, "\n")] = '\0';

    // Converte a mensagem hexadecimal para ASCII
    ConverterHexParaASCII(mensagem, ascii_mensagem);

    

    // Separa a mensagem convertida em pares
    SepararPares(ascii_mensagem);
    
    // Exibe a mensagem convertida
    printf("Mensagem convertida: %s\n", ascii_mensagem);

    return 0;
}
