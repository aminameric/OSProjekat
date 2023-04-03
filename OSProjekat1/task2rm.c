#include <stdio.h>

int main() {
    char fileName[20];

    printf("Enter file name: ");
    scanf("%s", fileName);

    remove(fileName);

    return 0;
}