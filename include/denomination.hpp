#pragma once

#include <iostream>
#include <vector>

double precision(double n, int decimal_places)
{
    if(decimal_places < 0) {
        return n;
    }
    
    int mult = 1;
    for(int i = 0; i < decimal_places; i++) {
        mult *= 10;
    }

    return static_cast<double>(static_cast<int>(n * mult)) / mult;
}

std::vector<int> convertToInt(const std::vector<double>& v, int mult)
{
    std::vector<int> convert;
    for(int i = 0; i < v.size(); i++) {
        convert.push_back(static_cast<int>(v[i] * mult));
    }
    return convert;
}

std::vector<std::pair<double, int>> getChange(double total, double cost)
{
    int mult = 100;
    std::vector<int> denominations = convertToInt({1000, 500, 200, 100, 50, 20, 10, 5, 1, .25, .05, .01}, mult);
    int change = (total - cost) * mult;
    std::vector<std::pair<double, int>> changes;

    int i = 0;
    while(i < denominations.size()) {
        int temp = denominations[i]; 
        if(change >= temp) {
            if(!changes.empty() && static_cast<int>(changes.back().first * mult) == temp) {
                changes.back().second++;
            } else {
                changes.push_back({static_cast<double>(temp) / mult, 1});
            }
            change -= temp;
            continue;
        }
        i++;
    }

    return changes;
} 

void printChange(const std::vector<std::pair<double, int>>& changes)
{
    for(int i = 0; i < changes.size(); i++) {
        std::cout << changes[i].second << "x PHP" << changes[i].first << std::endl; 
    }
}