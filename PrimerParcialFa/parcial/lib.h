
typedef struct {
    int ID;
    char nombre[50];
    char apellido[51];
    long int dni;

}Ecliente;

typedef struct {
    int IDCliente;
    int equipo;
    int tiempo_estimado;
    char operador;
    int tiempo_real;
    int IDAlquiler;
    char estado[50];
}Ealquiler;



void agregarCliente(Ecliente clientes[]);

int inicializarClientes(Ecliente clientes[]);

void borrarCliente(Ecliente clientes[]);

void modificarCliente(Ecliente clientes[]);

void nuevoAlquiler(Ealquiler alquiler[]);

void finalizarAlquiler(Ealquiler alquiler[]);

void mostrarMenuInformes(Ecliente clientes[], Ealquiler alquiler[]);




