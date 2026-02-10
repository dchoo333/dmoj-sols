# 2007 CCC Report

---

### **CCC 07 J1 – Who is in the Middle? (ccc07j1)**

**Main idea / algorithm**

Read three integers, sort them, and output the middle value after sorting.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.14s, 10.14 MB`

---

### **CCC 07 J2 – I Speak TXTMSG (ccc07j2)**

**Main idea / algorithm**

Use a dictionary to map common text abbreviations to their full meanings, repeatedly translate each input line, and stop when `TTYL` is encountered.

**Time complexity**

O(L)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.03s, 10.08 MB`

---

### **CCC 07 J3 – Deal or No Deal Calculator (ccc07j3)**

**Main idea / algorithm**

Remove eliminated case values, compute the expected value of remaining cases, and compare it to the banker’s offer to decide whether to deal.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.12s, 10.52 MB`

---

### **CCC 07 J4 – Anagram Checker (ccc07j4)**

**Main idea / algorithm**

Remove spaces from both strings, sort their characters, and compare the results to determine whether they are anagrams.

**Time complexity**

O(N log N)

**Space complexity**

O(N)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.19s, 9.82 MB`

---

### **CCC 07 J5 – Keep on Trucking (ccc07j5)**

**Main idea / algorithm**

Insert all motels into a sorted list and use dynamic programming to count the number of valid ways to reach each motel while respecting minimum and maximum daily distances.

**Time complexity**

O(N²)

**Space complexity**

O(N)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.19s, 10.19 MB`

---

### **CCC 07 S1 – Federal Voting Age (ccc07s1)**

**Main idea / algorithm**

Compare each person’s birth date against the cutoff date using year, month, and day comparisons to determine eligibility.

**Time complexity**

O(N)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.11s, 10.07 MB`

---

### **CCC 07 S2 – Boxes (ccc07s2)**

**Main idea / algorithm**

Sort dimensions of both the item and each box, check if the item fits, and select the fitting box with the minimum volume.

**Time complexity**

O(N)

**Space complexity**

O(N)

**Difficulty**

Easy–Medium

**All DMOJ subtasks accepted in:**

`0.12s, 10.54 MB`

---

### **CCC 07 S3 – Friends (ccc07s3)**

**Main idea / algorithm**

Represent friendships as a directed graph and use BFS to determine whether one person can reach another and how many intermediaries are required.

**Time complexity**

O(V + E)

**Space complexity**

O(V + E)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.16s, 11.77 MB`

---

### **CCC 07 S4 – Waterpark (ccc07s4)**

**Main idea / algorithm**

Model slides as a directed acyclic graph and use dynamic programming with DFS to count the total number of paths from slide 1 to slide N.

**Time complexity**

O(V + E)

**Space complexity**

O(V + E)

**Difficulty**

Medium–Hard

**All DMOJ subtasks accepted in:**

`0.16s, 11.91 MB`

---

### **CCC 07 S5 – Bowling for Numbers (ccc07s5)**

**Main idea / algorithm**

Use dynamic programming where `dp[i][b]` represents the maximum score achievable starting at position `i` using `b` balls, choosing between skipping or taking a window of width `w`.

Use C++ to solve.

**Time complexity**

O(N · K)

**Space complexity**

O(N · K)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`0.08s, 61.72 MB`
