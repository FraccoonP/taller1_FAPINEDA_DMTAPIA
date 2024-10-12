#pragma once
#include <string>
#include "MaterialBibliografico.h"

class Usuario {
private:
    std::string nombre;
    int id;
    MaterialBibliografico* materialesPrestados[5];
    int numPrestamos;

public:
   
    Usuario(const std::string& nombre, int id)
        : nombre(nombre), id(id), numPrestamos(0) {
        for (int i = 0; i < 5; ++i) {
            materialesPrestados[i] = nullptr;
        }
    }

    // Método para prestar material
    void prestarMaterial(MaterialBibliografico* material) {
        if (numPrestamos < 5 && !material->estaPrestado()) {
            materialesPrestados[numPrestamos++] = material;
            material->prestar();
        } else {
            std::cout << "No se puede prestar más material o material ya prestado.\n";
        }
    }

    // Método para devolver material
    void devolverMaterial(MaterialBibliografico* material) {
        for (int i = 0; i < numPrestamos; ++i) {
            if (materialesPrestados[i] == material) {
                materialesPrestados[i]->devolver();
                materialesPrestados[i] = nullptr;
                numPrestamos--;
                std::cout << "Material devuelto correctamente.\n";
                return;
            }
        }
        std::cout << "El material no pertenece a este usuario.\n";
    }

    // Mostrar materiales prestados
    void mostrarMaterialesPrestados() const {
        std::cout << "Materiales prestados por " << nombre << ":\n";
        for (int i = 0; i < numPrestamos; ++i) {
            if (materialesPrestados[i] != nullptr) {
                materialesPrestados[i]->mostrarInformacion();
            }
        }
    }
};