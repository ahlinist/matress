import random

def generate_matrix(X):
    matrix = [[random.uniform(-0.2, 0.2) for _ in range(X)] for _ in range(X)]
    return matrix

def write_matrix_to_file(matrix, filename):
    with open(filename, 'w') as file:
        for row in matrix:
            row_str = ','.join(map(str, row))
            file.write(row_str + '\n')

if __name__ == "__main__":
    X = 300  # Change this to your desired matrix size
    matrix = generate_matrix(X)
    write_matrix_to_file(matrix, 'input.txt')
