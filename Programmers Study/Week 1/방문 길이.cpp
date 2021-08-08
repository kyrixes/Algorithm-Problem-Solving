#include <string>
#include <set>
#include <tuple>
using namespace std;

int solution(string dirs) {
    int x = 0, y = 0, cnt = 0;
    int oldx = x, oldy = y;

    using edge = tuple<int, int, int, int>; // oldx, oldy, x, y
    set<edge> passed;

    for (char c : dirs) {
        switch (c) {
        case 'U': if (y < 5) y++; break;
        case 'D': if (y > -5) y--; break;
        case 'R': if (x < 5) x++; break;
        case 'L': if (x > -5) x--; break;
        }

        if (x == oldx && y == oldy)
            continue;

        passed.insert(edge(oldx, oldy, x, y));
        passed.insert(edge(x, y, oldx, oldy));
        oldx = x;
        oldy = y;
    }

    return passed.size() / 2;
}
