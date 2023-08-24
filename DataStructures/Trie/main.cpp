#include <iostream>
#include "trie.h"

int main()
{
    Trie myTrie;
    myTrie.add("ball");
    myTrie.add("bat");
    myTrie.add("doll");
    myTrie.add("dork");
    myTrie.add("do");
    myTrie.add("dorm");
    myTrie.add("send");
    myTrie.add("sense");

    std::cout << myTrie.isWord("doll") << std::endl; // Output: 1
    std::cout << myTrie.isWord("dor") << std::endl;  // Output: 0
    std::cout << myTrie.isWord("dorf") << std::endl; // Output: 0

    std::vector<std::string> words = myTrie.print();
    for (const auto &word : words)
    {
        std::cout << word << std::endl;
    }

    return 0;
}
