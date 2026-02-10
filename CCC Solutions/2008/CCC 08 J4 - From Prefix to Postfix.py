res = []

s = input()
while s != "0":
    t = s.split()
    st = []
    for i in range(len(t) - 1, -1, -1):
        x = t[i]
        if x in "+-*/%^":
            a = st.pop()
            b = st.pop()
            st.append(a + " " + b + " " + x)
        else:
            st.append(x)
    res.append(st.pop())
    s = input()

for x in res:
    print(x)
