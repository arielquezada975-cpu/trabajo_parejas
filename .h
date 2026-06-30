#ifndef ALUMNO_H
#define ALUMNO_H

typedef struct
{
    char callePrincipal[50];
    char calleSecundaria[50];
    int numeroCasa;
} Direccion;

typedef struct
{
    char nombre[50];
    Direccion direccion;
    int edad;
} Alumno;

void guardarCSV(Alumno *a, int tam);
void leerCSV();
void buscarAlumno(char *nombreBuscado);

#endif