N = int(input())
ans = []
for i in range(N):
    if i == 0:
        rate = float(input())
        hours = int(input())
        tax_category = input()
        donation = input()
        
        if hours <= 40:
            salary = hours*rate
        else:
            salary = 40*rate
            salary += 2 * (hours-40) * rate # remove 2 if fares_x's comment is correct
        
        dictionary = {'A': 0, 'B': 10, 'C': 20, 'D': 29, 'E': 35}
        
        tax = dictionary.get(tax_category)
        
        salary = salary - ((tax/100) * salary)
        if donation == 'y':
            salary = salary - 10
    else:
    
        blank = input() # Account for the bruh Newline
        rate = float(input())
        hours = int(input())
        tax_category = input()
        donation = input()
        
        if hours <= 40:
            salary = hours*rate
        else:
            salary = 40*rate
            salary += 2 * (hours-40) * rate # remove 2 if fares_x's comment is correct
        
        dictionary = {'A': 0, 'B': 10, 'C': 20, 'D': 29, 'E': 35}
        
        tax = dictionary.get(tax_category)
        
        salary = salary - ((tax/100) * salary)
        if donation == 'y':
            salary = salary - 10        
    
    ans.append(f"{salary:.2f}")
    
for item in ans:
    print(item)
