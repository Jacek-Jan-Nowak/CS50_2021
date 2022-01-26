from cs50 import get_float, get_int, get_string


def main():
    # Get input text from the user
    text = get_string("Text: ")

    # Total number of letters in the text
    letters = compute_letters(text)
    print(f"letter(s) {letters}")

    # Total number of words in the text
    words = compute_words(text)
    print(f"word(s) {words}")

    # Total number of sentences in the text
    sentences = compute_sentences(text)
    print(f"sentence(s) {sentences}")

    # Average number of letters per 100 words
    L = (letters * 100) / words
    # Average number of sentences per 100 words
    S = (sentences * 100) / words

    print(L)
    print(S)

    # Calculating grade using Coleman-Liau index
    index = int(round(0.0588 * L - 0.296 * S - 15.8))
    # printf("%i grade\n", index );

    # Final Grade
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


def compute_letters(text):
    letters = 0
    for i in text:
        if i.isalpha():
            letters += 1
    return letters


def compute_words(text):
    words = 1
    for i in text:
        if i.isspace():
            words += 1
    return words


def compute_sentences(text):
    sentences = 0
    for i in text:
        if (i == "!" or i == "." or i == "?"):
            sentences += 1
    return sentences


main()
