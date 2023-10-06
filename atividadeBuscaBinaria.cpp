#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se uma string começa com outra
int startsWith(const char *str, const char *prefix) {
    while (*prefix) {
        if (tolower(*str) != tolower(*prefix)) {
            return 0;
        }
        str++;
        prefix++;
    }
    return 1;
}

int main() {
    FILE *file = fopen("nomes.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char search[50];
    printf("Digite o início do nome a ser buscado: ");
    scanf("%s", search);

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        // Remover o caractere de nova linha, se existir
        char *newline = strchr(line, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }

        if (startsWith(line, search)) {
            printf("%s\n", line);
        }
    }

    fclose(file);
    return 0;
}
