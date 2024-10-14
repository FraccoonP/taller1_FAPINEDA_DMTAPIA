#pragma once
#include <string>
#include <iostream>
#include "MaterialBibliografico.h"

class Libro : public MaterialBibliografico {
private:
    std::string resumen;

public:
    Libro(const std::string& nombre, const std::string& isbn, const std::string& autor, const std::string& fechaPublicacion, const std::string& resumen, bool prestado = false);

    // Implementar el método virtual puro
    bool estaPrestado() const override { return prestado; }

    void mostrarInformacion() const override;
};