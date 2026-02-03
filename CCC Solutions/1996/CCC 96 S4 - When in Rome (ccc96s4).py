def r2i(s):
    v = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
    t = p = 0
    try:
        for c in s.upper()[::-1]:
            x = v[c]
            t = t - x if x < p else t + x
            p = x
        if t < 1 or t > 1000:
            raise ValueError
        return t
    except:
        return "CONCORDIA CUM VERITATE"

def i2r(n):
    a = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
    b = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
    s = ""
    for i in range(len(a)):
        while n >= a[i]:
            s += b[i]
            n -= a[i]
    return s

def calc(x):
    y,z = x[:-1].split("+")
    u = r2i(y)
    v = r2i(z)
    if isinstance(u,str) or isinstance(v,str):
        return "CONCORDIA CUM VERITATE"
    w = u + v
    return i2r(w) if 0 < w <= 1000 else "CONCORDIA CUM VERITATE"

for _ in range(int(input())):
    s = input()
    print(s + calc(s))
