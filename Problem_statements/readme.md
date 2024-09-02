# SubString Quest

## Problem Description

Raju and Rani like playing with strings, exploring the interesting patterns of smaller parts within them, called substrings.
Presently, they are engrossed in a string-centric game and it is Raju's turn. His task involves two strings provided by Rani, namely **S1** and **S2**. 

Raju is tasked with dividing the first string **S1** into the fewest possible substrings, ensuring that all resulting substrings, whether in their original or reversed order, are present in **S2** while also aiming for maximizing the length of the current substring.

For example, if **S1** = "vanaja" and **S2** = "rvanpnaja", then the output will be `van|aja` rather than `va|naja`.

### Note

- The letter in the *i*th position in **S1** can be used in exactly one substring of **S1**.
- The letters from **S2** can be reused any number of times, but the letters from **S1** can be used only once.
- The letters are case sensitive in both the strings.
