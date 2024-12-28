# Unscramble

This is my first project on Github, so I chose something simple. This project takes a user input (a scrambled word) and unscrambles it, i.e. returns a list of possible words that the string could be. Initialization has a runtime of O(L + N), where L is the total number of characters in "words_alpha.txt" (the word list) and N is the length of the inputted string.

The algorithm I created works like so. If we assign a numerical value to each word, then the values of words with the same characters and quantity of characters should be equivalent. This is easily accomplished
using a polynomial of the format a1x^b1 + a2x^b2 + ... + anx^bn. The integer coefficients (a1, a2, ..., an) represent the quantity of a specific character, and the exponent gives the identity of the character (a, b, c, etc.). 

Another criteria must be that amx^bm = anx^bn is never true for any pair of terms with rational coefficients and exponents. Notice that this is only possible when x is an irrational number. For convenience, I chose e as the x value. For the exponents, I chose them to be nth roots (1 representing 'a', 1/26 representing 'z', etc.), because integer exponents created values that were either too big (e^26 for 'z' exceeded integer bounds) or too small (e^-26 for 'z' is worryingly small). Meanwhile, nth roots are always on the bounds (1,e], and the difference between nth roots until the 26th root is big enough that no meaningful data is being rounded off. So, the value is calculated by summing together each e^(1/(int)(char - '`')) term for each character in the string.

Using an unordered map of (double, array) pairs, words from the word list are pushed into arrays that contain all words with the same numerical value (are all scrambled versions of each other). When the user inputs a string, the numerical value is calculated using the algorithm in O(N) time (for loop through characters). Then, the array of all possible words is pulled from the unordered map in O(1) time, and each item is printed.

Citations:
The word file "words_alpha.txt" was obtained from dwyl's github repository which can be found at https://github.com/dwyl/english-words.
