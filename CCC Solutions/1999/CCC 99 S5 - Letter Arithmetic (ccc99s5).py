from functools import reduce

def dfs(i, L, asn, carry):
    a,b,c = s1[-i-1], s2[-i-1], s3[-i-1]
    for p in poss[a]:
        if (a in asn and asn[a] != p) or (p in asn.values() and a not in asn): continue
        asn1 = dict(asn)
        asn1[a] = p
        for q in poss[b]:
            if (b in asn1 and asn1[b] != q) or (q in asn1.values() and b not in asn1): continue

            asn2 = dict(asn1)
            asn2[b] = q
            s = (p+q+carry)%10
            nc = (p+q+carry)//10
            if s in poss[c]:
                if (c in asn2 and asn2[c] != s) or (s in asn2.values() and c not in asn2): continue
                asn3 = dict(asn2)
                asn3[c] = s
                if i == L-1:
                    if len(s3) > L and nc==0: continue
                    return True, asn3
                found, res = dfs(i+1,L,asn3,nc)
                if found: return True, res
    return False, asn

for _ in range(int(input())):
    s1, s2, s3 = [list(input()) for _ in range(3)]

    poss = {}
    for w in [s1,s2,s3]:
        for ch in w:
            if ch not in poss: poss[ch] = list(range(10))
    for w in [s1,s2,s3]:
        poss[w[0]] = list(range(1,10))

    l1,l2,l3 = len(s1),len(s2),len(s3)
    if l1==l2==l3 and s1[0]==s2[0]:
        poss[s1[0]] = poss[s2[0]] = [1,2,3,4]
        poss[s3[0]] = [2,3,4,5,6,7,8,9]
    elif l3>max(l1,l2):
        poss[s3[0]] = [1]
        if l1>l2: poss[s1[0]] = [9]
        elif l2>l1: poss[s2[0]] = [9]

    L = min(l1,l2)
    start_map = {}
    if poss[s3[0]]==[1]: start_map[s3[0]] = 1
    if poss[s1[0]]==[9]: start_map[s1[0]] = 9
    elif poss[s2[0]]==[9]: start_map[s2[0]] = 9

    ok, mapping = dfs(0,L,start_map,0)
    print(reduce(lambda n, ch: n*10 + mapping[ch], s1, 0))
    print(reduce(lambda n, ch: n*10 + mapping[ch], s2, 0))
    print(reduce(lambda n, ch: n*10 + mapping[ch], s3, 0))
    print()
