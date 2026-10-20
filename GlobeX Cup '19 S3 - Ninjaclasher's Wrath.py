def go(x, h):
    n = len(x); r = [-1] * n; st = []
    for i in range(n - 1, -1, -1):
        if st:
            m = 0
            while len(st) >= 2:
                a = st[-1]; b = st[-2]
                if (h[a] - h[i]) * (x[b] - x[i]) <= (h[b] - h[i]) * (x[a] - x[i]):
                    m = max(m, h[a]); st.pop()
                else: break
            r[i] = max(m, h[st[-1]])
        st.append(i)
    return r

n = int(input())
h = list(map(int, input().split()))
d = list(map(int, input().split())) if n > 1 else []

x = [0] * n
for i in range(1, n): x[i] = x[i - 1] + d[i - 1]

R = go(x, h)
L = go([-v for v in reversed(x)], h[::-1])[::-1]

print("\n".join(f"{L[i]} {R[i]}" for i in range(n)))