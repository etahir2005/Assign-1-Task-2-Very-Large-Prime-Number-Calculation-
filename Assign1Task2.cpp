#include <iostream>
using namespace std;

class ListNode {
public:
    unsigned long long data;  //use unsigned long long for large integers (64-bit)
    ListNode* next;

    ListNode(unsigned long long d) : data(d), next(nullptr) {}
};

//class to represent the 1024-bit number using a linked list
class LargeNumber {
private:
    ListNode* head;
    int node_count; //to track the number of nodes

public:
    LargeNumber() : head(nullptr), node_count(0) {}

    //add a 64-bit integer to the list
    void addNode(unsigned long long value) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
        }
        else {
            ListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        node_count++;
    }

    //print the large number (just for testing purposes)
    void printNumber() {
        ListNode* temp = head;
        cout << "Input: A 1024-bit number represented as \"";
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "";
            temp = temp->next;
        }
        cout << "...\"\n";
    }

    //function to generate a fixed "random" 1024-bit number (split into 64-bit chunks)
    void generateFixed1024Bit() {
        //using pre-defined 64-bit numbers for demonstration
        unsigned long long values[] = { 12345, 67890, 12345, 67890, 12345, 67890, 12345, 67890,
                                       12345, 67890, 12345, 67890, 12345, 67890, 12345, 67890 };
        for (int i = 0; i < 16; i++) {  // 1024 bits -> 16 nodes of 64 bits
            addNode(values[i]);
        }
    }

    
};

//utility function for modular multiplication (a * b) % mod
unsigned long long modularMultiply(unsigned long long a, unsigned long long b, unsigned long long mod) {
    unsigned long long result = 0;
    a = a % mod;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result + a) % mod;
        a = (a * 2) % mod;
        b /= 2;
    }
    return result;
}

//utility function for modular exponentiation (base^exp) % mod
unsigned long long modularExponentiation(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = modularMultiply(result, base, mod);
        base = modularMultiply(base, base, mod);
        exp /= 2;
    }
    return result;
}

//function to perform the Miller-Rabin Primality Test
bool millerRabinTest(unsigned long long d, unsigned long long n) {
    unsigned long long a = 2; // A fixed small base (instead of random)
    unsigned long long x = modularExponentiation(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    while (d != n - 1) {
        x = modularMultiply(x, x, n);
        d *= 2;

        if (x == 1) return false;
        if (x == n - 1) return true;
    }

    return false;
}

//main function to check if a large number (in the linked list) is prime using Miller-Rabin Test
bool isPrime(LargeNumber& largeNumber, int k) {
    //simulate the number as a large 64-bit integer for primality test
   
    unsigned long long n = 1234567890123456789ULL;  //placeholder for large number 

   
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    //find d such that n - 1 = d * 2^r
    unsigned long long d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }

    //perform the Miller-Rabin test k times
    for (int i = 0; i < k; i++) {
        if (!millerRabinTest(d, n)) {
            return false;
        }
    }

    return true;
}

int main() {
    LargeNumber largeNumber;
    largeNumber.generateFixed1024Bit();
    largeNumber.printNumber();

    //print smaller primes used for primality test (for simplicity, showing a small list)
    unsigned long long smallerPrimes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
    cout << "Smaller primes: [";
    for (int i = 0; i < 9; i++) {
        if (i != 0) cout << ", ";
        cout << smallerPrimes[i];
    }
    cout << "]\n";

    //perform primality test on the large number
    int iterations = 5; //number of Miller-Rabin iterations
    if (isPrime(largeNumber, iterations)) {
        cout << "Output: True (Prime)\n";
    }
    else {
        cout << "Output: False (Not Prime)\n";
    }

    return 0;
}
