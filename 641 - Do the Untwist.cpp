#include <iostream>
#include <array>
#include <cstring>

#define LENGTH 70

using namespace std;

int encode(char c);
char decode(int n);

int main() {
    array<char, LENGTH> ciphertext = {0};
    array<int,  LENGTH> ciphercode = {0};
    array<char, LENGTH> plaintext  = {0};

    int k;
    cin >> k;

    while (k != 0) {
        cin >> ciphertext.data();
        int n = strlen(ciphertext.data());

        for (int i = 0; i < n; i++) {
            ciphercode[i] = encode(ciphertext[i]);
        }

        for (int i = 0; i < n; i++) {
            int plain_pos = (k * i) % n;

            for (int plain = 0; ; plain++) {
                int x = ((plain - i) / 28) * 28 + ciphercode[i];
                int y = plain - i;

                if (x == y) {
                    plaintext[plain_pos] = decode(plain % 28);
                    break;
                }
            }
        }

        cout << plaintext.data() << endl;

        ciphertext.fill(0);
        ciphercode.fill(0);
        plaintext.fill(0);

        cin >> k;
    }

    return 0;
}

int encode(char c) {
    if (c == '_') {
        return 0;
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 1;
    } else {
        return 27;
    }
}

char decode(int n) {
    if (n == 0) {
        return '_';
    } else if (n >= 1 && n <= 26) {
        return 'a' + n - 1;
    } else {
        return '.';
    }
}
