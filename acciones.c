#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "acciones.h"
#include "estructuras.h"
#include <unistd.h>
#include <fcntl.h>

char* size=NULL;
char* unit=NULL;
char* path=NULL;
char* type=NULL;
char* fit=NULL;
char* dele=NULL;
char* name=NULL;
char* add=NULL;
char* id=NULL;
int boolCrearDisco=1;
int raid=0;
int varLetra=0;

boolExec=0;

void atributoDisco(char* coman)
{
	char* token1 = tolower(coman);
    char* com=coman;
    token1=strtok(com,"=");
	if(token1!=NULL)
	{
		//printf(token1);
		//printf("\n");
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
		else
		{
        	printf("ERROR: El atributo \"%s\" es incorrecto.\n",token1);
        }
	}
}

void crearDisco()
{
	boolCrearDisco = 1;
	if(unit==NULL){ unit="m"; }
	if(size==NULL || path==NULL){ printf("ERROR: Falta un atributo obligatorio.\n"); }
	else
	{
		if(size>0)
		{
			int d =crearArchivoBinario(size,unit,path);
			if(d==0){printf("\nSe han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n");}
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
	size=NULL;
	unit=NULL;
	path=NULL;
	type=NULL;
	fit=NULL;
	dele=NULL;
	name=NULL;
	add=NULL;
	id=NULL;
	raid=0;
}

//void metodoPrueba(){ for(int i=0;i<10; i++){ printf("M%d= %s\n",i, montar[i].vdID); } }

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
	//metodoPrueba();
}

int desmontarParticion(char* id)
{
	printf("ID=%s\n",id);
	int i=0;
	for(i=0;i<31; i++)
	{
		if(montar[i].vdID!=NULL)
		{
			//printf("NOT NULL -> %s-%s-\n",montar[i].vdID,id);
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
		if(strcasecmp(name, "mbr")==0 || strcasecmp(name, "MBR")==0 || strcasecmp(name, "mbr\n")==0 || strcasecmp(name, "MBR\n")==0)
		{
			int d =	reporteMBR(id, name, path);
			if(d==0){ printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n"); }
		}
		else if(strcasecmp(name, "disk")==0 || strcasecmp(name, "DISK")==0 || strcasecmp(name, "Disk\n")==0)
		{
			int d =	reporteDISK(id, name, path);
			if(d==0){ printf("Se han encontrado errores en el comando. No se ha podido ejecutar correctamente.\n"); }
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


