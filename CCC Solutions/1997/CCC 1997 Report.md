# 1997 CCC Report

### **CCC 97 S1 - Sentences (ccc97s1)**

**Main idea / algorithm**

Read three lists of strings x, y, z, then print every possible combination i j k where i from x, j from y, k from z. Triple nested loops, simple brute-force.

**Time complexity**

O(a * b * c) - a,b,c are the lengths of the three lists

**Space complexity**

O(a + b + c) - storing all three input lists

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.03s, 9.84 MB`

### **CCC 97 S2 - Nasty Numbers (ccc97s2)**

**Main idea / algorithm**

Check if a number is divisible by 6, if yes it's nasty, else not nasty. Very simple modulo check.

**Time complexity**

O(1) per number

**Space complexity**

O(1) - just integer variables

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.03s, 9.83 MB`

### **CCC 97 S3 - Double Knockout Competition (ccc97s3)**

**Main idea / algorithm**

Simulate rounds of a double knockout tournament. Keep track of undefeated u, one-loss l, eliminated e. Update counts each round until only one or no players remain. Print rounds info.

**Time complexity**

O(log n) roughly - each round roughly halves players

**Space complexity**

O(1) - only integer counters

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.03s, 10.46 MB`

### **CCC 97 S4 - Dynamic Dictionary Coding (ccc97s4)**

**Main idea / algorithm**

Read words, replace repeated words with code numbers using a dictionary, assign new code numbers to new words. Print each line after replacing words.

**Time complexity**

O(total_words) - each word processed once

**Space complexity**

O(unique_words) - dictionary stores mapping of words to codes

**Difficulty**

Easy - Medium

**All DMOJ subtasks accepted in:**

`0.03s, 9.98 MB`

### **CCC 97 S5 - Long Division (ccc97s5)**

**Main idea / algorithm**

Implement long division on big integers using strings. For each digit in numerator, subtract denominator as many times as possible to get quotient digit, keep remainder as new numerator. Handle leading zeros carefully.
N.B: Out of all alternative languages provided, C++ was chosen.

**Time complexity**

O(n * m) - n digits numerator, m digits denominator

**Space complexity**

O(n + m) - storing numerator, denominator, quotient, remainder strings

**Difficulty**

Medium - Hard

**All DMOJ subtasks accepted in:**

`0.00s, 3.59 MB`
