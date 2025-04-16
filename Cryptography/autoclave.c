#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_SIZE 1000
#define MAX_KEY_SIZE 100

void runningKeyCipher() {
    char mode;
    char text[MAX_TEXT_SIZE];
    char key[MAX_KEY_SIZE];
    char fullKey[MAX_TEXT_SIZE];
    
    // Get mode (encrypt or decrypt)
    printf("Do you want to (e)ncrypt or (d)ecrypt? ");
    scanf("%c", &mode);
    getchar(); // Clear the newline character
    mode = tolower(mode);
    
    // Get text
    printf("Enter the text: ");
    fgets(text, MAX_TEXT_SIZE, stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove trailing newline
    
    // Get key
    printf("Enter the initial key: ");
    fgets(key, MAX_KEY_SIZE, stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove trailing newline
    
    // Convert text and key to uppercase
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            text[i] = toupper(text[i]);
        }
    }
    
    for (int i = 0; i < strlen(key); i++) {
        if (isalpha(key[i])) {
            key[i] = toupper(key[i]);
        }
    }
    
    // Create the full key
    strcpy(fullKey, key);
    int keyLen = strlen(key);
    int textLen = strlen(text);
    char result[MAX_TEXT_SIZE];
    
    if (mode == 'e') {
        // For encryption, the key is extended with the plaintext
        int j = 0;
        for (int i = 0; i < textLen; i++) {
            if (isalpha(text[i])) {
                if (j < keyLen) {
                    // Use the initial key
                    int k = fullKey[j] - 'A';
                    int p = text[i] - 'A';
                    result[i] = ((p + k) % 26) + 'A';
                } else {
                    // Use the plaintext as key
                    int k = text[i - keyLen] - 'A';
                    int p = text[i] - 'A';
                    result[i] = ((p + k) % 26) + 'A';
                }
                j++;
            } else {
                result[i] = text[i];
            }
        }
    } else {
        // For decryption, we need to decrypt character by character
        int j = 0;
        for (int i = 0; i < textLen; i++) {
            if (isalpha(text[i])) {
                if (j < keyLen) {
                    // Use the initial key
                    int k = fullKey[j] - 'A';
                    int c = text[i] - 'A';
                    result[i] = ((c - k + 26) % 26) + 'A';
                } else {
                    // Use the decrypted text as key
                    int k = result[i - keyLen] - 'A';
                    int c = text[i] - 'A';
                    result[i] = ((c - k + 26) % 26) + 'A';
                }
                j++;
            } else {
                result[i] = text[i];
            }
        }
    }
    
    result[textLen] = '\0';
    printf("Result: %s\n", result);
}

int main() {
    runningKeyCipher();
    return 0;
}
