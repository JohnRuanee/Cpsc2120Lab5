/*
 * Name: John Ruane
 * Date Submitted: 10/18
 * Lab Section: 001
 * Assignment Name: Lab 5
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 /*
 int main(){
     Stringset wordlist;
     testStringset(wordlist);
     return 0;
 }
 */
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }
 
//loads file
void loadStringset(Stringset& words, string filename){
    //opens file
    ifstream infile(filename);
    string word;
    //gets each word and adds it to the table
    while(getline(infile, word)){
        words.insert(word);
    }
 }
 
vector<string> spellcheck(const Stringset& words, string word){
    //vars
    vector<string> temp;
    string test;

    //loops through changing one letter of word at a time till it goes through whole alphabet on each letter
    for(int i = 0; i < 26; i++){
        for(int n = 0; n < word.size(); n++){
            test = word;
            test[n] = char(i+97);
            
            //if one of these changed words is in table and if its not the original word add it to temp
            if(words.find(test) && test != word)
                temp.push_back(test);
        }
    }
    //returns temp
    return temp;
 }
