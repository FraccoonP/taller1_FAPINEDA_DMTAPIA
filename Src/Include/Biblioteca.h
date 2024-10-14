#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "MaterialBibliografico.h"

class Biblioteca {
public:
    Biblioteca();
    ~Biblioteca();

    int contarMaterialesEnArchivo() const;
    void agregarMaterial(const std::string& nombre,const std::string& isbn,const std::string& autor, const std::string& fecha,const std::string& resuOrEd, bool libro);
    void listarMateriales() const;
    bool prestarMaterial(const std::string& isbn);
    bool devolverMaterial(const std::string& isbn);

private:
    //Array con las revistas y libros
    MaterialBibliografico* biblioteca[10];
};

