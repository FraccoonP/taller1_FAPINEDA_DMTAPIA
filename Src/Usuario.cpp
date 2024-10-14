#include "Include/Usuario.h"
#include <iostream>
#include <fstream>

Usuario::Usuario(const std::string& nombre, int id)
    : nombre(nombre), id(id) {}

std::string Usuario::getNombre() const {
    return nombre;
}

int Usuario::getId() const {
    return id;
}

void Usuario::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Usuario::setId(int id) {
    this->id = id;
}

void Usuario::guardarUsuario(std::ofstream& out) const {
    out << nombre << '\n' << id << '\n';  // Guardar el nombre y el ID como int
}

Usuario Usuario::cargarUsuario(std::ifstream& in) {
    std::string nombre;
    int id;
    std::getline(in, nombre);  // Leer el nombre
    in >> id;                  // Leer el ID como int
    in.ignore();               // Ignorar el salto de línea después del ID
    return Usuario(nombre, id);
}

// Implementación del método prestarMaterial
void Usuario::prestarMaterial(MaterialBibliografico* material) {
    if (numPrestamos < 5 && !material->estaPrestado()) {
        materialesPrestados[numPrestamos++] = material;
        material->prestar();
        std::cout << "Material prestado correctamente.\n";
    } else {
        std::cout << "No se puede prestar más material o material ya prestado.\n";
    }
}

// Implementación del método devolverMaterial
void Usuario::devolverMaterial(MaterialBibliografico* material) {
    for (int i = 0; i < numPrestamos; ++i) {
        if (materialesPrestados[i] == material) {
            materialesPrestados[i]->devolver();
            // Mover los elementos para llenar el hueco dejado por el material devuelto
            for (int j = i; j < numPrestamos - 1; ++j) {
                materialesPrestados[j] = materialesPrestados[j + 1];
            }
            materialesPrestados[--numPrestamos] = nullptr;
            std::cout << "Material devuelto correctamente.\n";
            return;
        }
    }
    std::cout << "El material no pertenece a este usuario.\n";
}

// Implementación del método mostrarMaterialesPrestados
void Usuario::mostrarMaterialesPrestados() const {
    std::cout << "Materiales prestados por " << nombre << ":\n";
    for (int i = 0; i < numPrestamos; ++i) {
        if (materialesPrestados[i] != nullptr) {
            materialesPrestados[i]->mostrarInformacion();
        }
    }
}
