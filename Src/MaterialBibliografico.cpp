#include "Include/MaterialBibliografico.h"
#include <iostream>

MaterialBibliografico::MaterialBibliografico(const std::string& nombre, const std::string& isbn, const std::string& autor, const std::string& fechaPublicacion)
    : nombre(nombre), isbn(isbn), autor(autor), fechaPublicacion(fechaPublicacion), prestado(false) {}

std::string MaterialBibliografico::getISBN() const {
    return isbn;
}

bool MaterialBibliografico::estaPrestado() const {
    return prestado;
}

void MaterialBibliografico::prestar() {
    prestado = true;
}

void MaterialBibliografico::devolver() {
    prestado = false;
}
