#include <bits/stdc++.h>
using namespace std;

#define DHRUV_GHEEWALA
#define DEBUG
#define endl '\n'

#ifdef DEBUG
    #define cline cerr
    // #define cline cerr << "Line: " << __LINE__ << ", "

    #define debug(...) cline, debug_out_separate(#__VA_ARGS__, __VA_ARGS__)
    // #define debug(...) cline, debug_out_tourist(#__VA_ARGS__, __VA_ARGS__)

    #define fundri cerr << "----------------------------\n"

#else
    #define fundri 137
    #define debug(...) 1729

#endif

template<typename T, typename U>
string to_string(pair<T, U> p);

string to_string(const string s) {return '"' + s + '"';}
string to_string(const char *s) {return to_string((string)s);}
string to_string(bool b) {return (b ? "1" : "0");}

string to_string(char c)
{
    string res(3, '\'');
    res[1] = c;
    return res;
}

string to_string(vector<bool> v)
{
    string res = "{";
    bool fir = true;

    for(bool b: v) {
        if(!fir)
            res += ", ";
        fir = false;
        res += to_string(b);
    }
    res += "}";
    return res;
}

template<size_t N>
string to_string(bitset<N> bs)
{
    string res = "";
    for(int i = 0 ; i < N ; i++)
        res += static_cast<char>(bs[i] + '0');
    return res;
}

template<typename T>
string to_string(queue<T> q)
{
    string res = "{";
    bool fir = true;

    while(!q.empty()) {
        if(!fir)
            res += ", ";
        fir = false;
        res += to_string(q.front());
        q.pop();
    }
    res += "}";
    return res;
}

template<class T, class Container, class Compare>
string to_string(priority_queue<T, Container, Compare> pq)
{
    string res = "{";
    bool fir = true;

    while(!pq.empty()) {
        if(!fir)
            res += ", ";
        fir = false;
        res += to_string(pq.top());
        pq.pop();
    }
    res += "}";
    return res;
}

template<typename T>
string to_string(stack<T> st)
{
    string res = "{";
    bool fir = true;

    while(!st.empty()) {
        if(!fir)
            res += ", ";
        fir = false;
        res += to_string(st.top());
        st.pop();
    }
    res += "}";
    return res;
}

template<typename T>
string to_string(T v)
{
    string res = "{";
    bool fir = true;

    for(auto &x: v) {
        if(!fir)
            res += ", ";
        fir = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template<typename T, typename U>
string to_string(pair<T, U> p)
{
    string res = "{";
    res += to_string(p.first);
    res += ", ";
    res += to_string(p.second);
    res += "}";
    return res;
}


// ============================================ \\

template<typename T>
void debug_out_separate(string name, T arg) {cerr << name << " = " << to_string(arg) << endl;}
template<typename H, typename... T>
void debug_out_separate(string names, H arg, T... args)
{
    cerr << names.substr(0, names.find(',')) << " = " << to_string(arg) << ", ";
    debug_out_separate(names.substr(names.find(',') + 2), args...);
}

// ============================================ \\

template<typename T>
void debug_out_tourist(T arg) {cerr << to_string(arg) << endl;}
template<typename H, typename... T>
void debug_out_tourist(H arg, T... args)
{
    cerr << to_string(arg) << ", ";
    debug_out_tourist(args...);
}