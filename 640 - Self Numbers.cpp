#include <bits/stdc++.h>

#define N 1000000

using namespace std;

int getSum(int n);

int main() {

    bool n[N + 1] = {false};

    for (int i = 1; i <= N; i++) {
        int successor = i + getSum(i);

        if (successor <= N)
            n[successor] = true;
    }

    for (int i = 1; i <= N; i++) {
        if (!n[i])
            cout << i << endl;
    }

    return 0;
}

int getSum(int n) {
    int sum = 0;

    while (n != 0) {
        sum = sum + n % 10;
        n = n/10;
    }

    return sum;
}
