n = int(input())
obs = [tuple(map(int, input().split())) for _ in range(n)]
obs.sort(key=lambda x: x[0])

ans = 0

for i in range(n - 1):
    distance = abs(obs[i + 1][1] - obs[i][1])
    time = obs[i + 1][0] - obs[i][0]
    speed = distance / time
    if speed > ans:
        ans = speed

print(ans)
