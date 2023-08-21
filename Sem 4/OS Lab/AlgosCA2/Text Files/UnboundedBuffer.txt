#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

bool Wait(int *s)
{
    if (*s > 0)
    {
        (*s)--;
        return true;
    }
    return false;
}

void signal(int *s)
{
    (*s)++;
}

void producer(vector<int> &buffer)
{
    int val;
    cout << "Enter Data : ";
    cin >> val;
    buffer.push_back(val);
}

void consumer(vector<int> &buffer)
{
    cout << "Consumed Data : " << buffer.front() << endl;
    buffer.erase(buffer.begin() + 0); // Pops out First Element
}

int main()
{
    int len, full = 0, mutex = 1;
    vector<int> buffer;
    int inp, flag = 1;
    while (flag == 1)
    {
        cout << "1 : Producer " << endl
             << "2 : Consumer " << endl
             << "Enter Choice : ";
        cin >> inp;
        switch (inp)
        {
        case 1:
            if (Wait(&mutex))
            {
                producer(buffer);
                signal(&mutex);
                signal(&full);
            }
            else
                cout << "Buffer is Occupied" << endl;
            break;
        case 2:
            if (Wait(&full) && Wait(&mutex))
            {
                consumer(buffer);
                signal(&mutex);
            }
            else
                cout << "Buffer is Empty or Occupied" << endl;
            break;
        default:
            cout << "Enter Valid Choice" << endl;
        }
        cout << endl
             << "To continue : Press 1 -> ";
        cin >> flag;
    }

    return 0;
}