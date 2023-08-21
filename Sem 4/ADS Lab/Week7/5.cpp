// You are using GCC
// Length of Strongest Subsequence

#include <iostream>
#include <unordered_map>
using namespace std;
int LongestBitonic(int *arr, int n)
{
      unordered_map<int, int> I, D;
      int lenI[n], lenD[n];
      int l;
      for (int j = 0; j < n; j++)
      {
            l = 0;
            if (I.find(arr[j] - 1) != I.end())
                  l = I[arr[j] - 1];
            I[arr[j]] = lenI[j] = l + 1;
      }

      for (int j = n - 1; j > -1; j--)
      {
            l = 0;
            if (D.find(arr[j] - 1) != D.end())
                  l = D[arr[j] - 1];
            D[arr[j]] = lenD[j] = l + 1;
      }

      int longLen = 0;
      for (int j = 0; j < n; j++)
      {

            l = lenI[j] + lenD[j] - 1;
            if (longLen < l)
                  longLen = l;
      }
      return longLen;
}

int main()
{
      int n;
      cin >> n;
      int arr[n];
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }
      cout << LongestBitonic(arr, n);
}