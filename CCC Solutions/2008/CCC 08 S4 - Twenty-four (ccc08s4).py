for _ in range(int(input())):
    h = tuple(int(input()) for _ in range(4))
    memo = {}
    
    stack = [(h,)]
    ans = 0

    def func(h):
        if h in memo:
            return memo[h]
        if len(h) == 1:
            memo[h] = h[0] if h[0] <= 24 else 0
            return memo[h]
        n = len(h)
        ans = 0
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                a, b = h[i], h[j]
                rest = tuple(h[k] for k in range(n) if k != i and k != j)
                nv = [a+b, a-b, a*b]
                if b != 0 and a % b == 0:
                    nv.append(a//b)
                for val in nv:
                    ans = max(ans, func(rest + (val,)))
        memo[h] = ans
        return ans

    print(func(h))
