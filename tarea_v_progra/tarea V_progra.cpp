#include <iostream>
#include <string>
//Carlos Daniel Catro Caceres
using namespace std;


struct Nodo {
    string carne;
    string nombreCompleto;
    string carrera;
    Nodo* siguiente;
};


void insertarInicio(Nodo*& head) {
    Nodo* nuevo = new Nodo();

    cout << "Ingrese carne: ";
    getline(cin, nuevo->carne);

    cout << "Ingrese nombre completo: ";
    getline(cin, nuevo->nombreCompleto);

    cout << "Ingrese carrera: ";
    getline(cin, nuevo->carrera);

    nuevo->siguiente = head;
    head = nuevo;

    cout << "Estudiante agregado al inicio.\n";
}


void insertarFinal(Nodo*& head) {
    Nodo* nuevo = new Nodo();

    cout << "Ingrese carne: ";
    getline(cin, nuevo->carne);

    cout << "Ingrese nombre completo: ";
    getline(cin, nuevo->nombreCompleto);

    cout << "Ingrese carrera: ";
    getline(cin, nuevo->carrera);

    nuevo->siguiente = NULL;

    if (head == NULL) {
        head = nuevo;
    } else {
        Nodo* aux = head;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }

    cout << "Estudiante agregado al final.\n";
}


void mostrar(Nodo* head) {
    if (head == NULL) {
        cout << "La lista esta vacia.\n";
        return;
    }

    Nodo* aux = head;

    while (aux != NULL) {
        cout << "Carné: " << aux->carne << endl;
        cout << "Nombre: " << aux->nombreCompleto << endl;
        cout << "Carrera: " << aux->carrera << endl;
        cout << "-----------------------------\n";

        aux = aux->siguiente;
    }
}

void buscar(Nodo* head) {
    string carneBuscar;
    cout << "Ingrese carne a buscar: ";
    getline(cin, carneBuscar);

    Nodo* aux = head;

    while (aux != NULL) {
        if (aux->carne == carneBuscar) {
            cout << "\nEstudiante encontrado:\n";
            cout << "Nombre: " << aux->nombreCompleto << endl;
            cout << "Carrera: " << aux->carrera << endl;
            return;
        }
        aux = aux->siguiente;
    }

    cout << "Estudiante no encontrado.\n";
}

void eliminar(Nodo*& head) {
    string carneEliminar;
    cout << "Ingrese carne a eliminar: ";
    getline(cin, carneEliminar);

    Nodo* actual = head;
    Nodo* anterior = NULL;

    while (actual != NULL && actual->carne != carneEliminar) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        cout << "Estudiante no encontrado.\n";
        return;
    }

    if (anterior == NULL) {
        head = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    delete actual;
    cout << "Estudiante eliminado correctamente.\n";
}

int main() {
    Nodo* head = NULL;
    int opcion;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Insertar estudiante al inicio\n";
        cout << "2. Insertar estudiante al final\n";
        cout << "3. Mostrar estudiantes\n";
        cout << "4. Buscar estudiante\n";
        cout << "5. Eliminar estudiante\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1:
                insertarInicio(head);
                break;
            case 2:
                insertarFinal(head);
                break;
            case 3:
                mostrar(head);
                break;
            case 4:
                buscar(head);
                break;
            case 5:
                eliminar(head);
                break;
            case 6:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 6);

    return 0;
}