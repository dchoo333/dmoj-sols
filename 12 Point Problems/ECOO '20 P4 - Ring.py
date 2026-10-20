P = 10**9 + 7

for _ in range(int(input())):
    n = int(input())
    st = [[1, 0, None]]
    fn = {}
    for _ in range(n):
        s = input().split()
        t = st[-1]
        if s[0] == 'ADD': t[1] = (t[1] + int(s[1])) % P
        elif s[0] == 'SUB': t[1] = (t[1] - int(s[1])) % P
        elif s[0] == 'MULT':
            y = int(s[1])
            t[0] = t[0] * y % P; t[1] = t[1] * y % P
        elif s[0] == 'FUN': st.append([1, 0, s[1]])
        elif s[0] == 'END':
            a, b, f = st.pop()
            fn[f] = (a, b)
        else:
            c, d = fn[s[1]]
            t[0] = c * t[0] % P; t[1] = (c * t[1] + d) % P
    print(st[0][1])