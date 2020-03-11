#ifndef ACCIONES_H_
#define ACCIONES_H_

#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include <time.h>
#include "estructuras.h"

// =========================================== PRIMERA FASE =========================
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

// =========================================== SEGUNDA FASE =========================
void crearArchivo();
int crearArchivoParticion(char* id, char* path, char* p, char* size, char* cont);
int agregarContenido(int posicion, superbloque super, char* ruta, char* name,char ajuste, char* contenido, int size, mbr structDisco);
int crearCarpeta(char* ruta, superbloque super, apunt apun, char*path, char*p,char ajuste, int inicio, int atras);
void mostrarContenido();
int mostrarContenidoArchivo(char* id, char* filen);
void remover();
int removerArchivo(char* id, char* path, int rf);
int eliminarArchivo(int posicion, superbloque super, char* ruta, char* name);
int eliminarCarpeta(char* ruta, superbloque super, char* path, int posicion);
int bitacora(int posicion, int operacion, char*nombre, char*contenido,superbloque super, char* ruta, char* vdID);
int buscarArchivo(char* ruta, superbloque super, apunt ap, char* path,char ajuste, int inicio, int atras);
int primerAjuste(int bloque, char* ruta, int inicio, int archivo);
int mejorAjuste(int bloque, char* ruta, int inicio, int archivo);
int peorAjuste(int bloque, char *aux4, int inicio, int archivo);
void copiar();
int copiarArchivo(char* id, char* path, char* dest, char* iddest);
int copiarCarpeta(char* ruta, superbloque super, char* path, int posicion,char* dest, char* iddest);
int copiarRaizCarpeta(char* ruta, superbloque super, int posicion, char* iddest,char* dest);
int crearCopia(char* id, char* path, char* p);
int copiarRaizArchivo(char* ruta, superbloque super, int posicion, char* iddest,char* dest);
char* contenidoArchivo(char* mensaje, int posicion, superbloque super,char* ruta, char* name);
void renombrar();
int renombrarArchivo(char* id, char* path, char* name);
int cambiarNombre(int posicion, superbloque super, char* ruta, char* nombre,char* nombreNuevo);
void encontrar();
int encontrarArchivo(char* id, char* path, char* name, char* perm, char* user);
char* buscarCarpeta(char* ruta, char* path, superbloque super, int posicion,char* msj, int espacio);
int buscarRaizCarpeta(char* ruta, superbloque super, int posicion,char* mensaje, int espacio);
int buscarRaizArchivo(char* ruta, superbloque super, int posicion, char*mensaje,int espacio);
void crearDirectorio();
int crearDirectorioArchivo(char* id, char* path, char* p);
void editar();
void mover();
int moverArchivo(char* id, char* path, char* dest, char* iddest);
superbloque crearBloque();
void listar();
int listarArchivo(char* id, char* path, char* name);
void imprimirLista();
void journaling(char *ruta, int posicion, superbloque sb, int tipoOp, char *path, char *contenido, char *id, int tipo);
char *generarPath(char *path);
char *concatenar(char* var1, char* var2);
char *obtenerNombre(char *path);
char *obtenerRuta(char *id);
void loss();
void recovery();
void copiarFichero(char *origen, char *destino);
char *obtenerPadre(char *ruta);
void logg();
int iniciarSesion(char* usuario, char* password) ;

// =========================================== VARIABLES GLOBALES =========================
int boolExec;
mount montar[50];
list listaArchivo[10];
#endif /* ACCIONES_H_ */
