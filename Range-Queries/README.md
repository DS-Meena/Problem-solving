# Range Queries

We need to recall, what are associative and commutative operations while working with range queries.

The operation ⊗(⊗ is an arbitrary operation, for example +,∗ or *gcd*) is called:

- **Associative ()**, if $(a⊗b)⊗c=a⊗(b⊗c)$, that is, for any arrangement of parentheses in the expression, the result does not change,

**Commutative** 

If $a⊗b=b⊗a$, that is, for any order of arguments, the result does not change. With commutative operations, we don't require lazy propagation.

**Distributive Operation 🤨**

A distributive operation is one that satisfies the property of distributivity over another operation. In mathematical terms, an operation $\otimes$ is distributive over another operation $\oplus$ if:

 $a \otimes (b \oplus c) = (a \otimes b) \oplus (a \otimes c)$ 

For example, multiplication is distributive over addition:

 $a \times (b + c) = (a \times b) + (a \times c)$


# Mass Operations 🏋🏽‍♂️

In mass operations, we do range update.

## Range query with commutative 🥈

Associative, commutative and distributive

Suppose, we have two types of queries:

- modify(l, r, x): apply to each $a_i(l≤i<r)$ operation $\otimes$ with the second argument x, that is, $a_i = a_i \otimes x$,
- calc(l, r): calculate the function on the segment [l, r), that is, $a_l \odot a_{l+1} \odot … \odot a_{r-1}$

$\otimes$ and $\odot$ have following properties:

- $\otimes$ and $\odot$, both should be associative because we will be combining old and new nodes.
- $\otimes$ should be commutative.
- $\otimes$ should be distributive relative to $\odot$.

Example of possible operations:

| modify | calc |
| --- | --- |
| * | + |
| + | min, max |
| & | $\vert$ |

### Implementation

Below code is solution of [3356. Zero Array Transformation II](https://leetcode.com/problems/zero-array-transformation-ii/description/), but don't worry this same structure applies on multiple problems with these properties (associative, commutative and distributive).

Here, modify is substraction(minus of addition) and calculate operation is maximum. Addition is both associative and commutative. and maximum is associative. 

```cpp
#define ll long long

class segmentTree{

    vector<ll> tree, mx;
    int size;

    public:
    segmentTree(int n, vector<int>& arr) {
        size=1;
        while(size<n) size *= 2;
        tree.resize(2*size, 0LL);
        mx.resize(2*size, 0LL);

        for (int i=0; i<n; i++) {
            mx[i+size] = arr[i];
        }

        for (int i=size-1; i>0; i--) {
            mx[i] = max(mx[2*i], mx[2*i+1]);
        }
    }

    void add(int l, int r, int v, int lx, int rx, int val) {
        if (l > rx || r < lx) return;
        if (lx >= l && rx <= r) {
            tree[v] += val;
            mx[v] += val;
            return;
        }

        int mid = (lx+rx)/2;
        add(l, r, 2*v, lx, mid, val);
        add(l, r, 2*v+1, mid+1, rx, val);

        // apply addition while coming back (instead of propagating)
        mx[v] = max(mx[2*v], mx[2*v+1]) + tree[v];
    }

    void addition(int l, int r, int val) {
        add(l, r, 1, 0, size-1, val);
    }

    int findMax(int l, int r, int v, int lx, int rx) {
        if (l > rx || r < lx) return 0;
        if (lx >= l && rx <= r) return mx[v];

        int mid = (lx+rx)/2;
        int a = findMax(l, r, 2*v, lx, mid);
        int b = findMax(l, r, 2*v+1, mid+1, rx);
        return max(a, b) + tree[v];   // same as addition
    }

    int getMax(int l, int r) {
        return findMax(l, r, 1, 0, size-1);
    }
};

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        segmentTree st = segmentTree(n, nums);

        for (int k=0; k<queries.size(); k++) {
            
            // appling before, because k can be 0 also
            if (st.getMax(0, n-1) <= 0)
                return k;

            st.addition(queries[k][0], queries[k][1], -queries[k][2]);
        }

        if (st.getMax(0, n-1) <= 0)
            return queries.size();
        
        return -1;
    }
};
```

Complexity: 

    time: O(logn) for both addition and maximum operations.
    space: O(2*n)