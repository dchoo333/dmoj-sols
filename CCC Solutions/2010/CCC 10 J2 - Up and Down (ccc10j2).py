a,b,c,d,s = int(input()),int(input()),int(input()),int(input()),int(input())

x = s//(a+b)
y = s//(c+d)

n = x*(a-b)
m = y*(c-d)

r = s-x*(a+b)
t = s-y*(c+d)

n += min(r,a)-(max(r-a,0))
m += min(t,c)-(max(t-c,0))

print("Nikky" if n>m else "Byron" if m>n else "Tied")
