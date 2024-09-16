# Problem Journal

## Codeforces Round 972

### The Strict Teacher (Hard Version)

Now, queries are not limited to 1.
For each position, find the closest teachers.

max left and min right maintain.

for each position, if should be able to find the left and right teachers.

```
left = 0, right = n+1
leftMax[] == 0 then this corner side
rightMin[] == n+1 then this is corner side

if (positions[i] == 1) left = i;
leftMax[] = left

starts from right side
if (postions[i] == 1) right = i
rightMin[] = right
```

**One Piece of Information**
- use maxLeft and minRight vector to find closest teachers positions.

### The Strict Teacher (Easy version)

q, queries = 1
m = number of teachers
b[] = position of the teachers
a[] = position of david

Find number of moves requires?
teachers minimize and david maximize

- David can't cross a teacher.

If david is in a corner 
- distance between corner and closest teacher.
otherwise
- distance between teachers around david / 2

**One Piece of Information**
- David can't cross a teacher.

### Simple Palindrome

Only two strategies possible, either keep same characters as far as possible or keep them together. Second one is correct.

**One Piece of Information**
- Keep same characters together.

n / 5 for each;
n % 5 => one from first n%5 character.