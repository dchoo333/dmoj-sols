from sys import stdin, stdout

MAX = 32
w, h, cw, ch, steps = int(input()), int(input()), int(input()), int(input()), int(input())
grid = [[True for _ in range(MAX)] for _ in range(MAX)]
coor = (cw + 1, 1)
global direction
direction = "right"


def stuck():
    pos = 0
    if not grid[coor[0] + 1][coor[1]]:
        pos += 1
    if not grid[coor[0] - 1][coor[1]]:
        pos += 1
    if not grid[coor[0]][coor[1] + 1]:
        pos += 1
    if not grid[coor[0]][coor[1] - 1]:
        pos += 1
    return pos == 4

def markObstructions():
    for i in range(1, cw + 1):
        for j in range(1, ch + 1):
            grid[i][j] = False
    for i in range(w - cw + 1, w + 1):
        for j in range(1, ch + 1):
            grid[i][j] = False
    for i in range(1, cw + 1):
        for j in range(h - ch + 1, h + 1):
            grid[i][j] = False
    for i in range(w - cw + 1, w + 1):
        for j in range(h - ch + 1, h + 1):
            grid[i][j] = False

def updatedirection():
    global direction
    if direction == "right" and (not grid[coor[0] + 1][coor[1]] or coor[0] + 1 > w):
        direction = "down"
    elif direction == "down" and (not grid[coor[0]][coor[1] + 1] or coor[1] + 1 > h):
        direction = "left"
    elif direction == "up" and (not grid[coor[0]][coor[1] - 1] or coor[1] - 1 <= 0):
        direction = "right"
    elif direction == "left" and (not grid[coor[0] - 1][coor[1]] or coor[0] - 1 <= 0):
        direction = "up"
    elif direction == "down" and not grid[coor[0] + 1][coor[1] - 1] and grid[coor[0] + 1][coor[1]]:
        direction = "right"
    elif direction == "left" and not grid[coor[0] + 1][coor[1] + 1] and grid[coor[0]][coor[1] + 1]:
        direction = "down"
    elif direction == "up" and not grid[coor[0] - 1][coor[1] + 1] and grid[coor[0] - 1][coor[1]]:
        direction = "left"
    elif direction == "right" and not grid[coor[0] - 1][coor[1] - 1] and grid[coor[0]][coor[1] - 1]:
        direction = "up"

markObstructions()
if 2 * cw == w - 1:
    direction = "down"
do = True
while steps > 0:
    if stuck():
        stdout.write(str(coor[0]) + "\n" + str(coor[1]) + "\n")
        do = False
        break
    grid[coor[0]][coor[1]] = False
    if direction == "right":
        coor = (coor[0] + 1, coor[1])
    elif direction == "left":
        coor = (coor[0] - 1, coor[1])
    elif direction == "up":
        coor = (coor[0], coor[1] - 1)
    elif direction == "down":
        coor = (coor[0], coor[1] + 1)
    updatedirection()
    steps -= 1
if do:
    stdout.write(str(coor[0]) + "\n" + str(coor[1]) + "\n")