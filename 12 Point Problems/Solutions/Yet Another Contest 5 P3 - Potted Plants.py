import sys
K = int(input())
used = bytearray(K * K)
for a in range(2, K - 1, 2):
    if K % 2 == 0: used[a * K + a + 1] = used[(a + 1) * K + a] = 1

pt = [0] * K
st = [0]; W = []
while st:
    v = st[-1]; p = pt[v]; b = v * K
    while p < K and (p == v or used[b + p]): p += 1
    pt[v] = p
    if p < K:
        used[b + p] = used[p * K + v] = 1
        st.append(p)
    else:
        W.append(st.pop())

S = W + W[::-1]
sys.stdout.write(" ".join(str(x + 1) for x in S) + "\n")