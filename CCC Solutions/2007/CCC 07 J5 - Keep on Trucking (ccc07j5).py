from collections import *
import sys

truck = [-1, 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000, 999999999]
a = int(input())
b = int(input())

for _ in range(int(input())):
    truck.append(int(input()))
truck.sort()

motlen = len(truck) - 1
dp = [0] * (motlen + 1)
dp[1] = 1

for i in range(1, motlen):
    incc = 0
    while truck[i + incc] - truck[i] <= b:
        if truck[i + incc] - truck[i] >= a:
            dp[i + incc] += dp[i]
        incc += 1

print(dp[motlen - 1])