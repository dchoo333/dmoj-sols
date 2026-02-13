s = input()
n = len(s)
A = [0]*(n+1)
B = [0]*(n+1)
C = [0]*(n+1)
for i in range(1, n+1):
    A[i] = A[i-1] + (s[i-1]=='A')
    B[i] = B[i-1] + (s[i-1]=='B')
    C[i] = C[i-1] + (s[i-1]=='C')
cntA, cntB, cntC = A[n], B[n], C[n]
ans = float('inf')
for l in range(1, n+1):
    if l >= cntA+cntB:
        nx, ny = A[n], B[n]
        s1 = ny-(B[l]-B[l-ny]) + nx-(A[l-ny]-A[l-ny-nx])
        b = min(B[l-ny]-B[l-ny-nx], A[l]-A[l-ny])
        ans = min(ans, s1-b)
        nx, ny = B[n], A[n]
        s1 = ny-(A[l]-A[l-ny]) + nx-(B[l-ny]-B[l-ny-nx])
        b = min(A[l-ny]-A[l-ny-nx], B[l]-B[l-ny])
        ans = min(ans, s1-b)
    if l >= cntA+cntC:
        nx, ny = A[n], C[n]
        s1 = ny-(C[l]-C[l-ny]) + nx-(A[l-ny]-A[l-ny-nx])
        b = min(C[l-ny]-C[l-ny-nx], A[l]-A[l-ny])
        ans = min(ans, s1-b)
        nx, ny = C[n], A[n]
        s1 = ny-(A[l]-A[l-ny]) + nx-(C[l-ny]-C[l-ny-nx])
        b = min(A[l-ny]-A[l-ny-nx], C[l]-C[l-ny])
        ans = min(ans, s1-b)
    if l >= cntB+cntC:
        nx, ny = B[n], C[n]
        s1 = ny-(C[l]-C[l-ny]) + nx-(B[l-ny]-B[l-ny-nx])
        b = min(C[l-ny]-C[l-ny-nx], B[l]-B[l-ny])
        ans = min(ans, s1-b)
        nx, ny = C[n], B[n]
        s1 = ny-(B[l]-B[l-ny]) + nx-(C[l-ny]-C[l-ny-nx])
        b = min(B[l-ny]-B[l-ny-nx], C[l]-C[l-ny])
        ans = min(ans, s1-b)
print(ans)
