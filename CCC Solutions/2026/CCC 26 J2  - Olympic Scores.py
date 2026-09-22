lst = [int(input()) for _ in range(5)]
factor = int(input())
lst.remove(max(lst))
lst.remove(min(lst))
print(sum(lst) * factor)
