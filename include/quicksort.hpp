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
T medianOfThree(const std::vector<T>& v)
{
    std::vector<T> medians;
    medians.push_back(v[0]);
    medians.push_back(v[v.size() / 2]);
    medians.push_back(v[v.size()-1]);

    if(medians[1] < medians[0]) swap(medians[1], medians[0]);
    if(medians[2] < medians[1]) swap(medians[2], medians[1]);
    if(medians[1] < medians[0]) swap(medians[1], medians[0]);

    return medians[1];
}

template<typename T>
void quicksort(std::vector<T>& v)
{
    if(v.size() < 2) {
        return;
    }

    if(v.size() == 2) {
        if(v[1] < v[0]) swap(v[1], v[0]);
        return;
    }

    T pivot = medianOfThree(v);

    std::vector<T> left;
    std::vector<T> right;

    for(const auto& i : v) {
        if(i < pivot) {
            left.push_back(i);
        } else if(i > pivot) {
            right.push_back(i);
        }
    }

    quicksort(left);
    quicksort(right);

    v = left;
    v.push_back(pivot);
    v.insert(v.end(), right.begin(), right.end());
}