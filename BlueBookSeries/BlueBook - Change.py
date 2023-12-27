def make_change(amount):
    quarters = amount // 25
    amount %= 25

    dimes = amount // 10
    amount %= 10

    nickels = amount // 5
    amount %= 5

    cents = amount

    change = []

    if quarters > 0:
        change.append(f"{quarters} {'quarter' if quarters == 1 else 'quarters'}")
    if dimes > 0:
        change.append(f"{dimes} {'dime' if dimes == 1 else 'dimes'}")
    if nickels > 0:
        change.append(f"{nickels} {'nickel' if nickels == 1 else 'nickels'}")
    if cents > 0:
        change.append(f"{cents} {'cent' if cents == 1 else 'cents'}")

    return ", ".join(change)

# Input reading
amount = int(input())

# Get the change
change_str = make_change(amount)

# Output the result
print(f"{amount} cent{'s' if amount != 1 else ''} requires {change_str}.")

