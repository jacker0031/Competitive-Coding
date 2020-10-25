namespace convexHull {

    struct pt
    {
        int x, y;

        pt() : x(0), y(0) {}
        pt(int _x, int _y) : x(_x), y(_y) {}

        // According to y-coord
        friend bool operator <(const pt &lhs, const pt &rhs) {
            if(lhs.x == rhs.x)
                return lhs.y < rhs.y;
            return lhs.x < rhs.x;
        }

        // friend bool operator ==(const pt &lhs, const pt &rhs) {return lhs.x == rhs.x && lhs.y == rhs.y;}
        // friend bool operator >(const pt &lhs, const pt &rhs) {return !(lhs < rhs || lhs == rhs);}
        // friend pt operator -(const pt &p) {return pt(-p.x, -p.y);}
        // friend pt operator -(const pt &lhs, const pt &rhs) {return pt(lhs.x - rhs.x, lhs.y - rhs.y);}
        // friend pt operator +(const pt &lhs, const pt &rhs) {return lhs - (-rhs);}

        friend istream& operator >>(istream &in, pt &p) {return in >> p.x >> p.y;}

        // int cross(const pt &p) {return x * p.y - y * p.x;}
        // int dot(const pt &p) {return x * p.x + y * p.y;}
        long double dist(const pt &p)
        {
            int _x = (x - p.x);
            int _y = (y - p.y);
            return sqrt(_x * _x + _y * _y);
        }
    };
    long double dist(pt &p1, const pt &p2) {return p1.dist(p2);}

    string to_string(pt &a)
    {
        #ifndef DEBUG
            int x = a.x;
            int y = a.y;

            string res = "{";
            res += x + '0';
            res += ", ";
            res += y + '0';
            res += '}';

            return res;
        #endif
        return "";
    }

    namespace grahamScan
    {
        const int RIGHT = 1;
        const int LEFT = -1;
        const int SAME = 0;
        pt pivot;

        // This will return direction of line a -> lhs w.r.t. a -> rhs
        int direction(const pt &a, const pt &lhs, const pt &rhs) {
            int slopeCompare = (lhs.y - a.y) * (rhs.x - a.x) - (lhs.x - a.x) * (rhs.y - a.y);

            if(slopeCompare == 0)
                return SAME;  // Same Line

            if(slopeCompare > 0)
                return LEFT;  // Slope(a, lhs) > Slope(a, rhs)
            
            // this is required for sorting
            return RIGHT;  // Slope(a, lhs) < Slope(a, rhs)
        }

        bool cmp(const pt &lhs, const pt &rhs) {
            int dir = direction(pivot, lhs, rhs);
            if(dir == SAME)
                return dist(pivot, lhs) < dist(pivot, rhs);
            return (dir == RIGHT);
        }

        void giveHull(vector<pt> points, stack<pt> &res)
        {
            int n = points.size();
            if(n <= 2) {
                for(const auto &point : points)
                    res.push(point);
                return;
            }

            int ind, mny;
            mny = INT_MAX;
            
            for(int i = 0 ; i < points.size() ; i++) {
                if(mny > points[i].y) {
                    ind = i;
                    mny = points[i].y;
                }
            }
            // Making pivot according to minimum y-coord
            pivot = points[ind];
            swap(points[0], points[ind]);

            // sorting except first point(out pivot element)
            sort(points.begin() + 1, points.end(), cmp);

            res.push(points[0]);
            res.push(points[1]);
            res.push(points[2]);

            for(int i = 3 ; i < n ; i++) {
                pt fir = res.top();
                res.pop();

                // if there is an anthor point which lies to right side then
                while(!res.empty() && direction(res.top(), fir, points[i]) != RIGHT) {
                    fir = res.top();
                    res.pop();
                }

                res.push(fir);
                res.push(points[i]);
            }
        }
    };
};
using namespace convexHull;