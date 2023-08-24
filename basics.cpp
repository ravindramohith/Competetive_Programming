#include <bits/stdc++.h>
using namespace std;

void f2(int h)
{
    int g;
    cout << h;
}

void f()
{
    int x;
    f2(x);
}

int main()
{

    // Static memory:
    int a;   // 2 bytes(can also takes 4 bytes depending on compiler)
    float b; // 4 bytes
    f();
    // Static memory allocation: memory assigned to this particular funciton at compile time.
    // anything run at compile time is static.
    // ------------------
    // |      Heap      |
    // |      Memory    |
    // ------------------
    // |       Stack    |
    // |       Memory   |
    // |       g,h      | <-f2()
    // |       x        | <-f()
    // |       a,b      | <-main()
    // ------------------
    // |  Code section  |
    // | main(),f(),f2()|
    // ------------------

    // a program cannot directly access Heap memory. It can only code section and stack memory.
    // program accesses heap memory using pointer.
    // Allocating pointer:
    int *p; // 2 bytes for 'p'
    p = new int[5];
    // ----------------------------
    // |      Heap                |
    // |      Memory              |
    // |       ----------------   |
    // |   |-->|  |  |  |  |  |   |
    // |   |   ----------------   |
    // ----|-----------------------
    // |   |   Stack               |
    // |   |   Memory              |
    // |   |   g,h                 | <-f2()
    // |   |   x                   | <-f()
    // |   |-----p,                | <-main()
    // |       a,b                 | <-main()
    // -----------------------------
    // |  Code section  |
    // | main(),f(),f2()|
    // ------------------

    // Deallocating pointer:
    delete[] p;
    p = NULL;
    // ------------------
    // |      Heap      |
    // |      Memory    |
    // ------------------
    // |       Stack    |
    // |       Memory   |
    // |       g,h      | <-f2()
    // |       x        | <-f()
    // |       p        | <-main()
    // |       a,b      | <-main()
    // ------------------
    // |  Code section  |
    // | main(),f(),f2()|
    // ------------------

    //Physical Data Structures: These define how the memory should be organised for storing the data.
    // 1. Array(created in stack memory)
    // 2. linked list(created in heap memory)


    //Logical Data Structures: Organises disipline of flow of data

    // I.Linear:
    // 1. Stack(LIFO)
    // 2. Queue(FIFO)

    // II.Non-Linear:
    // 1. Trees
    // 2. Graphs

    // III.Tabular:
    // Hash-Table
}