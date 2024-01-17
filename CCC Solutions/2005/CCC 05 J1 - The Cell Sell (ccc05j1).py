daytime_minutes = int(input())
evening_minutes = int(input())
weekend_minutes = int(input())

cost_A = max(0, daytime_minutes - 100) * 0.25 + evening_minutes * 0.15 + weekend_minutes * 0.20

cost_B = max(0, daytime_minutes - 250) * 0.45 + evening_minutes * 0.35 + weekend_minutes * 0.25
print(f"Plan A costs {cost_A:.2f}")
print(f"Plan B costs {cost_B:.2f}")
if cost_A < cost_B:
    print("Plan A is cheapest.")
elif cost_B < cost_A:
    print("Plan B is cheapest.")
else:
    print("Plan A and B are the same price.")

