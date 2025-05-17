#include "analytics.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

using namespace ftxui;

void Analytics::updateProgress(float progress, const std::string& message) const {
    auto document = hbox({
        text(message),
        gauge(progress) | color(Color::Green) | flex_shrink
    });
    auto screen = Screen::Create(Dimension::Fit(document));
    Render(screen, document);
    screen.Print();
    std::cout << "\r" << std::flush;
}

void Analytics::loadData(bool onlyUK) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo: " + filename);
    }

    // Obtener tamaño del archivo para el progreso
    file.seekg(0, std::ios::end);
    auto file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::string line;
    std::getline(file, line); // Saltar cabecera

    transactions.clear();
    size_t lineCount = 0;
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Transaction t;
        std::string field;

        // Parsear cada campo
        std::getline(ss, t.invoiceNo, ',');
        std::getline(ss, t.stockCode, ',');
        std::getline(ss, t.description, ',');
        std::getline(ss, field, ',');
        t.quantity = field.empty() ? 0 : std::stoi(field);
        std::getline(ss, field, ',');
        t.unitPrice = field.empty() ? 0.0 : std::stod(field);
        std::getline(ss, t.customerID, ',');
        std::getline(ss, t.country);

        if (!onlyUK || t.country == "United Kingdom") {
            transactions.push_back(t);
        }

        lineCount++;
        if (lineCount % 100 == 0) { // Actualizar cada 100 líneas
            float progress = static_cast<float>(file.tellg()) / file_size;
            updateProgress(progress, "Cargando datos: ");
        }
    }
    updateProgress(1.0, "Datos cargados!      ");
    std::cout << std::endl;
    isAnalyzed = false;
}

void Analytics::analyzeData() const {
    if (isAnalyzed) return;

    countryCounts.clear();
    totalAmount = 0.0;

    for (size_t i = 0; i < transactions.size(); ++i) {
        const auto& t = transactions[i];
        countryCounts[t.country]++;
        totalAmount += t.quantity * t.unitPrice;

        if (i % 1000 == 0) { // Actualizar cada 1000 transacciones
            float progress = static_cast<float>(i) / transactions.size();
            updateProgress(progress, "Analizando datos: ");
        }
    }
    updateProgress(1.0, "Análisis completado! ");
    std::cout << std::endl;
    isAnalyzed = true;
}

// Resto de las funciones permanecen igual...
std::unordered_map<std::string, int> Analytics::getTransactionsByCountry() const {
    analyzeData();
    return countryCounts;
}

double Analytics::getTotalAmount() const {
    analyzeData();
    return totalAmount;
}

const std::vector<Transaction>& Analytics::getTransactions() const {
    return transactions;
}