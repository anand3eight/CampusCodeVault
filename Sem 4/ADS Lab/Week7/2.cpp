// You are using GCC
// Symmetric Pairs in an Array

#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
      int n, p, a, b, flag = 0;
      cin >> n >> p;
      unordered_map<int, int> HashMap;
      for (int i = 0; i < n; i++)
      {
            cin >> a >> b;
            if (HashMap.find(b) == HashMap.end())
                  HashMap[a] = b;
            else
            {
                  flag = 1;
                  cout << "(" << b << ", " << a << ")" << endl;
            }
      }
      if (flag == 0)
            cout << "No symmetric pairs are found";
      return 0;
}