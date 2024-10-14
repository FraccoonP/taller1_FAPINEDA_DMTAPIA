#pragma once
#include <string>
#include <iostream>
#include "MaterialBibliografico.h"

class Revista : public MaterialBibliografico {
private:
    int numeroEdicion;

public:
    Revista(const std::string& nombre, const std::string& isbn, const std::string& autor, const std::string& fechaPublicacion, int numeroEdicion, bool prestado = false);

    // Implementar el método virtual puro
    bool estaPrestado() const override { return prestado; }

    void mostrarInformacion() const override;
};