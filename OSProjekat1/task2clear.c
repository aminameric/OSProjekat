#include <stdlib.h>
#include <stdio.h>
int main() {
    printf("before clear");
    printf("\033[2J\033[H");
    printf("\n");
    return 0;
}

