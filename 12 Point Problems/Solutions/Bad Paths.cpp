M=10**9+7
N=10**6+5
f=[1]*N
for i in range(1,N):f[i]=f[i-1]*i%M
g=[1]*N
g[-1]=pow(f[-1],M-2,M)
for i in range(N-2,-1,-1):g[i]=g[i+1]*(i+1)%M
p=[1]*N
for i in range(1,N):p[i]=(p[i-1]+g[i])%M
h=pow(2,M-2,M)
for _ in range(int(input())):
 n=int(input())
 print(0 if n<3 else f[n]*p[n-3]%M*h%M)
