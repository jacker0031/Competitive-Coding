/****
  ** Time Complexity : O(n * Logn)
  ** Space Complexity : O(n)
****/

int LSIS(vi &a)
{
	int n = a.size();
	multiset<int> s;

	for(int i = 0 ; i < n ; i++)
	{
		auto it = s.lower_bound(a[i]);
		if(it != s.end())
			s.erase(it);
		s.insert(a[i]);
	}

	return s.size();
}

int LIS(vi &a)
{
	int n = a.size();
	multiset<int> s;

	for(int i = 0 ; i < n ; i++)
	{
		auto it = s.upper_bound(a[i]);
		if(it != s.end())
			s.erase(it);
		s.insert(a[i]);
	}

	return s.size();
}


/*

Link : https://codeforces.com/blog/entry/13225?#comment-180208

Sure, it can be done. The code becomes a bit longer because instead of storing just the values you have to store the indices.

In the simple code, you have the following invariant after processing each element: Consider the values currently stored in the set S, in increasing order. Let's call them S[0], S[1], S[2], etc. Then, for each i, S[i] is the smallest value such that the sequence we already processed has an increasing subsequence of length i+1 that ends in the value S[i].

If you want to reconstruct the sequence, you have to remember indices of those values instead of the values themselves. Then, whenever you insert a new index x into the position i, you look at the index currently at position i-1 in the set and remember it as the previous element of the optimal sequence that ends at index x.

Here is a sample implementation. The function returns the indices of elements that form one possible longest strictly increasing subsequence of the input. (The input is assumed to be non-empty. It is allowed to contain duplicates.)

vector<int> LIS(const vector<int> &elements) {
    // declare the set with a custom comparison function
    // that compares values instead of indices
    auto compare = [&](int x, int y) {
        return elements[x] < elements[y];
    };
    set< int, decltype(compare) > S(compare);

    // process the elements; for each length
    // maintain the index of the best end so far
    vector<int> previous( elements.size(), -1 );
    for (int i=0; i<int( elements.size() ); ++i) {
        auto it = S.insert(i).first;
        if (it != S.begin())
            previous[i] = *prev(it);
        if (*it == i && next(it) != S.end()) 
            S.erase(next(it));
    }

    // reconstruct the indices that form 
    // one possible optimal answer
    vector<int> answer;
    answer.push_back( *S.rbegin() );
    while ( previous[answer.back()] != -1 )
        answer.push_back( previous[answer.back()] );
    reverse( answer.begin(), answer.end() );
    return answer;
}
It's much easier if the input is guaranteed to have no duplicates. In that case, just use a map and for each value remember the immediately preceding one in an optimal solution.

*/