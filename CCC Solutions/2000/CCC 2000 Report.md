# 2000 CCC Report

### **CCC 00 J1 – Calendar (ccc00j1)**

**Main idea / algorithm**

Print the header for weekdays. Iterate from 1 to n, filling each week row by row, left padding empty cells for offset o. Join each week with spaces for alignment.

**Time complexity**

O(n)

**Space complexity**

O(n) - storing all weeks

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.66s, 10.60 MB`

---

### **CCC 00 J2 – 9966 (ccc00j2)**

**Main idea / algorithm**

Iterate through numbers from n to m, convert to digits, check if mirrored pairs of digits are valid as per set v. Count numbers satisfying the mirrored condition.

**Time complexity**

O((m-n) * d) where d is number of digits

**Space complexity**

O(d) - storing digits temporarily

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.14s, 10.52 MB`

---

### **CCC 00 S1 – Slot Machines (ccc00s1)**

**Main idea / algorithm**

Simulate slot machines. For each play, increment reels. If reels roll over to jackpot, add extra plays. Count total plays until going broke.

**Time complexity**

O(p) where p is number of plays until broke

**Space complexity**

O(1)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.14s, 10.36 MB`

---

### **CCC 00 S2 – Babbling Brooks (ccc00s2)**

**Main idea / algorithm**

Maintain a list of stream sections. Process commands to either merge two sections or split a section by percentage. Update the list dynamically and print final values.

**Time complexity**

O(n * c) where n is number of sections and c is number of commands

**Space complexity**

O(n) - storing stream sections

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.12s, 10.49 MB`

---

### **CCC 00 S3 – Surfing (ccc00s3)**

**Main idea / algorithm**

Parse documents and HREF links. Build adjacency list of pages. For each query, DFS from start page to check if end page is reachable. Report surfing possibility.

**Time complexity**

O(N + E) per query, where N is number of pages and E is total links

**Space complexity**

O(N + E) - adjacency list and visited set

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.05s, 10.65 MB`

---

### **CCC 00 S4 – Golf (ccc00s4)**

**Main idea / algorithm**

Use BFS to explore positions reachable by clubs from start to target distance d. Track number of strokes to reach each position. Output minimum strokes if possible, else acknowledge defeat.

**Time complexity**

O(d * c) where c is number of clubs

**Space complexity**

O(d) - visited array and BFS queue

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.18s, 10.68 MB`

---

### **CCC 00 S5 – Sheep and Coyotes (ccc00s5)**

**Main idea / algorithm (Python version)**

For each sheep, maintain interval [l,r] of x-coordinates where no coyote can split them. For each pair of sheep, compute the perpendicular bisector and adjust intervals. If interval remains non-empty, sheep might be eaten.

**Main idea / algorithm (C++ version)**

Same logic as Python, but implemented with precise floating point arithmetic and faster loops, using pairs and goto to skip invalid sheep. Iterates all sheep and bisectors efficiently.

**Notes**

Even O(n³) solutions pass due to the judge running very quickly, as mentioned by [Kirito](https://dmoj.ca/problem/ccc00s5#comment-13288). Both Python and C++ solutions work, but the C++ version is faster.

A [Hard Version](https://dmoj.ca/problem/ccc00s5hard) also exists, but since it is not strictly CCC it will not be included (totally not because I haven't solve it yet...)

**Time complexity**

O(n²) for both - checking each sheep against all others

**Space complexity**

O(n) - storing coordinates and intervals

**Difficulty**

Hard

**All DMOJ subtasks accepted in: (C++)**

`0.03s, 3.91 MB`

**All DMOJ subtasks accepted in: (Python)**

`0.528s, 11.02 MB`
