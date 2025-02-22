#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;



//fucntion declarations
void swap(int& a, int &b);
void triangle (int a, int b, int c);
void triangle (double a, double b, double c);
void promptMessage();



int main(int argc, char* argv[]) {
    int lengthA, lengthB, lengthC;

    if (argc == 4) {
        // Handle command line arguments
        lengthA = atoi(argv[1]);
        lengthB = atoi(argv[2]);
        lengthC = atoi(argv[3]);

        if (lengthA <= 0 || lengthB <= 0 || lengthC <= 0) {
            cerr << "Error: All values must be positive integers." << endl;
            return 1;
        }
    }
    else if (argc == 1) {
        // Handle interactive input
        promptMessage();
        if (!(cin >> lengthA >> lengthB >> lengthC) || lengthA <= 0 || lengthB <= 0 || lengthC <= 0) {
            cerr << "Error: All values must be positive integers." << endl;
            return 1;
        }
    }
    else {
        cerr << "Error: Program requires exactly three positive integer arguments." << endl;
        return 1;
    }

    triangle(lengthA, lengthB, lengthC);


    return 0;
}


void promptMessage() {
    cout << "Enter the lengths of a triangle (positive integers only): " << endl;
}

void triangle (int a, int b, int c) {
    if (a > c) {
        swap(a, c);
    }
    if (b > c) {
        swap(b, c);
    }
    if (a > b) {
        swap(a, b);
    }

    cout << a << " " << b << " "  << c << " ";

    if (a+b <= c) {
        cout << "Not a triangle" << endl;
        exit(1);
    }

    // a triangle is right if the square of the longest side is equal to the sum of the squares of the other two sides

    bool isRight = (a * a + b * b == c * c);

    if (a == b && b == c) {
        cout << "Equilateral triangle" << endl;
    } else if (a == b || b == c || a == c) {
        cout << (isRight ? "Right Isosceles triangle" : "Isosceles triangle") << endl;
    } else {
        cout << (isRight ? "Right Scalene triangle" : "Scalene triangle") << endl;
    }

}

void triangle (double a, double b, double c) {
    const double EPSILON = 0.001;

    if (a > c) {
        swap(a, b);
    }
    if (b > c) {
        swap(b, c);
    }
    if (a > b) {
        swap(a, b);
    }

    if (a+b <= c) {
        cout << "Not a trinagle" << endl;
    }

    cout << fixed << setprecision(5) << a << " " << b << " " << c << " ";

    bool isRight = (a * a + b * b == c * c);

    if ((abs(a-b) < EPSILON) && (abs(b-c) < EPSILON)) {
        cout << "Equilateral triangle" << endl;
    } else if ((abs(a-b) < EPSILON) || (abs(b-c) < EPSILON)|| (abs(b-c) < EPSILON)) {
        cout << (isRight ? "Right Isosceles triangle" : "Isosceles triangle") << endl;
    } else {
        cout << (isRight ? "Right Scalene triangle" : "Scalene triangle") << endl;
    }

}


void swap(int& a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}