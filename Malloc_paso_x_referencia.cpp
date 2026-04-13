#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void Crea(int **);
main()
{
	int *m=NULL;
	Crea(&m);//Recuerda que '&' se usa para obtener la direccion de memoria de la variable, en este caso del puntero
	//Se envia la direccion de memoria del puntero porque esta es la que vamos a modificar para que despues
	//de la funcion 'Crea' sea la direccion de inicio de la memoria dinamica.
	free(m);//Recuerda siempre liberar la memoria dinamica, Tapia insistio mucho en  hacerlo.	
}
//Funcion paso x referencia.
void Crea(int **m2)  //Recueda que para poder cachar una direccion de memoria se necesita un puntero, pero para 
					//cachar la direccion de un puntero se necesita un doble puntero (**), por lo para cachar la
					//direccion de un doble puntero se necesita uno tripe (***) y asi sucesivamente.
{
		int t=sizeof(int)*5;
		*m2=(int *)malloc(t);
		if(*m2==NULL)
		{
			printf("!!NO HAY SUFICIENTE MEMORIA DISPONIBLE!!");
			getch();
			exit(-1); 
		}
}

