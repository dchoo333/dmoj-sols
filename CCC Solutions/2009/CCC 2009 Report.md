# 2009 CCC Report

---

### **CCC 09 J1 – ISBN (ccc09j1)**

**Main idea / algorithm**

Compute the weighted 1–3 sum of digits in `9780921418` and the three input digits, then output the total.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.08s, 10.00 MB`

---

### **CCC 09 J2 – Old Fishin' Hole (ccc09j2)**

**Main idea / algorithm**

Brute force all non-negative combinations of three fish types, checking whether the total weight is within the limit and counting valid combinations.

**Time complexity**

O(T³), where T is the total allowed weight

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.28s, 10.09 MB`

---

### **CCC 09 J3 – Good Times (ccc09j3)**

**Main idea / algorithm**

Convert Ottawa time into other time zones using fixed offsets, handling wrap-around at 2400 and minute overflow.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.14s, 10.50 MB`

---

### **CCC 09 J4 – Signage (ccc09j4)**

**Main idea / algorithm**

Greedily pack words into lines of width `w`, then distribute dots evenly between words to justify each line.

**Time complexity**

O(N), where N is the number of characters

**Space complexity**

O(N)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.64s, 10.66 MB`

---

### **CCC 09 S1 – Cool Numbers (ccc09s1)**

**Main idea / algorithm**

Count integers whose sixth powers lie in the interval \([i, j]\) by computing tight bounds using sixth roots.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Easy–Medium

**All DMOJ subtasks accepted in:**

`0.14s, 10.15 MB`

---

### **CCC 09 S2 – Lights Going On and Off (ccc09s2)**

**Main idea / algorithm**

Represent each row as a bitmask and iteratively build all possible XOR combinations to count distinct lighting configurations.

**Time complexity**

O(R · 2^R) in the worst case, but small constraints make it feasible

**Space complexity**

O(2^R)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.12s, 10.51 MB`

---

### **CCC 09 S3 – Degrees of Separation (ccc09s3)**

**Main idea / algorithm**

Maintain a dynamic graph using adjacency sets and answer queries using BFS for shortest path and set operations for mutual connections.

**Time complexity**

O(V + E) per BFS query

**Space complexity**

O(V + E)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.10s, 10.74 MB`

---

### **CCC 09 S4 – Shop and Ship (ccc09s4)**

**Main idea / algorithm**

Run Dijkstra’s algorithm from all supplier cities simultaneously by initializing distances with shipping costs, then find the minimum cost to the destination.

**Time complexity**

O(N²) due to array-based Dijkstra

**Space complexity**

O(N²)

**Difficulty**

Medium–Hard

**All DMOJ subtasks accepted in:**

`3.03s, 98.91 MB`

---

### **CCC 09 S5 – Wireless (ccc09s5)**

**Main idea / algorithm**

Use a 2D difference array to apply circular signal strength updates efficiently, then scan the grid column by column to find the maximum signal and its frequency.

**Time complexity**

O(K · R + M · N), where K is the number of transmitters

**Space complexity**

O(M · N)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`0.33s, 118.15 MB`
