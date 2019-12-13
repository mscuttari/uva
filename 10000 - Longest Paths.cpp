#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    explicit Node(int id) {
        this->id = id;
    }

    int id;
    vector<Node*> children;
};

bool compareNodes(Node *a, Node *b) {
    return (a->id < b->id);
}

int main() {
    int caseNumber = 1;
    int n;

    do {
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<Node*> nodes;
        nodes.reserve(n + 1);

        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node(i);
        }

        int s;
        cin >> s;

        int p, q;
        cin >> p >> q;

        while (p != 0 && q != 0) {
            nodes[p]->children.push_back(nodes[q]);
            cin >> p >> q;
        }

        vector<Node*> current;
        vector<Node*> next;
        Node *last = nodes[s];

        current.push_back(last);
        int count = 0;

        while (!current.empty()) {
            vector<bool> visits(n + 1, false);

            sort(current.begin(), current.end(), compareNodes);

            for (int i = current.size() - 1; i >= 0; i--) {
                Node* node = current[i];
                last = node;

                for (auto& child : node->children) {
                    if (!visits[child->id]) {
                        visits[child->id] = true;
                        next.push_back(child);
                    }
                }
            }

            current.clear();

            swap(current, next);

            if (!current.empty())
                count++;
        }

        cout << "Case " << caseNumber++ << ": The longest path from " << s << " has length " << count << ", finishing at " << last->id << "." << endl;
        cout << endl;

        for (int i = 1; i <= n; i++) {
            delete nodes[i];
        }

    } while (n != 0);

    return 0;
}
