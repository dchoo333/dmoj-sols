# 2013 CCC Report

---

### **CCC 13 J1 – Next in Line (ccc13j1)**

**Main idea / algorithm**

Compute the next number in an arithmetic sequence of length 3 using the formula `-a + 2b`.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.13s, 10.08 MB`

---

### **CCC 13 J2 – Rotating Letters (ccc13j2)**

**Main idea / algorithm**

Check if all letters in the input belong to the set of letters symmetric under 180° rotation (`I`, `O`, `S`, `H`, `Z`, `X`, `N`).

**Time complexity**

O(n), n = length of string

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.27s, 9.75 MB`

---

### **CCC 13 J4 – Time on Task (ccc13j4)**

**Main idea / algorithm**

DMOJ, where is J3/5? Sort task durations and pick as many as fit in the total allowed time `T`.

**Time complexity**

O(n log n), n = number of tasks

**Space complexity**

O(n)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.14s, 9.88 MB`

---

### **CCC 13 S1 – From 1987 to 2013 (ccc13s1)**

**Main idea / algorithm**

Increment the year until all digits are unique.

**Time complexity**

O(Δy × d), Δy = difference between start year and next valid year, d = digits per year (≈4)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.40s, 10.01 MB`

---

### **CCC 13 S2 – Bridge Transport (ccc13s2)**

**Main idea / algorithm**

Simulate trucks crossing a bridge in order, keeping track of the last three weights to ensure the maximum is not exceeded.

**Time complexity**

O(b), b = number of trucks

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.61s, 9.93 MB`

---

### **CCC 13 S3 – Chances of Winning (ccc13s3)**

**Main idea / algorithm**

Use DFS to explore all outcomes of remaining games and count how many lead to team `T` winning the group, accounting for 3 possible results per game.

**Time complexity**

O(3^g), g = number of unplayed games (≤6 for 4-team groups)

**Space complexity**

O(1) extra; modifies scores in-place

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`0.19s, 10.66 MB`

---

### **CCC 13 S4 – Who is Taller (ccc13s4)**

**Main idea / algorithm**

Use BFS to check reachability in a directed graph representing "taller than" relationships. Must use `sys.stdin.readline` fast input to avoid TLE.

**Time complexity**

O(n + m), n = number of students, m = number of comparisons

**Space complexity**

O(n + m)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`6.57s, 119.79 MB`

---

### **CCC 13 S5 – Factor Solitaire (ccc13s5)**

**Main idea / algorithm**

Beautiful solution to an otherwise hard problem.

Simulate the solitaire game by repeatedly picking a factor `x` of the current number `n` and removing `n // x` from `n`, accumulating the score.

**Time complexity**

O(n √n) in worst case

**Space complexity**

O(1)

**Difficulty**

Medium–Hard

**All DMOJ subtasks accepted in:**

`1.23s, 11.34 MB`
