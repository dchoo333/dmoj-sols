two = ["a","b","c"]
three = ["d","e","f"]
four = ["g","h","i"]
five = ["j","k","l"]
six = ["m","n","o"]
seven = ["p","q","r","s"]
eight = ["t","u","v"]
nine = ["w","x","y","z"]
lst = [two,three,four,five,six,seven,eight,nine]
inp = ""
times = []
while inp != "halt":
    inp = input("")
    prevnumber = -1
    v=0
    time = 0
    for letters in inp:
        v = 0
        for numbers in lst:
            v+=1
            if letters in numbers:
                if prevnumber == v:
                    time += 2
                time += numbers.index(letters)+1
                prevnumber = v
    times.append(time)
times.pop()
for values in times:
    print(values)