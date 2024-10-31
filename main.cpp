#include <iostream>
#include "trie.h"
#include "dictionary.h"

int main()
{
    std::cout << "\t\t==== DSA-Project ====\n";
    Dictionary dict;
    Trie *newTrie = new Trie();
    dict.loadFile("dataset/5000-words.txt");
    dict.loadTrie();
    // dict.printDictionary("dict.txt");
    dict.printSearching("search.txt", "ban");
    return 0;
}