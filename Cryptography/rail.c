#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encryptRailFence(char* text, int key) {
    // Create the matrix
    char** rail = (char**)malloc(key * sizeof(char*));
    for (int i = 0; i < key; i++) {
        rail[i] = (char*)malloc(strlen(text) * sizeof(char));
        for (int j = 0; j < strlen(text); j++) {
            rail[i][j] = '\n';
        }
    }
    
    // Fill the rail matrix
    int row = 0, col = 0;
    int dir_down = 0;
    
    for (int i = 0; i < strlen(text); i++) {
        // Change direction at the top and bottom rails
        if (row == 0 || row == key - 1)
            dir_down = !dir_down;
        
        // Fill the current position
        rail[row][col++] = text[i];
        
        // Find the next row
        dir_down ? row++ : row--;
    }
    
    // Construct the ciphertext
    char* result = (char*)malloc((strlen(text) + 1) * sizeof(char));
    int index = 0;
    
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < strlen(text); j++) {
            if (rail[i][j] != '\n')
                result[index++] = rail[i][j];
        }
    }
    result[index] = '\0';
    
    // Free the allocated memory
    for (int i = 0; i < key; i++)
        free(rail[i]);
    free(rail);
    
    return result;
}

void railFenceCipher() {
    char mode;
    char text[1000];
    int key;
    
    printf("Do you want to (e)ncrypt or (d)ecrypt? ");
    scanf("%c", &mode);
    getchar(); // Clear newline
    
    printf("Enter the text: ");
    fgets(text, 1000, stdin);
    text[strcspn(text, "\n")] = '\0';
    
    printf("Enter the number of rails: ");
    scanf("%d", &key);
    
    if (mode == 'e') {
        char* result = encryptRailFence(text, key);
        printf("Encrypted text: %s\n", result);
        free(result);
    } else {
        // Decryption code would go here
        printf("Decryption not implemented in this example\n");
    }
}
