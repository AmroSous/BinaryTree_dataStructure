#include"MyBinaryTree.h"
#include<fstream>
#include<string>

int main()
{
	int choice;
	MyBinaryTree BST;

	/*{
		int arr[] = { 10, 5, 20, 3, 7, 15, 30, 6, 12, 17 }; 
		int k = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0; i < k; i++)
		{
			BST.insert(arr[i]);
		}
	}*/

	while (1)
	{
		choice = menu();
		system("cls");
		cout << "\n   ________________________________________________________________" << endl;
		if (choice == 9) break;

		switch (choice)
		{
		case 1:
		{
			string filename;
			int item;
			cout << "\n   Enter the file name to read nodes : "; cin >> filename;
			ifstream input_file(filename, ios::in);
			if (input_file.is_open())
			{
				while (!input_file.eof())
				{
					input_file >> item;
					if (input_file.fail()) break;
					BST.insert(item);
				}
				cout << "\n   Nodes have been read successfully" << endl;
			}
			else cout << "\n   Sorry.. Failed in open the file ):" << endl;
		}
		break;
		case 2:
		{
			int data;
			cout << "\n   Enter the data you want to insert in the tree : "; data = takeData();
			BST.insert(data);
			cout << "\n   The data has been inserted succeefully." << endl;
		}
		break;
		case 3:
		{
			cout << "\n   Print the tree In Order : " << BST << endl;
		}
		break;
		case 4:
		{
			int data;
			cout << "\n   Enter the data of the node you want to calculate it's height : "; data = takeData();
			data = BST.height(data);
			if (data == ERROR) cout << "\n   Sorry, This node does not exist." << endl;
			else cout << "\n   The height of the node is : " << data << endl;
		}
		break;
		case 5:
		{
			if (BST.isBalansed()) cout << "\n   Yes, the tree is balanced." << endl;
			else cout << "\n   No, the tree is not balanced." << endl;
		}
		break;
		case 6:
		{
			int k;
			cout << "\n   Enter the value of K : "; k = takeData();
			cout << "\n   Nodes are : "; BST.printSumNodesK(k);
			cout << endl;
		}
		break;
		case 7:
		{
			int r1, r2;
			cout << "\n   Enter the lower limit of range : "; r1 = takeData();
			cout << "\n   Enter the upper limit of range : "; r2 = takeData();
			if (r1 > r2) cout << "\n   Sorry this range is unavailable." << endl;
			else
			{
				cout << "\n   The nodes in this range of data are : ";
				BST.inValueRange(r1, r2);
				cout << endl;
			}
		}
		break;
		case 8:
		{
			int l1, l2;
			cout << "\n   Enter the lower limit of level range : "; l1 = takeData();
			cout << "\n   Enter the upper limit of level range : "; l2 = takeData();
			if (l1 > l2 || l1 < 0 || l2 < 0) cout << "\n   Sorry this range is unavailable." << endl;
			else
			{
				cout << "\n   The nodes in this range of levels are : " << endl;
				BST.inLevelRange(l1, l2);
				cout << endl;
			}
		}
		break;
		}  // switch

		cout << "\n   Press enter to choose another choice .. ";
		cin.ignore();
		cin.get();
		system("cls");

	}  // while

	cout << "\n\n      Ok .. Thank you .\n\n" << endl;  // if choose 8

	return 0;
}