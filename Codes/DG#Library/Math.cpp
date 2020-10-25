const int MAX_ARRAY = 1000000;
const long double PI = 2 * acos(0.0);

// Other
/***** Start *****/

bool isPowerOfTwo(int a) {return (x && ( !(x & (x - 1))));}

/*========================================================*/

// you have to make struct node(count, num)
void generateDivisors(int cur, int factor, vector<node> &arr, vi &ans)
{
    if(cur == arr.size())
    {
        ans.emplace_back(factor);
        return;
    }
    
    for(int i = 0 ; i < arr[cur].count ; i++) {
        generateDivisors(cur + 1, factor, arr, ans);
        factor *= arr[cur].num;
    }
}

/*========================================================*/

// catalan numbers : Cn = choose(2 * n, n) / (n + 1)
// reccurence : Cn = #(Ci * C(n-i)) {i = 0 to n}
// where # is sumation notation

/****** End ******/





// Modular Inverse
/***** Start *****/

vector<Mint> inv;
void build_mmi_euclid(int maximum = MAX_ARRAY)
{
    maximum = min(maximum, MAX_ARRAY);
    inv.resize(maximum);
    inv[1] = 1;
    
    for(int i = 2 ; i < maximum ; i++)
        inv[i] = MOD - inv[MOD % i] * (MOD / i);
}
Mint einverse(int a) {return inv[a];}  // euclid
Mint finverse(Mint a) {return power(a, MOD - 2);}  // fermet

/****** End ******/




// To Do primeFactorization of number n
/***** Start *****/

int primeFactorization(int n)
{
    int cnt = 0;
    
    for(int i : {2, 3, 5}) {
        while(n % i == 0) {
            n /= i;
            cnt++;
        }
    }
    
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int cur = 0;
    
    for(int i = 7 ; i * i <= n ; i += increments[cur++]) {
        while(n % i == 0) {
            n /= i;
            cnt++;
        }
        
        if(cur == 8)
            cur = 0;
    }
    
    if(n > 1)
        cnt++;
        
    return cnt;
}

/****** End ******/




// count the total number of factors
/***** Start *****/

int primeFactorization(int n)
{
    int cnt, mul = 1;
    
    for(int i : {2, 3, 5}) {
        cnt = 0;
        
        while(n % i == 0) {
            n /= i;
            cnt++;
        }
        
        mul *= (cnt + 1);
    }
    
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int cur = 0;
    
    for(int i = 7 ; i * i <= n ; i += increments[cur++]) {
        cnt = 0;
        
        while(n % i == 0) {
            n /= i;
            cnt++;
        }
        
        mul *= (cnt + 1);
        
        if(cur == 8)
            cur = 0;
    }
    
    if(n > 1)
        return (mul << 1);
        
    return mul;
}

/****** End ******/



// nCr efficient method "without mod"
/***** Start *****/

int choose(int n, int r)
{
    int res, k;
    
    if(r > n - r)
        r = n - r;
        
    k = res = 1;
    
    while(r != 0) {
        res *= n;
        k *= r;
        
        int g = __gcd(res, k);
        
        res /= g;
        k /= g;
        
        n--;
        r--;
    }
    
    return res;
}

/****** End ******/




// Stirling's approximation(to count digits in n!)
/***** Start *****/

vi __stirling;
int giveDigits(int n) {return __stirling[n];}  // gives count of digits in n!

void build_stirling(int maximum = 1e7 + 1)
{
    __stirling.resize(maximum);
    long double sum = 0.0;
    for(int i = 1 ; i < maximum ; i++) {
        sum += log10(i);
        __stirling[i] = floor(sum) + 1;
    }
}

/****** End ******/