import sys

input = sys.stdin.readline  # Redefining input function to read from standard input (stdin)

t = int(input())  # Read the number of test cases

for _ in range(t):  # Iterate over each test case
    n = int(input())  # Read the number of monsters
    monsters = map(int, input().split())  # Read the strengths of monsters as integers
    alive = []  # List to store the strengths of alive monsters
    res = []  # List to store the results for each monster
    for monster in monsters:  # Iterate over each monster's strength
        while len(alive) > 0 and monster >= alive[-1]:  # While there are alive monsters and the current monster's strength is greater than or equal to the strength of the last alive monster
            alive.pop()  # Remove the last alive monster
        alive.append(monster)  # Add the current monster to the list of alive monsters
        res.append(len(alive))  # Append the count of alive monsters to the result list
    print(*res)  # Print the result for the current test case
