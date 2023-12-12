#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void main(){
    pid_t c;
    
    c = fork();

    if(c < 0){
        printf("error!");
    } else if(c == 0){
        printf("running %d", getpid());
        sleep(1);
    } else {
        printf("Exit!");
    }

    int status;
    waitpid(c, &status, 0);

    if(WIFEXITED(status)){
        printf("Exit success!");
    } else {
        printf("Abnormal exit");
    }

    if(kill(c, SIGTERM) == 0){
        printf("Killed!!");
    } else {
        printf("IMMORTAL");
    }

    
}