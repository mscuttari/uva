#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    while (n--) {
        int m;
        cin >> m;

        stack<int> stack;

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;

            stack.push(x + y);
        }

        int carry = 0;
        char* result = new char[m + 1];
        result[m] = '\0';
        int pos = m - 1;

        while (!stack.empty()) {
            int value = stack.top();
            stack.pop();

            value += carry;
            int digit = value % 10;
            result[pos--] = digit + '0';
            carry = value / 10;
        }

        if (carry != 0) {
            cout << carry;
        }

        cout << result << endl;

        if (n) {
            cout << endl;
        }

        delete[] result;
    }

    return 0;
}
