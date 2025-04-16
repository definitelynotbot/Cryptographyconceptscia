#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_SIZE 1000
#define MAX_KEY_SIZE 100

void gronsfeldCipher() {
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
    
    // Get key (numeric)
    printf("Enter the numeric key (digits only): ");
    fgets(key, MAX_KEY_SIZE, stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove trailing newline
    
    // Validate key (should be only digits)
    for (int i = 0; i < strlen(key); i++) {
        if (!isdigit(key[i])) {
            printf("Error: Key should contain only digits.\n");
            return;
        }
    }
    
    int keyLen = strlen(key);
    int j = 0;
    
    // Process the text
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            int x = text[i] - base;
            int k = key[j % keyLen] - '0'; // Convert char digit to int
            
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
    gronsfeldCipher();
    return 0;
}
