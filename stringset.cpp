/*
 * Name: John Ruane
 * Date Submitted: 10/18
 * Lab Section: 001
 * Assignment Name: Lab 5
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

//inserts word into table
void Stringset::insert(string word){
    //if word is alread in the table exit
    if(find(word))
        return;

    //opens a hash
    hash<string> hash;

    //if size is too small to add another element
    if(num_elems == size){
        //double the size
        size = size * 2;
        //temp vector of size
        vector<list<string>> temp(size);

        //go through old vector and reassign it to new vector
        for(int i = 0; i < size / 2; i++){
            for(int n = table[i].size(); n > 0; n--){
                //sets a temp string of front of table
                string tempS = table[i].front();
                //set h to hash for an insert location
                int h = hash(tempS) % size;
                
                //pushes temps to front of temp then removes temp s from table
                temp[h].push_front(tempS);
                table[i].remove(tempS);
            }
        }
        //set table equal to temp
        table = temp;
    }
    //increases the number of elements
    num_elems++;

    //sets insert location to hash % size
    int insert_location = hash(word) % size;

    //pushes word at front of table at insert location
    table[insert_location].push_front(word);
}

//if word is in stringset returns true
bool Stringset::find(string word) const{
    //opens hash
    hash<string> hash;
    //sets search location to hash of word % size
    int h = hash(word) % size;

    //goes through table at h and gets each word and checks if it equals word
    for(string str : table[h]){
        //if so returns true
        if(str == word){
            return true;
        }
    }
    //else return false
    return false;
}

//removes word from table
void Stringset::remove(string word){
    //goes through each part of table and removes word
    for(int i = 0; i < size; i++)
        table[i].remove(word);
    //decriments num elements
    num_elems--;
}

