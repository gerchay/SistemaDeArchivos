#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "reportes.h"
#include "estructuras.h"
#include "acciones.h"
#include <string.h>
#include "time.h"
#include "math.h"
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>

//mount montar[50];

int reporteMBR(char* id, char* name, char* path)
{
	//VERIFICA SI EL EL ID EXISTE
	char* direcc;
	int boolIgual = 0;
	int i=0;
	for(i=0;i<51;i++)
	{
		if(montar[i].vdID!=NULL)
		{
			if(strcasecmp(montar[i].vdID,id)==0)
			{
				printf("-> Se ha encontrado una particion con el id.\n");
				boolIgual =1;
			}
			if(boolIgual==1)
			{
				if(montar[i].estado==1)
				{
					direcc= montar[i].path;
					break;
				}
			}
		}
	}
	 
	if(boolIgual==0){ printf("ERROR: El ID no existe.\n"); return 0; }
	printf("path =%s\n",direcc);

	//VERIFICA SI EL ARCHIVO EXISTE
	FILE* archivo;
	archivo = fopen(direcc,"rb+");
	if(archivo== NULL){ printf("ERROR: No existe el archivo.\n"); return 0; }
	mbr structDisco;
	fseek(archivo,0,SEEK_SET);
	fread(&structDisco,sizeof(mbr),1,archivo);

	//CREA LA CARPETA SI NO EXISTE
	char direccion[200];
	char auxDirecc[200];
	for(i=0;i<200;i++){ auxDirecc[i] ='\0'; }
	strcpy(direccion, path);
	char nombre[50];
	int n=0;
	for(i=0;i<200;i++)
	{
		nombre[n] = direccion[i];
	    if(direccion[i]=='/')
		{
	    	auxDirecc[i]=direccion[i];
	        char *aux7= (char*)malloc(150);
	        strcpy(aux7,"mkdir ");
	        strcat(aux7,auxDirecc);
	        system(aux7);
	        free(aux7);
	        n=0;
	    }
	    auxDirecc[i]=direccion[i];
	    n++;
	    if(direccion[i]=='\0'){ break; }
	}

	char d[200];
	strcpy(d,auxDirecc);

	char* ext=NULL;
	ext = &d;
	char* nam =NULL;
	nam= &d;
	int boolExt=0;
	char* auxName;
	char* extImg;
	ext = strtok(nam,".");
	auxName=ext;

	while(ext!=NULL)
	{
		ext = strtok(NULL,".");
		//printf("ex =%s\n",ext);
		extImg = ext;
		if(ext!=NULL)
		{
			if(strcmp(ext,"jpg")==0 || strcmp(ext,"png")==0 || strcmp(ext,"pdf")==0){ boolExt=1; break; }
		}
	}
	if(boolExt==0){ printf("ERROR: La imagen no tiene extension.\n"); return 0; }

	char *e =".dot";
	char *dot= (char *) malloc(1 + strlen(auxName)+ strlen(e) );
	strcpy(dot, auxName);
	strcat(dot, e);
	char fecha[100] ="fecha";
	struct tm *timeinfo;
	timeinfo = localtime(&structDisco.fecha);
	strftime(fecha,100,"%c",timeinfo);


	//CREA EL REPORTE
	FILE* report;
	report = fopen(dot,"w+");
	fprintf(report,"digraph mbr{\n");
	fprintf(report,"rankdir = LR;\n");
	fprintf(report,"node [shape = record, fontsize=12,fontname=\"%s\", style=filled ,fillcolor=lightsalmon, height = 1.2]; \n","UBUNTU");
	fprintf(report,"Particion[label=\"");


	fprintf(report,"{%s}\n"
			"|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
			"|{NOMBRE | VALOR}\n"
			"|{MBR_tamanio:| %d }\n"
			"|{ MBR_fecha:| %s }\n"
			"|{ MBR_disk_signature: | %d }\n"
			"",direcc,structDisco.size,fecha,structDisco.sign);
	int a=0;
	for(a=0;a<4;a++)
	{
	    if(structDisco.part[a].status=='1')
		{
	        fprintf(report,"\n|{PART_status_%d: | %c}\n"
	        		"| { PART_type_%d: | %c} \n"
	        		"|{ PART_fit_%d : | %c}\n"
	        		"| { PART_start_%d :| %d}\n"
	        		"|{ PART_size_%d:| %d }\n"
	        		"|{ PART_name_%d :| %s}\n "
	        		"",a,structDisco.part[a].status,a,
					structDisco.part[a].type,a,
					structDisco.part[a].fit,a,
					structDisco.part[a].start,a,
					structDisco.part[a].size,a,
					structDisco.part[a].name);
	    }
	}

	fprintf(report,"\"];\n");

	for(a=0;a<4;a++)
	{
	    if(structDisco.part[a].type=='E' || structDisco.part[a].type=='e' )
		{
	    	int i=0;
	    	int ii=0;
	       	for(i=0; i<8; i++)
			{
	         	if(structDisco.part[a].exten[i].status=='1')
				{
	             	ii++;
	             	fprintf(report,"Particion%d[label=\"",ii);
	             	fprintf(report,"{EBR_%d}\n"
	            		 "|{PART_status_%d: | %c}"
	            		 "|{ PART_fit_%d : | %c}"
	            		 "| { PART_start_%d :| %d}"
	            		 "|{ PART_size_%d:| %d }"
	            		 "|{ PART_next_%d:| %d }"
	            		 "|{ PART_name_%d :| %s} ",ii,ii,
						 structDisco.part[a].exten[i].status,ii,
						 structDisco.part[a].exten[i].fit,ii,
						 structDisco.part[a].exten[i].start,ii,
						 structDisco.part[a].exten[i].size,ii,
						 structDisco.part[a].exten[i].next,ii,
						 structDisco.part[a].exten[i].name);

	        		fprintf(report,"\"];\n");
	         	}
	       	}
	   	}
	}

	fprintf(report,"}\n");
	fclose(report);

	char *r1 = "dot -Tjpg ";
	char *r2 = " -o ";
	char *ruta= (char*)malloc(1+strlen(r1)+strlen(dot)+strlen(r2)+strlen(path));
	strcpy(ruta, r1);
	strcat(ruta, dot);
	strcat(ruta, r2);
	strcat(ruta, path);
	printf("RUTA= %s\n",ruta);

	char consola[300];
	strcpy(consola,"");
	strcat(consola, ruta);
	printf("%s\n",consola);
	system(consola);
	printf("-> Se creo el reporte MBR correctamente.\n");
	/*char consola2[300];
	strcpy(consola2,"");
	strcat(consola2, "xdg-open ");
	strcat(consola2, auxDirecc);
	system(consola2);*/

	return 1;
}

int reporteDISK(char* id,char* name, char* path)
{
	//VERIFICA SI EL EL ID EXISTE
	char* direcc;
	int boolIgual = 0;
	int i=0;
	for(i=0;i<51;i++)
	{
		if(montar[i].vdID!=NULL)
		{
			if(strcasecmp(montar[i].vdID,id)==0)
			{
				//printf("-> Se ha encontrado una particion con el id.\n");
				boolIgual =1;
			}
			if(boolIgual==1)
			{
				if(montar[i].estado==1)
				{
					direcc= montar[i].path;
					break;
				}
			}
		}
	}
		 
	if(boolIgual==0)
	{
		printf("ERROR: El ID no existe.\n");
		return 0;
	}
	//printf("path =%s\n",direcc);

	//VERIFICA SI EL ARCHIVO EXISTE
	FILE* archivo;
	archivo = fopen(direcc,"rb+");
	if(archivo== NULL){ printf("ERROR: No existe el archivo.\n"); return 0; }
	
	mbr structDisco;
	fseek(archivo,0,SEEK_SET);
	fread(&structDisco,sizeof(mbr),1,archivo);

	//CREA LA CARPETA SI NO EXISTE
	char direccion[200];
	char auxDirecc[200];
	for(i=0;i<200;i++){ auxDirecc[i] ='\0'; }
	strcpy(direccion, path);
	char nombre[50];
	int n=0;
	for(i=0;i<200;i++)
	{
		nombre[n] = direccion[i];
		if(direccion[i]=='/')
		{
		    auxDirecc[i]=direccion[i];
		    char *aux7= (char*)malloc(150);
		    strcpy(aux7,"mkdir ");
		    strcat(aux7,auxDirecc);
		    system(aux7);
		    free(aux7);
		    n=0;
		}
		auxDirecc[i]=direccion[i];
		n++;
		if(direccion[i]=='\0'){ break; }
	}

	char d[200];
	strcpy(d,auxDirecc);
	char* ext=NULL;
	ext = &d;
	char* nam =NULL;
	nam= &d;
	int boolExt=0;
	char* auxName;
	char* extImg;
	ext = strtok(nam,".");
	auxName=ext;

	while(ext!=NULL)
	{
		ext = strtok(NULL,".");
		extImg = ext;
		if(ext!=NULL)
		{
			if(strcmp(ext,"jpg")==0 || strcmp(ext,"png")==0|| strcmp(ext,"pdf")==0){ boolExt=1; break; }
		}
	}
	if(boolExt==0){ printf("ERROR: La imagen no tiene extension.\n"); return 0; }

	//printf("auxName= %s\n",auxName);
	char *e =".dot";
	char *dot= (char *) malloc(1 + strlen(auxName)+ strlen(e) );
	strcpy(dot, auxName);
	strcat(dot, e);
	//printf("dd=%s\n",dot);

	char * nameReport = "Reporte Disk";
	//CREA EL REPORTE
	int par=0;
	FILE* report = fopen(dot,"w+");
	fprintf(report, "digraph particiones{\nrankdir=TB;\ncolor=blue;\n node[shape = record, color = cyan];\nsubgraph cluster{\n");
	fprintf(report,"label=\"%s\"",nameReport);
	//printf("dd=%s\n",dot);
	fprintf(report,"\nnode8[label=\"MBR");
	int reportlibre=0;
	int conteyo=0;
	for(conteyo=0;conteyo<4;conteyo++)
	{
		if(structDisco.part[conteyo].status == '1')
		{
			reportlibre = reportlibre + structDisco.part[conteyo].size;
		}
	}
	int j=3;
	for(j=0;j<4;j++)
	{
		if(structDisco.part[j].status == '1' && (structDisco.part[j].type == 'P'|| structDisco.part[j].type=='p'))
		{
			float porcentaje = ((float)structDisco.part[j].size/(float)structDisco.size)*(float)100;
	        fprintf(report,"|Primaria \\nporcentaje: %d ",(int)porcentaje);
			//fprintf(report,porcentaje);
	        par++;
	    }
		else if(structDisco.part[j].status =='0' ) //&& structDisco.part[j].size!=0){
		{
			float porcentaje = ((((float)structDisco.size)-((float)reportlibre))/(float)structDisco.size)*(float)100;
	        fprintf(report,"|Libre \\nporcentaje: %d ",(int)porcentaje);
	        par++;
	    }
		else if(structDisco.part[j].status == '1' && (structDisco.part[j].type == 'E'|| structDisco.part[j].type=='e'))
		{
			int reportLog=0;
			int i=0;
			for(i=0;i<20;i++)
			{
				if(structDisco.part[j].exten[i].status=='1') {reportLog = reportLog + structDisco.part[j].exten[i].size;}
				
			}
			float porcentajeEXTRA = ((float)structDisco.part[j].size/(float)structDisco.size)*(float)100;
	        fprintf(report,"|{Extendida \\nporcentaje: %d |{", (int)porcentajeEXTRA);
	        for(i=0;i<20;i++)
			{
				float porcentaje = ((float)structDisco.part[j].exten[i].size/(float)structDisco.part[j].size)*(float)100;
	        	if(structDisco.part[j].exten[i].status=='1') { fprintf(report,"EBR|Logica \\nporcentaje: %d |", (int)porcentaje); }
				//else if(structDisco.part[j].exten[i].status=='0' && structDisco.part[j].exten[i].size!=0){ fprintf(report,"EBR|Libre \\nporcentaje: %d |", porcentaje); }
	        }
			float porcentaje = ((((float)structDisco.part[j].size)-((float)reportLog))/(float)structDisco.part[j].size)*(float)100;
	        fprintf(report,"Libre \\nporcentaje: %d |", (int)porcentaje);
			par++;
	        fprintf(report,"}}");
	    }

	}
	fprintf(report,"\"];\n\t}\n}");
	fclose(report);

	char *r1 = "dot -Tjpg ";
	char *r2 = " -o ";
	char *ruta= (char*)malloc(1+strlen(r1)+strlen(dot)+strlen(r2)+strlen(path));
	strcpy(ruta, r1);
	strcat(ruta, dot);
	strcat(ruta, r2);
	strcat(ruta, path);
	//printf("RUTA= %s\n",ruta);

	char consola[300];
	strcpy(consola,"");
	strcat(consola, ruta);
	printf("%s\n",consola);
	system(consola);
	printf("\n-> Se creo el reporte DISK correctamente.\n");
	/*char consola2[300];
	strcpy(consola2,"");
	strcat(consola2, "xdg-open ");
	strcat(consola2, auxDirecc);
	system(consola2);*/
	return 1;
}