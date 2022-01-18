#include <iostream>

using namespace std;

struct Polynomial {
    int coefficient;
    int exponent;
};

int main() {
    struct Polynomial p1[5], p2[3], p3[5];
    int i = 0, j = 0, k = 0;
    
    for (int i = 0; i < 5; i++) {
        p1[i].coefficient = 6 - i;
        p1[i].exponent = 4 - i;
        cout << p1[i].coefficient << "^" << p1[i].exponent << " ";
    }
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        p2[i].coefficient = 5 - i;
        p2[i].exponent = 2 - i;        
        cout << p2[i].coefficient << "^" << p2[i].exponent << " ";
    }
    cout << "\n";

    while (i < 5 && j < 3) {
        if (p1[i].exponent == p2[j].exponent) {
            p3[k].coefficient = (p1[i].coefficient + p2[j].coefficient);
            p3[k].exponent = p1[i].exponent;
            j++;
            i++;
        } else if (p1[i].exponent > p2[j].exponent) {
            p3[k].coefficient = p1[i].coefficient;
            p3[k].exponent = p1[i].exponent;
            i++;
        } else {
            p3[k].coefficient = p2[j].coefficient;
            p3[k].exponent = p2[j].exponent;
            j++;
        }
        k++;
    }

    while (i < 5) {
        p3[k].coefficient = p1[i].coefficient;
        p3[k].exponent = p1[i].exponent;        
        k++;
        i++;
    }

    while (j < 3) {
        p3[k].coefficient = p2[j].coefficient;
        p3[k].exponent = p2[j].exponent;        
        k++;
        j++;
    }

    for (int i = 0; i < 5; i++) {
        cout << p3[i].coefficient << "^" << p3[i].exponent << " ";
    }

    cout << "\n";
    return 0;
}


