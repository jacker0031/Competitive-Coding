vector<vi> lps;
int LPS(string &s)
{
    int i, j, n, m, len;
    n = s.size();
    lps = vector<vi>(n, vi(n, 0));

    for(i = 0 ; i < n ; i++)
        lps[i][i] = 1;

    for(len = 2 ; len <= n ; len++) {
        m = n - len + 1;
        for(i = 0 ; i < m ; i++) {
            j = i + len - 1;
            if(s[i] == s[j])
                lps[i][j] = max({lps[i][j], lps[i + 1][j - 1] + 2});
            else
                lps[i][j] = max({lps[i][j], lps[i][j - 1], lps[i + 1][j]});
        }
    }
    return lps[0][n - 1];
}