#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	
	int pid;//Variables para guardar id
	int cpid;
	int ppid;
	int children;
	srand(time(NULL)); 
//	int pipeptr[2];//Puntero a la tuberia



	printf("Indtrodusca el numero de procesos hijo a crear: ");
	scanf("%d", &children);
	//pipe(&pipeptr[0]);//Se declara la tuberia	
	pid=fork();

	if(pid>0){//Este es el proceso padre
		//int n;
//		close(pipeptr[0]);
		ppid=getpid();
//		n=write(pipeptr[1],&ppid,sizeof(ppid));//Escribe el id del hijoen la tuberia
		printf("Parent: Hello from parent!!, my id is: %d\n", ppid);	
	} else if (pid==0)
	{
		while(children!=0){
			if (pid==0)
			{
				children-=1;
				pid=fork();
			}
		}
		int delay=(rand()%30)+1;
		//int n;
		//int message;
		//close (pipeptr[1]);
		sleep(delay);
		ppid=getpid();
		printf("Child: Hello from child!!, my id is: %d\n",ppid);
		printf("Child: I have been slept for %d seconds\n",delay );
		//n=read(pipeptr[0], &message,sizeof(message));
		//printf("Child: Parent pid: %d\n", message);
	}else{
		printf("ERROR at fork\n");
	}

	return 0;
}