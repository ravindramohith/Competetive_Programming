#include <iostream>
#include "map.h"

int main()
{
    Map myMap;
    myMap.set("arms", 2);
    myMap.set("fingers", 10);
    myMap.set("eyes", 2);
    myMap.set("belley button", 1);

    std::cout << "Value of fingers: " << myMap.get("fingers") << std::endl;
    std::cout << "Size of map: " << myMap.size() << std::endl;

    std::vector<int> values = myMap.values();
    std::cout << "Values in map: ";
    for (int value : values)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    Map map2;
    map2.has("hands");
    map2.values();

    std::map<std::string, std::string> map3;
    std::string keyObj = "obj";
    std::string keyFunc = "func";

    map3.insert(std::make_pair("hello", "string value"));
    map3.insert(std::make_pair(keyObj, "obj value"));
    map3.insert(std::make_pair(keyFunc, "func value"));
    map3.insert(std::make_pair("NaN", "NaN value"));

    std::cout << "Size of map3: " << map3.size() << std::endl;
    std::cout << "Value of hello: " << map3["hello"] << std::endl;
    std::cout << "Value of obj key: " << map3[keyObj] << std::endl;
    std::cout << "Value of func key: " << map3[keyFunc] << std::endl;
    std::cout << "Value of NaN key: " << map3["NaN"] << std::endl;

    return 0;
}
