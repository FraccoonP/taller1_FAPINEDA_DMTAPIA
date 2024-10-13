#include <iostream>
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
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch(opcion) {
            case 1: {
                // Agregar un libro
                std::string nombre, isbn, autor, fecha, resumen;
                std::cout << "Ingrese nombre: "; std::cin >> nombre;
                std::cout << "Ingrese ISBN: "; std::cin >> isbn;
                std::cout << "Ingrese autor: "; std::cin >> autor;
                std::cout << "Ingrese fecha de publicación: "; std::cin >> fecha;
                std::cout << "Ingrese resumen: "; std::cin >> resumen;
                biblioteca.agregarMaterial(new Libro(nombre, isbn, autor, fecha, resumen));
                break;
            }
            case 2: {
                // Agregar una revista
                std::string nombre, isbn, autor, fecha;
                int numeroEdicion;
                std::cout << "Ingrese nombre: "; std::cin >> nombre;
                std::cout << "Ingrese ISBN: "; std::cin >> isbn;
                std::cout << "Ingrese autor: "; std::cin >> autor;
                std::cout << "Ingrese fecha de publicación: "; std::cin >> fecha;
                std::cout << "Ingrese número de edición: "; std::cin >> numeroEdicion;
                biblioteca.agregarMaterial(new Revista(nombre, isbn, autor, fecha, numeroEdicion));
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
                std::cout << "Ingrese ISBN del material a prestar: "; std::cin >> isbn;
                biblioteca.prestarMaterial(isbn);
                break;
            }
            case 5: {
                // Devolver material
                std::string isbn;
                std::cout << "Ingrese ISBN del material a devolver: "; std::cin >> isbn;
                biblioteca.devolverMaterial(isbn);
                break;
            }
            case 6: {
                // Salir
                std::cout << "Saliendo del programa...\n";
                break;
            }
            default: {
                std::cout << "Opción no válida. Intente de nuevo.\n";
                break;
            }
        }
    } while(opcion != 6);

    return 0;
}
