# 2012 CCC Report

---

### **CCC 12 J1 – Speed Fines Are Not Fine (ccc12j1)**

**Main idea / algorithm**

Calculate the difference between actual and speed limit, then branch on ranges to determine the fine or congratulations message.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.23s, 10.41 MB`

---

### **CCC 12 J2 – Sounds Fishy (ccc12j2)**

**Main idea / algorithm**

Compare consecutive depth readings to classify the fish movement: strictly increasing, strictly decreasing, constant, or neither.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.12s, 9.42 MB`

---

### **CCC 12 J3 – Icon Scaling (ccc12j3)**

**Main idea / algorithm**

Use nested loops to print a scaled ASCII icon pattern in three segments, carefully calculating spaces, `*`, and `x` placement.

**Time complexity**

O(a²), where `a` is the scaling factor

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.67s, 10.05 MB`

**Note**

Amazingly, a BF solution is possible

```brainfuck
>+
[>,----------]
<[<]>-
>[-------------------------------------->]
<<[>++++++++++<-]
>[>+>+<<-]
>[>]>>>>>
++++++++++++++++++++++++++++++++++++++++++
>++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
>++++++++++++++++++++++++++++++++++++++++++
>++++++++++
[<]<<<<<

[
  >>>>+<<<<
  <[<+>>>+>+>+<<<<-]
  <[>+<-]
  >>>
  [[>>>>>.<<<<<-]>]
  <<<<<-
]
<[<+>>+<-]
<[>+<-]
>>>>>>>>

----------
>>++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
[<]<<<<<

[
  >>>>+<<<<
  <[<+>>>+>+>+<<<<-]
  <[>+<-]
  >>>
  [[>>>>>.<<<<<-]>]
  <<<<<-
]
<[<+>>+<-]
<[>+<-]
>>>>>>>>

++++++++++
>----------------------------------------------------------------------------------------
>------------------------------------------------------------------------------
[<]<<<<<

[
  >>>>+<<<<
  <[<+>>>+>+>+<<<<-]
  <[>+<-]
  >>>
  [[>>>>>.<<<<<-]>]
  <<<<<-
]
```

---

### **CCC 12 J4 – Big Bang Secrets (ccc12j4)**

**Main idea / algorithm**

Decrypt a message by subtracting a position-dependent shift from each character, wrapping around alphabetically if necessary.

**Time complexity**

O(n), where n is the string length

**Space complexity**

O(1)

**Difficulty**

Easy–Medium

**All DMOJ subtasks accepted in:**

`0.13s, 10.00 MB`

---

### **CCC 12 S1 – Don’t Pass Me the Ball (ccc12s1)**

**Main idea / algorithm**

Count combinations of 3 players from `J` players using triple nested loops.

**Time complexity**

O(J³)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.14s, 10.41 MB`

---

### **CCC 12 S2 – Aromatic Numbers (ccc12s2)**

**Main idea / algorithm**

Interpret a string alternating Roman numeral and digit pairs, accumulating the value while handling subtractive notation.

**Time complexity**

O(n), where n is half the string length

**Space complexity**

O(1)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.12s, 10.29 MB`

---

### **CCC 12 S3 – Absolutely Acidic (ccc12s3)**

**Main idea / algorithm**

Count occurrences of pH readings (negated for array indexing), find the mode, then compute the maximum distance between the mode and the second most frequent value.

**Time complexity**

O(n + range of pH) ≈ O(n)

**Space complexity**

O(1000)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`3.74s, 10.43 MB`

---

### **CCC 12 S4 – A Coin Game (ccc12s4)**

**Main idea / algorithm**

Model the coin stack positions as a compressed integer mask (base-8 per coin) and perform BFS to find the minimum moves to reach sorted positions, checking only legal moves by top-most coins.

**Time complexity**

Exponential in n (number of coins), but manageable due to pruning via `top` array

**Space complexity**

O(number of reachable states)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`0.64s, 89.96 MB`

---

### **CCC 12 S5 – Mouse Journey (ccc12s5)**

**Main idea / algorithm**

Easiest S5 possibly? Dynamic programming on a grid: mark blocked squares, then compute number of paths to each cell as the sum of paths from top and left neighbors.

**Time complexity**

O(r × c), where r and c are the grid dimensions

**Space complexity**

O(r × c)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.167s, 10.59 MB`

