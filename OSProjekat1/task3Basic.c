#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
     

int main() {
    pid_t pid;

    pid = fork(); // Create a child process

    if (pid < 0) { // Fork failed
        printf("Fork failed.\n");
        return 1;
    }
    else if (pid == 0) // Child process
                        // exec() system call is used to replace the current process image with a new process image
                        // exec() system call is used in the child process to replace its memory image with a new 
                        //process image. The new program runs independently of the parent process, and any changes made 
                        //to the child process's memory space will not be reflected in the parent process's memory space.
    {
        printf("Hello from the child process!\n");
        char *args[] = {"ls," "-l", NULL};
        execvp(args[0],args);
    }
    else { // Parent process
        printf("Hello from the parent process!\n");
        wait(NULL); // Wait for child process to finish
    }

    return 0;
}


