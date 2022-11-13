#include <iostream>
#include <deque>
using namespace std;

int frame_size = 0;
int reference_string_size = 0;
int *reference_string = new int[reference_string_size];
int page_fault = 0;
int page_hit = 0;

deque<int> currentQueue;
deque<int> orderQueue;

void printQueue(deque<int> q){
	for (int ele : q){
		cout << ele << " | ";
	}
	cout << endl;
}

deque<int> insertToQueue(int value){
	
	// Check Values exist in orderQueue or Not
	bool isExist = false;
	for (int val : currentQueue){
		if (val == value){
			isExist = true;
			break;
		}
	}


	// Perform actions based on it
	if(isExist){
			page_hit += 1;
			printQueue(currentQueue);
			return currentQueue;
	}
	else{
		// FIFO 
		page_fault += 1;
		if (currentQueue.size() == frame_size) {
			int valueToReplace = orderQueue.front();
			orderQueue.pop_front();
			orderQueue.push_back(value);

			for (int i=0; i<currentQueue.size(); i++){
				if (currentQueue[i] == valueToReplace){
					currentQueue[i] = value;
					printQueue(currentQueue);
					return currentQueue;
				}
			}
		}
		else{
			currentQueue.push_back(value);
			orderQueue.push_back(value);
			printQueue(currentQueue);
		}
	}
	return currentQueue;
}
int main(){	

	cout << "Enter Frame Size : ";
	cin >> frame_size;

	cout << "Enter Reference String Size : ";
	cin >> reference_string_size;

	cout << "Enter Reference String :";
	for (int i = 0; i < reference_string_size; i++){
		cin >> reference_string[i];
	}

	for(int i=0; i<reference_string_size; i++){
		deque<int> newQueue = insertToQueue(reference_string[i]);
	}

	cout <<"Page Fault :" << page_fault << endl;
	cout <<"Page Hits  :" << page_hit << endl;
	cout << "Ratio of Page Hits   :" << float(page_hit)/float(reference_string_size) << "%" << endl;
	cout << "Ratio of Page Faults :" << float(page_fault)/float(reference_string_size) << "%" << endl;

	return 0;
}
