s=[int(input())for _ in range(int(input()))]
print(sorted(set(s),reverse=1)[2],s.count(sorted(set(s),reverse=1)[2]))
