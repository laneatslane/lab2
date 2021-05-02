#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void){
char name[30];

for(int i = 1; i < 5; i++) {
pid_t pid = fork();

if(pid ==0) {
printf("Enter child process name: ");
fgets(name, 30, stdin);
printf("Child  Name : %s \n", name);
printf("Child process => PPID=%d, PID=%d\n", getppid(), getpid());
exit (0);
}
else {
wait(NULL);
printf("Parent process => PID=%d\n", getpid());
printf("Child process finished.\n");
printf("Job is done!");

}
}

return EXIT_SUCCESS;

}
