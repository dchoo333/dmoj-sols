# 2015 CCC Report

---

### **CCC 15 J1 – Special Day (ccc15j1)**

**Main idea / algorithm**

Compare month and day to determine if the date is before, after, or on February 18.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.21s, 10.42 MB`

---

### **CCC 15 J2 – Happy or Sad (ccc15j2)**

**Main idea / algorithm**

Count occurrences of `:-)` and `:-(` to determine mood; handle ties and zero counts separately.

**Time complexity**

O(n), n = length of input string

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.23s, 11.22 MB`

---

### **CCC 15 J3 – Rövarspråket (ccc15j3)**

**Main idea / algorithm**

Transform consonants using nearest vowel and next consonant in alphabet; leave vowels unchanged.

**Time complexity**

O(n), n = length of input string

**Space complexity**

O(n)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.14s, 10.27 MB`

---

### **CCC 15 J4 – Wait Time (ccc15j4)**

**Main idea / algorithm**

Simulate a queue system, track total wait times for each customer, then compute differences based on order parity.

**Time complexity**

O(n)

**Space complexity**

O(n)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.07s, 10.49 MB`

---

### **CCC 15 J5 – π-day (ccc15j5)**

**Main idea / algorithm**

Dynamic programming to count partitions of `n` into exactly `k` positive integers.

**Time complexity**

O(n × k)

**Space complexity**

O(n × k)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.25s, 11.38 MB`

---

### **CCC 15 S1 – Zero That Out (ccc15s1)**

**Main idea / algorithm**

Use a stack to sum numbers, popping when zero appears.

**Time complexity**

O(n)

**Space complexity**

O(n)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.45s, 11.11 MB`

---

### **CCC 15 S2 – Jerseys (ccc15s2)**

**Main idea / algorithm**

Simulate jersey assignment and count successful swaps using an array to track availability.

**Time complexity**

O(a), a = number of requests

**Space complexity**

O(j), j = number of players

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`2.01s, 25.65 MB`

---

### **CCC 15 S3 – Gates (ccc15s3)**

**Main idea / algorithm**

Use a union-find structure to simulate planes docking at gates, counting total planes successfully assigned.

**Time complexity**

O(P log G) amortized, P = planes, G = gates

**Space complexity**

O(G)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`1.55s, 18.17 MB`

---

### **CCC 15 S4 – Convex Hull (ccc15s4)**

**Main idea / algorithm**

Use Dijkstra-style BFS with an additional height constraint to find shortest path under max height K.

**Time complexity**

O(M log N × K), M = edges, N = nodes

**Space complexity**

O(N × K)

**Difficulty**

Medium–Hard

**All DMOJ subtasks accepted in:**

`1.55s, 28.49 MB`

---

### **CCC 15 S5 – Greedy for Pies (ccc15s5)**

**Main idea / algorithm**

Recursive DP with memoisation to maximise pie score, switching between two arrays representing pie types.

**Time complexity**

O(N × M² × 2)

**Space complexity**

O(N × M² × 2)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`2.82s, 242.02 MB`
