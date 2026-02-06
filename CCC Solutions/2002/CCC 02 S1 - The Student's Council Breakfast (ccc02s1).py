p, g, r, o, T = [int(input()) for _ in range(5)]

cnt = 0
mn = 10**18

for i in range(T // p + 1):
    for j in range((T - i*p) // g + 1):
        for k in range((T - i*p - j*g) // r + 1):
            rem = T - i*p - j*g - k*r
            if rem < 0 or rem % o:
                continue
            l = rem // o

            s = i + j + k + l
            if s < mn:
                mn = s

            print(f"# of PINK is {i} # of GREEN is {j} # of RED is {k} # of ORANGE is {l}")
            cnt += 1

print(f"Total combinations is {cnt}.")
print(f"Minimum number of tickets to print is {mn}.")
