// You are using GCC
// Sum of Two Numbers in an Array

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
      int n, x, minus;
      unordered_map<int, int> HashMap;
      cin >> n;
      int arr[n];
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }
      cin >> x;
      for (int i = 0; i < n; i++)
      {
            minus = x - arr[i];
            if (HashMap.find(minus) != HashMap.end())
            {
                  cout << "Yes";
                  return 0;
            }
            else
                  HashMap[arr[i]] = minus;
      }
      cout << "No";
      return 0;
}