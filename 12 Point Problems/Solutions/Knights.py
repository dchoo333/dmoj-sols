import heapq

def puzzle_cost(n):
    if n % 2 == 0:
        h = n // 2
        return h * h + (h % 2)
    else:
        base = n * n // 4
        extra = 2 if ((n + 2) // 4) % 2 == 1 else 0
        return base + extra

def solve():
    import sys
    input_data = sys.stdin.read().split()
    idx = 0

    T, M, X = int(input_data[idx]), int(input_data[idx+1]), int(input_data[idx+2])
    idx += 3

    points = [0] * (T + 1)  # 1-indexed
    for i in range(2, T + 1):
        points[i] = int(input_data[idx])
        idx += 1

    adj = [[] for _ in range(T + 1)]
    for _ in range(M):
        u, v, n = int(input_data[idx]), int(input_data[idx+1]), int(input_data[idx+2])
        idx += 3
        cost = puzzle_cost(n)
        adj[u].append((v, cost))
        adj[v].append((u, cost))


    num_rooms = T 
    def room_to_bit(r):
        return r - 2  # room 2 → bit 0, room 3 → bit 1, ...

    total_bits = T - 1  # rooms 2..T
    INF = float('inf')

    dp = [[INF] * (1 << total_bits) for _ in range(T + 1)]

    start_mask = 0
    dp[1][start_mask] = 0

    pq = [(0, 1, start_mask)]

    while pq:
        cost, room, mask = heapq.heappop(pq)

        if cost > dp[room][mask]:
            continue

        collected = sum(points[i] for i in range(2, T + 1) if (mask >> room_to_bit(i)) & 1)
        if collected >= X:
            print(cost)
            return

        for neighbor, edge_cost in adj[room]:
            new_cost = cost + edge_cost
            new_mask = mask
            if neighbor != 1 and not ((mask >> room_to_bit(neighbor)) & 1):
                new_mask = mask | (1 << room_to_bit(neighbor))

            if new_cost < dp[neighbor][new_mask]:
                dp[neighbor][new_mask] = new_cost
                heapq.heappush(pq, (new_cost, neighbor, new_mask))

    print('diddy ahh blud')

solve()