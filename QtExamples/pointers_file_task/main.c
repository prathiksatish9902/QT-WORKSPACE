#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 20

int readDataFromFile(const char *filename, char (*lines)[LINE_LENGTH + 1], int capacity) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return -1;
    }

    int count = 0;
    char buffer[LINE_LENGTH + 2];

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (count >= capacity) {
            break;
        }

        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        strncpy(lines[count], buffer, LINE_LENGTH);
        lines[count][LINE_LENGTH] = '\0';
        count++;
    }

    fclose(fp);
    return count;
}

void displayData(char (*lines)[LINE_LENGTH + 1], int count) {
    printf("Data read from file:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", lines[i]);
    }
}

int main() {
    int capacity = 10;
    char (*lines)[LINE_LENGTH + 1] = malloc(capacity * sizeof(*lines));

    if (!lines) {
        perror("malloc failed");
        return 1;
    }

    int count = 0;
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        perror("Failed to open file");
        free(lines);
        return 1;
    }

    char buffer[LINE_LENGTH + 2];
    while (fgets(buffer, sizeof(buffer), fp)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        if (count >= capacity) {
            capacity *= 2;
            char (*temp)[LINE_LENGTH + 1] = realloc(lines, capacity * sizeof(*lines));
            if (!temp) {
                perror("realloc failed");
                free(lines);
                fclose(fp);
                return 1;
            }
            lines = temp;
        }

        strncpy(lines[count], buffer, LINE_LENGTH);
        lines[count][LINE_LENGTH] = '\0';
        count++;
    }
    fclose(fp);

    displayData(lines, count);
    free(lines);
    return 0;
}
