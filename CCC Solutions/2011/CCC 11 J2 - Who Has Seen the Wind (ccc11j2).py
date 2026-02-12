h = int(input())
m = int(input())
for i in range(1, 241):
    if -6*i**4 + h*i**3 + 2*i**2 + i <= 0:
        hour = i
        break
else:
    hour = None

if hour and hour <= m:
    print("The balloon first touches ground at hour: ")
    print(hour)
else:
    print("The balloon does not touch ground in the given time.")
