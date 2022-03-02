// Algorithm to convert Binary to BCD

#include <bits/stdc++.h>
using namespace std;

void displayRegister(const deque<int>& shiftRegister) {
    for (int i = 0; i < shiftRegister.size(); i++) {
        cout << shiftRegister[i];
        if ((i + 1) % 4 == 0) cout << " ";
    }
}

void displayInput(const deque<int>& input, int inputSize) {
    for (int x : input) { 
        cout << x;
    }
    for (int i = 0; i < inputSize - input.size(); i++) cout << 0;
}

void leftShiftInsert(deque<int>& shiftRegister, int bit) {
    for (int i = 0; i < shiftRegister.size() - 1; i++) {
        shiftRegister[i] = shiftRegister[i + 1];
    } 
    *shiftRegister.rbegin() = bit;
}

int doubleRegister(deque<int>& shiftRegister, const deque<int>& input, int inputSize) {
    int count = 0;
    for (int i = 0; i < shiftRegister.size()/4; i++) {
        int x = shiftRegister[4 * i] * 8 + shiftRegister[4 * i + 1] * 4 + shiftRegister[4 * i + 2] * 2 + shiftRegister[4 * i + 3];
        if (x >= 5) {
            x += 3;
            count++;
            for (int j = 3; j >= 0; j--) {
                shiftRegister[4 * i + j] = x % 2;
                x /= 2;
            }
            displayRegister(shiftRegister); cout << "  ";
            displayInput(input, inputSize); cout << "    Add 3 to " << (shiftRegister.size()/4 - i - 1) << "th Place\n";
        }
    } return count;
}

void doubleDabble(long long n) {
    deque<int> input;
    deque<int> shiftRegister(4 * (floor(log10(n)) + 1), 0);
    cout << "\n\n" << n << "    ";
    while (n > 0) {
        input.push_back(n % 2);
        n /= 2;
    }

    int i = 0, j = input.size() - 1;
    while (i < j) {
        swap(input[i], input[j]);
        i++; j--;
    }

    int inputSize = input.size();

    displayInput(input, inputSize); cout << "\n\n\n";

    displayRegister(shiftRegister); cout << "  ";
    displayInput(input, inputSize); cout << "    Initialization\n\n";

    while (true) {
        leftShiftInsert(shiftRegister, input[0]);
        input.pop_front();
        displayRegister(shiftRegister); cout << "  ";
        displayInput(input, inputSize); cout << "    Left Shift\n";
        if (input.size() == 0) break;
        doubleRegister(shiftRegister, input, inputSize);
        cout << "\n";
    }   

    cout << "\n\nFinal Result: ";
    displayRegister(shiftRegister); cout << "\n";
}


int main() {

    long long n; cin >> n;
    doubleDabble(n);

    return 0;
}