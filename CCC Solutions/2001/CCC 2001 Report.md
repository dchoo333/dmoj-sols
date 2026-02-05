# 2001 CCC Report

### **CCC 01 J1 – Dressing Up (ccc01j1)**

**Main idea / algorithm**

Generate the upper-left triangle of stars for odd numbers 1…n, doubling n if needed. Then mirror it in reverse to form the bottom. For each row, print stars on the sides and spaces in the middle, using the formula `(n - x) * 2` for padding.

**Time complexity**

O(n) – single loop building the pattern

**Space complexity**

O(n) – storing rows in a list

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.07s, 10.55 MB`

---

### **CCC 01 J2 – Modular Inverse (ccc01j2)**

**Main idea / algorithm**

Iterate through integers x = 0 to 999 and check `(a*x - 1) % b == 0`. Stop at the first x satisfying the modular inverse condition. If none found, report no solution.

**Time complexity**

O(1000) – brute force search up to 1000

**Space complexity**

O(1) – no additional storage beyond inputs

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`
0.12s, 10.34 MB`

---

### **CCC 01 S1 – Keeping Score (ccc01s1)**

**Main idea / algorithm**

Parse the input string into suits, split cards, then compute points based on presence and number of cards per suit plus special values for face cards. Print table with proper alignment for each suit and total points.

**Time complexity**

O(n) – parsing and summing over 52 cards

**Space complexity**

O(n) – storing suits and card lists

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.09s, 10.46 MB`

---

### **CCC 01 S2 – Spirals (ccc01s2)**

**Main idea / algorithm**

Place numbers in a counter-clockwise spiral starting from the center, moving down first, stopping at end value. Track row, column, and steps in alternating directions. For the exact version, add strict formatting rules: column-based widths, right alignment, single space between columns, equal row lengths, and blank lines between multiple spirals.

**Time complexity**

O((e-s+1)) – filling each number once

**Space complexity**

O(n²) – n x n grid to store spiral

**Difficulty**

Medium-Hard (Kind of tedious ngl)

**Notes on difference between S2 and S2 Exact**

The actual core spiral algorithm is unchanged. The difference lies in formatting:  
- Each column has its own width equal to the largest number in that column
- Numbers are right-aligned within the column width
- Exactly one space separates columns  
- Empty cells occupy column space  
- Every row must have identical length; trailing spaces may be required  
- Multiple test cases require exactly one blank line between spirals, no extra blank lines elsewhere  

Basically all WA's come from whitespace errors

CHECK THE COMMENTS, they have great explanations

**All DMOJ subtasks accepted in: (Normal Version)**

`0.12s, 10.77 MB`

**All DMOJ subtasks accepted in: (Exact Version)**

`2.60s, 10.98 MB`

---

### **CCC 01 S3 – Strategic Bombing (ccc01s3)**

**Main idea / algorithm**

Build an undirected graph of cities and roads. For each road, temporarily remove it and BFS from the starting city. If the capital becomes unreachable, mark the road as disconnecting. Count and print all disconnecting roads.

**Time complexity**

O(E*(V+E)) – checking each road via BFS

**Space complexity**

O(V+E) – adjacency list and visited array

**Difficulty**

Medium-Hard

**All DMOJ subtasks accepted in:**

`0.13s, 10.47 MB`

---

### **CCC 01 S4 – Cookies (ccc01s4)**

**Main idea / algorithm**

Use Welzl’s randomized algorithm for the minimal enclosing circle: recursively choose points and construct circle from 0, 2, or 3 boundary points. Shuffle input points to ensure expected linear time.

**Time complexity**

O(n) expected – randomized recursion

**Space complexity**

O(n) – storing points and recursion stack

**Difficulty**

Medium - Hard (Once you use Welzl's, it's actually not that hard)

**All DMOJ subtasks accepted in:**

`0.13s, 11.11 MB`

---

### **CCC 01 S5 – Post's Correspondence Problem (ccc01s5)**

**Main idea / algorithm**

DFS/stack-based search of all sequences of tiles up to length m. For each state, concatenate strings from both sequences and check if they match. Track solution path and print sequence indices. Stop at first valid sequence.

**Time complexity**

O(n^m) worst case – exploring all sequences up to length m

**Space complexity**

O(m) – recursion/stack depth and sequence tracking

**Difficulty**

Medium-Hard

**All DMOJ subtasks accepted in:**

`0.79s, 10.51 MB`
