from cs50 import get_float, get_int, get_string


# Prompt for Credit card number
def get_positive_int():
    while True:
        n = get_int("Number: ")
        if n > 0:
            break
    return n


cc_num = get_positive_int()


# Backups for checking checksum and length
cc_num_check = cc_num
cc_num_length = cc_num
cc_num_pref = cc_num

# Calculating Checksum

sum = 0
i = 1
second_dig = 0
while cc_num_check > 0:
    if i % 2 == 0:
        second_dig = int(2 * (cc_num_check % 10))
        if second_dig < 10:
            sum += second_dig
        else:
            sum += int(second_dig / 10) + int(second_dig % 10)
    else:
        sum += int(cc_num_check % 10)
    cc_num_check = int(cc_num_check / 10)
    i += 1

# Calculating length of the number

if sum % 10 == 0:
    length = 0
    while cc_num_length > 0:
        cc_num_length = int(cc_num_length / 10)
        length += 1

    # Checking preffix of the card

    if length == 13:
        cc_num_pref = int(cc_num / 1e12)
    elif length == 16:
        if cc_num > 5e15:
            cc_num_pref = int(cc_num / 1e14)
        else:
            cc_num_pref = int(cc_num / 1e15)
    elif length == 15:
        cc_num_pref = int(cc_num / 1e13)

    # Checking brand of the card

    if length == 15 and (cc_num_pref == 34 or cc_num_pref == 37):
        print("AMEX")
    elif length == 16 and (cc_num_pref >= 51 and cc_num_pref <= 55):
        print("MASTERCARD")
    elif (length == 13 and cc_num_pref == 4) or (length == 16 and cc_num_pref == 4):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
# how many comment I really need here?!
