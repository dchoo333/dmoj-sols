import math

T = int(input())

for _ in range(T):
    x, y, z, rx, ry, rz, theta = map(float, input().split())
    kx, ky, kz = rx / math.sqrt(rx**2 + ry**2 + rz**2), ry / math.sqrt(rx**2 + ry**2 + rz**2), rz / math.sqrt(rx**2 + ry**2 + rz**2)
    
    c, s = math.cos(theta), math.sin(theta)
    dp = kx * x + ky * y + kz * z

    print(f"{(x * c + (ky * z - kz * y) * s + kx * dp * (1 - c)):.6f} {(y * c + (kz * x - kx * z) * s + ky * dp * (1 - c)):.6f} {(z * c + (kx * y - ky * x) * s + kz * dp * (1 - c)):.6f}")
