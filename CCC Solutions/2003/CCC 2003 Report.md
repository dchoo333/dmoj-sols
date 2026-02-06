# 2003 CCC Report

### **CCC 03 J1 – Trident (ccc03j1)**

**Main idea / algorithm**

Make trident. Use loops and string multiplication for alignment.

**Time complexity**

O(t + h) – t prongs and h handle lines

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.12s, 10.41 MB`

---

### **CCC 03 J2 – Picture Perfect (ccc03j2)**

**Main idea / algorithm**

For each input number, find its divisors and compute candidate rectangle perimeters. Select the rectangle with minimum perimeter and handle small edge cases separately. Print minimum perimeter and rectangle dimensions.

**Time complexity**

O(N·√C) – N inputs, C max input value

**Space complexity**

O(√C) – temporary arrays for divisors and perimeters

**Difficulty**

Easy (However in my opinion, harder than S1 & should be worth 5 pts maybe?)

**All DMOJ subtasks accepted in:**

`0.03s, 10.50 MB`

---

### **CCC 03 S1 – Snakes and Ladders (ccc03s1)**

**Main idea / algorithm**

Simulate a single-player snakes and ladders game. Update the square number based on die roll and snakes/ladders. If roll exceeds 100, ignore it. Print player's square after each move and handle win or quit conditions.

**Time complexity**

O(M) – M moves

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.05s, 10.59 MB`

---

### **CCC 03 S2 – Poetry (ccc03s2)**

**Main idea / algorithm**

Extract the vowel-ending segment of the last word in each of four lines. Determine rhyme scheme by comparing these segments: perfect, even, cross, shell, or free.

**Time complexity**

O(L) per poem – L is total length of all lines

**Space complexity**

O(1) – small temporary arrays

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.11s, 10.22 MB`

---

### **CCC 03 S3 – Floor Plan (ccc03s3)**

**Main idea / algorithm**

Flood fill all empty rooms in the grid to compute their sizes. Sort room sizes descending and assign available flooring to largest rooms first. Count fully floored rooms and remaining area.

**Time complexity**

O(R·C) – grid traversal

**Space complexity**

O(R·C) – visited matrix

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.12s, 10.65 MB`

---

### **CCC 03 S4 – Substrings (ccc03s4)**

**Main idea / algorithm**

Don't be deceived by the brevity of the solution. THe question is actually quite hard conceptually, and if you don't know suffix tree/array, is very very difficult. 

Basically the idea is to build the suffix array, compute the LCP array and then the number of distinct substrings is `sum lengths of suffixes - sum of LCPs + 1` (+1 for empty substring)

**Time complexity**

O(N log N) – suffix sorting

**Space complexity**

O(N) – suffix and LCP arrays

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`0.31s, 23.28 MB`

---

### **CCC 03 S5 – Trucking Troubles (ccc03s5)**

**Main idea / algorithm**

Compute the maximum bandwidth path from node 1 to all destinations using a variation of Dijkstra’s algorithm with a priority queue, taking the minimum edge weight along a path as the path’s bandwidth. The final answer is the minimum among requested destinations.

**Time complexity**

O(E log N) – using heap-based priority queue

**Space complexity**

O(N + E) – adjacency lists and best path array

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`0.56s, 37.30 MB`
