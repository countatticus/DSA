n = int(input("Enter an odd number: "))

for i in range(n):
    for j in range(n):
        if (j - i) == n//2 or (i - j) == n//2 or (i + j) == n//2 or (i+j) == n + ((n//2)-1):
           print("*", end = "")
        else:
           print(" ", end = "")
        
    print()