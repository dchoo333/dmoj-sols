a = int(input())
q = a // 25
a %= 25
d = a // 10
a %= 10
n = a // 5
a %= 5
c = a
r = []
if q: r.append(f"{q} {'quarter' if q==1 else 'quarters'}")
if d: r.append(f"{d} {'dime' if d==1 else 'dimes'}")
if n: r.append(f"{n} {'nickel' if n==1 else 'nickels'}")
if c: r.append(f"{c} {'cent' if c==1 else 'cents'}")
print(f"{int(input()) if False else a} cent{'s' if a!=1 else ''} requires {', '.join(r)}.")
