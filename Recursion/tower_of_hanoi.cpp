#include <iostream>
using namespace std;

void tower_of_hanoi(int n, char A, char B, char C)
{
    if (n > 0)
    {
        tower_of_hanoi(n - 1, A, C, B);
        cout << "Moved from " << A << " to " << C << endl;
        tower_of_hanoi(n - 1, B, A, C);
    }
}
int main()
{
    tower_of_hanoi(4, 'A', 'B', 'C');
    return 0;
}