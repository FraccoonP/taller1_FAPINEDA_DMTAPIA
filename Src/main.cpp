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
    std::cout << "6. Gestionar Usuarios\n";
    std::cout << "7. Salir\n";
}

void mostrarMenuUsuarios() {
    std::cout << "\n--- Gestión de Usuarios ---\n";
    std::cout << "1. Crear Usuario\n";
    std::cout << "2. Buscar Usuario\n";
    std::cout << "3. Eliminar Usuario\n";
    std::cout << "4. Listar Usuarios\n";
    std::cout << "5. Salir del menú de usuarios\n";
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

         // Cargar usuarios desde el archivo
        biblioteca.cargarUsuarios("usuarios.txt");

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
                 do {
                    mostrarMenuUsuarios();
                     std::cout << "Seleccione una opción: ";
                    std::cin >> opcion;

                    switch (opcion) {
                        case 1: {  // Crear un nuevo usuario
                        std::string nombre;
                        int id;
                        std::cout << "Ingrese el nombre del usuario: ";
                        std::cin >> nombre;
                        std::cout << "Ingrese el ID del usuario: ";
                        std::cin >> id;
                        Usuario nuevoUsuario(nombre, id);
                        biblioteca.agregarUsuario(nuevoUsuario);
                        break;
                        }
                        case 2: {  // Buscar usuario
                        int id;
                        std::cout << "Ingrese el ID del usuario a buscar: ";
                        std::cin >> id;
                        Usuario* usuario = biblioteca.buscarUsuario(id);
                        if (usuario) {
                            std::cout << "Usuario encontrado: " << usuario->getNombre() << ", ID: " << usuario->getId() << "\n";
                        } else {
                            std::cout << "Usuario no encontrado.\n";
                        }
                        break;
                        }
                        case 3: {  // Eliminar usuario
                        int id;
                        std::cout << "Ingrese el ID del usuario a eliminar: ";
                std::cin >> id;
                if (biblioteca.eliminarUsuario(id)) {
                    std::cout << "Usuario eliminado con éxito.\n";
                } else {
                    std::cout << "Usuario no encontrado.\n";
                }
                break;
            }
            case 4: {  // Listar usuarios
                biblioteca.listarUsuarios();
                break;
            }
            case 5: {
                std::cout << "Saliendo del menú de usuarios...\n";
                break;
            }
            default: {
                std::cout << "Opción no válida. Intente de nuevo.\n";
                break;
            }
            // Guardar los usuarios en el archivo al finalizar
            biblioteca.guardarUsuarios("usuarios.txt");
        }
    } while (opcion != 6);
    break;

            }
            case 7: {
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
