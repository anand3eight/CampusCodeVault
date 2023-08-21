// Priority Pre-emptive

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
typedef struct Process P;
struct Process
{
    char name[10];
    int at, bt, pr, rbt, wt, tat;
};

P *inputPrcs(int n)
{
    P *prcs = (P *)malloc(sizeof(P));
    for (int i = 0; i < n; i++)
    {
        cin >> prcs[i].name >> prcs[i].at >> prcs[i].bt >> prcs[i].pr;
        prcs[i].rbt = prcs[i].bt;
        prcs[i].tat = prcs[i].wt = 0;
    }
    return prcs;
}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int *orderPPR(P *prcs, int n)
{
    int *order = (int *)malloc(sizeof(int));
    for (int i = 0; i < n; i++)
    {
        order[i] = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (prcs[order[i]].at > prcs[order[j]].at)
            {
                swap(order, i, j);
            }
        }
    }
    return order;
}

void PPR(P *prcs, int *ord, int cst, int n)
{
    cout << endl
         << "Order : ";
    int min, cur, prev = -1, cmp = 0, t = prcs[ord[0]].at;
    while (cmp != n)
    {
        min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (prcs[ord[i]].at <= t)
            {
                if (prcs[ord[i]].rbt > 0 && min > prcs[ord[i]].pr)
                {
                    min = prcs[ord[i]].pr;
                    cur = ord[i];
                }
            }
            else if (i == cmp)
            {
                t = prcs[ord[i]].at;
                i--;
            }
        }
        if (prev != -1 && prev != cur)
            t += cst;
        t += 1;
        prcs[cur].rbt -= 1;
        if (prcs[cur].rbt == 0)
        {
            cout << prcs[cur].name << " " << t << " ";
            prcs[cur].tat = t - prcs[cur].at;
            prcs[cur].wt = prcs[cur].tat - prcs[cur].bt;
            cmp += 1;
        }
        prev = cur;
    }
    cout << endl;
}

void printPrcs(P *prcs, int n)
{
    int tat = 0, twt = 0;
    cout << setw(10) << "Process" << setw(10) << "AT" << setw(10) << "BT" << setw(10) << "WT" << setw(10) << "TAT" << endl;
    for (int i = 0; i < n; i++)
    {
        tat += prcs[i].tat;
        twt += prcs[i].wt;
        cout
            << setw(10) << prcs[i].name << setw(10) << prcs[i].at << setw(10) << prcs[i].bt << setw(10) << prcs[i].wt << setw(10) << prcs[i].tat << endl;
    }
    cout << setw(10) << "Avg WT : " << setw(10) << setprecision(3) << float(twt) / float(n) << endl;
    cout << setw(10) << "Avg TAT : " << setw(10) << setprecision(3) << float(tat) / float(n) << endl;
}
int main()
{
    int n, cst, *order;
    cout << "Enter No. of Processes : ";
    cin >> n;
    cout << "Enter CST : ";
    cin >> cst;
    cout << "Enter Processes (Name, AT, BT, PR) : " << endl;
    P *prcs = inputPrcs(n);
    order = orderPPR(prcs, n);
    for (int i = 0; i < n; i++)
    {
        cout << prcs[order[i]].name << " ";
    }
    cout << endl;
    PPR(prcs, order, cst, n);
    printPrcs(prcs, n);
    return 0;
}