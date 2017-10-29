#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define CANT 20
#include "lib.h"






int inicializarClientes(Ecliente clientes[])
{
    int i;
    for (i=0; i<CANT; i++)
    {
        clientes[i].ID=0;
    }
    return 0;
}

void agregarCliente(Ecliente clientes[])
{
    int i,j, nuevoId;

    for(i=0; i<CANT; i++)
    {
        if(clientes[i].ID==0)
        {
            system("cls");

            printf("Ingresar nombre: ");
            fflush(stdin);
            scanf("%[^\n]", clientes[i].nombre);
            system("cls");

            printf("\nIngresar apellido:");
            fflush(stdin);
            scanf("%[^\n]", clientes[i].apellido);
            system("cls");

            printf("\nIngresar DNI:");
            fflush(stdin);
            char dni[8] = "";
            scanf("%[^\n]", dni);
            clientes[i].dni = atol(dni);
            system("cls");

            int maxId = 0;
            for(j=0; j<CANT; j++)
            {
                if(clientes[j].ID > maxId)
                    maxId = clientes[j].ID;
            }
            clientes[i].ID = maxId + 1;
            nuevoId = clientes[i].ID;
            break;
        }
    }
    printf("\nCreado cliente Id: %d", nuevoId);
}

void borrarCliente(Ecliente clientes[])
{
    int i;
    char opcion;
    int idIngresado;
    int flag=0;
    printf("Ingrese ID del cliente: ");
    scanf("%d", &idIngresado);

    for(i=0; i<CANT; i++)
    {
        if(idIngresado==clientes[i].ID)
        {
            printf("\nID: %d , Seguro desea dar de baja?", idIngresado);
            opcion=getche();
            if(opcion=='s')
            {
                clientes[i].ID=0;
                printf("Cliente eliminado");
            }
            else
            {
                printf("Operacion cancelada");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("ID inexistente");
        getch();
    }
}

void modificarCliente(Ecliente clientes[])
{
    int idIngresado, i;

    printf("Ingrese ID del cliente a modificar: ");
    scanf("%d",&idIngresado);
    for( i=0; i<CANT; i++)
    {
        if(idIngresado==clientes[i].ID)
        {

            printf("Ingresar nombre: ");
            fflush(stdin);
            scanf("%[^\n]", clientes[i].nombre);
            system("cls");

            printf("\nIngresar apellido:");
            fflush(stdin);
            scanf("%[^\n]", clientes[i].apellido);
            system("cls");

        }
    }
}

void nuevoAlquiler(Ealquiler alquiler[])
{
    int IDCliente, cantDias, i, j;
    char IdEquipo, IdOperador[1];

    printf("ID del cliente: ");
    fflush(stdin);
    scanf("%[^\n]",IDCliente);

    for( i=0; i<CANT; i++)
    {
        if(alquiler[i].IDCliente == 0)
        {
            alquiler[i].IDCliente = atoi(IDCliente);

            printf("Equipo [1: Amoladora][2: Mezcladora][3: Taladro]");
            fflush(stdin);
            scanf("%c",IdEquipo);
            alquiler[i].equipo = atoi(IdEquipo);

            printf("Tiempo estimado (en dias): ");
            fflush(stdin);
            scanf("%[^\n]",cantDias);
            alquiler[i].tiempo_estimado = atoi(cantDias);

            printf("Operador [1: Pepo][2: Alberto][3: Mario]");
            fflush(stdin);
            scanf("%[^\n]",IdOperador);
            alquiler[i].operador = atoi(IdOperador);

            int maxId = 0;
            for(j=0; j<CANT; j++)
            {
                if(alquiler[j].IDAlquiler > maxId)
                    maxId = alquiler[j].IDAlquiler;
            }
            alquiler[i].IDAlquiler = maxId + 1;

            strncpy(alquiler[i].estado, "ALQUILADO", 50);

            printf("El equipo esta ALQUILADO. Numero de alquiler: %d", alquiler[j].IDAlquiler);

            break;
        }
    }
}

void finalizarAlquiler(Ealquiler alquiler[])
{
    int IDAlquiler, IdEquipo, tiempoReal, i;

    printf("Ingresar numero de alquiler: ");
    scanf("%[^\n]",IDAlquiler);

    for(i = 0; i < CANT; i++)
    {
        if(alquiler[i].IDAlquiler == IDAlquiler)
        {
            printf("Ingresar tiempo de alquiler en dias: ");
            scanf("%[^\n]",tiempoReal);
            alquiler[i].tiempo_real = atoi(tiempoReal);

            strncpy(alquiler[i].estado, "FINALIZADO", 50);

            printf("El alquiler ha finalizado.");
            break;
        }
    }
}

void mostrarMenuInformes(Ecliente clientes[], Ealquiler alquiler[])
{
    int opcion;

    printf("1- informarPromedios\n");
    printf("2- Cliente con mas alquileres\n");
    printf("3- Equipos mas alquilados\n");

    printf("Opcion seleccionada: ");
    scanf("%d",&opcion);
    switch (opcion){
        case 1:
            informarPromedios(clientes, alquiler);
            break;

        case 2:
            clienteConMasAlquileres(clientes, alquiler);

            break;

        case 3:
            equiposMasAlquilados(alquiler);
            break;

        default:

            break;
    }
}

void informarPromedios(Ecliente clientes[], Ealquiler alquiler[])
{
    int i, cantAlquileresFinalizados, tiempoRealTotal;

    for(i = 0; i <CANT; i++)
    {
        if(alquiler[i].estado == "FINALIZADO")
        {
            cantAlquileresFinalizados++;
            tiempoRealTotal += alquiler[i].tiempo_real;
        }
    }
    int promedio = tiempoRealTotal / cantAlquileresFinalizados;

    printf("El promedio es: %d", promedio);

}

void clienteConMasAlquileres(Ecliente clientes[], Ealquiler alquiler[])
{
    int idClienteConMasAlquileres, cantAlquileresMaximos, cantAlquileres, i,j;

    for(i = 0; i < CANT; i++)
    {
        cantAlquileres = 0;

        for(j = 0; j < CANT; j++)
        {
            if(alquiler[j].IDCliente == clientes[i].ID)
            {
                cantAlquileres++;
            }
        }

        if(cantAlquileres > cantAlquileresMaximos)
        {
            cantAlquileresMaximos = cantAlquileres;
            idClienteConMasAlquileres = i;
        }
    }

    printf("Cliente con mas alquileres: %s %s", clientes[idClienteConMasAlquileres].nombre, clientes[idClienteConMasAlquileres].apellido);

}


void equiposMasAlquilados(Ealquiler alquiler[])
{
    int i, j, h, maxCantidadAlquileres;
    int equiposCantVecesAlquilados[2] = {0,0,0};
    int equiposMasAlquilados[2] = {2,3,0};

    for(i = 0; i<CANT ; i++)
    {
        if(alquiler[i].equipo == 1)
            equiposCantVecesAlquilados[0] = equiposCantVecesAlquilados[0] + 1;
        else if(alquiler[i].equipo == 2)
            equiposCantVecesAlquilados[1] = equiposCantVecesAlquilados[1] + 1;
        else if(alquiler[i].equipo == 3)
            equiposCantVecesAlquilados[2] = equiposCantVecesAlquilados[2] + 1;
    }

    for (j = 0; j < 2; j++)
    {
        if(equiposCantVecesAlquilados[j] >= maxCantidadAlquileres)
        {
            maxCantidadAlquileres = equiposCantVecesAlquilados[j];

            //limpio array de equipos mas veces alquilados, manteniendo vivos los productos que fueron igual de veces alquilados
            for(h = 0; h < 2; h++){
                if(equiposMasAlquilados[h] != maxCantidadAlquileres)
                {
                    equiposCantVecesAlquilados[h] = 0;
                }
            }

            //agrego al producto al primer espacio libre
            for(h = 0; h < 2; h++)
            {
                if(equiposCantVecesAlquilados[h] == 0)
                {
                    equiposCantVecesAlquilados[h] = j;
                    break;
                }
            }
        }
    }

    printf("Equipos con mas alquileres: ");
    for(i = 0; i < 2; i++)
    {
        if(equiposMasAlquilados[i] != 0){
            switch(equiposMasAlquilados[i])
            {
                case 1:
                    printf("Amoladora /t");
                    break;
                case 2:
                    printf("Mezcladora /t");
                    break;
                case 3:
                    printf("Taladro /t");
                    break;
            }
        }
    }
}






