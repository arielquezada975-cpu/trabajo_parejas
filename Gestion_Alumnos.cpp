/*
 * Proyecto: Gestion de Alumnos
 * Trabajo en parejas - UDLA
 */
#include <stdio.h>
#include <string.h>
#include "alumno.h"

int main()
{
    Alumno alumnos[2];
    char nombreBuscado[50];

    strcpy(alumnos[0].nombre, "Juan");
    strcpy(alumnos[0].direccion.callePrincipal, "Av. Prensa");
    strcpy(alumnos[0].direccion.calleSecundaria, "Florida");
    alumnos[0].direccion.numeroCasa = 123;
    alumnos[0].edad = 20;

    strcpy(alumnos[1].nombre, "Ana");
    strcpy(alumnos[1].direccion.callePrincipal, "Av.Galo Plaza");
    strcpy(alumnos[1].direccion.calleSecundaria, "Inca");
    alumnos[1].direccion.numeroCasa = 543;
    alumnos[1].edad = 21;

    printf("Ingrese el nombre a buscar: ");
    fgets(nombreBuscado, 50, stdin);
    nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';

    buscarAlumno(nombreBuscado);

    return 0;
}
