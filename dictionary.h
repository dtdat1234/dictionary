#pragma once
#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include "trie.h"
#include <fstream>

class Dictionary
{
private:
    std::vector<std::string> dict;
    Trie *trie = nullptr;

public:
    Dictionary();
    ~Dictionary();

    void loadFile(std::string);
    void loadTrie();
    void printDictionary(std::string);
    void printSearching(std::string, std::string);
};

#include "dictionary.cpp"
#endif //_DICTIONARY_H_