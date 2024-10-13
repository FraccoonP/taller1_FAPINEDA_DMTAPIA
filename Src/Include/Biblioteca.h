#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "MaterialBibliografico.h"

class Biblioteca {
public:
    Biblioteca();
    ~Biblioteca();

    void agregarMaterial(MaterialBibliografico* material);
    void listarMateriales() const;
    bool prestarMaterial(const std::string& isbn);
    bool devolverMaterial(const std::string& isbn);

private:
    //Array con las revistas y libros
    std::vector<MaterialBibliografico*> materiales;
};

