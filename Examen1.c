#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	
	int pid;//Variables para guardar id
	int ppid;//parent processes id
	int cpid;// child processes id
	int nchildren;//numero de procesos hijo
	ppid=getpid();
	printf("Hello from parent!!, my id is: %d\n", ppid);	
	printf("Indtroduzca el numero de procesos hijo a crear: ");
	scanf("%d", &nchildren);
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
		int delay=rand()%31;
		sleep(delay);
		printf("Hello from child!!, my id is: %d, i have been slept for %d seconds\n",cpid,delay);
	}
	return 0;
}