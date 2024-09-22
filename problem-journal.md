# Problem Journal

## Codeforces Round 974

### Renez-vous de Marin et Robin

They define rating by algorithm. The framing of problem remains same. It just the solution will be using different algorithms.

n vertices [1 to n]
m edges
u_i, v_i, w_i (seconds) - all w_i are even.

Marian starts at 1 and robin starts at vetex n.
There are h horses are also available on vertices. Horse reduces the further travel time in half.

Find earliest time, Robin and Marian can meet. If 1 and n are disconnected output -1.

**One Piece of information**
- Find shortest path to all nodes for both one by one.


#### Graph
We have graph. Find minimum time it takes to meet them at any vertex.

Initially find shortest path to each node for Marian.
Single source shortest path - Dijkstra we can use.

We do same for both robin and Marian. Our time = min(time, marian[i] + robin[i]).

- they should not need to cross each other.

How do we use the horse in Dijkstra's algorithm?

**Example**:




### Robert Hood and Mrs Hood

Maximize number of distinct overlaps with brother and minimize from mother.

Both will come for once only. You can decide the dates. 

n (total days), d(duration of visits), k(number of jobs)
l_i, r_i (start and end day of each job)

**One piece of information**
- The jobs are also overlapping.
- I need find a window of d days.

#### Sliding Window

Means some days he can do more jobs. He should call his brother on more jobs days and his mother on less jobs days.

I need find a window of d days - on which most jobs are done.
I need find a window of d days - on which least jobs are done.

1 2 1 0 2 1 3 2 1  => this would be easy
but we need to calcualte this number of jobs done for each day also.

That's also easy. I can use prefix sum (for jobs[l_i]++, jobs[r_i + 1]--).

time complexity: O(n)
space complexity: O(n)

Example: 
0 0 0 0 0 0 0 0 (7+1)
2 0 -1 -1 0 1 0 -1
2 2 1 0 0 1 1 

We need to compare number of distinct jobs no just number of jobs in a day.

### Robin Hood in Town

Minimize the value of x for which Robin hood will appear.

What's the condition for good:

more than half of population are unhappy.
unhappy => wealth <= (aveage)/2

To calcualte unhappy => iterate all of population O(n)

It will be impossible in case of what.
- we can make x very large, so that average becomes skewed.
- all of the majority will lie far from the average.

Impossible: 
n = 1 or n = 2.

**One Piece of Information**
- apply binary search to minimize x.

```cpp



```



### Robin Hood and the Major Oak

We have an oak tree, that grows i^i leaves in the ith year.
1 year - 1^1   = 1  - 1+k year 
2 year - 2^2   = 5 
3 year - 3^3   = 14

Leaves fall down after k years:
In the i+k year the leaves will fall down. 

We need to find, if in nth year the tree will have even number of leaves.

1 => 5 => 14 => 30 => 55
           13    25    41

Let's assume if previous values are not coming:
even * even = even
odd * odd = odd

Also, it depends on the sum of (last k-1 years): if their sum is odd or even.

1 2 3 4 [5 6 7 8] 9
If k is even => half odd and half even => even => then depends on nth only
If k is odd => 
    1 2 3 4 5 [6 7 8] 9  => if k is odd and n is odd => then sum is odd => ans (total even)
    1 2 3 4 [5 6 7] 8 9  => if k is odd and n is even => then sum is even => ans (total even)

**One Piece of information**
- The result depends only on the parity of n and k.

```
int n, k; cin >> n >> k;
k--;

bool res = true;
if (k % 2 == 0) {
    res = (n%2 == 0);    
}

if (res) cout << "YES\n";
else cout << "NO\n";
```

### Robin Helps

**One Piece of information**
- N is less, just simulate and calculate.


## Codeforces Round 973

## Minimize the Difference

n = length of the array
1 <= a[i] <= 10^12

Operation:
a[i]-- and a[i+1]++

Minimize max(a1,a2,...,an) - min(a1,a2,...,an) after any number of operations.

What does our operation do: it increases the difference between a[i] and a[i+1] by 2.
Opposite of what we want.




## Password Cracking

n = size of binary string (1 <= n <= 100)

Queries:
System will tell, if predicted string t is a substring of his password or not.
? t

Response of query:
1 if substring
0 otherwise

Final answer:
! s

Find password in <= 2n queries.

We have find the password, using these types of queries.

**One Piece of Information**
- It's a binary string bro.
- I can either add in begging or add in the end.

Ask a substring => that is not substring of any of your previous queries.

Choices:
00101010101

0 => 00 => 000
        => 001 => 0010 => 00100
                       => 00101 => 001010 => 0010100
                                          => 0010101 => 00101010 => 001010100
                        
To increase my correct length by 1, it at max takes 2 queries. That means, i should be able to grow of size n in 2n queries.


Where is it wrong?
I might not grew from start. It might start from in between.


## Battle for Survive

n fighters
array[i] = rating of ith fighter

output = maximum rating last remaining fighter can preserve

Operation:
choose pair of index = (i, j)
i will be eliminated, j will remain always. It depends only on index.
a[j] -= a[i]

To keep j higher, what can i do? Choose i with smallest value.
choose all fighters to fight with n-2.
In end fight (n-2, n-1).

a[n-1] - (a[n-2] - a[n-3] - a[n-4] ... - a[0])
(sum[0...n-3])

Will it work always?
- if i < n-2 are huge, then good
- if i==n-2 is huge than sum. But n-2 can't remain in the end. Always n-1 remains in the end.

**One Piece of information**
- In the end always n-1 remains.
- It's value => a[n-1] - a[n-2] + sum(a[0]...a[n-3])


### Zhan's Blender

T test cases, n number of fruits that zhan has
x = number of fruits it can blend, 
y = number of fruits you can put in it

Have to blend n fruits, n = 
case x < y:
    time = (n+1) / x
else 
    time = (n+1) / y

**One Piece of information**
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