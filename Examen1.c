#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	
	int pid;//Variables para guardar id
	int ppid;//parent processes id
	int cpid;// child processes id
	int nchildren;//numero de procesos hijo
	printf("Indtrodusca el numero de procesos hijo a crear: ");
	scanf("%d", &nchildren);
	ppid=getpid();
	printf("Parent: Hello from parent!!, my id is: %d\n", ppid);	
	while(nchildren!=0&&ppid==getpid()){
		nchildren=nchildren-1;
		pid=fork();
		if (pid==0)
		{
			cpid=getpid();
		}
	}
	if (cpid==getpid())
	{
		for (int i = 0; i < cpid; ++i)
			rand();
		int delay=rand()%11;
		sleep(delay);
		printf("Child: Hello from child!!, my id is: %d\nChild: I have been slept for %d seconds\n",cpid,delay);
	}
	return 0;
}