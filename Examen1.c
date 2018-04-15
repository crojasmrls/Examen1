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
	int *pipeptr;//Puntero a la tuberia
	int message;


	printf("Indtrodusca el número de procesos hijo a crear: ");
	scanf("%d", &children);
	pipeptr= calloc(children+1,sizeof(ppid));
	pipe(pipeptr);//Se declara la tuberia	

	pid=fork();//Se crea un proceso hijo

	if(pid>0){//Este es el proceso padre
		for (int i = 1; i < children+1; ++i)
		{
			close(*(pipeptr+i));
		}
		ppid=getpid();
		n=write(*pipeptr,&ppid,sizeof(ppid));//Escribe el id del niño en la tuberia
		printf("Parent: Hello from parent!!, my id is: %d\n", ppid);	
	} else if (pid==0)
	{
		sleep(2);
		for (int i = 2; i < children+1; ++i)
		{
			close(*(pipeptr+i));
		}
		ppid=getpid();
		printf("Child: Hello from child!!, my id is: %d\n",ppid);
		n=read(*pipeptr, &message,sizeof(message));
		printf("Child: Parent pid: %d\n", message);
	}else{
		printf("ERROR at fork\n");
	}

	return 0;
}