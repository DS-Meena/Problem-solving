# String

# Pattern Searching

## Knuth–Morris–Pratt algorithm 🥝

In KMP algorithm we use prefix function to search patterns.

### Prefix function definition 🚘

You are given a string  S  of length  n . The **prefix function** for this string is defined as an array  pi of length  n , where  $\pi[i]$  is the length of the longest proper prefix of the substring  $s[0.…i]$  which is also a suffix of **this** substring.
A proper prefix of a string is a prefix that is not equal to the string itself.
By definition,  pi[0] = 0.

$$
\pi[i] = \max_ {k = 0 \dots i} \{k : s[0 \dots k-1] = s[i-(k-1) \dots i] \}
$$

For example, prefix function of string "abcabcd" is $[0, 0, 0, 1, 2, 3, 0]$ , and prefix function of string "aabaaab" is $[0, 1, 0, 1, 2, 2, 3]$.
    

### Algorithm 👚
    
So we finally can build an algorithm that doesn't perform any string comparisons and only performs O(n)  actions.

Here is the final procedure:

- We compute the prefix values $\pi[i]$  in a loop by iterating from  **$i = 1$  to  $i = n-1$** ( $\pi[0]$ just gets assigned with 0 ).
- To calculate the current value $\pi[i]$ we set the variable  j denoting the length of the best suffix for  i-1 . Initially $j = \pi[i-1]$.
- Test if the suffix of length $j+1$ is also a prefix by comparing  $s[j]$  and  $s[i]$. If they are equal then we assign  $\pi[i] = j + 1$ , otherwise we reduce j to  $\pi[j-1]$ and repeat this step.
- If we have reached the length j = 0 and still don't have a match, then we assign  $\pi[i] = 0$ and go to the next index  i + 1 .

```cpp
// Calculate pi-Array
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];   // previous best proper prefix
        
        // while not matches reduce
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
            
        // if matches increment prefix length by 1
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
```

**Result:**

`a c e $ a c e a c e`  [It utilizes information from previous best proper prefix]

`0 0 0 0 1 2 3 1 2 3 `

### Applications

1. Searching for a pattern in string.
    
    ```cpp
    // find the pattern
    int main()
    {
        string s, t;
        cin >> s >> t;
        
        string concat = t + "$" + s;      // pattern + text
        vector<int> pi = prefix_function(concat);

        // iterate the pi-array
        for (int i=1; i<concat.length(); i++)  {
            if (pi[i] == m)
                cout << i-2*m << " ";         // present at i-(m+1)-m+1 = i-2m
        }
    }
    ```
        
    **Complexity:** 

    $Time = O(n+m)$

    $Space = O(n+m)$
    
2. Counting the number of occurrences of each prefix.
3. Find the number of different substring in a string.
4. Compressing a string.
5. Building the automaton according to the prefix function.