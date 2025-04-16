#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void autokeyCipher() {
    char mode;
    char text[1000];
    char key[100];
    char result[1000];
    
    printf("Do you want to (e)ncrypt or (d)ecrypt? ");
    scanf("%c", &mode);
    getchar(); // Clear newline
    
    printf("Enter the text: ");
    fgets(text, 1000, stdin);
    text[strcspn(text, "\n")] = '\0';
    
    printf("Enter the initial key: ");
    fgets(key, 100, stdin);
    key[strcspn(key, "\n")] = '\0';
    
    // Convert to uppercase
    for (int i = 0; i < strlen(text); i++)
        text[i] = toupper(text[i]);
    for (int i = 0; i < strlen(key); i++)
        key[i] = toupper(key[i]);
    
    int keyLen = strlen(key);
    int textLen = strlen(text);
    
    if (mode == 'e') {
        // Encryption
        for (int i = 0; i < textLen; i++) {
            if (isalpha(text[i])) {
                char keyChar;
                if (i < keyLen) {
                    keyChar = key[i];
                } else {
                    keyChar = text[i - keyLen];
                }
                
                result[i] = ((text[i] - 'A' + keyChar - 'A') % 26) + 'A';
            } else {
                result[i] = text[i];
            }
        }
    } else {
        // Decryption
        for (int i = 0; i < textLen; i++) {
            if (isalpha(text[i])) {
                char keyChar;
                if (i < keyLen) {
                    keyChar = key[i];
                } else {
                    keyChar = result[i - keyLen];
                }
                
                result[i] = ((text[i] - keyChar + 26) % 26) + 'A';
            } else {
                result[i] = text[i];
            }
        }
    }
    
    result[textLen] = '\0';
    printf("Result: %s\n", result);
}
