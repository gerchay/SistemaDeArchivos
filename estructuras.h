#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_

#include <time.h>

//BLOQUE DE ARCHIVOS

typedef struct APUNTADOR { //av
	char pointer[16]; //name
	int subDirectorios[6];
	int directorio;
	int apuntador;
} apunt;

typedef struct DATOS { //bloque de archivos
	char data[64]; //content
} datos;

typedef struct INODO {
	int noInodo;
	int size;
	int noAsignados; //numero de bloques asignados ///****
	int bloques[15];
	int indirecto; //apuntador indirecto por si ocupa mas de 4 //****
	//int contador;
	int uid;
	int gid;
	time_t fechaLeido;
	time_t fechaCreado;
	time_t fechaModificado;
	char type;
	char permisos[3];
} inodo;

//BLOQUE DE CARPETAS

typedef struct ARCHIVO { //archivo //content
	char name[12];
	int inod;
	inodo ino;
} archivo;

typedef struct CARPETA { //*detalle
	archivo content[5]; //16  //archivo
	int detalle; //Si ya no caben apunta a otro detalle
} detalle;


typedef struct JOURNAL {
	int operacion;
	int tipo; //0 archivo / 1 directorio
	char nombre[50];
	char path[200];
	char contenido[64];
	time_t fecha;
	char vdID[5];
	char padre[50];
	int tamanio;
} journal;

typedef struct DETALLE_SP { //Cola para realizar el mount
	int arbolVirtualCount; //
	int detalleDirectorioCount;
	int apuntadorBitArbolDirectorio; //
	int apuntador; //********
	int apuntadorBitDetalleDirectorio; //
	int apuntadorDetalleDirectorio; //
	int apuntadorBitmapInodo; //
	int contadorJ;
	int contadorU;
	int contadorP;
} detalleSB;

typedef struct JOURN {
	journal bitacora;
} journ;

typedef struct USERS {
	char id[5];
	char tipo[2];
	char grupo[30];
	char clave[30];
	char usuario[30];
} user;

typedef struct USUARIOS {
	user usuario;
} usuario;

typedef struct PERM {
	char grupo[30]; // ?? Saber
	char permiso[5];
	char usuario[30];
	char ruta[50];
} perm;


typedef struct PERMISOS {
	perm permiso;
} permiso;

typedef struct SUPERBLOQUE {
	int inodosCount; //
	int bloquesCount; //
	int freeBloquesCount; //
	int freeInodosCount; //
	time_t FechaMontado; //
	time_t FechaDesmontado; //
	int mountCount; //
	int apuntadorBitTablaInodo;	//
	int apuntadorTablaInodo;	//
	int apuntadorBitBloques;	//
	int apuntadorBloques;	//
	int inodoSize; //
	int bloqueSize; //
	int firstFreeBitTablaInodo;	//
	int firstFreeBitBloque;	//
	int magic; //
	int jourfirst; //
	int apuntadorAVD;
	journ j[50];
	detalleSB s;
	usuario user[50];
	permiso perm[50];
} superbloque;

typedef struct LIST {
	char nombre[20];
} list;

typedef struct MONTAR { //Cola para realizar el mount
	char path[70];
	char name[40];
	int var;
	int part;
	char *vdID;
	int estado;
	int uso;
	int loss;
} mount;

typedef struct EBR { //20 maximo
	char status;
	char fit;
	int start;
	int size;
	int auxiliar;
	int next; //Byte en el que esta el sigueinte ebr -1 si no hay
	char name[16];
} ebr;

typedef struct PARTICION {
	char status; //1 activa, 0
	char type;
	char fit; //ajuste
	int start; //en que byte inicia
	int size;
	int auxiliar;
	char name[16];
	ebr exten[20];
} particion;

typedef struct MBR { //Master Boot Record -> Registro de arranque principal
	int size;
	time_t fecha;
	int signature;
	particion part[4];
	char* nameCopy;
} mbr;

typedef struct INO {
	int noInodo;
	int size;
	int noAsignados;
	int apuntadores[15];
	//int apuntador;
	int bloques[15];
} ino;

typedef struct BLO {
	int noBloque;
	int noAsignados;
	//int apuntador;
	int cont;
	archivo datos[5];

} blo;

typedef struct ListaIB {
	ino inodos[50];
	blo bloques[50];
} listaIB;

typedef struct ATRIBUTOS {
	char* atributos;
} atrib;

#endif /* ESTRUCTURAS_H_ */
