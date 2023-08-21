// You are using GCC
// Double hashing program
#include <iostream>
#include <cstring>
using namespace std;
typedef struct Pair Pair;
struct Pair
{
      char key[30];
      int value;
};

int hash1(int v, int n)
{
      return v % n;
}

int hash2(int v, int n)
{
      return n - (v % n);
}
int double_hash(int v, int n, bool *chk)
{
      int h1 = hash1(v, n);
      int h2 = hash2(h1, n);
      if (chk[h1] == false)
            return h1;
      else
      {
            int index = (h1 + h2) % n;
            if (chk[index] == false)
                  return index;
      }
      return -1;
}

int main()
{
      char k[30];
      int n, j, v;
      cin >> n;
      Pair ht[n];
      bool chk[n] = {0};
      for (int i = 0; i < n; i++)
      {
            cin >> k >> v;
            j = double_hash(v, n, chk);
            if (j != -1)
            {
                  strcpy(ht[j].key, k);
                  ht[j].value = v;
                  chk[j] = true;
            }
      }
      cout << "Hash Table" << endl;
      for (int i = 0; i < n; i++)
      {
            cout << ht[i].key << " " << ht[i].value << endl;
      }
      return 0;
}