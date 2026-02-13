n = int(input())
H = [int(i) for i in input().split()]
W = [int(i) for i in input().split()]
A = [(H[i] + H[i + 1]) * W[i] / 2 for i in range(n)]
print(sum(A))