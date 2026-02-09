d, e, w = [int(input()) for _ in range(3)]
a=max(0,d-100)*0.25+e*0.15+w*0.2
b=max(0,d-250)*0.45+e*0.35+w*0.25
print(f'''Plan A costs {a:.2f}
Plan B costs {b:.2f}''')
print("Plan A is cheapest." if a<b else "Plan B is cheapest." if b<a else "Plan A and B are the same price.")
