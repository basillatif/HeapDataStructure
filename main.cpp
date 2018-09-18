#include<iostream>
#include<fstream>
#include<cstdlib>
#include <string>
#include "heap.h"

using namespace std;

int main()
{
	struct HEAP* a=NULL;
	//ELEMENT *b;
	bool running = true;
	while (running) {
		cout << "Please enter your command \n";
		char input;
		cin >> input;
		switch (input) {
		case 'S':
		{
			cout << "Stopping program";
			running = false;
		}
			break;
		case 'C':
		{
			int n;
			cin >> n;
			//cout << n;
			a = Initialize(n);
		}
			break;
		case 'R':
		{
			ifstream myFile("HEAPinput.txt");
			int capacity;
			myFile >> capacity;
			a = Initialize(capacity);
			ELEMENT *b = (struct ELEMENT*)malloc(sizeof(struct ELEMENT)*capacity);
			//bool myFile = true;
			a->size = capacity;
			int c = 0;
			while (!myFile.eof())
			{
				//cout << "Hi";
				//int temp;
				//myFile >> temp;
				//cout << temp;
				myFile >> a->H[c].key;
				c++;
			}
			BuildHeap(a, a->H);
			myFile.close();
		}
			break;
		
		// the program reads in the array A from ﬁle HEAPinput.txt, 
		//calls the linear time build heap algorithm to build the heap based on A, and waits for the next command. 
		case 'W':
		{
			cout << "heap size: " << a->size << endl;
			cout << "heap capacity: " << a->capacity << endl;
			//if (a->size)
			for (int i = 0; i < a->size; i++)
			{
				cout << a->H[i].key;
			}

			cout << "\n";
		}
			break;
		//ELEMENT[a];
		//the program writes the current heap information to the screen, and waits for the next command.
		case 'I':
		{
			int k;
			cin >> k;
			Insert(a, k);
		}
			break;
		//the program inserts an element with key equal to k into the current heap, and waits for the next command.
		case 'D':
		{
			DeleteMin(a);
		}
			break;
		//the program deletes the minimum element from the heap and prints the key ﬁeld of the deleted element 
		//on the screen, it waits for the next command. 
		//case 'K':
		// the program decreases the key of element with index i by v amount.
		}

	}
}

