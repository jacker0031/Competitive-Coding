int LISLenght(vi &a)
{
    int n = a.size();
    set<int> s;
    set<int>::iterator it;
    for(int i = 0 ; i < n ; i++) {
        s.insert(a[i]);
        it = s.upper_bound(a[i]);
        if(it != s.end())
            s.erase(it);
    }
    return s.size();
}

int LDSLenght(vi &a)
{
    reverse(all(a));
    int n = a.size();
    set<int> s;
    set<int>::iterator it;
    for(int i = 0 ; i < n ; i++) {
        s.insert(a[i]);
        it = s.upper_bound(a[i]);
        if(it != s.end())
            s.erase(it);
    }
    reverse(all(a));
    return s.size();
}