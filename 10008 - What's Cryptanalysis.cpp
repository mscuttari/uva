#include <bits/stdc++.h>

using namespace std;

bool sortFunction(pair<char, int> &x, pair<char, int> &y) {
    if (x.second == y.second)
        return x.first < y.first;

    return x.second > y.second;
}

int main() {
    int n;
    cin >> n;
    n++;

    map<char, int> m;

    for (char c = 'A'; c <= 'Z'; c++) {
        m[c] = 0;
    }

    while (n--) {
        string str;
        getline(cin, str);

        for (auto& c : str) {
            if (c >= 'a' && c <= 'z') {
                c = toupper(c);
            }

            if (c >= 'A' && c <= 'Z') {
                m[c]++;
            }
        }
    }

    vector<pair<char, int>> v;

    for (auto const& x : m) {
        v.emplace_back(x.first, x.second);
    }

    sort(v.begin(), v.end(), sortFunction);

    for (auto& p : v) {
        if (p.second != 0) {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}