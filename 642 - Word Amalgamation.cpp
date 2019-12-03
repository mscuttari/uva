#include <bits/stdc++.h>

using namespace std;

int getKey(const string& str);
bool areAnagrams(const string& str1, const string& str2);

int main() {
    string str;
    cin >> str;

    map<int, vector<string>> anagrams;

    while (str != "XXXXXX") {
        int key = getKey(str);
        auto it = anagrams.find(key);

        if (it != anagrams.end()){
            vector<string> &v = it->second;
            v.push_back(str);

        } else {
            vector<string> v;
            v.push_back(str);
            anagrams[key] = v;
        }

        cin >> str;
    }

    cin >> str;

    while (str != "XXXXXX") {
        int key = getKey(str);
        auto it = anagrams.find(key);

        if (it != anagrams.end()){
            vector<string> &v = it->second;
            sort(v.begin(), v.end());
            bool found = false;

            for (const auto & i : v) {
                bool print = areAnagrams(str, i);
                found |= print;

                if (print)
                    cout << i << endl;
            }

            if (!found)
                cout << "NOT A VALID WORD" << endl;

        } else {
            cout << "NOT A VALID WORD" << endl;
        }

        cout << "******" << endl;
        cin >> str;
    }

    return 0;
}

int getKey(const string& str) {
    int hash = 0;

    for (char const &c : str) {
        hash += c;
    }

    return hash;
}

bool areAnagrams(const string& str1, const string& str2) {
    int n1 = str1.length();
    int n2 = str2.length();

    if (n1 != n2) {
        return false;
    }

    string x(str1);
    string y(str2);

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for (int i = 0; i < n1; i++) {
        if (x[i] != y[i])
            return false;
    }

    return true;
}
