void buscarAlumno(char *nombreBuscado)
{
    FILE *archivo = fopen("alumnos.csv", "r");
    if (archivo == NULL) { printf("Error al abrir el archivo.\n"); return; }

    if (nombreBuscado == NULL || strlen(nombreBuscado) == 0)
    {
        printf("Debe ingresar un nombre valido.\n");
        fclose(archivo);
        return;
    }

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

