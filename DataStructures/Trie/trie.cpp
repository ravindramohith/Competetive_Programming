#include "trie.h"

Trie::Trie() : root(new Node()) {}

Trie::~Trie()
{
    delete root;
}

void Trie::add(const std::string &word)
{
    Node *node = root;
    for (char c : word)
    {
        if (!node->keys.count(c))
        {
            node->keys[c] = new Node();
        }
        node = node->keys[c];
    }
    node->setEnd();
}

bool Trie::isWord(const std::string &word) const
{
    Node *node = root;
    for (char c : word)
    {
        if (!node->keys.count(c))
        {
            return false;
        }
        node = node->keys[c];
    }
    return node->isEnd();
}

std::vector<std::string> Trie::print() const
{
    std::vector<std::string> words;
    search(root, "", words);
    return words;
}

void Trie::search(Node *node, std::string str, std::vector<std::string> &words) const
{
    if (node->isEnd())
        words.push_back(str);

    for (auto const [c, n] : node->keys)
        search(n, str + c, words);
}
