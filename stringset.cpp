/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
 */

#include "stringset.h"
#include <iostream>

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const{
    return size;
}

void Stringset::insert(string word){
    if(find(word))
        return;

    std::hash<std::string> hash;
    if(num_elems == size){
        size = 8;
        vector<list<string>> temp(size / 2);
        temp = table;
        table.clear();
        for(int i = 0; i < size; i++){
            table.push_back({});
        }

        for(int i = 0; i < size / 2; i++){
            for(int n = 0; n < temp[i].size(); n++){
                string tempS = temp[i].back();
                temp[i].pop_back();
                
                int insert_location = hash(tempS) % size;

                table[insert_location].push_back(tempS);
            }
        }
    }
    num_elems++;

    int insert_location = hash(word) % size;

    table[insert_location].push_back(word);
}

bool Stringset::find(string word) const{
    for(int i = 0; i < size; i++){
        list<string> l = table[i];
        for(int n = 0; n < table[i].size(); n++){
            if(l.back() == word)
                return true;
            l.pop_back();
        }
    }
    return false;
}

void Stringset::remove(string word){
    for(int i = 0; i < size; i++)
        table[i].remove(word);
    num_elems--;
}