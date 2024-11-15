#include <iostream>
#include <cassert>

void pattern(unsigned int n) { // Function #1

    for (unsigned int i = 0; i <= n; ++i) { // Top part of the pyramid (including middle row) (n = positive value inputted by user, i = row number)
        for (unsigned int j = 0; j < i; ++j) { // Print Spaces (j = number of spaces per line before asterisks)
            std::cout << " ";
        }
        for (unsigned int k = 0; k < (2 * (n - i) + 1); ++k) { // Print Asterisks (k = number of asterisks per line)
            std::cout << "*";
    }
    std::cout << std::endl;
    }
    for (unsigned int i = 1; i <= n; ++i) { // Bottom part of the pyramid (excluding middle row) (n = positive value inputted by user, i = row number)
        for (unsigned int j = 0; j < n - i; ++j) { // Print Spaces (j = number of spaces per line before asterisks)
            std::cout << " ";
        }
        for (unsigned int k = 0; k < (2 * i + 1); ++k) { // Print Asterisks (k = number of asterisks per line)
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
unsigned int log10(unsigned int n) { // Function #2
    assert(n != 0); // Makes sure n != 0 because for log10(n), n > 0
    unsigned int m{}; // m Starts at 0. m is the exponent value
   
    while (n >= 10) { // Find the largest exponent m such that 10^m <= n. n must be >= 10 so the loop runs
        n /= 10; // Divide n by 10, then use that n value and re-run the loop
        ++m; // Will act as a counter to see how many remainders are shifted out
    }
    return m; // The value of m will be the exponent value
}
unsigned int count(unsigned int n, unsigned int bit) { // Function #3
    assert(bit == 0 || bit == 1); // Makes sure but is only either 1 or 0
    unsigned int count = 0; // Store the number of times the bit appears in n

     // Go through all 32 bits of the number
    for (unsigned int i = 0; i < 32; ++i) {
        if (((n >> i) & 1) == bit) { // Check each bit
            ++count; // Increment if it matches the bit we're counting
        }
    }
    return count; // returns the amount of 0 or 1 bits in the number
}
unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1) { // Function #4
    assert(b0 >= 0 && b0 <= 3); // Byte has to be within a haxadecimal value
    assert(b1 >= 0 && b1 <= 3); // Byte has to be within a haxadecimal value

    if (b0 == b1) return n; // If the bytes are equal, then don't change anything

    unsigned int byte1 = (n >> (b0 * 8)) & 0xFF; // Shift the required byte all the way to the right and saves (masks) everything else
    unsigned int byte2 = (n >> (b1 * 8)) & 0xFF; // Shift the required byte all the way to the right and saves (masks) everything else

    n &= ~(0xFF << (b0 * 8)); // Creates a mask where only the byte at position b0 is set to 1 (~ (invert) makes everything else 1 except b0)
    n &= ~(0xFF << (b1 * 8)); // Creates a mask where only the byte at position b1 is set to 1 (~ (invert) makes everything else 1 except b1)

    n |= (byte1 << (b1 * 8)); // Moves byte1 to b1
    n |= (byte2 << (b0 * 8)); // Moves byte2 to b0
    return n;
}


int main() {
   unsigned int n{};
   std::cout << "Enter a value for pattern (0-5): ";
   std::cin >> n;

   if (n <= 5) {
        pattern(n);  // Call pattern function with user input
    } else {
        std::cout << "Invalid input for pattern." << std::endl;
    }

    // Testing the log10 function
    std::cout << "Enter a number to calculate log10: ";
    std::cin >> n;
    
    assert(n != 0);  // Ensure the number is non-zero
    std::cout << "The log10 of " << n << " is " << log10(n) << std::endl;

    // Testing the count function
    unsigned int bit;
    std::cout << "Enter a number to count bits in: ";
    std::cin >> n;
    std::cout << "Enter the bit (0 or 1) to count: ";
    std::cin >> bit;
    
    assert(bit == 0 || bit == 1);  // Ensure the bit is 0 or 1
    std::cout << "The bit " << bit << " appears " << count(n, bit) << " times in " << n << std::endl;

    // Testing the swap_bytes function
    unsigned int b0, b1;
    std::cout << "Enter a number for byte swapping: ";
    std::cin >> n;
    std::cout << "Enter two byte positions to swap (0-3): ";
    std::cin >> b0 >> b1;
    
    assert(b0 >= 0 && b0 <= 3);  // Ensure byte positions are valid
    assert(b1 >= 0 && b1 <= 3);
    std::cout << "After swapping bytes, the result is: " << std::dec << swap_bytes(n, b0, b1) << std::endl;
    return 0;
}
 // for (unsigned int n = 0; n <= 5; ++n) { // Function for asterisks (goes from n = 0 to n = 5)
    //     std::cout << "n = " << n << ":" << std::endl; // Displays the pattern for each n value
    //     pattern(n); // The pattern with respect to n will be displayed
    //     std::cout << std::endl; // Space between each pattern
    // } 