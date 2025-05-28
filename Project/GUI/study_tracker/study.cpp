#include "study.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <ctime>
#include <sstream>
#include <iomanip>

namespace fs = std::filesystem;

Estudio::Estudio(const std::string& nombreArchivo) : archivo_registro(nombreArchivo) {}

bool Estudio::archivoExiste() const {
    return fs::exists(archivo_registro);
}

void Estudio::crearArchivo() {
    std::ofstream archivo(archivo_registro);
    if (archivo.is_open()) {
        archivo << "Subject,Monday,Tuesday,Wednesday,Thursday,Friday\n";
        archivo << "Subject1,0,0,0,0,0\n";
        archivo << "Subject2,0,0,0,0,0\n";
        archivo << "Subject3,0,0,0,0,0\n";
        archivo << "Subject4,0,0,0,0,0\n";
        archivo.close();
        std::cout << "Archivo de registro creado exitosamente.\n";
    } else {
        std::cerr << "Error: No se pudo crear el archivo.\n";
    }
}

void Estudio::obtenerFechaActual(std::string& nombre_dia, int& dia_mes, std::string& fecha_formateada) const {
    time_t ahora = time(0);
    tm* tiempo_local = localtime(&ahora);

    dia_mes = tiempo_local->tm_mday;

    const char* dias_semana[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    nombre_dia = dias_semana[tiempo_local->tm_wday];

    std::ostringstream oss;
    oss << (tiempo_local->tm_year + 1900) << "/"
        << std::setfill('0') << std::setw(2) << (tiempo_local->tm_mon + 1) << "/"
        << std::setfill('0') << std::setw(2) << tiempo_local->tm_mday;
    fecha_formateada = oss.str();
}

std::string Estudio::formatoTiempo(float segundos) const {
    int horas = static_cast<int>(segundos) / 3600;
    int minutos = (static_cast<int>(segundos) % 3600) / 60;
    int segs = static_cast<int>(segundos) % 60;

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << horas << ":"
        << std::setfill('0') << std::setw(2) << minutos << ":"
        << std::setfill('0') << std::setw(2) << segs;
    return oss.str();
}

void Estudio::generarResumenSemanal(const std::string& dia_actual, const std::string& fecha_actual) {
    if (dia_actual != "Wednesday") return; // Cambia según la lógica que quieras

    std::ifstream entrada(archivo_registro);
    if (!entrada.is_open()) {
        std::cerr << "No se pudo abrir el archivo de registro para generar resumen.\n";
        return;
    }

    std::ofstream salida("final_report.csv", std::ios::app);
    std::string linea;
    bool es_cabecera = true;
    std::vector<std::string> materias;
    std::vector<float> totales;

    while (std::getline(entrada, linea)) {
        std::stringstream ss(linea);
        std::string campo;
        std::vector<std::string> campos;
        while (std::getline(ss, campo, ',')) {
            campos.push_back(campo);
        }

        if (es_cabecera) {
            es_cabecera = false;
            if (!fs::exists("final_report.csv") || fs::file_size("final_report.csv") == 0) {
                salida << "Date";
                // Aquí escribirás después los nombres de materias
            }
        } else {
            materias.push_back(campos[0]);
            float suma = 0.0f;
            for (size_t i = 1; i < campos.size(); ++i) {
                suma += std::stof(campos[i]);
            }
            totales.push_back(suma);
        }
    }
    entrada.close();

    if (!fs::exists("final_report.csv") || fs::file_size("final_report.csv") == 0) {
        for (const auto& m : materias) {
            salida << "," << m;
        }
        salida << "\n";
    }

    salida << fecha_actual;
    for (float t : totales) {
        salida << "," << t;
    }
    salida << "\n";
    salida.close();

    std::cout << "Resumen semanal guardado en final_report.csv\n";
}

void Estudio::reiniciarArchivo() {
    std::ifstream archivo_entrada(archivo_registro);
    std::vector<std::string> lineas;
    std::string linea;
    bool es_cabecera = true;

    while (std::getline(archivo_entrada, linea)) {
        if (es_cabecera) {
            lineas.push_back(linea);
            es_cabecera = false;
        } else {
            std::stringstream ss(linea);
            std::string materia;
            std::getline(ss, materia, ',');
            std::string linea_actualizada = materia + ",0,0,0,0,0";
            lineas.push_back(linea_actualizada);
        }
    }
    archivo_entrada.close();

    std::ofstream archivo_salida(archivo_registro);
    for (const auto& l : lineas) {
        archivo_salida << l << "\n";
    }
}

void Estudio::registrarTiempoGUI(const std::string& materia, float tiempoEstudio, const std::string& diaActual) {
    actualizarRegistro(materia, tiempoEstudio, diaActual);
}


void Estudio::actualizarRegistro(const std::string& materia, float tiempo_estudio, const std::string& dia_actual) {
    std::ifstream archivo_entrada(archivo_registro);
    std::vector<std::string> lineas;
    std::string linea;
    bool materia_encontrada = false;
    int indice_dia = -1;

    const std::string dias_semana[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    for (int i = 0; i < 5; ++i) {
        if (dias_semana[i] == dia_actual) {
            indice_dia = i + 1;
            break;
        }
    }

    if (indice_dia == -1) {
        std::cerr << "Error: Día no válido (solo de Lunes a Viernes).\n";
        return;
    }

    bool es_cabecera = true;
    while (std::getline(archivo_entrada, linea)) {
        if (es_cabecera) {
            lineas.push_back(linea);
            es_cabecera = false;
            continue;
        }

        std::stringstream ss(linea);
        std::string campo;
        std::vector<std::string> campos;

        while (std::getline(ss, campo, ',')) {
            campos.push_back(campo);
        }

        if (campos.empty()) continue;

        if (campos[0] == materia) {
            materia_encontrada = true;
            float actual = std::stof(campos[indice_dia]);
            campos[indice_dia] = std::to_string(actual + tiempo_estudio);
        }

        std::string linea_actualizada;
        for (size_t i = 0; i < campos.size(); ++i) {
            if (i != 0) linea_actualizada += ",";
            linea_actualizada += campos[i];
        }
        lineas.push_back(linea_actualizada);
    }

    if (!materia_encontrada) {
        std::string nueva_linea = materia + ",0,0,0,0,0";
        std::vector<std::string> campos = {"0", "0", "0", "0", "0"};
        campos[indice_dia - 1] = std::to_string(tiempo_estudio);

        for (const auto& c : campos) {
            nueva_linea += "," + c;
        }
        lineas.push_back(nueva_linea);
    }

    archivo_entrada.close();

    std::ofstream archivo_salida(archivo_registro);
    for (const auto& l : lineas) {
        archivo_salida << l << "\n";
    }

    std::cout << "Registro actualizado correctamente.\n";
    std::cout << "Tiempo estudiado en " << materia << ": " << formatoTiempo(tiempo_estudio) << "\n";
}