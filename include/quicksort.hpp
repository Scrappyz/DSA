#pragma once

#include <vector>

template<typename T>
void swap(T& a, T& b) 
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T medianOfThree(std::vector<T>& v, int low, int high) 
{
    int middle = (low + high) / 2;

    // Sort the low, middle, high
    if(v[low] > v[middle]) swap(v[low], v[middle]);
    if(v[middle] > v[high]) swap(v[middle], v[high]);
    if(v[low] > v[middle]) swap(v[low], v[middle]);

    // Swap middle element with the next to last element so the pivot is at v[high-1]
    swap(v[middle], v[high-1]);

    // Return the pivot
    return v[high-1];
}

template<typename T>
void quicksort(std::vector<T>& v, int low, int high)
{
    int size = high - low + 1;

    if(size < 2) return;

    T pivot = medianOfThree(v, low, high);

    int i = low;
    int j = high - 1;
    while(true) {
        // Move 'i' pointer to the right until it finds an element greater or equal to the pivot
        while(v[i] < pivot) i++;

        // Move 'j' pointer to the left until it finds an element lesser than the pivot
        while(v[j] >= pivot) j--;

        // if 'i' and 'j' pointers cross, stop the loop
        if(i > j) break;

        // Otherwise, swap 'i' element and 'j' element
        swap(v[i], v[j]);
    }

    // Swap 'i' element with the pivot (pivot being v[high-1])
    swap(v[i], v[high-1]);
    // Pivot is now at v[i]

    // Sort the left subarray (all elements left of the pivot index)
    quicksort(v, low, i-1);

    // Sort the right subarray (all elements right of the pivot index)
    quicksort(v, i+1, high);
}

template<typename T>
void quicksort(std::vector<T>& v)
{
    quicksort(v, 0, v.size()-1);
}