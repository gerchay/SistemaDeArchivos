#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "acciones.h"
#include "estructuras.h"
#include "comandos.h"
#include <stdio_ext.h>
#include <unistd.h>
#include <fcntl.h>

int opcion=1;
int salida;
char letras[15];

int main()
{
    printf("\n*---------------  SISTEMA DE ARCHIVOS         --------------**\n");
    printf("*---------------  Luis Gerardo Chay Grijalva  --------------** \n");
    printf("*---------------  201700345                   --------------** \n");
    char com[1000];
    char com2[1000];
    while(opcion!=0)
    {
        printf("\n\n~~>: ");
        fgets(com,500,stdin);
        int i;
        strcpy(com2, com);
        char *comando = NULL;
        comando = strtok( com, " ");
        char *atr;
        if(comando!=NULL)
        {
    	   atr = com2;
    	   verificarComando(comando, atr);
        }
    }
    return 0;
}
