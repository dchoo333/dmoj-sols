num_pitches = int(input())
pitch_sequence = input()

laugh_grid = [["." for col in range(num_pitches)] for row in range(2 * num_pitches + 1)]
laugh_strs = []
current_row = num_pitches

for i in range(num_pitches):
    if pitch_sequence[i] == 'v':
        current_row += 1
        laugh_grid[current_row][i] = "\\"
    elif pitch_sequence[i] == '>':
        laugh_grid[current_row][i] = "_"
    else: 
        laugh_grid[current_row][i] = "/"
        current_row -= 1

for row in laugh_grid:
    laugh_strs.append(''.join(map(str, row)))

for laugh_str in laugh_strs:
    if laugh_str != "." * num_pitches:
        print(laugh_str)
