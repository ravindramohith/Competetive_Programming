#ifndef TRIE_H
#define TRIE_H

#include <map>
#include <string>
#include <vector>
using namespace std;

class Node
{
public:
    map<char, Node *> keys;
    bool end;
    Node() : end(false){};
    void setEnd() { end = true; }
    bool isEnd() const { return end; }
    ~Node()
    {
        for (auto const &it : keys)
        {
            delete it.second;
        }
    }
};

class Trie
{
private:
    Node *root;
    void search(Node *node, string str, vector<string> &words) const;

public:
    Trie();
    ~Trie();
    void add(const string &word);
    bool isWord(const string &word) const;
    vector<string> print() const;
};

#endif /* TRIE_H */
