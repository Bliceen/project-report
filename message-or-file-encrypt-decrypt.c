#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *str) {
    for (int i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] + 3;
}

void decrypt(char *str) {
    for (int i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] - 3;
}

void process_message() {
    char str[100];
    int x;

    printf("\nPlease enter a string:\t");
    getchar(); // to consume any leftover newline character
    gets(str);

    printf("\nPlease choose the following options: \n");
    printf("1 = Encrypt the string.\n");
    printf("2 = Decrypt the string.\n");
    scanf("%d", &x);

    switch(x) {
        case 1:
            encrypt(str);
            printf("\nEncrypted string: %s\n", str);
            break;
        case 2:
            decrypt(str);
            printf("\nDecrypted string: %s\n", str);
            break;
        default:
            printf("\nError\n");
    }
}

void process_file() {
    char filename[100], str[100];
    int x;

    printf("\nPlease enter the filename:\t");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r+");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    fgets(str, 100, file);

    printf("\nPlease choose the following options: \n");
    printf("1 = Encrypt the file content.\n");
    printf("2 = Decrypt the file content.\n");
    scanf("%d", &x);

    switch(x) {
        case 1:
            encrypt(str);
            break;
        case 2:
            decrypt(str);
            break;
        default:
            printf("\nError\n");
            fclose(file);
            return;
    }

    fseek(file, 0, SEEK_SET);
    fprintf(file, "%s", str);
    fclose(file);

    printf("\nOperation completed. Check the file for the result.\n");
}

int main() {
    int choice;
    char repeat;

    do {
        printf("\nPlease choose the following options: \n");
        printf("1 = Process a message.\n");
        printf("2 = Process a file.\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                process_message();
                break;
            case 2:
                process_file();
                break;
            default:
                printf("\nError\n");
        }

        printf("\nDo you want to perform another operation? (y/n): ");
        scanf(" %c", &repeat);
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}

