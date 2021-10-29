#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;
int m, n, a[51][51], b[51][51];
vector<pair<int, int>> rs;

void solve(int i) {

    ifstream inp("./SQUAREFILLING/Test" + to_string(i) + "/SQUAREFILLING.INP");
    ofstream out("SQUAREFILLING.OUT");

    inp >> n >> m;

    rs.clear();

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            inp >> a[i][j];
            b[i][j] = 0;
        }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j + 1 <= m && i + 1 <= n) {
                if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i + 1][j + 1] == 1 && a[i][j + 1] == 1) {
                    b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
                    rs.emplace_back(i, j);
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)if (b[i][j] != a[i][j])goto label1;

    out << rs.size() << "\n";
    for (int i = 0; i < rs.size(); ++i)out << rs[i].first << " " << rs[i].second << "\n";
    inp.close();
    out.close();
    return;
    label1:
    out << -1;
    inp.close();
    out.close();
}

void check(int i) {
    ifstream program_output("SQUAREFILLING.OUT");
    ifstream expected_output("./SQUAREFILLING/Test" + to_string(i) + "/SQUAREFILLING.OUT");

    string test1, test2;

    while (getline(program_output, test1) && getline(expected_output, test2)) {
        if (test1 != test2) {
            cout << "Test " << i << ": FAILED\n";
            return;
        }
    }
    cout << "Test " << i << ": OK\n";
    program_output.close();
    expected_output.close();
}

int main() {
    for (int i = 1; i <= 20; i++) {
        solve(i);
        check(i);
    }

    return 0;
}





