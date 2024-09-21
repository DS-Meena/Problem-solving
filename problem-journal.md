# Problem Journal

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