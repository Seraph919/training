#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int word(char a) {
    return (a != ' ' && a != '\t');
}

// Swap function to swap words in the array
void swapp(char **s, int size) {
    for (int i = 0; i < size / 2; i++) {
        char *temp = s[i];
        s[i] = s[size - 1 - i]; // Corrected the index
        s[size - 1 - i] = temp; // Corrected the index
    }
}

// Function to swap words in a string
void wordsSwap(char *s) {
    int n = 0; // Count of words
    char **words = (char**) malloc(sizeof(char *) * 100); // Assuming max 100 words
    char *wordBuffer = malloc(sizeof(char) * 100); // Buffer for a single word

    // Extract words from the string s
    int k;
    for (int i = 0, k = 0; s[i]; i++) {
        if (word(s[i])) {
            wordBuffer[k++] = s[i]; // Copy character to word
        } else {
            if (k > 0) {
                wordBuffer[k] = '\0'; // Null-terminate the word
                words[n] = malloc(strlen(wordBuffer) + 1); // Allocate memory for the word
                strcpy(words[n++], wordBuffer); // Copy to words array
                k = 0; // Reset buffer index
            }
        }
    }

    // Handle last word if exists
    if (k > 0) {
        wordBuffer[k] = '\0';
        words[n] = malloc(strlen(wordBuffer) + 1);
        strcpy(words[n++], wordBuffer);
    }

    swapp(words, n);

    // Construct the final string back
    int index = 0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (words[i][j]) {
            s[index++] = words[i][j++];
        }
        if (i < n - 1) {
            s[index++] = ' '; // Add space between words
        }
    }
    s[index] = '\0'; // Null-terminate the final string

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(words[i]); // Free each word
    }
    free(words); // Free words array
    free(wordBuffer); // Free the word buffer
}

// Example usage
int main() {
    char str[] = "Hello world this is a test";
    wordsSwap(str);
    printf("%s\n", str);
    return 0;
}