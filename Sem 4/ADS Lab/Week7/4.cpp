// You are using GCC
// Subset Array

#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
      int a, n1 = 0, n2 = 0, c = 0;
      cin >> n1;
      unordered_map<int, int> HashMap;
      for (int i = 0; i < n1; i++)
      {
            cin >> a;
            HashMap[a] = 1;
      }
      cin >> n2;
      for (int i = 0; i < n2; i++)
      {
            cin >> a;
            if (HashMap.find(a) != HashMap.end())
                  c++;
      }
      if (c == n2)
            cout << "arr2[] is subset of arr1[]";
      else
            cout << "arr2[] is not a subset of arr1[]";
}