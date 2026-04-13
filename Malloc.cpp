#include<stdio.h>
#include<conio.h>//En esta libreria se encuentra "getch();". NO CONFUNDIR CON "getchar();"
#include<stdlib.h>//En esta se encuentra "()malloc();", "free();" y "exit();".
int * Crea(void);//Esta funcion regresa una direccion de memoria
main()
{
	int *m=NULL;//Este es el puntero que se va a usar para recibir la direccion de memoria de la funcion 'Crea'.
	m=Crea();
	free(m);//Se usa para liberar a la memoria dinamica.	
}
//En este caso se uso una funcion de paso por valor.
int * Crea(void)
{
		int t=sizeof(int)*5;//En este caso 't' sea va a usar para representar el tamanio de la memoria dinamica y se uso a '5' como codigo duro, pero puede ser cualquier valor
		int *m2=NULL;//Esta variable es la que vamos a usar para retornar la direccion de memoria
		m2=(int *)malloc(t);//la funcion ()malloc() retorna UNA direcion de memoria de cualquier tipo de variable(char,int,float o double) o el valor'NULL' si es que no hay suficiente 
							//memoria.
							
							//En el primer parentesis se especifica el tipo de variable del que se quiere obtener la direccion de la memoria dinamica.
							
							//Mientras que el segundo sirve para dar el tamanio de la memoria dinamica(en este caso podriamos haber hecho el proceso de 't' dentro
							//del parentesis y hubiera quedado: (int *)malloc(sizeof(int)*5), pero el tamanio se perderia.
		//Observa que 'm2' no se puede declarar e inicializar al mismo tiempo ya que 'm2' != '*m2'			
		//Se podria decir que la funcion ()malloc() es como hacer un arreglo en este caso unidimencional.
		if(m2==NULL)
		{
			printf("!!NO HAY SUFICIENTE MEMORIA DISPONIBLE!!");
			getch();//Sirve para hacer una pausa al programa, solo se va a usar si es que el programa se cierra muy rapido y no da tiempo de leer el mensaje.
			exit(-1);//Sirve para que el programa finalize, en este caso se uso -1 pero puedes experimentar con tu compilador para ver si es que con otros numeros tienen diferente resultado. 
		}
		return(m2);//Recuerda que m2 es un puntero, por lo que regresa una direccion de memoria siempore que no este desreferenciado.
}

