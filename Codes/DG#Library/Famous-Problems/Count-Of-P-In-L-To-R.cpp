// will give count of p comes in factorization of numbers between [l, r] (inclusive)
int countP(int l, int r, int p)
{
    l = max(l, 1);
    int a, b;
    int ans = 0;
    int val = p;
    
    while(true)
    {
        b = r / val;
        a = (l - 1) / val;
        val *= p;
        if(a == b)
            break;
        ans += b - a;
    }
    return ans;
}