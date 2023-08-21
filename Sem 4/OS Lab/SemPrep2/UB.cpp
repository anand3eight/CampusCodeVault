#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int Wait(int *s)
{
    if (*s > 0)
    {
        (*s)--;
        return 1;
    }
    return 0;
}

void signal(int *s)
{
    (*s)++;
}

void producer(vector<int> &buffer)
{
    int val;
    cout << "Enter Value : ";
    cin >> val;
    buffer.push_back(val);
}

void consumer(vector<int> &buffer)
{
    cout << "Value : " << buffer.front();
    buffer.erase(buffer.begin() + 0);
}

int main()
{
    int ch, full, mutex;
    vector<int> buffer;
    full = 0;
    mutex = 1;
    do
    {
        cout << endl
             << "1 : P \n2 : C \n3 : Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            if (Wait(&mutex))
            {
                producer(buffer);
                signal(&mutex);
                signal(&full);
            }
            else
            {
                cout << "Buffer is Full or Occupied";
            }
            break;
        case 2:
            if (Wait(&full) && Wait(&mutex))
            {
                consumer(buffer);
                signal(&mutex);
            }
            else
            {
                cout << "Buffer is empty or Occupied";
            }
            break;
        case 3:
            return 0;
        default:
            cout << endl
                 << "Invalid Choice";
        }
    } while (1);
    return 0;
}