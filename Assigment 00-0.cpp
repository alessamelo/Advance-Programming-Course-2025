//Solve a cuadratic equation
#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

using zeros = std::pair <double, double>;
using answer = std:: pair<bool, zeros>;

answer SolveQuadratic(double a, double b, double c){
    double det = b*b -4* a*c;
    if (det < 0){
        cout<< "There are no zeros." << endl;
        return {false, {0, 0}};
    }else {
        double raiz = sqrt(det);
        cout<< "The equation has real solutions.";
        return {true, {(-b + raiz)/(2*a), (-b - raiz)/(2*a)}};
    }        
}

int main(){
    double a, b, c;
    cout<< "Enter the numerical coefficients of the quadratic equation: " << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    answer solution = SolveQuadratic(a, b, c);

    if (solution.first = true){
        cout <<"\nx1 = " << solution.second.first << endl;
        cout <<"x2 = " << solution.second.second << endl;
    return 0;
    }
}
