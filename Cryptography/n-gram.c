#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_SIZE 1000

void ngramOperations() {
    char text[MAX_TEXT_SIZE];
    int n;
    
    // Get text
    printf("Enter the text: ");
    fgets(text, MAX_TEXT_SIZE, stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove trailing newline
    
    // Get n-gram size
    printf("Enter the n-gram size: ");
    scanf("%d", &n);
    
    if (n <= 0 || n > strlen(text)) {
        printf("Invalid n-gram size.\n");
        return;
    }
    
    // Convert text to uppercase and remove non-alphabetic characters
    int len = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            text[len++] = toupper(text[i]);
        }
    }
    text[len] = '\0';
    
    // Print all n-grams
    printf("N-grams:\n");
    for (int i = 0; i <= len - n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", text[i + j]);
        }
        printf("\n");
    }
    
    // Count frequency of each n-gram
    printf("\nN-gram frequencies:\n");
    for (int i = 0; i <= len - n; i++) {
        char ngram[MAX_TEXT_SIZE];
        strncpy(ngram, text + i, n);
        ngram[n] = '\0';
        
        int count = 0;
        for (int j = 0; j <= len - n; j++) {
            if (strncmp(text + j, ngram, n) == 0) {
                count++;
            }
        }
        
        // Check if this n-gram has already been printed
        int already_printed = 0;
        for (int j = 0; j < i; j++) {
            if (strncmp(text + j, ngram, n) == 0) {
                already_printed = 1;
                break;
            }
        }
        
        if (!already_printed) {
            printf("%s: %d\n", ngram, count);
        }
    }
}

int main() {
    ngramOperations();
    return 0;
}
