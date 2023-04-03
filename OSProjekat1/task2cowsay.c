#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cowsay(char *message){
    //printing the message
    printf ("_______________\n");
    printf("<%s>\n", message);
    printf("----------------\n");
    printf ("       \\      ^__^\n");
    printf("         \\     (oo)\\_______\n");
    printf("               (__)\\        )\\/\\\n");
    printf("                   ||-----w  |\n");
    printf("                   ||       ||\n");

}
int main() {
    char message[50];

    printf("Enter message: ");
    scanf("%s", message);

    cowsay(message);
    return 0;
}