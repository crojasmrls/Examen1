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
	srand(time(NULL)); 
//	int pipeptr[2];//Puntero a la tuberia



	printf("Indtrodusca el numero de procesos hijo a crear: ");
	scanf("%d", &children);
	ppid=getpid();
	printf("Parent: Hello from parent!!, my id is: %d\n", ppid);	
	//pipe(&pipeptr[0]);//Se declara la tuberia	
	while(children!=0){
		if (ppid==getpid())
		{
			children=children-1;
			pid=fork();

		} else 	if (pid==0)
		{
			cpid=getpid();
			int delay=(rand()%10)+1;
			sleep(delay);
			printf("Child: Hello from child!!, my id is: %d\n",ppid);
			printf("Child: I have been slept for %d seconds\n",delay );
		}
	}
	return 0;
}