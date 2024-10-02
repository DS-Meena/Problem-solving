# Problem-solving
This repository is my problem solving journal. Will contain the learnings gained from solving coding problems.

# Mathematics ➗

Sum of AP:

$sum = \frac{len}{2} * (\text{first term} + \text{last term})$

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


## Tips for a Newbie (like me) 🤓

### Don't do this
1. Don't Learn complicated Data structures.
2. Focus on your level problems A and B.
3. Don't Stop Thinking if you still have ideas! Try yourself first.
4. Don't think on problem more than enough.
5. Don't Give up!

### Do this
1. Solve a lot of low difficult problems.
2. Implementations, Brute force and Mathematics tags.
3. You must reach 300 Accepts!
4. Participate in all CF Contests! Especially Div 3.
5. Read the codes of other people.