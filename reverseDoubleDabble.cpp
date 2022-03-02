// Algorithm to convert BCD to Binary

#include <bits/stdc++.h>
using namespace std;

void displayRegister(const deque<int>& shiftRegister) {
    for (int i = 0; i < shiftRegister.size(); i++) {
        cout << shiftRegister[i];
        if ((i + 1) % 4 == 0) cout << " ";
    }
}

void displayOutput(const deque<int>& output, int outputSize) {
    for (int x : output) {
        cout << x;
    }
    for (int i = 0; i < outputSize - output.size(); i++) {
        cout << " ";
    }
}

bool isEmptyRegister(const deque<int>& shiftRegister) {
    for (int x : shiftRegister) {
        if (x == 1) return false;
    } return true;
}

void reverseDoubleDabble(long long n) {

    deque<int> digits;
    int outputSize = floor(log2(n)) + 1;
    cout << "\n\n" << n << "    ";
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }

    int i = 0, j = digits.size() - 1;
    while (i < j) {
        swap(digits[i], digits[j]);
        i++; j--;
    }

    deque<int> shiftRegister(4 * digits.size(), 0);
    for (int i = 0; i < digits.size(); i++) {
        int x = digits[i];
        for (int j = 3; j >= 0; j--) {
            shiftRegister[4 * i + j] = x % 2;
            x /= 2;
        }
    }

    displayRegister(shiftRegister); cout << "\n\n";

    displayRegister(shiftRegister); cout << "  ";

    deque<int> output;
    displayOutput(output, outputSize);
    cout << "    Initialization\n\n";

    while (!isEmptyRegister(shiftRegister)) {
        output.push_front(*shiftRegister.rbegin());
        for (int i = shiftRegister.size() - 1; i >= 1; i--) {
            shiftRegister[i] = shiftRegister[i - 1];
        } shiftRegister[0] = 0;
        displayRegister(shiftRegister); cout << "  ";
        displayOutput(output, outputSize);
        cout << "    Right Shift\n";
        for (int i = 0; i < digits.size(); i++) {
            int x = shiftRegister[4 * i] * 8 + shiftRegister[4 * i + 1] * 4 + shiftRegister[4 * i + 2] * 2 + shiftRegister[4 * i + 3];
            if (x >= 8) {
                x -= 3;
            }
            for (int j = 3; j >= 0; j--) {
                shiftRegister[4 * i + j] = x % 2;
                x /= 2;
            }
            displayRegister(shiftRegister); cout << "  ";
            displayOutput(output, outputSize);
            cout << "    Subtract 3 from " << i << "th Place\n";
        } cout << "\n";
    } 
    cout << "\n\nFinal Result: ";
    displayOutput(output, outputSize); cout << "\n\n";
}

int main() {
    long long n; cin >> n;
    reverseDoubleDabble(n);
    return 0;
}
