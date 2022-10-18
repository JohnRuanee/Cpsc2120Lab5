/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
 */

#include "stringset.h"
 #include <iostream>
 #include <fstream>
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

    hash<string> hash;
    if(num_elems == size){
        size = size * 2;
        vector<list<string>> temp(size);

        for(int i = 0; i < size / 2; i++){
            for(int n = table[i].size(); n > 0; n--){
                string tempS = table[i].front();
                int h = hash(tempS) % size;
                
                temp[h].push_front(tempS);
                table[i].remove(tempS);
            }
        }
        table = temp;
    }
    num_elems++;

    int insert_location = hash(word) % size;

    table[insert_location].push_front(word);
}

bool Stringset::find(string word) const{
    hash<string> hash;
    int h = hash(word) % size;

    for(string str : table[h]){
        if(str == word){
            return true;
        }
    }
    
    return false;
}

void Stringset::remove(string word){
    for(int i = 0; i < size; i++)
        table[i].remove(word);
    num_elems--;
}

