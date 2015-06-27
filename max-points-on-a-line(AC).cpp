#include <algorithm>
#include <map>
using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

typedef struct Term {
    Term(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    
    int x, y;
    bool operator < (const Term &other) const
    {
        if (x != other.x) {
            return x < other.x;
        } else {
            return y < other.y;
        }
    }
    
    bool operator == (const Term &other) const
    {
        return x == other.x && y == other.y;
    }
} Term;

int gcd(int x, int y)
{
    return x ? gcd(y % x, x) : y;
}

int abs(int x)
{
    return x >= 0 ? x : -x;
}

void normalize(Term &t)
{
    if (t.x == 0) {
        t.y = t.y ? 1 : 0;
        return;
    }
    if (t.y == 0) {
        t.x = t.x ? 1 : 0;
        return;
    }
    
    if (t.x < 0) {
        t.x = -t.x;
        t.y = -t.y;
    }
    int g = gcd(t.x, abs(t.y));
    t.x /= g;
    t.y /= g;
}

class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if (n < 3) {
            return n;
        }
        
        map<Term, int> mm;
        map<Term, int>::iterator it;
        Term t;
        int i, j;
        int zc;
        int msum = 2;
        int sum;
        
        for (i = 0; i < n; ++i) {
            for (j = i + 1; j < n; ++j) {
                t.x = points[j].x - points[i].x;
                t.y = points[j].y - points[i].y;
                normalize(t);
                ++mm[t];
            }
            zc = mm[Term(0, 0)];
            sum = 0;
            for (it = mm.begin(); it != mm.end(); ++it) {
                if (it->first == Term(0, 0)) {
                    continue;
                }
                sum = max(sum, it->second);
            }
            msum = max(msum, sum + zc + 1);
            mm.clear();
        }
        return msum;
    }
};