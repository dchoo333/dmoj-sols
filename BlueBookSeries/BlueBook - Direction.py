for _ in range(int(input())):
    direction = int(input())
    print("N" if direction <= 45 or direction >= 315 else
          "E" if 45 < direction <= 135 else
          "S" if 135 < direction <= 225 else
          "W" if 225 < direction <= 315 else None)
