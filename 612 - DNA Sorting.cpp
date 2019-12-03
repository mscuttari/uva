#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
    char* str;
    int length;
    int pos;
    int value;
} dna_t;

int evaluate(dna_t data);
int compare(const void *a, const void *b);

int main() {
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        int n, m;
        cin >> n >> m;

        dna_t data[m];

        for (int j = 0; j < m; j++) {
            data[j].str = new char[n + 1];
            cin >> data[j].str;
            data[j].str[n] = '\0';

            data[j].length = n;
            data[j].pos = j;
            data[j].value = evaluate(data[j]);
        }

        qsort(data, m, sizeof(dna_t), compare);

        for (int j = 0; j < m; j++) {
            cout << data[j].str << endl;
            delete data[j].str;
        }

        if (i < cases - 1)
            cout << endl;
    }

    return 0;
}

int evaluate(dna_t data) {
    int alphabet[4] = {0};
    int result = 0;

    for (int i = data.length - 1; i >= 0; i--) {
        char c = data.str[i];

        int index;

        if (c == 'A') {
            index = 0;
        } else if (c == 'C') {
            index = 1;
        } else if (c == 'G') {
            index = 2;
        } else {
            index = 3;
        }

        alphabet[index]++;

        for (int j = index - 1; j >= 0; j--) {
            result += alphabet[j];
        }
    }

    return result;
}

int compare(const void *a, const void *b) {
    auto* x = (dna_t*) a;
    auto* y = (dna_t*) b;

    if (x->value != y->value)
        return x->value - y->value;

    return x->pos - y->pos;
}
