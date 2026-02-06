# 2002 CCC Report

### **CCC 02 J1 – 0123456789 (ccc02j1)**

**Main idea / algorithm**

Essentially, just hardcode the ASCII patterns. Not too difficult, watch for whitespace though

**Time complexity**

O(1) – constant number of print operations

**Space complexity**

O(1) – no extra data structures

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.27s, 10.58 MB`

---

### **CCC 02 J2 – AmeriCanadian (ccc02j2)**

**Main idea / algorithm**

Read words until `"quit!"`. For each word, if it ends in `"or"`, has length greater than 3, and the preceding letter is not a vowel or `y`, replace `"or"` with `"our"`. Otherwise, keep the word unchanged.

**Time complexity**

O(L) per word – L is word length

**Space complexity**

O(N) – storing all output words

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.02s, 10.20 MB`

---

### **CCC 02 S1 – The Student’s Council Breakfast (ccc02s1)**

**Main idea / algorithm**

Brute force all valid combinations of tickets using four nested loops, each representing one ticket type. For each combination that sums to the total cost, print it, count total combinations, and track the minimum number of tickets used.

**Time complexity**

O(T⁴) in worst case – bounded by ticket costs

**Space complexity**

O(1) – only counters and variables

**Difficulty**

Medium - Easy

**All DMOJ subtasks accepted in:**

`0.07s, 10.50 MB`

---

### **CCC 02 S2 – Fraction Action (ccc02s2)**

**Main idea / algorithm**

Convert an improper fraction into a mixed number. Compute quotient and remainder, reduce the fractional part using GCD, and print either an integer, proper fraction, or mixed number depending on the result.

**Time complexity**

O(log d) – due to GCD computation

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.21s, 10.54 MB`

---

### **CCC 02 S3 – Blindfold (ccc02s3)**

**Main idea / algorithm**

Precompute paths for all four possible starting directions based on the instruction list. For each grid cell, test whether placing the robot there causes it to hit a wall or exit the grid. If valid, mark the final position with `*`.

**Time complexity**

O(R·C·M) – R rows, C columns, M instructions

**Space complexity**

O(R·C + M) – grid, walls, and path storage

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`0.43s, 11.04 MB`

---

### **CCC 02 S4 – Bridge Crossing (ccc02s4)**

**Main idea / algorithm**

Dynamic programming where `dp[i]` is the minimum time to cross the first `i` people. For each state, try sending 1 to m people, taking the maximum crossing time in the group. Track group sizes to reconstruct the optimal grouping.

**Time complexity**

O(n·m)

**Space complexity**

O(n) – DP and reconstruction arrays

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`0.12s, 10.59 MB`

---

### **CCC 02 S5 – Follow the Bouncing Ball (ccc02s5)**

**Main idea / algorithm**

Model the ball’s path as a straight line by reflecting the room instead of the ball. Compute intersections with vertical and horizontal walls using linear equations. Count how many wall hits occur until the ball comes within 5 units of a corner.

**Time complexity**

O(K) – iterating over wall crossings until termination

**Space complexity**

O(1)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`1.35s, 10.39 MB`
