#include "Biblioteca.h"
#include <iostream>

Biblioteca::Biblioteca() {}

Biblioteca::~Biblioteca() {
    // Liberar memoria de los materiales bibliográficos almacenados
    for (MaterialBibliografico* material : materiales) {
        delete material;
    }
}

void Biblioteca::agregarMaterial(MaterialBibliografico* material) {
    materiales.push_back(material);
    std::cout << "Material agregado con éxito.\n";
}

void Biblioteca::listarMateriales() const {
    if (materiales.empty()) {
        std::cout << "No hay materiales en la biblioteca.\n";
        return;
    }
    for (const MaterialBibliografico* material : materiales) {
        material->mostrarInformacion();
    }
}

bool Biblioteca::prestarMaterial(const std::string& isbn) {
    for (MaterialBibliografico* material : materiales) {
        if (material->getISBN() == isbn) {
            if (material->estaPrestado()) {
                std::cout << "El material ya está prestado.\n";
                return false;
            } else {
                material->prestar();
                std::cout << "Material prestado con éxito.\n";
                return true;
            }
        }
    }
    std::cout << "Material con ISBN " << isbn << " no encontrado.\n";
    return false;
}

bool Biblioteca::devolverMaterial(const std::string& isbn) {
    for (MaterialBibliografico* material : materiales) {
        if (material->getISBN() == isbn) {
            if (!material->estaPrestado()) {
                std::cout << "El material no estaba prestado.\n";
                return false;
            } else {
                material->devolver();
                std::cout << "Material devuelto con éxito.\n";
                return true;
            }
        }
    }
    std::cout << "Material con ISBN " << isbn << " no encontrado.\n";
    return false;
}
