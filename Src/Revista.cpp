#include "Include/Revista.h"
#include <iostream>

Revista::Revista(const std::string& nombre, const std::string& isbn, const std::string& autor, const std::string& fechaPublicacion, int numeroEdicion, bool prestado)
    : MaterialBibliografico(nombre, isbn, autor, fechaPublicacion), numeroEdicion(numeroEdicion) {
    this->prestado = prestado; // Inicializar el estado prestado
}

// Método para mostrar la información de la revista
void Revista::mostrarInformacion() const {
    std::cout << "Título: " << nombre 
              << "\nISBN: " << isbn 
              << "\nAutor: " << autor 
              << "\nFecha de Publicación: " << fechaPublicacion 
              << "\nNúmero de Edición: " << numeroEdicion 
              << "\nEstado: " << (estaPrestado() ? "Prestado" : "Disponible") 
              << "\n----------------------------------------\n";
}