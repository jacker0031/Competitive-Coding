/****
  ** Time Complexity : O(n)
  ** Space Complexity : O(n) // this can be optimized to O(k) by improving insertValue fxn
****/

deque<pii> dq;
void insertValue(int val, int x)
{
	// if we change dq.pop_back().ff < val to dq.pop_back().ff > val
	// then we will get minimums of all subarrays

	while(!dq.empty() && dq.back().ff < val)
		dq.pop_back();
	dq.push_back({val, x});
}

int findAllSubarrayMaximum(vi &a, vi &ans, int k)
{
	int fir = 0;
	int n = a.size();
	ans.resize(n - k + 1);
	dq = deque<pii>();

	for(int i = 0 ; i < k ; i++)
		insertValue(a[i], i);

	ans[fir++] = dq.front().ff;
	for(int i = k ; i < n ; i++)
	{
		insertValue(a[i], i);
		while(dq.front().ss <= i - k)
			dq.pop_front();
		ans[fir++] = dq.front().ff;
	}
	return n - k + 1;
}