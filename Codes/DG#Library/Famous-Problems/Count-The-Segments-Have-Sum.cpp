// give the count of sub-segments with sum k
int countSegments(vi &a, int k)
{
	int n = a.size();
	int cnt, sum;
	map<int, int> mp;

	cnt = sum = 0;
	for(int i = 0 ; i < n ; i++)
	{
		sum += a[i];
		if(sum == k)
			cnt++;
		if(mp.count(sum - k))
			cnt++;
		mp[sum]++;
	}
	return cnt;
}