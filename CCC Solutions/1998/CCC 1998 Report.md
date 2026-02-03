# 1998 CCC Report

### **CCC 98 S1 – Censor (ccc98s1)**

**Main idea / algorithm**

Read each line, replace all words of length 4 with '****', then print the line. Almost trivial string processing with list comp

**Time complexity**

O(L) per line - L length (num of characters)

**Space complexity**

O(L) - storing the split words

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.07s, 10.45 MB`

---

### **CCC 98 S2 – Cross Number Puzzle (ccc98s2)**

**Main idea / algorithm**

Generate all 4-digit perfect numbers (sum of proper divisors = number) and all numbers where sum of cubes of digits = number. These are also known as 3-digit Armstrong numbers. Use simple iteration and conditions.

Given solution two lines, note one line is possible:

```python
print(*[x for x in range(1000,10000) if sum(i for i in range(1,x) if x%i==0)==x]); print(*[x for x in range(100,1001) if x==sum(int(c)**3 for c in str(x))])
```

**Time complexity**

O(10⁴) for perfect numbers + O(10³) for Armstrong numbers

**Space complexity**

O(1) extra beyond storing results

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`1.88s, 10.50 MB`

Note that due to weak test data, text and brain**** solutions are possible in 0.00 seconds.

---

### **CCC 98 S3 – Mars Rover (ccc98s3)**

**Main idea / algorithm**

Track horizontal and vertical position with a facing direction modulo 4. Handle commands to move forward, turn left or right, then compute Manhattan distance. 

Use case handling depending on current facing, HOWEVER this is not the most efficient solution (127 lines, should be solved mathematically perhaps?)

**Time complexity**

O(C) per test case - C number of commands

**Space complexity**

O(1) - just integer variables

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.20s, 11.28 MB`

---

### **CCC 98 S4 – Lottery (ccc98s4)**

**Main idea / algorithm**

Aiming to parse string with 'X', '+', '-' and wrap each operation in parentheses correctly. Repeatedly replace symbols, track positions, and reconstruct the expression. 

Basically a manual string parsing with greedy parentheses insertion

**Time complexity**

O(L²) - repeated scans over string of length L

**Space complexity**

O(L) - storing modified string

**Difficulty**

Hard - tricky string parsing and careful indexing

**All DMOJ subtasks accepted in:**

`0.02s, 10.75 MB`

---

### **CCC 98 S5 – Mountain Passage (ccc98s5)**

**Main idea / algorithm**

Treat the grid as a graph. First, label regions where heights are within 2 units using DFS. Then BFS from start to end, counting region transitions. Track distances and use BFS/DFS combination to simulate travel constraints

**Time complexity**

O(n²) - scanning the n×n grid and BFS/DFS

**Space complexity**

O(n²) - for grid, distance tracking, and visited arrays

**Difficulty**

Medium–Hard (in my opinion, easier than s4)

**All DMOJ subtasks accepted in:**

`0.13s, 10.89 MB`
