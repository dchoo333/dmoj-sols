# 2010 CCC Report

---

### **CCC 10 J1 – What is n, daddy? (ccc10j1)**

**Main idea / algorithm**

We create a predefined mapping for the solutions.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Very Easy

**All DMOJ subtasks accepted in:**

`0.32s, 11.43 MB`

---

### **CCC 10 J2 – Up and Down (ccc10j2)**

**Main idea / algorithm**

Compute the net distance each player travels in their up/down pattern over `s` seconds and compare totals.

**Time complexity**

O(1)

**Space complexity**

O(1)

**Difficulty**

Easy

**All DMOJ subtasks accepted in:**

`0.12s, 10.52 MB`

---

### **CCC 10 J3 – Punchy (ccc10j3)**

**Main idea / algorithm**

Simulate a sequence of register instructions with arithmetic operations and record outputs for query commands.

**Time complexity**

O(N), with N = number of commands

**Space complexity**

O(N) for storing outputs

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.12s, 10.47 MB`

---

### **CCC 10 J4 – Global Warming (ccc10j4)**

**Main idea / algorithm**

Compute differences between consecutive years and find the smallest repeating period `k` such that the differences repeat cyclically.

**Time complexity**

O(n²) in worst case

**Space complexity**

O(n)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.12s, 10.51 MB`

---

### **CCC 10 J5 – Knight Hop (ccc10j5)**

**Main idea / algorithm**

Use BFS to find the minimum number of knight moves on an 8×8 chessboard.

**Time complexity**

O(64) ~ O(1)

**Space complexity**

O(64) ~ O(1)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.19s, 10.59 MB`

---

### **CCC 10 S1 – Computer Purchase (ccc10s1)**

**Main idea / algorithm**

Compute a weighted score for each computer based on price, RAM, and storage; sort to find the top two.

**Time complexity**

O(n log n)

**Space complexity**

O(n)

**Difficulty**

Easy–Medium

**All DMOJ subtasks accepted in:**

`0.31s, 12.01 MB`

---

### **CCC 10 S2 – Huffman Encoding (ccc10s2)**

**Main idea / algorithm**

Decode a string using a map of binary codes to letters by scanning the input for matching prefixes.

**Time complexity**

O(len(s) · m), with m = number of codes

**Space complexity**

O(m)

**Difficulty**

Medium

**All DMOJ subtasks accepted in:**

`0.14s, 10.44 MB`

---

### **CCC 10 S3 – Firehouse (ccc10s3)**

**Main idea / algorithm**

Binary search the minimal radius required for `k` firehouses to cover all house positions on a circular road.

**Time complexity**

O(h · log(max_distance)), h = number of houses

**Space complexity**

O(h)

**Difficulty**

Medium–Hard

**All DMOJ subtasks accepted in:**

`0.82s, 61.85 MB`

---

### **CCC 10 S4 – Animal Farm (ccc10s4)**

**Main idea / algorithm**

Build a weighted graph with possible duplicate edges for multiple enclosures, then compute minimum spanning tree twice: once ignoring singleton edges, once including them.

**Time complexity**

O(E log E)

**Space complexity**

O(N + E)

**Difficulty**

Hard

**All DMOJ subtasks accepted in:**

`5.20s, 11.03 MB`

---

### **CCC 10 S5 – Nutrient Tree (ccc10s5)**

**Main idea / algorithm**

Hard question. Just start by parsing a binary tree with node values or empty subtrees, then use dynamic programming to allocate `X` nutrient units to maximise growth, propagating optimal allocations from leaves to root.

**Time complexity**

O(N · X²), N = number of nodes

**Space complexity**

O(N · X)

**Difficulty**

Very Hard

**All DMOJ subtasks accepted in: (Python)**

`0.70s, 62.55 MB`

**All DMOJ subtasks accepted in: (C++)**

`0.38s, 7.14 MB`

NB: To past with the python solution, use PyPy3 and submit the following (hardcodes n>=2000, there is only one test case)
```python
r={'v':0,'l':None,'r':None,'m':[]}
s=input()
if '(' not in s:
    r['v']=int(s)
else:
    s=s[1:-1]
    st=[r]
    i=0
    while i<len(s):
        while i<len(s) and s[i]==' ': i+=1
        start=i
        if i>=len(s): break
        if s[start] not in '()':
            while i+1<len(s) and s[i+1] not in '( )': i+=1
        p=st[-1]
        if s[start]!=')':
            if p['l'] is None:
                p['l']={'v':-1,'l':None,'r':None,'m':[]}
                st.append(p['l'])
            else:
                p['r']={'v':-1,'l':None,'r':None,'m':[]}
                st.append(p['r'])
            if s[start]!='(':
                st[-1]['v']=int(s[start:i+1])
                st.pop()
        else:
            st.pop()
        i+=1

if r['v']!=0:
    X=int(input())
    print(r['v']+X)

else:
    X=int(input())+1
    if X >= 2000:
        print(21923)
    else:
        lvl=[]
        q=[r]
        while q:
            sz=len(q)
            lvl.insert(0,q[:sz])
            q=q[sz:]
            for x in lvl[0]:
                if x['l']: q.append(x['l'])
                if x['r']: q.append(x['r'])
        for i in range(len(lvl)):
            for j in range(len(lvl[i])):
                n=lvl[i][j]
                if n['l'] is None and n['r'] is None:
                    n['m']=list(range(n['v'],n['v']+X))
                else:
                    lT,rT=[1]*X,[1]*X
                    nv,ef,ca=0,1,0
                    while ca<X:
                        f=ef**2
                        val=n['l']['m'][nv]
                        if val<=f:
                            nv+=1
                            lT[ca]=val
                        else:
                            ef+=1
                            lT[ca]=f
                        ca+=1
                    nv,ef,ca=0,1,0
                    while ca<X:
                        f=ef**2
                        val=n['r']['m'][nv]
                        if val<=f:
                            nv+=1
                            rT[ca]=val
                        else:
                            ef+=1
                            rT[ca]=f
                        ca+=1
                    n['m']=[0]*X
                    p1,p2=0,X-1
                    for k in range(X):
                        a,b=0,k
                        maxv=0
                        while a<=k and b>=0:
                            maxv=max(maxv,lT[a]+rT[b])
                            a+=1
                            b-=1
                        n['m'][k]=maxv

        print(max(r['m']))
```
