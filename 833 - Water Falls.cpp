#include <bits/stdc++.h>

using namespace std;

class Point {
public:
    Point() : x(0), y(0) {};
    Point(int x, int y) : x(x), y(y) {};

    int x, y;

    bool operator <(const Point& rhs) const {
        return (x < rhs.x) || ((x == rhs.x) && (y < rhs.y));
    }
};

int main() {
    int t, np, ns;
    cin >> t;

    while (t--) {
        map<Point, pair<float, Point>> map;

        cin >> np;

        while (np--) {
            Point p1, p2;

            cin >> p1.x >> p1.y >> p2.x >> p2.y;

            if (p1.x > p2.x) {
                swap(p1, p2);
            }

            int direction = p1.y == p2.y ? 0 : (p1.y < p2.y ? 1 : 2);
            float m = (float) (p2.y - p1.y) / (p2.x - p1.x);
            float q = p1.y - m * p1.x;

            for (int x = p1.x; x <= p2.x; x++) {
                float y = m * x + q;
                int y_ceil = ceil(y);

                Point curr(x, y_ceil);

                if (map.find(curr) == map.end() || map[curr].first < y) {
                    if (direction == 1 && x != p1.x && y != p1.y) {
                        Point dest(p1.x, p1.y);
                        map[curr] = pair<float, Point>(y, dest);

                    } else if (direction == 2 && x != p2.x && y != p2.y) {
                        Point dest(p2.x, p2.y);
                        map[curr] = pair<float, Point>(y, dest);
                    }
                }
            }
        }

        cin >> ns;

        while (ns--) {
            Point p;
            cin >> p.x >> p.y;

            while (p.y != 0) {
                if (map.find(p) != map.end()) {
                    int dest_x = map[p].second.x;
                    int dest_y = map[p].second.y;

                    p.x = dest_x;
                    p.y = dest_y;

                } else {
                    p.y--;
                }
            }

            cout << p.x << endl;
        }

        if (t) {
            cout << endl;
        }
    }

    return 0;
}
