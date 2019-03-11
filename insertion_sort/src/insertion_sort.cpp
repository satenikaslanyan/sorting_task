#include <sstream>  
#include "insertion_sort.hpp"
#include <assert.h>

int main()
{
    int n = get_int(1);
    int* arr = new int [n];
    assert(arr);
    for (int i=0; i < n; ++i) { 
        arr[i] = get_int(2);                                     
    } 
    std::cout << "\nGiven array is : ";
    print_array(arr, n);
    insertion_sort(arr, n, 1);
    std::cout << "\nSorted array in ascending order: ";
    print_array(arr, n);
    insertion_sort(arr, n, 2);
    std::cout << "\nSorted array in descending order: ";
    print_array(arr, n);
    std::cout << std::endl;
    delete [] arr;
}

void is_number(std::string& s, bool& fl, int i)
{
     for (; i < s.size(); ++i) {
         if(s[i] < '0' || s[i] > '9') {
             std::cout << "Error, invalid input" << std::endl;
             fl = true;
             break;
         }
     }
}

//This function is for checking input
void check_input(std::string& s, bool& fl, const int& a)
{
    if (s.size() == 0) {
        std::cout << "Error, invalid input" << std::endl;
        fl = true;
    } else {
        if (1 == a) {
            if (s == "0") {
                std::cout << "Error, invalid input" << std::endl;
                fl = true;
            } else {
                is_number(s, fl, 0);
            }
        } else if (2 == a) {
            if (s[0] == '-' || s[0] < '0' || s[0] > '9') {
                if (s[0] == '-' && s.size() == 1) {
                    std::cout << "Error, invalid input" << std::endl;
                    fl = true;
                } else {
                    is_number(s, fl, 1);
                }
            }
        }
    }
}

//This function is for input
int get_int(const int& a) 
{
    bool fl = false;
    int result = 0;
    std::string s("");
    do {
        if (1 == a) {
            std::cout << "\nWhat size of array do you want? ";
        } else if (2 == a) {
            std::cout << "Input element ";
        } 
        getline(std::cin, s);
        fl = false;
        check_input(s, fl, a);
    } while(fl);
    std::stringstream str_int(s);
    str_int >> result;
    return result;
}


// Function to sort an array using insertion sort
// k parameter is the order that the array will be sorted (descending or ascending)
void insertion_sort(int arr[], int& n, const int& k) 
{ 
   int elem = 0; 
   int j = 0;
   for (int i = 1; i < n; ++i) { 
       elem = arr[i]; 
       j = i-1; 
       /* Move elements of arr[0..i-1], that are 
          greater than elem, to one position ahead 
          of their current position */
       if (1 == k) {
           while (0 <= j && arr[j] >= elem) { 
               arr[j+1] = arr[j]; 
               j = j-1; 
           } 
           arr[j+1] = elem;
       } else if (2 == k) {
           while (0 <= j && arr[j] <= elem) {
               arr[j+1] = arr[j];
               j = j-1;
           }
           arr[j+1] = elem; 
       }
   } 
} 
  
// A utility function to print an array of size n 
void print_array(int arr[], const int& n) 
{ 
   for (int i=0; i < n; ++i) { 
       std::cout << arr[i] << " "; 
   }
   std::cout << std::endl;
} 
