# Dynamic Programming

In this page, we will see some of the generic style DP patterns, that are used to solve many problems. Remember these are just patterns, when and how to use them depends on you. 💪🏽

# Fibonacci Style 🤘

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

# String Style DP Problems 🧵

Common patterns in string-based dynamic programming problems:

- **State Definition:** Usually `dp[i][j]` represents solution for substrings of length i and j
- **Transition:** Often involves checking if characters match and taking max/min of different possibilities
- **Base Cases:** Usually involve empty strings or single characters

Common techniques with example code:

### Two String pattern 💑

Compare/match two strings character by character (like LCS, Edit Distance)

```cpp 
// Base cases - empty string
for(int i = 0; i <= m; i++) dp[i][0] = i;
for(int j = 0; j <= n; j++) dp[0][j] = j;

// Fill dp table
for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
        if(word1[i-1] == word2[j-1])
            dp[i][j] = dp[i-1][j-1];
        else
            dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
    }
}
```

### Single String Pattern 👲

Find properties within one string (like palindrome, substring problems)

```cpp
// Base cases - single chars are palindromes
for(int i = 0; i < n; i++) 
    dp[i][i] = true;

// Check all possible lengths
for(int len = 2; len <= n; len++) {
    for(int start = 0; start < n-len+1; start++) {
        int end = start + len - 1;
        
        if(len == 2)
            dp[start][end] = (s[start] == s[end]);
        else
            dp[start][end] = (s[start] == s[end]) && dp[start+1][end-1];
    }
}
```

Key points to remember:

1. Initialize base cases properly (empty strings, single characters)
2. Consider all possible operations at each step
3. Use previous computed results efficiently
4. Handle edge cases separately

# LIS (Longest increasing subsequence) Style DP Pattern 

Idea – fix the ending points and find the longest increasing subsequence.

lis[i] = longest increasing subsequence with arr[i] as ending point.

```cpp
vector lis(n, 1);

for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {

        if (a[j] < a[i])
            lis[i] = max(lis[i], lis[j] + 1);
    }
}

return *max_element(begin(lis), end(lis));
```

Complexity: 

time = $O(n^2)$ and space = $O(n)$

### Tail vector approach:

Idea - Maintain a tail array where tail[i] represents the smallest possible value that can end an increasing subsequence of length i+1.

```cpp
vector<int> tail;

for (int num : nums) {
    // Find position to insert using binary search
    auto it = lower_bound(tail.begin(), tail.end(), num);
    
    // If num is greater than all elements, append it
    if (it == tail.end())
        tail.push_back(num);
    else
        *it = num; // Replace the element at position
}

return tail.size();
```

Complexity: time = $O(n log (n))$ and space = $O(n)$

Key points:

- tail[i] represents smallest value that can end an increasing subsequence of length i+1
- Binary search is used to find the position where current element should be placed
- If current element is larger than all tail elements, append it
- Otherwise, replace the smallest element that is ≥ current element

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