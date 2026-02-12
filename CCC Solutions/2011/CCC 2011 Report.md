# 2011 CCC Report

---

### **CCC 11 J1 – Which Alien? (ccc11j1)**

**Main idea / algorithm**

Direct basic condition checking. Trivial, almost.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.19s, 9.47 MB`

---

### **CCC 11 J2 – Who Has Seen the Wind (ccc11j2)**

**Main idea / algorithm**

Brute force sim - iterate through hours 1 to 240, evaluate the quartic height function, and stop at the first hour where the balloon height becomes non-positive.

**Time complexity**

O(1), since the loop runs at most 240 iterations

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.21s, 9.98 MB`

---

### **CCC 11 J3 – Sumac Sequences (ccc11j3)**

**Main idea / algorithm**

Simulate the sequence iteratively by repeatedly subtracting the previous two terms until the next term exceeds the previous one, counting how many terms are generated.

**Time complexity**

O(n), proportional to the sequence length

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.12s, 10.39 MB`

---

### **CCC 11 J4 – Boring Business (ccc11j4)**

**Main idea / algorithm**

Simulate movement step by step on a grid, maintaining a list of previously visited coordinates; if a coordinate is revisited, immediately report danger.

**Time complexity**

O(T²) in worst case due to linear membership checks in the visited list

**Space complexity**

O(T), where T is total number of steps taken

**Difficulty**

Easy-Medium

**All DMOJ subtasks accepted in:**

`0.10s, 10.68 MB`

---

### **CCC 11 J5 – Unfriend (ccc11j5)**

**Main idea / algorithm**

Dynamic programming on a rooted tree: for each person, compute the number of valid invitation subsets of their subtree, combining children multiplicatively and subtracting the empty set at the end.

**Time complexity**

O(n²) in the given implementation due to repeated scans for children

**Space complexity**

O(n)

**Difficulty**

Medium–Hard

**All DMOJ subtasks accepted in:**

`0.12s, 10.36 MB`

---

### **CCC 11 S1 – English or French (ccc11s1)**

**Main idea / algorithm**

Count occurrences of ‘t’ and ‘s’ (case-insensitive) across all lines and compare totals to determine the language.

**Time complexity**

O(total characters)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.25s, 10.46 MB`

---

### **CCC 11 S2 – Multiple Choice (ccc11s2)**

**Main idea / algorithm**

Store student answers and correct answers, then count how many positions match.

**Time complexity**

O(n)

**Space complexity**

O(n)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.14s, 10.61 MB`

---

### **CCC 11 S3 – Alice Through the Looking Glass (ccc11s3)**

**Main idea / algorithm**

Recursive fractal simulation: at each level, determine which of the 5×5 sub-squares the point lies in, classify immediately if it is definitively crystal or empty, or recurse into the central fractal region with reduced scale.

**Time complexity**

O(m) per query, where m is the fractal depth

**Space complexity**

O(1)

**Difficulty**

Medium–Hard

**All DMOJ subtasks accepted in:**

`0.12s, 10.52 MB`

---

### **CCC 11 S4 – Blood Distribution (ccc11s4)**

**Main idea / algorithm**

Model the compatibility rules as a flow network and compute the maximum flow from donors to recipients using Dinic’s algorithm (BFS level graph plus DFS blocking flow).

**Time complexity**

O(V²E) in general, but small constant due to fixed graph size

**Space complexity**

O(V²)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`2.56s, 10.77 MB`

---

### **CCC 11 S5 – Switch (ccc11s5) – C++ Version**

**Main idea / algorithm**

State compression with BFS: represent the light configuration as a bitmask, and from each state try flipping every off light to on, then collapse any consecutive block of four or more on lights to off, exploring all reachable states until reaching the all-off configuration.

**Why it passes**

Even O(2ⁿ · n²) style exploration works because n is small and the judge runs very quickly, so exhaustive BFS over all reachable bitmasks is feasible.

**Time complexity**

Up to O(2ⁿ · n²) in worst case

**Space complexity**

O(2ⁿ)

**Why C++ is faster**

Bit manipulation and hash table operations are significantly faster in C++, making the BFS state exploration noticeably quicker.

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`0.66s, 55.62 MB`

---

### **CCC 11 S5 – Switch (ccc11s5) – Python Version**

**Main idea / algorithm**

The same BFS over bitmask states, using Python integers for bit operations and a deque for traversal, generating new masks by toggling bits and recomputing valid collapsed segments.

**Why it passes**

Although Python is slower, the input constraints are small enough that the full BFS still completes within time limits.

**Time complexity**

Up to O(2ⁿ · n²)

**Space complexity**

O(2ⁿ)

**Why it is slower than C++**

Higher constant factors in Python’s bit operations, hashing, and dynamic structures make each state expansion more expensive.

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`0.73s, 11.55 MB`


