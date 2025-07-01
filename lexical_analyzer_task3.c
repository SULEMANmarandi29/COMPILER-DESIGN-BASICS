#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *keywords[] = {"int", "float", "if", "else", "while", "for", "return", "void"};
char operators[] = "+-*/=<>";

int isKeyword(char *str) {
    for (int i = 0; i < 8; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

void analyze(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    char ch, buffer[100];
    int i = 0;

    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch) || ch == '_') {
            buffer[i++] = ch;
        } else if (isdigit(ch)) {
            buffer[i++] = ch;
        } else {
            buffer[i] = '\0';
            if (i > 0) {
                if (isKeyword(buffer))
                    printf("%s: Keyword\n", buffer);
                else
                    printf("%s: Identifier\n", buffer);
            }
            i = 0;
            if (isOperator(ch)) {
                printf("%c: Operator\n", ch);
            }
        }
    }
    // Check for last token if file doesn't end with delimiter
    buffer[i] = '\0';
    if (i > 0) {
        if (isKeyword(buffer))
            printf("%s: Keyword\n", buffer);
        else
            printf("%s: Identifier\n", buffer);
    }
    fclose(fp);
}

int main() {
    char filename[100];
    printf("Enter the input file name: ");
    scanf("%99s", filename);
    analyze(filename);
    return 0;
}
