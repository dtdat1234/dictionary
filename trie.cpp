#include "trie.h"

Trie::Trie()
{
    root = new trieNode();
}

void Trie::helperDestroy(trieNode *&node)
{
    if (node == nullptr)
    {
        return;
    }
    for (trieNode *child : node->child)
    {
        if (child != nullptr)
        {
            helperDestroy(child);
        }
    }
    delete node;
    node = nullptr;
}

Trie::~Trie()
{
    helperDestroy(root);
}

bool Trie::isEmpty()
{
    for (trieNode *child : root->child)
    {
        if (child != nullptr)
        {
            return false;
        }
    }
    return true;
}

void Trie::insert(std::string word)
{
    trieNode *current = root;
    for (char c : word)
    {
        if (current->child[c - 'a'] == nullptr)
        {
            current->child[c - 'a'] = new trieNode();
            current->child[c - 'a']->val = current->val + c;
        }
        current = current->child[c - 'a'];
    }
    current->flag = true;
}

bool Trie::search(std::string word)
{
    trieNode *current = root;
    for (char c : word)
    {
        if (current->child[c - 'a'] == nullptr)
        {
            return false;
        }
        else
        {
            current = current->child[c - 'a'];
        }
    }

    return current->flag;
}

bool Trie::startsWith(std::string prefix)
{
    trieNode *current = root;
    for (char c : prefix)
    {
        if (current->child[c - 'a'] == nullptr)
        {
            return false;
        }
        else
        {
            current = current->child[c - 'a'];
        }
    }

    return true;
}

bool Trie::helperRemove(trieNode *node, std::string word, int depth)
{
    if (node == nullptr)
    {
        return false;
    }

    if (depth == word.size())
    {
        if (!node->flag)
        {
            std::cout << "Word not found.\n";
            return false;
        }
        // if flag == true
        node->flag = false;

        // if node has children, then it can't be deleted
        for (trieNode *child : node->child)
        {
            // node has another children
            if (child != nullptr)
            {
                return false;
            }
        }
        return true;
    }

    int idx = word[depth] - 'a';
    if (helperRemove(node->child[idx], word, depth + 1))
    {
        delete node->child[idx];
        node->child[idx] = nullptr;

        // check if node has no children and not the end of another word.
        if (node->flag)
        {
            return false;
        }
        else
        {
            for (trieNode *child : node->child)
            {
                if (child != nullptr)
                {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

void Trie::remove(std::string word)
{
    helperRemove(root, word, 0);
}

void Trie::helperAutoSearch(std::vector<std::string> &dict, trieNode *current)
{
    if (current == nullptr)
    {
        return;
    }

    if (current->flag)
    {
        dict.push_back(current->val);
    }

    for (trieNode *child : current->child)
    {
        if (child != nullptr)
        {
            helperAutoSearch(dict, child);
        }
    }
}

std::vector<std::string> Trie::autoComplete(std::string prefix)
{
    std::vector<std::string> dict;

    trieNode *current = root;
    for (char c : prefix)
    {
        if (current->child[c - 'a'] == nullptr)
        {
            return dict;
        }
        else
        {
            current = current->child[c - 'a'];
        }
    }

    helperAutoSearch(dict, current);
    return dict;
}