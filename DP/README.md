# Dynamic Programming

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

1. Calculate nth fibonacci number - dp[i] = dp[i-1] + dp[i-2]
2. Climbing stairs (1 or 2 steps) - dp[i] = dp[i-1] + dp[i-2]
3. House robber (can't rob adjacent houses) - dp[i] = max(dp[i-2] + nums[i], dp[i-1])

### Tips:

- Usually can be optimized to O(1) space by keeping track of just previous 2 states
- Watch out for modulo requirements in large number problems
- Base cases are crucial - make sure they're handled correctly