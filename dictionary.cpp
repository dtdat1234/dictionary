#include "dictionary.h"
#include <iostream>

Dictionary::Dictionary()
{
    trie = new Trie();
}

Dictionary::~Dictionary() {}

void Dictionary::loadFile(std::string fileName)
{
    std::ifstream inFile;
    inFile.open(fileName);
    if (!inFile.is_open())
    {
        std::cout << "Unable to open file.\n";
    }
    else
    {
        std::string line;
        while (std::getline(inFile, line))
        {
            dict.push_back(line);
        }
    }
    inFile.close();
}

void Dictionary::loadTrie()
{
    for (std::string word : dict)
    {
        trie->insert(word);
    }
}

void Dictionary::printDictionary(std::string fileName)
{
    std::ofstream outFile;
    outFile.open(fileName);

    for (std::string word : dict)
    {
        outFile << word << '\n';
    }
    outFile.close();
}

void Dictionary::printSearching(std::string fileName, std::string prefix)
{
    std::ofstream outFile;
    outFile.open(fileName);

    std::vector<std::string> res = trie->autoComplete(prefix);
    for (std::string word : res)
    {
        outFile << word << '\n';
    }
    outFile.close();
}