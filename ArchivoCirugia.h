#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
#include "Cirugia.h"

class ArchivoCirugia {
private:
    const char* nombreArchivo = "cirugias.dat";
public:
    ArchivoCirugia() {
        crearArchivoSiNoExiste();
    }
    bool leer(int pos, Cirugia& registro) {
        FILE* p = fopen(nombreArchivo, "rb");
        if (p == nullptr) {
            return false;
        }

        if (fseek(p, pos * sizeof(Cirugia), SEEK_SET) != 0) {
            fclose(p);
            return false;
        }

        bool leyo = fread(&registro, sizeof(Cirugia), 1, p) == 1;
        fclose(p);
        return leyo;
    }

    std::vector<Cirugia> leerTodos() {
        std::vector<Cirugia> registros;
        FILE* p = fopen(nombreArchivo, "rb");
        if (p == nullptr) {
            return registros;
        }

        Cirugia registro;
        while (fread(&registro, sizeof(Cirugia), 1, p) == 1) {
            registros.push_back(registro);
        }

        fclose(p);
        return registros;
    }

    bool agregar(const Cirugia& registro) {
        FILE* p = fopen(nombreArchivo, "ab");
        if (p == nullptr) {
            return false;
        }

        bool guardado = fwrite(&registro, sizeof(Cirugia), 1, p) == 1;
        fclose(p);
        return guardado;
    }

    bool guardar(const Cirugia& registro, int pos) {
        FILE* p = fopen(nombreArchivo, "r+b");
        if (p == nullptr) {
            p = fopen(nombreArchivo, "w+b");
            if (p == nullptr) {
                return false;
            }
        }

        if (fseek(p, pos * sizeof(Cirugia), SEEK_SET) != 0) {
            fclose(p);
            return false;
        }

        bool guardado = fwrite(&registro, sizeof(Cirugia), 1, p) == 1;
        fclose(p);
        return guardado;
    }

    bool guardar(const Cirugia& registro) {
        std::cout << "\nGuardando el registro en archivo...";
        FILE* p = fopen(nombreArchivo, "ab");
        if (p == NULL) return false;
        fwrite(&registro, sizeof(Cirugia), 1, p);
        fclose(p);

        std::cout << "\nGuardado exitoso";//<< con ID " << this->id << ".\n";

        return true;
    }

    bool leer(int pos) {
        Cirugia registro;
        FILE* p = fopen(this->nombreArchivo, "rb");
        if (p == NULL) return false;
        fseek(p, pos * sizeof(Cirugia), SEEK_SET);
        bool leyo = fread(&registro, sizeof(Cirugia), 1, p) == 1;
        fclose(p);
        return leyo;
    }

    Cirugia leerRegistro(int pos) {
        Cirugia reg;
        FILE* p = fopen(this->nombreArchivo, "rb");
        if (p == NULL) {
            return reg;
        }
        fseek(p, pos * sizeof(Cirugia), SEEK_SET);
        fread(&reg, sizeof(Cirugia), 1, p);
        fclose(p);
        return reg;
    }

    void listar() {
        std::cout << "\n--- LISTADO ("<<this->nombreArchivo<<")---\n\n";
        int pos = 0;
        while (leer(pos++)) {
            leerRegistro(pos - 1).mostrarCampos();
        }
        if (pos == 1) {
            std::cout << "No hay registros cargados.\n";
        }
        std::cout << "\n--- " << pos - 1 << " registros ---\n\n";
    }


    void crearArchivoSiNoExiste() {
        FILE* p = fopen(nombreArchivo, "ab");
        if (p != nullptr) {
            fclose(p);
        }
    }
};

