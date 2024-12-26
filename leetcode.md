# Leetcode Problems

## 3395. Subsequences with a Unique Middle Mode I 📳

This problem is solved using combinatrics and frequency map. Instead of counting pairs every time, use frequency and nCr formula. This reduces time complexity from `O(n^3)` to `O(n^2)`.

**One Piece of Information 🧩**
- Use map and combinatrics to find the number of pairs with required frequency of mode.

l = frequency of mode on left side, r = frequency of mode on right side,
otherL = number of elements other than mode on left side, otherR = number of elements other than mode on right side

```cpp
// 5 frequency: (2, 2)
ans = (ans + ncr(l, 2) * ncr(r, 2)) % mod;

// 4 frequency: (2, 1), (1, 2)
ans = (ans + ncr(l, 2) * (r * otherR)) % mod;
ans = (ans + (l * otherL) * ncr(r,2)) % mod;

// 3 frequency: (2, 0), (0, 2), (1, 1)
ans = (ans + ncr(l, 2) * ncr(otherR, 2)) % mod;
ans = (ans + ncr(otherL, 2) * ncr(r, 2)) % mod;
ans = (ans + (l * otherL) * (r * otherR)) % mod;

// 2 frequency: (1, 0), (0, 1) 
// Understand again
```

## 3394. Check if Grid can be Cut into Sections ⏹️

Solved using Sweep line algorithm.

**One Piece of Information 🧩**
- We can check one by one (first horizontally then vertically), to draw lines.
- Instead of considering rectangles, use either horizontal (x coordinates) or vertical (y coordinates) lines at a time.

```cpp
int startx = rectangles[i][0], endx = rectangles[i][2];
points.push_back({startx, 1});
points.push_back({endx, -1});
```

## 3393. Count Paths With the Given XOR Value 💝

Solved using 3D DP. Using `int dp[305][305][32];` works.

**One Piece of Information 🧩**
- At max XOR value can go till 31. Hence, we can track the ways to get possible xor values (not alone k).

```cpp
 for (int x=0; x<=31; x++) {
    int xr = x ^ grid[i][j];

    // comoing from up and down (with x as previous xor)
    dp[i][j][xr] = (dp[i][j][xr] + dp[i-1][j][x]) % mod;
    dp[i][j][xr] = (dp[i][j][xr] + dp[i][j-1][x]) % mod;
}
```

## 3392. Count Subarrays of Length Three With a Condition ⚖️

Solved using Sliding window algorithm.

**One Piece of Information 🧩**
- The constraints are small, we can check every subarray.

## 3362. Zero Array Transformation III 💌💌💌

**Using max heap**

**One Piece of Information 🧩**
- We need to know the candidate queries (`queries[j][0] <= i`)
- We use the candidate who has farthest ending point, `mxHeap.top()`;
- Use cur and psum to track the currently active queries. 

```cpp
cur += psum[i]

// later
while(cur < nums[i]) {
    psum[mxHeap.top() + 1]--;
    mxHeap.pop();
    cur++;
}
```

## 3356. Zero Array Transformation II 💌💌

Two ways:
1. using **segment trees** - range update (associative, commutative) and range query (max query).
    - After applying initial k queries, if Max of (1, n) <= 0, then k is answer. `O(m * log(n))`

2. **Binary Search** - binary search over k and use the previous question methods to check if became zero array.
    - Binary search tells how many initial queries to consider `log(m)`
    - Prefix sum method tells whether the array became zero array after applying mid queries. `O(n)`

 ```cpp
vector<int> ps(n+1, 0);
for (int i=0; i<k; i++) {
    ps[l] += val;
    ps[r+1] -= val;
}
 ```

## 3355. Zero Array Transformation I 💌

**One Piece of Information 🧩**
- Keep track of active queries with the help of frequency array.

```cpp
vector<int> ps(n+1, 0);
for (auto query : queries) {
    ps[query[0]]++;
    ps[query[1]+1]--;
}
```

You can call this prefix sum trick or sweep lines algorithm

## 3351. Sum of Good Subsequences 🧧

Using DP - 1D array.

**One Piece of Information 🧩**
- Use 1D array and DP.
- `count[x] += count[x-1] + count[x+1] + 1`
- `sum[x] += (sum[x-1] + sum[x+1] + x * (count[x-1] + count[x+1] + 1))`

Well, I identified the formula myself.

## 3350. Adjacent Increasing Subarrays Detection II 🕵🏽‍♀️

### Using Binary search 🔍

**One Piece of Information 🧩**

- Create incremental array to check if good.
- Use binary search to maximize k.

### Using 2 pointers 2️⃣

**One Piece of information 🧩**
- Track the length of previous and current increasing sequence length.
- No need to try any k, `ans = max(ans, prev/2, min(prev, cur))`

## 2762. Continuous Subarrays 🚉

**One Piece of Information 🧩**
- We are talking about subarrays, hence 2 pointer will be useful. For good subarrays do `ans += r-l+1;`.
- I just need to know the min and max of current subarray.

To know the min and max of current subarray, you can either use ` multiset<int>` or `map<int, int>` in cpp. 

```cpp
while(!ms.empty() && *ms.rbegin() - *ms.begin() > 2)
    ms.erase(ms.find(nums[l++]));

while(mp.rbegin()->first - mp.begin()->first > 2) {
    mp[nums[l]]--;
    if (mp[nums[l]] == 0) {
        mp.erase(nums[l]);
    }
    l++;
}
```

But map is more efficient because it can't grow more than 3 (size) while multiset can grow till `O(n)`.

## 2461. Maximum Sum of Distinct Subarrays With Length K 🪟

Solved using sliding window and hash map.

**One Piece of Information 🧩**
- Length of subarray is fixed, hence we can use sliding window.
- To check if all elements in window are distinct track the frequency of window elements.

## 1137. N-th Tribonacci Number 🔢

**One Piece of Information 🧩**
- Same as Fibonacci number problem, using variables `d = a + b + c`.

```cpp
int d = a + b + c;
a = b;
b = c;
c = d;
```

## 931. Minimum Falling Path Sum 🍂

**One Piece of Information**

- You can directly store the results in matrix itself.
- Check the value of j in each row, to not go out of bounds.

## 746. Min Cost Climbing Stairs 👛

**One Piece of Information 🧩**
- DP pattern, depends on last two variables.

`dp[i] = cost[i] + min(dp[i-1], dp[i-2])`

It can be easily implemented using variables.

## 740. Delete and Earn 🌾

**One Piece of Information 🧩**
- You can also use map as dp structure. 
- Count the frequency of elements to know total value of each number. 

```cpp
for (int i=2; i<= 20005; i++)
    dp[i] = i * freq[i] + max(dp[i-2], dp[i-3]);
```

## 516. Longest Palindromic Subsequence 🪗

Here, we have to find the length of the subsequence.The base case for both problems above is L==1, in that set [i][j] equal to true or 1.

**One Piece of Information**
- Solved using the Length, start point and end point algorithm.

```cpp
if (L==2) 
	len[i][j]=(s[i]==s[j])?2:1; 
else  
	len[i][j] = (s[i]==s[j]) ? (2+len[i+1][j-1]) : max(len[i+1][j], len[i][j-1]);
```

## 509. Fibonacci Number 🔢

**One Piece of Information 🧩**
- The next Fibonacci number depends only on last two numbers. hence c = a + b.

```cpp
int c = a + b;
a = b;
b = c;
```

## 221. Maximal Square 🐿️

It can be easily solved by DP, you just need to know the state transition.

**One Piece of Information**
- State transition is `dp[i][j] = 1 + min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1])`

## 198. House Robber 🏚️

**One Piece of Information 🧩**
- 2D DP array can be used to track the state values.
- After DP, it can be easily converted into variables.

```cpp
int tmp = notRob;

notRob = max(rob, notRob);
rob = nums[i] + tmp;
```

## 120. Triangle 🔺

**One Piece of Information**
- At each cell of every row, we can check if `(j==0)` or `(j==i)` to fill accordingly.
- To optimize space, you can store the results in triangle itself. Then space complexity becomes`O(1)`.

```cpp
if (j == 0) dp[i].push_back(dp[i-1][j]);
else if (j == i) dp[i].push_back(dp[i-1][j-1]);
else dp[i].push_back(min(dp[i-1][j], dp[i-1][j-1])); 
```

## 72. Edit Distance 🫛

This is solved by strings style DP.

**One Piece of Information**
- Use `dp[i][j]` to represent the min moves required to convert i length of word1 into j length of word2.
- If `word1[i-1] != word2[j-1]` then we can do insertion, deletion and substitution that is represented by `mn[i][j] = 1 + min(mn[i-1][j], mn[i][j-1], mn[i-1][j-1])`.

## 70. Climbing Stairs 🪜

The generic formulas for this is `dp[i] = dp[i-1] + dp[i-2] + ... + dp[i-k]`

**One Piece of Information 🧩**
- I just need to know the value of `ways[i-1]` and `ways[i-2]` values.

## 64. Minimum Path Sum ➕

It is solved using DP.

**One Piece of Information 🧩**
- Choose the previous state, that brings minimum cost. `dp[i][j] = nums[i] + min(dp[i-1][j], dp[i][j-1]);`

### DP without extra space

**One Piece of Information 🧩**
- Instead of using extra space, we can directly store the values in original matrix. ` grid[i][j] += min(grid[i-1][j], grid[i][j-1]);`

## 63. Unique Paths 🛣️🛣️

**One Piece of Information**

- If some cell contains obstacle, then ways to reach here is 0.
- Use if else inside for loop, to handle different cases.

## 62. Unique Paths 🛣️

It is solved using 2D DP.

**One Piece of Information 🧩**

- The state transition is easily identifiable. `dp[i][j] = dp[i-1][j] + dp[i][j-1]`

## 5. Longest Palindromic Substring 🤲🏽

`dp[i][j] = true`, if substring(i, j) is palindromic. This is solved using the length, start point and end point algorithm. This is used in many problems.

**One Piece of Information**
- Use the Length, start point and end point algorithm.

```cpp
for (int L=2; L<=n; L++) {  // Length

    for (int i=0; i<n-L+1; i++) {   // start of string
        int j = i+L-1;      // end of string
        
        if (L==2)
            palin[i][j] = (s[i] == s[j]);
        else 
            palin[i][j] = (s[i] == s[j] && palin[i+1][j-1]);
    }
}
```