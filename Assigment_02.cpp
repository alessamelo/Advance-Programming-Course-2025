#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <cctype>
#include <ctime>  


std::string extract_initials(const std::string& name);

std::string kYourName = "Tu Nombre"; 

std::string extract_initials(const std::string& name) {
    std::string initials;
    if (!name.empty()) {
        initials += toupper(name[0]);
        for (size_t i = 1; i < name.length(); ++i) {
            if (name[i - 1] == ' ') {
                initials += toupper(name[i]);
            }
        }
    }
    return initials;
}

std::set<std::string> get_applicants(const std::string& filename) {
    std::set<std::string> applicants;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << filename << std::endl;
        return applicants;
    }

    std::string name;
    while (std::getline(file, name)) {
        if (!name.empty()) { 
            applicants.insert(name);
        }
    }

    file.close();
    return applicants;
}

std::queue<const std::string*> find_matches(const std::string& name, std::set<std::string>& students) {
    std::queue<const std::string*> matches;

    std::string initials = extract_initials(name);

    for (const std::string& student : students) {
        std::string student_initials = extract_initials(student);
        if (student_initials == initials) {
            matches.push(&student); 
        }
    }

    return matches;
}

std::string get_match(std::queue<const std::string*>& matches) {
    if (matches.empty()) {
        return "NO MATCHES FOUND.";
    }

    std::srand(std::time(0));
    int random_index = std::rand() % matches.size(); 

    for (int i = 0; i < random_index; ++i) {
        matches.push(matches.front()); 
        matches.pop(); 
    }

    return *matches.front(); 
}

#include "autograder/utils.hpp" 
