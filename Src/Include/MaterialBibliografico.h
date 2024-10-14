#pragma once
#include <iostream>
#include <string>

class MaterialBibliografico {
protected:
    std::string nombre;
    std::string isbn;
    std::string autor;
    std::string fechaPublicacion;
    bool prestado; // Estado del material

public:
    MaterialBibliografico(const std::string& nombre, const std::string& isbn, const std::string& autor, const std::string& fechaPublicacion);
    virtual ~MaterialBibliografico() {}

    std::string getISBN() const;
    virtual bool estaPrestado() const = 0; // Método virtual puro
    virtual void prestar(); // Método para marcar como prestado
    virtual void devolver(); // Método para marcar como disponible
    virtual void mostrarInformacion() const = 0; // Método virtual puro
};