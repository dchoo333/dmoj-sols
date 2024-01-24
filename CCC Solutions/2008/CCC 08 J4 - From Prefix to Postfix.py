postfix = []

st = input().strip()
while st != "0":
    s = st.split(" ")
    stack = []
    for i in range(len(s) - 1, -1, -1):
        a = s[i]
        if s[i] in ["+", "*", "/", "-", "%", "^"]:
            x = stack.pop()
            y = stack.pop()
            stack.append(x + " " + y + " " + a)
        else:
            stack.append(a + "")
    postfix.append(str(stack.pop()))
    st = input().strip()
for post in postfix:
    print(post)