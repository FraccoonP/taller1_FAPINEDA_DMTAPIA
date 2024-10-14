#include "Include/Biblioteca.h"
#include "Include/MaterialBibliografico.h"
#include "Include/Libro.h"
#include "Include/Revista.h"
#include <fstream>
#include <iostream>

Biblioteca::Biblioteca() {}

Biblioteca::~Biblioteca() {
    // Liberar memoria de los materiales bibliográficos almacenados
    for (MaterialBibliografico* material : biblioteca) {
        delete material;
    }
}

int Biblioteca::contarMaterialesEnArchivo() const {
    std::ifstream archivo("materialesbiblio.txt");
    std::string linea;
    int contador = 0;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            if (!linea.empty()) {
                contador++;
            }
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo materialesbiblio.txt" << std::endl;
    }
    return contador;
}

void Biblioteca::agregarMaterial(const std::string& nombre, const std::string& isbn, const std::string& autor, const std::string& fecha, const std::string& resuOrEd, bool libro) {
    int numMaterialesArchivo = contarMaterialesEnArchivo();
    
    if (numMaterialesArchivo < 10) {
        MaterialBibliografico* nuevoMaterial;
        
        if (libro) {
            // Para Libro, el parámetro resuOrEd es el resumen (un std::string)
            nuevoMaterial = new Libro(nombre, isbn, autor, fecha, resuOrEd, false); // Coloca "false" en la última posición
        } else {
            // Para Revista, el parámetro resuOrEd es el número de edición (un int)
            int numeroEdicion = std::stoi(resuOrEd); // Convierte resuOrEd a un entero
            nuevoMaterial = new Revista(nombre, isbn, autor, fecha, numeroEdicion, false); // Coloca "false" en la última posición
        }

        // Almacenar en el array de la biblioteca
        biblioteca[numMaterialesArchivo] = nuevoMaterial;

        // Guardar el material en el archivo
        std::ofstream archivo("materialesbiblio.txt", std::ios::app);  // Abrimos el archivo en modo append
        if (archivo.is_open()) {
            archivo << nombre << "," << isbn << "," << autor << "," << fecha << ",false," << resuOrEd << "\n";
            archivo.close();
        } else {
            std::cerr << "No se pudo abrir el archivo materialesbiblio.txt" << std::endl;
        }
    } else {
        std::cout << "La biblioteca está llena. No se puede agregar más material.\n";
    }
}

void Biblioteca::listarMateriales() const {
    if (contarMaterialesEnArchivo() == 0) { // Verificar el conteo en lugar de usar empty()
        std::cout << "No hay materiales en la biblioteca.\n";
        return;
    }
    for (const MaterialBibliografico* material : biblioteca) {
        if (material != nullptr) {
            material->mostrarInformacion();
        }
    }
}

bool Biblioteca::prestarMaterial(const std::string& isbn) {
    for (MaterialBibliografico* material : biblioteca) {
        if (material->getISBN() == isbn) {
            if (material->estaPrestado()) {
                std::cout << "El material ya está prestado.\n";
                return false;
            } else {
                material->prestar();
                std::cout << "Material prestado con éxito.\n";
                return true;
            }
        }
    }
    std::cout << "Material con ISBN " << isbn << " no encontrado.\n";
    return false;
}

bool Biblioteca::devolverMaterial(const std::string& isbn) {
    for (MaterialBibliografico* material : biblioteca) {
        if (material->getISBN() == isbn) {
            if (!material->estaPrestado()) {
                std::cout << "El material no estaba prestado.\n";
                return false;
            } else {
                material->devolver();
                std::cout << "Material devuelto con éxito.\n";
                return true;
            }
        }
    }
    std::cout << "Material con ISBN " << isbn << " no encontrado.\n";
    return false;
}