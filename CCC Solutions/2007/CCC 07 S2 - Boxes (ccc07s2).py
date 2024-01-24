import sys
import math
def check(a, b):
    temp1 = sorted(a)
    temp2 = sorted(b)
    for i in range(3):
        if temp1[i] > temp2[i]:
            return False
    return True

N = int(input())
s = [None]*N
sizes = [None]*N
for i in range(N):
    a, b, c = map(int, input().split())
    s[i] = str(a) + " " + str(b) + " " + str(c)
    sizes[i] = a * b * c

cases = int(input())
for i in range(cases):
    found = False
    temp = list(map(int, input().split()))
    ans = float('inf')
    for j in range(len(s)):
        if check(temp, list(map(int, s[j].split()))):
            ans = min(sizes[j], ans)
            found = True
    if not found:
        print("Item does not fit.")
    else:
        print(ans)
