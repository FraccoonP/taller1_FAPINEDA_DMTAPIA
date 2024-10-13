#include "Revista.h"
#include <iostream>

Revista::Revista(const std::string& nombre, const std::string& isbn, const std::string& autor, const std::string& fechaPublicacion, int numeroEdicion)
    : MaterialBibliografico(nombre, isbn, autor, fechaPublicacion), numeroEdicion(numeroEdicion) {}

void Revista::mostrarInformacion() const {
    std::cout << "Revista: " << nombre << "\n"
              << "ISBN: " << isbn << "\n"
              << "Autor: " << autor << "\n"
              << "Fecha de Publicación: " << fechaPublicacion << "\n"
              << "Número de Edición: " << numeroEdicion << "\n"
              << (prestado ? "Estado: Prestado\n" : "Estado: Disponible\n")
              << "----------------------------------------\n";
}
