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
		n=write(pp[0],&pid,sizeof(pid));//Escribe el id del niño en la tuberia
		ppid=getpid();
		printf("Parent: Hello from parent!!, my id is: %d\n", ppid);
		printf("Parent: Reading message from the pipe... \n");
		while (wait(NULL)!=pid);
		n=read(pp[0], &message,sizeof(message));
		printf("Parent: The message is: %d\n", message );		
	} else if (pid==0)
	{
		int n;
		int message = 65;
		close(pp[0]);
		ppid=getpid();
		printf("Child: Hello from child!!, my id is: %d\n",ppid);
		printf("Child: Sending message to the pipe\n");
		n=write(pp[1], &message, sizeof(message));
	}else{
		printf("ERROR at fork\n");
	}

	return 0;
}