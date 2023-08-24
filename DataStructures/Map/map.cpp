#include "map.h"

Map::Map()
{
    count = 0;
}

int Map::size()
{
    return count;
}

void Map::set(std::string key, int value)
{
    collection[key] = value;
    count++;
}

bool Map::has(std::string key)
{
    return (collection.find(key) != collection.end());
}

int Map::get(std::string key)
{
    if (has(key))
    {
        return collection[key];
    }
    return -1;
}

void Map::remove(std::string key)
{
    if (has(key))
    {
        collection.erase(key);
        count--;
    }
}

std::vector<int> Map::values()
{
    std::vector<int> result;
    for (auto &element : collection)
    {
        result.push_back(element.second);
    }
    return result;
}

void Map::clear()
{
    collection.clear();
    count = 0;
}
