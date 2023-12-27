modulus = 1000000007

def func(num, result):
    if num == 0:
        result[0] = 0
        result[1] = 1
        return

    func((num // 2), result)
    x = result[0]
    y = result[1]

    z = 2 * y - x

    if z < 0:
        z += modulus
    z = (x * z) % modulus
    w = (x * x + y * y) % modulus

    if num % 2 == 0:
        result[0] = z
        result[1] = w
    else:
        result[0] = w
        result[1] = z + w

N = int(input())
output_result = [0] * 2

func(N, output_result)

print(output_result[0])
