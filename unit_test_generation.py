import numpy as np
import os


def generate_matrices_with_dimensions(rows_a, cols_a, cols_b, folder):
    
    # Generate random matrices
    A = np.random.randint(0, 10, (rows_a, cols_a))  
    B = np.random.randint(0, 10, (cols_a, cols_b))  
    C = A @ B  

    # Save matrices A, B, and C, including their dimensions 
    with open(f"{folder}/A.txt", 'w') as f:
        f.write(f"{rows_a} {cols_a}\n") 
        np.savetxt(f, A, fmt='%d')       

    with open(f"{folder}/B.txt", 'w') as f:
        f.write(f"{cols_a} {cols_b}\n")  
        np.savetxt(f, B, fmt='%d')       

    with open(f"{folder}/C.txt", 'w') as f:
        f.write(f"{rows_a} {cols_b}\n") 
        np.savetxt(f, C, fmt='%d')      


# Generate test cases are reangulgh matrices
rectangular_test_cases = [
    (50, 30, 40),   
    (60, 45, 50),  
    (80, 70, 90),  
    (100, 50, 75),  
    (120, 80, 60),  
    (200, 150, 100) 
]

# Generate test cases for square matrices 
square_test_cases = [(size, size, size) for size in range(100, 501, 20)]

# Combine both rectangular and square test cases
all_test_cases = rectangular_test_cases + square_test_cases

# Create unit test directories and generate matrices for each test case
for unit, (rows_a, cols_a, cols_b) in enumerate(all_test_cases, start=1):
    folder = f"Unit_test/unit_{unit}"
    os.makedirs(folder, exist_ok=True)
    generate_matrices_with_dimensions(rows_a, cols_a, cols_b, folder)

print("Test case matrices generated successfully!")

def generate_negative_test_cases(folder):
    os.makedirs(folder, exist_ok=True)

    # Zero-dimension matrix
    with open(f"{folder}/A.txt", 'w') as f:
        f.write("0 5\n")

    with open(f"{folder}/B.txt", 'w') as f:
        f.write("5 0\n")

    # Dimension mismatch
    with open(f"{folder}/A.txt", 'w') as f:
        f.write("4 3\n1 2 3\n4 5 6\n7 8 9\n10 11 12\n")
    with open(f"{folder}/B.txt", 'w') as f:
        f.write("2 4\n1 2 3 4\n5 6 7 8\n")

    print("Negative test cases generated successfully!")
