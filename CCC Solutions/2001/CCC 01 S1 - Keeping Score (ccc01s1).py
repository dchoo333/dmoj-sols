cards = input()
suits = []
suits = [list(cards[cards.find("C")+1:cards.find("D")]),
         list(cards[cards.find("D")+1:cards.find("H")]),
         list(cards[cards.find("H")+1:cards.find("S")]),
         list(cards[cards.find("S")+1:])]
clubs = suits[0]
diamonds = suits[1]
hearts = suits[2]
spades = suits[3]

print("Cards Dealt%20s" % "Points")
points = []

points = [3 if not i else 2 if len(i) == 1 else 1 if len(i) == 2 else 0 + sum(4 if j == "A" else 3 if j == "K" else 2 if j == "Q" else 1 if j == "J" else 0 for j in i) for i in suits]

print(f"Clubs {' '.join(clubs):<23} {points[0]}")
print(f"Diamonds {' '.join(diamonds):<20} {points[1]}")
print(f"Hearts {' '.join(hearts):<22} {points[2]}")
print(f"Spades {' '.join(spades):<22} {points[3]}")
print(f"{'                       Total':<23} {sum(points)}")