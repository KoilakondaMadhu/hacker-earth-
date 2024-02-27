def solve(N, C):
    stack = []      # Create an empty stack to store elements
    result = []     # Create an empty list to store the result

    for i in range(N):   # Iterate through the elements of C
        if C[i] == 0:    # If the current element is 0
            result.append(stack.pop())   # Pop an element from the stack and append it to the result list
        else:
            stack.append(C[i])   # If the current element is not 0, push it onto the stack

    return result   # Return the result list

# Read the input N
N = int(input())
# Read the input list C
C = list(map(int, input().split()))

# Call the solve function with inputs N and C
out_ = solve(N, C)

# Print the result list as a space-separated string
print(' '.join(map(str, out_)))
