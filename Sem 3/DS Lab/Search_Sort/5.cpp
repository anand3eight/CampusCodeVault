//Sorting Odd Numbers and Even Numbers

#include<iostream>
#include<stack>

using namespace std;

void sortHalf(int arr[], int len)
{
	stack <int> odd, even, temp;
	for(int i = 0; i < len; i++)
	{
		if(arr[i] % 2)
		{
			while(!odd.empty() && arr[i] > odd.top())
			{
				temp.push(odd.top());
				odd.pop();
			}
			odd.push(arr[i]);
			while(!temp.empty())
			{
				odd.push(temp.top());
				temp.pop();
			}
		}
		else
		{
			while(!even.empty() && arr[i] > even.top())
			{
				temp.push(even.top());
				even.pop();
			}
			even.push(arr[i]);
			while(!temp.empty())
			{
				even.push(temp.top());
				temp.pop();
			}
		}
	}
	cout << "Array : ";
	while(!odd.empty())
	{
		cout << odd.top() << " ";
		odd.pop();
	}
	while(!even.empty())
	{
		cout << even.top() << " ";
		even.pop();
	}
	
}
int main()
{
	int arr[] = {9, 8, 1, 2, 4};
	sortHalf(arr, 5);
	return 0;	
}
