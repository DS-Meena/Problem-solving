# Problem Journal

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