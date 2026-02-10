coldest_city = ""
coldest_temperature = float('inf')

while True:
    try:
        city, temperature = input().split()
        temperature = int(temperature)
        
        if temperature < coldest_temperature:
            coldest_city = city
            coldest_temperature = temperature
        
        if city == 'Waterloo':
            break
    except ValueError:
        break

print(coldest_city)