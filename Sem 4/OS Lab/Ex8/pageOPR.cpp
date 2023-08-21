//Page Replacement Algorithm - OPR

#include<iostream>
using namespace std;

int searchPage(char *slotArr, int slots, int page){
	for(int i = 0; i < slots; i++){
		if(page == slotArr[i])
			return i;
	}
	return -1;
}

int replaceOPR(char *slotArr, char *refString, int st, int pages, int slots){
	int max = -1, res;
	for(int i = 1; i < slots; i++){
		res = -1;
		if(slotArr[i] == ' ')
			return i;
		for(int j = st; j < pages; j++){
			if(slotArr[i] == refString[j])
				res = j;
		}
		if(res == -1){
			return i;
		}
		else if(res > max)
			max = res;
	}
	return max;
}

void pageOPR(char *refString, int pages, int slots){
	int pos = 0, pagefault = 0;
	char slotArr[slots];
	for(int i = 0; i < slots; i++){
		slotArr[i] = ' ';
	}

	for(int i = 0; i < pages; i++){
		if(searchPage(slotArr, slots, refString[i]) == -1){
			pagefault++;
			slotArr[replaceOPR(slotArr, refString, i-1, pages, slots)] = refString[i];
		}
	}
	cout << "\nPage Faults : " << pagefault;
	cout << "\nPage Fault Probability : " << float(pagefault)/float(pages);
	cout << "\nPage Fault Percentage : " << float(pagefault)*100/float(pages) << "%";
}

int main(){
	int slots, pages;
	cout << "Enter No. of Slots : ";
	cin >> slots;
	cout << "Enter No. of Pages : ";
	cin >> pages;
	char refString[pages];
	cout << "Enter Reference String : ";
	for(int i = 0; i < pages; i++){
		cin >> refString[i];
	}
	pageOPR(refString, pages, slots);
	return 0;
}
