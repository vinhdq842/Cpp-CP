//
// Created by admin on 17/04/2020.
//

#include <iostream>

using namespace std;
#define ll long long
const ll MAX = 100000000;

ll solve(ll, ll, ll);

ll f[1000 + 1][2500 + 1][30 + 1];

int main() {
    ll m, n, o;// Number of desk, chair and day, respectively.

    /**
     * The problem is to find the least cost of producing m desks, n chairs in o days
     * A company has two factories A and B. A requires $1000 per day producing desks and chairs while B requires $900
     * A can produce 20 desks and 60 chairs a day, B can produce 25 desks and 50 chairs a day
     */

    cin >> m >> n >> o;

    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= o; ++k)f[i][j][k] = -1;

    cout << solve(m, n, o) << "\n \n";

    ll back_track = f[m][n][o];

    while (back_track > 0) {
        if (back_track - 1000 == solve(m - 20, n - 60, o - 1)) {
            back_track -= 1000;
            cout << 1000 << "\n";
            m -= 20;
            n -= 60;
            --o;
        } else if (back_track - 900 == solve(m - 25, n - 50, o - 1)) {
            back_track -= 900;
            cout << 900 << "\n";
            m -= 25;
            n -= 50;
            --o;
        } else if (back_track - 1900 == solve(m - 45, n - 110, o - 1)) {
            back_track -= 1900;
            cout << 1900 << "\n";
            m -= 45;
            n -= 110;
            --o;
        }
    }

    return 0;
}

ll solve(ll m, ll n, ll o) {
    // If the result has already been calculated, simply return it.
    if (m >= 0 && n >= 0 && o >= 0 && f[m][n][o] != -1)return f[m][n][o];

    // Cannot produce desks and chairs this way. Not enough time.
    if (o < 1 && (m > 0 || n > 0)) {
        if (m >= 0 && n >= 0 && o >= 0)f[m][n][o] = MAX;
        return MAX;
    }

    // If there exists a desk or a chair to be produced, continue the process
    if (m > 0 || n > 0) {
        ll tmp = min(solve(m - 20, n - 60, o - 1) + 1000,
                     min(solve(m - 25, n - 50, o - 1) + 900, solve(m - 45, n - 110, o - 1) + 1900));
        if (m >= 0 && n >= 0 && o >= 0)f[m][n][o] = tmp;
        return tmp;
    }

    if (m >= 0 && n >= 0 && o >= 0)f[m][n][o] = 0;

    // If produce enough desks and chairs
    return 0;
}