#ifndef STUDY_H
#define STUDY_H

#include <string>
#include <vector>

class Estudio {
private:
    std::string archivo_registro;

public:
    Estudio(const std::string& nombreArchivo);
    bool archivoExiste() const;
    void crearArchivo();
    void obtenerFechaActual(std::string& nombre_dia, int& dia_mes, std::string& fecha_formateada) const;
    std::string formatoTiempo(float segundos) const;
    void generarResumenSemanal(const std::string& dia_actual, const std::string& fecha_actual);
    void reiniciarArchivo();
    void registrarTiempoGUI(const std::string& materia, float tiempoEstudio, const std::string& diaActual);
    void actualizarRegistro(const std::string& materia, float tiempo_estudio, const std::string& dia_actual);
};

#endif
