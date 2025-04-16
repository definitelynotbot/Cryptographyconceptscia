#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_SIZE 1000
#define MAX_KEY_SIZE 100

void vigenereCipher() {
    char mode;
    char text[MAX_TEXT_SIZE];
    char key[MAX_KEY_SIZE];
    
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
    printf("Enter the key: ");
    fgets(key, MAX_KEY_SIZE, stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove trailing newline
    
    // Convert key to uppercase
    for (int i = 0; i < strlen(key); i++) {
        if (isalpha(key[i])) {
            key[i] = toupper(key[i]);
        }
    }
    
    int keyLen = strlen(key);
    int j = 0;
    
    // Process the text
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            int x = toupper(text[i]) - 'A';
            int k = key[j % keyLen] - 'A';
            
            if (mode == 'e') {
                // Encrypt: (plaintext + key) mod 26
                text[i] = ((x + k) % 26) + base;
            } else {
                // Decrypt: (ciphertext - key + 26) mod 26
                text[i] = ((x - k + 26) % 26) + base;
            }
            j++;
        }
    }
    
    printf("Result: %s\n", text);
}

int main() {
    vigenereCipher();
    return 0;
}
