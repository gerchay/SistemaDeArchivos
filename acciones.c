#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "acciones.h"
#include "estructuras.h"
#include <unistd.h>
#include <fcntl.h>

char* ruta = NULL;
char* size=NULL;
char* unit=NULL;
char* path=NULL;
char* type=NULL;
char* fit=NULL;
char* dele=NULL;
char* name=NULL;
char* add=NULL;
char* id=NULL;
int raid=0;
int boolCrearDisco = 1;
int varLetra = 0;
int boolK = 0;
int boolM = 0;
int boolH = 0;
int boolI = 0;
char* nDirectorio = NULL;
char* fs = NULL;
char* p = NULL;
char* cont = NULL;
char* ugo = NULL;
char* R = NULL;
int boolR = 0;
char* filen = NULL;
int rf = 0;
char* dest = NULL;
char* iddest = NULL;
char* file = NULL;
char* allocation;
int contadorM = 0;
int boolExec = 0;
int bool = 0;
int correcto = 1;
int boolEditar = 0;
int contadorArchivo = 0;
char* contenidoUsers = NULL;
char* arch = "*";
int boolLs = 0;

char* usuarioo = NULL;
char* password = NULL;
char* grupo = NULL;
char* permi = NULL;
char* userr = NULL;
int boolLogin = 0;
char* usrLogin = NULL;
int contadorUsuario = 0;
int contadorGrupo = 0;
char caracter[1000];
char* inst = NULL;
char* contadorU = NULL;
char* tipoU = NULL;
char* grupoU = NULL;
char* nombreU = NULL;
char* passU = NULL;
int con = 1;
char* contEliminar = NULL;
atrib atrUsuario[50];
atrib atribUsuario[50];

// ================================= PRIMERA FASE ======================

void atributoDisco(char* coman)
{
	char* token1 = tolower(coman);
    char* com=coman;
    token1=strtok(com,"=");
	if(token1!=NULL)
	{
		if(strcasecmp(token1,"-size")==0)
		{
			token1=strtok(NULL,"=");
			char *auxtoken1;
    		auxtoken1 = strtok(token1,"\n");
			size=auxtoken1;
		}
		else if(strcasecmp(token1,"-unit")==0)
		{
			token1=strtok(NULL,"=");
			char *auxtoken1;
    		auxtoken1 = strtok(token1,"\n");
			unit=auxtoken1;
		}
		else if(strcasecmp(token1,"-path")==0)
		{
			token1=strtok(NULL,"=");
			char direccion[200];
			strcpy(direccion,token1);
			if(direccion[0]=='"')
			{
				int i=0;
				while(direccion[i+1]!='"') //Le quita las comillas
				{
					direccion[i]=direccion[i+1];
					if(direccion[i]==' '){ direccion[i]='_'; }
				    i++;
				}
				direccion[i]='\0';
				direccion[i+1]='\0';
			}
			strcpy(token1,direccion);
			char *auxtoken1;
    		auxtoken1 = strtok(token1,"\n");
			path=auxtoken1;
		}
		else if(strcasecmp(token1,"-type")==0)
		{
			token1=strtok(NULL,"=");
			char *auxtoken1;
    		auxtoken1 = strtok(token1,"\n");
			type=auxtoken1;
		}
		else if(strcasecmp(token1,"-fit")==0)
		{
			token1=strtok(NULL,"=");
			char *auxtoken1;
    		auxtoken1 = strtok(token1,"\n");
			fit=auxtoken1;
		}
		else if(strcasecmp(token1,"-delete")==0)
		{
			token1=strtok(NULL,"=");
			char *auxtoken1;
    		auxtoken1 = strtok(token1,"\n");
			dele=auxtoken1;
		}
		else if(strcasecmp(token1,"-name")==0)
		{
			token1=strtok(NULL,"=");
			char nombre[200];
			strcpy(nombre,token1);
			if(nombre[0]=='"')
			{
				int i=0;
				while(nombre[i+1]!='"')//Le quita las comillas
				{ 
					nombre[i]=nombre[i+1];
					if(nombre[i]==' ') { nombre[i]='_'; }
					i++;
				}
				nombre[i]='\0';
				nombre[i+1]='\0';
			}
			strcpy(token1,nombre);
			char *auxtoken1;
    		auxtoken1 = strtok(token1,"\n");
			name=auxtoken1;
		}
		else if(strcasecmp(token1,"-add")==0)
		{
			token1=strtok(NULL,"=");
			char *auxtoken1;
    		auxtoken1 = strtok(token1,"\n");
			add=auxtoken1;
		}
		else if(strcasecmp(token1,"-id")==0)
		{
			token1=strtok(NULL,"=");
			char *auxtoken1;
    		auxtoken1 = strtok(token1,"\n");
			id=auxtoken1;
		}
		else if(strcasecmp(token1,"-id1")==0 || strcasecmp(token1,"-id2")==0 || strcasecmp(token1,"-id3")==0 || strcasecmp(token1,"-id4")==0 || strcasecmp(token1,"-id5")==0 || strcasecmp(token1,"-id6")==0 || strcasecmp(token1,"-id7")==0|| strcasecmp(token1,"-id8")==0)
		{
			token1=strtok(NULL,"=");
			char *auxtoken1;
    		auxtoken1 = strtok(token1,"\n");
			id=auxtoken1;
		}
		else if(boolExec==1)
		{ 
			token1=strtok(NULL,"=");
			char direccion[200];
			strcpy(direccion,token1);
			if(direccion[0]=='"')
			{
				int i=0;
				while(direccion[i+1]!='"')
				{
					direccion[i]=direccion[i+1];
					if(direccion[i]==' '){ direccion[i]='_'; }
					i++;
				}
				direccion[i]='\0';
				direccion[i+1]='\0';
			}
			strcpy(token1,direccion);
			char *auxtoken1;
    		auxtoken1 = strtok(token1,"\n");
			path=auxtoken1;

        }
		else if(strcasecmp(token1,"-fs")==0)
		{
			token1=strtok(NULL,"=");
			char *auxtoken1;
    		auxtoken1 = strtok(token1,"\n");
			fs=auxtoken1;
		}
		else if(strcasecmp(token1,"-usr")==0)
		{
			token1=strtok(NULL,"=");
			char *auxtoken1;
    		auxtoken1 = strtok(token1,"\n");
			usuarioo=auxtoken1;
		}
		else if(strcasecmp(token1,"-pwd")==0)
		{
			token1=strtok(NULL,"=");
			char *auxtoken1;
    		auxtoken1 = strtok(token1,"\n");
			password=auxtoken1;
		}
		else if(strcasecmp(token1,"-grp")==0)
		{
			token1=strtok(NULL,"=");
			char *auxtoken1;
    		auxtoken1 = strtok(token1,"\n");
			grupo = auxtoken1;
		}
		else if(strcasecmp(token1,"-ugo")==0)
		{
			token1=strtok(NULL,"=");
			char *auxtoken1;
    		auxtoken1 = strtok(token1,"\n");
			ugo = auxtoken1;
		}
		else if (strcasecmp(token1, "-r") == 0) 
		{
			boolR = 1;
		}
		else if (strcasecmp(token1, "-p") == 0) 
		{
			p = "p";
		}
		else if (strcasecmp(token1, "-cont") == 0) 
		{
			token1 = strtok(NULL, "=");
			char direccion[200];
			strcpy(direccion, token1);
			if (direccion[0] == '"') {
				int i = 0;
				while (direccion[i + 1] != '"') { //Le quita las comillas
					direccion[i] = direccion[i + 1];
					if (direccion[i] == ' ') {
						direccion[i] = '_';
					}
					i++;
				}
				direccion[i] = '\0';
				direccion[i + 1] = '\0';
			}
			strcpy(token1, direccion);
			cont = token1;
		}
		else if (strcasecmp(token1, "-file") == 0) 
		{
			token1 = strtok(NULL, "=");
			char direccion[200];
			strcpy(direccion, token1);
			if (direccion[0] == '"') {
				int i = 0;
				while (direccion[i + 1] != '"') { //Le quita las comillas
					direccion[i] = direccion[i + 1];
					if (direccion[i] == ' ') {
						direccion[i] = '_';
					}
					i++;
				}
				direccion[i] = '\0';
				direccion[i + 1] = '\0';
			}
			strcpy(token1, direccion);
			file = token1;

		}
		else if (strcasecmp(token1, "-dest") == 0) 
		{
			token1 = strtok(NULL, "=");
			char direccion[200];
			strcpy(direccion, token1);
			if (direccion[0] == '"') {
				int i = 0;
				while (direccion[i + 1] != '"') { //Le quita las comillas
					direccion[i] = direccion[i + 1];
					if (direccion[i] == ' ') {
						direccion[i] = '_';
					}
					i++;
				}
				direccion[i] = '\0';
				direccion[i + 1] = '\0';
			}
			strcpy(token1, direccion);
			dest = token1;

		}
		else
		{
        	printf("ERROR: El atributo \"%s\" es incorrecto.\n",token1);
        }
	}
}

void crearDisco(int num)
{
	boolCrearDisco = 1;
	if(unit==NULL){ unit="m"; }
	if(size==NULL || path==NULL){ printf("ERROR: Falta un atributo obligatorio.\n"); }
	else
	{
		if(size>0)
		{
			char pathNuevo[50];
			strcpy(pathNuevo, path);

			int d =crearArchivoBinario(size,unit,path);
			if(d==0){printf("\nSe han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");}
			if (num == 1) 
			{
				
				//Recover
				FILE *archivo;
				char *recovery = concatenar( "/home/chay/recovery",name);
				archivo = fopen(recovery, "w+");
				fclose(archivo);
				copiarFichero(path, recovery);

				//Copy
				char *nombre = concatenar(pathNuevo, name);
				name = concatenar("Copy", name);
				path = concatenar(pathNuevo, name);
				copiarFichero(nombre, path);
				printf("/");
				strcpy(path, pathNuevo);
			}
		}
		else{ printf("ERROR: El tamanio es incorrecto.\n"); }
	}
}

int crearArchivoBinario(char* size, char* unit, char* path)
{
	int unidad=0;
	int tam=atoi(size);
	if(strcmp(unit,"M")==0 || strcmp(unit,"m")==0 ){ unidad =1; }  
	else if(strcmp(unit,"K")==0 || strcmp(unit,"k")==0 ){ unidad=2; }
	else
	{
       printf("ERROR: La unidad no existe. \n");
       boolCrearDisco =0;
       return 0;
    }
	if(boolCrearDisco ==1)
	{
		char direcc[200];
	   	char direcc2[200];
	   	int i=0;
	   	for(i=0;i<200;i++){ direcc2[i] ='\0'; }
	   	strcpy(direcc, path);

	    for(i=0;i<200;i++)
		{
		    if(direcc[i]=='/')
			{
				direcc2[i]=direcc[i];
			  	char *aux= (char*)malloc(200);
			  	strcpy(aux,"mkdir ");
			  	strcat(aux,direcc2);
			  	system(aux);
			  	free(aux);
		    }
			else
			{
				direcc2[i]=direcc[i];
			  	if(direcc[i]=='\0'){ break; }
			}
		}
		
		for(i=0;i<200;i++) { if(direcc2[i]=='\n'){  direcc2[i]='\0'; } }
	  	mbr structDisco;
	  	structDisco.fecha = time(0);
	  	int as = aleatorio();
	  	structDisco.signature = as;
	   	i=0;
	   	for(i=0;i<4;i++)
		{
		   	structDisco.part[i].size =0;
		   	structDisco.part[i].auxiliar =0;
		   	structDisco.part[i].start =0;
		   	structDisco.part[i].fit = '0';
		   	structDisco.part[i].status = '0';
		   	structDisco.part[i].type = '0';
			int j=0;
			for(j=0;j<20;j++)
			{
				structDisco.part[i].exten[j].status='0';
				structDisco.part[i].exten[j].fit='0';
				structDisco.part[i].exten[j].next=0;
				structDisco.part[i].exten[j].size=0;
				structDisco.part[i].exten[j].auxiliar=0;
				structDisco.part[i].exten[j].start=0;
			}
	   	}
		
		char buffer[1024];
		i=0;
		for(i=0;i<1024;i++){ buffer[i]='0'; }
		FILE *disco;
	   	disco = fopen(path,"wb+");
	   	if(disco==NULL) { printf("ERROR: Al crear archivo.\n"); return 0; }

	   	if(unidad==1) { structDisco.size = tam*1024*1024; tam= tam*1024; }//MegaBytes
		else if(unidad==2){ structDisco.size = tam*1024; }//KiloBytes

	   	i=0;
	   	for(i=0;i<tam;i++){ fwrite(&buffer,1024,1,disco); }

	  	fseek(disco,0,SEEK_SET);
	  	fwrite(&structDisco,sizeof(mbr),1,disco);
		fclose(disco);
	  	printf("-> Se creo el disco correctamente.\n");

		if(raid==0)
		{
			raid=1;
			char d[200];
			strcpy(d,path);
			char* ext=NULL;
			ext = &d;
			char* nam =NULL;
			nam= &d;
			char* auxName;
			char* extRaid;
			ext = strtok(nam,".");
			auxName=ext;

			char *e ="_ra1.disk";
			char *newpath= (char *) malloc(1 + strlen(auxName)+ strlen(e) );
			strcpy(newpath, auxName);
			strcat(newpath, e);

			crearArchivoBinario(size,unit,newpath);
		}
	 	return 1;
	}
	return 1;
}

void limpiarVariables() 
{
	size = NULL;
	unit = NULL;
	path = NULL;
	type = NULL;
	fit = NULL;
	dele = NULL;
	name = NULL;
	add = NULL;
	id = NULL;
	ruta = NULL;
	contadorM =0;
	boolK = 0;
	boolM = 0;
	boolH = 0;
	boolI = 0;
	nDirectorio = NULL;
	p = NULL;
	cont = NULL;
	ugo = NULL;
	boolR = 0;
	rf = 0;
	dest = NULL;
	iddest = NULL;
	file = NULL;
	allocation = NULL;
}

void mostrarMontadas() 
{
	int i;
	if (contadorM == 0) 
	{
		printf("-> No existe ningua particion montada.\n");
	}
	for (i = 0; i < 5; i++) 
	{
		printf("M%d= id=>%s  -path=>%s  -nombre=>%s \n", i, montar[i].vdID, montar[i].path, montar[i].name);
	}
}

int eliminarDisco()
{
 	FILE* archivo;
    archivo = fopen(path,"rb+");
    if(archivo== NULL){ printf("ERROR: No existe el disco.\n"); return 0; }
	else
	{
		char com[5];
        printf("-> ¿Desea continuar? [S/n]: \n");
        fgets(com,5,stdin);
        if(com[0]=='s' || com[0]=='S')
		{
			char* aux;
			aux = (char*)malloc(160);
			strcpy(aux,"rm ");
			strcat(aux, path);
			system(aux);
			printf("-> Disco eliminado con exito.\n");
        }
		else{ printf("-> No se elimino el disco.\n"); }
    }
    return 1;
}

void adminParticion()
{
	//Atributos opcionales
	if(unit==NULL){ unit="k"; }//kilobytes
	if(type==NULL){ type="p"; }//primaria
	if(fit==NULL) { fit="wf";  }//peor ajuste

	//Atributos obligatorios
	if(add==NULL && dele==NULL)
	{
		if(path==NULL || size ==NULL || name ==NULL){ printf("ERROR: Falta un atributo obligatorio.\n"); }
		else
		{
			int d =	crearParticion(path,name,size,unit,type,fit);
			if(d==0){ printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n"); }
		}
	}
	else if(dele==NULL)
	{
	    if(path==NULL || name ==NULL){ printf("ERROR: Falta un atributo obligatorio.\n"); }
		else
		{
	       	int d =agregarParticion(add,unit,path,name);
	       	if(d==0){ printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n"); }
	    }
	} 
	else if(add==NULL)
	{
	    if(path==NULL || name ==NULL){ printf("ERROR: Falta un atributo obligatorio.\n"); }
		else
		{
	      	int d =eliminarParticion(dele,path,name);
	      	if(d==0){ printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n"); }
	    }
	}
	else
	{
		if(path==NULL || name ==NULL){ printf("ERROR: Falta un atributo obligatorio.\n"); }
		else
		{ 
			int d =agregarParticion(add,unit,path,name);
	    	if(d==0){ printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n"); }
	    }
	}

	//Recover
	char pathAux[100];
	strcpy(pathAux, path);
	char *nombre = obtenerNombre(path);
	char *recovery = concatenar( "/home/chay/recovery", nombre);
	copiarFichero(pathAux, recovery);
	//Copy
	char pathAux2[100];
	strcpy(pathAux2, pathAux);
	char *ruta = generarPath(pathAux);
	copiarFichero(pathAux2, ruta);
}

int crearParticion(char* path, char* name,char* size,char* unit,char* type,char* fit)
{
	int tam= atoi(size);
	int libre=0;
	FILE* archivo;
    archivo = fopen(path,"rb+");
    if(archivo== NULL){ printf("ERROR: No existe el disco.\n"); return 0; }
  	
	mbr structDisco;
  	fseek(archivo,0,SEEK_SET);
  	fread(&structDisco,sizeof(mbr),1,archivo);
  	int tipo=0;
  	char ajuste[5];

	//VERIFICAR EL TIPO
  	if(strcasecmp(type,"P")==0 || strcasecmp(type,"p")==0){  tipo=1; }//primaria
  	else if(strcasecmp(type,"L")==0 || strcasecmp(type,"l")==0) { tipo=2; }//logica
	else if(strcasecmp(type,"E")==0 || strcasecmp(type,"e")==0) { tipo=3; } //extendida
	else{ printf("ERROR: Tipo de particion incorrecta.\n"); return 0; }

    //VERIFICAR LA UNIDAD
    int bytes=0;
    if(strcasecmp(unit,"b")==0||strcasecmp(unit,"B")==0){  bytes = tam; }
	else if(strcasecmp(unit,"k")==0||strcasecmp(unit,"K")==0) { bytes=tam*1024; }
	else if(strcasecmp(unit,"m")==0||strcasecmp(unit,"M")==0){ bytes = tam*1024*1024; }
	else{ printf("ERROR: La unidad no existe.\n"); return 0; }

	//VERIFICAR AJUSTE
  	if(strcasecmp(fit,"BF")==0 || strcasecmp(fit,"bf")==0 || strcasecmp(fit,"bF")==0 || strcasecmp(fit,"Bf")==0){ strcpy(ajuste,"BF"); }
	else if(strcasecmp(fit,"FF")==0 || strcasecmp(fit,"ff")==0 || strcasecmp(fit,"fF")==0 || strcasecmp(fit,"Ff")==0){ strcpy(ajuste,"FF"); }
	else if(strcasecmp(fit,"WF")==0 || strcasecmp(fit,"wf")==0 || strcasecmp(fit,"wF")==0 || strcasecmp(fit,"Wf")==0){ strcpy(ajuste,"WF"); }
	else{ printf("ERROR: No existe el ajuste indicado.\n"); return 0; }
   	
	//VERIFICAR NOMBRE REPETIDO   
	int i=0;
   	for(i=0;i<4;i++) { if(strcasecmp(name,structDisco.part[i].name)==0){ printf("ERROR: Ya existe el nombre.\n"); return 0; } }


  	if(tipo==1)//primaria
	{ 
      	for(i=0;i<4;i++)
		{
			if(strcasecmp(name,structDisco.part[i].name)==0){ printf("ERROR: Ya existe el nombre.\n"); return 0; }
      	}
  	}
	else if(tipo==3) //extendida
	{
		for(i=0;i<4;i++)
		{
			if(structDisco.part[i].type == 'E' || structDisco.part[i].type == 'e' || strcasecmp(name,structDisco.part[i].name)==0)
			{
				printf("ERROR: Ya existe una particion extendida.\n");
              	return 0;
          	}
  		}
  	}
	else
	{
      	for(i=0;i<4;i++)
		{
          	if(structDisco.part[i].type == 'E' || structDisco.part[i].type == 'e' )
			{
				int j=0;
              	for(j=0; j<20; j++)
				{
                  	if(strcasecmp(name,structDisco.part[i].exten[j].name)==0){ printf("ERROR: Ya existe el nombre.\n"); return 0; }
              	}
				break;
         	}
      	}
    	if(i==4){ printf("ERROR: No existe una particion extendida.\n"); return 0; }
  	}
  
  	//VERIFICAR EL TAMANIO DE LA PARTICION Y LA CANTIDAD DE PARTICIONES
  	int particion=0;
  	int contParticion=0;
  	for(i=0;i<4;i++)
	{
        if(structDisco.part[i].status=='1')
		{
    	  	particion = particion + structDisco.part[i].size;
          	contParticion++;
      	}
  	}
  	if(contParticion==4 && tipo!=2)
	{
    	printf("ERROR: Ya existen 4 particiones.\n");
    	return 0;
  	}

	//VERIFICAR TAMANIO DE PARTICION
  	libre = structDisco.size-particion;
  	int espacio=0;

	if(tipo==1 || tipo==3) // Si la particion es primaria o extendida
	{ 
       	if(libre < bytes){ printf("ERROR: No hay tamaño disponible.\n"); return 0; }

		//ASINGAR TIPO, AJUSTE, TAMANIO
		for(i=0;i<4;i++)
		{
			if(structDisco.part[i].status == '0')
			{
				if(structDisco.part[i].size ==0 || bytes<structDisco.part[i].size)
				{
					if(ajuste[0]=='FF') { structDisco.part[i].fit = 'FF'; }
					else if(ajuste[0]=='BF'){ structDisco.part[i].fit = 'BF'; }
					else{ structDisco.part[i].fit = 'WF'; }
					strcpy(structDisco.part[i].name,name);
					structDisco.part[i].size = bytes;
					structDisco.part[i].auxiliar = bytes;
					if(i==0){ structDisco.part[i].start = sizeof(mbr)+1; espacio =1; }
					else{ structDisco.part[i].start = structDisco.part[i-1].start+structDisco.part[i-1].size; espacio =1; }
					structDisco.part[i].status ='1';

					if(strcasecmp(type,"E")==0||strcasecmp(type,"e")==0){ structDisco.part[i].type ='e'; }
					else{ structDisco.part[i].type ='p'; }
					espacio =1;
					break;
				}
			}
		}
   	}
	else //Si la particion es logica
	{ 
        for(i=0;i<4;i++)
		{
           if(structDisco.part[i].type == 'E' || structDisco.part[i].type == 'e' ) //Si existe una extendida antes
		   { 
			   	int k=0;
                int espa=0; //suma de todas las particiones extendidas
                for(k=0;k<20;k++){ espa= espa + structDisco.part[i].exten[k].size; }
				//printf("\nespa: %d\n",espa);
				//printf("\nsize del part: %d\n",structDisco.part[i].auxiliar);
               	espa= structDisco.part[i].auxiliar-espa;
				//printf("\nnuevo espa: %d\n",espa); 
				//printf("\nbytes: %d\n",bytes); 
			   	if(bytes>espa){ printf("ERROR: No hay tamaño disponible.\n"); return 0; }

              	int j=0;
               	for(j=0;j<20;j++)
			   	{
					if(structDisco.part[i].exten[j].status == '0')
					{
			   			if(structDisco.part[i].exten[j].size ==0 || bytes<structDisco.part[i].exten[j].size)
						{
							if(ajuste[0]=='FF'){ structDisco.part[i].exten[j].fit = 'FF'; }//Primer ajuste
							else if(ajuste[0]=='BF'){ structDisco.part[i].exten[j].fit = 'BF'; } //Mejor Ajuste
							else{ structDisco.part[i].exten[j].fit = 'WF'; } //Peor ajuste
				   			
							strcpy(structDisco.part[i].exten[j].name,name);
				   			structDisco.part[i].exten[j].size = bytes;
				   			structDisco.part[i].exten[j].auxiliar = bytes;

				   			if(j==0)
							{ 
					   			structDisco.part[i].exten[j].start = structDisco.part[i].start+1;
					   			structDisco.part[i].exten[j].next = -1;
					   			espacio =1;
				   			}
							else
							{
					   			structDisco.part[i].exten[j].start = structDisco.part[i].exten[j-1].start+structDisco.part[i].exten[j-1].size;
					   			structDisco.part[i].exten[j-1].next= structDisco.part[i].exten[j-1].start+structDisco.part[i].exten[j-1].size;
					   			espacio =1;
				   			}

				   			structDisco.part[i].exten[j].status ='1';
				   			espacio =1;
				   			break;
			   			}
		   			}
              	}
           }
       	}
   	}

	if (espacio==0){ printf("ERROR: No existe espacio suficiente.\n"); return 0; }
	
	fseek(archivo,0,SEEK_SET);
	fwrite(&structDisco,sizeof(mbr),1,archivo);
	fclose(archivo);
	printf("-> Se creo la particion:  %s  ,correctamente.\n",name);

	if(raid==0)
	{
		raid=1;
		char d[200];
		strcpy(d,path);
		char* ext=NULL;
		ext = &d;
		char* nam =NULL;
		nam= &d;
		char* auxName;
		char* extRaid;
		ext = strtok(nam,".");
		auxName=ext;

		char *e ="_ra1.disk";
		char *newpath= (char *) malloc(1 + strlen(auxName)+ strlen(e) );
		strcpy(newpath, auxName);
		strcat(newpath, e);

		crearParticion(newpath,name,size,unit,type,fit);
	}
	return 1;
}

int agregarParticion(char* add,char* unit,char* path,char* name)
{
	int tam= atoi(add);
	int libre=0;
	int par=0;

	//VERIFICA SI EL DISCO EXISTE
	FILE* archivo;
	archivo = fopen(path,"rb+");
	if(archivo== NULL){ printf("ERROR: No existe el disco.\n"); return 0; }
	mbr structDisco;
	fseek(archivo,0,SEEK_SET);
	fread(&structDisco,sizeof(mbr),1,archivo);

	//VERIFICA LA UNIDAD DEL DISCO
	int bytes=0;
	if(strcasecmp(unit,"k")==0||strcasecmp(unit,"K")==0){ bytes = tam*1024; }
	else if(strcasecmp(unit,"m")==0||strcasecmp(unit,"M")==0){ bytes = tam*1024*1024; }
	else if(strcasecmp(unit,"b")==0||strcasecmp(unit,"B")==0) { bytes=tam; }
	else{ printf("ERROR: Unidad incorrecta.\n"); return 0; }
	
	//VERIFICA SI EL NOMBRE EXISTE
	int i=0;
	int a=0;
	int j=0;
	for(i=0;i<4;i++)
	{
		if(strcasecmp(name, structDisco.part[i].name)==0){ break; }
	    for(j=0; j<20; j++)
		{
			if(strcasecmp(name, structDisco.part[i].exten[j].name)==0){ a=1; break; }
	    }
	    if(a>0){ break; }
	}
   	if(i==4 && a==0){ printf("ERROR: El nombre indicado no existe.\n"); return 0; }

	//VERIFICAR SI EL ESPACIO ES SUFICIENTE
   	if(a>0)
	{
    	if(bytes>0)
		{ 
			if(j<20) //j depende de donde encontro el nombre
			{
				printf("j = %d\n",j);
			 	if(structDisco.part[i].exten[j+1].start!=0) //Si no es la primer particion
				{
					int sig = structDisco.part[i].exten[j].start + structDisco.part[i].exten[j].auxiliar ;
				   	int ant = structDisco.part[i].exten[j+1].start;
					int resta= ant-sig;
					if(resta<bytes) {  printf("ERROR: No hay espacio.\n"); return 0; }
				   	structDisco.part[i].exten[j].auxiliar = structDisco.part[i].exten[j].auxiliar + bytes;

				   	if(structDisco.part[i].exten[j].auxiliar >  structDisco.part[i].exten[j].size)
					{
						structDisco.part[i].exten[j].size = structDisco.part[i].exten[j].size + (structDisco.part[i].exten[j].auxiliar - structDisco.part[i].exten[j].size);
				   	}

			   	}
				else //Si es la primer particion
				{
					int j=0;
				   	int sum=0;
					for(j=0; j<20; j++){ sum = sum +structDisco.part[i].exten[j].size; }
					int resta= structDisco.part[i].auxiliar-sum;
					if(resta<bytes){ printf("ERROR: No hay espacio.\n"); return 0; }
					structDisco.part[i].exten[j].auxiliar = structDisco.part[i].exten[j].auxiliar+bytes;
					if(structDisco.part[i].exten[j].auxiliar> structDisco.part[i].exten[j].size)
					{
						structDisco.part[i].exten[j].size= structDisco.part[i].exten[j].size+(structDisco.part[i].exten[j].auxiliar- structDisco.part[i].exten[j].size);
					}
			  	}
		 	}
			else //Si es la primera particion
			{ 
			 	int j=0;
			 	int sum=0;
		   		for(j=0; j<20; j++){ sum = sum + structDisco.part[i].exten[j].size; }
		   		int resta = structDisco.part[i].auxiliar-sum;
		   		if(resta<bytes){ printf("ERROR: No hay espacio.\n"); return 0; }
		   		structDisco.part[i].exten[j].auxiliar = structDisco.part[i].exten[j].auxiliar + bytes;
		   		
				if(structDisco.part[i].exten[j].auxiliar > structDisco.part[i].exten[j].size)
				{
					structDisco.part[i].exten[j].size = structDisco.part[i].exten[j].size+(structDisco.part[i].exten[j].auxiliar- structDisco.part[i].exten[j].size);
		   		}

		 	}
    	}
		else //Si los bytes son 0
		{
       		if(j<20)
			{
				if(structDisco.part[i].exten[j+1].start!=0) //Si no es la primer particion
				{
					int resta= structDisco.part[i].exten[j].auxiliar + bytes;
					if(resta>0){ structDisco.part[i].exten[j].auxiliar=resta; }
					else{ printf("ERROR: No hay espacio para borrar.\n"); return 0; }
				}
				else //Si es la primer particion
				{
					int resta = bytes + structDisco.part[i].exten[j].auxiliar;
					if(resta>0)
					{
						structDisco.part[i].exten[j].auxiliar=resta;
						structDisco.part[i].exten[j].size=resta;
					}
					else{ printf("ERROR: No hay espacio.\n"); return 0; }
				}
       		}
			else
			{
           		int resta=bytes+ structDisco.part[i].exten[j].auxiliar;
           		if(resta>0)
				{
        	   		structDisco.part[i].exten[j].auxiliar=resta;
        	   		structDisco.part[i].exten[j].size=resta;
           		}
				else{ printf("ERROR: No hay espacio.\n"); return 0;
           	}
       	}
    }
    }
	else
	{
        if(bytes>0)
		{
			if(i<3)
			{
				if(structDisco.part[i+1].start!=0)
				{
					int sig = structDisco.part[i].auxiliar+structDisco.part[i].start;
					int ant = structDisco.part[i+1].start;
					int resta= ant-sig;
					if(resta<bytes){ printf("No hay espacio "); return 0; }
					
					structDisco.part[i].auxiliar=structDisco.part[i].auxiliar+bytes;
					if(structDisco.part[i].auxiliar> structDisco.part[i].size)
					{
						structDisco.part[i].size= structDisco.part[i].size+(structDisco.part[i].auxiliar- structDisco.part[i].size);
					}
            	}
				else
				{
                 	int i2=0;
                 	int sum=0;
               		for(i2=0; i2<4; i2++){ sum=sum +structDisco.part[i2].size; }
               		int resta= structDisco.size-sum;
               		if(resta<bytes){ printf("No hay espacio "); return 0; }
             		structDisco.part[i].auxiliar = structDisco.part[i].auxiliar+bytes;
               		if(structDisco.part[i].auxiliar> structDisco.part[i].size)
					{
                		structDisco.part[i].size= structDisco.part[i].size+(structDisco.part[i].auxiliar- structDisco.part[i].size);
               		}
            	}
        	}
    	}

    }
   
   	fseek(archivo,0,SEEK_SET);
	fwrite(&structDisco,sizeof(mbr),1,archivo);
	fclose(archivo);
	printf("-> Se realizo la modificacion correctamente.\n");

	if(raid==0)
	{
		raid=1;
		char d[200];
		strcpy(d,path);
		char* ext=NULL;
		ext = &d;
		char* nam =NULL;
		nam= &d;
		char* auxName;
		char* extRaid;
		ext = strtok(nam,".");
		auxName=ext;

		char *e ="_ra1.disk";
		char *newpath= (char *) malloc(1 + strlen(auxName)+ strlen(e) );
		strcpy(newpath, auxName);
		strcat(newpath, e);

		agregarParticion(add,unit,newpath,name);
	}
	return 1;
}

int eliminarParticion(char* dele,char* path,char* name)
{
	//VERIFICA SI EXISTE EL DISCO
	FILE* archivo;
	archivo = fopen(path,"rb+");
	if(archivo== NULL){ printf("ERROR: No existe el disco.\n"); return 0; }
	mbr structDisco;
	fseek(archivo,0,SEEK_SET);
	fread(&structDisco,sizeof(mbr),1,archivo);

	int existe=0;
	int tipoDelete=0;
	int i=0;
	int j=0;

	//VERIFICA TIPO DE ELIMINAR
	if(strcasecmp(dele,"full")==0){ tipoDelete=1; }
	else if(strcasecmp(dele,"fast")==0){ tipoDelete=2; }
	else{ printf("ERROR: Tipo de Delete incorrecto.\n"); return 0; }

	//VERIFICA SI EL NOMBRE EXISTE
	for(i=0;i<4;i++)
	{ 
		if(strcasecmp(structDisco.part[i].name,name)==0){ break; }
	    for(j=0;j<20;j++)
		{
	        if(strcasecmp(structDisco.part[i].exten[j].name,name)==0){ existe=1; break; }
	    }
	    if(existe==1){ break; }
	}
	    
	if(i==4 && existe==0){ printf("ERROR: No existe el nombre.\n"); return 0; }


	//SI EXISTE...
	if(existe==1)
	{
		//si hay extendida
	    if(j<20) //i , j lugar donde encontro la particion
		{ 
	    	//LIMPIAR VARIABLES
	        if( structDisco.part[i].exten[j+1].status!='0')
			{
	        	structDisco.part[i].exten[j].status='0';
	        	strcpy(structDisco.part[i].exten[j].name," ");
	        }
			else
			{
	        	structDisco.part[i].exten[j].status='0';
	            structDisco.part[i].exten[j].start=0;
	            structDisco.part[i].exten[j].size=0;
	            structDisco.part[i].exten[j].auxiliar=0;
	            strcpy(structDisco.part[i].exten[j].name," ");
	        }
	    }
		else //Si no hay extendida
		{ 
	        structDisco.part[i].exten[j].status='0';
	        structDisco.part[i].exten[j].start=0;
	        structDisco.part[i].exten[j].size=0;
	        structDisco.part[i].exten[j].auxiliar=0;
	        strcpy(structDisco.part[i].exten[j].name," ");
	    }
	}
	else // Si no existe
	{
	    if(i<3)
		{
	        if( structDisco.part[i+1].status!='0')
			{
	            if(structDisco.part[i].type=='e' ||structDisco.part[i].type=='E')
				{
	                int i1=0;
	                for(i1=0;i1<8;i1++)
					{
	                    structDisco.part[i].exten[i1].status='0';
	                    structDisco.part[i].exten[i1].start=0;
	                    structDisco.part[i].exten[i1].size=0;
	                    structDisco.part[i].exten[i1].auxiliar=0;
	                    strcpy(structDisco.part[i].exten[i1].name," ");
	                }
	            }
	            structDisco.part[i].status='0';
	            structDisco.part[i].type='0';
	            strcpy(structDisco.part[i].name," ");
	        }
			else
			{
	            if(structDisco.part[i].type=='e' ||structDisco.part[i].type=='E')
				{
	                int i1=0;
	                for(i1=0;i1<8;i1++)
					{
	                    structDisco.part[i].exten[i1].status='0';
	                    structDisco.part[i].exten[i1].start=0;
	                    structDisco.part[i].exten[i1].size=0;
	                    structDisco.part[i].exten[i1].auxiliar=0;
	                    strcpy(structDisco.part[i].exten[i1].name," ");
	                }
	            }
	            structDisco.part[i].status='0';
	            structDisco.part[i].start=0;
	            structDisco.part[i].size=0;
	            structDisco.part[i].auxiliar=0;
	            structDisco.part[i].type='0';
	            strcpy(structDisco.part[i].name," ");
	        }
	    }
		else
		{
	        if(structDisco.part[i].type=='e' ||structDisco.part[i].type=='E')
			{
	            int i1=0;
	            for(i1=0;i1<8;i1++)
				{
	                structDisco.part[i].exten[i1].status='0';
	                structDisco.part[i].exten[i1].start=0;
	                structDisco.part[i].exten[i1].size=0;
	                structDisco.part[i].exten[i1].auxiliar=0;
	                strcpy(structDisco.part[i].exten[i1].name," ");
	            }
	        }
	        structDisco.part[i].status='0';
	        structDisco.part[i].start=0;
	        structDisco.part[i].size=0;
	        structDisco.part[i].auxiliar=0;
	        structDisco.part[i].type='0';
	        strcpy(structDisco.part[i].name," ");
	    }
	}

	fseek(archivo,0,SEEK_SET);
	fwrite(&structDisco,sizeof(mbr),1,archivo);
	fclose(archivo);
	printf("-> Se elimino correctamente.\n");

	if(raid==0)
	{
		raid=1;
		char d[200];
		strcpy(d,path);
		char* ext=NULL;
		ext = &d;
		char* nam =NULL;
		nam= &d;
		char* auxName;
		char* extRaid;
		ext = strtok(nam,".");
		auxName=ext;

		char *e ="_ra1.disk";
		char *newpath= (char *) malloc(1 + strlen(auxName)+ strlen(e) );
		strcpy(newpath, auxName);
		strcat(newpath, e);

		eliminarParticion(dele,newpath,name);
	}
	return 1;
}

void montarP()
{
	if(path==NULL || name ==NULL){ printf("ERROR: Falta un atributo obligatorio.\n"); }
	else
	{
		int d =	montarParticion(path,name);
		if(d==0){ printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n"); }
	}
}

int montarParticion(char* path, char* name)
{
    FILE* archivo;
    archivo = fopen(path,"rb+");
    if(archivo== NULL){
         printf("ERROR: No existe el disco\n");
        return 0;
    }
    mbr structDisco;
    fseek(archivo,0,SEEK_SET);
    fread(&structDisco,sizeof(mbr),1,archivo);

	//VERIFICA SI EL NOMBRE DE LA PARTICION EXISTE
    int boolExten=0;
    int i=0;
    int j=0;
    for(i=0;i<4;i++)
	{
        if(strcasecmp(structDisco.part[i].name, name)==0){ break; }
        for(j=0;j<20;j++) {  if(strcasecmp(structDisco.part[i].exten[j].name,name)==0){ boolExten=1; break; } }
		if(boolExten==1){ break; }
    }
    if(i==4 && boolExten==0){ printf("ERROR: No existe el nombre de la particion.\n"); fclose(archivo); return 0; }
 
 	//VERIFICAR SI EL PATH Y LA PARTICION YA ESTA REGISTRADO
    int pop=0;
    for(pop=0;pop<31;pop++)
	{
		if(strcasecmp(montar[pop].path, path)==0 && strcasecmp(montar[pop].name, name)==0 )
		{
           	if(montar[pop].estado==1){ printf("-> La particion ya esta montada:: %s\n",montar[pop].vdID); }
           	fclose(archivo);
           	return 0;
        }
    }
    int a=0, c=0, d=0;
    int v=0, boolExistePath=0;

    for(a=0; a<31;a++)
	{
       	if(strcasecmp(montar[a].path,path)==0)
		{
    	   c++;
           boolExistePath=1;
           v = montar[a].var ;
        }
    }

    if(boolExistePath==1)
	{
		for(a=0; a<31;a++){ if(montar[a].uso==0){ break; } }
	
		int cont = 0;
		for(pop=0;pop<31;pop++)
		{
			if(path!=NULL) { if(strcasecmp(montar[pop].path, path)==0){ cont++; } }
		}

		montar[a].estado=1;
		montar[a].uso='1';
		strcpy(montar[a].path,path);
		strcpy(montar[a].name,name);
		int p ;
		p = montar[a].part;
		p = p + 1;
		montar[a].part++;
		char *letra = letraDisco(v);
		char n = p+'0';
		char *num = numeroMontar(cont);
		char *str = (char *) malloc(1 + strlen(letra)+ strlen(num) );
		strcpy(str, letra);
		strcat(str, num);
		montar[a].vdID =str;
		montar[a].var = v;
		printf("-> Se monto la particion con id::%s correctamente.\n",str);

    }
	else
	{
    	for(a=0; a<31;a++){ if(montar[a].uso==0){ break; } }
    	varLetra++;
    	v = varLetra;
		montar[a].estado=1;
		montar[a].uso='1';
		strcpy(montar[a].path, path);
		montar[a].var = v;
		montar[a].part = 1;
		strcpy(montar[a].name,name);

		char *letra = letraDisco(varLetra);
		char *num = "1";
		char *str = (char *) malloc(1 + strlen(letra)+ strlen(num) );
		strcpy(str, letra);
		strcat(str, num);
		montar[a].vdID =str;
		printf("-> Se monto la particion con id::%s correctamente.\n",str);
    }

    fclose(archivo);
	contadorM += 1;
	return 1;
}

char *numeroMontar(int num)
{
	char *numero;
	switch(num)
	{
		case 0:
			numero ="1";
			break;
		case 1:
			numero = "2";
			break;
		case 2:
			numero= "3";
			break;
		case 3:
			numero= "4";
			break;
		case 4:
			numero= "5";
			break;
		case 5:
			numero= "6";
			break;
		case 6:
			numero= "7";
			break;
		case 7:
			numero= "8";
			break;
		case 8:
			numero= "9";
			break;
		case 9:
			numero= "10";
			break;
		case 10:
			numero= "11";
			break;
		case 11:
			numero= "12";
			break;
		case 12:
			numero= "13";
			break;
	}
	return numero;
}

char *letraDisco(int varLetra)
{
	char *letra;
	switch(varLetra){
		case 0:
			letra = "vd";
			break;
		case 1:
			letra = "vda";
			break;
		case 2:
			letra = "vdb";
			break;
		case 3:
			letra = "vdc";
			break;
		case 4:
			letra = "vdd";
			break;
		case 5:
			letra = "vde";
			break;
		case 6:
			letra = "vdf";
			break;
		case 7:
			letra = "vdg";
			break;
		case 8:
			letra = "vdh";
			break;
		case 9:
			letra = "vdi";
			break;
		case 10:
			letra = "vdj";
			break;
		case 11:
			letra = "vdk";
			break;
		case 12:
			letra = "vdl";
			break;
	}
	return letra;
}

void desmontar()
{
	if(id==NULL) { printf("ERROR: Falta un atributo obligatorio.\n"); }
	else
	{
		int d =	desmontarParticion(id);
		if(d==0){ printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n"); }
	}
	mostrarMontadas();
	contadorM -= 1;
}

int desmontarParticion(char* id)
{
	printf("ID=%s\n",id);
	int i=0;
	for(i=0;i<31; i++)
	{
		if(montar[i].vdID!=NULL)
		{
			if(strcasecmp(montar[i].vdID,id)==0)
			{
				printf("igual\n");
				if(montar[i].estado==1)
				{
					montar[i].estado=0;
					montar[i].vdID =NULL;
					printf("-> Se ha desmontado la particion correctamente.\n");
					return 1;
				}
			}
		}
	}
	printf("ERROR: El ID no existe.\n");
	return 0;
}

void generarReporte()
{
	if(path==NULL || name ==NULL|| id == NULL) { printf("ERROR: Falta un atributo obligatorio.\n"); }
	else
	{
		name = tolower(name);
		if(strcasecmp(name, "mbr")==0 ) // ya
		{
			int d =	reporteMBR(id, name, path);
			if(d==0){ printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n"); }
		}
		else if(strcasecmp(name, "disk")==0) // ya
		{
			int d =	reporteDISK(id, name, path);
			if(d==0){ printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n"); }
		}
		else if (strcasecmp(name, "inode") == 0)  // ya
		{
			int d = reporteINODO(id, name, path);
			if (d == 0) 
			{
				printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
			}
		} 
		else if (strcasecmp(name, "block") == 0)  // ya
		{
			int d = reporteBLOQUE(id, "*", path);
			if (d == 0) 
			{
				printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
			}
		}
		else if (strcasecmp(name, "journaling") == 0) // ya
		{
			int d = reporteJOURNALING(name, path, id);
			if (d == 0) 
			{
				printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
			}
		}
		else if (strcasecmp(name, "bm_inode") == 0) // ya
		{
			int d = reporteBITMAP_INODO(name, path, id);
			if (d == 0) 
			{
				printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
			}
		} 
		else if (strcasecmp(name, "bm_block") == 0) // ya
		{
			int d = reporteBITMAP_BLOQUE(name, path, id);
			if (d == 0) 
			{
				printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
			}
		} 
		else if (strcasecmp(name, "tree") == 0) // ya
		{
			int d = reporteArbol(id, "*", path);
			if (d == 0) 
			{
				printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
			}
		} 
		else if (strcasecmp(name, "sb") == 0) // ya
		{
			int d = reporteSB(name, path, id);
			if (d == 0) 
			{
				printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
			}
		} 
		else if (strcasecmp(name, "file") == 0) // ya
		{
			if (ruta != NULL) 
			{
				int d = reporteFILE(name, path, id, ruta);
				if (d == 0) 
				{
					printf( "Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
				}
			} 
			else 
			{
				printf("Falta el atributo ruta.\n");
			}
		}
		else
		{
			printf("name = %s\n",name);
			printf("x\n");
		}
	}
}

int aleatorio()
{
	srand(time(NULL));
	int test = rand() % 1000;
	return test;
}

void script(){

	if(path==NULL){ printf("ERROR: Falta un atributo obligatorio.\n"); }
	else
	{
		int d =	ejecutarScript(path);
		if(d==0){ printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n"); }
	}
}

int ejecutarScript(char *path)
{
	char *auxpth2;
    auxpth2 = strtok(path,"\n");
	FILE* archivo;
	char caracter[1000];
	archivo = fopen(auxpth2,"r+");
	if(archivo== NULL){ printf("ERROR: No existe el archivo.\n"); return 0; }
	else
	{
	    int j=0;
	    for( j=0;j<1000;j++){ caracter[j] = '\0'; }
	    int i=0;
	    while (feof(archivo) == 0)  // *feof* hasta que se acabe el archivo
		{
	        caracter[i] = fgetc(archivo); // *fgetc* lee lineapor linea
	        //printf(&caracter[i]);
	        //caracter[i]= tolower(caracter[i]);
	        if(caracter[i]=='\n')
			{
	            char com[1000];
	            char com2[1000];
	            caracter[i]='\0';
	            strcpy(com,caracter);
	            strcpy(com2, com);
	            char *comando = NULL;
	            comando = strtok( com, " ");
	            char *atr;
	            if(comando!=NULL)
				{
	            	atr = com2;
	            	verificarComando(comando, atr);
	            }
				for( j=0;j<1000;j++){ caracter[j] = '\0'; }
	            printf("\n");
	            i=0;
	        }
			else if(caracter[i]=='\\') { caracter[i]=' '; }
			else{ i++; }
	    }
	}

}

// ================================= SEGUNDA FASE ======================

char *concatenar(char* var1, char* var2)
{
	char *cadena = (char *) malloc(1 + strlen(var1) + strlen(var2));
	strcpy(cadena, var1);
	strcat(cadena, var2);
	return cadena;
}

char *generarPath(char *direccion) 
{
	char aux[200];
	strcpy(aux, direccion);

	char* datos[10];
	int cont = 0;

	char* inst = NULL;
	inst = strtok(direccion, "/");
	datos[cont] = inst;

	while (inst != NULL) 
	{
		cont++;
		inst = strtok(NULL, "/");
		datos[cont] = inst;
	}

	char *d = "/";
	char *rutaNueva = (char *) malloc(1 + strlen(aux) + strlen("copy"));
	rutaNueva = "/";

	int i = 0;
	for (i = 0; i < cont - 1; i++) {
		char *c1 = concatenar(datos[i], d);
		rutaNueva = concatenar(rutaNueva, c1);
	}
	rutaNueva = concatenar(rutaNueva, "Copy");
	rutaNueva = concatenar(rutaNueva, datos[cont - 1]);

	strcpy(direccion, aux);
	return rutaNueva;

}

char *obtenerNombre(char *ruta) 
{
	char* datos[10];
	int cont = 0;

	char* inst = NULL;
	inst = strtok(ruta, "/");
	datos[cont] = inst;

	while (inst != NULL) 
	{
		cont++;
		inst = strtok(NULL, "/");
		datos[cont] = inst;
	}
	return datos[cont - 1];
}

char *obtenerRuta(char *id) 
{
	char* ruta;
	int i = 0;
	for (i = 0; i < 31; i++) {
		if (montar[i].vdID != NULL) 
		{
			if (strcasecmp(montar[i].vdID, id) == 0) 
			{
				if (montar[i].estado == 1) 
				{
					ruta = montar[i].path;
					return ruta;
				}
			}
		}
	}
	return NULL;
}

void formatear() 
{
	if (type == NULL) { type = "full"; } //kilobytes
	if (unit == NULL) { unit = "k";  } //kilobytes

	if (id == NULL) { printf("ERROR: Falta un atributo obligatorio.\n"); } 
	else 
	{
		fflush(NULL);
		int d = formatearDisco(id, type, add, unit, fs);
		if (d == 0) 
		{
			printf( "Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
			return;
		} 
		else 
		{
			printf("-> Se ha dado formato a la particion correctamente.\n");
			crearArchivoParticion(id, "/home/users.txt", "si", "10", "/home/chay/vacio.txt");
			printf("-> Se ha creado el archivo USERS correctamente.\n");

		}

		//Recover :: No se actualiza
		path = obtenerRuta(id);
		char pathAux[100];
		strcpy(pathAux, path);
		char *nombre = obtenerNombre(path);
		char *recovery = concatenar( "/home/chay/recovery", nombre);
		strcpy(path, pathAux);
		//Copy
		char pathAux2[100];
		strcpy(pathAux2, path);
		ruta = generarPath(path);
		copiarFichero(pathAux2, ruta);

		strcpy(path, pathAux2);
		strcpy(ruta, pathAux2);

		/////////////////////////////////////////////////////////

	}
}

int formatearDisco(char* id, char* type, char* add, char* unit, char* fs) 
{

	if (strcasecmp(type, "full") != 0 || strcasecmp(type, "fast") != 0) { printf("ERROR: Tipo no existe.\n"); return 0;} 

	char* ruta;
	char* nombre;
	int i = 0;
	for (i = 0; i < 31; i++) 
	{
		if (montar[i].vdID != NULL) 
		{
			if (strcasecmp(montar[i].vdID, id) == 0)
			{
				if (montar[i].estado == 1)
				{
					ruta = montar[i].path; //%%%
					nombre = montar[i].name;
					break;
				}
			}
		}
	}
	if (i == 31) { printf("ERROR: El ID no existe.\n"); return 0; }

	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	if (archivo == NULL) 
	{
		ruta = generarPath(ruta);
		archivo = fopen(ruta, "rb+");
		if (archivo == NULL) 
		{
			printf("ERROR: No existe el disco.\n");
			return 0;
		}
	}
	mbr structDisco;
	fseek(archivo, 0, SEEK_SET);
	fread(&structDisco, sizeof(mbr), 1, archivo);

	//VERIFICAR SI EL NOMBRE COINCIDE CON LA PARTICION
	int j = 0;
	int existeLogica = 0;
	for (i = 0; i < 4; i++) //Primaria/extendida
	{ 
		if (strcasecmp(structDisco.part[i].name, nombre) == 0) { break; }
		for (j = 0; j < 20; j++) //journalica
		{ 
			if (strcasecmp(structDisco.part[i].exten[j].name, nombre) == 0) 
			{
				existeLogica = 1;
				break;
			}
		}
		if (existeLogica == 1) 
		{
			break;
		}

	}

	if (i == 4 && existeLogica == 0) 
	{
		printf("ERROR: No existe el nombre indicado.\n");
		return 0;
	}

	superbloque sb;
	int pos = 0;
	int n = 0;
	int tam = 0;
	if (existeLogica == 1) //Si la particion es journalica
	{ 
		n = structDisco.part[i].exten[j].auxiliar - sizeof(superbloque);
		int m = (1 + sizeof(journal) + 3 + sizeof(inodo) + 3 * sizeof(datos));
		int nn = n / m;

		tam = floor(nn);
		pos = tam;
		sb.s.arbolVirtualCount = tam;
		sb.s.detalleDirectorioCount = tam * 2;
		sb.inodosCount = tam;
		sb.bloquesCount = tam * 3;
		sb.freeBloquesCount = tam - 1;
		sb.freeInodosCount = (tam * 3) - 10;
		sb.FechaMontado = time(0);
		sb.FechaDesmontado = time(0);
		sb.mountCount = 0;
		sb.magic = 201700345;  //0xEF53
		sb.inodoSize = sizeof(inodo);
		sb.bloqueSize = sizeof(datos);
		sb.jourfirst = sb.apuntadorBloques + sizeof(datos);
		sb.s.apuntadorBitArbolDirectorio = structDisco.part[i].exten[j].start
				+ sizeof(superbloque);
		sb.s.apuntador = structDisco.part[i].exten[j].start
				+ sizeof(superbloque) + tam;
		sb.s.apuntadorBitDetalleDirectorio = structDisco.part[i].exten[j].start
				+ sizeof(superbloque) + tam + sizeof(apunt);
		sb.s.apuntadorDetalleDirectorio = sb.s.apuntadorBitDetalleDirectorio
				+ tam;
		sb.apuntadorBitTablaInodo = sb.s.apuntadorDetalleDirectorio
				+ sizeof(detalle);
		sb.apuntadorTablaInodo = sb.apuntadorBitTablaInodo + tam;
		sb.s.apuntadorBitmapInodo = sb.apuntadorTablaInodo + sizeof(inodo);
		sb.firstFreeBitTablaInodo = 1;
		sb.firstFreeBitBloque = 1;

		//USUARIOS-GRUPOS
		sb.s.contadorU = 0;
		strcpy(sb.user[sb.s.contadorU].usuario.id, "1");
		strcpy(sb.user[sb.s.contadorU].usuario.tipo, "G");
		strcpy(sb.user[sb.s.contadorU].usuario.grupo, "root");
		sb.s.contadorU++;
		strcpy(sb.user[sb.s.contadorU].usuario.id, "1");
		strcpy(sb.user[sb.s.contadorU].usuario.tipo, "U");
		strcpy(sb.user[sb.s.contadorU].usuario.grupo, "root");
		strcpy(sb.user[sb.s.contadorU].usuario.usuario, "root");
		strcpy(sb.user[sb.s.contadorU].usuario.clave, "123");
		sb.s.contadorU++;
		sb.s.contadorP = 0;

		fseek(archivo, structDisco.part[i].exten[j].start, SEEK_SET);
		fwrite(&sb, sizeof(superbloque), 1, archivo);

	} 
	else 
	{
		n = structDisco.part[i].auxiliar - sizeof(superbloque);
		int m = (1 + sizeof(journal) + 3 + sizeof(inodo) + 3 * sizeof(datos));
		int nn = n / m;
		tam = floor(nn);
		printf("tam1== %d\n", tam);

		pos = tam;
		sb.s.arbolVirtualCount = tam;
		sb.s.detalleDirectorioCount = tam * 2;
		sb.inodosCount = tam;
		sb.bloquesCount = tam * 3;
		sb.freeBloquesCount = tam - 1;
		sb.freeInodosCount = (tam * 3) - 10;
		sb.FechaDesmontado = time(0);
		sb.FechaMontado = time(0);
		sb.mountCount = 0;
		sb.magic = 201700345;  //0xEF53
		sb.inodoSize = sizeof(inodo);
		sb.bloqueSize = sizeof(datos);
		sb.jourfirst = sb.apuntadorBloques + sizeof(datos);
		sb.s.apuntadorBitArbolDirectorio = structDisco.part[i].start
				+ sizeof(superbloque);
		sb.s.apuntador = structDisco.part[i].start + sizeof(superbloque) + tam;
		sb.s.apuntadorBitDetalleDirectorio = structDisco.part[i].start
				+ sizeof(superbloque) + tam + sizeof(apunt);
		sb.s.apuntadorDetalleDirectorio = sb.s.apuntadorBitDetalleDirectorio
				+ tam;
		sb.apuntadorBitTablaInodo = sb.s.apuntadorDetalleDirectorio
				+ sizeof(detalle);
		sb.apuntadorTablaInodo = sb.apuntadorBitTablaInodo + tam;
		sb.s.apuntadorBitmapInodo = sb.apuntadorTablaInodo + sizeof(inodo);
		sb.firstFreeBitTablaInodo = 1;
		sb.firstFreeBitBloque = 1;

		//USUARIOS-GRUPOS
		sb.s.contadorU = 0;
		strcpy(sb.user[sb.s.contadorU].usuario.id, "1");
		strcpy(sb.user[sb.s.contadorU].usuario.tipo, "G");
		strcpy(sb.user[sb.s.contadorU].usuario.grupo, "root");
		sb.s.contadorU++;
		strcpy(sb.user[sb.s.contadorU].usuario.id, "1");
		strcpy(sb.user[sb.s.contadorU].usuario.tipo, "U");
		strcpy(sb.user[sb.s.contadorU].usuario.grupo, "root");
		strcpy(sb.user[sb.s.contadorU].usuario.usuario, "root");
		strcpy(sb.user[sb.s.contadorU].usuario.clave, "123");
		sb.s.contadorU++;
		sb.s.contadorP = 0;

		fseek(archivo, structDisco.part[i].start, SEEK_SET);
		fwrite(&sb, sizeof(superbloque), 1, archivo);

	}
	sb.s.contadorJ = 0;

	char bitm = '0';
	char bitm1 = '1';
	fseek(archivo, sb.s.apuntadorBitArbolDirectorio, SEEK_SET);
	fwrite(&bitm1, 1, 1, archivo);
	int io = 0;
	for (io = 0; io < (pos) - 1; io++) { fwrite(&bitm, 1, 1, archivo); }

	fseek(archivo, sb.s.apuntadorBitDetalleDirectorio, SEEK_SET);
	for (io = 0; io < (pos); io++) { fwrite(&bitm, 1, 1, archivo); }

	fseek(archivo, sb.apuntadorBitTablaInodo, SEEK_SET);
	for (io = 0; io < (pos); io++) { fwrite(&bitm, 1, 1, archivo); }

	fseek(archivo, sb.s.apuntadorBitmapInodo, SEEK_SET);
	for (io = 0; io < (pos); io++) { fwrite(&bitm, 1, 1, archivo); }

	apunt insertar;
	insertar.apuntador = -1;
	insertar.directorio = 0;
	strcpy(insertar.pointer, "/");
	int ip = 0;
	for (ip = 0; ip < 4; ip++) { insertar.subDirectorios[ip] = 0; }
	fseek(archivo, sb.s.apuntador, SEEK_SET);
	fwrite(&insertar, sizeof(apunt), 1, archivo);

	//CAMBIOS EN EL JOURNALING
	journal bitacora;

	bitacora.operacion = 1;
	bitacora.tipo = 0;
	bitacora.fecha = time(0);
	strcpy(bitacora.nombre, "Formatear");
	strcpy(bitacora.contenido, "Formatear");
	fseek(archivo, sb.jourfirst, SEEK_SET); //**
	fwrite(&bitacora, sizeof(journal), 1, archivo);

	fclose(archivo);
	strcpy(structDisco.part[i].name, montar[i].name);
	return 1;
}

void crearArchivo() 
{
	if (id == NULL || path == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		int d = crearArchivoParticion(id, path, p, size, cont);
		if (d == 0) 
		{
			printf( "Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
		}
	}

}

int crearArchivoParticion(char* id, char* path, char* p, char* size, char* cont) 
{
	char* ruta;
	char* nombre;
	int i = 0;
	for (i = 0; i < 31; i++) 
	{
		if (montar[i].vdID != NULL) 
		{
			if (strcasecmp(montar[i].vdID, id) == 0) 
			{
				if (montar[i].estado == 1) 
				{
					if (montar[i].loss == 1) 
					{
						printf("ERROR: Existe un fallo en el disco.\n");
						return 0;
					}
					ruta = montar[i].path; //%%%
					nombre = montar[i].name;
					break;
				}
			}
		}
	}
	if (i == 31) 
	{
		printf("ERROR: El ID no existe.\n");
		return 0;
	}
	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	if (archivo == NULL) 
	{
		ruta = generarPath(ruta);
		archivo = fopen(ruta, "rb+");
		if (archivo == NULL) 
		{
			printf("ERROR: No existe el disco.\n");
			return 0;
		}
	}
	mbr structDisco;
	fseek(archivo, 0, SEEK_SET);
	fread(&structDisco, sizeof(mbr), 1, archivo);

	//VERIFICAR SI EL NOMBRE COINCIDE CON LA PARTICION
	int j = 0;
	int existeLogica = 0;
	for (i = 0; i < 4; i++) //Primaria/extendida
	{ 
		if (strcasecmp(structDisco.part[i].name, nombre) == 0 || strcmp(nombre, structDisco.part[i].name) == 0) 
		{
			break;
		}
		for (j = 0; j < 20; j++) //logica
		{ 
			if (strcasecmp(structDisco.part[i].exten[j].name, nombre) == 0) 
			{
				existeLogica = 1;
				break;
			}
		}
		if (existeLogica == 1)
		 {
			break;
		}
	}
	if (i == 4 && existeLogica == 0) 
	{
		printf("ERROR: No existe el nombre indicado (CAP).\n");
		return 0;
	}
	superbloque sb;
	char ajuste;

	int posicion;
	if (existeLogica == 1) 
	{
		posicion = structDisco.part[i].exten[j].start;
		ajuste = structDisco.part[i].exten[j].fit;
		fseek(archivo, structDisco.part[i].exten[j].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	} 
	else 
	{
		posicion = structDisco.part[i].start;
		ajuste = structDisco.part[i].fit;
		fseek(archivo, structDisco.part[i].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	}

	FILE* archivoCont;
	archivoCont = fopen(cont, "r");
	int existeCont = 1;

	if (cont == NULL) { existeCont = 0; } 
	else if (archivoCont == NULL) 
	{
		printf("ERROR: No existe ruta de cont.\n");
		return 0;
	}

	int tamanio;
	if (existeCont > 0)
	{
		fseek(archivoCont, 0, SEEK_END);
		tamanio = ftell(archivoCont);
	} 
	else 
	{
		tamanio = atoi(size);
	}

	if (tamanio < 0) 
	{
		printf("ERROR: El tamanio es incorrecto.\n");
		return 0;
	}

	if (sb.magic == 201700345) 
	{
		fseek(archivo, sb.s.apuntador, SEEK_SET);
		apunt ap;
		fread(&ap, sizeof(ap), 1, archivo);

		char crear[100] = "";
		char verificar[100] = "";
		char verificar2[100] = "";
		strcpy(crear, path);

		int b, a = 0;
		for (a = 0; a < 100; a++) 
		{
			if (crear[a] != '\0') 
			{
				verificar[a] = crear[a];
				verificar2[a] = crear[a];
			} 
			else 
			{
				for (b = a; b >= 0; b--) 
				{
					if (verificar[b] != '/') 
					{
						verificar[b] = '\0';
						verificar2[b] = '\0';
					} 
					else
					 {
						verificar[b] = '\0';
						verificar2[b] = '\0';
						break;
					}
				}
				break;
			}
		}
		char* rutaC;
		strcpy(verificar, verificar2);
		if (verificar[0] == '\0') 
		{
			p = "si";
			rutaC = strtok(crear, "/");
		} 
		else 
		{
			rutaC = strtok(verificar, "/");
		}
		fclose(archivo);
		int informacion = 0;
		int datos = 0;

		correcto = 1; 
		informacion = crearCarpeta(ruta, sb, ap, rutaC, p, ajuste, posicion, sb.s.apuntador);
		
		if (correcto > 0) 
		{
			rutaC = strtok(verificar2, "/");
			datos = buscarArchivo(ruta, sb, ap, rutaC, ajuste, posicion, sb.s.apuntador);

			if (datos > 0) 
			{
				rutaC = strtok(crear, "/");	//verificar si ruta es igual a NULO
				while ((strstr(rutaC, ".") == 0x0 || strstr(rutaC, ".") == "" || strstr(rutaC, ".") == NULL) && rutaC != NULL) 
				{
					rutaC = strtok(NULL, "/");
					if (rutaC == NULL || rutaC == 0x0) { break; }
				}
				char leer[tamanio];
				if (archivoCont != NULL) 
				{
					fseek(archivoCont, 0, SEEK_SET);
					fread(&leer, tamanio, 1, archivoCont);
				} 
				else 
				{
					printf("Sin contenido.\n");
					int r, c = 0;
					for (r = 0; r < 64; r++) 
					{
						leer[r] = (char) (c + 48);
						c++;
						if (c > 9) { c = 0; }
					}
				}
				char contenido[100];
				if (rutaC != NULL || rutaC != 0x0) 
				{
					agregarContenido(datos, sb, ruta, rutaC, ajuste, leer, tamanio, structDisco);
					if (size == 0x0 || size == NULL) 
					{
						strcat(contenido, "-cont:");
						strcat(contenido, cont);
					} 
					else 
					{
						strcat(contenido, "-size:");
						strcat(contenido, size);
					}
					printf("-> Se ha creado el archivo correctamente.\n");

				}
			} 
			else { printf("ERROR: No se ha podido crear el archivo.\n"); }
		}
	} 
	else 
	{
		printf("ERROR: No se ha formateado la particion.\n");
	}
	return 1;
}

int agregarContenido(int posicion, superbloque super, char* ruta, char* name, char ajuste, char* contenido, int size, mbr structDisco) 
{
	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	detalle carp;
	fseek(archivo, posicion, SEEK_SET);
	fread(&carp, sizeof(detalle), 1, archivo);
	fflush(NULL);
	int i = 0, k = 0;
	int j = 0;
	for (i = 0; i < 5; i++) //Maneja 5 inodos
	{ 
		if (carp.content[i].inod > 1) 
		{
			if (strcasecmp(carp.content[i].name, name) == 0) 
			{
				if (boolEditar == 0) 
				{
					printf("ERROR: El nombre ya existe.\n");
					return 0;
				}
				break;
			}
			k++;

		} 
		else { j = i; }
	}
	if (k > 4) 
	{
		if (carp.detalle > 0) 
		{
			fclose(archivo);
			return agregarContenido(carp.detalle, super, ruta, name, ajuste, contenido, size, structDisco);
		} 
		else 
		{
			detalle carp;
			carp.detalle = 0;
			int a = 0;
			for (a = 0; a < 5; a++) { carp.content[a].inod = -1; }
			int posicion = 0;
			fclose(archivo);

			if (ajuste == 'w' || ajuste == 'W') 
			{
				posicion = peorAjuste(super.s.arbolVirtualCount, ruta, super.s.apuntadorBitDetalleDirectorio, 1);
			} 
			else if (ajuste == 'f' || ajuste == 'F') 
			{
				posicion = primerAjuste(super.s.arbolVirtualCount, ruta, super.s.apuntadorBitDetalleDirectorio, 1);
			} 
			else 
			{
				posicion = mejorAjuste(super.s.arbolVirtualCount, ruta, super.s.apuntadorBitDetalleDirectorio, 1);
			}

			FILE* disco;
			disco = fopen(ruta, "rb+");

			carp.detalle = super.s.apuntadorDetalleDirectorio + 100 * posicion * sizeof(detalle);
			fseek(disco, posicion, SEEK_SET);
			fwrite(&carp, sizeof(detalle), 1, disco);

			fseek(disco, super.s.apuntadorDetalleDirectorio + 100 * posicion * sizeof(detalle), SEEK_SET);
			fwrite(&carp, sizeof(detalle), 1, disco);
			fclose(disco);
			setbuf(stdin, NULL);
			printf("agregar2\n");
			return agregarContenido(carp.detalle, super, ruta, name, ajuste, contenido, size, structDisco);
		}
	} 
	else //Se crean los inodos
	{ 
		printf("Creando inodos\n");
		strcpy(carp.content[j].name, name);
		int pos = 0;
		fclose(archivo);
		if (ajuste == 'w' || ajuste == 'W') 
		{
			pos = peorAjuste(super.s.arbolVirtualCount, ruta, super.apuntadorBitTablaInodo, 1);
		} 
		else if (ajuste == 'f' || ajuste == 'F') 
		{
			pos = primerAjuste(super.s.arbolVirtualCount, ruta, super.apuntadorBitTablaInodo, 1);
		} 
		else 
		{
			pos = mejorAjuste(super.s.arbolVirtualCount, ruta, super.apuntadorBitTablaInodo, 1);
		}
		FILE* disco;
		disco = fopen(ruta, "rb+");
		carp.content[j].inod = super.apuntadorTablaInodo + 100 * pos * sizeof(inodo);
		fseek(disco, posicion, SEEK_SET);
		fwrite(&carp, sizeof(detalle), 1, disco);
		fclose(disco);
		inodo ino;
		ino.noAsignados = pos;
		ino.size = size;
		ino.indirecto = 0;
		int aux = size / 25;

		if (size % 25) { aux++; }
		datos arch;
		char conten[20000] = "";
		strcpy(conten, contenido);
		int l, m = 0;
		int pos2 = 0;

		if (aux < 5) 
		{
			ino.noInodo = size / 25;
			if (size % 25 > 0) 
			{
				ino.noInodo++;
			}
			ino.indirecto = 0;
			for (l = 0; l < ino.noInodo; l++) 
			{
				if (ajuste == 'w' || ajuste == 'W') 
				{
					pos2 = peorAjuste(super.s.arbolVirtualCount, ruta, super.s.apuntadorBitmapInodo, 1);
				} 
				else if (ajuste == 'f' || ajuste == 'F') 
				{
					pos2 = primerAjuste(super.s.arbolVirtualCount, ruta, super.s.apuntadorBitmapInodo, 1);
				} 
				else 
				{
					pos2 = mejorAjuste(super.s.arbolVirtualCount, ruta, super.s.apuntadorBitmapInodo, 1);
				}
				FILE* disco;
				disco = fopen(ruta, "rb+");
				for (m = 0; m < 25; m++) 
				{
					arch.data[m] = conten[l * 25 + m];
				}
				ino.bloques[l] = super.apuntadorBloques + 100 * pos2 * sizeof(datos);
				fseek(disco, super.apuntadorBloques + 100 * pos2 * sizeof(datos), SEEK_SET);
				fwrite(&arch, sizeof(datos), 1, disco);
				fclose(disco);
			}

		} 
		else 
		{
			ino.noInodo = 4;
			for (l = 0; l < 4; l++) 
			{
				if (ajuste == 'w' || ajuste == 'W') 
				{
					pos2 = peorAjuste(super.s.arbolVirtualCount, ruta, super.s.apuntadorBitmapInodo, 1);
				} 
				else if (ajuste == 'f' || ajuste == 'F') 
				{
					pos2 = primerAjuste(super.s.arbolVirtualCount, ruta, super.s.apuntadorBitmapInodo, 1);
				} 
				else 
				{
					pos2 = mejorAjuste(super.s.arbolVirtualCount, ruta, super.s.apuntadorBitmapInodo, 1);
				}
				FILE* disco;
				disco = fopen(ruta, "rb+");
				for (m = 0; m < 25; m++) 
				{
					arch.data[m] = conten[l * 25 + m];
				}
				ino.bloques[l] = super.apuntadorBloques + 100 * pos2 * sizeof(datos);
				fseek(disco, super.apuntadorBloques + 100 * pos2 * sizeof(datos), SEEK_SET);
				fwrite(&arch, sizeof(datos), 1, disco);
				fclose(disco);
			}
			int pos3 = 0;
			if (ajuste == 'w' || ajuste == 'W') 
			{
				pos3 = peorAjuste(super.s.arbolVirtualCount, ruta, super.apuntadorBitTablaInodo, 1);
			} 
			else if (ajuste == 'f' || ajuste == 'F') 
			{
				pos3 = primerAjuste(super.s.arbolVirtualCount, ruta, super.apuntadorBitTablaInodo, 1);
			} 
			else 
			{
				pos3 = mejorAjuste(super.s.arbolVirtualCount, ruta, super.apuntadorBitTablaInodo, 1);
			}
			inodo ino2;
			ino2.noAsignados = pos3;
			ino2.size = size;
			ino2.indirecto = 0;
			ino2.noInodo = (size - 100) / 25;
			if ((size - 100) % 25 > 0) 
			{
				ino2.noInodo++;
			}
			if (ino2.noInodo > 4) 
			{
				ino2.noInodo = 4;
			}
			int pos4 = 0;
			for (l = 0; l < ino2.noInodo; l++) 
			{
				if (ajuste == 'w' || ajuste == 'W') 
				{
					pos4 = peorAjuste(super.s.arbolVirtualCount, ruta,
							super.s.apuntadorBitmapInodo, 1);
				} 
				else if (ajuste == 'f' || ajuste == 'F') 
				{
					pos4 = primerAjuste(super.s.arbolVirtualCount, ruta,
							super.s.apuntadorBitmapInodo, 1);
				} 
				else 
				{
					pos4 = mejorAjuste(super.s.arbolVirtualCount, ruta,
							super.s.apuntadorBitmapInodo, 1);
				}
				FILE* disco;
				disco = fopen(ruta, "rb+");
				int m = 0;
				for (m = 0; m < 25; m++) 
				{
					arch.data[m] = conten[l * 25 + m + 100];
				}
				ino2.bloques[l] = super.apuntadorBloques
						+ 100 * pos4 * sizeof(datos);
				fseek(disco,
						super.apuntadorBloques + 100 * pos4 * sizeof(datos),
						SEEK_SET);
				fwrite(&arch, sizeof(datos), 1, disco);
				fclose(disco);
			}

			disco = fopen(ruta, "rb+");
			ino.indirecto = super.s.apuntadorDetalleDirectorio + 100 * pos3 * sizeof(inodo);
			fseek(disco, super.s.apuntadorDetalleDirectorio + 100 * pos3 * sizeof(inodo), SEEK_SET);
			fwrite(&ino2, sizeof(inodo), 1, disco);
			fclose(disco);
		}
		disco = fopen(ruta, "rb+");
		fseek(disco, super.apuntadorTablaInodo + 100 * pos * sizeof(inodo),
		SEEK_SET);
		fwrite(&ino, sizeof(inodo), 1, disco);
		fclose(disco);
		fflush(NULL);
		printf("-> Se agrego el contenido correctamente.\n");
		return 1;
	}
}

int agregarArchivo(int posicion, superbloque super, char* aux4, char* name, char ajuste, char* contenido, int size) 
{
	FILE* disco;
	disco = fopen(aux4, "rb+");
	detalle con;
	fseek(disco, posicion, SEEK_SET);
	fread(&con, sizeof(detalle), 1, disco);
	int i = 0;
	int k = 0;
	int w = 0;
	for (i = 0; i < 5; i++) 
	{

		if (con.content[i].inod > 1) 
		{
			if (strcasecmp(con.content[i].name, name) == 0) 
			{
				printf("Ya existe ese nombre");
				return 0;
				break;
			}
			k++;
		} 
		else 
		{
			w = i;
		}
	}
	if (k > 4) 
	{
		if (con.detalle > 0) 
		{
			fclose(disco);
			return agregarArchivo(con.detalle, super, aux4, name, ajuste, contenido, size);
		} 
		else 
		{
			detalle conx;
			conx.detalle = 0;
			int uy = 0;
			for (uy = 0; uy < 5; uy++) 
			{
				conx.content[uy].inod = -1;
			}
			int pos = 0;
			fclose(disco);
			if (ajuste == 'w') 
			{
				pos = peorAjuste(super.s.arbolVirtualCount, aux4, super.s.apuntadorBitDetalleDirectorio, 1);
			} 
			else if (ajuste == 'f') 
			{
				pos = primerAjuste(super.s.arbolVirtualCount, aux4, super.s.apuntadorBitDetalleDirectorio, 1);
			} 
			else 
			{
				pos = mejorAjuste(super.s.arbolVirtualCount, aux4, super.s.apuntadorBitDetalleDirectorio, 1);
			}
			FILE* disco;
			disco = fopen(aux4, "rb+");

			con.detalle = super.s.apuntadorDetalleDirectorio + 100 * pos * sizeof(detalle);
			fseek(disco, posicion, SEEK_SET);
			fwrite(&con, sizeof(detalle), 1, disco);

			fseek(disco, super.s.apuntadorDetalleDirectorio + 100 * pos * sizeof(detalle), SEEK_SET);
			fwrite(&conx, sizeof(detalle), 1, disco);
			fclose(disco);
			return agregarArchivo(con.detalle, super, aux4, name, ajuste, contenido, size);
		}
	} 
	else 
	{
		strcpy(con.content[w].name, name);

		int pos = 0;
		fclose(disco);
		if (ajuste == 'w') 
		{
			pos = peorAjuste(super.s.arbolVirtualCount, aux4, super.apuntadorBitTablaInodo, 1);
		} 
		else if (ajuste == 'f') 
		{
			pos = primerAjuste(super.s.arbolVirtualCount, aux4, super.apuntadorBitTablaInodo, 1);
		} 
		else 
		{
			pos = mejorAjuste(super.s.arbolVirtualCount, aux4, super.apuntadorBitTablaInodo, 1);
		}
		FILE* disco;
		disco = fopen(aux4, "rb+");

		con.content[w].inod = super.apuntadorTablaInodo + 100 * pos * sizeof(inodo);
		fseek(disco, posicion, SEEK_SET);
		fwrite(&con, sizeof(detalle), 1, disco);
		fclose(disco);
		inodo conx;
		conx.noAsignados = pos;
		conx.size = size;
		int axulii = size / 25;
		if (size % 25) { axulii++; }
		datos conq;
		char q[200];
		strcpy(q, contenido);
		int yu, qw = 0;
		int pos2 = 0;
		if (axulii < 5) 
		{
			conx.noInodo = size / 25;
			if (size % 25 > 0) 
			{
				conx.noInodo++;
			}
			conx.indirecto = 0;
			for (yu = 0; yu < conx.noInodo; yu++) 
			{
				if (ajuste == 'w') {
					pos2 = peorAjuste(super.s.arbolVirtualCount, aux4,
							super.s.apuntadorBitmapInodo, 1);
				} else if (ajuste == 'f') {
					pos2 = primerAjuste(super.s.arbolVirtualCount, aux4,
							super.s.apuntadorBitmapInodo, 1);
				} else {
					pos2 = mejorAjuste(super.s.arbolVirtualCount, aux4,
							super.s.apuntadorBitmapInodo, 1);
				}
				FILE* disco;
				disco = fopen(aux4, "rb+");
				for (qw = 0; qw < 25; qw++) {
					conq.data[qw] = q[yu * 25 + qw];
				}
				conx.bloques[yu] = super.apuntadorBloques + 100 * pos2 * sizeof(datos);
				fseek(disco, super.apuntadorBloques + 100 * pos2 * sizeof(datos), SEEK_SET);
				fwrite(&conq, sizeof(datos), 1, disco);
				fclose(disco);
			}
		} 
		else 
		{
			conx.noInodo = 4;
			for (yu = 0; yu < 4; yu++) 
			{
				if (ajuste == 'w') {
					pos2 = peorAjuste(super.s.arbolVirtualCount, aux4,
							super.s.apuntadorBitmapInodo, 1);
				} else if (ajuste == 'f') {
					pos2 = primerAjuste(super.s.arbolVirtualCount, aux4,
							super.s.apuntadorBitmapInodo, 1);
				} else {
					pos2 = mejorAjuste(super.s.arbolVirtualCount, aux4,
							super.s.apuntadorBitmapInodo, 1);
				}
				FILE* disco;
				disco = fopen(aux4, "rb+");
				for (qw = 0; qw < 25; qw++) {
					conq.data[qw] = q[yu * 25 + qw];
				}
				conx.bloques[yu] = super.apuntadorBloques
						+ 100 * pos2 * sizeof(datos);
				fseek(disco,
						super.apuntadorBloques + 100 * pos2 * sizeof(datos),
						SEEK_SET);
				fwrite(&conq, sizeof(datos), 1, disco);
				fclose(disco);
			}
			int pos3 = 0;
			if (ajuste == 'w') {
				pos3 = peorAjuste(super.s.arbolVirtualCount, aux4,
						super.apuntadorBitTablaInodo, 1);
			} else if (ajuste == 'f') {
				pos3 = primerAjuste(super.s.arbolVirtualCount, aux4,
						super.apuntadorBitTablaInodo, 1);
			} else {
				pos3 = mejorAjuste(super.s.arbolVirtualCount, aux4,
						super.apuntadorBitTablaInodo, 1);
			}
			inodo conxw;
			conxw.noAsignados = pos3;
			conxw.size = size;
			conxw.indirecto = 0;
			conxw.noInodo = (size - 100) / 25;
			if ((size - 100) % 25 > 0) {
				conxw.noInodo++;
			}
			if (conxw.noInodo > 4) {
				conxw.noInodo = 4;
			}
			int pos4 = 0;
			for (yu = 0; yu < conxw.noInodo; yu++) 
			{
				if (ajuste == 'w') {
					pos4 = peorAjuste(super.s.arbolVirtualCount, aux4,
							super.s.apuntadorBitmapInodo, 1);
				} else if (ajuste == 'f') {
					pos4 = primerAjuste(super.s.arbolVirtualCount, aux4,
							super.s.apuntadorBitmapInodo, 1);
				} else {
					pos4 = mejorAjuste(super.s.arbolVirtualCount, aux4,
							super.s.apuntadorBitmapInodo, 1);
				}
				FILE* disco;
				disco = fopen(aux4, "rb+");
				int qw = 0;
				for (qw = 0; qw < 25; qw++) {
					conq.data[qw] = q[yu * 25 + qw + 100];
				}
				conxw.bloques[yu] = super.apuntadorBloques
						+ 100 * pos4 * sizeof(datos);
				fseek(disco,
						super.apuntadorBloques + 100 * pos4 * sizeof(datos),
						SEEK_SET);
				fwrite(&conq, sizeof(datos), 1, disco);
				fclose(disco);
			}

			disco = fopen(aux4, "rb+");
			conx.indirecto = super.s.apuntadorDetalleDirectorio
					+ 100 * pos3 * sizeof(inodo);
			fseek(disco,
					super.s.apuntadorDetalleDirectorio
							+ 100 * pos3 * sizeof(inodo), SEEK_SET);
			fwrite(&conxw, sizeof(inodo), 1, disco);
			fclose(disco);
		}

		disco = fopen(aux4, "rb+");
		fseek(disco, super.apuntadorTablaInodo + 100 * pos * sizeof(inodo),
		SEEK_SET);
		fwrite(&conx, sizeof(inodo), 1, disco);
		fclose(disco);

		printf("-> Se creo el archivo correctamente.\n");
	}

}

int crearCarpeta(char* ruta, superbloque super, apunt apun, char* path, char* p, char ajuste, int inicio, int atras) 
{
	char* patito = path;

	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	apunt ap;
	if (atras > 800000000) { return 0; }
	fseek(archivo, atras, SEEK_SET);
	fread(&apun, sizeof(apunt), 1, archivo);
	int i = 0, x = 0, w = 0, qw = 0;

	for (i = 0; i < 4; i++) 
	{
		if (apun.subDirectorios[i] > 0) //Si ya existe la carpeta
		{	
			fseek(archivo, apun.subDirectorios[i], SEEK_SET);
			fread(&ap, sizeof(ap), 1, archivo);
			char point[16] = "";
			strcpy(point, ap.pointer);
			if (strcasecmp(point, path) == 0) {
				break;
			}
		} 
		else if (x == 0) 
		{
			x = 1;
			w = i;
			qw++;
		} 
		else 
		{
			qw++;
		}
	}
	
	if (i < 4) 
	{
		path = strtok(NULL, "/");
		//	printf("path=%s\n", path);
		if (path != NULL && path != 0x0) 
		{
			fclose(archivo);
			crearCarpeta(ruta, super, ap, path, p, ajuste, inicio,
					apun.subDirectorios[i]);
		} 
		else 
		{
			return 1;
		}
	} 
	else if (i > 3 && x > 0)
	{
		if (p != NULL) 
		{
			int pos = 0;
			fclose(archivo);
			if (ajuste == 'w') {
				pos = peorAjuste(super.s.arbolVirtualCount, ruta,
						super.s.apuntadorBitArbolDirectorio, 1);
			} else if (ajuste == 'f') {
				pos = primerAjuste(super.s.arbolVirtualCount, ruta,
						super.s.apuntadorBitArbolDirectorio, 1);
			} else {
				pos = mejorAjuste(super.s.arbolVirtualCount, ruta,
						super.s.apuntadorBitArbolDirectorio, 1);
			}
			FILE* archivo;
			archivo = fopen(ruta, "rb+");
			ap.apuntador = -1;
			ap.directorio = 0;
			strcpy(ap.pointer, "");
			strcpy(ap.pointer, path);
			int au = 0;
			for (au = 0; au < 4; au++) {
				ap.subDirectorios[au] = -1;
			}

			apun.subDirectorios[w] = super.s.apuntador + 100 * pos * sizeof(apunt);
			fseek(archivo, atras, SEEK_SET);
			fwrite(&apun, sizeof(apunt), 1, archivo);

			fseek(archivo, super.s.apuntador + 100 * pos * sizeof(apunt),
			SEEK_SET);
			fwrite(&ap, sizeof(apunt), 1, archivo);
			path = strtok(NULL, "/");
			fclose(archivo);
			if (path != NULL) 
			{
				crearCarpeta(ruta, super, apun, path, p, ajuste, inicio, apun.subDirectorios[w]);
			} 
			else 
			{
				printf("-> Se creo la carpeta correctamente. %s\n", patito);
				return 1;
			}
		} 
		else 
		{
			correcto = 0;
			printf("*ERROR: La ruta indicada no existe.\n");
			return 0;
		}
	} 
	else if (i > 3 && x < 1) 
	{
		if (apun.apuntador < 0) 
		{
			if (p != NULL) 
			{
				int pos = 0;
				fclose(archivo);
				if (ajuste == 'w') {
					pos = peorAjuste(super.s.arbolVirtualCount, ruta,
							super.s.apuntadorBitArbolDirectorio, 1);
				} else if (ajuste == 'f') {
					pos = primerAjuste(super.s.arbolVirtualCount, ruta,
							super.s.apuntadorBitArbolDirectorio, 1);
				} else {
					pos = mejorAjuste(super.s.arbolVirtualCount, ruta,
							super.s.apuntadorBitArbolDirectorio, 1);
				}
				FILE* disco;
				disco = fopen(ruta, "rb+");

				ap.apuntador = -1;
				ap.directorio = 0;
				//ap.fechaCreacion = time(0);
				strcpy(ap.pointer, apun.pointer);
				int aux = 0;
				for (aux = 0; aux < 6; aux++) {
					ap.subDirectorios[aux] = -1;
				}
				apun.apuntador = super.s.apuntador + 100 * pos * sizeof(apunt);

				fseek(disco, atras, SEEK_SET);
				fwrite(&apun, sizeof(apunt), 1, disco);

				fseek(disco, super.s.apuntador + 100 * pos * sizeof(apunt),
				SEEK_SET);
				fwrite(&ap, sizeof(apunt), 1, disco);

				if (path != NULL) 
				{
					fclose(disco); //XXX
					crearCarpeta(ruta, super, ap, path, p, ajuste, inicio, apun.apuntador);
				}
			} 
			else 
			{
				correcto = 0;
				printf("/ERROR: La ruta indicada no existe.\n");
				return 0;
			}
		} 
		else 
		{
			fclose(archivo);
			crearCarpeta(ruta, super, apun, path, p, ajuste, inicio, apun.apuntador);
		}
	} 
	else 
	{
		correcto = 0;
		printf("ERROR: No se ha podido crear la carpeta.\n");
		return 0;
	}

	return 1;

}

int buscarArchivo(char* ruta, superbloque super, apunt ap, char* path, char ajuste, int inicio, int atras) 
{
	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	apunt ap2;
	fseek(archivo, atras, SEEK_SET);
	fread(&ap, sizeof(apunt), 1, archivo);
	int i = 0, x = 0, qw = 0;

	for (i = 0; i < 6; i++) 
	{
		if (ap.subDirectorios[i] > 0) 
		{
			fseek(archivo, ap.subDirectorios[i], SEEK_SET);
			fread(&ap2, sizeof(apunt), 1, archivo);
			if (strcasecmp(ap2.pointer, path) == 0) {
				break;
			}
		} 
		else if (x == 0) 
		{
			x = 1;
			qw++;
		} else {
			qw++;
		}
	}

	if (i < 6) 
	{
		path = strtok(NULL, "/");
		if (path != NULL && path != 0x0) 
		{
			fclose(archivo);
			return buscarArchivo(ruta, super, ap2, path, ajuste, inicio, ap.subDirectorios[i]);
		} 
		else 
		{
			if (ap2.directorio > 0) 
			{
				fclose(archivo);
				return ap2.directorio;
			} 
			else 
			{
				detalle c;
				c.detalle = 0;
				int uy = 0;
				for (uy = 0; uy < 5; uy++) 
				{
					c.content[uy].inod = -1; //+
				}
				int pos = 0;
				fclose(archivo);
				if (ajuste == 'w') {
					pos = peorAjuste(super.s.arbolVirtualCount, ruta,
							super.s.apuntadorBitDetalleDirectorio, 1);
				} else if (ajuste == 'f') {
					pos = primerAjuste(super.s.arbolVirtualCount, ruta,
							super.s.apuntadorBitDetalleDirectorio, 1);
				} else {
					pos = peorAjuste(super.s.arbolVirtualCount, ruta,
							super.s.apuntadorBitDetalleDirectorio, 1);
				}
				FILE* archivo;
				archivo = fopen(ruta, "rb+");

				ap2.directorio = super.s.apuntadorDetalleDirectorio
						+ 100 * pos * sizeof(detalle);
				fseek(archivo, ap.subDirectorios[i], SEEK_SET);
				fwrite(&ap2, sizeof(apunt), 1, archivo);
				fclose(archivo);

				archivo = fopen(ruta, "rb+");
				fseek(archivo, super.s.apuntadorDetalleDirectorio + 100 * pos * sizeof(detalle), SEEK_SET);
				fwrite(&c, sizeof(detalle), 1, archivo);
				fclose(archivo);
				return ap2.directorio;
			}
		}
	} 
	else 
	{
		if (ap.apuntador < 1) 
		{
			printf("ERROR: No existe carpeta \n");
			return 0;
		} 
		else 
		{
			fclose(archivo);
			return buscarArchivo(ruta, super, ap, path, ajuste, inicio, ap.apuntador);
		}
	}

}

int primerAjuste(int bloque, char* ruta, int inicio, int arch) 
{
	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	int sig = 0;
	char leer;
	fseek(archivo, inicio, SEEK_SET);

	int i = 0;
	int posicion = 0;
	for (i = 0; i < bloque; i++) 
	{
		fread(&leer, 1, 1, archivo);
		if (leer == '0') {		//Si es vacio
			sig++;
		} else {
			sig = 0;
		}
		if (sig == arch) {
			posicion = (i - (sig - 1));
			break;
		}
	}
	fseek(archivo, inicio + posicion, SEEK_SET);
	leer = '1';
	fwrite(&leer, 1, 1, archivo);
	fclose(archivo);
	return posicion;
}

int mejorAjuste(int bloque, char* ruta, int inicio, int arch) 
{
	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	int posicion = 0;
	int sig = 0;
	int i = 0;
	int menor = bloque;
	char leer;
	fseek(archivo, inicio, SEEK_SET);
	for (i = 0; i < bloque; i++) 
	{
		fread(&leer, 1, 1, archivo);
		if (leer == '0') {
			sig++;
		} else {
			if (menor > sig && sig != 0) {
				menor = sig;
				if (menor >= arch || menor == arch) {
					posicion = i - menor;
				}
			} else if (menor == bloque) {
				posicion = i + 1;
			}
			sig = 0;
		}

	}
	fseek(archivo, inicio + posicion, SEEK_SET);
	leer = '1';
	fwrite(&leer, 1, 1, archivo);
	fclose(archivo);
	return posicion;

}

int peorAjuste(int bloque, char* ruta, int inicio, int arch) 
{
	if (bloque > 20000) 
	{
		printf("bloque = %d\n", bloque);
	}

	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	int posicion = 0;
	int sig = 0;
	int i = 0;
	int mayor = 0;
	int aux = 0;
	char leer;
	fseek(archivo, inicio, SEEK_SET);
	for (i = 0; i < bloque; i++) 
	{
		fread(&leer, 1, 1, archivo);
		if (leer == '0') 
		{
			sig++;
		} 
		else 
		{
			aux = i + 1;
			if (mayor < sig) 
			{
				mayor = sig;
				if (mayor >= arch || mayor == arch) {
					posicion = i - mayor;
				}
			} 
			else if (mayor == 0) {
				posicion = i + 1;
			}
			sig = 0;

		}

		if (sig >= arch) {
			if (aux == 0) {
				posicion = 0;
			} else {
				posicion = aux;
			}
		}

	}
	fseek(archivo, inicio + posicion, SEEK_SET);
	leer = '1';
	fwrite(&leer, 1, 1, archivo);
	fclose(archivo);
	return posicion;
}

void remover() 
{
	if (id == NULL || file == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		int d = removerArchivo(id, file, rf);
		if (d == 0) 
		{
			printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
		}
	}

}

int removerArchivo(char* id, char* path, int rf) 
{
	char* ruta;
	char* nombre;
	int i = 0;
	for (i = 0; i < 31; i++) 
	{
		if (montar[i].vdID != NULL) 
		{
			if (strcasecmp(montar[i].vdID, id) == 0) 
			{
				if (montar[i].estado == 1) 
				{
					if (montar[i].loss == 1) {
						printf("ERROR: Existe un fallo en el disco.\n");
						return 0;
					}
					ruta = montar[i].path; //%%%
					nombre = montar[i].name;
					break;
				}
			}
		}
	}
	if (i == 31) 
	{
		printf("ERROR: El ID no existe.\n");
		return 0;
	}

	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	if (archivo == NULL) 
	{
		ruta = generarPath(ruta);
		archivo = fopen(ruta, "rb+");
		if (archivo == NULL) 
		{
			printf("ERROR: No existe el disco.\n");
			return 0;
		}
	}
	mbr structDisco;
	fseek(archivo, 0, SEEK_SET);
	fread(&structDisco, sizeof(mbr), 1, archivo);

	//VERIFICAR SI EL NOMBRE COINCIDE CON LA PARTICION
	int j = 0;
	int existeLogica = 0;
	for (i = 0; i < 4; i++)  //Primaria/extendida
	{
		if (strcasecmp(structDisco.part[i].name, nombre) == 0) {
			break;
		}
		for (j = 0; j < 20; j++) //journalica
		{ 
			if (strcasecmp(structDisco.part[i].exten[j].name, nombre) == 0) {
				existeLogica = 1;
				break;
			}
		}
		if (existeLogica == 1) {
			break;
		}
	}
	if (i == 4 && existeLogica == 0) 
	{
		printf("ERROR: No existe el nombre indicado.\n");
		return 0;
	}
	superbloque sb = crearBloque();
	char ajuste;

	int posicion;
	if (existeLogica == 1) 
	{
		posicion = structDisco.part[i].exten[j].start;
		ajuste = structDisco.part[i].exten[j].fit;
		fseek(archivo, structDisco.part[i].exten[j].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	} 
	else 
	{
		posicion = structDisco.part[i].start;
		ajuste = structDisco.part[i].fit;
		fseek(archivo, structDisco.part[i].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	}

	if (sb.magic == 201700345) 
	{
		fseek(archivo, sb.s.apuntador, SEEK_SET);
		apunt ap;
		fread(&ap, sizeof(ap), 1, archivo);

		char crear[100];
		char verificar[100];
		char verificar2[100];
		strcpy(crear, path);

		int b, a = 0;
		for (a = 0; a < 100; a++) 
		{
			if (crear[a] != '\0') 
			{
				verificar[a] = crear[a];
				verificar2[a] = crear[a];
			} 
			else 
			{
				for (b = a; b >= 0; b--) 
				{
					if (verificar[b] != '/') 
					{
						verificar[b] = '\0';
						verificar2[b] = '\0';
					} 
					else 
					{
						verificar[b] = '\0';
						verificar2[b] = '\0';
						break;
					}
				}
				break;
			}
		}

		char* ruta1;
		char* ruta2;
		char auxPath[100];
		strcpy(auxPath, path);
		a = 0; //nuevas variables
		b = 0;
		for (a = 0; a < 100; a++)
		{
			if (auxPath[a] == '.') { b++; }
		}
		fclose(archivo);

		strcpy(verificar, verificar2);
		if (verificar[0] == '\0') 
		{
			ruta1 = strtok(crear, "/");
		} 
		else 
		{
			ruta1 = strtok(verificar, "/");
		}
		ruta2 = strtok(crear, ".");

		int datos = 0;

		if (b < 1) 
		{
			ruta1 = strtok(crear, "/");
			printf("Eliminar Carpeta.\n");
			eliminarCarpeta(ruta, sb, ruta1, sb.s.apuntador);
			journaling(ruta, posicion, sb, 3, path, "", id, 1);
		} 
		else 
		{
			ruta1 = strtok(verificar2, "/");
			datos = buscarArchivo(ruta, sb, ap, ruta1, ajuste, posicion, sb.s.apuntador);
			if (datos > 0) 
			{
				char pathAux[200] = "";
				strcpy(pathAux, path);
				ruta1 = strtok(path, "/");
				//retorna un puntero - strstr
				while ((strstr(ruta1, ".") == 0x0 || strstr(ruta1, ".") == "" || strstr(ruta1, ".") == NULL) && ruta1 != NULL && ruta1 != 0x0) 
				{
					ruta1 = strtok(NULL, "/");
					if (ruta1 == NULL) {
						break;
					}
				}
				strcpy(path, pathAux);
				if (ruta1 != NULL) 
				{
					printf("Eliminar Archivo.\n");
					eliminarArchivo(datos, sb, ruta, ruta1);
					journaling(ruta, posicion, sb, 3, path, "", id, 0);
				}
			} 
			else 
			{
				printf("ERROR: No existe la ruta indicada.\n");
			}
		}
	} else {
		printf("ERROR: La particion no ha sido formateada.\n");
	}

	return 1;
}

int eliminarCarpeta(char* ruta, superbloque super, char* path, int posicion) 
{
	FILE* disco;
	disco = fopen(ruta, "rb+");
	apunt ap2, ap;
	fseek(disco, posicion, SEEK_SET);
	fread(&ap, sizeof(apunt), 1, disco);

	int i = 0;
	for (i = 0; i < 4; i++) 
	{
		if (ap.subDirectorios[i] > 0) {
			fseek(disco, ap.subDirectorios[i], SEEK_SET);
			fread(&ap2, sizeof(ap2), 1, disco);
			if (strcasecmp(ap2.pointer, path) == 0) {
				break;
			}
		}
	}

	if (i < 4) 
	{
		path = strtok(NULL, "/");
		if (path != NULL && path != 0x0) 
		{
			fclose(disco);
			eliminarCarpeta(ruta, super, path, ap.subDirectorios[i]);
		} 
		else 
		{
			int c = ap.subDirectorios[i];
			ap.subDirectorios[i] = -1;
			fseek(disco, posicion, SEEK_SET);
			fwrite(&ap, sizeof(apunt), 1, disco);
			int pos = (c - super.s.apuntador) / (100 * sizeof(apunt));

			char ok = '0';
			printf("-> Se elimino la carpeta correctamente.\n");
			return eliminarCarpetaCompleta(ruta, super, c);
		}
	} 
	else 
	{
		if (ap.apuntador < 1) 
		{
			printf("ERROR: No existe la carpeta especificada.\n");
			return 0;
		} 
		else 
		{
			fclose(disco);
			return eliminarCarpeta(ruta, super, path, ap.apuntador);
		}

	}
	return 1;
}

int eliminarCarpetaCompleta(char*ruta, superbloque super, int posicion) 
{
	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	apunt ap2, ap;

	fseek(archivo, posicion, SEEK_SET);
	fread(&ap, sizeof(apunt), 1, archivo);

	int i = 0;

	for (i = 0; i < 6; i++) 
	{
		if (ap.subDirectorios[i] > 0) 
		{
			int c = ap.subDirectorios[i];
			ap.subDirectorios[i] = -1;
			fseek(archivo, posicion, SEEK_SET);
			fwrite(&ap, sizeof(apunt), 1, archivo);
			int pos = (c - super.s.apuntador) / (100 * sizeof(apunt));

			char ok = '0';
			fseek(archivo, super.s.apuntadorBitArbolDirectorio + pos, SEEK_SET);
			fwrite(&ok, 1, 1, archivo);
			fclose(archivo);
			eliminarCarpetaCompleta(ruta, super, c);
		}
	}

	if (ap.apuntador > 0) 
	{
		archivo = fopen(ruta, "rb+");
		int c = ap.apuntador;
		ap.apuntador = -1;
		fseek(archivo, posicion, SEEK_SET);
		fwrite(&ap, sizeof(apunt), 1, archivo);
		int pos = (c - super.s.apuntador) / (100 * sizeof(apunt));
		char ok = '0';
		fseek(archivo, super.s.apuntadorBitArbolDirectorio + pos, SEEK_SET);
		fwrite(&ok, 1, 1, archivo);
		fclose(archivo);
	}
	if (ap.directorio > 50) 
	{
		archivo = fopen(ruta, "rb+");
		int c = ap.directorio;
		ap.directorio = 0;
		fseek(archivo, posicion, SEEK_SET);
		fwrite(&ap, sizeof(apunt), 1, archivo);
		int pos = (c - super.s.apuntadorDetalleDirectorio) / (100 * sizeof(detalle));
		char yeah = '0';
		fseek(archivo, super.s.apuntadorBitDetalleDirectorio + pos, SEEK_SET);
		fwrite(&yeah, 1, 1, archivo);
		fclose(archivo);
	}
}

int eliminarArchivo(int posicion, superbloque super, char* ruta, char* name) 
{
	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	detalle carp;
	fseek(archivo, posicion, SEEK_SET);
	fread(&carp, sizeof(detalle), 1, archivo);
	int i = 0;
	int contenidoInodo;
	char* contenidoNombre;

	for (i = 0; i < 5; i++) 
	{
		contenidoInodo = carp.content[i].inod;
		contenidoNombre = carp.content[i].name;
		if (carp.content[i].inod > 1) {
			if (strcasecmp(carp.content[i].name, name) == 0) {
				break;
			}
		}
	}
	char v = '0';
	if (i < 5) 
	{
		carp.content[i].inod = -1;
		strcpy(carp.content[i].name, "");
		fseek(archivo, posicion, SEEK_SET);
		fwrite(&carp, sizeof(detalle), 1, archivo);

		inodo ino;
		fseek(archivo, contenidoInodo, SEEK_SET);
		fread(&ino, sizeof(ino), 1, archivo);

		int cont = ino.noAsignados;
		ino.noAsignados = -1;
		fseek(archivo, super.apuntadorBitTablaInodo + cont, SEEK_SET);
		fwrite(&v, 1, 1, archivo);
		fseek(archivo, contenidoInodo, SEEK_SET);
		fwrite(&ino, sizeof(ino), 1, archivo);

		int j = 0;
		for (j = 0; j < ino.noInodo; j++) 
		{
			int pos = (ino.bloques[j] - super.apuntadorBloques)
					/ (100 * sizeof(datos));
			fseek(archivo, super.s.apuntadorBitmapInodo + pos, SEEK_SET);
			fwrite(&v, 1, 1, archivo);
		}
		
		inodo inodo2;
		if (ino.indirecto > 0) 
		{
			fseek(archivo, ino.indirecto, SEEK_SET);
			fread(&inodo2, sizeof(inodo), 1, archivo);
			cont = inodo2.noAsignados;
			inodo2.noAsignados = -1;
			fseek(archivo, super.apuntadorBitTablaInodo + cont, SEEK_SET);
			fwrite(&v, 1, 1, archivo);

			for (j = 0; j < inodo2.noInodo; j++) 
			{
				int aux = (inodo2.bloques[j] - super.apuntadorBloques) / (100 * sizeof(datos));
				fseek(archivo, super.s.apuntadorBitmapInodo + aux, SEEK_SET);
				fwrite(&v, 1, 1, archivo);
			}
			fseek(archivo, ino.indirecto, SEEK_SET);
			fwrite(&inodo2, sizeof(inodo), 1, archivo);
		}
		fclose(archivo);
		printf("-> Se ha eliminado el archivo correctamente.\n");
		return 1;

	} 
	else 
	{
		if (carp.detalle > 0) 
		{
			fclose(archivo);
			return eliminarArchivo(carp.detalle, super, ruta, name);
		} 
		else 
		{
			fclose(archivo);
			printf("ERROR: No se ha encontrado el archivo.\n");
			return 0;
		}
	}
}

void encontrar() 
{
	if (id==NULL || path == NULL || name == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		int d = encontrarArchivo(id, path, name, "", "");
		if (d == 0) 
		{
			printf( "Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
		}
	}
}

int encontrarArchivo(char* id, char* path, char* name, char* perm, char* user) 
{
	char* ruta;
	char* nombre;
	int i = 0;
	for (i = 0; i < 31; i++) 
	{
		if (montar[i].vdID != NULL) 
		{
			if (strcasecmp(montar[i].vdID, id) == 0) 
			{
				if (montar[i].estado == 1) 
				{
					if (montar[i].loss == 1) 
					{
						printf("ERROR: Existe un fallo en el disco.\n");
						return 0;
					}
					ruta = montar[i].path; //%%%
					nombre = montar[i].name;
					break;
				}
			}
		}
	}
	if (i == 31) 
	{
		printf("ERROR: El ID no existe.\n");
		return 0;
	}

	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	if (archivo == NULL) 
	{
		ruta = generarPath(ruta);
		archivo = fopen(ruta, "rb+");
		if (archivo == NULL) 
		{
			printf("ERROR: No existe el disco.\n");
			return 0;
		}
	}

	mbr structDisco;
	fseek(archivo, 0, SEEK_SET);
	fread(&structDisco, sizeof(mbr), 1, archivo);
	i = 0;
	int j = 0;
	int esLogica = 0;
	for (i = 0; i < 4; i++) 
	{
		if (strcasecmp(structDisco.part[i].name, nombre) == 0) { break; }
		for (j = 0; j < 20; j++) 
		{
			if (strcasecmp(structDisco.part[i].exten[j].name, nombre) == 0) 
			{
				esLogica = 1;
				break;
			}
			if (esLogica == 1)
			{
				break;
			}
		}
	}
	
	if (i == 4 && esLogica == 0) 
	{
		printf("ERROR: No existe el nombre indicado.\n");
		return 0;
	}
	superbloque sb;
	char ajuste;
	int posicion;
	if (esLogica == 1) 
	{
		posicion = structDisco.part[i].exten[j].start;
		ajuste = structDisco.part[i].exten[j].fit;
		fseek(archivo, structDisco.part[i].exten[j].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	} 
	else 
	{
		posicion = structDisco.part[i].start;
		ajuste = structDisco.part[i].fit;
		fseek(archivo, structDisco.part[i].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	}

	if (sb.magic == 201700345) 
	{
		fseek(archivo, sb.s.apuntador, SEEK_SET);
		apunt ap;
		fread(&ap, sizeof(ap), 1, archivo);

		char crear[100];
		char verificar[100];
		char verificar2[100];
		strcpy(crear, path);
		int b, a = 0;
		for (a = 0; a < 100; a++) 
		{
			if (crear[a] != '\0') //Hasta que llegue al final
			{ 
				verificar[a] = crear[a];
				verificar2[a] = crear[a];
			} 
			else 
			{
				for (b = a; b >= 0; b--) 
				{
					if (verificar[b] != '/') 
					{
						verificar[b] = '\0';
						verificar2[b] = '\0';
					} 
					else 
					{
						verificar[b] = '\0';
						verificar2[b] = '\0';
						break;
					}
				}
				break;
			}
		}
		char* ruta1;
		strcpy(verificar, verificar2);
		if (verificar[0] == '\0') 
		{
			ruta1 = strtok(crear, "/");
		} 
		else 
		{
			ruta1 = strtok(verificar, "/");
		}
		fclose(archivo);

		char aux[10];
		char aux2[10];
		int k = 0;
		for (k = 0; k < 10; k++) 
		{
			aux[k] = '\0';
			aux2[k] = '\0';
		}
		strcpy(aux, name);
		k = 1;
		if (aux[0] == '"') 
		{
			while (aux[k] != '"') 
			{
				aux2[k - 1] = aux[k];
				k++;
			}
		} 
		else 
		{
			strcpy(aux2, aux);
		}
		if (strcasecmp(path, "/") == 0) 
		{
			buscarRaizCarpeta(ruta, sb, sb.s.apuntador, aux2, 0);
		} 
		else 
		{
			buscarCarpeta(ruta, ruta1, sb, sb.s.apuntador, aux2, 0);
		}

	} 
	else 
	{
		printf("ERROR: No se ha formateado la particion.\n");
		return 0;
	}

}

char* buscarCarpeta(char* ruta, char* path, superbloque super, int posicion, char* mensaje, int espacio) 
{
	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	apunt ap, ap2;
	fseek(archivo, posicion, SEEK_SET);
	fread(&ap, sizeof(apunt), 1, archivo);

	int i = 0;
	int j = 0;

	if (boolLs == 0) 
	{
		for (j = 0; j < espacio; j++) 
		{
			printf(" ");
		}
		printf("|_%s *\n", ap.pointer);
	} 

	char nombre[50];
	strcpy(nombre, ap.pointer);
	if (nombre[0] == '0' || nombre[15] == '0') 
	{
		return "";
	}

	for (i = 0; i < 6; i++) 
	{
		if (ap.subDirectorios[i] > 50)
		{
			fseek(archivo, ap.subDirectorios[i], SEEK_SET);
			fread(&ap2, sizeof(ap2), 1, archivo);
			if (strcasecmp(ap2.pointer, path) == 0) 
			{
				break;
			}
		}
	}
	if (i < 6) 
	{
		path = strtok(NULL, "/");
		if (path != NULL && path != 0x0) 
		{
			fclose(archivo);
			return buscarCarpeta(ruta, path, super, ap.subDirectorios[i], mensaje, espacio + 2);
		}
		else 
		{
			int a = ap.subDirectorios[i];
			fclose(archivo);
			return buscarRaizCarpeta(ruta, super, a, mensaje, espacio + 2);
		}
	} 
	else 
	{
		if (ap.apuntador < 1) 
		{
			printf("ERROR: No existe la carpeta indicada.\n");
			return "";
		} 
		else 
		{
			fclose(archivo);
			int p = ap.apuntador;
			return buscarCarpeta(ruta, path, super, p, mensaje, espacio);
		}
	}
	return "";
}

int buscarRaizCarpeta(char* ruta, superbloque super, int posicion, char* mensaje, int espacio) 
{
	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	apunt ap2, ap;

	fseek(archivo, posicion, SEEK_SET);
	fread(&ap, sizeof(apunt), 1, archivo);
	int i = 0;
	int j = 0;

	for (j = 0; j < espacio; j++)
	{
		printf(" ");
	}
	if (boolLs == 0) 
	{
		printf("|_%s . \n", ap.pointer);
	} 
	else
	{
		if (strcmp(arch, ap.pointer) == 0) 
		{
			bool = 1;
		}
		if (bool == 2)
		{
			strcpy(listaArchivo[contadorArchivo].nombre, ap.pointer);
			contadorArchivo++;
		}
	}
	fclose(archivo);
	for (i = 0; i < 4; i++) 
	{
		if (ap.subDirectorios[i] > 500) 
		{
			archivo = fopen(ruta, "rb+");
			fseek(archivo, ap.subDirectorios[i], SEEK_SET);
			fread(&ap2, sizeof(ap2), 1, archivo);
			fclose(archivo);
			bool++;
			buscarRaizCarpeta(ruta, super, ap.subDirectorios[i], mensaje,
					espacio + 2);
			bool--;
		}
	}
	if (ap.directorio > 100) 
	{
		bool++;
		buscarRaizArchivo(ruta, super, ap.directorio, mensaje, espacio + 2);
		bool--;
	}
	if (ap.apuntador > 100) 
	{
		bool++;
		buscarRaizCarpeta(ruta, super, ap.apuntador, mensaje, espacio);
		bool--;
	}
}

int buscarRaizArchivo(char* ruta, superbloque super, int posicion, char* mensaje, int espacio) 
{
	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	detalle ap2, ap;

	fseek(archivo, posicion, SEEK_SET);
	fread(&ap, sizeof(detalle), 1, archivo);
	int i = 0;
	int x = 0;
	int j = 0;

	fclose(archivo);
	for (i = 0; i < 5; i++) 
	{
		if (ap.content[i].inod > 50) 
		{
			char aux[10];
			char aux2[16];
			for (j = 0; j < 10; j++) 
			{
				aux[j] = '\0';
			}
			for (j = 0; j < 16; j++) 
			{
				aux2[j] = '\0';
			}
			strcpy(aux2, ap.content[i].name);
			strcpy(aux, mensaje);

			if (aux[0] == '?' && aux[1] == '\0') 
			{
				if (aux2[1] == '\0') 
				{
					for (j = 0; j < espacio; j++) 
					{
						printf(" ");
					}
					printf("|_ %s &\n", ap.content[i].name);
				}
			} 
			else if (aux[0] == '*' && aux[1] == '\0') 
			{
				for (j = 0; j < espacio; j++) {
					printf(" ");
				}
				printf("|_%s @\n", ap.content[i].name);
			} 
			else 
			{
				j = 0;
				x = 0;
				while (aux[j] != '\0') 
				{
					if (aux[j] == '?') 
					{
						if (aux[j + 1] == aux2[x + 1]) 
						{
							j++;
							x++;
						} else { break; }
					} 
					else if (aux[j] == '*') 
					{
						j++;
						while (aux[j] != aux2[x] && '\0' != aux2[x]) { x++; }
					} 
					else if (aux[j] == aux2[x]) 
					{
						j++;
						x++;
					} 
					else {
						break;
					}
				}
				if (aux[j] == '\0')
				{
					int h;
					for (h = 0; h < espacio; h++) 
					{
						printf(" ");
					}
					printf("|_%s #\n", ap.content[i].name);
				}
			}
		}
	}
}

void crearDirectorio() 
{
	if (id == NULL || path == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		int d = crearDirectorioArchivo(id, path, p);
		if (d == 0) 
		{
			printf( "Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
		}
	}
}

int crearDirectorioArchivo(char* id, char* path, char* p) 
{
	char* ruta;
	char* nombre;
	int i = 0;
	for (i = 0; i < 31; i++) 
	{
		if (montar[i].vdID != NULL) 
		{
			if (strcasecmp(montar[i].vdID, id) == 0) 
			{
				if (montar[i].estado == 1) {
					if (montar[i].loss == 1) {
						printf("ERROR: Existe un fallo en el disco.\n");
						return 0;
					}
					ruta = montar[i].path; //%%%
					nombre = montar[i].name;
					break;
				}
			}
		}
	}
	if (i == 31) 
	{
		printf("ERROR: El ID no existe.\n");
		return 0;
	}

	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	if (archivo == NULL) 
	{
		ruta = generarPath(ruta);
		archivo = fopen(ruta, "rb+");
		if (archivo == NULL) 
		{
			printf("ERROR: No existe el disco.\n");
			return 0;
		}
	}
	mbr structDisco;
	fseek(archivo, 0, SEEK_SET);
	fread(&structDisco, sizeof(mbr), 1, archivo);

	//VERIFICAR LA PARTICION
	i = 0;
	int j = 0;
	int esLogica = 0;
	for (i = 0; i < 4; i++) 
	{
		if (strcasecmp(structDisco.part[i].name, nombre) == 0) 
		{
			break;
		}
		for (j = 0; j < 20; j++) 
		{
			if (strcasecmp(structDisco.part[i].exten[j].name, nombre) == 0) {
				esLogica = 1;
				break;
			}
			if (esLogica == 1) {
				break;
			}
		}
	}
	if (i == 4 && esLogica == 0) 
	{
		printf("ERROR: No existe el nombre indicado.\n");
		return 0;
	}
	superbloque sb;
	char ajuste;
	int posicion;
	if (esLogica == 1) 
	{
		posicion = structDisco.part[i].exten[j].start;
		ajuste = structDisco.part[i].exten[j].fit;
		fseek(archivo, structDisco.part[i].exten[j].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	} 
	else 
	{
		posicion = structDisco.part[i].start;
		ajuste = structDisco.part[i].fit;
		fseek(archivo, structDisco.part[i].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	}

	if (sb.magic == 201700345) 
	{
		fseek(archivo, sb.s.apuntador, SEEK_SET);
		apunt ap;
		fread(&ap, sizeof(ap), 1, archivo);

		char crear[100] = "";
		char verificar[100];
		char verificar2[100];
		strcpy(crear, path);
		int b, a = 0;
		for (a = 0; a < 100; a++) 
		{
			if (crear[a] != '\0') //Hasta que llegue al final
			{ 
				verificar[a] = crear[a];
				verificar2[a] = crear[a];
			} 
			else 
			{
				for (b = a; b >= 0; b--) 
				{
					if (verificar[b] != '/') {
						verificar[b] = '\0';
						verificar2[b] = '\0';
					} else {
						verificar[b] = '\0';
						verificar2[b] = '\0';
						break;
					}
				}
				break;
			}
		}

		fflush(NULL);
		char* ruta2;
		strcpy(verificar, verificar2);
		if (verificar[0] == '\0') 
		{
			ruta2 = strtok(crear, "/");
		}
		else 
		{
			ruta2 = strtok(verificar, "/");
		}

		int datos;
		correcto = 1;
		if (p == NULL) 
		{
			datos = crearCarpeta(ruta, sb, ap, ruta2, p, ajuste, posicion, sb.s.apuntador);
			ruta2 = strtok(crear, "/");
			if (correcto > 0) 
			{
				datos = crearCarpeta(ruta, sb, ap, ruta2, "si", ajuste, posicion, sb.s.apuntador);
			}
		} 
		else 
		{
			fflush(NULL);
			ruta2 = strtok(crear, "/");
			datos = crearCarpeta(ruta, sb, ap, ruta2, p, ajuste, posicion, sb.s.apuntador);
		}
		journaling(ruta, posicion, sb, 6, path, "", id, 1);
		return 1;
	} 
	else 
	{
		printf("No ha formateado la particion");
		return 0;
	}
}

void copiar() 
{

	if (id == NULL || path == NULL || dest == NULL || iddest == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		int d = copiarArchivo(id, path, dest, iddest);
		if (d == 0) 
		{
			printf( "Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
		} 
		else 
		{
			printf("-> Se ha copiado el archivo correctamente.\n");
		}
	}

}

int copiarArchivo(char* id, char* path, char* dest, char* iddest) 
{
	char* ruta;
	char* nombre;
	int i = 0;
	for (i = 0; i < 31; i++) 
	{
		if (montar[i].vdID != NULL) 
		{
			if (strcasecmp(montar[i].vdID, id) == 0) 
			{
				if (montar[i].estado == 1) {
					if (montar[i].loss == 1) {
						printf("ERROR: Existe un fallo en el disco.\n");
						return 0;
					}
					ruta = montar[i].path; //%%%
					nombre = montar[i].name;
					break;
				}
			}
		}
	}
	if (i == 31) 
	{
		printf("ERROR: El ID no existe.\n");
		return 0;
	}

	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	if (archivo == NULL) 
	{
		ruta = generarPath(ruta);
		archivo = fopen(ruta, "rb+");
		if (archivo == NULL) 
		{
			printf("ERROR: No existe el disco.\n");
			return 0;
		}
	}
	mbr structDisco;
	fseek(archivo, 0, SEEK_SET);
	fread(&structDisco, sizeof(mbr), 1, archivo);

	//VERIFICAR LA PARTICION
	i = 0;
	int j = 0;
	int esLogica = 0;
	for (i = 0; i < 4; i++) 
	{
		if (strcasecmp(structDisco.part[i].name, nombre) == 0) 
		{
			break;
		}
		for (j = 0; j < 20; j++) 
		{
			if (strcasecmp(structDisco.part[i].exten[j].name, nombre) == 0) 
			{
				esLogica = 1;
				break;
			}
			if (esLogica == 1) 
			{
				break;
			}
		}
	}
	if (i == 4 && esLogica == 0) 
	{
		printf("ERROR: No existe el nombre indicado.\n");
		return 0;
	}
	superbloque sb = crearBloque();
	char ajuste;
	int posicion;
	if (esLogica == 1) 
	{
		posicion = structDisco.part[i].exten[j].start;
		ajuste = structDisco.part[i].exten[j].fit;
		fseek(archivo, structDisco.part[i].exten[j].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	} 
	else 
	{
		posicion = structDisco.part[i].start;
		ajuste = structDisco.part[i].fit;
		fseek(archivo, structDisco.part[i].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	}

	if (sb.magic == 201700345) 
	{
		fseek(archivo, sb.s.apuntador, SEEK_SET);
		apunt ap;
		fread(&ap, sizeof(ap), 1, archivo);

		char crear[100];
		char verificar[100];
		char verificar2[100];
		strcpy(crear, path);
		int b, a = 0;
		for (a = 0; a < 100; a++) 
		{
			if (crear[a] != '\0') 
			{ //Hasta que llegue al final
				verificar[a] = crear[a];
				verificar2[a] = crear[a];
			} 
			else
			{
				for (b = a; b >= 0; b--) 
				{
					if (verificar[b] != '/') {
						verificar[b] = '\0';
						verificar2[b] = '\0';
					} else {
						verificar[b] = '\0';
						verificar2[b] = '\0';
						break;
					}
				}
				break;
			}
		}
		char* ruta1;
		char* ruta2;
		char auxPath[100];
		strcpy(auxPath, path);
		a = 0; //nuevas variables
		b = 0;
		for (a = 0; a < 100; a++) 
		{
			if (auxPath[a] == '.') {
				b++;
			}
		}
		fclose(archivo);
		strcpy(verificar, verificar2);
		if (verificar[0] == '\0') 
		{
			ruta1 = strtok(crear, "/");
		} 
		else 
		{
			ruta1 = strtok(verificar, "/");
		}
		ruta2 = strtok(crear, ".");

		int datos = 0;
		if (b < 1) 
		{
			ruta1 = strtok(crear, "/");
			copiarCarpeta(ruta, sb, ruta1, sb.s.apuntador, dest, iddest);
			journaling(ruta, posicion, sb, 4, path, "", id, 1);
		} 
		else 
		{
			ruta1 = strtok(verificar2, "/");
			datos = buscarArchivo(ruta, sb, ap, ruta1, posicion, ajuste, sb.s.apuntador);
			if (datos > 0) 
			{
				ruta1 = strtok(path, "/");
				while ((strstr(ruta1, ".") == 0x0 || strstr(ruta1, ".") == ""
						|| strstr(ruta1, ".") == NULL) && ruta1 != NULL
						&& ruta1 != 0x0) {
					ruta1 = strtok(NULL, "/");
				}
				if (ruta1 != NULL) 
				{
					char mensaje[200];
					int j = 0;
					for (j = 0; j < 200; j++) 
					{
						mensaje[j] = '\0';
					}
					strcpy(mensaje, contenidoArchivo(" ", datos, sb, ruta, ruta1));
					FILE* reporte;
					reporte = fopen("/home/chay/auxContenido.txt", "w+");
					fprintf(reporte, mensaje);
					fclose(reporte);
					char auxRuta[100];
					for (j = 0; j < 100; j++) 
					{
						auxRuta[j] = '\0';
					}
					strcat(auxRuta, dest);
					strcat(auxRuta, "/");
					strcat(auxRuta, ruta1);
					crearArchivoParticion(iddest, auxRuta, NULL, NULL, "/home/chay/auxContenido.txt");
				}
			} 
			else 
			{
				printf("ERROR: No existe la ruta indicada.\n");
				return 0;
			}
		}
	} 
	else 
	{
		printf("ERROR: La particion no ha sido formateada.\n");
		return 0;
	}
	return 1;
}

int copiarCarpeta(char* ruta, superbloque super, char* path, int posicion, char* dest, char* iddest) 
{
	FILE* disco;
	disco = fopen(ruta, "rb+");
	apunt ap, ap2;

	fseek(disco, posicion, SEEK_SET);
	fread(&ap, sizeof(apunt), 1, disco);
	int i = 0;
	for (i = 0; i < 6; i++) 
	{
		if (ap.subDirectorios[i] > 50) 
		{
			fseek(disco, ap.subDirectorios[i], SEEK_SET);
			fread(&ap2, sizeof(ap2), 1, disco);

			if (strcasecmp(ap2.pointer, path) == 0) {
				break;
			}
		}
	}
	if (i < 6) 
	{
		char* copia = path;
		path = strtok(NULL, "/");
		if (path != NULL && path != 0x0) 
		{
			fclose(disco);
			return copiarCarpeta(ruta, super, path, ap.subDirectorios[i], dest,
					iddest);
		} 
		else 
		{
			int sub = ap.subDirectorios[i];
			printf("-> Se copio la carpeta correctamentee.\n");
			fclose(disco);
			return copiarRaizCarpeta(ruta, super, sub, iddest, dest);
		}
	} 
	else 
	{
		if (ap.apuntador < 1) 
		{
			printf("ERROR: No existe la carpeta.\n");
			return 0;
		} 
		else 
		{
			fclose(disco);
			return copiarCarpeta(ruta, super, path, ap.apuntador, dest, iddest);
		}
	}
}

int copiarRaizCarpeta(char* ruta, superbloque super, int posicion, char* iddest, char* dest) 
{
	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	apunt ap;

	fseek(archivo, posicion, SEEK_SET);
	fread(&ap, sizeof(apunt), 1, archivo);

	int i = 0;
	int j = 0;

	char llenar[50];
	for (j = 0; j < 50; j++) 
	{
		llenar[j] = '\0';
	}
	strcpy(llenar, dest);
	strcat(llenar, "/");
	strcat(llenar, ap.pointer);
	fclose(archivo);
	crearCopia(iddest, llenar, NULL);
	printf("holi\n");

	for (i = 0; i < 6; i++) 
	{
		if (ap.subDirectorios[i] > 0) 
		{
			int sub = ap.subDirectorios[i];
			copiarRaizCarpeta(ruta, super, sub, iddest, llenar);
		}
	}

	if (ap.apuntador > 0) 
	{
		copiarRaizCarpeta(ruta, super, ap.apuntador, iddest, dest);
	}
	if (ap.directorio > 0) 
	{
		copiarRaizArchivo(ruta, super, ap.directorio, iddest, llenar);
	}
	return 1;
}

int crearCopia(char* id, char* path, char* p) 
{
	char* ruta;
	char* nombre;
	int i = 0;
	for (i = 0; i < 31; i++) 
	{
		if (montar[i].vdID != NULL) 
		{
			if (strcasecmp(montar[i].vdID, id) == 0) 
			{
				if (montar[i].estado == 1) {
					ruta = montar[i].path; //%%%
					nombre = montar[i].name;
					break;
				}
			}
		}
	}
	if (i == 31) 
	{
		printf("ERROR: El ID no existe.\n");
		return 0;
	}

	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	if (archivo == NULL) 
	{
		printf("ERROR: No existe el disco.\n");
		return 0;
	}
	mbr structDisco;
	fseek(archivo, 0, SEEK_SET);
	fread(&structDisco, sizeof(mbr), 1, archivo);

	//VERIFICAR LA PARTICION
	i = 0;
	int j = 0;
	int esLogica = 0;
	for (i = 0; i < 4; i++) 
	{
		if (strcasecmp(structDisco.part[i].name, nombre) == 0) 
		{
			break;
		}
		for (j = 0; j < 20; j++) 
		{
			if (strcasecmp(structDisco.part[i].exten[j].name, nombre) == 0) 
			{
				esLogica = 1;
				break;
			}
			if (esLogica == 1) {
				break;
			}
		}
	}
	if (i == 4 && esLogica == 0) 
	{
		printf("ERROR: No existe el nombre indicado.\n");
		return 0;
	}
	superbloque sb;
	char ajuste;
	int posicion;
	if (esLogica == 1) 
	{
		posicion = structDisco.part[i].exten[j].start;
		ajuste = structDisco.part[i].exten[j].fit;
		fseek(archivo, structDisco.part[i].exten[j].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	} 
	else 
	{
		posicion = structDisco.part[i].start;
		ajuste = structDisco.part[i].fit;
		fseek(archivo, structDisco.part[i].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	}

	if (sb.magic == 201700345) 
	{
		fseek(archivo, sb.s.apuntador, SEEK_SET);
		apunt ap;
		fread(&ap, sizeof(ap), 1, archivo);

		char crear[100];
		char verificar[100];
		char verificar2[100];
		strcpy(crear, path);
		int b, a = 0;
		for (a = 0; a < 100; a++) 
		{
			if (crear[a] != '\0') 
			{ //Hasta que llegue al final
				verificar[a] = crear[a];
				verificar2[a] = crear[a];
			} 
			else 
			{
				for (b = a; b >= 0; b--) 
				{
					if (verificar[b] != '/') {
						verificar[b] = '\0';
						verificar2[b] = '\0';
					} else {
						verificar[b] = '\0';
						verificar2[b] = '\0';
						break;
					}
				}
				break;
			}
		}
		char* ruta1;
		strcpy(verificar2, verificar);
		if (verificar[0] == '\0') 
		{
			p = "si";
			ruta1 = strtok(crear, "/");
		} 
		else 
		{
			ruta1 = strtok(verificar, "/");
		}
		fclose(archivo);

		int datos;
		correcto = 1;
		if (p == NULL) 
		{
			datos = crearCarpeta(ruta, sb, ap, ruta1, p, ajuste, posicion, sb.s.apuntador);
			ruta1 = strtok(crear, "/");
			if (correcto > 0) 
			{
				datos = crearCarpeta(ruta, sb, ap, ruta1, "si", ajuste, posicion, sb.s.apuntador);
				printf("murio\n");
			}
		} 
		else 
		{
			ruta1 = strtok(crear, "/");
			datos = crearCarpeta(ruta, sb, ap, ruta1, p, ajuste, posicion, sb.s.apuntador);
		}
		journaling(ruta, posicion, sb, 6, path, "", id, 1);
	} 
	else 
	{
		printf("ERROR: No se ha formateado la particion.");
	}
	return 1;
}

int copiarRaizArchivo(char* ruta, superbloque super, int posicion, char* iddest, char* dest) 
{
	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	detalle carp;

	fseek(archivo, posicion, SEEK_SET);
	fread(&carp, sizeof(detalle), 1, archivo);
	int i = 0;
	int j = 0;

	fclose(archivo);
	for (i = 0; i < 5; i++) 
	{
		if (carp.content[i].inod > 50) 
		{
			char mensaje[200];
			for (j = 0; j < 200; j++) 
			{
				mensaje[j] = '\0';
			}
			strcpy(mensaje,
					contenidoArchivo(" ", posicion, super, ruta,carp.content[i].name));
			FILE* reporte;
			reporte = fopen("/home/chay/archivoAux.txt", "w+");
			fprintf(reporte, mensaje);
			fclose(reporte);
			char aux[100];
			for (j = 0; j < 100; j++) 
			{
				aux[j] = '\0';
			}
			strcpy(aux, dest);
			strcat(aux, "/");
			strcat(aux, carp.content[i].name);
			char* enviado = aux;
			crearArchivoParticion(iddest, enviado, NULL, NULL, "/home/chay/archivoAux.txt");
		}
	}
	if (carp.detalle > 50) 
	{
		copiarRaizArchivo(ruta, super, carp.detalle, iddest, dest);
	}
	return 1;
}

char* contenidoArchivo(char* contenido, int posicion, superbloque super,char* ruta, char* name)
{
	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	detalle carp;
	fseek(archivo, posicion, SEEK_SET);
	fread(&carp, sizeof(detalle), 1, archivo);
	int i = 0;
	for (i = 0; i < 5; i++) 
	{
		if (carp.content[i].inod > 1) 
		{
			if (strcasecmp(carp.content[i].name, name) == 0) 
			{
				break;
			}
		}
	}
	if (i < 5) 
	{
		inodo ino;
		fseek(archivo, carp.content[i].inod, SEEK_SET);
		fread(&ino, sizeof(inodo), 1, archivo);
		if (ino.size > 100) 
		{
			int i = 0;
			char texto[2000];
			for (i = 0; i < 2000; i++) 
			{
				texto[i] = '\0';
			}
			if (ino.noInodo > 4) 
			{
				ino.noInodo = 4;
			}
			setbuf(stdin, NULL);
			for (i = 0; i < ino.noInodo; i++) 
			{
				datos arch;
				fseek(archivo, ino.bloques[i], SEEK_SET);
				fread(&arch, sizeof(datos), 1, archivo);
				strcat(texto, arch.data);
				contenido = &texto;
			}
			inodo ino2;
			fseek(archivo, ino.indirecto, SEEK_SET);
			fread(&ino2, sizeof(inodo), 1, archivo);
			if (ino2.noInodo > 4) 
			{
				ino2.noInodo = 4;
			}
			for (i = 0; i < ino2.noInodo; i++) 
			{
				datos arch;
				fseek(archivo, ino2.bloques[i], SEEK_SET);
				fread(&arch, sizeof(datos), 1, archivo);
				strcat(texto, arch.data);
				setbuf(stdin, NULL);
				contenido = &texto;
			}
			fclose(archivo);
			return contenido;

		} 
		else 
		{
			char texto[2000];
			int i = 0;
			for (i = 0; i < ino.noInodo; i++) 
			{
				datos arch;
				fseek(archivo, ino.bloques[i], SEEK_SET);
				fread(&arch, sizeof(datos), 1, archivo);
				strcat(texto, arch.data);
				setbuf(stdin, NULL);
				contenido = &texto;
				if (i > 3) 
				{
					break;
				}
			}
			fclose(archivo);
			return contenido;
		}
	} 
	else 
	{
		if (carp.detalle > 0) 
		{
			fclose(archivo);
			setbuf(stdin, NULL);
			return contenidoArchivo(contenido, carp.detalle, super, ruta, name);
		} 
		else 
		{
			printf("ERROR: El archivo no existe.\n");
			return "";
		}
	}
}

void mostrarContenido() 
{
	int cont = 0;
	if (id == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		if (file != NULL) 
		{
			int d = mostrarContenidoArchivo(id, file);
			if (d == 0) 
			{
				printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
			}
			cont++;
		}
		if (cont == 0) 
		{
			printf("ERROR: Falta un atributo obligatorio.\n");
		}
	}
}

int mostrarContenidoArchivo(char* id, char* filen) 
{
	char* ruta;
	char* nombre;
	int i = 0;
	for (i = 0; i < 31; i++) 
	{
		if (montar[i].vdID != NULL) 
		{
			if (strcasecmp(montar[i].vdID, id) == 0) 
			{
				if (montar[i].estado == 1) 
				{
					if (montar[i].loss == 1) 
					{
						printf("ERROR: Existe un fallo en el disco.\n");
						return 0;
					}
					ruta = montar[i].path; //%%%
					nombre = montar[i].name;
					break;
				}
			}
		}
	}
	if (i == 31) 
	{
		printf("ERROR: El ID no existe.\n");
		return 0;
	}

	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	if (archivo == NULL) 
	{
		ruta = generarPath(ruta);
		archivo = fopen(ruta, "rb+");
		if (archivo == NULL) 
		{
			printf("ERROR: No existe el disco.\n");
			return 0;
		}
	}
	mbr structDisco;
	fseek(archivo, 0, SEEK_SET);
	fread(&structDisco, sizeof(mbr), 1, archivo);

	//VERIFICAR LA PARTICION
	i = 0;
	int j = 0;
	int esLogica = 0;
	for (i = 0; i < 4; i++) 
	{
		if (strcasecmp(structDisco.part[i].name, nombre) == 0) {
			break;
		}
		for (j = 0; j < 20; j++) 
		{
			if (strcasecmp(structDisco.part[i].exten[j].name, nombre) == 0) {
				esLogica = 1;
				break;
			}
			if (esLogica == 1) {
				break;
			}
		}
	}
	if (i == 4 && esLogica == 0) 
	{
		printf("ERROR: No existe el nombre indicado.\n");
		return 0;
	}

	superbloque sb;
	char ajuste;
	int posicion;
	if (esLogica == 1) 
	{
		posicion = structDisco.part[i].exten[j].start;
		ajuste = structDisco.part[i].exten[j].fit;
		fseek(archivo, structDisco.part[i].exten[j].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	} 
	else 
	{
		posicion = structDisco.part[i].start;
		ajuste = structDisco.part[i].fit;
		fseek(archivo, structDisco.part[i].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	}

	if (sb.magic == 201700345) 
	{
		fseek(archivo, sb.s.apuntador, SEEK_SET);
		apunt ap;
		fread(&ap, sizeof(ap), 1, archivo);

		char crear[100];
		char verificar[100];
		char verificar2[100];
		strcpy(crear, filen);
		int b, a = 0;
		for (a = 0; a < 100; a++) 
		{
			if (crear[a] != '\0') 
			{ //Hasta que llegue al final
				verificar[a] = crear[a];
				verificar2[a] = crear[a];
			} 
			else 
			{
				for (b = a; b >= 0; b--) 
				{
					if (verificar[b] != '/') {
						verificar[b] = '\0';
						verificar2[b] = '\0';
					} else {
						verificar[b] = '\0';
						verificar2[b] = '\0';
						break;
					}
				}
				break;
			}
		}
		char* ruta2;
		strcpy(verificar, verificar2);
		if (verificar[0] == '\0') 
		{
			ruta2 = strtok(crear, "/");
		} 
		else 
		{
			ruta2 = strtok(verificar, "/");
		}
		fclose(archivo);
		int datos;
		ruta2 = strtok(verificar2, "/");
		datos = buscarArchivo(ruta, sb, ap, ruta2, ajuste, posicion,sb.s.apuntador);

		if (datos > 0) 
		{
			ruta2 = strtok(crear, "/");
			while ((strstr(ruta2, ".") == 0x0 || strstr(ruta2, ".") == ""
					|| strstr(ruta2, ".") == NULL) && ruta2 != NULL) {
				ruta2 = strtok(NULL, "/");
			}
			if (ruta2 != NULL) 
			{
				char mensaje[2000] = "";
				strcpy(mensaje, contenidoArchivo(" ", datos, sb, ruta, ruta2));
				printf("* * * * * * * * * * * * * * * * * * * * * *\n%s\n", mensaje);
			}
		} 
		else 
		{
			printf("ERROR: La ruta no existe.\n");
		}
	} 
	else 
	{
		printf("ERROR: La particion no esta formateada.\n");
	}
	return 1;
}

void mover() 
{
	if (id == NULL || path == NULL || dest == NULL || iddest == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		boolEditar = 1;
		int d = moverArchivo(id, path, dest, iddest);
		if (d == 0) 
		{
			printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
		}
	}

}

int moverArchivo(char* id, char* path, char* dest, char* iddest) 
{
	printf("-> Copiar\n");
	char pathAux[200] = "";
	strcpy(pathAux, path);
	int a = copiarArchivo(id, path, dest, iddest);
	printf("-> Eliminar\n");
	strcpy(path, pathAux);
	int b = removerArchivo(id, path, 0);
	strcpy(path, pathAux);
	if (a == 1 && b == 1) 
	{
		return 1;
	} 
	else 
	{
		return 0;
	}
}

superbloque crearBloque() 
{
	superbloque sb;
	sb.inodosCount = 0;
	sb.bloquesCount = 0;
	sb.freeBloquesCount = 0;
	sb.freeInodosCount = 0;
	sb.mountCount = 0;
	sb.magic = 0;
	sb.inodoSize = 0;
	sb.bloqueSize = 0;
	sb.apuntadorBitTablaInodo = 0;
	sb.apuntadorTablaInodo = 0;
	sb.firstFreeBitTablaInodo = 0;
	sb.firstFreeBitBloque = 0;

	return sb;
}

int bitacora(int posicion, int operacion, char* nombre, char* contenido, superbloque super, char* ruta, char* vdID) 
{
	printf("Bitacora = (%d, %d, %s, %s, %s , ->%s<- )\n", posicion, operacion, nombre, contenido, ruta, vdID);

	FILE* disco;
	disco = fopen(ruta, "rb+");
	journal bitacora;
	fseek(disco, posicion, SEEK_SET);
	fread(&bitacora, sizeof(journal), 1, disco);

	journal aux = bitacora;

	int a = 1;
	int b = posicion;
	int tipo = bitacora.tipo;
	while (bitacora.tipo > 0) //Si es carpeta
	{ 
		b = bitacora.tipo;
		fseek(disco, bitacora.tipo, SEEK_SET);
		fread(&bitacora, sizeof(journal), 1, disco);
		a++;
		if (a == 10000)
		{
			printf("Limite\n");
			bitacora = aux;
			break;
		}
	}

	if (a != 10000) 
	{
		printf("Menor\n");
		bitacora.tipo = super.jourfirst + 100 * a * sizeof(journal);
		fseek(disco, b, SEEK_SET);
		fwrite(&bitacora, sizeof(journal), 1, disco);
		journal bita;
		bita.operacion = operacion;
		strcpy(bita.vdID, vdID);
		strcpy(bita.nombre, nombre);
		strcpy(bita.contenido, contenido);
		bita.fecha = time(0);
		bita.tipo = 0;
		fseek(disco, bitacora.tipo, SEEK_SET);
		fwrite(&bita, sizeof(journal), 1, disco);
	}
	else 
	{
		fseek(disco, tipo, SEEK_SET);
		printf("Mayor\n");
	}
	fclose(disco);
	return 1;
}

void journaling(char *ruta, int posicion, superbloque sb, int ope, char *path,char *contenido, char *id, int tipo) 
{
	printf("Posicion = %d - Path = %s - ", posicion, path);
	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	if (archivo == NULL) 
	{
		ruta = generarPath(ruta);
		archivo = fopen(ruta, "rb+");
		if (archivo == NULL) 
		{
			printf("ERROR: No existe el disco.\n");
			return;
		}
	}
	if (strlen(contenido) == 0) 
	{
		char pathAux[100];
		strcpy(pathAux, path);
		fseek(archivo, posicion, SEEK_SET);
		printf("Contador = %d\n", sb.s.contadorJ);
		sb.j[sb.s.contadorJ].bitacora.tipo = tipo; //0 archivo, 1 D
		sb.j[sb.s.contadorJ].bitacora.operacion = ope;
		sb.j[sb.s.contadorJ].bitacora.fecha = time(0);
		strcpy(sb.j[sb.s.contadorJ].bitacora.vdID, id);
		strcpy(sb.j[sb.s.contadorJ].bitacora.path, path);
		strcpy(sb.j[sb.s.contadorJ].bitacora.nombre, obtenerNombre(path));
		strcpy(path, pathAux);
		strcpy(sb.j[sb.s.contadorJ].bitacora.padre, obtenerPadre(path));
		strcpy(path, pathAux);
		strcpy(sb.j[sb.s.contadorJ].bitacora.contenido, "");
		sb.s.contadorJ++;
		fwrite(&sb, sizeof(superbloque), 1, archivo);
	} 
	else 
	{
		char content[strlen(contenido)];
		strcpy(content, contenido);
		char datos[64] = "";
		int i, j = 0;
		for (i = 0; i < strlen(contenido); i++) 
		{
			for (j = 0; j < 64; j++) 
			{
				//	if()
				datos[j] = content[i];
				i++;
				if (i == strlen(contenido)) 
				{
					break;
				}
			}
			char pathAux[100];
			strcpy(pathAux, path);

			fseek(archivo, posicion, SEEK_SET);
			printf("Contador = %d\n", sb.s.contadorJ);
			sb.j[sb.s.contadorJ].bitacora.tipo = tipo; //0 archivo, 1 D
			sb.j[sb.s.contadorJ].bitacora.operacion = ope;
			sb.j[sb.s.contadorJ].bitacora.fecha = time(0);
			sb.j[sb.s.contadorJ].bitacora.tamanio = j;
			strcpy(sb.j[sb.s.contadorJ].bitacora.vdID, id);
			strcpy(sb.j[sb.s.contadorJ].bitacora.path, path);
			strcpy(sb.j[sb.s.contadorJ].bitacora.nombre, obtenerNombre(path));
			strcpy(path, pathAux);
			strcpy(sb.j[sb.s.contadorJ].bitacora.padre, obtenerPadre(path));
			strcpy(path, pathAux);
			strcpy(sb.j[sb.s.contadorJ].bitacora.contenido, datos);

			sb.s.contadorJ++;
			fwrite(&sb, sizeof(superbloque), 1, archivo);
		}
	}

	fclose(archivo);
}

void actualizar() 
{
	if (id != NULL)
	{
		char *ruta1 = obtenerRuta(id);
		if (ruta1 != NULL) 
		{
			char rutaAux[200];
			strcpy(rutaAux, ruta1);
			char *nombre = generarPath(ruta1);
			copiarFichero(rutaAux, nombre);
			strcpy(ruta1, rutaAux);
		}
	}
}

void loss() 
{
	if (id == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		int i = 0;
		for (i = 0; i < 31; i++) 
		{
			if (montar[i].vdID != NULL) 
			{
				if (strcasecmp(montar[i].vdID, id) == 0) 
				{
					if (montar[i].estado == 1) {
						montar[i].loss = 1;
						break;
					}
				}
			}
		}
		if (i == 31) 
		{
			printf("ERROR: El ID no existe.\n");
			return;
		}
	}
}

void recovery() 
{
	if (id == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		char* ruta;
		char* nombre;
		int i = 0;
		for (i = 0; i < 31; i++) 
		{
			if (montar[i].vdID != NULL) 
			{
				if (strcasecmp(montar[i].vdID, id) == 0) 
				{
					if (montar[i].estado == 1) {
						montar[i].loss = 0;
						ruta = montar[i].path; //%%%
						nombre = montar[i].name;
						break;
					}
				}
			}
		}
		if (i == 31) 
		{
			printf("ERROR: El ID no existe.\n");
			return;
		}

		FILE* archivo;
		archivo = fopen(ruta, "rb+");
		if (archivo == NULL) 
		{
			ruta = generarPath(ruta);
			archivo = fopen(ruta, "rb+");
			if (archivo == NULL) 
			{
				printf("ERROR: No existe el disco.\n");
				return;
			}
		}
		mbr structDisco;
		fseek(archivo, 0, SEEK_SET);
		fread(&structDisco, sizeof(mbr), 1, archivo);

		//VERIFICAR LA PARTICION
		i = 0;
		int j = 0;
		int esLogica = 0;
		for (i = 0; i < 4; i++) 
		{
			if (strcasecmp(structDisco.part[i].name, nombre) == 0) {
				break;
			}
			for (j = 0; j < 20; j++) 
			{
				if (strcasecmp(structDisco.part[i].exten[j].name, nombre)
						== 0) {
					esLogica = 1;
					break;
				}
				if (esLogica == 1) {
					break;
				}
			}
		}
		if (i == 4 && esLogica == 0) {
			printf("ERROR: No existe el nombre indicado.\n");
			return;
		}
		superbloque sb;
		if (esLogica == 1) 
		{
			fseek(archivo, structDisco.part[i].exten[j].start, SEEK_SET);
			fread(&sb, sizeof(superbloque), 1, archivo);
		} 
		else 
		{
			fseek(archivo, structDisco.part[i].start, SEEK_SET);
			fread(&sb, sizeof(superbloque), 1, archivo);
		}

		fclose(archivo);
		char rutaAux[100];
		strcpy(rutaAux, ruta);
		char *nameR = obtenerNombre(ruta);
		strcpy(ruta, rutaAux);
		char *recovery = concatenar("/home/chay/recovery",nameR);
		copiarFichero(ruta, recovery);
		formatearDisco(id, "full", "", "k", "");

		for (i = 0; i < sb.s.contadorJ; i++) 
		{
			journal bitacora = sb.j[i].bitacora;

			if (bitacora.operacion == 1) 
			{
				crearArchivo();
			} 
			else if (bitacora.operacion == 2) 
			{ // mkfile
				crearArchivoParticion(bitacora.vdID, bitacora.nombre, "p", 0, bitacora.contenido);
			} 
			else if (bitacora.operacion == 3) 
			{ //rm
				removerArchivo(bitacora.vdID, bitacora.nombre, 0);
			} 
			else if (bitacora.operacion == 4) 
			{ //cp
				//copiarArchivo(bitacora.vdID,bitacora.nombre)
			} else if (bitacora.operacion == 5) 
			{ //mv
				//moverArchivo(bitacora.vdID,bitacora.nombre,"","")''
			} 
			else if (bitacora.operacion == 6) 
			{ // mkdir
				char p[100] = "";
				strcpy(p, bitacora.path);
				crearDirectorioArchivo(bitacora.vdID, p, "p");
			} 
		}

	}

}

void copiarFichero(char *origen, char *destino) 
{
	FILE *arch1 = NULL;
	FILE *arch2 = NULL;
	arch1 = fopen(origen, "r");
	arch2 = fopen(destino, "r");
	if (arch1 != NULL && arch2 != NULL) 
	{
		char *cadena = concatenar("cp ", origen);
		cadena = concatenar(cadena, " ");
		cadena = concatenar(cadena, destino);
		system(cadena);

		fclose(arch1);
		fclose(arch2);
	}
}

char *obtenerPadre(char *ruta) 
{
	char* datos[10];
	int cont = 0;

	char* inst = NULL;
	inst = strtok(ruta, "/");
	datos[cont] = inst;

	while (inst != NULL) 
	{
		cont++;
		inst = strtok(NULL, "/");
		datos[cont] = inst;
	}
	return datos[cont - 2];
}

void load() 
{
	if (id == NULL || path == NULL || type == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		int d = loadData(id, path, type);
		if (d == 0) 
		{
			printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
		}
	}

}

int loadData(char* id, char* path, char* type) 
{
	char* ruta;
	char* nombre;
	int i = 0;
	for (i = 0; i < 31; i++) {
		if (montar[i].vdID != NULL) {
			if (strcasecmp(montar[i].vdID, id) == 0) {
				if (montar[i].estado == 1) {
					if (montar[i].loss == 1) {
						printf("ERROR: Existe un fallo en el disco.\n");
						return 0;
					}
					ruta = montar[i].path; //%%%
					nombre = montar[i].name;
					break;
				}
			}
		}
	}
	if (i == 31) {
		printf("ERROR: El ID no existe.\n");
		return 0;
	}

	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	if (archivo == NULL) 
	{
		ruta = generarPath(ruta);
		archivo = fopen(ruta, "rb+");
		if (archivo == NULL) {
			printf("ERROR: No existe el disco.\n");
			return 0;
		}
	}
	mbr structDisco;
	fseek(archivo, 0, SEEK_SET);
	fread(&structDisco, sizeof(mbr), 1, archivo);

	//VERIFICAR SI EL NOMBRE COINCIDE CON LA PARTICION
	int j = 0;
	int existeLogica = 0;
	for (i = 0; i < 4; i++) 
	{ //Primaria/extendida
		if (strcasecmp(structDisco.part[i].name, nombre) == 0) {
			break;
		}
		for (j = 0; j < 20; j++) 
		{ //journalica
			if (strcasecmp(structDisco.part[i].exten[j].name, nombre) == 0) {
				existeLogica = 1;
				break;
			}
		}
		if (existeLogica == 1) {
			break;
		}
	}
	if (i == 4 && existeLogica == 0) 
	{
		printf("ERROR: No existe el nombre indicado.\n");
		return 0;
	}
	superbloque sb;
	char ajuste;
	int posicion;

	if (existeLogica == 1) 
	{
		posicion = structDisco.part[i].exten[j].start;
		ajuste = structDisco.part[i].exten[j].fit;
		fseek(archivo, structDisco.part[i].exten[j].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	} 
	else 
	{
		posicion = structDisco.part[i].start;
		ajuste = structDisco.part[i].fit;
		fseek(archivo, structDisco.part[i].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	}

	if (sb.magic == 201700345) 
	{
		if (strcasecmp(type, "usr") == 0) 
		{
			//OBTENER ARCHIVO
			FILE* archivoCargar;
			char caracter[1000];
			archivoCargar = fopen(path, "r+");
			if (archivoCargar == NULL) 
			{
				printf("ERROR: No existe el archivo a cargar.\n");
				return 0;
			} 
			else 
			{
				int j = 0;
				for (j = 0; j < 1000; j++) 
				{
					caracter[j] = '\0';
				}
				int i = 0;
				fseek(archivo, posicion, SEEK_SET);

				while (feof(archivoCargar) == 0) // *feof* hasta que se acabe el archivo
				{ 
					caracter[i] = fgetc(archivoCargar); // *fgetc* lee lineapor linea
					printf(&caracter[i]);

					if (caracter[i] == '\n') 
					{
						char com[1000];
						char com2[1000];
						caracter[i] = '\0';
						strcpy(com, caracter);
						strcpy(com2, com);
						char *comando = NULL;
						int contador = 1;
						comando = strtok(com, ",");
						strcpy(sb.user[sb.s.contadorU].usuario.id, comando);

						while (comando != NULL) 
						{
							//strcpy(sb.user[sb.s.contadorU].usuario.id, comando);
							comando = strtok(NULL, ",");
							if (comando != NULL) 
							{
								//printf("%s\n", comando);
								switch (contador) 
								{
									case 0:
										break;
									case 1:
										strcpy(sb.user[sb.s.contadorU].usuario.tipo,
												comando);
										break;
									case 2:
										strcpy(
												sb.user[sb.s.contadorU].usuario.grupo,
												comando);
										break;
									case 3:
										strcpy(
												sb.user[sb.s.contadorU].usuario.usuario,
												comando);
										break;
									case 4:
										strcpy(
												sb.user[sb.s.contadorU].usuario.clave,
												comando);
										break;
								}
							}
							contador++;
						}
						sb.s.contadorU++;

						for (j = 0; j < 1000; j++) 
						{
							caracter[j] = '\0';
						}
						printf("\n");
						i = 0;
					} 
					else if (caracter[i] == '\\') 
					{
						caracter[i] = ' ';
					} 
					else 
					{
						i++;
					}
				}
				fwrite(&sb, sizeof(superbloque), 1, archivo);
			}

			fclose(archivo);
			fclose(archivoCargar);
			printf("-> Se han cargado los USUARIOS correctamente.\n");
			return 1;

		} 
		else if (strcasecmp(type, "perm") == 0) 
		{
			boolEditar = 1;
			crearArchivoParticion(id, "/home/permisos.txt", "si", "10", "/home/chay/vacio.txt");
			FILE* archivoCargar;
			char caracter[1000];
			archivoCargar = fopen(path, "r+");
			if (archivoCargar == NULL) 
			{
				printf("ERROR: No existe el archivo a cargar.\n");
				return 0;
			} 
			else 
			{
				int j = 0;
				for (j = 0; j < 1000; j++) {
					caracter[j] = '\0';
				}
				int i = 0;
				fseek(archivo, posicion, SEEK_SET);

				while (feof(archivoCargar) == 0) 
				{ // *feof* hasta que se acabe el archivo
					caracter[i] = fgetc(archivoCargar); // *fgetc* lee lineapor linea
					printf(&caracter[i]);

					if (caracter[i] == '\n') 
					{
						char com[1000];
						char com2[1000];
						caracter[i] = '\0';
						strcpy(com, caracter);
						strcpy(com2, com);
						char *comando = NULL;
						int contador = 1;
						comando = strtok(com, ",");
						strcpy(sb.perm[sb.s.contadorP].permiso.usuario,
								comando);
						while (comando != NULL) 
						{
							comando = strtok(NULL, ",");
							if (comando != NULL) 
							{
								//printf("%s\n", comando);
								switch (contador) 
								{
									case 1:
										strcpy(sb.perm[sb.s.contadorP].permiso.ruta,
												comando);
										break;
									case 2:
										strcpy(
												sb.perm[sb.s.contadorP].permiso.permiso,
												comando);
										break;
								}
							}
							contador++;
						}
						sb.s.contadorP++;

						for (j = 0; j < 1000; j++) 
						{
							caracter[j] = '\0';
						}
						printf("\n");
						i = 0;
					} 
					else if (caracter[i] == '\\') 
					{
						caracter[i] = ' ';
					} 
					else 
					{
						i++;
					}
				}
				fwrite(&sb, sizeof(superbloque), 1, archivo);
			}

			fclose(archivo);
			fclose(archivoCargar);

			printf("-> Se han cargado los PERMISOS correctamente.\n");
			return 1;
		} 
		else 
		{
			printf("ERROR: Tipo no existe.\n");
			return 0;
		}
	} 
	else 
	{
		printf("ERROR: La particion no ha sido formateada.\n");
	}

	return 1;
}

void logg() 
{
	boolLogin = 1;
	usrLogin = "root";
}

void login() 
{
	if (usuarioo == NULL || password == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		logg();
		int d = iniciarSesion(usuarioo, password);
		if (d == 0) 
		{
			printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
		}
	}
}

int verificarLogin(char* atributos, char* usuario, char* password) 
{
	char* instruc = NULL;
	con = 1;
	char atr[200];
	strcpy(atr, atributos);
	int j;
	for (j = 0; j < 200; j++) 
	{
		if (atr[j] == '\\') 
		{
			atr[j] = ' ';
		}
	}
	strcpy(atributos, atr);
	char aux[100];

	strcpy(aux, atributos);
	instruc = strtok(atributos, ",");
	contadorU = instruc;
	while (instruc != NULL) 
	{
		instruc = strtok(NULL, ",");
		if (instruc != NULL) 
		{
			switch (con) 
			{
				case 1:
					tipoU = instruc;
					break;
				case 2:
					grupoU = instruc;
					break;
				case 3:
					nombreU = instruc;
					break;
				case 4:
					passU = instruc;
					break;
			}
			con++;
		}
	}
	/*****************/
	if (strcasecmp(tipoU, "U") == 0) 
	{
		printf("U:: %s - %s\n", nombreU, usuario);
		if (strcasecmp(nombreU, usuario) == 0) 
		{
			printf("P:: %s - %s\n", passU, password);
			if (strcasecmp(passU, password) == 0) 
			{
				if (strcasecmp(contadorU, "0") == 0) 
				{
					printf("-> El usuario ha sido eliminado.\n");
					return 0;
				} 
				else 
				{
					printf("-> El usuario %s se ha logeado exitosamente.\n", usuario);
					return 1;
				}
			}
		}
	}
	return 0;
}

int iniciarSesion(char* usuario, char* password) 
{
	char* ruta;
	char* nombre;
	int i = 0;
	for (i = 0; i < 31; i++) 
	{
		if (montar[i].vdID != NULL) 
		{
			if (strcasecmp(montar[i].vdID, "vda1") == 0) 
			{
				if (montar[i].estado == 1) 
				{
					ruta = montar[i].path; //%%%
					nombre = montar[i].name;
					break;
				}
			}
		}
	}
	if (i == 31) 
	{
		printf("ERROR: El ID no existe.\n");
		return 0;
	}

	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	if (archivo == NULL) 
	{
		printf("ERROR: No existe el disco.\n");
		return 0;
	}
	mbr structDisco;
	fseek(archivo, 0, SEEK_SET);
	fread(&structDisco, sizeof(mbr), 1, archivo);

	//VERIFICAR LA PARTICION
	i = 0;
	int j = 0;
	int esLogica = 0;
	for (i = 0; i < 4; i++) 
	{
		if (strcasecmp(structDisco.part[i].name, nombre) == 0) {
			break;
		}
		for (j = 0; j < 8; j++) 
		{
			if (strcasecmp(structDisco.part[i].exten[j].name, name) == 0) {
				esLogica = 1;
				break;
			}
			if (esLogica == 1) {
				break;
			}
		}
	}
	if (i == 4 && esLogica == 0) 
	{
		printf("ERROR: No existe el nombre indicado.\n");
		return 0;
	}

	superbloque sb = crearBloque();
	char ajuste;
	int posicion;
	if (esLogica == 1) 
	{
		posicion = structDisco.part[i].exten[j].start;
		ajuste = structDisco.part[i].exten[j].fit;
		fseek(archivo, structDisco.part[i].exten[j].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	} 
	else
	{
		posicion = structDisco.part[i].start;
		ajuste = structDisco.part[i].fit;
		fseek(archivo, structDisco.part[i].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	}

	if (sb.magic == 201700345) 
	{
		fseek(archivo, sb.apuntadorAVD, SEEK_SET);
		apunt ap;
		fread(&ap, sizeof(ap), 1, archivo);

		char crear[100];
		char verificar[100];
		char verificar2[100];
		strcpy(crear, "/home/users.txt");
		int b, a = 0;
		for (a = 0; a < 100; a++) 
		{
			if (crear[a] != '\0') //Hasta que llegue al final
			{ 
				verificar[a] = crear[a];
				verificar2[a] = crear[a];
			} 
			else 
			{
				for (b = a; b >= 0; b--) 
				{
					if (verificar[b] != '/') {
						verificar[b] = '\0';
						verificar2[b] = '\0';
					} else {
						verificar[b] = '\0';
						verificar2[b] = '\0';
						break;
					}
				}
				break;
			}
		}
		char* ruta2;
		strcpy(verificar, verificar2);
		if (verificar[0] == '\0') 
		{
			ruta2 = strtok(crear, "/");
		} 
		else 
		{
			ruta2 = strtok(verificar, "/");
		}
		fclose(archivo);
		int datos;
		ruta2 = strtok(verificar2, "/");
		datos = buscarArchivo(ruta, sb, ap, ruta2, ajuste, posicion, sb.apuntadorAVD);

		if (datos > 0) 
		{
			ruta2 = strtok(crear, "/");
			while ((strstr(ruta2, ".") == 0x0 || strstr(ruta2, ".") == ""
					|| strstr(ruta2, ".") == NULL) && ruta2 != NULL) {
				ruta2 = strtok(NULL, "/");
			}
			if (ruta2 != NULL)
			{
				char mensaje[200];
				strcpy(mensaje, contenidoArchivo(" ", datos, sb, ruta, ruta2));
				printf("* * * * * * * * * * * * * * * * * * * * * *\n%s\n", mensaje);
			}
		} 
		else{
			printf("ERROR: La ruta no existe.\n");
		}
	} 
	else 
	{
		printf("ERROR: La particion no esta formateada.\n");
	}
	return 1;
}

void logout() 
{
	if (boolLogin == 1) //Alguien journaleado
	{ 
		printf("-> Ha cerrado sesion correctamente.\n");
		boolLogin = 0;
		usrLogin = NULL;
	} 
	else 
	{
		printf("ERROR: No existe ningun usuario journaleado.\n");
	}
}

void crearGrupo() 
{
	if (id == NULL || name == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		if (boolLogin == 1) 
		{
			printf("usr =%s*\n", usrLogin);
			if (strcasecmp(usrLogin, "root") == 0) 
			{
				int d = crearGrupoDisco(id, name);
				if (d == 0) {
					printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
				}
			} 
			else 
			{
				printf("ERROR: Solo el usuario ROOT puede realizar cambios.\n");
			}
		} 
		else 
		{
			printf("bool = %d\n", boolLogin);
			printf("ERROR: Debe iniciar sesion como usuario ROOT.\n");
		}

	}
}

int crearGrupoDisco(char* id, char* name) 
{
	int o = obtenerArchivoUsers(id);
	if (o == 1) 
	{
		contadorGrupo += 1;
		FILE* archivoUsuario;
		archivoUsuario = fopen("/home/chay/usersTemporal.txt", "w+");
		fprintf(archivoUsuario, "%d,G,%s\n", contadorGrupo, name);
		fprintf(archivoUsuario, "%s", contenidoUsers);
		fclose(archivoUsuario);

		boolEditar = 1;
		int d = crearArchivoParticion(id, "/home/users.txt", "si", size, "/home/chay/usersTemporal.txt");
		if (d == 0) 
		{
			printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
		}
		return 1;

	} 
	else 
	{
		printf("ERROR: No se pudo agregar el Grupo. Intentelo de nuevo.\n");
		return 0;
	}
}

void eliminarGrupo() 
{
	if (id == NULL || name == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		if (boolLogin == 1) 
		{
			if (strcasecmp(usrLogin, "root") == 0) 
			{
				int d = eliminarGrupoDisco(id, name);
				if (d == 0) {
					printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
				}
			} 
			else 
			{
				printf("ERROR: Solo el usuario ROOT puede realizar cambios.\n");
			}
		} 
		else 
		{
			printf("ERROR: Debe iniciar sesion como usuario ROOT.\n");
		}

	}
}

int eliminarGrupoDisco(char* id, char* usuario) 
{
	int o = obtenerArchivoUsers(id);
	if (o == 1) 
	{
		int con2 = 1;
		char* contenido = NULL;
		FILE* archivoUsuario;
		archivoUsuario = fopen("/home/chay/usersTemporal.txt", "w+");

		char *atributos;
		if (archivoUsuario == NULL) 
		{
			printf("ERROR: No existe el archivo Users.\n");
			return 0;
		} 
		else 
		{
			remove("/home/chay/usersTemporal.txt"); // Eliminamos el archivo

			atributos = contenidoUsers;
			char atr[200];
			strcpy(atr, atributos);
			int j;
			for (j = 0; j < 200; j++) 
			{
				if (atr[j] == '\\') 
				{
					atr[j] = ' ';
				}
			}
			strcpy(atributos, atr);
			char aux[100];
			char *auxInst = NULL;
			strcpy(aux, atributos);
			inst = strtok(atributos, "\n");

			auxInst = inst;
			atrUsuario[con2].atributos = auxInst;
			atribUsuario[con2].atributos = auxInst;
			con2++;
			while (inst != NULL) 
			{
				inst = strtok(NULL, "\n");
				atrUsuario[con2].atributos = inst;
				atribUsuario[con2].atributos = inst;
				con2++;
			}
			int i;
			for (i = 1; i < con2; i++) 
			{
				if (atrUsuario[i].atributos != NULL) 
				{
					int v = eliminarG(atrUsuario[i].atributos, usuario);
					printf("v= %d\n", v);
				}
			}
			fclose(archivoUsuario);
			return 1;
		}
		return 1;

	} 
	else 
	{
		printf("ERROR: No se ha iniciado sesion.\n");
		return 0;
	}
}

void crearUsuario() 
{
	if (id == NULL || name == NULL || password == NULL || grupo == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		if (boolLogin == 1) 
		{
			if (strcasecmp(usrLogin, "root") == 0) 
			{
				int d = crearUsuarioDisco(id, name, password, grupo);
				if (d == 0) 
				{
					printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
				}
			} 
			else 
			{
				printf("ERROR: Solo el usuario ROOT puede realizar cambios.\n");
			}
		} 
		else 
		{
			printf("bool = %d\n", boolLogin);
			printf("ERROR: Debe iniciar sesion como usuario ROOT.\n");
		}
	}
}

int crearUsuarioDisco(char* id, char* usuario, char* password, char* grupo) 
{
	int o = obtenerArchivoUsers(id);
	if (o == 1) 
	{
		contadorUsuario += 1;
		FILE* archivoUsuario;
		archivoUsuario = fopen("/home/chay/usersTemporal.txt", "a+");
		int v = verificarGrupo(grupo);
		if (v > 0) 
		{
			fprintf(archivoUsuario, "\n%d,U,%s,%s,%s", contadorUsuario, grupo, usuario, password);
		}
		fclose(archivoUsuario);

		boolEditar = 1;
		int d = crearArchivoParticion(id, "/home/users.txt", "si", size, "/home/chay/usersTemporal.txt");
		if (d == 0) 
		{
			printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
		}
		return 1;

	} 
	else 
	{
		printf("ERROR: No se pudo agregar el Usuario. Intentelo de nuevo.\n");
		return 0;
	}
}

int verificarGrupo(char* grupo) 
{
	int con2 = 1;
	FILE* archivoUsuario;
	archivoUsuario = fopen("/home/chay/usersTemporal.txt", "r+b");

	char *atributos;
	if (archivoUsuario == NULL) 
	{
		printf("ERROR: No existe el archivo Users.\n");
		return 0;
	} 
	else 
	{
		atributos = contenidoUsers;
		char atr[200];
		strcpy(atr, atributos);
		int j;
		for (j = 0; j < 200; j++) 
		{
			if (atr[j] == '\\') {
				atr[j] = ' ';
			}
		}
		strcpy(atributos, atr);
		char aux[100];
		char *auxInst = NULL;
		strcpy(aux, atributos);
		inst = strtok(atributos, "\n");
		auxInst = inst;
		atrUsuario[con2].atributos = auxInst;
		con2++;
		while (inst != NULL) 
		{
			inst = strtok(NULL, "\n");
			atrUsuario[con2].atributos = inst;
			con2++;
		}
		int i;
		for (i = 1; i < con2; i++) 
		{
			if (atrUsuario[i].atributos != NULL) 
			{
				int v = verificar(atrUsuario[i].atributos, grupo);
				if (v > 0) {
					return 1;
				}
			}
		}
		fclose(archivoUsuario);
		printf("ERROR: No se ha encontrado el grupo.\n");
		return 0;
	}

	return 1;
}

void eliminarUsuario() 
{
	if (id == NULL || usuarioo == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		if (boolLogin == 1) 
		{
			if (strcasecmp(usrLogin, "root") == 0) 
			{
				int d = eliminarUsuarioDisco(id, usuarioo);
				if (d == 0) 
				{
					printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
				}
			} 
			else 
			{
				printf("ERROR: Solo el usuario ROOT puede realizar cambios.\n");
			}
		} 
		else 
		{
			printf("ERROR: Debe iniciar sesion como usuario ROOT.\n");
		}

	}
}

int eliminarUsuarioDisco(char* id, char* usuario) 
{
	int o = obtenerArchivoUsers(id);
	if (o == 1) 
	{
		int con2 = 1;
		char* contenido = NULL;
		FILE* archivoUsuario;
		archivoUsuario = fopen("/home/chay/usersTemporal.txt", "w+");

		char *atributos;
		if (archivoUsuario == NULL) 
		{
			printf("ERROR: No existe el archivo Users.\n");
			return 0;
		} 
		else 
		{
			remove("/home/chay/usersTemporal.txt"); // Eliminamos el archivo

			atributos = contenidoUsers;
			char atr[200];
			strcpy(atr, atributos);
			int j;
			for (j = 0; j < 200; j++) 
			{
				if (atr[j] == '\\') 
				{
					atr[j] = ' ';
				}
			}
			strcpy(atributos, atr);
			char aux[100];
			char *auxInst = NULL;
			strcpy(aux, atributos);
			inst = strtok(atributos, "\n");

			auxInst = inst;
			atrUsuario[con2].atributos = auxInst;
			atribUsuario[con2].atributos = auxInst;
			con2++;
			while (inst != NULL) 
			{
				inst = strtok(NULL, "\n");
				atrUsuario[con2].atributos = inst;
				atribUsuario[con2].atributos = inst;
				con2++;
			}
			int i;
			for (i = 1; i < con2; i++) 
			{
				if (atrUsuario[i].atributos != NULL) 
				{
					int v = eliminarU(atrUsuario[i].atributos, usuario);
					printf("v= %d\n", v);
				}
			}
			fclose(archivoUsuario);
			return 1;
		}
		return 1;

	} 
	else 
	{
		printf("ERROR: No se ha iniciado sesion.\n");
		return 0;
	}

}

int eliminarU(char* atributos, char* usuario) 
{
	FILE* archivoUsuario;
	archivoUsuario = fopen("/home/chay/usersTemporal.txt", "a+b");
	char* c1;
	char* c2;
	char* c3;
	char* c4;

	char* instruc = NULL;
	con = 1;
	char atr[200];
	strcpy(atr, atributos);
	int j;
	for (j = 0; j < 200; j++) 
	{
		if (atr[j] == '\\') {
			atr[j] = ' ';
		}
	}
	strcpy(atributos, atr);
	char aux[100];

	strcpy(aux, atributos);
	instruc = strtok(atributos, ",");
	contadorU = instruc;
	printf("k = %s\n", instruc);
	while (instruc != NULL) 
	{
		instruc = strtok(NULL, ",");
		if (instruc != NULL) 
		{
			printf("j = %s\n", instruc);

			switch (con)
			{
				printf("switch %d\n", con);
				case 1:
					tipoU = instruc;
					c1 = (char *) malloc(1 + strlen(",") + strlen(tipoU));
					strcpy(c1, ",");
					strcat(c1, tipoU);
					break;
				case 2:
					grupoU = instruc;
					c2 = (char *) malloc(1 + strlen(c1) + strlen(",") + strlen(grupoU));
					strcat(c2, c1);
					strcat(c2, ",");
					strcat(c2, grupoU);
					break;
				case 3:
					nombreU = instruc;
					c3 = (char *) malloc(
							1 + strlen(c2) + strlen(",") + strlen(nombreU));
					strcat(c3, c2);
					strcat(c3, ",");
					strcat(c3, nombreU);
					break;
				case 4:
					passU = instruc;
					c4 = (char *) malloc(1 + strlen(c3) + strlen(",") + strlen(passU));
					strcat(c4, c3);
					strcpy(c4, ",");
					strcat(c4, passU);

					break;
			}
			con++;
		}
	}
	if (strcasecmp(tipoU, "U") == 0) 
	{
		if (strcasecmp(nombreU, usuario) == 0) 
		{
			char* conten = (char *) malloc(1 + strlen("0") + strlen(c4));
			strcpy(conten, "0");
			strcat(conten, c4);
			fprintf(archivoUsuario, "%s\n", conten);
			fclose(archivoUsuario);

			if (strcasecmp(contadorU, "0") == 0) 
			{
				printf("-> El usuario ya esta eliminado.\n");
				return 0;
			} 
			else 
			{
				printf("-> El grupo %s se ha eliminado correctamente.\n", nombreU);
				return 1;
			}
		} 
		else 
		{
			char* conten = (char *) malloc(1 + strlen(contadorU) + strlen(c4));
			strcpy(conten, contadorU);
			strcat(conten, c4);
			fprintf(archivoUsuario, "%s\n", conten);
			fclose(archivoUsuario);
		}
	} 
	else 
	{
		char* conten = (char *) malloc(1 + strlen(contadorU) + strlen(c2));
		strcpy(conten, contadorU);
		strcat(conten, c2);
		fprintf(archivoUsuario, "%s\n", conten);
		fclose(archivoUsuario);

	}
	return 0;
}

int obtenerArchivoUsers(char* id) 
{
	char* ruta;
	char* nombre;
	int i = 0;
	for (i = 0; i < 31; i++) 
	{
		if (montar[i].vdID != NULL) 
		{
			if (strcasecmp(montar[i].vdID, id) == 0) 
			{
				if (montar[i].estado == 1)
				{
					ruta = montar[i].path; //%%%
					nombre = montar[i].name;
					break;
				}
			}
		}
	}
	if (i == 31) 
	{
		printf("ERROR: El ID no existe.\n");
		return 0;
	}

	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	if (archivo == NULL) 
	{
		printf("ERROR: No existe el disco.\n");
		return 0;
	}
	mbr structDisco;
	fseek(archivo, 0, SEEK_SET);
	fread(&structDisco, sizeof(mbr), 1, archivo);

	//VERIFICAR LA PARTICION
	i = 0;
	int j = 0;
	int esLogica = 0;
	for (i = 0; i < 4; i++) 
	{
		//printf("N:: %s - %s\n", structDisco.part[i].name, nombre);
		if (strcasecmp(structDisco.part[i].name, nombre) == 0) {
			break;
		}
		for (j = 0; j < 10; j++) 
		{
			if (strcasecmp(structDisco.part[i].exten[j].name, nombre) == 0) {
				esLogica = 1;
				break;
			}
			if (esLogica == 1) {
				break;
			}
		}
	}
	if (i == 4 && esLogica == 0) 
	{
		printf("ERROR: No existe el nombre indicado (ObtenerUsuarios).\n");
		return 0;
	}
	superbloque sb;
	char ajuste;
	int posicion;
	if (esLogica == 1) 
	{
		posicion = structDisco.part[i].exten[j].start;
		ajuste = structDisco.part[i].exten[j].fit;
		fseek(archivo, structDisco.part[i].exten[j].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	} 
	else 
	{
		posicion = structDisco.part[i].start;
		ajuste = structDisco.part[i].fit;
		fseek(archivo, structDisco.part[i].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	}

	if (sb.magic == 201700345) 
	{
		fseek(archivo, sb.apuntadorAVD, SEEK_SET);
		apunt ap;
		fread(&ap, sizeof(ap), 1, archivo);

		char crear[100];
		char verificar[100];
		char verificar2[100];
		strcpy(crear, "/home/users.txt");
		int b, a = 0;
		for (a = 0; a < 100; a++) 
		{
			if (crear[a] != '\0') 
			{ //Hasta que llegue al final
				verificar[a] = crear[a];
				verificar2[a] = crear[a];
			} 
			else 
			{
				for (b = a; b >= 0; b--) 
				{
					if (verificar[b] != '/') {
						verificar[b] = '\0';
						verificar2[b] = '\0';
					} else {
						verificar[b] = '\0';
						verificar2[b] = '\0';
						break;
					}
				}
				break;
			}
		}
		char* ruta2;
		strcpy(verificar, verificar2);
		if (verificar[0] == '\0') 
		{
			ruta2 = strtok(crear, "/");
		} 
		else 
		{
			ruta2 = strtok(verificar, "/");
		}
		fclose(archivo);
		int datos;
		ruta2 = strtok(verificar2, "/");
		datos = buscarArchivo(ruta, sb, ap, ruta2, ajuste, posicion,sb.apuntadorAVD);

		if (datos > 0) 
		{
			ruta2 = strtok(crear, "/");
			while ((strstr(ruta2, ".") == 0x0 || strstr(ruta2, ".") == ""
					|| strstr(ruta2, ".") == NULL) && ruta2 != NULL) {
				ruta2 = strtok(NULL, "/");
			}
			if (ruta2 != NULL)
			{
				char mensaje[200];
				printf("* * * * * *\n");
				char* con = contenidoArchivo(" ", datos, sb, ruta, ruta2);
				strcpy(mensaje, con);
				contenidoUsers = con;
				return 1;
			}
		} 
		else 
		{
			printf("ERROR: La ruta no existe.\n");
		}
	} 
	else 
	{
		printf("ERROR: La particion no esta formateada.\n");
	}
	return 1;
}

void permisoMetodo() 
{
	if (id == NULL || path == NULL || ugo == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		int d = permisoArchivo(id, path, ugo, R);
		if (d == 0) 
		{
			printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
		}
	}
}

int permisoArchivo(char* id, char* path, char* ugo, char* R) 
{
	int r = rangoPermiso(ugo);
	if (r == 0) 
	{
		return 0;
	}
	printf("rango\n");
	char* ruta;
	char* nombre;
	int i = 0;
	for (i = 0; i < 31; i++) 
	{
		if (montar[i].vdID != NULL) 
		{
			if (strcasecmp(montar[i].vdID, id) == 0) 
			{
				if (montar[i].estado == 1) 
				{
					ruta = montar[i].path; //%%%
					nombre = montar[i].name;
					break;
				}
			}
		}
	}
	if (i == 31) 
	{
		printf("ERROR: El ID no existe.\n");
		return 0;
	}

	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	if (archivo == NULL) 
	{
		printf("ERROR: No existe el disco.\n");
		return 0;
	}
	mbr structDisco;
	fseek(archivo, 0, SEEK_SET);
	fread(&structDisco, sizeof(mbr), 1, archivo);

	//VERIFICAR LA PARTICION
	i = 0;
	int j = 0;
	int esLogica = 0;
	for (i = 0; i < 4; i++) 
	{
		if (strcasecmp(structDisco.part[i].name, nombre) == 0) 
		{
			break;
		}
		for (j = 0; j < 8; j++) 
		{
			if (strcasecmp(structDisco.part[i].exten[j].name, nombre) == 0) 
			{
				esLogica = 1;
				break;
			}
			if (esLogica == 1) 
			{
				break;
			}
		}
	}
	if (i == 4 && esLogica == 0) 
	{
		printf("ERROR: No existe el nombre indicado.\n");
		return 0;
	}
	superbloque sb;
	char ajuste;
	int posicion;
	if (esLogica == 1) 
	{
		posicion = structDisco.part[i].exten[j].start;
		ajuste = structDisco.part[i].exten[j].fit;
		fseek(archivo, structDisco.part[i].exten[j].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	} 
	else 
	{
		posicion = structDisco.part[i].start;
		ajuste = structDisco.part[i].fit;
		fseek(archivo, structDisco.part[i].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	}

	if (sb.magic == 201700345) 
	{
		fseek(archivo, sb.apuntadorAVD, SEEK_SET);
		apunt ap;
		fread(&ap, sizeof(ap), 1, archivo);

		char crear[100];
		char verificar[100];
		char verificar2[100];
		strcpy(crear, path);
		int b, a = 0;
		for (a = 0; a < 100; a++) 
		{
			if (crear[a] != '\0') { //Hasta que llegue al final
				verificar[a] = crear[a];
				verificar2[a] = crear[a];
			} 
			else 
			{
				for (b = a; b >= 0; b--) 
				{
					if (verificar[b] != '/') {
						verificar[b] = '\0';
						verificar2[b] = '\0';
					} else {
						verificar[b] = '\0';
						verificar2[b] = '\0';
						break;
					}
				}
				break;
			}
		}
		////////////////////////////////////////
		char* ruta1;
		strcpy(verificar, verificar2);
		if (verificar[0] == '\0') {
			ruta1 = strtok(crear, "/");
		} else {
			ruta1 = strtok(verificar, "/");
		}
		fclose(archivo);
		int datos;
		ruta1 = strtok(verificar2, "/");
		datos = buscarArchivo(ruta, sb, ap, ruta1, ajuste, posicion,sb.apuntadorAVD);
		if (datos > 0) 
		{
			ruta1 = strtok(crear, "/");
			while ((strstr(ruta1, ".") == 0x0 || strstr(ruta1, ".") == ""
					|| strstr(ruta1, ".") == NULL) && ruta1 != NULL) {
				ruta1 = strtok(NULL, "/");
			}
			if (ruta1 != NULL) 
			{
				cambiarPermiso(datos, sb, ruta, ruta1, ugo, 1);
				char contenido[100];
				strcat(contenido, "-name:");
				strcat(contenido, name);
				return 1;
			}
		} 
		else 
		{
			printf("ERROR: No existe la ruta indicada.\n");
			return 0;
		}
	} 
	else 
	{
		printf("ERROR: No se ha formateado la particion.\n");
		return 0;
	}
}

int cambiarPermiso(int posicion, superbloque super, char* ruta, char* nombre, char* permiso, int opcion) 
{
	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	detalle carp;
	fseek(archivo, posicion, SEEK_SET);
	fread(&carp, sizeof(detalle), 1, archivo);
	int i = 0;
	for (i = 0; i < 3; i++) 
	{
		if (carp.content[i].inod > 1)
		{
			if (opcion == 0) 
			{ //Agregar
				if (strcasecmp(carp.content[i].ino.permisos, permiso) == 0) 
				{
					break;
				}
			} 
			else 
			{ //Modificar
				if (strcasecmp(carp.content[i].ino.permisos, permiso) == 0) 
				{
					break;
				}
			}
		}
	}
	if (i < 3) 
	{
		if (opcion == 0) 
		{ //Agregar
			strcpy(carp.content[i].ino.permisos, permiso);
			strcpy(carp.content[i].ino.uid, usrLogin);
		} 
		else 
		{ //Modificar
			strcpy(carp.content[i].ino.permisos, permiso);
		}
		fseek(archivo, posicion, SEEK_SET);
		fwrite(&carp, sizeof(detalle), 1, archivo);
		fclose(archivo);
		printf("-> Se ha cambiado los permisos correctamente.\n");
		return 1;
	} 
	else 
	{
		if (carp.detalle > 0) 
		{
			fclose(archivo);
			return cambiarPermiso(carp.detalle, super, ruta, nombre, permiso,
					opcion);
		} 
		else 
		{
			printf("ERROR: no existe documento");
			return 0;
		}
	}
}

int rangoPermiso(char* ugo) 
{
	char perm[10];
	strcpy(perm, ugo);
	int i;
	for (i = 0; i < 3; i++) 
	{
		if (perm[i] == '0' || perm[i] == '1' || perm[i] == '2' || perm[i] == '3'
				|| perm[i] == '4' || perm[i] == '5' || perm[i] == '6'
				|| perm[i] == '7') {

		} 
		else 
		{
			printf("ERROR: Permiso %c invalido.\n", perm[i]);
			return 0;
		}
	}
	return 1;
}

void renombrar() 
{
	if (id == NULL || path == NULL || name == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		int d = renombrarArchivo(id, path, name);
		if (d == 0) 
		{
			printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
		}
	}
}

int renombrarArchivo(char* id, char* path, char* name) 
{
	char* ruta;
	char* nombre;
	int i = 0;
	for (i = 0; i < 31; i++) 
	{
		if (montar[i].vdID != NULL) 
		{
			if (strcasecmp(montar[i].vdID, id) == 0) 
			{
				if (montar[i].estado == 1) 
				{
					ruta = montar[i].path; //%%%
					nombre = montar[i].name;
					break;
				}
			}
		}
	}
	if (i == 31) 
	{
		printf("ERROR: El ID no existe.\n");
		return 0;
	}

	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	if (archivo == NULL) 
	{
		printf("ERROR: No existe el disco.\n");
		return 0;
	}
	mbr structDisco;
	fseek(archivo, 0, SEEK_SET);
	fread(&structDisco, sizeof(mbr), 1, archivo);

	//VERIFICAR LA PARTICION
	i = 0;
	int j = 0;
	int esLogica = 0;
	for (i = 0; i < 4; i++) 
	{
		if (strcasecmp(structDisco.part[i].name, nombre) == 0) {
			break;
		}
		for (j = 0; j < 8; j++) 
		{
			if (strcasecmp(structDisco.part[i].exten[j].name, nombre) == 0) {
				esLogica = 1;
				break;
			}
			if (esLogica == 1) {
				break;
			}
		}
	}
	if (i == 4 && esLogica == 0) 
	{
		printf("ERROR: No existe el nombre indicado.\n");
		return 0;
	}
	superbloque sb;
	char ajuste;
	int posicion;
	if (esLogica == 1) 
	{
		posicion = structDisco.part[i].exten[j].start;
		ajuste = structDisco.part[i].exten[j].fit;
		fseek(archivo, structDisco.part[i].exten[j].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	} 
	else 
	{
		posicion = structDisco.part[i].start;
		ajuste = structDisco.part[i].fit;
		fseek(archivo, structDisco.part[i].start, SEEK_SET);
		fread(&sb, sizeof(superbloque), 1, archivo);
	}

	if (sb.magic == 201700345) 
	{
		fseek(archivo, sb.apuntadorAVD, SEEK_SET);
		apunt ap;
		fread(&ap, sizeof(ap), 1, archivo);

		char crear[100];
		char verificar[100];
		char verificar2[100];
		strcpy(crear, path);
		int b, a = 0;
		for (a = 0; a < 100; a++) 
		{
			if (crear[a] != '\0') 
			{ //Hasta que llegue al final
				verificar[a] = crear[a];
				verificar2[a] = crear[a];
			} 
			else 
			{
				for (b = a; b >= 0; b--) 
				{
					if (verificar[b] != '/') {
						verificar[b] = '\0';
						verificar2[b] = '\0';
					} else {
						verificar[b] = '\0';
						verificar2[b] = '\0';
						break;
					}
				}
				break;
			}
		}
		////////////////////////////////////////
		char* ruta1;
		strcpy(verificar, verificar2);
		if (verificar[0] == '\0') {
			ruta1 = strtok(crear, "/");
		} else {
			ruta1 = strtok(verificar, "/");
		}
		fclose(archivo);
		int datos;
		ruta1 = strtok(verificar2, "/");

		datos = buscarArchivo(ruta, sb, ap, ruta1, ajuste, posicion,sb.apuntadorAVD);

		if (datos > 0) 
		{
			ruta1 = strtok(crear, "/");
			while ((strstr(ruta1, ".") == 0x0 || strstr(ruta1, ".") == ""
					|| strstr(ruta1, ".") == NULL) && ruta1 != NULL) {
				ruta1 = strtok(NULL, "/");
			}
			if (ruta1 != NULL) 
			{
				cambiarNombre(datos, sb, ruta, ruta1, name);

				char contenido[100];
				strcat(contenido, "-name:");
				strcat(contenido, name);
				return 1;
			}
		} 
		else 
		{
			printf("ERROR: No existe la ruta indicada.\n");
			return 0;
		}
	} 
	else 
	{
		printf("ERROR: No se ha formateado la particion.\n");
		return 0;
	}
}

int cambiarNombre(int posicion, superbloque super, char* ruta, char* nombre,char* nombreNuevo) 
{
	FILE* archivo;
	archivo = fopen(ruta, "rb+");
	detalle carp;
	fseek(archivo, posicion, SEEK_SET);
	fread(&carp, sizeof(detalle), 1, archivo);
	int i = 0;
	for (i = 0; i < 5; i++) 
	{
		if (carp.content[i].inod > 1) {
			if (strcasecmp(carp.content[i].name, nombre) == 0) {
				break;
			}
		}
	}
	if (i < 5) 
	{
		strcpy(carp.content[i].name, nombreNuevo);
		fseek(archivo, posicion, SEEK_SET);
		fwrite(&carp, sizeof(detalle), 1, archivo);
		fclose(archivo);
		printf("-> Se ha cambiado el nombre correctamente.\n");
		return 1;
	} 
	else 
	{
		if (carp.detalle > 0) {
			fclose(archivo);
			return cambiarNombre(carp.detalle, super, ruta, nombre, nombreNuevo);
		} else {
			printf("ERROR: no existe documento");
			return 0;
		}
	}
}

int eliminarG(char* atributos, char* grupo) 
{
	FILE* archivoUsuario;
	archivoUsuario = fopen("/home/chay/usersTemporal.txt", "a+b");
	char* contenido = "";
	char* c1;
	char* c2;
	char* c3;
	char* c4;

	char* instruc = NULL;
	con = 1;
	char atr[200];
	strcpy(atr, atributos);
	int j;
	for (j = 0; j < 200; j++) {
		if (atr[j] == '\\') {
			atr[j] = ' ';
		}
	}
	strcpy(atributos, atr);
	char aux[100];

	strcpy(aux, atributos);
	instruc = strtok(atributos, ",");
	contadorU = instruc;
	printf("k = %s\n", instruc);
	while (instruc != NULL) 
	{
		instruc = strtok(NULL, ",");
		if (instruc != NULL) 
		{
			printf("j = %s\n", instruc);

			switch (con) 
			{
				printf("switch %d\n", con);
				case 1:
					tipoU = instruc;
					c1 = (char *) malloc(1 + strlen(",") + strlen(tipoU));
					strcpy(c1, ",");
					strcat(c1, tipoU);
					break;
				case 2:
					grupoU = instruc;
					c2 = (char *) malloc(1 + strlen(c1) + strlen(",") + strlen(grupoU));
					strcat(c2, c1);
					strcat(c2, ",");
					strcat(c2, grupoU);
					break;
				case 3:
					nombreU = instruc;
					c3 = (char *) malloc(
							1 + strlen(c2) + strlen(",") + strlen(nombreU));
					strcat(c3, c2);
					strcat(c3, ",");
					strcat(c3, nombreU);
					break;
				case 4:
					passU = instruc;
					c4 = (char *) malloc(1 + strlen(c3) + strlen(",") + strlen(passU));
					strcat(c4, c3);
					strcpy(c4, ",");
					strcat(c4, passU);

					break;
			}
			con++;
		}
	}

	if (strcasecmp(tipoU, "G") == 0) 
	{
		if (strcasecmp(grupoU, grupo) == 0) 
		{
			contenido = "0";
			char* conten = (char *) malloc(1 + strlen("0") + strlen(c2));
			strcpy(conten, "0");
			strcat(conten, c2);
			fprintf(archivoUsuario, "%s\n", conten);
			fclose(archivoUsuario);

			if (strcasecmp(contadorU, "0") == 0) 
			{
				printf("-> El usuario ya esta eliminado.\n");
				return 0;
			} 
			else 
			{
				printf("-> El grupo %s se ha eliminado correctamente.\n",
						grupo);
				return 1;
			}
		} 
		else 
		{
			char* conten = (char *) malloc(1 + strlen(contadorU) + strlen(c2));
			strcpy(conten, contadorU);
			strcat(conten, c2);
			fprintf(archivoUsuario, "%s\n", conten);
			fclose(archivoUsuario);
		}
	} 
	else 
	{
		char* conten = (char *) malloc(1 + strlen(contadorU) + strlen(c4));
		strcpy(conten, contadorU);
		strcat(conten, c4);
		fprintf(archivoUsuario, "%s\n", conten);
		fclose(archivoUsuario);
	}
	return 0;
}

char* cambiarEliminado(char* atributos) 
{
	char* contenido = NULL;
	char* instruc = NULL;
	con = 1;
	char atr[200];
	strcpy(atr, atributos);
	int j;
	for (j = 0; j < 200; j++) 
	{
		if (atr[j] == '\\') {
			atr[j] = ' ';
		}
	}
	strcpy(atributos, atr);
	char aux[100];

	strcpy(aux, atributos);
	instruc = strtok(atributos, ",");
	contadorU = instruc;
	strcpy(contenido, "0,");
	while (instruc != NULL) 
	{
		instruc = strtok(NULL, ",");
		//	printf("j = %s\n",instruc);
		if (instruc != NULL) 
		{
			switch (con) 
			{
				case 1:
					tipoU = instruc;
					strcat(contenido, tipoU);
					break;
				case 2:
					grupoU = instruc;
					strcat(contenido, ",");
					strcat(contenido, grupoU);
					break;
				case 3:
					nombreU = instruc;
					strcat(contenido, ",");
					strcat(contenido, nombreU);
					break;
				case 4:
					passU = instruc;
					strcat(contenido, ",");
					strcat(contenido, passU);
					break;
			}
			con++;
		}
	}
	return contenido;
}

int verificar(char* atributos, char* grupo) 
{
	con = 1;
	char* instruc = NULL;
	char atr[200];
	strcpy(atr, atributos);
	int j;
	for (j = 0; j < 200; j++) 
	{
		if (atr[j] == '\\') {
			atr[j] = ' ';
		}
	}
	strcpy(atributos, atr);
	char aux[100];
	strcpy(aux, atributos);
	instruc = strtok(atributos, ",");
	contadorU = instruc;
	while (instruc != NULL) 
	{
		instruc = strtok(NULL, ",");
		if (instruc != NULL) 
		{
			switch (con) 
			{
				case 1:
					tipoU = instruc;
					break;
				case 2:
					grupoU = instruc;
					break;
				case 3:
					nombreU = instruc;
					break;
				case 4:
					passU = instruc;
					break;
			}
			con++;
		}
	}

	/*****************/
	if (strcasecmp(tipoU, "G") == 0) 
	{
		if (strcasecmp(grupoU, grupo) == 0) 
		{
			if (strcasecmp(contadorU, "0") == 0) 
			{
				printf("-> El usuario ha sido eliminado.\n");
				return 0;
			} 
			else 
			{
				printf("-> Se ha encontrado el grupo.\n");
				return 1;
			}
		}
	}
	return 0;
}

void editar() 
{
	if (id == NULL || path == NULL) 
	{
		printf("ERROR: Falta un atributo obligatorio.\n");
	} 
	else 
	{
		boolEditar = 1;
		int d = crearArchivoParticion(id, path, "si", size, cont);
		if (d == 0) 
		{
			printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");
		}
	}
}