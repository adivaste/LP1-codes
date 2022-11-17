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

int countPositives(deque<int> q){
      int count = 0;
      for (int i = 0; i < q.size(); i++){
            if (q[i] > -1) count++;
      }
      return count;
}

deque<int> insertToQueue2(int value, int index) {
	
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
            // Optimal
		page_fault += 1;
            if (currentQueue.size() == frame_size) {

                  // Creating the temporary deque and push all item from currentDQ to it. 
                  deque<int> tempQueue;
                  int lastToReplace = -1;
                  for (int i = 0; i < currentQueue.size(); i++){
                        tempQueue.push_back(currentQueue[i]);
                  }

                  // Iterating through next elements and checking currentQueue for matching elements, if element matches
                  // then we will make the index of tempQueue element as -1 and every time will update lastToReplace, so
                  // if all the elements are still prensent in next searching elements then we have lastToReplace variable,
                  // and if some are not present then we can choose either element from that tempQueue
                  for (int i = index; i >= 0; i--){
                        for (int j = 0; j < currentQueue.size(); j++){
                              int val1 = currentQueue[j];
                              int val2 = reference_string[i];
                              int sz = countPositives(tempQueue);

                              if ((currentQueue[j] == reference_string[i]) and sz) {
                                    tempQueue[j] = -1;
                                    lastToReplace = currentQueue[j];
                                    break;
                              }
                        }
                  }

                  // Selecting the number to replace in currentQueue
                  int numToReplace = lastToReplace;
                  for (int i = 0; i< tempQueue.size(); i++){
                        if (tempQueue[i] != -1){
                              numToReplace = tempQueue[i];
                              break;
                        }
                  }

                  // Finally updating the number
                  for (int i = 0; i< currentQueue.size(); i++){
                        if (currentQueue[i] == numToReplace) currentQueue[i] = value;
                  }

			printQueue(currentQueue);
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

	// cout << "Enter Frame Size O: ";
	// cin >> frame_size;

	// cout << "Enter Reference String Size : ";
	// cin >> reference_string_size;

	// cout << "Enter Reference String :";
	// for (int i = 0; i < reference_string_size; i++){
	// 	cin >> reference_string[i];
	// }

      frame_size = 3;
      reference_string_size = 16;
      int sample[reference_string_size] = {2,4,0,1,4,5,2,1,1,3,1,1,4,3,1,5};
      for (int i = 0; i<reference_string_size; i++){
            reference_string[i] = sample[i];
      }

	for(int i=0; i<reference_string_size; i++){
		deque<int> newQueue = insertToQueue2(reference_string[i],i);
	}

	cout <<"Page Fault :" << page_fault << endl;
	cout <<"Page Hits  :" << page_hit << endl;
	cout << "Ratio of Page Hits   :" << float(page_hit)/float(reference_string_size) << "%" << endl;
	cout << "Ratio of Page Faults :" << float(page_fault)/float(reference_string_size) << "%" << endl;

	return 0;
}
