from cs50 import get_float, get_int, get_string

# Prompt for change owed


def get_positive_float():
    while True:
        n = get_float("Change owed: ")
        if n > 0:
            break
    return n


change = get_positive_float()
cents = round(change * 100)
coins = 0

# quarters
while cents >= 25:
    cents -= 25
    coins += 1

# dimes
while cents >= 10:
    cents -= 10
    coins += 1

# nickels
while cents >= 5:
    cents -= 5
    coins += 1

# pennies
while cents >= 1:
    cents -= 1
    coins += 1


# Print amount of coins
print(coins)