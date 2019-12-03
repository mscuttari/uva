#include <iostream>
#include <map>
#include <vector>

using namespace std;

static int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

int getKey(const string& str);

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

                for (int i = 1; i <= v.size(); i++) {
                    cout << "  " << i << ") " << v[i - 1] << endl;
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
        hash += primes[c - 'a'];
    }

    return hash;
}
