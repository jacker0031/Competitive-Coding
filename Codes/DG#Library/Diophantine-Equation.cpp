// a * x + b * y = gcd(a, b)
int gcd(int a, int b, int &x, int &y)
{
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    int xg, yg;
    int g = gcd(b, a % b, xg, yg);
    x = yg;
    y = xg - yg * (a / b);
    return g;
}

// a * x + b * y = c
bool find_any_solution(int a, int &x, int b, int &y, int c, int &g)
{
    g = gcd(abs(a), abs(b), x, y);
    
    if(c % g) return false;
    
    x *= c / g;
    y *= c / g;
    
    if(a < 0) x *= -1;
    
    if(b < 0) y *= -1;
    
    return true;
}

void shift_solution(int &x, int &y, int a, int b, int cnt)
{
    x += cnt * b;
    y -= cnt * a;
}

// a = 0 or b = 0, case isn't handled
// gives total number of solution in given range
int find_all_solution(int a, int b, int c, int minx, int maxx, int miny, int maxy)
{
    // we will store solutions in this array
    vector<pii> sols(4);
    int x, y, g;
    
    if(!find_any_solution(a, x, b, y, c, g))
        return 0;
        
    a /= g;
    b /= g;
    
    int sign_a = a > 0 ? 1 : -1;
    int sign_b = b > 0 ? 1 : -1;
    
    // making x >= minx(smallest x)
    shift_solution(x, y, a, b, (minx - x) / b);
    if(x < minx) shift_solution(x, y, a, b, sign_b);
    if(x > maxx) return 0;
    int lx1 = x;
    sols[0] = {x, y};
    
    // making x <= maxx(greatest x)
    shift_solution(x, y, a, b, (maxx - x) / b);
    if(x > maxx) shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;
    sols[1] = {x, y};
    
    // making y >= miny(smallest y)
    shift_solution(x, y, a, b, -(miny - y) / a);
    if(y < miny) shift_solution(x, y, a, b, -sign_a);
    if(y > maxy) return 0;
    int lx2 = x;
    sols[2] = {x, y};
    
    // making y <= maxy(greatest y)
    shift_solution(x, y, a, b, -(maxy - y) / a);
    if(y > maxy) shift_solution(x, y, a, b, sign_a);
    int rx2 = x;
    sols[3] = {x, y};

    // to find range
    if(lx2 > rx2) swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    return max((rx - lx) / abs(b) + 1, 0LL);
}