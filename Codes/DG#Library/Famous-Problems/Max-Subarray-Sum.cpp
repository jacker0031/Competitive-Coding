int max_subarray_sum(vi &a)
{
    int n, sum;
    n = a.size();
    sum = 0;
    vi dp(n, 0);

    for(int i = 0 ; i < n ; i++)
    {
        sum += a[i];
        if(sum > 0)
        {
        	dp[i] = sum;
        	continue;
        }
        sum = 0;
        dp[i] = a[i];  // this can be changed according 
                       // to min size of subarray(here, it is 1)
    }
    return *max_element(all(dp));
}