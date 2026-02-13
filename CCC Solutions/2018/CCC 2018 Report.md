# 2018 CCC Report

---

### **CCC 18 J1 – Telemarketer or Not (ccc18j1)**

**Main idea / algorithm**

Check the first, second, and last digits of a phone number against telemarketer patterns.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.38s, 9.41 MB`

---

### **CCC 18 J2 – Occupy Parking (ccc18j2)**

**Main idea / algorithm**

Count positions where both rows have a car (‘C’).

**Time complexity**

O(n)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.28s, 10.46 MB`

---

### **CCC 18 J3 – Are We There Yet (ccc18j3)**

**Main idea / algorithm**

Compute Manhattan distances from (0,0) along row/column sums and fill a 5x5 table.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.11s, 10.03 MB`

---

### **CCC 18 J5 – Choose Your Own Path (ccc18j5)**

**Main idea / algorithm**

Use BFS to check connectivity in a directed book-choice graph; track depth to first leaf.

**Time complexity**

O(n + edges)

**Space complexity**

O(n + edges)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.72s, 12.10 MB`

---

### **CCC 18 S1 – Voronoi Villages (ccc18s1)**

**Main idea / algorithm**

Sort village coordinates; compute minimal distance between neighboring villages using midpoints.

**Time complexity**

O(n log n)

**Space complexity**

O(n)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.38s, 10.51 MB`

---

### **CCC 18 S2 – Sunflowers (ccc18s2)**

**Main idea / algorithm**

Rotate the 2D grid up to 4 times to find sorted rows; print the correctly oriented grid.

**Time complexity**

O(4 * n²)

**Space complexity**

O(n²)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.44s, 10.98 MB`

---

### **CCC 18 S3 – RoboThieves (ccc18s3)**

**Main idea / algorithm**

BFS from the starting cell while avoiding camera coverage and conveyor belts with chain movement.

**Time complexity**

O(n * m)

**Space complexity**

O(n * m)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`0.85s, 62.97 MB`

---

### **CCC 18 S4 – Balanced Trees (ccc18s4)**

**Main idea / algorithm**

Recursive counting with memoization of the number of balanced trees of size w using integer division intervals.

**Time complexity**

O(n log n)

**Space complexity**

O(n)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`4.89s, 69.51 MB`

---

### **CCC 18 S5 – Maximum Strategic Savings (ccc18s5)**

**Main idea / algorithm**

Sort edges and apply Kruskals + union-find with sizes to greedily select maximal savings in connecting cities horizontally and vertically

**Time complexity**

O((P+Q) log (P+Q) + α(N+M))

**Space complexity**

O(N + M + P + Q)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`6.54s, 92.21 MB` (PyPy3)
