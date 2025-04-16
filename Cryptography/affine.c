#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_SIZE 1000

// Function to find greatest common divisor
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find modular multiplicative inverse
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; // No mod inverse exists
}

void affineCipher() {
    char mode;
    char text[MAX_TEXT_SIZE];
    int a, b;
    
    // Get mode (encrypt or decrypt)
    printf("Do you want to (e)ncrypt or (d)ecrypt? ");
    scanf("%c", &mode);
    getchar(); // Clear the newline character
    mode = tolower(mode);
    
    // Get text
    printf("Enter the text: ");
    fgets(text, MAX_TEXT_SIZE, stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove trailing newline
    
    // Get keys
    do {
        printf("Enter the 'a' key (must be coprime with 26): ");
        scanf("%d", &a);
        getchar(); // Clear the newline character
    } while (gcd(a, 26) != 1);
    
    printf("Enter the 'b' key (0-25): ");
    scanf("%d", &b);
    b = b % 26;
    
    int a_inv = modInverse(a, 26);
    
    // Process the text
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            int x = text[i] - base;
            
            if (mode == 'e') {
                // Encrypt: E(x) = (ax + b) mod 26
                text[i] = ((a * x + b) % 26) + base;
            } else {
                // Decrypt: D(y) = a^-1 * (y - b) mod 26
                text[i] = ((a_inv * ((x - b + 26) % 26)) % 26) + base;
            }
        }
    }
    
    printf("Result: %s\n", text);
}

int main() {
    affineCipher();
    return 0;
}
