ngoc, minh = input(), input()
ni, mi = 0, 0
ne, me = 0, 0
beats = {'R':'G', 'G':'B', 'B':'R'}
while ni < len(ngoc) and mi<len(minh):
    if ngoc[ni] == minh[mi]:
        ne += 1; me += 1; ni += 1; mi += 1
    elif beats[ngoc[ni]] == minh[mi]:
        ne += 1
        mi += 1
    else:
        me += 1
        ni += 1

ne += len(ngoc) - ni
me += len(minh) - mi
print(ne, me, sep = '\n')
