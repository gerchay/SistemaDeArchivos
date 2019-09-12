#ifndef ACCIONES_H_
#define ACCIONES_H_

#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include <time.h>
#include "estructuras.h"

void atributoDisco(char* coman);
void crearDisco();
int  crearArchivoBinario(char* size, char* unit, char* path);
void limpiarVariables();
void metodoPrueba();
int  eliminarDisco();
void adminParticion();
int  crearParticion(char* path,char* name,char* size,char* unit,char* type,char* fit);
int  agregarParticion(char* add,char* unit,char* path,char* name);
int  eliminarParticion(char* delete,char* path,char* name);
void montarP();
int  montarParticion(char* path, char* name);
void desmontar();
int  desmontarParticion(char* id);
int  mm(char*pa,char*name);
int  miMontar(char *path, char *name);
char *letraDisco(int varLetra);
int aleatorio();
void script();
int ejecutarScript(char *path);
void atributoExec(char* coman);
char *numeroMontar(int num);

int boolExec;
mount montar[50];

#endif /* ACCIONES_H_ */
