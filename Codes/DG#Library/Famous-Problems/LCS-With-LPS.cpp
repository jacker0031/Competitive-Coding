vector<vi> lcs;
int LCS(string &s, string &t)
{
    int n = s.length();
    int m = t.length();
    lcs = vector<vi>(n, vi(m, 0));

    for(int i = 0 ; i < m ; i++)
        lcs[0][i] = (s[0] == t[i]);
    for(int i = 0 ; i < n ; i++)
        lcs[i][0] = (s[i] == t[0]);

    for(int i = 1 ; i < n ; i++) {
        for(int j = 1 ; j < m ; j++) {
            if(s[i] == t[j])
                lcs[i][j] = max(lcs[i][j], lcs[i - 1][j - 1] + 1);
            else
                lcs[i][j] = max({lcs[i][j], lcs[i - 1][j], lcs[i][j - 1]});
        }
    }
    return lcs[n - 1][m - 1];
}

int LPS(string &s)
{
    string t = s;
    reverse(all(t));
    return LCS(s, t);
}