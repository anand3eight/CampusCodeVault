#include <iostream>
#include <cstdlib>
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

void producer(int *buffer, int len, int *in)
{
    int val;
    cout << "Enter Data : ";
    cin >> val;
    buffer[(*in)] = val;
    *in = ((*in) + 1) % len;
}

void consumer(int *buffer, int len, int *out)
{
    cout << "Consumed Data : " << buffer[(*out)] << endl;
    (*out) = ((*out) + 1) % len;
}

int main()
{
    int len, empty, full = 0, mutex = 1, in = 0, out = 0;
    int *buffer;
    int inp, flag = 1;
    cout << "Enter Buffer Length : ";
    cin >> len;
    empty = len;
    buffer = (int *)malloc(sizeof(int));
    while (flag == 1)
    {
        cout << "1 : Producer " << endl
             << "2 : Consumer " << endl
             << "Enter Choice : ";
        cin >> inp;
        switch (inp)
        {
        case 1:
            if (Wait(&empty) && Wait(&mutex))
            {
                producer(buffer, len, &in);
                signal(&mutex);
                signal(&full);
            }
            else
                cout << "Buffer is Full or Occupied" << endl;
            break;
        case 2:
            if (Wait(&full) && Wait(&mutex))
            {
                consumer(buffer, len, &out);
                signal(&mutex);
                signal(&empty);
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