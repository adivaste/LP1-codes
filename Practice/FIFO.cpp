#include <iostream>
#include <deque>
using namespace std;

// Declaring the required constants
int frame_size;
int reference_string_size;
int *reference_string = new int[reference_string_size];
deque<int> current_queue;
deque<int> order_queue;

int page_hits = 0;
int page_miss = 0;

// Creating required functions 
void printQueue(deque<int> q){
	for (int ele : q){
		cout << ele << " | ";
	}
	cout << endl;
}

// Algorithm for inserting values 
void insertIntoQueue(int value, int index){

	// Checking weather given element is present in the current queue or not 
	bool isExists = false;
	for (int ele : current_queue){
		if (ele == value){
			isExists = true;
		}
	}

	// Based on presence perform the perticular actions 
	if (isExists){
		page_hits += 1;
		printQueue(current_queue)	;
		return;
	}
	else{
		page_miss += 1;
		if (current_queue.size() == frame_size){
			int elementToReplace = order_queue.front();
			order_queue.pop_front();
			order_queue.push_back(value);

			for (int i=0; i<current_queue.size(); i++){
				if (current_queue[i] == elementToReplace){
					current_queue[i] = value;
					printQueue(current_queue);
					return;
				}
			}
		}
		else{
			order_queue.push_back(value);
			current_queue.push_back(value);
			printQueue(current_queue);
		}
	}
	return ;
}


int main(){

	cout << "Enter Frame Size : ";
	cin >> frame_size;

	cout << "Enter Reference String Size : ";
	cin >> reference_string_size;

	cout << "Enter Reference String : ";
	for (int i=0; i< reference_string_size; i++){
		cin >> reference_string[i];
	}

	for(int i=0; i<reference_string_size; i++){
		insertIntoQueue(reference_string[i], i);
	}
	cout << page_hits;
	cout << page_miss;
	
}

