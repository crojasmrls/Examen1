#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	//Variable para guardar el process id
	int pid;
	//parent processes id
	int ppid;
	// child processes id
	int cpid;
	//numero de procesos hijo
	int nchildren;
	//Se obtiene el id del padre
	ppid=getpid();
	//Mensaje del padre	
	printf("Hello from parent!!, my id is: %d\n", ppid);
	//Se solicita el numero de procesos hijo al usuario
	printf("Indtroduzca el numero de procesos hijo a crear: ");
	//Se lee el dato ingresado por el usuario
	scanf("%d", &nchildren);
	//Mientras sea el proceso padre y el numero de hijos restantes no es cero
	while(nchildren!=0&&ppid==getpid()){
		// Disminuye en uno el numero de procesos hijo restantes
		nchildren=nchildren-1;
		//Crea un nuevo proceso hijo
		pid=fork();
		//Si es el proceso recien creado
		if (pid==0){
			//Guarda el id del proceso creado
			cpid=getpid();
		}
	}
	//Si es el proceso creado anteriormente
	if (cpid==getpid()){
		//Este bucle hace llamadas a la función rand para dar resultados diferentes
		for (int i = 0; i < cpid; ++i)
			rand();
		//Se genera el tiempo de retraso entre 0 y 31 para el proceso hijo
		int delay=rand()%31;
		//Se espera el tiempo de retraso
		sleep(delay);
		//Se manda el mensaje del hijo
		printf("Hello from child!!, my id is: %d, i have been slept for %d seconds\n",cpid,delay);
	}
	return 0;
}