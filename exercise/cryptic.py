# Consider a file words.txt that contains a text in ASCII format. Complete the following Python
# script allowing to read this file and print a dictionary containing the number of occurrences of
# each letter of the alphabet in the text. 
# Hint : the read method of file objects allow to read its content into one string object.

letters = "abcdefghijklmnopqrstuvwxyz"
dico = {
    "a": 3
}

file = open("cwords.txt", "r").read()
for letter in letters:
    dico[letter] = file.count(letter)

# ... your implementation below :
