#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	
	int pid;//Variables para guardar id
	int cpid;
	int n;
	int ppid;
	int children;
	int pipeptr[2];//Puntero a la tuberia



	printf("Indtrodusca el número de procesos hijo a crear: ");
	scanf("%d", &children);
	pipe(&pipeptr[0]);//Se declara la tuberia	

	pid=fork();//Se crea un proceso hijo

	if(pid>0){//Este es el proceso padre
		close(pipeptr[1]);
		ppid=getpid();
		n=write(pipeptr[0],&ppid,sizeof(ppid));//Escribe el id del niño en la tuberia
		printf("Parent: Hello from parent!!, my id is: %d\n", ppid);	
	} else if (pid==0)
	{
		int message;
		close (pipeptr[0]);
		sleep(2);
		ppid=getpid();
		printf("Child: Hello from child!!, my id is: %d\n",ppid);
		n=read(pipeptr[0], &message,sizeof(message));
		printf("Child: Parent pid: %d\n", message);
	}else{
		printf("ERROR at fork\n");
	}

	return 0;
}