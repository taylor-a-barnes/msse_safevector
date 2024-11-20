#include <iostream>
#include <limits>
#include <list>
#include <stdexcept>
#include <vector>

int main() {
  // Initialize vectors that will be used for tests
  // Note: You must change the "std::vector" to a custom vector class that you have defined.
  std::vector<int> int_vec;
  const std::vector<double> double_vec = {1.1, 2.2, 3.3, 4.4};
  std::vector<std::list<int>> list_vec;

  /* -------------------------------------
     DO NOT EDIT ANYTHING PAST THIS POINT!
     ------------------------------------- */

  // Initialize the vector of integers
  if ( int_vec.empty() ) {
    for (int i = 0; i < 100; i++) {
      int_vec.push_back(i+1);
    }
  }

  // Print some elements from the vector of integers
  std::cout << "int_vec" << std::endl;
  std::cout << "  Second element of int_vec: " << int_vec[1] << std::endl;
  std::cout << "  Last element of int_vec: " << int_vec.back() << std::endl;
  try {
    // If these lines print, your vector is NOT memory-safe
    std::cout << "  Attempting to access int_vec out-of-bounds: " << int_vec[int_vec.size()] << std::endl;
    std::cout << "  Oh no! The vector was accessed out-of-bounds!" << std::endl;
  }
  catch (const std::out_of_range& e) {
    // If your vector is memory-safe, this error message should print
    std::cerr << "  Error: " << e.what() << std::endl << std::endl;
  }

  // Print some elements from the vector of doubles
  std::cout << "double_vec" << std::endl;
  std::cout << "  Second element of double_vec: " << double_vec[1] << std::endl;
  std::cout << "  Last element of double_vec: " << double_vec.back() << std::endl;
  try {
    // If these lines print, your vector is NOT memory-safe
    std::cout << "  Attempting to access double_vec out-of-bounds: " << double_vec[-1] << std::endl;
    std::cout << "  Oh no! The vector was accessed out-of-bounds!" << std::endl << std::endl;
  }
  catch (const std::out_of_range& e) {
    // If your vector is memory-safe, this error message should print
    std::cerr << "  Error: " << e.what() << std::endl << std::endl;
  }

  // Initialize the vector of lists
  for ( int i = 0; i < 100; i++ ) {
    std::list<int> new_list;
    for (int j = 0; j < 10; j++ ) {
      new_list.push_front((i+1)*(j+1));
    }

    // Store a pointer to the first element of the newest list
    int* original_int_ptr = &(*new_list.begin());

    // Add the list to the vector using move semantics
    list_vec.push_back(move(new_list));

    // Get a pointer to the first element of the list in the vector
    int* final_int_ptr = &(*list_vec.back().begin());

    // If the move was correct, the two pointers should be the same
    if ( final_int_ptr != original_int_ptr ) {
      std::cout << "Oh no! Your vector does not properly support move semantics!" << std::endl;
    }
  }

  // Print some elements from the vector of lists
  std::cout << "list_vec" << std::endl;
  std::cout << "  Second element of list_vec: " << std::endl;
  for (std::list<int>::iterator it = list_vec[1].begin();
       it != list_vec[1].end();
       ++it){
    std::cout << "    " << *it << std::endl;
  }
  std::cout << "  Last element of list_vec: " << std::endl;
  for (std::list<int>::iterator it = list_vec.back().begin();
       it != list_vec.back().end();
       ++it){
    std::cout << "    " << *it << std::endl;
  }
  try {
    // If these lines print, your vector is NOT memory-safe
    std::cout << "  Attempting to access double_vec out-of-bounds: " << double_vec[-1] << std::endl;
    std::cout << "  Oh no! The vector was accessed out-of-bounds!" << std::endl << std::endl;
  }
  catch (const std::out_of_range& e) {
    // If your vector is memory-safe, this error message should print
    std::cerr << "  Error: " << e.what() << std::endl << std::endl;
  }

  return 0;
}
