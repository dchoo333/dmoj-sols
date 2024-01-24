adj = []
nums = []
N = 0
def find_path(i):
    global nums, adj, N
    for nxt in adj[i]:
        if nxt == N:
            nums[i] += 1
        elif nums[nxt] != 0:
            nums[i] += nums[nxt]
        else:
            find_path(nxt)
            nums[i] += nums[nxt]

N = int(input())
adj = [list() for _ in range(N+1)]
nums = [0 for _ in range(N+1)]
for i in range(N+1):
    adj[i] = []
while True:
    line = input().split()
    a = int(line[0])
    b = int(line[1])
    if a == 0 and b == 0:
        break
    adj[a].append(b)
find_path(1)
print(nums[1])
