#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    bool visited = false;
    bool color = false;
    vector<Node*> children;
};

bool isBicorolable(vector<Node*> &nodes);

int main() {
    int n, l;
    cin >> n;

    while (n != 0) {
        cin >> l;

        vector<Node*> nodes;
        nodes.reserve(n);

        for (int i = 0; i < n; i++) {
            nodes[i] = new Node;
        }

        while (l--) {
            int x, y;
            cin >> x >> y;
            nodes[x]->children.push_back(nodes[y]);
            nodes[y]->children.push_back(nodes[x]);
        }

        if (isBicorolable(nodes)) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }

        for (int i = 0; i < n; i++) {
            delete nodes[i];
        }

        cin >> n;
    }

    return 0;
}

bool isBicorolable(vector<Node*> &nodes) {
    queue<Node*> q;
    q.push(nodes[0]);
    nodes[0]->visited = true;

    while (!q.empty()) {
        Node *node = q.front();
        q.pop();

        for (auto child : node->children) {
            if (child->visited && child->color == node->color)
                return false;

            if (!child->visited) {
                child->visited = true;
                child->color = !node->color;

                q.push(child);
            }
        }
    }

    return true;
}