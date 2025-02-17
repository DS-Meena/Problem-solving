# Problem Journal

# Codeforces Round #998 (Div. 3)

I was able to solve 4 problems in the contest and 1 problem in upsolving.

## 2060A - Fibonacciness

There are only 3 possible values. [e-d, d-b, a+b]. Choose the value that gives maximum point.

## 2060B - Farmer John's Card Game

**One Piece of Information**
- Track the cows that contributes to a specific mod.
- One cow should contribute in one mod only.

```cpp
int mod = card % n;
mods[mod].insert(i+1);

// if same mod is present with multiple cows
if (mods[mod].size() > 1) ok = false;
```

## 2060C - Game of Mathletes

**One Piece of Information**
- The move played by Alice doesn't matter.
- Bob will get a point, whenever we find a pair.

```cpp
ll y = k - x;

if (nums.find(y) != nums.end()) {
    score++;
    nums.erase(nums.find(y));
} else {
    nums.insert(x);
}
```

## 2060D - Subtract Min Sort

**One Piece of Information**
- Try to make starting numbers zero. Apply the operation at every location.
- In last check, if still not good.

## 2060E - Graph Composition

**One Piece of Information**
- Use DSU to check if two vertices are connected or not [belong to same component].
- First create the DSU for graph2, then iterate graph1 and remove the extra edges.
- After removing extra edges create DSU for graph1, then iterate graph2 and add edges if required.

```cpp
for (int i=1; i<=n; i++) {
    
    vector<int> safe;
    for (int v : adj1[i]) {

        // belong to different components in DSU of graph2
        if (find(v, par2) != find(i, par2))
            ans++;
        else 
            safe.push_back(v);
    }

    adj1[i] = safe;
}
```

# Codeforces Round #674 (Div. 3)

I was able to solve 5 questions myself (within allotted time). and F solved during upsolving.

## 1426A - Floor Number

It is a simple math's problem.

```cpp
if (n <= 2) cout << "1\n";
else cout << (n+x-3) / x + 1 << endl;
```

## 1426B - Symmetric Matrix

Just need to check one condition.

**One Piece of Information**
- If there exists a symmetric tile, then we can create a symmetric square.

## 1426C - Increase and Copy

This took a little extra time, I knew binary search will be used but was consfused about how many increment and how many append operations to do.

**One Piece of Information**
- We will greedily do all increment operations first, after that do append operations.
- If we are given x operations, then best strategy is to divide equally for increment and append operations [*Required for binary search*].
- Binary search over total number of operations required.

```cpp
bool good(int n, int total) {
 
    int x = (total+1) / 2;
    int y = total/2;
 
    return ((x+1) * (y+1)) >= n;
}

int lo=0, hi=1;
while(!good(n, hi)) hi *= 2;     // without this was giving more answer
```

## 1426D - Non-zero Segments

I solved it using set (to check if found a 0 segment sum). My idea is to insert +INF before last number of zero subsegment. 

**One Piece of Information**
- The sum of the segment $[l;r]$ is zero if $p_r−p_{l−1}$ is zero (in other words, $p_l−1=p_r$), where $p_i$ is the sum of the first i elements ($p_0=0$).
- I can also add +INF, to make sure numbers before +INF can't be used by later numbers.

```cpp
// insert inf and start new set (& subsegment)
if (sums.find(cur) != sums.end() || cur == 0) {
    ans++;
    cur = ar[i];
    sums.clear();
} 
```

## 1426E - Rock, Paper, Scissors

**One Piece of Information**
- The maximum number of rounds Alice can win is pretty easy to calculate greedily: $min(a_1,b_2)+min(a_2,b_3)+min(a_3,b_1)$.
- To get minimum number of wins, she must either lose or draw using the available operations.

```cpp
ll mxWin = min(ar, bs) + min(as, bp) + min(ap, br);

// min win
// consume ar
// consume as
// consume ap

// using remaining ar, as, ap
ll mnWin = min(ar, bs) + min(as, bp) + min(ap, br);
```

## 1426F - Number of Subsequences

I couldn't solve this problem by myself, have to see the solution.

$dp_{i,j,k}$ as the number of subsequences of s that end up in position not later than i, match j first characters of abc and contain k question marks.

**One Piece of Information**
- For every such subsequence, the number of strings containing it is $3^k−q^{Pos(pa,pb,pc)}$, where $q^{Pos(pa,pb,pc)}$ is the number of positions from pa,pb,pc that contain a question mark.

```cpp
dp[0][0][0] = 1;

// not matches
dp[i+1][j][k] = add(dp[i+1][j][k], dp[i][j][k]);

// matches
if (j < 3 && (s[i] == '?' || s[i]-'a' == j)) {
    int nk = (s[i] == '?') ? k + 1 : k;

    dp[i+1][j+1][nk] = add(dp[i+1][j+1][nk], dp[i][j][k]);
}
```

# Codeforces Round #498 (Div. 3)

3 solved during virtual contest and 2 by upsolving.

## 1006A - Adjacent Replacements

Found the pattern, that odd values remains same and even value reduces by 1.

**One Piece of information**
- We always go increasing, hence x and x-1 will not be updated again. But x+1 will be updated again.

## 1006B - Polycarp's Practice

Solved using sorting, multiset and some implementation logic.

**One Piece of Information**
- We only care about the k largest values.
- Store largest k values in multiset -> place separator after each of them.

```cpp
int prev=0;
for (int i=0; i<n && k>1; i++) {
    
    // if one of the peaks, cut
    if (peaks.find(ar[i]) != peaks.end()) {
        cout << i - prev + 1 << " ";
        prev = i+1;
        peaks.erase(peaks.find(ar[i]));
        k--;
    }
}
cout << n-prev << endl;
```

## 1006C - Three Parts of the Array

Solved using two pointers.

**One Piece of Information**
- Start i pointer from 0 and j pointer from n-1.
- Track maximum segment sum, which satisfies sum1 == sum3.

```cpp
if (sum1 <= sum3) {
    i++;
    sum1 += ar[i];
} else {
    j--;
    sum3 += ar[j];
}
```

## 1006D - Two Strings Swaps

I also got this idea and code structure, but couldn't check the conditions correctly.

**One Piece of Information**
- We only need to check the (a[i], b[i], a[n-1-i], b[n-1-i]) characters.
- Count frequency and check few conditions.

```cpp
if (freq.size() == 4)   // check conditions using distinct characters count
    ans += 2;
else if (freq.size() == 3) 
    ans += 1 + (a[i] == a[n-i-1]);   // pair in a
else if (freq.size() == 2)
    ans += freq[a[i]] != 2; // not a pair
```

## 1006E - Military Problem

I implemented the O(h*q) [worst case: h = n] solution but it was giving TLE. Then used editorial to implement O(n+q) solution.

**One Piece of Information**
- Store the dfs path in a vector.
- Store the start and end indices of every subtree (associated with a vertex).

```cpp
void dfs(int u, vector<int>& path, vector<p>& index) {
 
    path.push_back(u);
    index[u].first = path.size() - 1;    // in index
 
    for (int v : graph[u]) {
        dfs(v, path, index);
    }
 
    index[u].second = path.size();   // out index
}
```

## 1006F - Xor-Paths

Couldn't get AC even after using editorial. The idea used is simple, to reduce the depth of recursion from O(2^40) to O(2^20), we will use meet in the middle technique.

**One Piece of Information**
- We can't store all 10^18 values, hence will only store the visited xor values. `map<ll, int> dp[20][20];`
- Do recursion from start and from the end.

```cpp
// from start
val ^= a[x][y];
if (cnt == half) {  // half way
    ++v[x][y][val];
    return;
}

// from end
if (cnt == n + m - 2 - half) {
    if (v[x][y].count(k ^ val))
        ans += v[x][y][k ^ val];
    return;
}
```

# Codeforces Round #494 (Div. 3)

3 solved during virtual contest and 3 by upsolving.

## 1003A - Polycarp's Pockets

Solved using hash map.

**One Piece of Information**
- We need at max k pockets, where k = max frequency of an element.

## 1003B - Binary String Constructing

I solved by first creating a string containing only '0' or '1'. Then x/2 times added '0' or '1' in the middle with spacing.

**One Piece of Information**
- Instead of finding, I tried creating the string.
- Start with basic structure then incorporate the other details.

```cpp
string s = string(n, l);  // l can be '0' or '1'

// last piece
if (x%2==1) {  // increase by 1  (00000111)
    for (int i=n-b; i<n; i++) s[i]=r;
} else {      // increase by 0    (00001111000)
    for (int i=lst+1; i<=lst+b; i++) s[i] = r;
}
```

## 1003C - Intense Heat

Time limit was enough to use a `O(n^2)` solution.

**One Piece of Information**
- Try all window sizes and use sliding window algorithm.

## 1003D - Coins and Queries

I solved it by counting the available coin types (bit positions). Then Greedily tried to decrease sum by iterating from 31st bit to 0th bit of sum.

I solved it myself at 1600 problem.

**One Piece of Information**
- `log2(x)` gives the only set bit position in x.
- 1 x set bit can be consumed by 2 x-1 set bit coins. 
- While coming down, double the requirements of set bits (or coins).

```cpp
for (int b=31; b>=0; b--) {
 
    if (x & (1<<b))
        cur++;
    
    // use the 2^b coins
    if (cur > 0 && freq[b] > 0) {
        ans += min(cur, freq[b]);
        cur = max(0, cur-freq[b]);
    }

    // requirement doubles when goes down
    cur *= 2;
}
```

## 1003E - Tree Constructing

Graph problem. I got the structure of problem, but got TLE because didn't used set to track free vertices.

**Free vertex:**
- where degree < k
- farthest leaf node distance < d 

If above conditions satisfy then adding one more vertex at this node, won't ruin our structure.

Note -> On adding a new node at free vertex, the distance from any free vertex to farthest leaf node does not changes because we never increases the diameter of tree.

**One Piece of information**
- Start creating from the basic structure. Create d+1 nodes long tree.
- Using set track all the free vertices, where we can add a new vertex. [Mistake: I tried using DFS]
- Update set after adding each new vertex (old node might not be valid now, add new node).

```cpp
// add other vertices
for (int i=d+2; i<=n; i++) {
    
    if (!freeVertices.empty()) {    
        p v = *freeVertices.begin();
        freeVertices.erase(freeVertices.begin());

        tree[v.second].push_back(i);
        tree[i].push_back(v.second);

        // enter new free vertex (mistake)
        if (v.first+1<d)
            freeVertices.insert({v.first+1, i});

        // old node (mistake)
        if (tree[v.second].size() < k)
            freeVertices.insert(v);
    } else {
        cout << "NO\n";
        return 0;
    }
}
```

## 1003F - Abbreviation

Solving using DP and using L length algorithm.

What we need to solve problem -> Try all equal segments and to know their (should not overlap each other and equal)

`dp[i][j]` = length of longest equal segment starting at i and j
```cpp
vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
for (int i=n-1; i>=0; i--) {
    for (int j=n-1; j>=0; j--) {
        if (text[i] == text[j])
            dp[i][j] = 1 + dp[i+1][j+1];
    }
}
```

**One Piece of information**
- Use dp to check if segment starting at i and j are equal or not.
- Use L length algorithm, to check all starting position and all length equal segmetns. Count the number of equal segments also.

```cpp
for (int i=0; i<n; i++) {
    for (int L=1; L<= n; L++) {
        int j = i+L, cnt=1;

        while (j<n) {
            if (dp[i][j] >= L) {  // equal segment
                cnt++;
                j += L;
            } else 
                j++;                  
        }
    }
}
```

time: `O(n^3)`

---
---
# 2025
---

# Codeforces Round 994 (Div. 2) 🎆

## 2049A - MEX Destruction 

**One Piece of Information**
- First remove 0's from both ends, then it's easy to solve.
- There are 3 cases to check.

```cpp
while(!a.empty() && a.back() == 0)
    a.pop_back();
reverse(a.begin(), a.end());
// repeat
```

## 2049B - pspspsps

**One Piece of Information**
- If $s_n$ is p, then set $s_n$ as `.` and if $s_1$ is s, then set $s_1$ as `.`.
- In the middle, both s and p can not exist simultaneously.

## 2049C - MEX Cycle

This can be solved if you try the possible cases:
- Case 1: Even number of people.
    - Distance (y-x) is odd 
    - Distance is even
- Case 2: Odd number of people
    - Distance is odd
    - Distance is even.

**One Piece of Information**
- $a_i=mex(a_{f_1},a_{f_2},…,a_{f_k})$ means $a_i$ will have that his friends doesn't have.
- You just need to satisfy the friends (adjacent, some extra (x-y)).

```cpp
for (int i=0; i<n; i++) a[(x+i) % n] = i%2;
if (n%2 || (y-x)%2 == 0)
    a[x] = 2;
```

## 2049D - Shift + Esc

**One Piece of Information**
- Write as `g(i, j, x)` helped in writing state transition.
- `g(i, j, x)` min cost to reach to cell(i, j).
- If n==20, then in dp algorithms, it's mostly a 3D dp solution.

```bash
# moving horizontally
g(i, j, x) = g(i, j-1, x) + cell(i, (j+x)%n) 

# moving vertically
g(i, j, x) = g(i-1, j, y) + cell(i, j)
```

# Codeforces Round 995 (Div. 3) 🎄

## 2051A - Preparing for the Olympiad

It can be easily solved by implementation.

**One Piece of Information**
- Train on ith day if `a[i] - b[i+1] > 0`, otherwise skip.

## 2051B - Journey

This also can be easily solved by implementation.

**One Piece of Information**
- Instead of checking one by one, do `days = n // (a+b+c) * 3`.
- Process the mod separately.

```cpp
day = n/(a+b+c) * 3;

int rem = n%(a+b+c)
if (rem == 0) return day;
else if (rem - a <= 0) return day+1;
else if (rem - (a+b) <= 0) return day+2;
return day+3;
```

## 2051C - Preparing for the Exam

We are given a answer list and a set of questions (missing questions are mentioned). Total n questions are present in syllabus.

**One Piece of Information**
- If answer list's `size < n-1`, then he can't pass any exam.
- If answer list's `size == n`, then he can pass any exam.
- For other cases, If the missing question on question list, is also missing from answer list then he will pass. Otherwise, fail.

To check, if current question is also missing from answer list - I can use set or boolean array.

```cpp
if (present[ques[i]] == 0) cout << "pass";
```

## 2051D - Counting Pairs

We have to find number of interesting pairs. On removing intersting pair, `x <= remaining array sum <= y`. 

1. Brute force -> check all pairs. `O(n^2)`. Too slow.

### Some Maths

On solving the equations we get, `a[j] <= total - a[i] - x (large)` && `a[j] >= total - a[i] - y (small)`. Hence for each a[i], we need to find numbers that lies between [small, large].

**One piece of Information**
- There is a common trick in problems of the form "count something on segment [l,r]": calculate the answer for [0,r], and then subtract the answer for [0,l−1]. 💖💖

```cpp
// [0, large] - [0, small-1]
ll r = upper_bound(a.begin(), a.end(), large) - a.begin();
ll l = upper_bound(a.begin(), a.end(), small-1) - a.begin();

ans += r-l;

// if i==j also satisfies the condition
if (small <= a[i] && a[i] <= large) ans--;
```

## 2051E - Best Price

**One Piece of Information**
- We only need to check 2n prices, as given in array `a` and `b`.
- To calcualte earnings - find number of sold trees. `price <= b[i]` 
- To check if valid price - find number of negative reviews. `sold_trees - positive_reviews`, in positive review `price <= a[i]`

## 2051F - Joker

Wow, I solved this myself.

How does joker position changes, cases:
1. pos < joker: new positions are `{joker, joker-1}`;
2. pos > joker: new positions are `{joker, joker+1}`;
3. pos == joker: new positions are `{1, n}`;

**One Piece of Information**
- There are only few ways in which the position of jocker changes.
- Instead of checking all positions one by one, handle them in intervals.
- You can use auxillary set to update the intervals. 🤗
- You can use stack to merge the intervals. 🤗

```cpp
for (auto& it : intervals) {
    if (it.first > pos) {
        updated.insert({it.first-1, it.second});
    } 
    else if (it.second < pos) {
        updated.insert({it.first, it.second+1});
    }
    else {
        // tricky part
        if (it.first != pos) updated.insert({it.first, pos});
        if (it.second != pos) updated.insert({pos, it.second});
        updated.insert({1, 1});
        updated.insert({n, n});
    }
}
```

## 2051G - Snakes

`dp[bitmask][j]` = minimum cell on which we can place jth snake, placed snakes are represented using bitmask (including jth snake) 🐍

**One Piece of Information**
- First find, minimum distance required between ith and jth snakes.
- To handle the snake position permutation, use bitmask dp. Here, bitmask will represent all the snakes placed till now. `dp[1<<i][i] = 1;`

```cpp
for (int nxt=0; nxt<n; nxt++) {
    if (mask & (1<<nxt))
        continue;

    int nmask = mask | (1<<nxt);  // nmask after placing nxt snake
    dp[nmask][nxt] = min(dp[nmask][nxt], dp[mask][lst] + minDist[lst][nxt]);
}

 ans = min(ans, dp[(1<<n) - 1][i] + enlarge[i]);
```

time: O(1<<n * n^2)

# Brute force, Math, Implementation (1000-1200)

## B. Incinerate 🐦‍🔥

We have follow attacks:
- reduce health of all monsters by k, health[i] -= k
- after attach, k reduces by power of weakeast monseter, k -= power[i]

Can he kill all monsters before k reaches to 0?

-----

**One Piece of information 🧩**
- Sort by power, so that we don't have to search for weakest alive monster's power level.
- Keep track of total_damage and curr_attack power.

## C. Premutation 🦋

**One piece of information 🧩**
- Every column has some rank associated with it. First comers (column wise) are values more.

### C. Turtle Fingers: Count the Values of k 🖐️

Given 3 positive intergers: a, b, l. We can always find, k, x and y such that $l = k . a^x . b^y$

Find the number of distinct possible values of k?

----

**One Piece of information 🧩**
- The number of distinct values of k, depends on the combination of x and y.
- (a^x . b^y) should be divisor of l.

**Approach 👏**
1. Iterate over all possible values of x and y.
2. If $a^x . b^y$ is a divisor of l. Insert into set.
3. return size of set.

```cpp
// The other way
// Iterate over possible values of a^x and b^y
for(ll i = 1; i<=l; i*=a){
    for(ll j=1; j*i<=l; j*=b){
        if((l%(i*j))==0){    // overall it should divide l
            s.insert(l/(i*j));
        }
    }
}
```

### B. Collatz Conjecture 🥸

variable - x, constant y.

An operation is performed k times:
- x++
- while(x%y == 0) x /= y

Find final value of x?

----------------------------------------

1. If brute force was allowed, then just implement.
2. Using some optimization find the final value.

If x becomes 1:
ans = 1 + rem % (y-1)

**One Piece of Infomation 🧩**
- After x becomes 1, it follows the same sequence to y.
- To make x divisible by y, add $y - (x \mod y)$ to x.

**Mistake**
- Wrong inference, that once start dividing it will end < y.

### B. Three Brothers (800)

**One Piece of information 🧩**
- Only 3 options are there.

## Codeforces Round 976

### B. Brightness Begins 💡

Initiall all bulbs are on. The final state of ith bulb depends on the number of divisors of i.
- On -> even number of divisors -> not perfect square
- off -> odd number of divisors -> perfect square

**One Piece of Information 🧩**
- Perfect square has an odd number of divisors (off).

It becomes, find kth number which is not a perfect square (on)? Binary search can be used.

$n - off == k => n - sqrt(n) == k$


## A. Find Minimum Operations 😱

$n = n - K^x$ for any x>=0

Find minimum operations required to make n equal to 0.

**One Piece of Information 🧩**
- Instead of doing k operations of x=0, a single operation x=1 will do the job.
- Min operations = $O(log_kn)$

## Codeforces Round 975

## All Pairs Segments

**One Piece of information 🧩**
- Using formula calculate, in how many intervals does point p lies.

$x_{i+1} - x_i - 1$ points contained in exactly $i(n-i)$ intervals (becaue there are i possible left endpoints and n-i possible right endpoints).

Similarly, point $p=x_i$ is contained in $i(n-i+1)-1$ intervals (remove interval $[x_i, x_i]$).

## Max Plus Size

**One Piece of Information 🧩**
- There are two ways of coloring, start red at 0 or at 1.

## Codeforces Round 974

## Renez-vous de Marin et Robin 🐎

They define rating by algorithm. The framing of problem remains same. It just the solution will be using different algorithms.

Marian starts at 1 and robin starts at vetex n. There are h horses are also available on vertices. Horse reduces the further travel time in half.

**One Piece of information 🧩**
- Find shortest path to all nodes for both one by one using Dijkstra's algoritm.
- Use 2d distance vector for with horse and without horse distance.
- They don't need to cross each other.

#### Dijkstra's algorithm 🏇

```cpp
void dijkstra(int source, vector<vector<ll>> &d, vector<vector<p>> &graph, vector<bool> &hs) {

    // comparator for set
    auto cmp = [&](auto &a, auto &b) {
        return make_pair(d[a.first][a.second], a) < 
                make_pair(d[b.first][b.second], b);
    };

    set<pair<int, int>, decltype(cmp)> mnHeap(cmp);

    d[source][0] = 0;
    mnHeap.insert({source, 0});

    while(!mnHeap.empty()) {

        auto [u, withHorse] = *mnHeap.begin();
        mnHeap.erase(mnHeap.begin());

        // do we have a horse
        bool horse = (withHorse || hs[u]);

        for (auto &[v, w] : graph[u]) {

            ll dist = horse ? w/2 : w;
            if (d[v][horse] > d[u][withHorse] + dist) {
                
                mnHeap.erase({v, horse});
                d[v][horse] = d[u][withHorse] + dist;

                mnHeap.insert({v, horse});
            }
        }
    }
}

// look at this
ll best = 1e18;

// lambda function
auto get = [&](int a) {return max(min(d1[a][0], d1[a][1]), min(d2[a][0], d2[a][1]));};

for (int i=0; i<n; i++) {
    best = min(best, get(i));
}

```



## Robert Hood and Mrs Hood 🤶

**One piece of information 🧩**
- Find the window (start) with max overlapping jobs for brother and min overlapping jobs for mother.
- Use prefix sum arrays: for total started and total finished jobs.

We care about the start day of the window.

### Sliding window 🪟

```cpp
// prefix sum arrays: total started and total finished
for (int i=0; i<n; i++) ss[i+1] += ss[i];
for (int i=0; i<n; i++) es[i+1] += es[i];

// number of jobs in the window (total_started - total_finished)
int curr = ss[i] - es[i-d];
```

## Robin Hood in Town 🗼

After sorting:

$a_j < \text{half of average} = \frac{s+x}{2*n}$

$x > 2 * n * a_j - s$

To make, more than half population unhappy use:

$x = max(0, 2 * n * a[j] - s + 1)$

**One Piece of Information 🧩**
- After sorting, We can check if good, by checking j = n/2 index.
- Use formula to find minium value of x, no need to apply binary search.


Impossible: 
n = 1 or n = 2.

## Robin Hood and the Major Oak 🌳

We have an oak tree, that grows $i^i$ leaves in the ith year.
Leaves fall down after k years:
In the i+k year the leaves will fall down. 

**One Piece of information 🧩**
- $i^i$ has same parity as i. 
- Just find the sum of k consequetive intergers ending in n.

$n, n-1, n-2, ..., n-(k-2), n-(k-1)$

$sum = \frac{len}{2} * (\text{first term} + \text{last term})$

$sum = \frac{k}{2} * {n + n - (k-1)}$

$sum = \frac{k}{2} * {2n - k + 1}$

```cpp
int n, k; cin >> n >> k;

ll sum = ((2 * n - k + 1) * k) / 2;

if (sum % 2 == 0) cout << "YES\n";
else cout << "NO\n";
```

## Robin Helps 🏹

**One Piece of information 🧩**
- N is less, just simulate and calculate.


# Codeforces Round 973

## Minimize the Difference ⛏️

**One Piece of Information 🧩**
- make the numbers close to each other.
- Use stack to process the numbers.

## Password Cracking 🔑

Queries: System will tell, if predicted string t is a substring of his password or not.
? t

**One Piece of Information 🧩**
- It's a binary string bro.
- I can either add in begging or add in the end.

Approach:
1. Initially, try to create a prefix with the help of at max 2 queries. `curr = curr + "0"` or `curr = curr + "1"`.
2. If both options are wrong for prefix.
    - start creating a suffix with the help of 1 query. `curr = "0" + curr` or `curr = "1" + curr`.

## Battle for Survive ⚔️

My Idea: Reduce all numbers from 2nd last number, make it -ve. Then reduce this -ve from last number (-ve -ve becomes +ve).

Final sum = $a_1 + a_2 + ... + a_{n-2} - a_{n-1} + a_n$

**One Piece of information 🧩**
- In the end always n-1 remains.
- It's value => a[n-1] - a[n-2] + sum(a[0]...a[n-3])

## Zhan's Blender 🧃

There are only 2 cases:

case1:  x <= y:

$time = \frac{n+1}{x}$

case 2:

$time = \frac{n+1}{y}$

**One Piece of information 🧩**
- Time required depends on the smaller value between x and y.

## Codeforces Round 972

### The Strict Teacher (Hard Version) 🧑‍🏫

Only change from previous: $m, q <= 10^5$, not limited to 2 and 1 respectively.

```cpp
positions.push_back(pos);
sort(positions.begin(), positions.end())
int k = lower_bound(postions.begin(), positions.end(), pos) - positions.begin();
// easy to check the cases
```

- I can't iterate the whole positions array for every query. O(q * m)

**One Piece of Information 🧩**
- Sort the positions array and use binary search to find closest teachers.

Complexity:

time: O(nlog(n) + q * log(n))

### The Strict Teacher (Easy version) 🧑‍🏫

Find number of moves requires?
teachers minimize and david maximize

- David can't cross a teacher.

There can be following cases based on david's position:
1. David is in left corner: leftmost_teacher_position - 1
2. David is in right corner: n - rightmost_teacher_position
3. David is in between two teachers: (distance between both teachers)/2

**One Piece of Information 🧩**
- Store the positions of teachers in array and sort it. Instead of marking the position as true.
- There are only 3 cases, just check the case.
- David can't cross a teacher.

**Mistake**
- I didn't noticed m=2
- i was marking the positions as true (using array of size $10^9$) instead of storing in an array.

### Simple Palindrome 🤦

String with minimum palindromic subsequences.

**One Piece of Information 🧩**
- Keep same characters together to decrease number of palindromic subsequences.

n / 5 for each;
n % 5 => one from first n%5 character.