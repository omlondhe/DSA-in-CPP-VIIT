#include <iostream>
#include <cmath>

using namespace std;

struct Polynomial {
    int coefficient;
    int exponent;
};

int main() {
    struct Polynomial p1[5];
    int k = 0, x, evaluation = 0;

    cout << "Enter the value of X: ";
    cin >> x;

    for (int i = 0; i < 5; i++) {
        p1[i].coefficient = 5 - i;
        p1[i].exponent = 4 - i;
        cout << p1[i].coefficient << "*2^" << p1[i].exponent << " ";
    }
    cout << "\n";

    for (int i = 0; i < 4; i++) {
        evaluation += (p1[i].coefficient * pow(x, p1[i].coefficient));
    }

    cout << "Evaluation: " << evaluation << "\n";
    return 0;
}


