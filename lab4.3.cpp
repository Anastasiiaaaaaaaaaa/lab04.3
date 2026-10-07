#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    double xp, x, xk, dx, F;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << "xp = ";
    cin >> xp;
    cout << "xk = ";
    cin >> xk;
    cout << "dx = ";
    cin >> dx;

    cout << fixed;
    cout << "---------------------------------------" << endl;
    cout << "|" << setw(12) << "x" << "|" << setw(14) << "F" << "|" << endl;
    cout << "---------------------------------------" << endl;

    x = xp;

    while (x <= xk + dx / 2.0) {
        bool error = false;

        if (a < 0 && c != 0) {
            F = a * x * x + b * x + c;
        }
        else if (a > 0 && c == 0) {
            if (abs(x - b) < 1e-7) {
                error = true;
            }
            else {
                F = -a / (x - b);
            }
        }
        else {
            F = a * (x + c);
        }

        cout << "|" << setw(12) << setprecision(2) << x << "|";
        if (error) {
            cout << setw(14) << "error" << "|" << endl;
        }
        else {
            cout << setw(14) << setprecision(4) << F << "|" << endl;
        }

        x += dx;
    }

    cout << "---------------------------------------" << endl;

    return 0;
}
