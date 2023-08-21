#include <iostream>
#include <iomanip>
using namespace std;
typedef struct Frame F;
struct Frame
{
    char page = ' ';
    int pos = -1;
};

int search(F *sa, char page, int s)
{
    for (int i = 0; i < s; i++)
    {
        if (sa[i].page == page)
            return i;
    }
    return -1;
}

int replace(F *sa, int s)
{
    int min = INT_MAX, m = -1;
    for (int i = 0; i < s; i++)
    {
        if (sa[i].page == ' ')
            return i;
        else if (min > sa[i].pos)
        {
            min = sa[i].pos;
            m = i;
        }
    }
    return m;
}
void pageLRU(char *rs, int p, int s)
{
    int pf = 0, pos;
    F sa[s];
    for (int i = 0; i < p; i++)
    {
        pos = search(sa, rs[i], s);
        if (pos == -1)
        {
            pf++;
            pos = replace(sa, s);
            sa[pos].page = rs[i];
            sa[pos].pos = i;
        }
        else
        {
            sa[pos].pos = i;
        }
    }
    cout << endl
         << setw(20) << "Page Faults : " << pf;
    cout << endl
         << setw(20) << "Probability : " << float(pf) / float(p);
    cout << endl
         << setw(20) << "Percentage : " << float(pf) * 100 / float(p);
}
int main()
{
    int p, s;
    cout << "Enter pages and slots : ";
    cin >> p >> s;
    char rs[p];
    cout << "Enter Ref. String : ";
    for (int i = 0; i < p; i++)
    {
        cin >> rs[i];
    }
    pageLRU(rs, p, s);
}