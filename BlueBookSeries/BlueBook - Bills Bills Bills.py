while (account_number := int(input())) >= 0:
    m1, m2 = map(int, input().split())
    consumption = (m2 - m1) % 10000
    charge = 6.59 + min(20, max(0, consumption - 10)) * 0.2373 + \
             min(55, max(0, consumption - 30)) * 0.2271 + \
             min(85, max(0, consumption - 85)) * 0.2178 + \
             max(0, consumption - 170) * 0.2085
    print(f"Account #: {account_number}\nBill: {charge:.2f}")
