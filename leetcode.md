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

## 1964. Find the Longest Valid Obstacle Course at Each Position

Solved it using the famous LIS algorithm - tail vector algorithm. Only change here is that it is a non-decreasing sequence (means == is good).

**One Piece of Information**
- Tail vector algorithm has same application - we do binary search find index and replace old number -> This index is our answer.

```cpp
if (tail.empty() || tail.back() <= obstacles[i]) {
    tail.push_back(obstacles[i]);
    ans.push_back(tail.size());
} else {

    int ub = upper_bound(tail.begin(), tail.end(), obstacles[i]) - tail.begin();
    tail[ub] = obstacles[i];
    
    ans.push_back(ub+1);
}
```

## 1312. Minimum Insertion Steps to Make a String Palindrome

### 1st way: My way using dp

Yeah, I know it's hard to directly write the state transition. But you can start from recrusion -> memoization -> dp.

**One Piece of Information**
- Start the i pointer from 0 and j pointer from end, then try to make it palindrome.
- Use can pass Data structures using reference to reduce memory usage in function calls.

```cpp
int minMoves(int i, int j, string& s) {  // & to decrease memory usage
    if (i >= j) return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == s[j])
        return dp[i][j] = minMoves(i+1, j-1, s);

    int a = minMoves(i+1, j, s);
    int b = minMoves(i, j-1, s);
    return dp[i][j] = min(a, b) + 1;
}
```

### 2nd way: The editorial way

**One Piece of Information**
- The answer of the problem would be the length of `s` minus the length of the longest palindromic subsequence in `s`.
- This can be easily space optimized by using 2 arrays instead of a matrix.

Length of the longest palindromic subsequence = `LCS(s, s_reverse)`

```cpp
if (text1[i-1]==text2[j-1]) 
    dp[j] = 1 + prev[j-1];    // directly converted from LCS algorithm
else 
    dp[j] = max(prev[j], dp[j-1]);
```

## 1218. Longest Arithmetic Subsequence of Given Difference

Solved using DP. 

map[x] = longest ap (fixed difference) ending with value x 

`map[x] = max[x-difference] + 1`

**One Piece of Information**
- Difference is fixed, we only need to check of x-difference value or `lis[x-difference]`.

## 1143. Longest Common Subsequence

Solved using the LCS algorithm.

**One Piece of Information**
- Use LCS algorithm.

```cpp
if (a[i-1]==b[j-1])
	dp[i][j] = 1 + dp[i-1][j-1]
else
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```

## 1137. N-th Tribonacci Number 🔢

**One Piece of Information 🧩**
- Same as Fibonacci number problem, using variables `d = a + b + c`.

```cpp
int d = a + b + c;
a = b;
b = c;
c = d;
```

## 1035. Uncrossed Lines

Solved using LCS.

**One Piece of Information**
- Maximum number of lines we can draw is equals to the LCS.

## 1027. Longest Arithmetic Subsequence

Solved using the LIS algorithm.

`lis[i][diff] = longest app ending here, with difference = diff`

**One Piece of Information**
- Use LIS algorithm, instead of checking difference -> store the result of each difference.

```cpp
for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
        int d=nums[j]-nums[i] + 1000;   // +1000 to componsate the -ve differences
        
        dp[j][d] = max(2, dp[i][d] + 1);
    }
}
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

## 714. Best Time to Buy and Sell Stock with Transaction Fee

Solved using DP, like other buy and sell stock problems.

**One Piece of Information**
- It's easy after identifying the state transition.

```cpp
for (int i=1; i<n; i++) {
    buy[i] = max(buy[i-1], sell[i-1] - prices[i]);
    sell[i] = max(buy[i-1] + prices[i] - fee, sell[i-1]);
}
```

You can easily remove the use of dp array, because it depends only on previous values.

## 712. Minimum ASCII Delete Sum for Two Strings

dp[i][j] = minimum ascii delete sum required to convert i length of string1 into j length of string2.

`dp[i][j] = min(ascii(string1[i-1]) + dp[i-1][j], ascii(string2[j-1]) + dp[i][j-1])`;

**One Piece of Information**
- String style dp pattern should work here.
- If `s1[i-1] != s2[j-1]`, try deleting last character from both sides.

## 673. Number of Longest Increasing Subsequence

Solved using the LIS style dp pattern.

**One Piece of Information**
- In the LIS vector, I need to maintain two things **{longest LIS ending here, number of ways to get this LIS}**.

```cpp
if (lis[i].first < lis[j].first + 1)
    lis[i] = {lis[j].first + 1, lis[j].second};    // first time getting lis

else if (lis[i].first == lis[j].first + 1)   // found another way
    lis[i].second += lis[j].second;
```

## 646. Maximum Length of Pair Chain

Solved using LIS algorithm in O(n^2) time.

**One Piece of Information**
- Use the LIS algorithm after sorting the pairs.

### Greedy

Solved using Greedy algorithm in O(n) time with O(1) space.

**One Piece of Information**
- Sort pairs by end value.
- Keep track of end value in current chain.

```cpp
 // good chain pair
if (pairs[i][0] > end) {
    end = pairs[i][1];
    len++;
}
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

## 354. Russian Doll Envelopes

Solved using the tail algorithm.

**One Piece of Information**

- Sort by width, then we can apply tail algorithm on height dimension.
- For same width, sort in decreasing order of height. So that tail algorithm only counts it once.

```cpp
if (lis.empty() || lis.back() < h)  // increment lis
    lis.push_back(h);  
else {                              // replace old with smaller one's
    int l = lower_bound(lis.begin(), lis.end(), h) - lis.begin();
    lis[l] = h;
}
```

## 309. Best Time to Buy and Sell Stock with Cooldown

Each element in each array represents the maximal profits that we could gain at the specific price point i with the specific state.

**One Piece of Information**
- Use 3 arrays for cooldown, sell, buy. Then It's easy to write state transitions.

cool[i] = max profit if this is a cooldown time (no current buy)

buy[i] = max profit if this is a buy time (buying ith stock)

sell[i] = max profit if this is a sell time (selling current buy)

```cpp
cool[i] = max(cool[i-1], sell[i-1])
buy[i] = max(buy[i-1], cool[i-1] - price[i])
sell[i] = buy[i-1] + price[i]
```

## 300. Longest Increasing Subsequence

Solved using the tail algorithm. To understand better, do a dry run on example.

**One piece of information**

- Length increases only if we get element greater than the tail [*which can change*].
- For smaller elements, we greedily replace the old elements with smaller elements.

```cpp
for (int i=1;i<n;i++) {
    if (nums[i]<tail[0])
        tail[0]=nums[i];
    else if (nums[i]>tail[len-1]) {
        tail[len++]=nums[i];
    }
    else {
        int lb = lower_bound(begin(tail), begin(tail)+len, nums[i])-begin(tail);
        tail[lb]=nums[i];
    }
}
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

## 188. Best Time to Buy and Sell Stock IV

Solved using dp.

**One Piece of Information**
- We Just need to create k dimension dp array.

```cpp
buy[i][k] = max(buy[i-1][k], sell[i][k-1] - prices[i]);
sell[i][k] = max(buy[i-1][k] + prices[i], sell[i-1][k]);
```

## 123. Best Time to Buy and Sell Stock III

**One Piece of Information**
- In the first transaction we can't use the previous sell profit (because there is no previous sell).
- For other things, ith transaction uses ith transaction values.

```cpp
// first transaction
buy[i][0] = max(buy[i-1][0], -prices[i]);   // can't use old sell
sell[i][0] = max(buy[i-1][0] + prices[i], sell[i-1][0]);

// second transaction
buy[i][1] = max(buy[i-1][1], sell[i][0] - prices[i]);   // using old sell
sell[i][1] = max(buy[i-1][1] + prices[i], sell[i-1][1]);
```

[Check My leetcode solution](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/solutions/6323614/intitutive-buy-and-sell-stock-solution-e-cg84/)

## 120. Triangle 🔺

**One Piece of Information**
- At each cell of every row, we can check if `(j==0)` or `(j==i)` to fill accordingly.
- To optimize space, you can store the results in triangle itself. Then space complexity becomes`O(1)`.

```cpp
if (j == 0) dp[i].push_back(dp[i-1][j]);
else if (j == i) dp[i].push_back(dp[i-1][j-1]);
else dp[i].push_back(min(dp[i-1][j], dp[i-1][j-1])); 
```

## 115. Distinct Subsequences 🚉

Problem was to count subsequences which are equal to string t. Started with recursion then converted into a DP solution.

dp[i][j] = number of subsequences equal to string[0....j]

base case: `dp[i][0] = 1`

state transition (memoization helped in this):

`dp[i][j] = dp[i-1][j]`

`if (s[i-1] == t[j-1])  dp[i][j] += dp[i-1][j-1];`

**One Piece of Information**
- When not able to write dp state transition, start with recursion -> Memoization -> Iterative DP.
- Intermediate results can give interger overflow, even if mentioned final answer fits in 32-bit integer. To avoid this use mod.
- From previous row, we only need `dp[i-1][j]` and `dp[i-1][j-1]` value. Hence, if we store `dp[i-1][j-1]` in prev variable then it can be converted into 1D dp solution.

## 96. Unique Binary Search Trees

Problem is to count the number of unique BST for a given number of nodes.

**One Piece of Information**
- Try to go through the derivation of formula.

$g(n)$ = number of unique BST using n nodes

$f(i, n)$ = number of unique BST using n nodes and i as root node.

$$g(n) = \sum_{i=1}^n f(i, n)$$

**Ways to construct BST with i as root**

$$f(i, n) = g(i-1) * g(n - i)$$

where, left subtree has i-1 nodes and right subtree has n-i nodes.

Combining both formulas gives us:

$$g(n) = \sum_{i=1}^n g(i-1) * g(n-i)$$

```cpp
for (int i=2; i<=n; i++) {
    for (int j=1; j<= i; j++)
        dp[i] += dp[j-1] * dp[i-j];
}
```

## 95. Unique Binary Search Trees II

This is the alternate version of it's part. In this we have to return a list of all unique BST instead of just counting the number.

**One Piece of Information**
- Try to make `start <= i <= end` as root. Do same for left subtree (start, i-1) and right subtree (i+1, end).
- For each i root, try the combination of possible left and right subtrees.
- Each function call returns a list of BST.

```cpp
vector<TreeNode*> possibleLeftNodes = constructBST(start, i-1);
vector<TreeNode*> possibleRightNodes = constructBST(i+1, end);

for (int j=0; j<possibleLeftNodes.size(); j++) {
    for (int k=0; k<possibleRightNodes.size(); k++) {

        TreeNode* root = new TreeNode(i);
        root->left = possibleLeftNodes[j];
        root->right = possibleRightNodes[k];

        ans.push_back(root);
    }
}
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