#!/usr/bin/python3
largest_palindrome = 0

for i in range(999, 99, -1):
    for j in range(i, 99, -1):
        product = i * j
        product_str = str(product)
        if product_str == product_str[::-1] and product > largest_palindrome:
            largest_palindrome = product

# Save the result in the file
with open('102-result', 'w') as file:
    file.write(str(largest_palindrome))

