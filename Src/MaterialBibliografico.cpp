#include "Include/MaterialBibliografico.h"
#include <iostream>

MaterialBibliografico::MaterialBibliografico(const std::string& nombre, const std::string& isbn, const std::string& autor, const std::string& fechaPublicacion)
    : nombre(nombre), isbn(isbn), autor(autor), fechaPublicacion(fechaPublicacion), prestado(false) {}

// Método para obtener el ISBN
std::string MaterialBibliografico::getISBN() const {
    return isbn;
}

// Método para verificar si está prestado
bool MaterialBibliografico::estaPrestado() const {
    return prestado;
}

// Método para prestar el material
void MaterialBibliografico::prestar() {
    prestado = true; // Cambia el estado a prestado
}

// Método para devolver el material
void MaterialBibliografico::devolver() {
    prestado = false; // Cambia el estado a disponible
}