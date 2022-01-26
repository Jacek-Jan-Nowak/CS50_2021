# 1. Opening the files.
# first row of CSV file has name as the first column, and then STRs for each of the remaining columns.
# each ramaining row corresponds to a person.

# csv module has reader and DictReader as sequence of lists of dictionaries.
# sys module gives access to sys.argv for command-line arguments.
# Once you've opened a text file f using open(filename), you can read its contents using f.read().

# 2. Computing STR Counts
# For each position in the sequence: compute how many times the STR repeats starting at that position.
# For each position, keep checking successive substrings until the STR repeats no longer.
# len(s) in Python will get you length of the string s.
# s[i:j] in Python takes the string s, and returns the substring with all characters from the ith character up to (but not including) the jth.

# 3.Comparing Against Data
# Save STR counts in some data structure.
# For each row in the data check if each STR count matches. If so, print out the person's name.

# once again
# Open the CSV file and DNA sequence, read contents into memory.
# For each STR, compute the longest run of consecutive repeats in the DNA sequence.
# Compare the STR counts against each row in the CSV file.

# HINTS
# int(x) takes the string x and turns it into an integer.
# To confirm a match, you'll need to check every column other than the first column.

import csv
import sys

from cs50 import get_float, get_int, get_string


if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)

with open(sys.argv[2], "r") as file:
    f = csv.reader(file)
    for row in f:
        sequence = row[0]

with open(sys.argv[1], "r") as file:
    data = csv.DictReader(file)
    strs = data.fieldnames
    people = []
    for row in data:
        people.append(row)


results = {}

strs.pop(0)
for ii in strs:
    count = 0
    current_max = 0
    for i in range(len(sequence)):
        if sequence[i:(i+len(ii))] == ii:
            count += 1
            if current_max <= count:
                current_max = count
            i += len(ii)
            if sequence[i:(i+len(ii))] != ii:
                count = 0
        results[ii] = str(current_max)
# print(results)
for person in people:
    name = person['name']
    # print(name)
    person2 = person
    del person2['name']
    # print(person2)
    if person2 == results:
        print(name)
        sys.exit(0)

print("No match")
