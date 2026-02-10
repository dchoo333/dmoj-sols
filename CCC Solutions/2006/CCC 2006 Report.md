# 2006 CCC Report

### **CCC 06 J1 – Canadian Calorie Counting (ccc06j1)**

**Main idea / algorithm**

Store calorie values for each menu choice in arrays, read the selected options, sum the corresponding calories, and print the total in the required format.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.12s, 10.45 MB`

---

### **CCC 06 J2 – Roll the Dice (ccc06j2)**

**Main idea / algorithm**

Brute force all possible pairs of dice values within the given limits and count how many pairs sum to 10, then print the result with correct grammar.

**Time complexity**

O(a·b)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.16s, 10.18 MB`

---

### **CCC 06 J3 – Cell-Phone Messaging (ccc06j3)**

**Main idea / algorithm**

Simulate old phone keypad typing by mapping each letter to a key group and counting key presses, adding pauses when consecutive letters use the same key.

**Time complexity**

O(L)

**Space complexity**

O(1)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.02s, 10.30 MB`

---

### **CCC 06 J4 – It’s Tough Being a Teen! (ccc06j4)**

**Main idea / algorithm**

Model task dependencies as a directed graph, track indegrees, and repeatedly select tasks with zero prerequisites to produce a valid ordering or determine impossibility.

**Time complexity**

O(V²)

**Space complexity**

O(V²)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.24s, 10.58 MB`

---

### **CCC 06 J5 – CCC Othello (ccc06j5)**

**Main idea / algorithm**

Simulate an Othello board by applying each move, scanning in all eight directions to flip opponent pieces when bounded by the current player’s pieces, then count final totals.

Pretty diffcult to implement imo

**Time complexity**

O(M·64)

**Space complexity**

O(64)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`0.24s, 10.85 MB`

---

### **CCC 06 S1 – Maternity (ccc06s1)**

**Main idea / algorithm**

Construct the set of possible baby genes by combining parents’ alleles, then check each baby string to see if all characters are valid.

**Time complexity**

O(N·L)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.07s, 10.51 MB`

---

### **CCC 06 S2 – Attack of the CipherTexts (ccc06s2)**

**Main idea / algorithm**

Build a partial substitution cipher from known plaintext and ciphertext pairs, deduce the final mapping if possible, and decode the message using the mapping.

**Time complexity**

O(L)

**Space complexity**

O(1)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`2.50s, 10.38 MB`

---

### **CCC 06 S3 – Tin Can Telephone (ccc06s3)**

**Main idea / algorithm**

For each polygon, check whether the line segment between two people intersects any polygon edge using line intersection geometry, and count how many polygons block the signal.

**Time complexity**

O(N·E)

**Space complexity**

O(1)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`0.10s, 10.70 MB`

---

### **CCC 06 S4 – Groups (ccc06s4)**

**Main idea / algorithm**

Verify whether a table defines a group by checking for an identity element, inverses for every element, and associativity through triple nested checks.

**Time complexity**

O(N³)

**Space complexity**

O(N²)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`0.23s, 10.52 MB`

---

### **CCC 06 S5 – Origin of Life (ccc06s5)**

**Main idea / algorithm**

Represent each grid state as a bitmask, precompute all reverse transitions, then run BFS backward from the initial state to find the minimum number of generations or determine impossibility.

Hard, have to use C++.

**Time complexity**

O(2^(mn) · mn)

**Space complexity**

O(2^(mn))

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`2.08s, 51.23 MB`
