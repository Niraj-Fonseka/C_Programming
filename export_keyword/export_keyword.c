#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    printf("OUTSIDE : %s \n" , getenv("OUTSIDE"));
    callFork();
    return 0;
}

void callFork() {

    printf("OUTSIDE : %s \n" , getenv("OUTSIDE"));
    putenv("GREETING=hello");

    const char* s = getenv("GREETING");

    printf("printing greeting : %s , pid : %lun \n",s , getpid());
    

    if (fork() == 0)
    {
        printf("Hello from child \n");
        printf("OUTSIDE : %s \n" , getenv("OUTSIDE"));

        const char* s_child = getenv("GREETING");
        printf("printing greeting from child : %s , pid : %lun  \n",s_child, getpid());

        if (fork() == 0)
        {
        printf("Hello from child's child \n");
        printf("OUTSIDE : %s \n" , getenv("OUTSIDE"));

        const char* s_child_child = getenv("GREETING");
        printf("printing greeting from child's child : %s , pid : %lun  \n",s_child_child, getpid());
        }
    }
    else 
    {
        printf("Hello from parent \n");
    }
}