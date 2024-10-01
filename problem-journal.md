# Problem Journal

## Codeforces Round 976

## B. Brightness Begins 💡

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