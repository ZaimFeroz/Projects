#include <iostream>
double* geometric(double a, double ratio, std::size_t cap) {
    // Allocate memory even if cap is zero to return a valid pointer
    double* p_array = new double[cap];

    // Only fill the array if cap is greater than zero
    if (cap > 0) {
        p_array[0] = a; // Set the first term of the array
        for (std::size_t i = 1; i < cap; i++) {
            p_array[i] = p_array[i - 1] * ratio; // Calculate each term by multiplying the previous term by the ratio
        }
    }

    return p_array;
}


double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1) {
    
    std::size_t total_cap = cap0 + cap1 - 1; // Capacity of the new array
    
    double *p_total_array = new double[total_cap]; // Dynamically allocate the total array
    for(std::size_t x{}; x < total_cap; x++) { // initialize all terms to 0
        p_total_array[x] = 0.0;
    }
    for(std::size_t i{}; i < cap0; ++i) {
        for(std::size_t j{}; j < cap1; ++j) {
            p_total_array[i + j] += array0[i] * array1[j];
        }
    }
    return p_total_array;
}


std::size_t shift_duplicates(int array[], std::size_t capacity) {
    int unique_counter{};  // Counter for unique elements
    int copy[capacity];  // Temporary array to store duplicates
    int copy_counter{};  // Counter for duplicates

    // Step 1: Find unique elements and store them at the beginning of the array
    for (std::size_t i{}; i < capacity; i++) {
        bool is_duplicate = false;

        // Check if array[i] is a duplicate of any earlier unique element
        for (int j{}; j < unique_counter; j++) {
            if (array[i] == array[j]) {
                is_duplicate = true;  // It's a duplicate
                break;
            }
        }

        // If it's unique, add it to the "unique" section of the array
        if (!is_duplicate) {
            array[unique_counter++] = array[i];
        } else {
            // If it's a duplicate, add it to the duplicates array
            copy[copy_counter++] = array[i];
        }
    }

    // Step 2: Append duplicates at the end of the array
    for (std::size_t i{}; i < copy_counter; i++) {
        array[unique_counter + i] = copy[i];
    }

    return unique_counter;  // Return the count of unique elements
}


void deallocate(double *&ptr, bool is_array, std::size_t capacity = 0) {
    if (is_array) {
        for (std::size_t i{}; i < capacity; i++) {
            ptr[i] = 0.0;  // Set each element in the array to 0.0
        }
        delete[] ptr;       // Use delete[] for array deallocation
    } else {
        *ptr = 0.0;         // Set the single double value to 0.0
        delete ptr;         // Use delete for single double deallocation
    }
    ptr = nullptr;          // Set ptr to nullptr
}




int main() {
    // Input for geometric function
    double a, ratio;
    std::size_t cap;
    std::cout << "Enter the first term for the geometric series: ";
    std::cin >> a;
    std::cout << "Enter the common ratio for the geometric series: ";
    std::cin >> ratio;
    std::cout << "Enter the number of terms in the geometric series: ";
    std::cin >> cap;

    double *test1 = geometric(a, ratio, cap);
    std::cout << "Geometric series: ";
    for (std::size_t i{}; i < cap; i++) {
        std::cout << test1[i] << " ";
    }
    std::cout << std::endl;

    // Input for cross_correlation function
    std::size_t cap0, cap1;
    std::cout << "Enter the size of the first array for cross-correlation: ";
    std::cin >> cap0;
    double *array0 = new double[cap0];
    std::cout << "Enter elements for the first array: ";
    for (std::size_t i{}; i < cap0; i++) {
        std::cin >> array0[i];
    }

    std::cout << "Enter the size of the second array for cross-correlation: ";
    std::cin >> cap1;
    double *array1 = new double[cap1];
    std::cout << "Enter elements for the second array: ";
    for (std::size_t i{}; i < cap1; i++) {
        std::cin >> array1[i];
    }

    double *test2 = cross_correlation(array0, cap0, array1, cap1);
    std::cout << "Cross-correlation: ";
    for (std::size_t i{}; i < (cap0 + cap1 - 1); i++) { 
        std::cout << test2[i] << " ";
    }
    std::cout << std::endl;

    // Input for shift_duplicates function
    std::size_t capacity;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> capacity;

    int *array = new int[capacity];
    std::cout << "Enter " << capacity << " elements:" << std::endl;
    for (std::size_t i{}; i < capacity; i++) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> array[i];
    }

    std::cout << "Original array: ";
    for (std::size_t i{}; i < capacity; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    // Call the function that moves duplicates to the end
    std::size_t num_unique = shift_duplicates(array, capacity);

    std::cout << "Array after moving duplicates to the end: ";
    for (std::size_t i{}; i < capacity; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Number of unique elements: " << num_unique << std::endl;

    // Deallocate dynamic arrays
    delete[] test1;
    delete[] test2;
    delete[] array0;
    delete[] array1;
    delete[] array;

    return 0;
}
