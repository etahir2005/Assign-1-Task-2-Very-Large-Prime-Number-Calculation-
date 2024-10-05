**Overview**
This is a C++ implementation that uses a linked list to create a 1024-bit number and use Miller-Rabin Primality Test to determine the primality of that number. It shows how to handle large integers divided into 64 bits and implements a probabilistic primality test.

**Approach:**
Data Representation: The large number is divided into 64-bit segments, each wrapped in a node of the singly linked list data structure. This will mimic a 1024-bit number.
To handle this representation, the LargeNumber class has employed the use of a linked list where each node holds a 64-bit integer.
Modular Arithmetic: Large numbers are handled through implementation of functions for modular multiplication and modular exponentiation.
These functions aid in performing modular computations that are essential for the Miller-Rabin Primality Test in a more structured manner.
Primality Testing: The Miller-Rabin Test is a specific test that can determine the primality of a number, although its basis works probabilistically. It is performed a number of times (k iterations) to enhance the estimation precision.
When testing for primality, the isPrime() function employs a stand-in large number. A number is declared prime if it passes the test in all iterations.

**Assumptions:**
It should be noted that at the moment the number being tested for primality is represented by a 64-bit placeholder integer 1234567890123456789ULL rather than by the full 1024-bit number. Thus, in real-world usage, the entire of the 1024-bit number would be required to be processed.
For the Miller-Rabin test there is only a fixed base a=2 instead of a random base, which would make it easier to implement.
These numbers are hardcoded as the series of 64-bit numbers to demonstrate the approach on a large number.

**Challenges Faced:**
Handling Large Numbers: As mentioned earlier, to manage 1024-bit numbers for representation and performing arithmetic operations, the number had to be divided into 64-bit segments.
Modular Arithmetic: The design and implementation of these efficient algorithms for modular multiplication and exponentiation played the vital role for large number computations.
Miller-Rabin Test Complexity: Due to the large size of the numbers, it was necessary to consider them probabilistically, which involved understanding the Miller-Rabin test and its application; all these steps necessitated knowledge of number theory principles.

**Screenshot of Output:**
![Screenshot (901)](https://github.com/user-attachments/assets/f744e2aa-33f7-496c-9765-423b4d90edc8)
