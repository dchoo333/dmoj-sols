n=int(input())
s=[input() for _ in range(n)]
a=[input() for _ in range(n)]
print(sum(s[i]==a[i] for i in range(n)))
