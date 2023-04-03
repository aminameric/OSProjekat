#include <stdio.h>
#include <string.h>
#include <unistd.h>

void prompt(){
    	char in[100];
    	char hostname[100];
		char *login = getlogin();
    	gethostname(hostname, 100);
    	printf("%s@%s:~$", hostname, login);
		scanf("%s", in)
}

int main(){
    	while(1) {
    	prompt();
    	}
}


