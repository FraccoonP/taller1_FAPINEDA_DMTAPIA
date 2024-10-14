#include "Include/Libro.h"
#include <iostream>

Libro::Libro(const std::string& nombre, const std::string& isbn, const std::string& autor, const std::string& fechaPublicacion, const std::string& resumen, bool prestado)
    : MaterialBibliografico(nombre, isbn, autor, fechaPublicacion), resumen(resumen) {
    this->prestado = prestado; // Inicializar el estado prestado
}

// Método para mostrar la información del libro
void Libro::mostrarInformacion() const {
    std::cout << "Título: " << nombre 
              << "\nISBN: " << isbn 
              << "\nAutor: " << autor 
              << "\nFecha de Publicación: " << fechaPublicacion 
              << "\nResumen: " << resumen 
              << "\nEstado: " << (estaPrestado() ? "Prestado" : "Disponible") 
              << "\n----------------------------------------\n";
}