#pragma once
#include <iostream>
#include <string>
#include "MaterialBibliografico.h"

class Usuario {
private:
    std::string nombre;
    int id;
    MaterialBibliografico* materialesPrestados[5];
    int numPrestamos;

public:
    Usuario(const std::string& nombre, int id);

    // Declaración de los métodos
    void prestarMaterial(MaterialBibliografico* material);
    void devolverMaterial(MaterialBibliografico* material);
    void mostrarMaterialesPrestados() const;
};