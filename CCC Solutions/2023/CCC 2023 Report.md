# 2023 CCC Report

---

### **CCC 23 J1 – Deliv-e-droid (ccc23j1)**

**Main idea / algorithm**

Compute total profit using the formula `P * 50 - C * 10 + 500` if `P > C`.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.19s, 10.31 MB`

---

### **CCC 23 J2 – Chili Peppers (ccc23j2)**

**Main idea / algorithm**

Use a dictionary mapping pepper names to Scoville values and sum the values over all inputs.

**Time complexity**

O(n)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.09s, 10.44 MB`

---

### **CCC 23 J3 – Special Event (ccc23j3)**

**Main idea / algorithm**

Count how many participants said “Y” for each of the 5 options and output all indices that achieve the maximum.

**Time complexity**

O(n)

**Space complexity**

O(n)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.23s, 10.46 MB`

---

### **CCC 23 J5 – CCC Word Hunt (ccc23j5)**

**Main idea / algorithm**

For every starting cell matching the first letter, perform DFS in all 8 directions, allowing at most one 90° turn, and count full matches.

**Time complexity**

O(n * m * 8 * |w|)

**Space complexity**

O(|w|)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.50s, 10.72 MB`

---

### **CCC 23 S1 – Trianglane (ccc23s1)**

**Main idea / algorithm**

Start with 3 sides per occupied cell and subtract shared edges between adjacent triangles.

**Time complexity**

O(n)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`1.34s, 15.96 MB`

---

### **CCC 23 S2 – Symmetric Mountains (ccc23s2)**

**Main idea / algorithm**

Expand around every possible center (odd and even lengths), track asymmetry cost, and store the minimum for each subarray size.

**Time complexity**

O(n²)

**Space complexity**

O(n)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`3.29s, 62.30 MB`

---

### **CCC 23 S3 – Palindromic Poster (ccc23s3)**

**Main idea / algorithm**

Construct a grid of characters based on constraints, handling special edge cases and possible rotation when dimensions swap.

**Time complexity**

O(r0 * c0)

**Space complexity**

O(r0 * c0)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`8.07s, 98.22 MB`

---

### **CCC 23 S4 – Minimum Cost Roads (ccc23s4)**

**Main idea / algorithm**

Process roads in decreasing cost order; temporarily remove each road and check via Dijkstra whether its endpoints remain connected within allowed length. If not, keep it and add its cost.

**Time complexity**

O(M * (N log N))

**Space complexity**

O(N + M)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`34.99s, 90.36 MB`

---

### **CCC 23 S5 – The Filter (ccc23s5)**

**Main idea / algorithm**

Recursively generate intervals of a Cantor-like construction, then simulate the transformation `x → 3x (mod 2n)` to detect cycles using a hash map.

**Time complexity**

Approximately O(K + generated values), where K is recursion depth

**Space complexity**

O(number of generated values)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`4.35s, 5.55 MB`
