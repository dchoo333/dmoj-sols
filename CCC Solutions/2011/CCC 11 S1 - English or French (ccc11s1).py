n=int(input())
s=t=0
for _ in range(n):
    l=input()
    s+=l.lower().count('s')
    t+=l.lower().count('t')
print('English' if t>s else 'French')
