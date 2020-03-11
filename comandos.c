#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "comandos.h"
#include <stdio_ext.h>
#include <unistd.h>
#include <fcntl.h>
 
char *com1=NULL;
char *com2=NULL;
char *com3=NULL;
char *com4=NULL;
char *com5=NULL;
char *com6=NULL;
char *com7=NULL;
char *com8=NULL;

int verificarCadena(char* cad) 
{
	printf("v = %s\n", cad);
	char* cadena = (cad);
	char* c = cad;
	cadena = strtok(c, ":");

	if (strcasecmp(cadena, "-name") == 0) 
	{
		cadena = strtok(NULL, ":");
		char nombre[100];
		strcpy(nombre, cadena);
		if (nombre[0] == '"') 
		{
			int i = 0;
			int cont = 0;
			for (i = 0; i < 100; i++) 
			{
				if (nombre[i] != NULL) 
				{
					printf("Diferente de null\n");
					if (nombre[i] == '"') 
					{
						cont++;
						printf("comillas = ");
					}
				}
			}
			if (cont == 2) { return 1; } 
			else { return 0; }
			nombre[i] = '\0';
			nombre[i + 1] = '\0';
		}
	} 
	else if (strcasecmp(cadena, "-path") == 0) 
	{
		cadena = strtok(NULL, ":");
		char nombre[50];
		strcpy(nombre, cadena);
		if (nombre[0] == '"') 
		{
			int i = 0;
			int cont = 0;
			for (i = 0; i < 50; i++) 
			{
				printf("P\n");
				if (nombre[i] == '"') { cont++; }
			}

			if (cont == 2) { return 1; } 
			else { return 0; }
			nombre[i] = '\0';
			nombre[i + 1] = '\0';
		}
	}
	return 0;
}

void verificarComando(char *com, char *atributos)
{
	limpiarVariables();

    char* inst=NULL;
    int cont=1;

    if(strcasecmp(com,"mkdisk")==0 ) // ya
	{
    	char aux[100];
    	strcpy(aux, atributos);
    	inst = strtok(atributos," ");
    	while(inst!=NULL)
		{
			inst = strtok(NULL, " ");
			switch(cont)
			{
				case 1:
					com1=inst;
					break;
				case 2:
					com2=inst;
					break;
				case 3:
					com3=inst;
					break;
				case 4:
					com4=inst;
					break;
			}
			cont++;
    	}
    	int i;
    	for(i=1;i<cont-1;i++)
		{
			if(i==1){ atributoDisco(com1); }
			else if(i==2){ atributoDisco(com2); }
			else if(i==3){ atributoDisco(com3); }
			else if(i==4){ atributoDisco(com4); }
    	}
        crearDisco(1);
    }
	else  if(strcasecmp(com,"rmdisk")==0 ) // ya
	{
		char aux[100];
    	strcpy(aux, atributos);
    	inst = strtok(atributos," ");
    	while(inst!=NULL)
		{
    	    inst = strtok(NULL, " ");
    		switch(cont)
			{
    			case 1:
    				com1=inst;
    				break;
    		}
    		cont++;
    	}
    	int i;
    	for(i=1;i<cont-1;i++) { if(i==1){ atributoDisco(com1); } }
    	eliminarDisco();
    } 
	else  if(strcasecmp(com,"fdisk")==0 ) // ya
	{
		char aux[100];
        strcpy(aux, atributos);
        inst = strtok(atributos," ");
        while(inst!=NULL)
		{
			inst = strtok(NULL, " ");
           	switch(cont)
			{
           		case 1:
           			com1=inst;
           			break;
           		case 2:
           			com2=inst;
           			break;
           		case 3:
           			com3=inst;
           			break;
           		case 4:
           			com4=inst;
           			break;
           		case 5:
           		    com5=inst;
           		    break;
           		case 6:
           		    com6=inst;
           		    break;
           		case 7:
           		    com7=inst;
           		    break;
           		case 8:
           		      com8=inst;
           		      break;
           	}
           	cont++;
        }
        int i;
        for(i=1;i<cont-1;i++)
		{
			if(i==1){ atributoDisco(com1); }
			else if(i==2){ atributoDisco(com2); }
			else if(i==3){ atributoDisco(com3); }
			else if(i==4){ atributoDisco(com4); }
			else if(i==5){ atributoDisco(com5); }
			else if(i==6){ atributoDisco(com6); }
			else if(i==7){ atributoDisco(com7); }
			else if(i==8){ atributoDisco(com8); }
        }
        adminParticion();
    } 
	else  if(strcasecmp(com,"mount")==0 ) // ya
	{
		char aux[100];
    	strcpy(aux, atributos);
    	inst = strtok(atributos," ");
    	while(inst!=NULL)
		{
			inst = strtok(NULL, " ");
    		switch(cont)
			{
				case 1:
					com1=inst;
					break;
    			case 2:
					com2=inst;
					break;
    		}
    		cont++;
    	}
    	int i;
    	for(i=1;i<cont-1;i++)
		{
    		if(i==1){  atributoDisco(com1); }
			else if(i==2){ atributoDisco(com2); }
    	}
		montarP();
		mostrarMontadas();
    } 
	else  if(strcasecmp(com,"umount")==0 ) // ya
	{
		char aux[100];
        strcpy(aux, atributos);
    	inst = strtok(atributos," ");
        while(inst!=NULL)
		{
			inst = strtok(NULL, " ");
			switch(cont)
			{
				case 1:
            		com1=inst;
            		break;
            	case 2:
            		com2=inst;
            		break;
            	case 3:
            		com3=inst;
            		break;
            	case 4:
            		com4=inst;
            		break;
            	case 5:
            		com5=inst;
            		break;
            	case 6:
            		com6=inst;
            		break;
            	case 7:
            		com7=inst;
            		break;
            	case 8:
            		com8=inst;
            		    break;
            }
            cont++;
        }
        int i;
        for(i=1;i<cont-1;i++)
		{
			if(i==1){ atributoDisco(com1); desmontar(com1); }
			else if(i==2){ atributoDisco(com2); desmontar(com2); }
			else if(i==3){ atributoDisco(com3); desmontar(com3); }
			else if(i==4){ atributoDisco(com4); desmontar(com4); }
			else if(i==5){ atributoDisco(com5); desmontar(com5); }
			else if(i==6){ atributoDisco(com6); desmontar(com6); }
			else if(i==7){ atributoDisco(com7); desmontar(com7); }
			else if(i==8){ atributoDisco(com8); desmontar(com8); }
        }
    } 
	else  if(strcasecmp(com,"REP")==0 ) // ya
	{
		char aux[100];
        strcpy(aux, atributos);
        inst = strtok(atributos," ");
        while(inst!=NULL)
		{
			inst = strtok(NULL, " ");
            switch(cont)
			{
				case 1:
               	 	com1=inst;
               	 	break;
               	case 2:
               		com2=inst;
               		break;
               	case 3:
               		com3=inst;
               	 	break;
				case 4:
					com4 = inst;
					break;
            }
            cont++;
        }
		int i;
        for(i=1;i<cont-1;i++)
		{
			if(i==1){ atributoDisco(com1); }
			else if(i==2){ atributoDisco(com2); }
			else if(i==3){ atributoDisco(com3); }
			else if(i==4){ atributoDisco(com4); }
        }
        generarReporte();

    }
	else  if(strcasecmp(com,"exec")==0 ) // ya
	{
		char aux[100];
        strcpy(aux, atributos);
        inst = strtok(atributos," ");
        while(inst!=NULL)
		{
			inst = strtok(NULL, " ");
            switch(cont)
			{
				case 1:
                	com1=inst;
                	break;
            }
            cont++;
        }
		int i;
        for(i=1;i<cont-1;i++){ if(i==1){ atributoDisco(com1); } }
        script();

    }
	else if (strcasecmp(com, "mkfs") == 0 )  // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) {
			case 1:
				com1 = inst;
				break;
			case 2:
				com2 = inst;
				break;
			case 3:
				com3 = inst;
				break;
			case 4:
				com4 = inst;
				break;
			case 5:
				com5 = inst;
				break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) 
		{
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			} else if (i == 3) {
				atributoDisco(com3);
			} else if (i == 4) {
				atributoDisco(com4);
			} else if (i == 5) {
				atributoDisco(com5);
			}
		}
		formatear();
	}
	else if (strcasecmp(com, "login") == 0 ) // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
				case 3:
					com3 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			} else if (i == 3) {
				atributoDisco(com3);
			}
		}
		login();

	} 
	else if (strcasecmp(com, "logout") == 0 ) // ya
	{
		logout();
	}
	else if (strcasecmp(com, "mkgrp") == 0 ) // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			}
		}

		crearGrupo();

	} 
	else if (strcasecmp(com, "rmgrp") == 0 )  // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			}
		}
		eliminarGrupo();

	} 
	else if (strcasecmp(com, "mkusr") == 0 ) // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
				case 3:
					com3 = inst;
					break;
				case 4:
					com4 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			} else if (i == 3) {
				atributoDisco(com3);
			} else if (i == 4) {
				atributoDisco(com4);
			}
		}
		
		crearUsuario();

	} 
	else if (strcasecmp(com, "rmusr") == 0 ) // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			}
		}

		eliminarUsuario();

	} 
	else if (strcasecmp(com, "chmod") == 0 ) // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
				case 3:
					com3 = inst;
					break;
				case 4:
					com4 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			} else if (i == 3) {
				atributoDisco(com3);
			} else if (i == 4) {
				atributoDisco(com4);
			}
		}
		
		permisoMetodo();

	} 
	else if (strcasecmp(com, "mkfile") == 0 ) // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
				case 3:
					com3 = inst;
					break;
				case 4:
					com4 = inst;
					break;
				case 5:
					com5 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			} else if (i == 3) {
				atributoDisco(com3);
			} else if (i == 4) {
				atributoDisco(com4);
			} else if (i == 5) {
				atributoDisco(com5);
			}
		}
		
		crearArchivo();

	} 
	else if (strcasecmp(com, "cat") == 0 ) // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
				case 3:
					com3 = inst;
					break;
				case 4:
					com4 = inst;
					break;
				case 5:
					com5 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			} else if (i == 3) {
				atributoDisco(com3);
			} else if (i == 4) {
				atributoDisco(com4);
			} else if (i == 5) {
				atributoDisco(com5);
			}
		}
		
		mostrarContenido();

	} 
	else if (strcasecmp(com, "rem") == 0 ) // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
				case 3:
					com3 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			} else if (i == 3) {
				atributoDisco(com3);
			}
		}
		
		remover();

	} 
	else if (strcasecmp(com, "edit") == 0 )  // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
				case 3:
					com3 = inst;
					break;
				case 4:
					com4 = inst;
					break;
				case 5:
					com5 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			} else if (i == 3) {
				atributoDisco(com3);
			} else if (i == 4) {
				atributoDisco(com4);
			} else if (i == 5) {
				atributoDisco(com5);
			}
		}
		
		editar();

	} 
	else if (strcasecmp(com, "ren") == 0 )   // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
				case 3:
					com3 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			} else if (i == 3) {
				atributoDisco(com3);
			}
		}
		
		renombrar();
	} 
	else if (strcasecmp(com, "mkdir") == 0 ) // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
				case 3:
					com3 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			} else if (i == 3) {
				atributoDisco(com3);
			}
		}
		
		crearDirectorio();

	} 
	else if (strcasecmp(com, "cp") == 0 ) // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
				case 3:
					com3 = inst;
					break;
				case 4:
					com4 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			} else if (i == 3) {
				atributoDisco(com3);
			} else if (i == 4) {
				atributoDisco(com4);
			}
		}
		
		copiar();

	} 
	else if (strcasecmp(com, "mv") == 0 ) // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
				case 3:
					com3 = inst;
					break;
				case 4:
					com4 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			} else if (i == 3) {
				atributoDisco(com3);
			} else if (i == 4) {
				atributoDisco(com4);
			}
		}
		
		mover();

	} 
	else if (strcasecmp(com, "find") == 0 ) // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
				case 3:
					com3 = inst;
					break;
				case 4:
					com4 = inst;
					break;
				case 5:
					com5 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			} else if (i == 3) {
				atributoDisco(com3);
			} else if (i == 4) {
				atributoDisco(com4);
			} else if (i == 5) {
				atributoDisco(com5);
			}
		}
		
		encontrar();

	} 
	else if (strcasecmp(com, "chown") == 0 )
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
				case 3:
					com3 = inst;
					break;
				case 4:
					com4 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			} else if (i == 3) {
				atributoDisco(com3);
			} else if (i == 4) {
				atributoDisco(com4);
			}
		}
		//imprimirDatos();

	} 
	else if (strcasecmp(com, "chgrp") == 0 ) 
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
				case 2:
					com2 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			} else if (i == 2) {
				atributoDisco(com2);
			}
		}
		//imprimirDatos();

	} 
	else if(strcasecmp(com,"pause")==0 ) // ya
	{
		printf("Presione cualquier tecla para continuar");
		getchar();
	}
	else if (strcasecmp(com, "recovery") == 0) // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) 
		{
			inst = strtok(NULL, " ");
			switch (cont) 
			{
				case 1:
					com1 = inst;
					break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) { if (i == 1) { atributoDisco(com1); } }
		recovery();
	} 
	else if (strcasecmp(com, "loss") == 0 ) // ya
	{
		char aux[100];
		strcpy(aux, atributos);
		inst = strtok(atributos, " ");
		while (inst != NULL) {
			inst = strtok(NULL, " ");
			switch (cont) {
			case 1:
				com1 = inst;
				break;
			}
			cont++;
		}
		int i;
		for (i = 1; i < cont - 1; i++) {
			if (i == 1) {
				atributoDisco(com1);
			}
		}
		loss();
	}
}
