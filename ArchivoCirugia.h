#pragma once
#include <cstdio>
#include <vector>

template <typename T>
class ArchivoCirugia {
public:
    static bool leer(int pos, T& registro, const char* nombreArchivo = "libros.dat") {
        FILE* p = fopen(nombreArchivo, "rb");
        if (p == nullptr) {
            return false;
        }

        if (fseek(p, pos * sizeof(T), SEEK_SET) != 0) {
            fclose(p);
            return false;
        }

        bool leyo = fread(&registro, sizeof(T), 1, p) == 1;
        fclose(p);
        return leyo;
    }

    static std::vector<T> leerTodos(const char* nombreArchivo = "libros.dat") {
        std::vector<T> registros;
        FILE* p = fopen(nombreArchivo, "rb");
        if (p == nullptr) {
            return registros;
        }

        T registro;
        while (fread(&registro, sizeof(T), 1, p) == 1) {
            registros.push_back(registro);
        }

        fclose(p);
        return registros;
    }

    static bool agregar(const T& registro, const char* nombreArchivo = "libros.dat") {
        FILE* p = fopen(nombreArchivo, "ab");
        if (p == nullptr) {
            return false;
        }

        bool guardado = fwrite(&registro, sizeof(T), 1, p) == 1;
        fclose(p);
        return guardado;
    }

    static bool guardar(const T& registro, int pos, const char* nombreArchivo = "libros.dat") {
        FILE* p = fopen(nombreArchivo, "r+b");
        if (p == nullptr) {
            p = fopen(nombreArchivo, "w+b");
            if (p == nullptr) {
                return false;
            }
        }

        if (fseek(p, pos * sizeof(T), SEEK_SET) != 0) {
            fclose(p);
            return false;
        }

        bool guardado = fwrite(&registro, sizeof(T), 1, p) == 1;
        fclose(p);
        return guardado;
    }

    static void crearArchivoSiNoExiste(const char* nombreArchivo = "libros.dat") {
        FILE* p = fopen(nombreArchivo, "ab");
        if (p != nullptr) {
            fclose(p);
        }
    }
};

