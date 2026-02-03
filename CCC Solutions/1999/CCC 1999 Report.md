# 1999 CCC Report

### **CCC 99 S1 – Card Game (ccc99s1)**

**Main idea / algorithm**

Read the 52 cards in order, each face card has a value. For each card, check the next v cards where v is its value, if no other face card is found, award points to the current player. Keep running totals for players A and B and print scores

**Time complexity**

O(52²) worst case - each card may check up to 4 following cards

**Space complexity**

O(52) - storing all cards

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.02s, 10.36 MB`

---

### **CCC 99 S2 – Year 2000 (ccc99s2)**

**Main idea / algorithm**

The easiest method which comes to mind is of course, regex. Use it to get all dates in formats like dd/mm/yy, dd.mm.yy, Month dd, yy. Convert 2-digit years to 4-digit, assuming yy >= 25 -> 19yy else 20yy. Replace original dates in the string with converted ones

**Time complexity**

O(L) per string - L length

**Space complexity**

O(L) - storing modified string

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.03s, 11.11 MB_`

---

### **CCC 99 S3 – Divided Fractals (ccc99s3)**

**Main idea / algorithm**

For a given rectangle of a Sierpiński carpet, iterate through coordinates, check recursively if each cell lies in a removed middle third at any level. Print '*' if filled, ' ' if empty

**Time complexity**

O((r2-r1+1)*(c2-c1+1)*log(max(r2,c2))) - recursion depth for checking each cell

(I'm like 98% sure, fact checking would be required)

**Space complexity**

O(C) - just for a row buffer, no recursion stack needed beyond current cell

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.03s, 10.51 MB`

---

### **CCC 99 S4 – A Knightly Pursuit (ccc99s4)**

**Main idea / algorithm**

Model chessboard as grid, BFS from knight's start to all squares. Track minimum moves to reach rows with pawns. Determine win/stalemate/loss depending on whether knight can capture pawns before they reach promotion

Actually a very nice question, [Evang's comment](https://dmoj.ca/problem/ccc99s4#comment-14059) actually helped a lot (you'd think it be common sense...)

**Time complexity**

O(r*c*8) per test case - BFS exploring each square

**Space complexity**

O(r*c) - for visited and move counters

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`0.17s, 10.71 MB`

---

### **CCC 99 S5 – Letter Arithmetic (ccc99s5)**

**Main idea / algorithm**

Solve cryptarithm using recursive DFS, mapping letters to digits. Track carries, enforce unique digit assignments, and handle constraints on first letters. When mapping valid, reconstruct numbers and print

Made faster (Python 0.03s) by pruning impossible digit assignments early using DFS with carry check.

**Time complexity**

O(10^n) worst case - n letters to assign, pruned by constraints

**Space complexity**

O(n) - recursion stack and mapping dictionaries

**Difficulty**

Hard - Mediumish (optimisation)

**All DMOJ subtasks accepted in:**

`0.03s, 10.83 MB`
