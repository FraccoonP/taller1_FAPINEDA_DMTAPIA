#include "Libro.h"
#include <iostream>

Libro::Libro(const std::string& nombre, const std::string& isbn, const std::string& autor, const std::string& fechaPublicacion, const std::string& resumen)
    : MaterialBibliografico(nombre, isbn, autor, fechaPublicacion), resumen(resumen) {}

void Libro::mostrarInformacion() const {
    std::cout << "Libro: " << nombre << "\n"
              << "ISBN: " << isbn << "\n"
              << "Autor: " << autor << "\n"
              << "Fecha de Publicación: " << fechaPublicacion << "\n"
              << "Resumen: " << resumen << "\n"
              << (prestado ? "Estado: Prestado\n" : "Estado: Disponible\n")
              << "----------------------------------------\n";
}

