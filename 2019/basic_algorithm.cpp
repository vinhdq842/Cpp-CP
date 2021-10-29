#include <bits/stdc++.h>

using namespace std;

int digitsProduct(int);

bool isPrime(int);

int pagesNumbering(int);

string lineEncoding(string);

bool isPangram(string);

int differentValuesInMultiplicationTable2(int, int);

bool chessBoardCellColor(string, string);

pair<int, int> getIndex(string);

int chessKnight(string);

string getPosInString(pair<int, int>);

vector<vector<int> > spiralNumbers(int);

bool findPath(vector<vector<int>>);

int sumOfDigits(int);

vector<int> makeArrayConsecutive(vector<int>);

int rotOrange(vector<vector<int>>);

int main() {
    makeArrayConsecutive(vector<int>{2, 5, 7});
    return 0;
}

std::vector<int> makeArrayConsecutive(std::vector<int> sequence) {
    if (sequence.size() < 2)return vector<int>{};
    set<int> sets(sequence.begin(), sequence.end());
//for(set<int>::iterator it = sets.begin();it!=sets.end();it++)cout<<*it<<endl;
    vector<int> rs;
    set<int>::iterator it = sets.begin();
    int adu = *it;
    advance(it, 2);
    int adu2 = *it;
    cout << adu << " " << adu2;

    return rs;

}

int sumOfDigits(int n) {
    if (n < 10)return n;
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool findPath(std::vector<std::vector<int> > matrix) {
    int m, n;
    m = matrix.size();
    n = matrix[0].size();
    int posNum = 1;
    int x, y;
    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 1) {
                x = j;
                y = i;
                found = true;
                break;
            }
        if (found)
            break;
    }
    queue<pair<int, int> > q;
    q.push({x, y});
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!(posNum >= n * m || q.empty())) {
        pair<int, int> pr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xdst = pr.first + dx[i];
            int ydst = pr.second + dy[i];
            if (xdst >= 0 && xdst < n && ydst >= 0 && ydst < m && matrix[ydst][xdst] == posNum + 1) {
                q.push({xdst, ydst});
                posNum++;
                break;
            }
        }
    }
    return posNum == n * m;
}

std::vector<std::vector<int> >
spiralNumbers(int n) {
    int num = 1;
    vector<vector<int> > rs;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        rs.push_back(v);
        for (int j = 0; j < n; j++) {
            rs[i].push_back(0);
            cout << rs[i][j];
        }
    }

    int rowIndex = 0;
    int colIndex = 0;
    int rowEnd = n - 1;
    int colEnd = n - 1;
    int rowStart = 0;
    int colStart = 0;

    for (int i = 0; i < n * n; i++) {
        for (colIndex = colStart; colIndex <= colEnd; colIndex++)
            rs[rowIndex][colIndex] = num++;
        colIndex--;
        rowStart++;
        for (rowIndex = rowStart; rowIndex <= rowEnd; rowIndex++)
            rs[rowIndex][colIndex] = num++;
        rowIndex--;
        colEnd--;
        for (colIndex = colEnd; colIndex >= colStart; colIndex--)
            rs[rowIndex][colIndex] = num++;
        colIndex++;
        rowEnd--;
        for (rowIndex = rowEnd; rowIndex >= rowStart; rowIndex--)
            rs[rowIndex][colIndex] = num++;
        rowIndex++;
        colStart++;
    }

    return rs;
}

int chessKnight(std::string cell) {
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int rs = 0;
    pair<int, int> pos = getIndex(cell);
    int x = pos.second, y = pos.first;
    cout << x << " " << y;
    for (int i = 0; i < 8; i++) {
        int xdst = x + dx[i];
        int ydst = y + dy[i];
        if (xdst >= 0 && xdst < 8 && ydst >= 0 && ydst < 8)
            rs++;
    }
    return rs;
}

bool chessBoardCellColor(std::string cell1, std::string cell2) {
    int chessBoard[8][8];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if ((i - j) % 2 == 0)
                chessBoard[i][j] = 0;
            else
                chessBoard[i][j] = 1;

    pair<int, int> cell1st = getIndex(cell1);
    pair<int, int> cell2nd = getIndex(cell2);
    return chessBoard[cell1st.first][cell1st.second] == chessBoard[cell2nd.first][cell2nd.second];
}

pair<int, int>
getIndex(string cell) {
    char col = cell[0] - 97;
    char row = cell[1] - 49;
    return make_pair(row, col);
}

string
getPosInString(pair<int, int> pos) {
    string rs = "";
    char row = pos.first + 97;
    char col = pos.second + 49;
    rs += static_cast<char>(row);
    rs += static_cast<char>(col);
    return rs;
}

bool isPangram(std::string sentence) {
    set<char> sets;
    for (int i = 0; i < sentence.length(); i++) {
        if ((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z'))
            sets.insert(sentence[i] > 97 ? sentence[i] - 32 : sentence[i]);
    }
    cout << sets.size();
    return sets.size() == 26;
}

int differentValuesInMultiplicationTable2(int n, int m) {
    int arr[n][m];
    set<int> set1, set2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = (i + 1) * (j + 1);
            cout << arr[i][j] << " ";
            if (!set1.count(arr[i][j])) {
                set1.insert(arr[i][j]);
                set2.insert(arr[i][j]);
            } else
                set2.erase(arr[i][j]);
        }
        cout << "\n";
    }
    return set2.size();
}

std::string
lineEncoding(std::string s) {
    vector<string> coincardmooclong;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        string add = "";

        int j;
        for (j = i; j < s.length() && s[j] == c; j++) {
            add += c;
        }
        i = j - 1;
        coincardmooclong.push_back(add);
    }
    string rs = "";
    for (int i = 0; i < coincardmooclong.size(); i++) {
        if (coincardmooclong[i].length() > 1)
            rs += to_string(coincardmooclong[i].length()) + coincardmooclong[i][0];
        else
            rs += coincardmooclong[i];
    }

    return rs;
}

int digitsProduct(int product) {
    if (product == 0)
        return 10;
    if (product < 10)
        return product;
    if (isPrime(product))
        return -1;
    string rs = "";
    bool not_ok = false;
    for (int i = 9; i > 1; i--) {
        if (isPrime(product) && product > 9) {
            not_ok = true;
            break;
        }
        if (product % i == 0) {
            rs = to_string(i) + rs;
            product /= i;
            i = 9;
        }
    }
    if (not_ok)
        return -1;
    else
        stoi(rs);
}

bool isPrime(int n) {
    if (n == 2 || n == 3)
        return true;
    if (n < 2)
        return false;
    if (n % 2 == 0)
        return false;
    for (int i = 2; i < n / 2; i++)
        if (n % i == 0)
            return false;
    return true;
}

int pagesNumbering(int n) {
    if (n < 10)
        return n;
    int digits = log10(n);
    int rs = 0;
    int chinchinchinchin = 0;
    string chin_chin_chin_chin = "";
    for (int i = 0; i < digits; i++)
        chin_chin_chin_chin += to_string(9);
    chinchinchinchin = stoi(chin_chin_chin_chin);
    // cout<<chinchinchinchin;
    while (chinchinchinchin > 0) {
        // cout<<(n-chinchinchinchin)*(digits+1)<<endl;
        rs += (n - chinchinchinchin) * (digits + 1);
        n = chinchinchinchin;
        chinchinchinchin /= 10;
        digits--;
    }
    return rs + 9;
}

int rotOrange(std::vector<std::vector<int>> matrix) {
    int n, m, x, y;
    int state[m = matrix.size()][n = matrix[0].size()];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            state[i][j] = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int times = 0;

    do {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 2 && state[i][j] == times) {
                    for (int k = 0; k < 4; k++) {
                        x = i + dx[k];
                        y = j + dy[k];
                        if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] == 1) {
                            matrix[x][y] = 2;
                            state[x][y] = times + 1;
                        }
                    }
                }
            }
        bool flag = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (state[i][j] > times) {
                    times++;
                    flag = true;
                }
            if (flag)
                break;
        }
        if (flag)
            continue;
        break;
    } while (true);


    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 1)
                return -1;
    return times;
}
