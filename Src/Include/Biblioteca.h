#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "MaterialBibliografico.h"
#include "Usuario.h"
#include <fstream>

class Biblioteca {
public:
    Biblioteca();
    ~Biblioteca();
    
    int contarMaterialesEnArchivo() const;
    void agregarMaterial(const std::string& nombre,const std::string& isbn,const std::string& autor, const std::string& fecha,const std::string& resuOrEd, bool libro);
    void agregarUsuario(const Usuario& usuario);

    void listarMateriales() const;
    void listarUsuarios() const;

    bool prestarMaterial(const std::string& isbn);
    bool devolverMaterial(const std::string& isbn);

    Usuario* buscarUsuario(int id);
    bool eliminarUsuario(int id);

    void guardarUsuarios(const std::string& archivoUsuarios) const;
    void cargarUsuarios(const std::string& archivoUsuarios);


private:
    //Array con las revistas y libros
    MaterialBibliografico* biblioteca[10];
    std::vector<Usuario> usuarios;
};

