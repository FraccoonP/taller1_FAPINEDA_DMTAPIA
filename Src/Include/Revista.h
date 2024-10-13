#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

class Revista : public MaterialBibliografico {
private:
    int numeroEdicion;

public:
    Revista(const std::string& nombre, const std::string& isbn, const std::string& autor, const std::string& fechaPublicacion, int numeroEdicion);
    virtual void mostrarInformacion() const override;
};