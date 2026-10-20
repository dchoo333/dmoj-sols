# DMOJ 12-Point Solutions

Welcome to a collection of solutions to every single 12-point problem on the [DMOJ](https://dmoj.ca/problems/?point_start=12&point_end=12). This repo features 462 solutions which pass all their test cases on the DMOJ judge, spanning everything from CCC and CCO to COCI, Baltic OI, IOI, NOI, ECOO, WC, DMOPC and a lot of community contests.

On DMOJ, these problems are worth a total of $462 \times 12 = 5544$ raw points (last update: October 20). Accounting for the scaling system, though, they would give you $\approx 463.7$ points\*, since the scaling gives a lot of weight to the best 100 problems (which in this case, are all the same) rather than the quantity of those problems.

**Some Notes**

Like my other repos, most solutions are written shortened without convention or care for readability. It is purely functional.

Most solutions are in Python or C++ but a few problems are language-restricted. Therefore there are some, e.g. x86-64 assembly (`A Simple Multiplication`) and COBOL (`Bob and Special Mud`). There are three `.txt` solutions: `CCO '18 P2 - Wrong Answer` and `DMOPC '21 Contest 4 P3 - Palindromic Presents` are output-only, and `DMOJ Capture The Flag '20 R4 - Python Cycles` is just the flag.

**Problems, ranked**

Out of the 462 problems, these are, in my opinion, the 10 hardest, taking into account finding the idea, implementing it, and their bugability (ability to have bugs)

1. [JOI '23 Open P3 - Garden](https://dmoj.ca/problem/joi23op3) - In my opinion the hardest. One needs to see that the problem is "smallest circular gap in $`x`$ for every $`y`$ range" and sweep with a linked list that deletes points and updates the largest gap as it goes, and also argue the total work is amortised.
2. [ECOO '15 R3 P4 - Under the Rug](https://dmoj.ca/problem/ecoo15r3p4) - This is basically set cover, and there is no clean intended solution. Therefore you must put together a heuristic. Mine was forced squares for corner cells (grown with 2D prefix sums), then trying each of the four corner
growth directions for whatever is left and removing redundant squares. It has 7.4% AC and only 3 solvers. Part of this is due to the fact there is a particularly tough TC with a target of 249 rugs that most solutions score 9/10 on, resulting in 1990/2000.
3. [Mock CCC '22 2 S3 - Kaguya Wants to Analyze the Academy Anthem](https://dmoj.ca/problem/nccc10s3) - Suffix arrya, wavelet tree for range $`k`$-th smallest queries. Hypothetically from scratch, the solution is hard to write and you have to realise the query reduces to a $`k`$-th smallest on a range of the suffix array in the first place.
4. [COCI '17 Contest 3 #3 Retro](https://dmoj.ca/problem/coci17c3p3) - the DP for the longest bracket sequence is fine, but reconstructing the l. smallest answer (by tracking a set of still-optimal states) is pretty tough.
5. [Baltic OI '07 P4 - Building a Fence](https://dmoj.ca/problem/btoi07p4) - Maybe I'm just bad at geo, but its a visibility graph from rectangle corners plus a dijkstra, with edge cases like points inside rectangles and blocked segments. Causes a lot of WAs.
6. [CCO '18 P2 - Wrong Answer](https://dmoj.ca/problem/cco18p2) - This is actually a really nice CF hack / (un)optimisation question. But since it's just so non-standard, it is pretty hard for those who are bad at [GCC's](https://dmoj.ca/contest/gcc26c1).
7. [CCO '01 P2 - Coke or Chocolate Milk](https://dmoj.ca/problem/cco01p2) - Spot the 2-sat and then parsing so much English
8. [An Animal Contest 4 P5 - Neighbourly Neighbourhoods](https://dmoj.ca/problem/aac4p5) - Lots of `-1` cases. THe idea is to construct a graph with exactly `X` strong connected components, greedy DSU merges, size-1 components needing 0 edge.
9. [NOI '14 P5 - Random Number Generator](https://dmoj.ca/problem/noi14p5) - The greedy is simple, taking the smallest and narrowing each row's column range. However, the grid can be 5000 x 5000, and under a pretty tight ML, one array has to be involutory.
10. [CCC '20 J4 - Cyclic Shifts (Hard)](https://dmoj.ca/problem/ccc20j4hard) - Almost all TLE and MLE ecause the z-function back and forth is reasonable, but at $`10^7`$ characters you need $`O(n)`$ with pre much no constant.

Honourable mention: [Bob and Special Mud](https://dmoj.ca/problem/specialmud) - Grid shortest-path DP, but cobol smh.

And these are, in my opinion, the 10 easiest:

1. [Longest Up-Down Subsequence](https://dmoj.ca/problem/olyq1p2) - I mean it's two variables one pass (make it [1p?](https://dmoj.ca/problem/ccc26s1))
2. [Educational DP Contest AtCoder P - Independent Set](https://dmoj.ca/problem/dpp) - Template tree DP.
3. [Educational DP Contest AtCoder M - Candies](https://dmoj.ca/problem/dpm) - Template bounded knapsack counting, just sped up with pref sums
4. [WC '18 Finals S2 - Top Billing](https://dmoj.ca/problem/wc18fs2) - One of the more obvious constructions where one fixed diagonal is a solution
5. [Rotations in 3 Dimensions](https://dmoj.ca/problem/3drotate) - I mean it's just a rotation formula
6. [COCI '10 Contest 1 #4 Ljutnja](https://dmoj.ca/problem/coci10c1p4) - Don't actually know why the AC rate is so low, just greedy - spread the shortfall as evenly as possible from the smallest up. We sort and pass once with one `divmod`
7. [DMOPC '19 Contest 3 P3 - Majority](https://dmoj.ca/problem/dmopc19c3p3) - Count subarrays num(1) > num(0) using a running pref balance and a count array. $`O(n)`$, and we don't even need BIT since the balance only moves by $`\pm 1`$.
8. [DMPG '16 S5 - Pizza Bag](https://dmoj.ca/problem/dmpg16s5) - Best circular subarray of length $`\le k`$, pref sums, monotonic deque.
9. [Facebook Hacker Cup '15 Round 1 P3 - Winning at Sports](https://dmoj.ca/problem/fhc15c1p3) - Ballot problems are everywhere, even without the closed form a 2d dp passes.
10. [WC '16 Contest 1 S4 - TP](https://dmoj.ca/problem/wc16c1s4) - Linearity of expectation gives us $`n\left(1 - \left(\frac{n-2}{n}\right)^m\right)`$ (one liner)

A low AC % doesn't always mean a hard problem e.g. Mock CCC '20 J5 - A Prime Problem (3.1%) and CCO '01 P4 - Breaking Level (2.2%) are low because of edge cases and people struggling with interactive io rather than the solution being particularly hard.

---

**\*Calculating the Scaling**

DMOJ of course has a scaling system. Per the [Point System Rework](https://dmoj.ca/post/103-point-system-rework) post and the judge's [source code](https://github.com/DMOJ/online-judge/blob/master/judge/models/profile.py), your score is

```math
\text{pp} = P + B
```

where $`P`$ is the "quality" measure, weighted sum of your best problem scores and $`B`$ is the bonus for the "quantity", or the number of AC problems.

*P.* Let $`S_0 \ge S_1 \ge S_2 \ge \dots`$ be your best score on each problem in desc. order. In this case, they are all 12. DMOJ only counts the top 100 and they are each each weighted by $`0.95^i`$:

```math
P = \sum_{i=0}^{\min(99,\ |S|-1)} 0.95^i \, S_i
```

(`DMOJ_PP_STEP = 0.95`, `DMOJ_PP_ENTRIES = 100` in [`settings.py`](https://github.com/DMOJ/online-judge/blob/master/dmoj/settings.py).)

Since we solved all 12p, $`S_i = 12`$ for all $`i`$, and since $`|S| = 462 \ge 100`$ we have a simple geometric series

```math
P = 12 \sum_{i=0}^{99} 0.95^i = 12 \cdot \frac{1 - 0.95^{100}}{1 - 0.95} = 240\left(1 - 0.95^{100}\right)
```

With $`0.95^{100} \approx 0.005921`$:

```math
P \approx 240 \times 0.994079 \approx 238.58
```

Unfortunately, this means our solutions 101 to 462 contribute essentially nothing to $`P`$. Even with infinitely many 12-pointers, $`P`$ is bounded by $`\frac{12}{0.05} = 240`$.

*Bonus* With $`N`$ = the number of problems we have solved,

```math
B = 300\left(1 - 0.997^{N}\right)
```

(`DMOJ_PP_BONUS_FUNCTION = lambda n: 300 * (1 - 0.997 ** n)` in [`settings.py`](https://github.com/DMOJ/online-judge/blob/master/dmoj/settings.py). In 2019 DMOJ had $`150`$ as the coefficient but according to Gigthub current source uses $`300`$.)

With $`N = 462`$ and $`0.997^{462} \approx 0.249553`$:

```math
B \approx 300 \times 0.750447 \approx 225.13
```

Therefore,

```math
\text{pp} = P + B \approx 238.58 + 225.13 \approx \mathbf{463.71}
```

Therefore due to scaling our $`5544`$ raw points are now a measly $`463.7`$, roughly $`8.4\%`$ of the raw total. (Under the 2019 coeff of $`150`$ it would be even worse $`238.58 + 112.57 \approx 351.15`$.) The upper limit for someone who solved with infinite 12-pointers is $`240 + 300 = 540`$, so 462 of them already gets us $`\frac{463.71}{540} \approx 86\%`$ of the way there.

