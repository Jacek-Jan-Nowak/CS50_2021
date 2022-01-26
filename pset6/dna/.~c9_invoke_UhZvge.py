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
# int(x) taqkes the string x and turns it into an integer.
# To confirm a match, you'll need to check every column other than the first column.

