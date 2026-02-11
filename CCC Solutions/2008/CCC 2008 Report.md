# 2008 CCC Report

---

### **CCC 08 J1 – Body Mass Index (ccc08j1)**

**Main idea / algorithm**

Compute BMI as `weight / height²` and classify based on standard thresholds.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.12s, 10.38 MB`

---

### **CCC 08 J2 – Do the Shuffle (ccc08j2)**

**Main idea / algorithm**

Maintain a list of letters, perform left/right rotations or adjacent swaps according to input commands until termination input is received.

**Time complexity**

O(M · 5) where M is the number of commands

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.12s, 10.50 MB`

---

### **CCC 08 J3 – GPS Text Entry (ccc08j3)**

**Main idea / algorithm**

Map characters to a grid, compute Manhattan distance between consecutive characters to simulate keypad movement, summing distances.

**Time complexity**

O(N)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.12s, 10.32 MB`

---

### **CCC 08 J4 – From Prefix to Postfix (ccc08j4)**

**Main idea / algorithm**

Iterate the prefix expression in reverse; use a stack to combine operands and operators into postfix notation.

**Time complexity**

O(N)

**Space complexity**

O(N)

**Difficulty**

Easy–Medium

**All DMOJ subtasks accepted in:**

`0.02s, 10.20 MB`

---

### **CCC 08 S1 – It's Cold Here (ccc08s1)**

**Main idea / algorithm**

Why does J5 not exist? Track the lowest temperature while reading city-temperature pairs; output the city with the lowest temperature when Waterloo is reached.

**Time complexity**

O(N)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.16s, 10.46 MB`

---

### **CCC 08 S2 – Pennies in the Ring (ccc08s2)**

**Main idea / algorithm**

Count lattice points inside a circle by iterating x from 0 to r and summing integer values of √(r² - x²), then multiply by 4 and add 1.

**Time complexity**

O(R)

**Space complexity**

O(1)

**Difficulty**

Easy–Medium

**All DMOJ subtasks accepted in:**

`0.15s, 10.25 MB`

---

### **CCC 08 S3 – Maze (ccc08s3)**

**Main idea / algorithm**

Use BFS to traverse the maze according to cell movement constraints ('+', '|', '-'), tracking distances to each cell and handling multiple test cases.

**Time complexity**

O(R · C)

**Space complexity**

O(R · C)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.12s, 10.68 MB`

---

### **CCC 08 S4 – Twenty-four (ccc08s4)**

**Main idea / algorithm**

Use recursive DFS with memoization to generate all possible values by combining 4 numbers with operations, returning the largest achievable value ≤ 24.

**Time complexity**

O(4! · 4³) ≈ O(1) for 4 numbers

**Space complexity**

O(1)

**Difficulty**

Medium–Hard

**All DMOJ subtasks accepted in:**

`0.13s, 10.56 MB`

---

### **CCC 08 S5 – Nukit (ccc08s5)**

**Main idea / algorithm**

Use iterative DFS with memoisation to determine the winning player for each initial state by checking all possible moves; standard combinatorial game DP.

**Time complexity**

O(Number of states × Moves per state)

**Space complexity**

O(Number of states)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`1.16s, 38.82 MB`
