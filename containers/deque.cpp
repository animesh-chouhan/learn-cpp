/*
    deque (pronounced "deck"): irregular acronym for double-ended queue
    template < class T, class Alloc = allocator<T> > class deque;

    > sequence container
    > dynamic sizing

    1.Similar functionality to vectors but with efficient insertion and deletion also at the beginning
    2.Unlike vectors deques are not guaranteed to store all of its elements in CONTIGUOUS LOCATIONS
    3.Typical implementation uses a sequence of individually allocated fixed-sized array, with additional
      bookkeeping which means indexed access to a deque must perform a two pointer dereferences, 
      compared to vector's indexed acces which performs only one
    
    Pros:
    1.Efficient insertion and deletion at both beginning and end  
    2.Expansion is cheaper than vector because it doesn't involve copying existing elements to a new memory location
    3.Useful with very long sequences, where reallocations become more expensive

    Cons:
    1.More complex internally as it provides constant time access to fragmented arrays
    2.Deques typically have large minimal memory cost: a deque holding just one element has to allocate its full internal array
    3.For operations that involve frequent insertion/removal at positions other than beginning/end, deques perform
      worse and have less consistent iterators and references than lists and forward lists

    Complexity:
    1.Random access: constant O(1)
    2.Insertion/Deletion at beginning/end: constant O(1)
    3.Insertion/Deletion: linear O(n) 
    
    Uses:
    1.Browser History
    2.Undo tracker
    3.A-steal job scheduling algo for parallel processing

*/

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
  vector<int> v = {5, 4, 8, 9};

  // constructor
  deque<int> d1;
  deque<int> d2(2, 1);
  deque<int> d3(v.begin(), v.end());
  deque<int> d4(d3);

  // capacity
  cout << d3.size() << "\n";
  cout << d3.max_size() << "\n";
  cout << d1.empty() << "\n";

  // resize
  cout << "Resize:\n";
  cout << d1.size() << "\n";
  d1.resize(10, 2);
  cout << d1.size() << "\n";

  // modifiers
  d1.push_back(5);
  d1.push_front(8);
  d3.pop_back();
  d4.pop_front();

  d1.assign(3, 4);
  d1.swap(d2);

  // output
  cout << "Output:\n";
  for (auto x : d1)
  {
    cout << x << "\n";
  }
  for (auto x : d2)
  {
    cout << x << "\n";
  }
  for (auto x : d3)
  {
    cout << x << "\n";
  }

  return 0;
}