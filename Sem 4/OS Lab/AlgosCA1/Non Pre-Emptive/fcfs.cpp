// FCFS Scheduling Algorithm

#include <iostream>
#include <cstdlib>
#include <queue>
#include <iomanip>
using namespace std;
typedef struct Process Process;
struct Process
{
      char name[30];
      int at, bt, tat, wt;
};

Process *inputProcesses(int n)
{
      Process *prs = (Process *)malloc(sizeof(Process) * n);
      cout << "Enter Details : (Name, AT, BT) " << endl;
      for (int i = 0; i < n; i++)
      {
            cin >> prs[i].name >> prs[i].at >> prs[i].bt;
      }
      return prs;
}

void swap(int *arr, int i, int j)
{
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
}

int *sortFCFS(Process *prs, int n)
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

void FCFS(Process *prs, int *ord, int cst, int n)
{
      int t = prs[ord[0]].at;
      for (int i = 0; i < n; i++)
      {
            if (prs[ord[i]].at > t)
            {
                  t = prs[ord[i]].at;
            }
            t += prs[ord[i]].bt;
            prs[ord[i]].tat = t - prs[ord[i]].at;
            prs[ord[i]].wt = prs[ord[i]].tat - prs[ord[i]].bt;
            t += cst;
      }
}

void printProcesses(Process *prs, int *ord, int n)
{
      cout << "Order : ";
      for (int i = 0; i < n; i++)
      {
            cout << prs[ord[i]].name << " ";
      }
      cout << endl;
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
      int n, cst;
      cout << "Process Count : ";
      cin >> n;
      cout << "Context Switching Time : (Type 0 if NA) -> ";
      cin >> cst;
      Process *prs = inputProcesses(n);
      int *order = sortFCFS(prs, n);
      FCFS(prs, order, cst, n);
      printProcesses(prs, order, n);
      return 0;
}