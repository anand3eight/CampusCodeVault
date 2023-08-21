#include <iostream>
#include <cstdlib>
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

void producer(int *buffer, int *in, int len)
{
    cout << endl
         << "Enter Value : ";
    cin >> buffer[(*in)];
    (*in) = ((*in) + 1) % len;
}

void consumer(int *buffer, int *out, int len)
{
    cout << "Value : " << buffer[*out];
    (*out) = ((*out) + 1) % len;
}

int main()
{
    int in, out, ch, full, empty, mutex, len;
    cout << "Enter Buffer Length : ";
    cin >> len;
    int *buffer = (int *)malloc(sizeof(int) * len);
    full = 0;
    empty = len;
    mutex = 1;
    in = 0;
    out = 0;
    do
    {
        cout << endl
             << "1 : P \n2 : C \n3 : Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            if (Wait(&empty) && Wait(&mutex))
            {
                producer(buffer, &in, len);
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
                consumer(buffer, &out, len);
                signal(&mutex);
                signal(&empty);
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