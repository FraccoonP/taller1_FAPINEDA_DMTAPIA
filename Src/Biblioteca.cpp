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

void Biblioteca::agregarUsuario(const Usuario& usuario) {
    usuarios.push_back(usuario);
    std::cout << "Usuario agregado con éxito.\n";
}

Usuario* Biblioteca::buscarUsuario(int id) {
    for (Usuario& usuario : usuarios) {
        if (usuario.getId() == id) {
            return &usuario;  // Devuelve un puntero al usuario encontrado
        }
    }
    return nullptr;  // Si no encuentra el usuario, devuelve nullptr
}

bool Biblioteca::eliminarUsuario(int id) {
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        if (it->getId() == id) {
            usuarios.erase(it);
            return true;  // Usuario eliminado con éxito
        }
    }
    return false;  // Usuario no encontrado
}

void Biblioteca::listarUsuarios() const {
    if (usuarios.empty()) {
        std::cout << "No hay usuarios en la biblioteca.\n";
        return;
    }
    for (const Usuario& usuario : usuarios) {
        std::cout << "Usuario: " << usuario.getNombre() << ", ID: " << usuario.getId() << '\n';
    }
}

// Funciones para guardar y cargar usuarios
void Biblioteca::guardarUsuarios(const std::string& archivoUsuarios) const {
    std::ofstream out(archivoUsuarios);
    if (!out) {
        std::cerr << "Error al abrir el archivo de usuarios para escribir.\n";
        return;
    }
    for (const Usuario& usuario : usuarios) {
        usuario.guardarUsuario(out);  // Guardar cada usuario en el archivo
    }
    out.close();
}

void Biblioteca::cargarUsuarios(const std::string& archivoUsuarios) {
    std::ifstream in(archivoUsuarios);
    if (!in) {
        std::cerr << "Error al abrir el archivo de usuarios para leer.\n";
        return;
    }
    while (in) {
        Usuario usuario = Usuario::cargarUsuario(in);  // Cargar cada usuario
        if (!usuario.getNombre().empty()) {
            agregarUsuario(usuario);
        }
    }
    in.close();
}