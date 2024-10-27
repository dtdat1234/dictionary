#pragma once
#ifndef _TRIE_H_
#define _TRIE_H_

#include <vector>
#include <string>
struct trieNode
{
    std::vector<trieNode *> child;
    bool flag;
    std::string val;

    trieNode() : val("")
    {
        for (int i = 0; i < 26; i++)
        {
            child.push_back(nullptr);
        }
    }
};

// Prototype from leetcode
class Trie
{
private:
    trieNode *root;

public:
    Trie();

    void insert(std::string);
    bool search(std::string);
    bool startsWith(std::string);
};

#include "trie.cpp"
#endif //_TRIE_H_