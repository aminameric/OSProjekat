#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    char file1_name[10];
    char file2_name[10];
    char file3_name[10];
    char buffer1[2048];
    char buffer2[2048];

    ssize_t bytes_read1;
    ssize_t bytes_read2;

    printf("Enter file 1: ");
    scanf("%s", file1_name);
    printf("Enter file 2: ");
    scanf("%s", file2_name);
    printf("Enter file 3 (destination): ");
    scanf("%s", file3_name);

    int file1 = open(file1_name, O_RDWR);
    int file2 = open(file2_name, O_RDWR);
    int file3 = open(file3_name, O_RDWR | O_APPEND);


    bytes_read1 = read(file1, buffer1, sizeof(buffer1));
    bytes_read2 = read(file2, buffer2, sizeof(buffer2));

    buffer1[bytes_read1] = '\0';
    buffer2[bytes_read2] = '\0';

    write(file3, buffer1, strlen(buffer1));
    write(file3, " \n", strlen(" \n"));
    write(file3, buffer2, strlen(buffer2));
    write(file3, " \n", strlen(" \n"));

    close(file1);
    close(file2);
    close(file3);

    return 0;
}


