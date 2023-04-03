#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork(); // Create a child process

    if (pid == -1) { // Fork failed
        printf("Fork failed.\n");
        return 1;
    }
    else if (pid == 0) { // Child process
        printf("Hello from the child process!\n");
        
        // Use execv() to execute a new program
        char *args[] = {"ls", "-l", NULL};
        execv("/bin/ls", args);

        // execv() only returns if an error occurred
        printf("Failed to execute program.\n");
        return 1;
    }
    else { // Parent process
        printf("Hello from the parent process!\n");
        
        // Send SIGTERM signal to child process
        kill(pid, SIGTERM);

        // Wait for child process to finish
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}
