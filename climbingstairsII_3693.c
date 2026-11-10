int climbStairs(int n, int* costs, int costsSize) {
    long long a = 0, b = 0, c = 0;  
    long long INF = (long long)4e18;
    a = INF; b = INF; c = 0;        
    for (int j = 1; j <= n; j++) {
        long long best = c + 1;     
        if (b != INF && b + 4 < best) best = b + 4;
        if (a != INF && a + 9 < best) best = a + 9;
        best += costs[j - 1];
        a = b; b = c; c = best;
    }
    return (int)c;
}
