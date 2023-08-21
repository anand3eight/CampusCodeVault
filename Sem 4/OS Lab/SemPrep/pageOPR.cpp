#include <iostream>
#include <iomanip>
using namespace std;

int search(char *sa, char page, int s)
{
    for (int i = 0; i < s; i++)
    {
        if (sa[i] == page)
            return i;
    }
    return -1;
}

int replace(char *sa, char *rs, int s, int p, int st)
{
    int res, max = -1;
    for (int i = 0; i < s; i++)
    {
        res = -1;
        if (sa[i] == ' ')
            return i;
        for (int j = st; j < p; j++)
        {
            if (sa[i] == rs[j])
                res = j;
        }
        if (res == -1)
            return i;
        if (res > max)
            max = res;
    }
    return max;
}
void pageOPR(char *rs, int p, int s)
{
    int pf = 0, pos;
    char sa[s];
    memset(&sa, ' ', s);
    for (int i = 0; i < p; i++)
    {
        if (search(sa, rs[i], s) == -1)
        {
            pf++;
            pos = replace(sa, rs, s, p, i);
            sa[pos] = rs[i];
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
    pageOPR(rs, p, s);
}