# 2004 CCC Report

### **CCC 04 J1 – Squares (ccc04j1)**

**Main idea / algorithm**

Compute the largest integer side length of a square that fits inside a given area by taking the integer square root of the input number.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.12s, 10.37 MB`

---

### **CCC 04 J2 – Terms of Office (ccc04j2)**

**Main idea / algorithm**

Iterate from starting year to ending year in steps of 60, printing the years when all positions change.

**Time complexity**

O((end-start)/60)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.22s, 10.10 MB`

---

### **CCC 04 J3 – Smile with Similes (ccc04j3)**

**Main idea / algorithm**

Generate all adjective-noun pairs in the format "adjective as noun" using nested loops over the lists of adjectives and nouns.

**Time complexity**

O(n·m) – n adjectives, m nouns

**Space complexity**

O(n + m) – storage of input lists

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.09s, 10.47 MB`

---

### **CCC 04 J4 – Simple Encryption (ccc04j4)**

**Main idea / algorithm**

Encrypt a message with I believe a Vigenère cipher by mapping letters to numbers, adding key letters modulo 26, and converting back to letters.

**Time complexity**

O(L) – L is the length of the message

**Space complexity**

O(L)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.13s, 10.12 MB`

---

### **CCC 04 J5 – Fractals (ccc04j5)**

**Main idea / algorithm**

Generate a fractal pattern recursively with line segments, keeping track of coordinates. Output the set of y-coordinates intersecting a given vertical line X.

**Time complexity**

O(5^L) – L recursion depth

**Space complexity**

O(5^L) – storing line segments

**Difficulty**

Medium-Hard

**All DMOJ subtasks accepted in:**

`0.12s, 10.61 MB`

---

### **CCC 04 S1 – Fix (ccc04s1)**

**Main idea / algorithm**

Check for any two strings in a set of three whether one is a prefix or suffix of the other; output "Yes" if all strings are distinct in this sense, otherwise "No".

**Time complexity**

O(1) per set – fixed 3 strings

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.12s, 10.50 MB`

---

### **CCC 04 S2 – TopYodeller (ccc04s2)**

**Main idea / algorithm**

Simulate scores across rounds, track each player's best and worst rank, and identify the player with rank 1 as TopYodeller.

**Time complexity**

O(R·N^2) – R rounds, N players

**Space complexity**

O(N)

**Difficulty**

Easy-Medium

**All DMOJ subtasks accepted in:**

`0.34s, 10.62 MB`

---

### **CCC 04 S3 – Spreadsheet (ccc04s3)**

**Main idea / algorithm**

Evaluate spreadsheet cells that may contain sums of other cells using DFS to resolve dependencies. Handle numeric cells directly and formulas recursively.

**Time complexity**

O(R·C + dependencies) – up to 10×9 grid

**Space complexity**

O(R·C)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.14s, 11.25 MB`

---

### **CCC 04 S4 – Space Turtle (ccc04s4)**

**Main idea / algorithm**

Simulate turtle movement in 3D space according to directional commands, keeping track of the minimum distance from the origin in any plane.

**Time complexity**

O(N) – number of movement commands

**Space complexity**

O(1)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.12s, 10.48 MB`

---

### **CCC 04 S5 – Super Plumber (ccc04s5)**

**Main idea / algorithm**

Dynamic programming to find the maximum sum path from bottom-left to bottom-right in a grid with obstacles and numeric tiles, considering vertical moves with constraints on blocked cells.

**Time complexity**

O(M·N) – M rows, N columns

**Space complexity**

O(M·N)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`0.14s, 10.95 MB`
