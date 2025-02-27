#include <iostream>
#include <utility>
#include <string>
#include <tuple>

//Initialization

std:: tuple<int, double, std::string, bool> getinfo(){
    int number = 14;
    double numberd = 14.00;
    std:: string word = "Hello";
    bool value = true;
    return {number, numberd, word, value};
}

std:: tuple <int, double, std::string> reference(){
    int age = 10;
    double height = 1.54;
    std::string name = "Anne";
    return {age, height, name};
}

int main(){

    //Initialization
    //Int
    int number1(14.0); // Direct Initialization
    int number2{14};  // Uniform Initalization
    std:: string word1 = "Hello";
    bool ok = true;
    //Double
    double numberd1(15.0); // Direct Initialization
    double numberd2{15.00};  // Uniform Initalization
    std:: string word2{"Hello"};
    bool oki{true};

    //Structure blinded
    auto [number, numberd, word, value] = getinfo(); 

    std:: cout << "Direct initialization: " << number1 << ", " <<numberd1 << ", " << word1 <<  ", " << ok <<std::endl;
    std:: cout << "Uniform Initialization: " << number2 << ", " << numberd2 << ", " << word2 <<  ", " << oki << std::endl;
    std:: cout << "\nStructure Blinded: \nint: " << number << ", double: " << numberd << ", std:: string: " << word << ", boolean: " << value << std::endl;
    
    //References
    int& n1 = number1;
    n1 = 85;

    double& nd1 = numberd1;
    nd1 = 104.85;

    std::string& str= word1;
    str = "World";

    bool& okidoki = ok;
    okidoki = false;

    std:: cout << "\nReference: " << number1 << ", " <<numberd1 << ", " << word1 <<  ", " << ok <<std::endl;


    


}
