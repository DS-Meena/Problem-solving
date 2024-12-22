
# Mathematics ➗

Sum of AP:

$sum = \frac{len}{2} * (\text{first term} + \text{last term})$

## Combinatrics 🪮

The nCr formula, also known as the binomial coefficient, is used to calculate the number of ways to choose r elements from a set of n elemetns without regard to the order of selection. The formula is given by:

$\binom{n}{r} = \frac{n!}{r!(n-r)!}$

where:

- n = total number of items
- r = number of items being chosen
- ! denotes factorial

**Special conditions 👓**
1. If `r>n`: then nCr is 0, you can't choose more elements than are available.
2. If `r == 0` or `r == n`: The value of nCr is 1.
3. If `r = 1`: The value of nCr is n because there are n ways to choose one element from n elements.

```cpp
ll nCr(ll n, int r) {
    if (n < r) return 0;
    if (r == 0 || r == n) return 1;
    if (r == 1) return n;

    // r == 2 (count ways to choose pairs)
    return ((n * (n-1))/2) % mod;  // comes from formulae

    // other ways, you code
}    
```

## Number Theory 

To make x % y == 0, we need to add following value to x:
`amount_to_add = (y - (x % y)) % y`

## Divisors ➗➗

### Number of divisors 🤿🤿

According to [**fundamental theorem of arithmetic**](https://en.wikipedia.org/wiki/Fundamental_theorem_of_arithmetic) or **unique factorization theorem** and **prime factorization theorem**, states that every integer greater than 1 can be represented uniquely as a product of prime numbers, up to the order of the factors.

Example →

${1200=2^{4}\cdot 3^{1}\cdot5^{2}=(2\cdot2\cdot 2\cdot 2)\cdot 3\cdot (5\cdot 5)=5\cdot 2\cdot 5\cdot 2\cdot 3\cdot 2\cdot 2= ...}$

The theorem says two things about this example: first, that 1200 *can* be represented as a product of primes, and second, that no matter how this is done, there will always be exactly four 2s, one 3, two 5s, and no other primes in the product.

Therefore if the prime factorization of  n  is  $p_1^{e_1} \cdot p_2^{e_2} \cdots p_k^{e_k}$ , where  $p_i$ are distinct prime numbers, then the number of divisors is:

**$d(n) = (e_1 + 1) \cdot (e_2 + 1) \cdots (e_k + 1)$**

- **Divisor Pairs:** Most divisors come in pairs. If a divides n, then n/a also divides n.
- **Odd Number of Divisors:** A number has an odd number of divisors if and only if it's a perfect square. This is because perfect squares have an unpaired divisor (the square root).

### Related Formulas

1. Number of divisors for a perfect square:
    
    If $n = a^2$, then the number of divisors of n is $2k + 1$, where k is the number of prime factors of a.
