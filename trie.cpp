#include "trie.h"

Trie::Trie()
{
    root = new trieNode();
}

void Trie::insert(std::string word)
{
    trieNode *current = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (current->child[word[i] - 'a'] == nullptr)
        {
            current->child[word[i] - 'a'] = new trieNode();
            current->child[word[i] - 'a']->val = current->val + word[i];
        }
        current = current->child[word[i] - 'a'];
    }
    current->flag = true;
}

bool Trie::search(std::string word)
{
    trieNode *current = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (current->child[word[i] - 'a'] == nullptr)
        {
            return false;
        }
        else
        {
            current = current->child[word[i] - 'a'];
        }
    }

    return current->flag;
}

bool Trie::startsWith(std::string prefix)
{
    trieNode *current = root;
    for (int i = 0; i < prefix.size(); i++)
    {
        if (current->child[prefix[i] - 'a'] == nullptr)
        {
            return false;
        }
        else
        {
            current = current->child[prefix[i] - 'a'];
        }
    }

    return true;
}