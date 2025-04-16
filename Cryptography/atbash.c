#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_SIZE 1000

void atbashCipher() {
    char mode;
    char text[MAX_TEXT_SIZE];
    
    // Get mode (encrypt or decrypt)
    printf("Do you want to (e)ncrypt or (d)ecrypt? ");
    scanf("%c", &mode);
    getchar(); // Clear the newline character
    
    // Get text
    printf("Enter the text: ");
    fgets(text, MAX_TEXT_SIZE, stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove trailing newline
    
    // Process the text (Atbash is its own inverse, so encryption and decryption are the same)
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (islower(text[i])) {
                text[i] = 'z' - (text[i] - 'a');
            } else {
                text[i] = 'Z' - (text[i] - 'A');
            }
        }
    }
    
    printf("Result: %s\n", text);
}

int main() {
    atbashCipher();
    return 0;
}
