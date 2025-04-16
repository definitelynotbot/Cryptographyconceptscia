#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_SIZE 1000

void caesarCipher() {
    char mode;
    char text[MAX_TEXT_SIZE];
    int key;
    
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
    printf("Enter the shift key (0-25): ");
    scanf("%d", &key);
    
    key = key % 26;
    if (mode == 'd')
        key = 26 - key;
    
    // Process the text
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] - base + key) % 26 + base;
        }
    }
    
    printf("Result: %s\n", text);
}

int main() {
    caesarCipher();
    return 0;
}
