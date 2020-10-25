namespace Graph {

	/***
	 **  This Requires
	 **  adj - adjacency list, where adj[u][v] = weight of edge u -> v, adj: vector<vector<int>>
	***/

	namespace cycle
	{
	    int start, cnt;
	    vector<bool> vis;

	    /****
	      ** Time Complexity : O()
	      ** Space Complexity : O(m)
	    ****/
	    void cycleLengthUtil(int u, int len)
	    {
	        vis[u] = true;
	        if(len == 0)
	        {
	            vis[u] = false; // to use it again
	            for(int v : adj[u]) {
	                if(start == v) {
	                    // this is a valid cycle, cycle: (... - u - start - u - ...)
	                    cnt++;
	                    break;
	                }
	            }
	        }
	        else
	        {
	            for(int v : adj[u]) {
	                if(!vis[v])
	                    cycleLengthUtil(v, len - 1);
	            }

	            vis[u] = false;  // to use it again(for current state it is fixed vertex)
	        }
	    }

	    /****
	      ** Time Complexity : O()
	      ** Space Complexity : O(m)
	    ****/

	    // Gives the count of cycles with length 'len'
	    // Recommended to use this fxn when 'len' >= 3
	    int cycleLength(int len)
	    {
	        cnt = 0;
	        int n = adj.size() - 1;
	        n -= (len - 1);
	        // bcoz if we want cycle of length 'len' then there must be
	        // n - (len - 1) vertices which are in cycle(logical thing)

	        vis = vector<bool>(n, false);
	        for(int i = 0 ; i < n ; i++) {
	            start = i;
	            cycleLengthUtil(i, len - 1);
	            vis[i] = true;  // this will remove the count of same cycles
	        }
	        return cnt / 2;
	    }
	}

	int x, diam;
	void diameterUtil(int u, int p, int len)
	{
	    if(len >= diam) {
	        diam = len;
	        x = u;
	    }
	    
	    for(int v : adj[u])
	    {
	        if(v != p)
	            diameterUtil(v, u, len + 1);
	    }
	}

	/****
	  ** Time Complexity : O(m)
	  ** Space Complexity : O(m)
	****/

	// This function will return the diameter of a tree
	int diameter(int u = 1)
	{
	    x = u;
	    diam = 0;
	    diameterUtil(u, -1, 0);  // farthest node
	    diam = 0;
	    diameterUtil(x, -1, 0);
	    return diam;
	}
}