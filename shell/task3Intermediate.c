#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;
    
    // Fork a child process
    pid = fork();
    
    if (pid < 0) {
        perror("fork error");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        
        // Execute the "ls" command
        char *args[] = {"ls", "-l", NULL};
        if (execv("/bin/ls", args) == -1) {
            perror("execv error");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        
        // Wait for the child process to complete
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid error");
            exit(EXIT_FAILURE);
        }
        
        // Send a SIGTERM signal to the child process
        if (kill(pid, SIGTERM) == -1) {
            perror("kill error");
            exit(EXIT_FAILURE);
        }
    }
    
    return 0;

}
