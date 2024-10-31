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

    trieNode() : val(""), flag(false)
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

    void helperDestroy(trieNode *&);
    void helperAutoSearch(std::vector<std::string> &, trieNode *);
    bool helperRemove(trieNode *, std::string, int);

public:
    Trie();
    ~Trie();

    bool isEmpty();
    void insert(std::string);
    bool search(std::string);
    bool startsWith(std::string);
    void remove(std::string);

    std::vector<std::string> autoComplete(std::string);
};

#include "trie.cpp"
#endif //_TRIE_H_