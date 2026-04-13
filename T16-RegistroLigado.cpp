#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 50
typedef struct cadena
{   char nom[T];
    struct cadena *q;
}cad;
typedef struct flotante
{   float flo;
    struct flotante *s;
}flota;
typedef struct entero
{   int ent;
    struct entero *t;
}enter;
typedef struct conjunto
{   cad *ptrA;
    flota *ptrB;
    enter *ptrC;
}con;
cad* NuevoA()
{   cad *nvo = NULL;
    nvo = (cad *)malloc(sizeof(cad));
    if(nvo == NULL)
    {
        printf("Error en memoria\n");
        //LiberarA(nvo);
        exit(1);
    }
    return (nvo);
}
flota* NuevoB()
{   flota *nvo = NULL;
    nvo = (flota *)malloc(sizeof(flota));
    if(nvo == NULL)
    {
        printf("Error en memoria\n");
        //LiberarA(nvo);
        //LiberarB(nvo);
        exit(1);
    }
    return (nvo);
}
enter* NuevoC()
{   enter *nvo = NULL;
    nvo = (enter *)malloc(sizeof(enter));
    if(nvo == NULL)
    {
        printf("Error en memoria\n");
        //LiberarA();
        //LiberarB();
        //LiberarC();
        exit(1);
    }
    return (nvo);
}
void LiberarA(cad *);
void LiberarB(flota *);
void LiberarC(enter *);
int main()
{   con *ptr1 = NULL;
    ptr1 = (con*)malloc(sizeof(con));
    ptr1->ptrA = NuevoA();
    strcpy(ptr1->ptrA->nom, "Luis"); //ptr1->ptrA->nom = "Luis";
    ptr1->ptrA->q = NuevoA();
    strcpy(ptr1->ptrA->q->nom, "Ana"); //ptr1->ptrA->q->nom = "Ana";
    ptr1->ptrA->q->q = NULL;
    ptr1->ptrB = NuevoB();
    ptr1->ptrB->flo = 6.9;
    ptr1->ptrB->s = NuevoB();
    ptr1->ptrB->s->flo = 4.2;
    ptr1->ptrB->s->s = NULL;
    ptr1->ptrC = NuevoC();
    ptr1->ptrC->ent = 6;
    ptr1->ptrC->t = NuevoC();
    ptr1->ptrC->t->ent = 9;
    ptr1->ptrC->t->t = NULL;
    printf("Usando ptr1->\n");
    printf("ptrA->nom = %s|ptrA->q = %p|ptrA->q->nom = %s|ptrA->q-> %p\n", ptr1->ptrA->nom, ptr1->ptrA->q, ptr1->ptrA->q->nom, ptr1->ptrA->q->q);
    printf("ptrB->flo = %.1f|ptrB->s = %p|ptrB->s->flo = %.1f|ptrB->s->s = %p\n", ptr1->ptrB->flo, ptr1->ptrB->s, ptr1->ptrB->s->flo, ptr1->ptrB->s->s);
    printf("ptrC->ent = %d|ptrC->t = %p|ptrC->t->ent = %d|ptrC->t->t = %p\n", ptr1->ptrC->ent, ptr1->ptrC->t, ptr1->ptrC->t->ent, ptr1->ptrC->t->t);
    LiberarA(ptr1->ptrA);
    LiberarB(ptr1->ptrB);
    LiberarC(ptr1->ptrC);
    //free(ptr1->ptrC->t);
    //free(ptr1->ptrC);
    //free(ptr1->ptrB->s);
    //free(ptr1->ptrB);
    //free(ptr1->ptrA->q);
    //free(ptr1->ptrA);
    free(ptr1);
    printf("Toda memoria liberada\n");  
    return 0;
} 
void LiberarA(cad *raiz) 
{   cad *aux;
    while (raiz != NULL) 
    {   aux = raiz; // Para no perder la raiz       
        raiz = raiz->q; // Paran no perder la rama
        free(aux); // se borra desde raiz hasta ramas sin perder el vinculo gracias al aux    
        printf("Memoria liberada\n");  
    }
}
void LiberarB(flota *raiz) 
{   flota *aux;
    while (raiz != NULL) 
    {   aux = raiz;
        raiz = raiz->s;
        free(aux);
        printf("Memoria liberada\n");  
    }
}
void LiberarC(enter *raiz) 
{   enter *aux;
    while (raiz != NULL) 
    {   aux = raiz;
        raiz = raiz->t;
        free(aux);
        printf("Memoria liberada\n");  
    }
}