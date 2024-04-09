#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Función para ingresar los datos de las personas y almacenarlos en el archivo
void ingresarDatos() {
    string nombre;
    int edad;

    ofstream archivo("datos.txt", ios::app); // Abre el archivo en modo de añadir al final

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    cout << "Ingrese el nombre (o escriba 'fin' para terminar): ";
    while (cin >> nombre && nombre != "fin") {
        cout << "Ingrese la edad de " << nombre << ": ";
        cin >> edad;

        archivo << nombre << " " << edad << endl;

        cout << "Ingrese otro nombre (o escriba 'fin' para terminar): ";
    }

    archivo.close();
}

// Función para leer los datos del archivo y mostrarlos en la pantalla
void mostrarDatos() {
    string nombre;
    int edad;

    ifstream archivo("datos.txt");

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    cout << "Datos almacenados en el archivo:" << endl;
    while (archivo >> nombre >> edad) {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }

    archivo.close();
}

int main() {
    ingresarDatos();
    mostrarDatos();

    return 0;
}
