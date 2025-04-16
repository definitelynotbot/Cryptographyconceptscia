#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void myszkowskiCipher() {
    char mode;
    char text[1000];
    char key[100];
    
    printf("Do you want to (e)ncrypt or (d)ecrypt? ");
    scanf("%c", &mode);
    getchar(); // Clear newline
    
    printf("Enter the text: ");
    fgets(text, 1000, stdin);
    text[strcspn(text, "\n")] = '\0';
    
    printf("Enter the key: ");
    fgets(key, 100, stdin);
    key[strcspn(key, "\n")] = '\0';
    
    int keyLen = strlen(key);
    int textLen = strlen(text);
    
    // Calculate number of rows needed
    int rows = (textLen + keyLen - 1) / keyLen;
    
    // Create the grid
    char** grid = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (char*)malloc(keyLen * sizeof(char));
        for (int j = 0; j < keyLen; j++) {
            grid[i][j] = ' ';
        }
    }
    
    // Fill the grid with the text
    int k = 0;
    for (int i = 0; i < rows && k < textLen; i++) {
        for (int j = 0; j < keyLen && k < textLen; j++) {
            grid[i][j] = text[k++];
        }
    }
    
    // Create the key order
    int* keyOrder = (int*)malloc(keyLen * sizeof(int));
    char* sortedKey = (char*)malloc((keyLen + 1) * sizeof(char));
    strcpy(sortedKey, key);
    
    // Sort the key characters
    for (int i = 0; i < keyLen - 1; i++) {
        for (int j = i + 1; j < keyLen; j++) {
            if (sortedKey[i] > sortedKey[j]) {
                char temp = sortedKey[i];
                sortedKey[i] = sortedKey[j];
                sortedKey[j] = temp;
            }
        }
    }
    
    // Assign order numbers to key characters
    int order = 1;
    for (int i = 0; i < keyLen; i++) {
        char currentChar = sortedKey[i];
        if (i > 0 && currentChar == sortedKey[i-1]) continue;
        
        for (int j = 0; j < keyLen; j++) {
            if (key[j] == currentChar) {
                keyOrder[j] = order;
            }
        }
        order++;
    }
    
    // Read the grid according to the key order
    char result[1000];
    k = 0;
    
    if (mode == 'e') {
        // For each unique order number
        for (int o = 1; o < order; o++) {
            // Find all columns with this order
            for (int j = 0; j < keyLen; j++) {
                if (keyOrder[j] == o) {
                    // Read this column
                    for (int i = 0; i < rows; i++) {
                        if (grid[i][j] != ' ') {
                            result[k++] = grid[i][j];
                        }
                    }
                }
            }
        }
    } else {
        // Decryption code would go here
        printf("Decryption not implemented in this example\n");
    }
    
    result[k] = '\0';
    printf("Result: %s\n", result);
    
    // Free allocated memory
    for (int i = 0; i < rows; i++)
        free(grid[i]);
    free(grid);
    free(keyOrder);
    free(sortedKey);
}
