int LISLength(vi &a)
{
    int n = a.size();
    if(n == 0)
        return 0;
    vi tail(n, 0);
    tail[0] = a[0];
    int length = 1;  // always points to empty slot in tail

    for(int i = 1 ; i < n ; i++) {
        auto it = lower_bound(all(tail) - n + length, a[i]);

        // if new element is at the end, then insert it and increase the length
        if(it == tail.begin() + length) {
            tail[length] = a[i];
            length++;
            continue;
        }
        *it = a[i];
    }

    return length;
}

int LDSLength(vi &a)
{
    reverse(all(a));
    int n = a.size();
    if(n == 0)
        return 0;
    vi tail(n, 0);
    tail[0] = a[0];
    int length = 1;  // always points to empty slot in tail

    for(int i = 1 ; i < n ; i++) {
        auto it = lower_bound(all(tail) - n + length, a[i]);

        // if new element is at the end, then insert it and increase the length
        if(it == tail.begin() + length) {
            tail[length] = a[i];
            length++;
            continue;
        }
        *it = a[i];
    }

    reverse(all(a));
    return length;
}