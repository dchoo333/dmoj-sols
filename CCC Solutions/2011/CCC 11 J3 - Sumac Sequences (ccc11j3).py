a,b,l=int(input()),int(input()),2
while True:
    c=a-b
    l+=1
    if c>b:
        print(l)
        break
    a,b=b,c
