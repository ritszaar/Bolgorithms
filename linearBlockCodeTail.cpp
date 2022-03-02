// Algoithm for generating Linear Block Codes - Parity Bits at Tail

#include <bits/stdc++.h>
using namespace std;

void displayMatrix(const vector<vector<int>>& m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            cout << m[i][j] << " ";
        } cout << "\n";
    }
}

void displayArray(string title, vector<int> a) {
    cout << title << " : [";
    for (int i = 0; i < a.size() - 1; i++) {
        cout << a[i] << ", ";
    } cout << a[a.size() - 1] << "]\n";
}

class LBC {
    int n;
    int k;
    int m;
    vector<vector<int>> G;
    vector<vector<int>> Ht;

    public:
    LBC(int n_, int k_, const vector<vector<int>>& G_) {
        n = n_;
        k = k_;
        m = n - k;
        G.assign(G_.size(), vector<int>(G_[0].size()));
        for (int i = 0; i < G.size(); i++) {
            for (int j = 0; j < G[i].size(); j++) {
                G[i][j] = G_[i][j];
            }
        }
        Ht.assign(n, vector<int>(m));
        for (int i = 0; i < k; i++) {
            for (int j = k; j < n; j++) {
                Ht[i][j - k] = G[i][j];
            }
        }
        for (int i = k; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Ht[i][j] = (i - j == k ? 1 : 0);
            }
        }
    }

    vector<int> getCode(const vector<int>& data) {
        vector<int> code(n);
        for (int i = 0; i < n; i++) {
            code[i] = 0;
            for (int j = 0; j < k; j++) {
                code[i] += data[j] * G[j][i];
                code[i] %= 2;
            }
        } return code;
    }

    vector<int> getSyndrome(const vector<int>& code) {
        vector<int> syndrome(m);
        for (int i = 0; i < m; i++) {
            syndrome[i] = 0;
            for (int j = 0; j < n; j++) {
                syndrome[i] += code[j] * Ht[j][i];
                syndrome[i] %= 2;
            }
        } return syndrome;
    }

    vector<int> correctCode(const vector<int>& code) {
        vector<int> syndrome = getSyndrome(code);
        int index = -1;
        for (int i = 0; i < n; i++) {
            index = i;
            for (int j = 0; j < m; j++) {
                if (syndrome[j] != Ht[i][j]) {
                    index = -1;
                    break;
                }
            }
            if (index != -1) break;
        }
        vector<int> correctedCode(n);
        for (int i = 0; i < n; i++) {
            if (i != index) {
                correctedCode[i] = code[i];
            } else {
                correctedCode[i] = 1 - code[i];
            }
        } return correctedCode;
    }

    void displayH() {
        displayMatrix(Ht);
    }

    void displayG() {
        displayMatrix(G);
    }
};

int main() {

    freopen("5.txt", "r", stdin);
    int n, k, m;
    cin >> n >> k;
    m = n - k;
    vector<vector<int>> G(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }
    
    LBC lbc(n, k, G);
    vector<int> data = {1, 0, 1, 1};
    vector<int> code = lbc.getCode(data);
    // code[0] = 1 - code[0];
    vector<int> syndrome = lbc.getSyndrome(code);
    vector<int> correctc = lbc.correctCode(code);

    lbc.displayH();
    displayArray("Data", data);
    displayArray("Code", code);
    displayArray("Syndrome", syndrome);
    displayArray("Correct Code", correctc);

    return 0;
}