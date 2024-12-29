# Dynamic Programming

In this page, we will see some of the generic style DP patterns, that are used to solve many problems. Remember these are just patterns, when and how to use them depends on you. 💪🏽

# Fibonacci Style

These problems follow a pattern where each state depends on one or more previous states, similar to how fibonacci numbers work.

General pattern:

```cpp
// Base cases
dp[0] = first base case
dp[1] = second base case

// Build solution
for(int i = 2; i <= n; i++) {
    dp[i] = f(dp[i-1], dp[i-2]);  // function depends on problem
}
```

### Common variations:

1. Calculate nth fibonacci number - `dp[i] = dp[i-1] + dp[i-2]`
2. Climbing stairs (1 or 2 steps) - `dp[i] = dp[i-1] + dp[i-2]`
3. House robber (can't rob adjacent houses) - `dp[i] = max(dp[i-2] + nums[i], dp[i-1])`

### Tips:

- Usually can be optimized to O(1) space by keeping track of just previous 2 states
- Watch out for modulo requirements in large number problems
- Base cases are crucial - make sure they're handled correctly

# Matrix Style DP Problems 🫡

These problems involve a 2D grid/matrix where each cell's solution depends on adjacent cells (usually cells above and to the left).

General pattern:

```cpp
// Initialize first row and column
for(int i = 0; i < m; i++) dp[i][0] = init_value;
for(int j = 0; j < n; j++) dp[0][j] = init_value;

// Build solution
for(int i = 1; i < m; i++) {
    for(int j = 1; j < n; j++) {
        dp[i][j] = f(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);  // function depends on problem
    }
}
```

### Common variations:

1. Minimum path sum - `dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])`
2. Maximal square - `dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])` if grid[i][j] == 1
3. Unique paths - `dp[i][j] = dp[i-1][j] + dp[i][j-1]`

### Tips:

- Pay attention to initialization of first row and column
- Consider whether diagonal elements are needed for your recurrence
- Space optimization possible by using only two rows of memory

# Bitmask dp pattern

```cpp
// dp[i][j] = minium cell on which we can place jth snake (snakes present are i (bit format))
vector<vector<int>> dp(1<<n, vector<int>(n, INF));
for (int i=0; i<n; i++)
    dp[1<<i][i] = 1;

for (int mask=1; mask<(1<<n); mask++) {
    for (int lst=0; lst<n; lst++) {

        if (dp[mask][lst] == INF)
            continue;
        
        for (int nxt=0; nxt<n; nxt++) {
            if (mask & (1<<nxt))
                continue;

            int nmask = mask | (1<<nxt);
            dp[nmask][nxt] = min(dp[nmask][nxt], dp[mask][lst] + minDist[lst][nxt]);
        }
    }
}
```