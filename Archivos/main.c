#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "pila.h"

typedef struct
{
    char nombre[30];
    int edad;
    int documento;

} alumno;

void agregarElemento(alumno a);
void mostrarAlumnos();
Pila apilarAlumnosMayores();
int conteoAlumnosMayoresA();
void mostrarNombresRango(menor, mayor);
int buscarMayor();
void mostrarAlumnoMayor(mayor);

int main()
{
    int num = 0;
    printf("Ingresa el caso a ejecutar \n");
    printf("Ingrese 1 para cargar elementos \n");
    printf("Ingrese 2 para mostrar elementos \n");
    printf("Ingrese 3 para apilar las edades mayores \n");
    printf("Ingrese 4 para contar las edades mayores a un numero elegido \n");
    printf("Ingrese 5 para mostrar los nombres de un rango especifico \n");
    printf("Ingrese 6 para mostrar los datos del alumno mayor \n");
    scanf("%i", &num);

    switch(num)
    {
        alumno a;
        int i = 0;
        int numUser = 0;
        int menor = 0, mayor = 0, mayor2 = 0;
    case 1:
        agregarElemento(a);
        break;
    case 2:
        mostrarAlumnos();
        break;

    case 3:
        apilarAlumnosMayores();
        break;
    case 4:
        printf("Ingrese la edad para buscar los mayores a esa edad \n");
        scanf("%i", &numUser);
        i = conteoAlumnosMayoresA(numUser);
        printf("La cantidad de alumnos mayores a la edad elegida es: %i", i);
        break;

    case 5:
        printf("Ingrese el rango menor \n");
        scanf("%i", &menor);
        printf("Ingrese el rango mayor \n");
        scanf("%i", &mayor);
        mostrarNombresRango(menor, mayor);
        break;
    case 6:
        mayor2 = buscarMayor();
        mostrarAlumnoMayor(mayor2);
        break;
    }

    return 0;
}

void agregarElemento(alumno a)
{
    FILE* buffer = fopen("alumnos.bin", "ab");
    char flag = 's';
    if(buffer != NULL)
    {
        while(flag == 's')
        {

            printf("Ingrese el nombre del alumno \n");
            fflush(stdin);
            gets(a.nombre);

            printf("Ingrese la edad del alumno \n");
            scanf("%d", &a.edad);

            printf("Ingrese el documento del alumno \n");
            scanf("%d", &a.documento);

            printf("Desea seguir cargando datos? (s/n) \n");
            fflush(stdin);
            scanf("%c", &flag);

            fwrite (&a, sizeof(alumno), 1, buffer);
        }
    }
    fclose(buffer);
}

void mostrarAlumno(alumno a)
{

    printf("Nombre del Alumno: %s \n", a.nombre);

    printf("Edad del alumno: %d \n", a.edad);

    printf("Documento del Alumno: %d \n", a.documento);

    printf("---------------------------- \n");
}

void mostrarAlumnos()
{
    FILE *buffer;
    alumno a;
    buffer = fopen("alumnos.bin", "rb");
    int i = 0;

    if(buffer)
    {
        while(!feof(buffer))
        {
            fread(&a, sizeof(alumno), 1, buffer);
            if(!feof(buffer))
            {
                printf("Registro numero: %d \n", i++);
                mostrarAlumno(a);
            }
        }
    }
    fclose(buffer);
}

Pila apilarAlumnosMayores()
{
    FILE *buffer;
    alumno a;
    buffer = fopen("alumnos.bin", "rb");

    Pila alumnosP;
    inicpila(&alumnosP);

    if(buffer)
    {
        while(fread(&a, sizeof(alumno), 1, buffer) >0)
        {
            if(a.edad>17)
            {
                apilar(&alumnosP, a.edad);
            }


        }
    }
    mostrar(&alumnosP);
    fclose(buffer);
    return alumnosP;
}

int conteoAlumnosMayoresA(numUser)
{
    FILE *buffer;
    alumno a;
    buffer = fopen("alumnos.bin", "rb");
    int i = 0;

    if(buffer)
    {
        while(fread(&a, sizeof(alumno), 1, buffer)>0)
        {
            if(a.edad>numUser)
            {
                i++;
            }
        }
    }
    fclose(buffer);
    return i;
}

void mostrarAlumnoNombre(alumno a)
{
    printf("Nombre del Alumno: %s \n", a.nombre);
}

void mostrarNombresRango(menor, mayor)
{
    FILE *buffer;
    alumno a;
    buffer = fopen("alumnos.bin", "rb");

    if(buffer)
    {
        while(fread(&a, sizeof(alumno), 1, buffer)>0)
        {
            if(a.edad >= menor && a.edad <= mayor)
            {
                mostrarAlumnoNombre(a);
            }
        }
    }
    fclose(buffer);
}

int buscarMayor()
{
    FILE *buffer;
    alumno a;
    buffer = fopen("alumnos.bin", "rb");
    int mayor2 = 0;

    if(buffer)
    {
        while(fread(&a, sizeof(alumno), 1, buffer) > 0)
        {
            if(a.edad > mayor2)
            {
                mayor2 = a.edad;
            }
        }
    }
    return mayor2;
}

    void mostrarAlumnoMayor(mayor2)
    {
        FILE *buffer;
        alumno a;
        buffer = fopen("alumnos.bin", "rb");
        if(buffer)
        {
            while(fread(&a, sizeof(alumno), 1, buffer) > 0)
            {
                if(mayor2 == a.edad)
                {
                    mostrarAlumno(a);
                }
            }
        }
    }





