#include <iostream>

// Chapter 19, Programming Challenge 12: Inventory Bin Queue
#include <iostream>
#include "InvStack.h" //keep for task 2
#include "InvItem.h" // keep for task 2
#include "InvQue.h" // keep for task 2
#include "BinaryTree.h" 

using namespace std;

int main()
{
	InvQue<InventoryItem> queue;	// create queue
	InvStack<InventoryItem> stack;
	InvTree<InventoryItem> tree;	// create binary tree
	InventoryItem item;				// create inventory item object

	int storagechoice;
	int choice;						// Menu choice
	long serial;					// Serial number
	string mDate;					// Manufacture date

	cout << "what would you like to store by?\n";
	cout << "1. Queue\n2. Stack\n";
	cout << "3. Binary Tree\n";
	cin >> storagechoice;

	while (storagechoice < 1 || storagechoice > 3)
	{
		cout << "Please enter 1, 2, or 3: ";
		cin >> storagechoice;
	}

	do
	{
		// Display the menu.
		cout << "\n------ Inventory Menu --------\n\n";
		cout << "1.  Enter a part into the inventory.\n";
		cout << "2.  Take a part from the inventory.\n";
		cout << "3.  Display all inventory\n";
		cout << "4.  Quit.\n\n";
		cout << "Please make a choice (1, 2, 3, or 4):  ";
		cin >> choice;

		// Validate choice
		while (choice < 1 || choice > 4)
		{
			cout << "Please enter 1, 2, 3, or 4: ";
			cin >> choice;
		}

		// Act on the user's choice.
		switch(choice)
		{

		case 1:
			// Enter a part into inventory.
			cout << "\nYou have chosen to add an item to the inventory bin.\n\n";
			cout << "Enter the item's serial number: ";
			cin >> serial;
			item.setSerialNum(serial);
			cout << "Enter the item's manufacture date: ";
			cin >> mDate;
			item.setManufactDate(mDate);
			if (storagechoice == 1)
			{
				queue.enqueue(item);
			}
			else if (storagechoice == 2)
			{
				stack.push(item);
			}
			else if (storagechoice == 3)
			{
				tree.insertNode(item);
			}
			
			cout << " item has been added to the inventory bin.\n";
			break;

		case 2:
    		// Take a part out of inventory.
            cout << "\nYou have chosen to remove an item from the inventory bin.\n\n";

            // Queue
            if (storagechoice == 1)
            {
                if (queue.isEmpty())
                {
                    cout << "No parts to remove.\n";
                }
                else
                {
                    queue.dequeue(item);

                    cout << "\nThe part you removed was:\n";
                    cout << "\tSerial number: "
                         << item.getSerialNum() << endl;
                    cout << "\tManufacture date: "
                         << item.getManufactDate() << endl;
                    cout << endl;
                }
            }

            // Stack
            else if (storagechoice == 2)
            {
                if (stack.isEmpty())
                {
                    cout << "No parts to remove.\n";
                }
                else
                {
                    stack.pop(item);

                    cout << "\nThe part you removed was:\n";
                    cout << "\tSerial number: "
                         << item.getSerialNum() << endl;
                    cout << "\tManufacture date: "
                         << item.getManufactDate() << endl;
                    cout << endl;
                }
            }

			// Binary Tree
            else
            {
                cout << "Enter the serial number of the part to remove: ";
                cin >> serial;

                InventoryItem searchItem;
                searchItem.setSerialNum(serial);

                if (tree.searchNode(searchItem))
                {
                    tree.remove(searchItem);
                    cout << "Part removed successfully.\n";
                }
                else
                {
                    cout << "Part not found in inventory.\n";
                }
            }
            break;

		
        case 3:
            cout << "\n------ Inventory Items ------\n";

            if (storagechoice == 1)
            {
                queue.display();
            }
            else if (storagechoice == 2)
            {
                stack.display();
            }
            else
            {
                tree.displayInOrder();
            }
            break;

		
        case 4:
            cout << "\nGoodbye!\n\n";
            break;
		}
	} while (choice  != 4);

	return 0;
}

//g++ main.cpp -o main
//./main