num_test_cases = int(input())

for case_num in range(num_test_cases):
    matrix_size = int(input())
    
    matrix = tuple(tuple(int(input()) for _ in range(matrix_size)) for _ in range(matrix_size))
    
    sum_first_row = sum(matrix[0])
    is_good = True
    
    for i in range(matrix_size):
        row_sum = 0
        for j in range(matrix_size):
            row_sum += matrix[i][j]
        
        if row_sum != sum_first_row:
            is_good = False
            break
    print("yes" if is_good else "no")
    if case_num != num_test_cases - 1:
        input()
