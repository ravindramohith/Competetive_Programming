#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 5; // Number of empty arrays

    std::vector<std::vector<int>> matrix(n, std::vector<int>());

    // Printing the size of each empty array
    cout << matrix.size() << endl;


    return 0;
}
