from cs50 import get_float, get_int, get_string

# Prompt user for height of the pyramid
h = 0

while True:
    if h > 0 and h < 9:
        # how that damn range is working?!
        for i in range(1, h + 1):
            for j in range(h - i, 0, -1):
                print(" ", end="")
            for j in range(i):
                print("#", end="")
            print("  ", end="")
            for j in range(i):
                print("#", end="")
            print("")
        break
    else:
        h = get_int("height: ")


# while True:
#     if h > 0 and h < 9:
#         # how that damn range is working?!
#         for i in range(0, h):
#             for j in range(i - h + 1, 0):
#                 print(" ", end="")
#             print((i + 1) * "#")
#         break
#     else:
#         h = get_int("height: ")

