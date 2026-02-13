# 2017 CCC Report

---

### **CCC 17 J1 – Quadrant Selection (ccc17j1)**

**Main idea / algorithm**

Check the signs of the x and y coordinates to determine the quadrant.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.35s, 9.34 MB`

---

### **CCC 17 J2 – Shifty Sum (ccc17j2)**

**Main idea / algorithm**

Precompute powers of 10 in a repeated digit pattern and multiply by input.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.35s, 10.44 MB`

---

### **CCC 17 J3 – Exactly Electrical (ccc17j3)**

**Main idea / algorithm**

Check if Manhattan distance parity matches the allowed moves and if distance ≤ moves.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.39s, 10.46 MB`

---

### **CCC 17 J4 – Favourite Times (ccc17j4)**

**Main idea / algorithm**

Simulate every minute on a 12-hour clock and count times matching a digit-difference pattern.

**Time complexity**

O(d), d = number of minutes

**Space complexity**

O(1)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`1.06s, 61.08 MB`

---

### **CCC 17 S1 – Sum Game (ccc17s1)**

**Main idea / algorithm**

Cumulative sums of two sequences; track last index where sums match.

**Time complexity**

O(n)

**Space complexity**

O(n)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.57s, 17.31 MB`

---

### **CCC 17 S2 – High Tide, Low Tide (ccc17s2)**

**Main idea / algorithm**

Sort the array, interleave the largest half in reverse with the smaller half.

**Time complexity**

O(n log n)

**Space complexity**

O(n)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.40s, 9.48 MB`

---

### **CCC 17 S3 – Nailed It (ccc17s3)**

**Main idea / algorithm**

Count pairs of numbers summing to each possible value using frequency arrays; track maximum pair count and number of sums achieving it.

**Time complexity**

O(n²) worst-case, n = max value ≤ 2000

**Space complexity**

O(4000)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`3.00s, 158.55 MB`

---

### **CCC 17 S4 – Minimum Cost Flow (ccc17s4)**

**Main idea / algorithm**

Sort edges by cost and priority, use union-find to select minimal-cost edges, then adjust for special conditions with extra edges ≤ k.

**Time complexity**

O(m log m + m α(n)), m = edges, α = inverse Ackermann

**Space complexity**

O(n + m)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`19.10s, 103.88 MB`

---

### **CCC 17 S5 – RMT (ccc17s5)**

**Main idea / algorithm**

Divide stations into blocks, track min/max in each block for efficient DP computation of maximum sugar sum, using square-root decomposition

There are over 470 test cases, so keep in mind, when you submit, you'll be waiting a while.

**Time complexity**

O(N √N)

**Space complexity**

O(N + BL²), BL = √N

**Difficulty**

Very Hard

**All DMOJ subtasks accepted in:**

`418.16s, 458.59 MB`!!!
