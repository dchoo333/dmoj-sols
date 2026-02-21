n = int(input())
d = ["1","2","3","4","5","6","7","8","9","10"]
e = ["one","two","three","four","five","six","seven","eight","nine","ten"]
et = {"one":1,"two":2,"three":3,"four":4,"five":5,"six":6,"seven":7,"eight":8,"nine":9,"ten":10}
f = ["un","deux","trois","quatre","cinq","six","sept","huit","neuf","dix"]
ft = {"un":1,"deux":2,"trois":3,"quatre":4,"cinq":5,"six":6,"sept":7,"huit":8,"neuf":9,"dix":10}
c = ["一","二","三","四","五","六","七","八","九","十"]
ct = {"一":1,"二":2,"三":3,"四":4,"五":5,"六":6,"七":7,"八":8,"九":9,"十":10}

for _ in range(n):
    s = input()
    a,b = s.split()
    if a in d:
        x = int(a)
    elif a in e:
        x = et[a]
    elif a in f:
        x = ft[a]
    elif a in c:
        x = ct[a]
    if b in d:
        y = int(b)
    elif b in e:
        y = et[b]
    elif b in f:
        y = ft[b]
    elif b in c:
        y = ct[b]
    print(x+y)
