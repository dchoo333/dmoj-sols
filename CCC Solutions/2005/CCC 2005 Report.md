# 2005 CCC Report

### **CCC 05 J1 – The Cell Sell (ccc05j1)**

**Main idea / algorithm**

Compute the total cost for two cellphone plans using piecewise formulas based on usage, then compare the two totals to determine which plan is cheaper or if they tie.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.09s, 10.67 MB`

---

### **CCC 05 J2 – RSA Numbers (ccc05j2)**

**Main idea / algorithm**

For each integer in the given range, count its divisors and check whether it has exactly four divisors, incrementing a counter when it does.

**Time complexity**

O((b−a)·b) worst case due to divisor counting

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.09s, 10.57 MB`

---

### **CCC 05 J3 – Returning Home (ccc05j3)**

**Main idea / algorithm**

Read directions and street names until reaching SCHOOL, reverse the path, invert left and right turns, and print the instructions needed to return home.

**Time complexity**

O(N)

**Space complexity**

O(N)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.07s, 10.41 MB`

---

### **CCC 05 J4 – Cross Spiral (ccc05j4)**

**Main idea / algorithm**

This is harder than J5. Simulate movement on a grid in a spiral pattern while marking blocked cells and changing direction when obstacles or boundaries are encountered, stopping after a fixed number of steps or when trapped.

**Time complexity**

O(steps)

**Space complexity**

O(W·H)

**Difficulty**

Medium - Hard

**All DMOJ subtasks accepted in:**

`0.13s, 10.63 MB`

---

### **CCC 05 J5 – Bananas (ccc05j5)**

**Main idea / algorithm**

Validate strings by translating symbols into a mathematical expression and checking for syntactic correctness while rejecting invalid characters and empty groupings.

**Time complexity**

O(L)

**Space complexity**

O(L)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.09s, 10.34 MB`

---

### **CCC 05 S1 – Snow Calls (ccc05s1)**

**Main idea / algorithm**

Convert phone numbers by mapping letters to digits using a lookup table, remove hyphens, truncate to ten digits, and format the output consistently.

**Time complexity**

O(L)

**Space complexity**

O(L)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.03s, 10.03 MB`

---

### **CCC 05 S2 – Mouse Move (ccc05s2)**

**Main idea / algorithm**

Simulate mouse movement on a bounded grid by applying movement deltas and clamping the position to remain within the grid limits after each move.

**Time complexity**

O(N)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.13s, 10.00 MB`

---

### **CCC 05 S3 – Quantum Operations (ccc05s3)**

**Main idea / algorithm**

Repeatedly expand matrices using a Kronecker-style product, then compute maximum and minimum values across all cells, rows, and columns of the final matrix.

**Time complexity**

O(R·C) for final matrix size

**Space complexity**

O(R·C)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`1.22s, 44.06 MB`

---

### **CCC 05 S4 – Pyramid Message Scheme (ccc05s4)**

**Main idea / algorithm**

Use a stack to track nesting depth of messages, determine the maximum stack size reached, and compute the total time based on the deepest level.

Note text and brain**** solutions are possible with the weak test data (first BF solution on DMOJ)

```brainfuck
-[----->+<]>+.----.>++++++++++.+[->+++++<]>+.--------.>++++++++++.[->+++++<]>-.+++++.------.>++++++++++.++[->++++<]>.>++++++++++.[->+++++<]>-.+.--.>++++++++++.[->+++++<]>-.+++.----.>++++++++++.[->+++++<]>-.-..>++++++++++.++[->++++<]>.>++++++++++.-[----->+<]>.---.--.>++++++++++.+[->+++++<]>++.---.------.>++++++++++.
```

**Time complexity**

O(N)

**Space complexity**

O(N)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.02s, 10.47 MB`

---

### **CCC 05 S5 – Pinball Ranking (ccc05s5)**

**Main idea / algorithm**

Use coordinate compression and a Binary Indexed Tree to count inversions efficiently, then compute the average ranking score over all elements

Note python just barely TLE's with a 1:1 conversion of the provided cpp code, so just use C++ instead.

**Time complexity**

O(N log N)

**Space complexity**

O(N)

**Difficulty**

Medium-Hard

**All DMOJ subtasks accepted in:**

`0.12s, 4.73 MB`
