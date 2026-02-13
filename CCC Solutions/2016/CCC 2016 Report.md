# 2016 CCC Report

---

### **CCC 16 J1 – Tournament Selection (ccc16j1)**

**Main idea / algorithm**

Count wins (‘W’) and map total to the corresponding tournament place using a tuple.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.17s, 10.30 MB`

---

### **CCC 16 J2 – Magic Squares (ccc16j2)**

**Main idea / algorithm**

Check if the sums of all rows and columns are equal.

**Time complexity**

O(1), fixed 4×4 matrix

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.33s, 10.47 MB`

---

### **CCC 16 J3 – Hidden Palindrome (ccc16j3)**

**Main idea / algorithm**

Brute-force check all substrings and update the maximum length of palindromes.

**Time complexity**

O(n²), n = length of string

**Space complexity**

O(n)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.19s, 10.32 MB`

---

### **CCC 16 J4 – Arrival Time (ccc16j4)**

**Main idea / algorithm**

Simulate minute-by-minute time passage with double-speed periods and print final time.

**Time complexity**

O(d), d = 120 (fixed)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.42s, 10.55 MB`

---

### **CCC 16 S1 – Ragaman (ccc16s1)**

**Main idea / algorithm**

Count letters in both strings, compare, and check if number of missing letters can be filled with asterisks.

**Time complexity**

O(26) = O(1)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.56s, 10.93 MB`

---

### **CCC 16 S2 – Tandem Bicycle (ccc16s2)**

**Main idea / algorithm**

Sort both arrays; reverse one for max/min speed depending on the mode; sum maximum per pair.

**Time complexity**

O(n log n)

**Space complexity**

O(n)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.60s, 10.46 MB`

---

### **CCC 16 S3 – Phenomenal Reviews (ccc16s3)**

**Main idea / algorithm**

Prune non-photographed leaf nodes, then compute the longest path in the remaining tree to minimize total distance.

**Time complexity**

O(n)

**Space complexity**

O(n)

**Difficulty**

Medium–Hard

**All DMOJ subtasks accepted in:**

`3.25s, 32.28 MB`

---

### **CCC 16 S4 – Combining Riceballs (ccc16s4)**

**Main idea / algorithm**

Dynamic programming to combine contiguous riceballs if sum conditions match; track largest possible combined size.

**Time complexity**

O(n³)

**Space complexity**

O(n²)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`4.42s, 63.23 MB`

---

### **CCC 16 S5 – Circle of Life (ccc16s5)**

**Main idea / algorithm**

Use powers of two to simulate XOR evolution of a circular array efficiently by doubling step sizes.

**Time complexity**

O(n log t), n = array size, t = number of steps

**Space complexity**

O(n)

**Difficulty**

Medium–Hard

**All DMOJ subtasks accepted in:**

`1.03s, 85.64 MB` (PyPy3)
