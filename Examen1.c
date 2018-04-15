#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	int pid, ppid;//
	int pp[2];//Espacio de memoria para la tuberia
	pipe(&pp[0]);//Se declara la tuberia
	pid=fork();//Se crea un proceso hijo
	if(pid>0){//Este es el proceso padre
		int n;
		int message;
		close(pp[1]);
		n=write(pp[1],&pid,sizeof(pid));
		ppid=getpid();
		printf("Parent: Hello from parent!!, my id is: %d\n", ppid);
		printf("Parent: Reading message from the pipe... \n");
		while (wait(NULL)!=pid);
		
	}

	return 0;
}