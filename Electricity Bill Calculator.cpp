#include <iostream>
using namespace std;

int main() {
    long long num;
    cout << "Enter a number: ";
    cin >> num;

    int count[10] = { 0 };

    long long temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        count[digit]++;
        temp /= 10;
    }

    cout << "Repeated digit(s): ";
    bool found = false;

    for (int i = 0; i < 10; i++) {
        if (count[i] > 1) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "None";
    }

    cout << endl;
    return 0;
}