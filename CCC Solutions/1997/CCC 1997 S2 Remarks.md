# CCC 97 S2 – Nasty Numbers (ccc97s2)

---

### **Perculiarity**

It is possible to cheese the problem using a simple divisibility / modulo check.

``` python
for num in [int(input()) for _ in range(int(input()))]:
    print(f"{num} is nasty") if num % 6 == 0 else print(f"{num} is not nasty")
```
However, althought it passes all DMOJ test cases, the algorithm is actually wrong. We can prove this by construction of a counterexample:

### Check factor pairs of 12

We have all factor pairs of 12:  

$$
(1,12),\ (2,6),\ (3,4),
$$

Obviously, those three are unordered pairs implying their sum and difference is the same.

For each pair, compute:

- **Product** $a \cdot b$ (trivially =12, but demonstrate)
- **Sum** $a + b$  
- **Difference** $|a - b|$  

| Pair    | Product | Sum  | Difference |
|---------|--------|------|------------|
| (1,12)  | 12     | 13   | 11         |
| (2,6)   | 12     | 8    | 4          |
| (3,4)   | 12     | 7    | 1          |

Observing the sums and differences, there exists: 11, 13, 8, 4, 7 and 1. there are **no duplicates** that satisfy |difference of one pair = sum of another pair|  

This implies that 12 does **not** satisfy the strict nasty number condition, even though it is divisible by 6

### Observation

Hence this would imply something about the strength of the test cases, and that submissions should be rejudged with stronger input.

However, we can obtain a more comprehensive solution. The current, most efficient Python solution is [given](https://github.com/dchoo333/dmoj-sols/blob/main/CCC%20Solutions/1997/CCC%2097%20S2%20-%20Nasty%20Numbers%20(ccc97s2).py).

### **Algorithm**

- For each number `n`, we look at all divisors `i` up to √n  
- For every divisor, we form two values: the sum of the pair `(i + n/i)` and the difference `(n/i - i)`  
- Store all these values in a list called `p`  
- If any value in `p` occurs more than once, it means there exist two distinct factor pairs that satisfy the nasty number condition |difference = sum|  
- If we find such a duplicate, we declare `n` as nasty  
- If no duplicates exist, then `n` is not nasty  

---

### **Time complexity**

- Finding divisors up to √n → O(√n)  
- Creating sums and differences → O(√n)  
- Checking duplicates in the list → worst-case O(√n²) = O(n)  

**Worst case:** O(n) per number  

---

### **Space complexity**

- Storing all sums and differences → O(√n)  
- Extra variables for loops → O(1)  

**Total space:** O(√n)  

---

See the code for the solution, available under this directory.

### **All DMOJ subtasks accepted in:**

`0.02s, 10.44 MB`
