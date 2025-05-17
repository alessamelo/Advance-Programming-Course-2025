#include "include/analytics.h"
#include "../lib/CLI11/include/CLI/CLI.hpp"
#include <iostream>
#include <iomanip>

int main(int argc, char** argv) {
    CLI::App app{"Retail Data Analytics App"};
    
    std::string country;
    app.add_option("-c,--country", country, "Filter by country");
    
    bool only_uk = false;
    app.add_flag("--only-uk", only_uk, "Analyze only UK transactions");
    
    CLI11_PARSE(app, argc, argv);

    try {
        Analytics analytics("data/Online-Retail.csv");  
        analytics.loadData(only_uk);

        auto countryCounts = analytics.getTransactionsByCountry();
        double totalAmount = analytics.getTotalAmount();

        // Display results
        std::cout << "\n=== Resultados del Análisis ===" << std::endl;
        
        if (!country.empty()) {
            std::cout << "Transacciones para " << country << ": " 
                      << countryCounts[country] << std::endl;
        } else if (only_uk) {
            std::cout << "Transacciones en UK: " 
                      << countryCounts["United Kingdom"] << std::endl;
        } else {
            for (const auto& [country, count] : countryCounts) {
                std::cout << country << ": " << count << " transacciones\n";
            }
        }

        std::cout << "Monto total: £" << std::fixed << std::setprecision(2) 
                  << totalAmount << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}