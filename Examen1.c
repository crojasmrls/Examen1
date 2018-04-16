#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	
	int pid;//Variables para guardar id
	int ppid;
	int cpid;
	int children;
	int delay;
	//
//	int pipeptr[2];//Puntero a la tuberia



	printf("Indtrodusca el numero de procesos hijo a crear: ");
	scanf("%d", &children);
	ppid=getpid();
	printf("Parent: Hello from parent!!, my id is: %d\n", ppid);	
	//pipe(&pipeptr[0]);//Se declara la tuberia	
	while(children!=0&&ppid==getpid()){
		children=children-1;
		pid=fork();
		if (pid==0)
		{
			delay=(rand()%10)+1;
			cpid=getpid();
		}
	}
	if (cpid==getpid())
	{
		sleep(delay);
		printf("Child: Hello from child!!, my id is: %d\n",cpid);
		printf("Child: I have been slept for %d seconds\n",delay );
	}
	return 0;
}