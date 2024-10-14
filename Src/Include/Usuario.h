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

    std::string getNombre() const;
    int getId() const;

    void setNombre(const std::string& nombre);
    void setId(int id);

    // Método para guardar la información del usuario en un archivo de texto
    void guardarUsuario(std::ofstream& out) const;

    // Método para cargar la información del usuario desde un archivo de texto
    static Usuario cargarUsuario(std::ifstream& in);

    // Declaración de los métodos
    void prestarMaterial(MaterialBibliografico* material);
    void devolverMaterial(MaterialBibliografico* material);
    void mostrarMaterialesPrestados() const;
};