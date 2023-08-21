//Page Replacement Algorithm - FIFO

#include<iostream>
using namespace std;

int searchPage(char *slotArr, int slots, int page){
	for(int i = 0; i < slots; i++){
		if(page == slotArr[i])
			return i;
	}
	return -1;
}

void pageFIFO(char *refString, int pages, int slots){
	int pos = 0, pagefault = 0;
	char slotArr[slots];
	for(int i = 0; i < slots; i++){
		slotArr[i] = ' ';
	}

	for(int i = 0; i < pages; i++){
		if(searchPage(slotArr, slots, refString[i]) == -1){
			pagefault++;
			slotArr[(pos++)%slots] = refString[i];
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
	pageFIFO(refString, pages, slots);
	return 0;
}
