#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef enum {NONE, K, B, T} MoveType;

class Coord;
class Move;
class Game;

class Coord {
public:
    Coord(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int x, y;

    bool operator==(const Coord &rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    bool operator!=(const Coord &rhs) const {
        return !(rhs == *this);
    }

    vector<Move> moves(int size);
};

class Move {
public:
    Move(Coord coord, MoveType type) : coord(coord), type(type) {

    }

    Coord coord;
    MoveType type;
};

vector<Move> Coord::moves(int size) {
    vector<Move> all = {
            // K moves
            Move(Coord(x - 2, y - 1), K),
            Move(Coord(x - 2, y + 1), K),
            Move(Coord(x - 1, y - 2), K),
            Move(Coord(x + 1, y - 2), K),
            Move(Coord(x + 2, y - 1), K),
            Move(Coord(x + 2, y + 1), K),
            Move(Coord(x - 1, y + 2), K),
            // B moves
            Move(Coord(x + 1, y + 2), B),
            Move(Coord(x - 2, y - 2), B),
            Move(Coord(x - 2, y + 2), B),
            Move(Coord(x + 2, y - 2), B),
            Move(Coord(x + 2, y + 2), B),
            // T moves
            Move(Coord(x, y >= size / 2 ?
                     size / 2 - (y - size / 2) - 1 :
                     size / 2 + (size / 2 - y) - 1), T),
            Move(Coord(x >= size / 2 ?
                     size / 2 - (x - size / 2) - 1 :
                     size / 2 + (size / 2 - x) - 1,
                       y), T)
    };

    vector<Move> result;

    for (Move move : all) {
        if (move.coord.x >= 0 && move.coord.y >= 0 && move.coord.x < size && move.coord.y < size) {
            result.push_back(move);
        }
    }

    return result;
}

class Game {
public:
    explicit Game(int n) {
        size = 2 * n;
        map = new bool**[size];

        for (int i = 0; i < size; i++) {
            map[i] = new bool*[size];

            for (int j = 0; j < size; j++) {
                map[i][j] = new bool[4];

                for (int k = 0; k < 4; k++) {
                    map[i][j][k] = false;
                }
            }
        }
    }

    ~Game() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                delete[] map[i][j];
            }

            delete[] map[i];
        }

        delete[] map;
    }

    void addObstacle(const Coord &coord) {
        map[coord.x][coord.y][0] = true;
    }

    bool isObstacle(const Coord &coord) {
        return map[coord.x][coord.y][0];
    }

    void visit(const Coord &coord, MoveType moveType) {
        if (moveType == K) {
            map[coord.x][coord.y][1] = true;
        } else if (moveType == B) {
            map[coord.x][coord.y][2] = true;
        } else if (moveType == T) {
            map[coord.x][coord.y][3] = true;
        }
    }

    bool isAlreadyVisited(const Coord &coord, MoveType moveType) {
        if (moveType == K) {
            return map[coord.x][coord.y][1];
        } else if (moveType == B) {
            return map[coord.x][coord.y][2];
        } else if (moveType == T) {
            return map[coord.x][coord.y][3];
        }

        return false;
    }

    int size;
    bool ***map;
};


int main() {
    int n;
    cin >> n;

    while (n != 0) {
        Game game(n);

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        Coord start(x1 - 1, y1 - 1);
        Coord end(x2 - 1, y2 - 1);

        int xO, yO;
        cin >> xO >> yO;

        while (xO != 0 && yO != 0) {
            game.addObstacle({xO - 1, yO - 1});
            cin >> xO >> yO;
        }

        int count = 0;
        queue<Move> q, next;
        q.push({start, NONE});
        bool found = false;

        while (!q.empty() && !found) {
            while (!q.empty() && q.front().coord != end) {
                Move last = q.front();
                q.pop();

                for (Move &move : last.coord.moves(game.size)) {
                    if (move.type != last.type && !game.isObstacle(move.coord) && !game.isAlreadyVisited(move.coord, move.type)) {
                        next.push(move);
                        game.visit(move.coord, move.type);
                    }
                }
            }

            if (q.empty()) {
                count++;
                swap(q, next);

            } else if (q.front().coord == end) {
                found = true;
            }
        }

        if (q.empty()) {
            cout << "Solution doesn't exist" << endl;
        } else {
            cout << "Result : " << count << endl;
        }

        cin >> n;
    }

    return 0;
}