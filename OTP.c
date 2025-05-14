#include <stdio.h>
#include <string.h>

int Key_adder(int key[], int valoresA[], int nbits)
{
    int resultado[800];

    for (int i = 0; i < nbits; i++) {
        int sum = key[i] + valoresA[i];
        resultado[i] = sum & 1;
        printf("%d", resultado[i]);
    }
    printf("\n");
    return 0;
}

int decimaltobinary(char string[], int valoresA[])
{
    int bitconut = 0;         
    int binario[] = {128,64,32,16,8,4,2,1};

    for (int i = 0; string[i] != '\0'; i++) {
        int number = (unsigned char)string[i];
        for (int j = 0; j < 8; j++) {
            if (number >= binario[j]) {
                number -= binario[j];
                valoresA[bitconut] = 1;
                printf("1");
            } else {
                valoresA[bitconut] = 0;
                printf("0");
            }
            bitconut++;
        }
        printf(" ");
    }
    printf("\n");
    return bitconut;
}

int main()
{   
    char key_str[800];
    int valoresA[800];
    int key[800];
    char mess[100];

    printf("Frase: ");
    scanf(" %99s", mess);

    printf("Key (bits): ");
    scanf(" %799s", key_str);

    int nbits   = decimaltobinary(mess, valoresA);
    int key_len = strlen(key_str);

    for (int i = 0; i < key_len && i < nbits; i++)
        key[i] = (key_str[i] == '1');

    // Se a chave for mais curta, preenche o resto com zeros
    for (int i = key_len; i < nbits; i++)
        key[i] = 0;

    Key_adder(key, valoresA, nbits);
    return 0;
}
