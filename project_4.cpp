#include <iostream>
#include <cassert>
#include <fstream>
#include <algorithm>
#include "p_4_header.hpp"

// Function to calculate the length of a C-string (char array)
std::size_t length(char const *a) {
    unsigned int counter{}; // Counter for the string length
    while (a[counter] != '\0') { // Loop until end of string
        ++counter;
    }
    return counter; // Return the length of the string
}

// Function to compare two C-strings lexicographically
int compare(char const *str1, char const *str2) {
    while ((*str1 != '\0') && (*str2 != '\0')) { // Loop until end of both strings
        if(*str1 < *str2) {
            return -1; // str1 is lexicographically smaller than str2
        }
        if(*str1 > *str2) {
            return 1; // str1 is lexicographically greater than str2
        }
        str1++; // Move to the next character in both strings
        str2++;
    }

    // If we reached the end of one string but not the other
    if ((*str1 == '\0') && (*str2 != '\0')) {
        return -1; // str1 is smaller than str2
    } 
    if ((*str1 != '\0') && (*str2 == '\0')) {
        return 1; // str1 is greater than str2
    }
    return 0; // Both strings are equal
}

// Function to copy one C-string into another
void assign(char *str1, char const *str2) {
    int i{}; 
    while (str2[i] != '\0') { // Loop until end of str2
        str1[i] = str2[i]; // Copy each character from str2 to str1
        i++;
    }
    str1[i] = '\0'; // Null-terminate str1
}

// Recursive function to calculate the Levenshtein distance between two strings
unsigned int distance(char const *str1, char const *str2) {
    if ((*str1 == '\0') && (*str2 == '\0')) {
        return 0; // If both strings are empty, distance is 0
    }
    if (*str1 == '\0') {
        return 1 + distance(str1, str2 + 1); // If str1 is empty, add 1 for each extra character in str2
    }
    if (*str2 == '\0') {
        return 1 + distance(str1 + 1, str2); // If str2 is empty, add 1 for each extra character in str1
    }
    if (*str1 == *str2) {
        return distance(str1 + 1, str2 + 1); // If characters match, move to the next pair of characters
    }

    // Calculate insert, remove, and replace distances
    int insert = 1 + distance(str1, str2 + 1);
    int remove = 1 + distance(str1 + 1, str2);
    int replace = 1 + distance(str1 + 1, str2 + 1);

    return std::min({insert, remove, replace}); // Return the minimum of the three
}

// Function to check if an array of strings is sorted lexicographically
std::size_t is_sorted(char *array[], std::size_t capacity) {
    for (unsigned int i{1}; i < capacity; ++i) {
        int result = compare(array[i-1], array[i]);
        if (result > 0) {
            return i; // Return index where the sorting fails
        }
    }
    return capacity; // Return capacity if the array is sorted
}

// Function to insert a value into the array maintaining sorted order
void insert(char *array[], std::size_t capacity) {
    char *value = new char[length(array[capacity - 1]) + 1]; // Create new string for the value to insert
    assign(value, array[capacity - 1]); // Assign value to the new string

    int position{capacity - 2}; // Start from the last element
    while ((position >= 0) && (compare(array[position], value) > 0)) { 
        array[position + 1] = array[position]; // Move elements to the right to make space
        --position;
    }

    array[position + 1] = value; // Insert the value at the correct position
}

// Function to perform insertion sort on an array of strings
void insertion_sort(char *array[], std::size_t capacity) {
    for (std::size_t k{1}; k < capacity; ++k) {
        insert(array, (k + 1)); // Insert each element into its correct position
    }
}

// Function to remove duplicate strings from a sorted array
std::size_t remove_duplicates(char *array[], std::size_t capacity) {
    if (capacity <= 1) {
        return capacity; // If there is one or no elements, return the capacity
    }

    std::size_t unique_count{1}; // Start with the first element as unique
    for (std::size_t i{1}; i < capacity; ++i) {
        if ((compare(array[i], array[i - 1])) != 0) { // If current element is different from the previous one
            array[unique_count] = array[i]; // Move it to the unique position
            ++unique_count; // Increment unique count
        }
    }
    return unique_count; // Return the count of unique elements
}

// Function to find the closest matching string to a target string in an array
std::size_t find(char *array[], std::size_t capacity, char const *str) {
    std::size_t closest_index{}; 
    int min_distance_value{-1};

    for (std::size_t i{}; i < capacity; ++i) {
        if ((compare(array[i], str)) == 0) {
            return i; // Return the index if exact match is found
        }

        int current_distance{distance(array[i], str)}; // Calculate the distance to the target string
        if ((min_distance_value == -1) || (current_distance < min_distance_value)) {
            closest_index = i; // Track the closest match
            min_distance_value = current_distance; // Update the minimum distance
        }
    }
    return closest_index; // Return the index of the closest match
}

// // Function to read words from a file into an array
// void read_words_from_file(const char* filename, char** &word_array, std::size_t &num_words, std::size_t width) {
//     std::ifstream file(filename);
//     if (!file) {
//         std::cout << "[ERROR] Could not open file " << filename << std::endl;
//         return;
//     }

//     file >> num_words; // Read the number of words
//     file.ignore(); // Ignore the newline character

//     word_array = new char*[num_words]; // Allocate memory for the array of word pointers
//     word_array[0] = new char[num_words * (width + 1)]; // Allocate memory for the first word (with width + 1 for null terminator)

//     for (std::size_t k{1}; k < num_words; ++k) {
//         word_array[k] = (word_array[k - 1] + (width + 1)); // Set up each subsequent word pointer
//     }

//     for (std::size_t k{}; k < num_words; ++k) {
//         file >> word_array[k]; // Read each word from the file into the array
//     }
//     file.close(); // Close the file
// }

// Function to free the memory allocated for the word array
void free_word_array(char** word_array) {
    if (word_array != nullptr) {
        // First delete each string (if any)
        for (std::size_t i{}; word_array[i] != nullptr; ++i) {
            delete[] word_array[i];
        }
        // Then delete the array holding the pointers to the strings
        delete[] word_array;
    }
}
