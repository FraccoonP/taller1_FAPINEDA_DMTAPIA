#pragma once
#include <string>

class MaterialBibliografico {
protected:
    std::string nombre;
    std::string isbn;
    std::string autor;
    std::string fechaPublicacion;
    bool prestado;

public:
    MaterialBibliografico(const std::string& nombre, const std::string& isbn, const std::string& autor, const std::string& fechaPublicacion);
    virtual ~MaterialBibliografico() {}

    std::string getISBN() const;
    bool estaPrestado() const;
    void prestar();
    void devolver();

    virtual void mostrarInformacion() const = 0;
};
