#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
     

int main() {
    pid_t pid;
    pid = fork(); // Create a child process

    if (pid == 0) // Child process
                        // exec() system call is used to replace the current process image with a new process image
                        // exec() system call is used in the child process to replace its memory image with a new 
                        //process image. The new program runs independently of the parent process, and any changes made 
                        //to the child process's memory space will not be reflected in the parent process's memory space.
    {
        char *args[] = {"ls", "-l", NULL};
        if (execvp(args[0], args) < 0) {
            perror("exec failed");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid > 0){ // Parent process
        printf("Hello from the parent process!\n");
        waitpid(pid, NULL, 0); // Wait for child process to finish
    }
    else if (pid < 0) { // Fork failed
        printf("Fork failed.\n");
        return 1;
    }

    return 0;
}

