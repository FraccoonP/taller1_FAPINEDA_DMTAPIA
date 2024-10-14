#include <iostream>
#include <limits>  // Para limpiar el flujo de entrada
#include "Include/Biblioteca.h"
#include "Include/Libro.h"
#include "Include/Revista.h"

void mostrarMenu() {
    std::cout << "1. Agregar Libro\n";
    std::cout << "2. Agregar Revista\n";
    std::cout << "3. Listar Materiales\n";
    std::cout << "4. Prestar Material\n";
    std::cout << "5. Devolver Material\n";
    std::cout << "6. Salir\n";
}

int main() {
    Biblioteca biblioteca;
    int opcion;

    do {
        mostrarMenu();
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        // Limpiar flujo de entrada después de leer un número
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(opcion) {
            case 1: {
                // Agregar un libro
                std::string nombre, isbn, autor, fecha, resumen;
                std::cout << "Ingrese nombre: "; std::getline(std::cin, nombre);
                std::cout << "Ingrese ISBN: "; std::getline(std::cin, isbn);
                std::cout << "Ingrese autor: "; std::getline(std::cin, autor);
                std::cout << "Ingrese fecha de publicacion: "; std::getline(std::cin, fecha);
                std::cout << "Ingrese resumen: "; std::getline(std::cin, resumen);
                biblioteca.agregarMaterial(nombre, isbn, autor, fecha, resumen, true);
                break;
            }
            case 2: {
                // Agregar una revista
                std::string nombre, isbn, autor, fecha, numeroEdicion;
                std::cout << "Ingrese nombre: "; std::getline(std::cin, nombre);
                std::cout << "Ingrese ISBN: "; std::getline(std::cin, isbn);
                std::cout << "Ingrese autor: "; std::getline(std::cin, autor);
                std::cout << "Ingrese fecha de publicacion: "; std::getline(std::cin, fecha);
                std::cout << "Ingrese numero de edicion: "; std::getline(std::cin, numeroEdicion);
                biblioteca.agregarMaterial(nombre, isbn, autor, fecha, numeroEdicion, false);
                break;
            }
            case 3: {
                // Listar materiales
                biblioteca.listarMateriales();
                break;
            }
            case 4: {
                // Prestar material
                std::string isbn;
                std::cout << "Ingrese ISBN del material a prestar: "; std::getline(std::cin, isbn);
                biblioteca.prestarMaterial(isbn);
                break;
            }
            case 5: {
                // Devolver material
                std::string isbn;
                std::cout << "Ingrese ISBN del material a devolver: "; std::getline(std::cin, isbn);
                biblioteca.devolverMaterial(isbn);
                break;
            }
            case 6: {
                // Salir
                std::cout << "Saliendo del programa...\n";
                break;
            }
            default: {
                std::cout << "Opcion no válida. Intente de nuevo.\n";
                break;
            }
        }
    } while(opcion != 6);

    return 0;
}
