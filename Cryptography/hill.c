#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_SIZE 1000
#define MAX_KEY_SIZE 100

void getKeyMatrix(char *key, int keyMatrix[][3]) {
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            keyMatrix[i][j] = (key[k] - 'A') % 26;
            k++;
        }
    }
}

void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1]) {
    for (int i = 0; i < 3; i++) {
        cipherMatrix[i][0] = 0;
        for (int j = 0; j < 3; j++) {
            cipherMatrix[i][0] += keyMatrix[i][j] * messageVector[j][0];
        }
        cipherMatrix[i][0] = cipherMatrix[i][0] % 26;
    }
}

void hillCipher() {
    char mode;
    char text[MAX_TEXT_SIZE];
    char key[MAX_KEY_SIZE];
    
    printf("Do you want to (e)ncrypt or (d)ecrypt? ");
    scanf("%c", &mode);
    getchar(); // Clear newline
    
    printf("Enter the text: ");
    fgets(text, MAX_TEXT_SIZE, stdin);
    text[strcspn(text, "\n")] = '\0';
    
    printf("Enter the key: ");
    fgets(key, MAX_KEY_SIZE, stdin);
    key[strcspn(key, "\n")] = '\0';
    
    int keyMatrix[3][3];
    getKeyMatrix(key, keyMatrix);
    
    int messageVector[3][1];
    for (int i = 0; i < 3; i++) {
        messageVector[i][0] = (text[i] - 'A') % 26;
    }
    
    int cipherMatrix[3][1];
    encrypt(cipherMatrix, keyMatrix, messageVector);
    
    char result[4];
    for (int i = 0; i < 3; i++) {
        result[i] = cipherMatrix[i][0] + 'A';
    }
    result[3] = '\0';
    
    printf("Result: %s\n", result);
}
