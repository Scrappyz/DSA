#pragma once

#include <vector>

template<typename T>
void insertionSort(std::vector<T>& v, bool reverse = false)
{
    if(v.size() < 2) {
        return;
    }

    for(int i = 1; i < v.size(); i++) { // start at 2nd index
        int j = i; // iterator to compare elements
        int k = j-1; // iterator to compare the element before 'j'

        // iterate 'j' and 'k' backwards and swap until
        // the elements are in order
        if(reverse) {
            while(k >= 0 && v[k] < v[j]) {
                T temp = v[k];
                v[k] = v[j];
                v[j] = temp;
                j--;
                k--;
            }
        } else {
            while(k >= 0 && v[k] > v[j]) {
                T temp = v[k];
                v[k] = v[j];
                v[j] = temp;
                j--;
                k--;
            }
        }
    }
}