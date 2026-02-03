a, b = float(input()), float(input())
print("indeterminate" if a == 0 and b == 0 else "undefined" if a == 0 else "{:.2f}".format(-b / a))