#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void routeCipher() {
    char mode;
    char text[1000];
    int rows, cols;
    
    printf("Do you want to (e)ncrypt or (d)ecrypt? ");
    scanf("%c", &mode);
    getchar(); // Clear newline
    
    printf("Enter the text: ");
    fgets(text, 1000, stdin);
    text[strcspn(text, "\n")] = '\0';
    
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    
    int len = strlen(text);
    char** table = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        table[i] = (char*)malloc(cols * sizeof(char));
    }
    
    // Fill the table with the text
    int k = 0;
    for (int i = 0; i < rows && k < len; i++) {
        for (int j = 0; j < cols && k < len; j++) {
            table[i][j] = text[k++];
        }
    }
    
    // Pad the remaining cells
    while (k < rows * cols) {
        table[k / cols][k % cols] = 'X';
        k++;
    }
    
    // Read the table according to the mode
    char result[1000];
    k = 0;
    
    if (mode == 'e') {
        // Read column by column
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                result[k++] = table[i][j];
            }
        }
    } else {
        // Read row by row
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[k++] = table[i][j];
            }
        }
    }
    
    result[k] = '\0';
    printf("Result: %s\n", result);
    
    // Free allocated memory
    for (int i = 0; i < rows; i++)
        free(table[i]);
    free(table);
}
