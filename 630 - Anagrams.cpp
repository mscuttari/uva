#include <bits/stdc++.h>

using namespace std;

int getKey(const string& str);
bool areAnagrams(const string& str1, const string& str2);

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int, vector<string>> anagrams;

        while (n--) {
            string str;
            cin >> str;

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
        }

        string str;
        cin >> str;

        while (str != "END") {
            cout << "Anagrams for: " << str << endl;

            int key = getKey(str);
            auto it = anagrams.find(key);

            if (it != anagrams.end()){
                vector<string> &v = it->second;
                int count = 0;

                for (int i = 1; i <= v.size(); i++) {
                    if (areAnagrams(str, v[i - 1]))
                        cout << "  " << ++count << ") " << v[i - 1] << endl;
                }

                if (count == 0) {
                    cout << "No anagrams for: " << str << endl;
                }

            } else {
                cout << "No anagrams for: " << str << endl;
            }

            cin >> str;
        }

        if (t) {
            cout << endl;
        }
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
