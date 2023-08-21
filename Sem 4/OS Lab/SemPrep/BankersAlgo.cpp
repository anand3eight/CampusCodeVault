// Banker's Algorithm

#include <iostream>
using namespace std;

int main()
{
    int f, p, r, cmp = 0;
    cout << "Enter Process and Resource Count : ";
    cin >> p >> r;
    int req[p][r], alloc[p][r], need[p][r];
    int av[r], cur[r];
    int flag[p];
    for (int i = 0; i < p; i++)
        flag[i] = 0;
    cout << "Requirement Matrix : " << endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
            cin >> req[i][j];
    }
    cout << "Allocated Matrix : " << endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
            cin >> alloc[i][j];
    }
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
            need[i][j] = req[i][j] - alloc[i][j];
    }
    cout << "Current Available Vector : ";
    for (int i = 0; i < r; i++)
    {
        cin >> cur[i];
    }
    int count = 0;
    cout << "Execution Order : ";
    while (cmp != p && count < p)
    {
        for (int i = 0; i < p; i++)
        {
            f = 0;
            if (!flag[i])
            {
                for (int j = 0; j < r; j++)
                {
                    if (need[i][j] <= cur[j])
                        f++;
                }
                if (f == r)
                {
                    cout << "P" << (i + 1) << " ";
                    flag[i] = 1;
                    cmp++;
                    for (int j = 0; j < r; j++)
                        cur[j] += alloc[i][j];
                }
            }
        }
        count++;
    }
    if (count == p)
    {
        for (int i = 0; i < p; i++)
        {
            if (!flag[i])
            {
                cout << endl
                     << "Invalid Execution due to P" << (i + 1);
                break;
            }
        }
    }
    return 0;
}