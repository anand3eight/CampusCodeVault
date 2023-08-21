#include <iostream>
using namespace std;

void bestFit(int *holes, int *prcs, int h, int p)
{
    int min, m;
    for (int i = 0; i < p; i++)
    {
        min = INT_MAX;
        m = -1;
        for (int j = 0; j < h; j++)
        {
            if (holes[j] > prcs[i])
            {
                if (m == -1)
                {
                    min = holes[j];
                    m = j;
                }
                else if (min > holes[j])
                {
                    min = holes[j];
                    m = j;
                }
            }
        }
        if (m == -1)
            cout << "Process " << (i + 1) << " is not allocated with Hole" << endl;
        else
        {
            cout << "Process " << (i + 1) << " is allocated with Hole " << m + 1 << endl;
            holes[m] -= prcs[i];
        }
    }
}

void worstFit(int *holes, int *prcs, int h, int p)
{
    int max, m;
    for (int i = 0; i < p; i++)
    {
        max = -1;
        m = -1;
        for (int j = 0; j < h; j++)
        {
            if (holes[j] > prcs[i])
            {
                if (m == -1)
                {
                    m = j;
                    max = holes[j];
                }
                else if (max < holes[j])
                {
                    m = j;
                    max = holes[j];
                }
            }
        }
        if (m == -1)
            cout << "Process " << (i + 1) << " is not allocated with Hole" << endl;
        else
        {
            cout << "Process " << (i + 1) << " is allocated with Hole " << m + 1 << endl;
            holes[m] -= prcs[i];
        }
    }
}

void firstFit(int *holes, int *prcs, int h, int p)
{
    int c;
    for (int i = 0; i < p; i++)
    {
        c = -1;
        for (int j = 0; j < h; j++)
        {
            if (holes[j] > prcs[i])
            {
                cout << "Process " << (i + 1) << " is allocated with Hole " << j + 1 << endl;
                holes[j] -= prcs[i];
                c = 0;
                break;
            }
        }
        if (c == -1)
            cout << "Process " << (i + 1) << " is not allocated with Hole" << endl;
    }
}
void restore(int *hs, int *holes, int h)
{
    for (int i = 0; i < h; i++)
        hs[i] = holes[i];
}
int main()
{
    int h, p;
    cout << "Enter Holes and Process Count : ";
    cin >> h >> p;
    int hs[h], holes[h], prcs[p];
    cout << "Enter Hole Size : ";
    for (int i = 0; i < h; i++)
        cin >> holes[i];
    cout << "Enter Process Size : ";
    for (int i = 0; i < p; i++)
        cin >> prcs[i];
    cout << endl
         << "Best Fit" << endl;
    restore(hs, holes, h);
    bestFit(hs, prcs, h, p);
    cout << endl
         << "Worst Fit" << endl;
    restore(hs, holes, h);
    worstFit(hs, prcs, h, p);
    cout << endl
         << "First Fit" << endl;
    restore(hs, holes, h);
    firstFit(hs, prcs, h, p);
    return 0;
}