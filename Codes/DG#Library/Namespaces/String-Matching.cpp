namespace patternMatching {
    
    /****
      ** Time Complexity : O(n + m)
      ** Space Complexity : O(m * no_of_distinct characters)
    ****/
    namespace finiteAutometa
    {
        // private methods and properties
        int n, m, no_of_chars, prevAns;
        string txt, pat;
        vector<int> charToId, idToChar;
        vector<vector<int>> transit;

        // returns next state of given state & character
        int nextState(int state, int ch)
        {
            if(state < m && pat[state] == ch)  // current char is matching, hence next state
                return state + 1;

            int i, j;
            for(i = state - 1 ; i >= 0 ; i--)
            {
                // if current char isn't matching or reached to accepted state

                // running reverse loop to find nearest state from
                // current state which is matching to given character
                
                if(pat[i] == ch)
                {
                    for(j = 0 ; j < i ; j++)
                    {
                        // matching prefix of pattern with previos states
                        if(pat[j] != pat[state - i + j])
                            break;
                    }
                    if(i == j) return i + 1;  // prefix is suffix of i + 1 state
                }
            }
            return 0;  // there no other option then initial state
        }

        // builds the state-table
        void build_table(vector<vi> &res)
        {
            prevAns = -m;
            no_of_chars = res.back().size();

            for(int state = 0 ; state <= m ; state++) {
                for(int i = 0 ; i < no_of_chars ; i++)
                    res[state][i] = nextState(state, idToChar[i]);
            }
        }

        // public methods

        // finds for next match in previously given string
        int findNext()
        {
            int cnt, state, res;
            cnt = state = 0;
            res = INT_MAX;

            for(int i = prevAns + m ; i < n ; i++) {
                state = transit[state][charToId[txt[i]]];  // next state
                if(state == m) // accepting state
                {
                    res = min(max(prevAns + 1, i - m + 1), res);
                    cnt++;
                }
            }
            return max(prevAns = (res == INT_MAX ? -m : res), -1LL);
        }

        // finds first match in given string
        int find(const string &_txt, const string &_pat)
        {
            if(pat.size() == _pat.size() && txt.size() == _txt.size() && pat == _pat && txt == _txt)
                return findNext();

            txt = _txt;
            n = txt.size();
            pat = _pat;
            m = pat.size();

            int res, cnt, state;
            res = INT_MAX;
            cnt = 0;

            charToId = vi(256, -1);
            idToChar = vi(256, -1);

            // index compression method
            for(int i = 0 ; i < m ; i++) {
                if(charToId[pat[i]] == -1) {
                    charToId[pat[i]] = cnt;
                    idToChar[cnt] = pat[i];
                    cnt++;
                }
            }
            for(int i = 0 ; i < n ; i++) {
                if(charToId[txt[i]] == -1) {
                    charToId[txt[i]] = cnt;
                    idToChar[cnt] = pat[i];
                    cnt++;
                }
            }

            no_of_chars = cnt;
            transit = vector<vector<int>>(m + 1, vector<int>(no_of_chars));
            build_table(transit);

            cnt = state = 0;
            for(int i = prevAns + m ; i < n ; i++) {
                state = transit[state][charToId[txt[i]]];  // next state
                if(state == m) // accepting state
                {
                    res = min(i - m + 1, res);
                    cnt++;
                }
            }
            return max(prevAns = (res == INT_MAX ? -m : res), -1LL);
        }

        // returns the most recently found answer
        int answer() {return max(prevAns, -1LL);}
    }

    /****
      ** Time Complexity : O(n + m)
      ** Space Complexity : O(m)
    ****/
    namespace KMP
    {
        vector<int> lps;
        void FillLPS(const string &pat)
        {
            int len = 0;
            int m = pat.size();
            lps.assign(m, 0);

            for(int i = 1 ; i < m ; i++) {
                if(pat[i] == pat[len]) {
                    lps[i] = ++len;
                    continue;
                }

                if(len == 0) {
                    lps[i] = 0;
                    continue;
                }

                i--;
                len = lps[len - 1];
            }
        }

        // This function will return all match of
        // given pattern according to 0-Based indexing
        vector<int> findAll(const string &txt, const string &pat)
        {
            int n = txt.size();
            int m = pat.size();
            vector<int> ans;
            FillLPS(pat);

            int i = 0;  // txt iterator
            int j = 0;  // pat iterator
            while(i < n) {
                if(txt[i] == pat[j]) {
                    i++;
                    j++;
                }

                if(j == m) {
                    ans.push_back({i - j});
                    j = lps[j - 1];
                }
                else if(i < n && txt[i] != pat[j]) {
                    if(j == 0) i++;
                    else j = lps[j - 1];
                }
            }
            return ans;
        }

        // This function will return first match of
        // given pattern according to 0-Based indexing
        int find(const string &txt, const string &pat)
        {
            int n = txt.size();
            int m = pat.size();
            vector<int> ans;
            FillLPS(pat);

            int i = 0;  // txt iterator
            int j = 0;  // pat iterator
            while(i < n) {
                if(txt[i] == pat[j]) {
                    i++;
                    j++;
                }

                if(j == m) return i - j;
                
                if(i < n && txt[i] != pat[j]) {
                    if(j == 0) i++;
                    else j = lps[j - 1];
                }
            }
            return -1;
        }
    }
}