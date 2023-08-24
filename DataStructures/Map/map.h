#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <map>
#include <vector>

class Map
{
private:
    std::map<std::string, int> collection;
    int count;

public:
    Map();
    int size();
    void set(std::string key, int value);
    bool has(std::string key);
    int get(std::string key);
    void remove(std::string key);
    std::vector<int> values();
    void clear();
};

#endif // MAP_H
