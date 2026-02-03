for _ in range(int(input())):
    d = int(input())
    print("N" if d <= 45 or d >= 315 else
          "E" if 45 < d <= 135 else
          "S" if 135 < d <= 225 else
          "W" if 225 < d <= 315 else None)