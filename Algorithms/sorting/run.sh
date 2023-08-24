echo "              Bubble Sort:

  parameter        Best       Worst
comparisions    -  O(n)       O(n^2)
swaps           -  O(1)       O(n^2)
time complexity -       O(n^2)

       Adaptive                Stable            Extra memory
 (already sorted order) (duplicate elements)
          ✔                     ✔                    ✘        
"
g++ bubble_sort.cpp && ./a.out
echo "              Insertion Sort:

  parameter        Best       Worst
comparisions    -  O(n)       O(n^2)
swaps           -  O(1)       O(n^2)
time complexity -       O(n^2)

       Adaptive                Stable            Extra memory
 (already sorted order) (duplicate elements)
          ✔                     ✔                    ✘        
"
g++ insertion_sort.cpp && ./a.out

echo "Selection sort
 k passes gives first k smallest elements

 parameter        Best       Worst
comparisions    -  O(n)       O(n^2)
swaps           -  O(1)       O(n)
time complexity -       O(n^2)

      Adaptive                Stable            Extra memory
(already sorted order) (duplicate elements)
         ✘                     ✘                    ✘
"
g++ selection_sort.cpp && ./a.out