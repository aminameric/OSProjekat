#include <stdio.h>
#include <sys/types.h>
 
int main()
{
    while(1)
       fork();   
    return 0;
}

// with this while infinite loop 
