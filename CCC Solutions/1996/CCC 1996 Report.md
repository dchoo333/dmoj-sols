# 1996 CCC Report
### **CCC 96 S1 – Deficient, Perfect and Abundant (ccc96s1)**

**Main idea / algorithm**

For each number, iterate through all positive divisors less than the number, sum them, and compare the sum to the original number to classify it as deficient, perfect, or abundant.

**Time complexity**

O(n) per number

**Space complexity**

O(1) - using just few integer variables

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.03s - 10.43 MB`

### **CCC 96 S2 – Divisibility by 11 (ccc96s2)**

**Main idea / algorithm**

Simply Implement divisibility algorithm given (Charles Dodgson) (repeatedly removing the last digit and subtracting it from the remaining number). Working directly on strings to handle very large integers (10^50)

**Time complexity**

O(d²) per number - d is the number of digits (each reduction may traverse the remaining digits)

**Space complexity**

O(d) - storing and modifying the number as a string

**Difficulty**

Medium - Easy

**All DMOJ subtasks accepted in:**

`0.01s - 3.68 MB`

### **CCC 96 S3 – Pattern Generator (ccc96s3)**

**Main idea / algorithm**

Recursive backtracking to generate all binary strings of length N containing exactly K 1's, branching by choosing either 0 or 1 at each position.

**Time complexity**

O(C(N, K) · N ) - each valid pattern of length N is constructed then printed

**Space complexity**

O(N) - recursion stack + temporary string construction

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.03s - 10.33 MB`

### **CCC 96 S4 – When in Rome (ccc96s4)**

**Main idea / algorithm**

Convert Roman numerals to integers using right-to-left subtraction rule, perform addition, then convert the result back to Roman numerals using greedy value matching approach

**Time complexity**

O(L) - L length

**Space complexity**

O(1) - lookup tables + variables const. size

**Difficulty**

Medium–Hard

**All DMOJ subtasks accepted in:**

`0.02s - 10.61 MB`

### **CCC 96 S5 – Maximum Distance (ccc96s5)**

**Main idea / algorithm**

Brute-force all valid index pairs (y, z) with y ≤ z, check the condition on the two arrays, track the maximum valid distance z − y

**Time complexity**

O(n²) - iterating through all pairs of indices

**Space complexity**

O(1) extra space beyond the input arrays

**Difficulty**

Easy (conceptually), but inefficient for large inputs

**All DMOJ subtasks accepted in:**

`0.25s - 24.85 MB`
