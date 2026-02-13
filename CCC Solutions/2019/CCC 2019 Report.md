# 2019 CCC Report

---

### **CCC 19 J1 – Winning Score (ccc19j1)**

**Main idea / algorithm**

Compute weighted sums for both teams and compare results.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.33s, 10.46 MB`

---

### **CCC 19 J2 – Time to Decompress (ccc19j2)**

**Main idea / algorithm**

Repeat each string y by the integer x for n inputs.

**Time complexity**

O(total length of output)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.15s, 11.18 MB`

---

### **CCC 19 J3 – Cold Compress (ccc19j3)**

**Main idea / algorithm**

Run-length encode the input strings line by line.

**Time complexity**

O(length of string)

**Space complexity**

O(length of string)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.12s, 10.45 MB`

---

### **CCC 19 J5 – Rule of Three (ccc19j5)**

**Main idea / algorithm**

What the?!? The most impossible J5 and the most loathed CCC problem by far.

The idea is, use a custom bitset structure and KMP-like matching to simulate string transformations and find valid sequences. It will pass for all official CCC subtasks.

However for DMOJ (thanks very much d), there are added subtasks which create essentially an O(N) type of constraint on an inherently exponential problem. This solution will not pass.

In my opinion, this should be worth at least 25+pp. I've solved 30p+ that did not feel as impossible as this.

**Time complexity**

O(large, attempted to optimise with hashing and bitsets)

**Space complexity**

O(n * size of sets)

**Difficulty**

Very Very Hard

**All CCC/CEMC subtasks accepted in:**

`0.047s, 179.57 MB`

---

### **CCC 19 S1 – Flipper (ccc19s1)**

**Main idea / algorithm**

Determine parity of 'H' and 'V' flips; reverse rows/columns accordingly.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.49s, 12.05 MB`

---

### **CCC 19 S2 – Pretty Average Primes (ccc19s2)**

**Main idea / algorithm**

For each number, find two odd primes that sum to twice the number using trial division.

**Time complexity**

O(n * sqrt(max value))

**Space complexity**

O(1)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`1.55s, 10.52 MB`

---

### **CCC 19 S3 – Arithmetic Square (ccc19s3)**

**Main idea / algorithm**

Iteratively fill missing 'X' values using row/column arithmetic sequences until complete.

**Time complexity**

O(1) for 3x3 grid

**Space complexity**

O(1)

**Difficulty**

Medium-Hard (hard to understand initially)

**All DMOJ subtasks accepted in:**

`2.07s, 10.65 MB`

---

### **CCC 19 S4 – Tourism (ccc19s4)**

**Main idea / algorithm**

Another hard S4. Use dynamic programming with block decomposition and sliding window maximums to maximise scenic values.

**Time complexity**

O(n)

**Space complexity**

O(n)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`2.21s, 37.61 MB`

---

### **CCC 19 S5 – Triangle The Data Structure (ccc19s5)**

**Main idea / algorithm**

Apply repeated overlapping max operations on a triangular array with variable step sizes to sum maximums in sub-triangles.

**Time complexity**

O(n * k)

**Space complexity**

O(n²)

**Difficulty**

Hard

**All CCC/CEMC subtasks accepted in:**

`8.59s, 37.82 MB`
