#include <stdio.h>
#include <string.h>

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

void guardarCSV(Alumno *a, int tam)
{
    FILE *archivo = fopen("alumnos.csv", "w");
    if (archivo == NULL) { printf("Error al crear el archivo.\n"); return; }
    for (int i = 0; i < tam; i++)
    {
        fprintf(archivo, "%s;%s;%s;%d;%d\n", a[i].nombre, a[i].direccion.callePrincipal,
                a[i].direccion.calleSecundaria, a[i].direccion.numeroCasa, a[i].edad);
    }
    fclose(archivo);
    printf("Archivo alumnos.csv generado correctamente.\n");
}

void leerCSV()
{
    FILE *archivo = fopen("alumnos.csv", "r");
    if (archivo == NULL) { printf("Error al abrir el archivo.\n"); return; }
    Alumno alumno;
    printf("Datos obtenidos del archivo alumnos.csv:\n");
    while (fscanf(archivo, "%49[^;];%49[^;];%49[^;];%d;%d\n", alumno.nombre,
                  alumno.direccion.callePrincipal, alumno.direccion.calleSecundaria,
                  &alumno.direccion.numeroCasa, &alumno.edad) == 5)
    {
        printf("Nombre: %s\n", alumno.nombre);
        printf("Edad: %d\n", alumno.edad);
        printf("Direccion: %s %d %s\n", alumno.direccion.callePrincipal,
               alumno.direccion.numeroCasa, alumno.direccion.calleSecundaria);
        printf("----------------------------------------\n");
    }
    fclose(archivo);
}

void buscarAlumno(char *nombreBuscado)
{
    FILE *archivo = fopen("alumnos.csv", "r");
    if (archivo == NULL) { printf("Error al abrir el archivo.\n"); return; }

    Alumno alumno;
    int encontrado = 0;
    while (fscanf(archivo, "%49[^;];%49[^;];%49[^;];%d;%d\n", alumno.nombre,
                  alumno.direccion.callePrincipal, alumno.direccion.calleSecundaria,
                  &alumno.direccion.numeroCasa, &alumno.edad) == 5)
    {
        if (strcmp(alumno.nombre, nombreBuscado) == 0)
        {
            printf("Registro encontrado \n");
            printf("Nombre: %s\n", alumno.nombre);
            printf("Edad: %d\n", alumno.edad);
            printf("Direccion: %s %d %s\n", alumno.direccion.callePrincipal,
                   alumno.direccion.numeroCasa, alumno.direccion.calleSecundaria);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) printf("No existe el nombre buscado\n");
    fclose(archivo);
}