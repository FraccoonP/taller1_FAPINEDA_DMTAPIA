#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

class Libro : public MaterialBibliografico {
private:
    std::string resumen;

public:
    Libro(const std::string& nombre, const std::string& isbn, const std::string& autor, const std::string& fechaPublicacion, const std::string& resumen);
    void mostrarInformacion() const override;
};

