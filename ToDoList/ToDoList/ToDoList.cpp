#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Tarea {
    string descripcion;
    bool completada;
};

void mostrarMenu() {
    cout << "==== Lista de Tareas ====" << endl;
    cout << "1. Agregar tarea" << endl;
    cout << "2. Ver tareas" << endl;
    cout << "3. Completar tarea" << endl;
    cout << "4. Salir" << endl;
    cout << "=========================" << endl;
    cout << "Elige una opcion: ";
}

void agregarTarea(vector<Tarea>& tareas) {
    Tarea nuevaTarea;
    cout << "Ingresa la descripcion de la tarea: ";
    cin.ignore();  // Para limpiar el buffer de entrada
    getline(cin, nuevaTarea.descripcion);
    nuevaTarea.completada = false;
    tareas.push_back(nuevaTarea);
    cout << "Tarea agregada!" << endl;
}

void verTareas(const vector<Tarea>& tareas) {
    cout << "=== Tus tareas ===" << endl;
    if (tareas.empty()) {
        cout << "No hay tareas pendientes." << endl;
    }
    else {
        for (size_t i = 0; i < tareas.size(); ++i) {
            cout << i + 1 << ". " << tareas[i].descripcion
                << (tareas[i].completada ? " [Completada]" : "") << endl;
        }
    }
}

void completarTarea(vector<Tarea>& tareas) {
    int indice;
    cout << "Ingresa el numero de la tarea a completar: ";
    cin >> indice;

    if (indice > 0 && indice <= static_cast<int>(tareas.size())) {
        tareas[indice - 1].completada = true;
        cout << "Tarea completada!" << endl;
    }
    else {
        cout << "Numero de tarea no valido." << endl;
    }
}

int main() {
    vector<Tarea> tareas;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            agregarTarea(tareas);
            break;
        case 2:
            verTareas(tareas);
            break;
        case 3:
            completarTarea(tareas);
            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no válida. Intenta de nuevo." << endl;
        }

        cout << endl;
    } while (opcion != 4);

    return 0;
}
