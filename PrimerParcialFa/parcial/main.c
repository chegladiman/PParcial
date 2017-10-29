#include <stdio.h>
#include <stdlib.h>
#define CANT 20
#include "lib.h"

int main()
{
    char seguir='s';
    int opcion=0;

    Ecliente clientes[CANT];

    Ealquiler alquiler[CANT];

    inicializarClientes(clientes);


    while(seguir=='s')
    {
        printf("Bienvenido! Que desea hacer?\n\n\n");
        printf("1- Alta de cliente\n");
        printf("2- Modificar  cliente\n");
        printf("3- Baja de cliente\n");
        printf("4- Nuevo alquiler\n");
        printf("5- Finalizar alquiler\n");
        printf("6- Informar datos\n");
        printf("7- Salir\n\n");

        printf("Opcion seleccionada: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarCliente(clientes);
                break;
            case 2:
                modificarCliente(clientes);
                break;
            case 3:
                borrarCliente(clientes);
                break;
            case 4:
                nuevoAlquiler(alquiler);
                break;
            case 5:
                finalizarAlquiler(alquiler);

                break;
            case 6:
                mostrarMenuInformes(clientes, alquiler);
                break;
            case 7:
                seguir = 'n';
                break;

        }
    }

    return 0;
}
