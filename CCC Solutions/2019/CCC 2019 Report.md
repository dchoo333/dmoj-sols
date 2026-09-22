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

J5 may be the most loathed CCC problem on the DMOJ, with the [general concensus](https://dmoj.ca/problem/ccc19j5#comment-10966) being that it should be worth more points. I have only recently started revisiting this problem to achieve the remaining points in d's subtask. The code I ended up using to AC in the end (and that which is now under the solutions tab) had an algorithm of a sort of meet-in-the middle BFS. The brute force typically has branching^S states, and we can cut it to about branching ^ (S/2) per side. On top of that there are some small optimisations, such as each string being packed into a single u64, growing whichever frontier is currently smaller instead of fixed S/2, and pretty aggressive pruning on counts.

However, note that a [much faster](https://dmoj.ca/src/1865918) solution is possible. Suppose L is the length of the longest string that shows up during the search, and B is how many different next strings one state can produce in a single state. We work backwards from F and perform a DFS, memoising every dead state. By fixing the exact rule multiset first, memoising failures and stopping at the first solution a O(L * b^S) but O(S*L) typical can be achieved, with a maximum single-case runtime of 0.003s.

**Time complexity**

O(L*b^(S/2)), with some count pruning

**Space complexity**

O(sum of layer sizes)

**Difficulty**

Very Very Hard

**All DMOJ subtasks accepted in:**

`1.304s, 213.47 MB`

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

**All DMOJ subtasks accepted in:**

`8.59s, 37.82 MB`
