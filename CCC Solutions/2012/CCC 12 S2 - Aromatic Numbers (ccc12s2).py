s = input()[::-1]

k = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
k2 = {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9}

res = 0
last = 'I'

for i in range(0,len(s),2):
    nxt = k[s[i]] * k2[s[i+1]]
    if k[s[i]] < k[last]:
        res -= nxt
    else:
        res += nxt
    last = s[i]

print(res)
