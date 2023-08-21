//Page Replacement Algorithm - LRU

#include<iostream>
using namespace std;
typedef struct frame f;
struct frame{
	int pos;
	char page;
};

int searchPage(f *slotArr, int slots, int page){
	for(int i = 0; i < slots; i++){
		if(page == slotArr[i].page)
			return i;
	}
	return -1;
}

int replaceLRU(f *slotArr, int slots){
	if(slotArr[0].pos == -1){
		return 0;
	}
	int min = slotArr[0].pos;
	for(int i = 1; i < slots; i++){
		if(slotArr[i].pos == -1)
			return i;
		else if(slotArr[i].pos < min){
			min = slotArr[i].pos;
		}
	}
	return min;
}

void pageLRU(char *refString, int pages, int slots){
	int res, p = 0, pagefault = 0;
	f slotArr[slots];
	for(int i = 0; i < slots; i++){
		slotArr[i].pos = -1;
		slotArr[i].page = ' ';
	}

	for(int i = 0; i < pages; i++){
		res = searchPage(slotArr, slots, refString[i]);
		if(res == -1){
			pagefault++;
			p = replaceLRU(slotArr, slots);
			slotArr[p].pos = i;
			slotArr[p].page = refString[i];
		}
		else{
			slotArr[res].pos = i;	
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
	pageLRU(refString, pages, slots);
	return 0;
}
