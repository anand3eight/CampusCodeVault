// Priority Scheduling Algorithm

#include <iostream>
#include <cstdlib>
#include <queue>
#include <iomanip>
using namespace std;
typedef struct Process Process;
struct Process
{
      char name[30];
      int at, bt, pr, tat, rbt, wt;
};

Process *inputProcesses(int n)
{
      Process *prs = (Process *)malloc(sizeof(Process) * n);
      cout << "Enter Details : (Name, AT, BT, PR) " << endl;
      for (int i = 0; i < n; i++)
      {
            cin >> prs[i].name >> prs[i].at >> prs[i].bt >> prs[i].pr;
            prs[i].rbt = prs[i].bt;
      }
      return prs;
}

void swap(int *arr, int i, int j)
{
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
}

int *sortPR(Process *prs, int n)
{
      int temp;
      int *order = (int *)malloc(sizeof(int) * n);
      for (int i = 0; i < n; i++)
      {
            order[i] = i;
      }
      for (int i = 0; i < n - 1; i++)
      {
            for (int j = i + 1; j < n; j++)
            {
                  if (prs[order[i]].at > prs[order[j]].at)
                        swap(order, i, j);
            }
      }
      return order;
}

void PPR(Process *prs, int *ord, int cst, int n)
{
      int min, in, t = prs[ord[0]].at, pr = -1, cmp = 0;
      cout << "Order : ";
      while (cmp != n)
      {
            min = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                  if (prs[ord[i]].at <= t)
                  {
                        if (prs[ord[i]].rbt > 0 && min > prs[ord[i]].pr)
                        {
                              min = prs[ord[i]].pr;
                              in = i;
                        }
                  }
                  else if (i == cmp)
                  {
                        t = prs[ord[i]].at;
                        i--;
                  }
                  else
                        break;
            }

            if (pr != -1 && pr != in)
                  t += cst;
            t += 1;
            prs[ord[in]].rbt -= 1;
            if (prs[ord[in]].rbt == 0)
            {
                  prs[ord[in]].tat = t - prs[ord[in]].at;
                  prs[ord[in]].wt = prs[ord[in]].tat - prs[ord[in]].bt;
                  cmp += 1;
                  cout << prs[ord[in]].name << " ";
            }
            pr = in;
      }
      cout << endl;
}
void printProcesses(Process *prs, int *ord, int n)
{
      int ttat = 0, twt = 0;
      cout << setw(10) << "Process" << setw(10) << "BT" << setw(10) << "WT" << setw(10) << "TAT" << endl;
      for (int i = 0; i < n; i++)
      {
            twt += prs[i].wt;
            ttat += prs[i].tat;
            cout << setw(10) << prs[i].name << setw(10) << prs[i].bt << setw(10) << prs[i].wt << setw(10) << prs[i].tat << endl;
      }
      cout << setw(40) << "Average Waiting Time : " << setw(10) << setprecision(2) << (float)twt / n << endl;
      cout << setw(40) << "Average Turn Around Time : " << setw(10) << setprecision(2) << (float)ttat / n << endl;
}

int main()
{
      int n, cst, tq;
      cout << "Process Count : ";
      cin >> n;
      cout << "Context Switching Time : (Type 0 if NA) -> ";
      cin >> cst;
      Process *prs = inputProcesses(n);
      int *order = sortPR(prs, n);
      PPR(prs, order, cst, n);
      printProcesses(prs, order, n);
      return 0;
}