# 2026 CCC Report

---

### **CCC 26 J1 – Concert Tickets (ccc26j1)**

**Main idea / algorithm**  

Trivially check if (b − c) covers a, and print the leftover amount if it does.

**Time complexity**  

O(1)

**Space complexity**  

O(1)

**Difficulty**  

Very Easy

**All DMOJ subtasks accepted in**  

`0.162s, 10.36 MB`

---

### **CCC 26 J2 – Olympic Scores (ccc26j2)**

**Main idea / algorithm**  

Simple implementation

**Time complexity**  

O(1)

**Space complexity**  

O(1)

**Difficulty**  

Very Easy

**All DMOJ subtasks accepted in**  

`0.139s, 10.44 MB`

---

### **CCC 26 J3 – Creative Candy Consumption (ccc26j3)**

**Main idea / algorithm**  

We use a two pointer simulation of RPS between the two candy strings. A tie scores for and advances both.
Otherwise the winner scores and only the loser's pointer advances. Leftover are added to owner.

**Time complexity**  

O(n + m)

**Space complexity**  

O(1) extra

**Difficulty**  

Easy

**All DMOJ subtasks accepted in**  

`1.768s, 13.67 MB`

---

### **CCC 26 J4 – Snail Path (ccc26j4)**

**Main idea / algorithm**  

Use a simple coordinate tracking algorithm.

**Time complexity**  

O(D) for total distance D

**Space complexity**  

O(D)

**Difficulty**  

Easy

**All DMOJ subtasks accepted in**  

`6.383s, 257.61 MB`

---

### **CCC 26 J5 – Beams of Light (ccc26j5)**

**Main idea / algorithm**  

Each light covers the range [P − S, P + S], clamped to [1, n]. Mark each range with a difference array, prefix-sum it to get the coverage count at every position, then answer each query in O(1).

**Time complexity**  

O(n + l + q)

**Space complexity**  

O(n)

**Difficulty**  

Medium

**All DMOJ subtasks accepted in**  

`39.951s, 29.38 MB`

---

### **CCC 26 S1 – Baby Hop, Giant Hop (ccc26s1)**

**Main idea / algorithm**  

A pretty hard S1, which cooked [Sucram314](https://dmoj.ca/problem/ccc26s1#comment-24466). Let D = |E − S|. The minimum hop count is either a = D / G giant hops plus r = D mod G baby hops, or one extra giant hop to overshoot and then G − r baby hops back. For T = 2 we need the smallest hop count strictly above the minimum. Check whether m1 + 1 hops is achievable by solving the two linear cases: all hops forward (k(G − 1) = D − h), or giants forward and babies back (g(G + 1) = D + h). If neither works the answer is m1 + 2, which is always possible by adding one hop forward and one back.

**Time complexity**  

O(1)

**Space complexity**  

O(1)

**Difficulty**  

Medium

**All DMOJ subtasks accepted in**  

`3.486s, 10.63 MB`

---

### **CCC 26 S2 – Beams of Light (ccc26s2)**

**Main idea / algorithm**  

Same problem as J5: a difference array over the light ranges, a prefix sum for coverage, and O(1) queries.

**Time complexity**  

O(n + l + q)

**Space complexity**  

O(n)

**Difficulty**  

Easy

**All DMOJ subtasks accepted in**  

`39.951s, 29.38 MB`

---

### **CCC 26 S3 – Common Card Choice (ccc26s3)**

**Main idea / algorithm (in-contest Python)**  

Any 4 numbers always contain two disjoint groups whose sums are both even, so their gcd is at least 2. If 2+ evens, take two evens on their own (1 vs 1). If 0 we pair four odds, o1 + o2 vs o3 + o4 (2 vs 2).
If there's 1, o1 + o2 vs the even (2 vs 1).

For n <= 3 the answer isn't guaranteed, so we brute force every pair of disjoint subsets with itertools combinations. 
For -1 case, we output 8 hardcoded disjoint 1v1, 1v2 and 2v2 guesses. This works if one of them happens to share a factor, which it did, resulting in AC.

**Main idea / algorithm (C++, post-contest solution)**  

Known - the parity argument shows the first 4 cards always contain an answer. So brute force every pair of disjoint non-empty masks over the first min(n, 4) cards (at most 3^4 pairs) and output the first pair with gcd(s1, s2) > 1. This one loop covers the n ≤ 3 cases and the n ≥ 4 cases, and it finds any common factor, not just 2.

Hidden values - randomisation. Shuffle the indices and output 100 disjoint 2 vs 2 guesses from 400 distinct cards. The sum of two random cards is even with probability at least about 1/2, so a guess has both sums even with probability at least about 1/4, whatever the array is. The chance that all 100 guesses fail is about (3/4)^100 ≈ 10^−13.

**Time complexity**  

Python: O(n) to split the cards by parity and O(1) BF

C++: O(n) to read input, plus O(3^4) = O(1) mask brute force. For hidden, O(n) shuffle.

**Space complexity**  

O(n)

**Difficulty**  

Hard

**All DMOJ subtasks accepted in**  

`3.477s, 20.95 MB`

---

### **CCC 26 S4 – Minecarts (ccc26s4)**

**Main idea / algorithm**  

Binary search on the answer C. Coord compress the cart values and use a BIT to precompute f[j], the number of smaller carts to the right of each cart. Furthermore for each C:

- Reject if any has f[j] > C.
- Each cart forces a min onto the empty slot at index 1+ pe[j] + (C − f[j]).
- A prefix max spreads these requirements into the cheapest possible fill of the empty slots. Reject if the total cost exceeds K.
- Sweep right to left with a BIT and check that no filled slot has more than C smaller after it

**Time complexity**  

O(n log n · log V)

**Space complexity**  

O(n)

**Difficulty**  

Very Hard

**All DMOJ subtasks accepted in**  

`17.57s, 10.53 MB`

---

### **CCC 26 S5 – On the Fence (ccc26s5)**

**Main idea / algorithm**  

A fence rectangle of size h × w uses 2(h + w) − 4 posts and encloses (h − 2)(w − 2) cells. There's a penalty when h > A and w > B, where A and B are the farthest distances from the marked cell, and leftover fence can be spent to reduce that penalty. 
The objective is piecewise quadratic in h and w, so the optimum lies near a critical point. So enumerate about 12 candidate heights: the bounds A, A + 1, N, the perimeter-limited values and vertices of each quad piece.
For each height, try about 6 candidate widths, check a +-3 neighbourhood of every candidate, and do this in both orientations. bestt separately handles rectangles that fit entirely to one side of the cell, by maximising p*q subject to p + q <= S.

**Time complexity**  

O(1) per test case, O(T) total

**Space complexity**  

O(1)

**Difficulty**  

Very Very Hard

**All DMOJ subtasks accepted in**  

`0.85s, 3.91 MB`
