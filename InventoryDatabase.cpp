#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

#include "projectNode.h"

class LinkedList{
	private:
		int count;
		LinkNode *head;
	public:

		LinkedList();
		~LinkedList(){deleteAllList();};
		bool deleteItem(string key);
		LinkNode *searchNode(string key);
		void insertNode(LinkNode *node);
		LinkNode *removeNode(string key);
		void traverseList();
		void deleteAllList();
		bool isEmptyList();
		int getSizeList();
		LinkNode *getHead();
};

LinkedList::LinkedList()
{
	count = 0;
	head  = nullptr;
}

LinkNode *LinkedList::getHead()
{
	return head;
}

int LinkedList::getSizeList()
{
	return count;
}

bool LinkedList::isEmptyList()
{
	return head == nullptr;
}

void LinkedList::insertNode(LinkNode *node)
{
	LinkNode *current, *prev;
	bool found;

	cout << "\n\t\t\tInserting New Node into LinkedList ...." << endl;

	
	if(head == nullptr){
		cout << "\n\t\t\tInserting into Empty list..." << endl;  //inserts into empty list
		head = node;

	}
	else{					//inserting into non-empty list:
	
		prev    = nullptr;
		current = head;
		found   = false;
		while( current != nullptr){

			if(current->getKey() > node->getKey()){
				found = true;
				break;
			}

			prev    = current;
			current = current->getNext();
		}

		if(found){
			if(prev == nullptr){
				cout << "\n\t\t\tInserting at the beginning of list..." << endl;
				node->setNext(head);
				head = node;	
			}
			else{
				//insert In between current and previous nodes
				cout << "\n\t\t\tInserting between: " << prev << " and " << current << endl;
				node->setNext(current);
				prev->setNext(node);
			}

		}else{ 
			if(prev != nullptr){
				cout << "\n\t\t\tInserting at the end of list..." << endl;
				prev->setNext(node);
			}
		}	
	}

				//update the node count:
	count += 1;

	return;

}

void LinkedList::deleteAllList()
{
	LinkNode *node;

	cout << "\n\n\t\t\tDeleting All Items in LinkedList ...."; //deletes all items

	while(count > 0){
		
		node = head;
		head = node->getNext();
		cout <<"\n\t\t\tDeleting Node: \n";
		node->printInfo();

		delete node;
		count--;		//deletes and subtracts the count

		cout << "\n\t\t\tNumber of Remaining Items is: " << count << "\n\n";
	}

	cout << "\n\n";

	return;

}

void LinkedList::traverseList()
{
	LinkNode *node;

	cout << "\n\n\t\t\tTraversing LinkedList ....";

	node = head;
	while(node != nullptr){
		
	//	node->printInfo();
		node = node->getNext();
	}

	cout << "\n\n";

	return;
}

bool LinkedList::deleteItem(string key)
{
	LinkNode *node;
	LinkNode *prev;
	bool found = false;

	cout << "\n\n\t\t\tSearching LinkedList ...." <<endl;

	prev = nullptr;
	node = head;
	while(node != nullptr){

		cout << "\n\t\t\t" <<node->getKey() << endl;

		if(node->getKey() == key){   //if item is found, prints
			cout << "\n\n\t\t\tRecord Found: "<< node->getKey() << " versus: " << key <<endl;	
			node->printInfo();
			found = true;
			break;
		}
		else if(node->getKey() > key){
			cout << "\n\n\t\t\tTerminating Search: "<< node->getKey() << " versus: " << key <<endl;	
			break;
		}

		prev = node;
		node = node->getNext();
	}

	if(found){
		cout << "\n\t\t\tDeleting Node ...\n";

		if(prev == nullptr)	// if item is last item inserted 
			head = node->getNext();
		else
			prev->setNext(node->getNext());

		delete node;
		count--;

		cout << "\n\t\t\tNumber of Remaining Items is: " << count << "\n\n";
	}
	else{
		cout << "\n\t\t\tItem Not Found: " << key <<endl;	

	}

	return found;
}

LinkNode *LinkedList::removeNode(string key)
{
	LinkNode *node;
	LinkNode *prev;
	bool found = false;

	cout << "\n\n\t\t\tSearching LinkedList ....";

	prev = nullptr;
	node = head;
	while(node != nullptr){

		cout << "\n\t\t\t" <<node->getKey() << endl;

		if(node->getKey() == key){//if record is found, prints
			cout << "\n\t\t\tRecord Found: "<< node->getKey() << " versus: " << key <<endl;	
			node->printInfo();
			found = true;
			break;
		}
		else if(node->getKey() > key){
			cout << "\n\n\t\t\tTerminating Search: "<< node->getKey() << " versus: " << key <<endl;	
			break;
		}

		prev = node;
		node = node->getNext();
	}

	if(found){
		cout << "\n\t\t\tDeleting Node ...\n";

		if(prev == nullptr)	// if item is last item inserted (i.e. at the beginning)
			head = node->getNext();
		else


			prev->setNext(node->getNext());

		count--;

		cout << "\n\t\t\tNumber of Remaining Items is: " << count << "\n\n";
	}
	else{
		cout << "\n\t\t\tItem Not Found: " << key <<endl;	
		node = nullptr;
	}

	return node;
}

LinkNode *LinkedList::searchNode(string key)
{
	LinkNode *node;
	bool found = false;

	cout << "\n\n\t\t\tSearching LinkedList ....";

	node = head;
	while(node != nullptr){

	//	cout << "\n\t\t\t" << node->getKey() << endl;

		if(node->getKey() == key){//if item is found, prints
			cout << "\n\t\t\tRecord Found: "<< node->getKey() << " versus: " << key <<endl;	
			node->printInfo();
			found = true;
			break;
		}
		else if(node->getKey() > key){
			cout << "\n\n\t\t\tTerminating Search: "<< node->getKey() << " versus: " << key <<endl;	
			break;
		}

		node = node->getNext();
	}

	cout << "\n\n";

	if(!found)
		node = nullptr;

	return node;
}

LinkNode *createNode(string name, float price, int quant)
{	
	LinkNode *node;

	try{
		node = new LinkNode(name,price,quant,nullptr); //creates the new node
		node->printInfo();	
	}
	catch(bad_alloc){
		cout << "\n\n\t\t\tYikes! Out of memory!!!\n";
		node = nullptr;
	}

	return node;
}

LinkedList *createLinkedList()
{
	LinkedList *list;

	list = new LinkedList(); //creates a new list
	
	return list;
}

void destroyLinkedList(LinkedList *list)
{
	if(list != nullptr){

		if(list->getSizeList() >0){
			cout << "\n\n\t\t\tFailure: Attempting to delete a non-empty list\n\n";
		}
		else{
			delete list; //deletes list
			list = nullptr;
			cout << "\n\n\t\t\tLinkedList Successfully Deleted\n\n";
		}
	}
	
	return;	
}


int main()
{

	int i,j,k;
	int num;
	string key;
	int quant;
	float price;
	int success;
	bool found;
	int choice;
	int count;
	string name;
	string line;
	string response="Y";
	
	LinkedList *myLinkedList;
	LinkNode *node;
	ifstream fp;
	fp.open("store_inventory.txt");
	getline(fp, line);
	getline(fp, line);

	cout << fixed << setprecision(2) << showpoint;
	while(true)
	{							//menu
		cout<<"\nInventory Database Menu: "<<endl;
		cout<<"\n1. Build Database"<<endl;
		cout<<"2. Add new Item"<<endl;
		cout<<"3. Remove Item"<<endl;
		cout<<"4. Edit Item"<<endl;
		cout<<"5. Search for Item"<<endl;
		cout<<"6. Print All Items"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"\nEnter Choice: ";
		cin>>choice;

		if (choice==1){ //build
			myLinkedList =  createLinkedList();
			cout << "\t\t\tNew LinkedList Count: " << myLinkedList->getSizeList() << endl;
			cout << "\t\t\tNew LinkedList Head: " << myLinkedList->getHead() << endl;


			while(fp>>name){
				fp>>price>>quant;
				node = createNode(name,price,quant);

				if(node != nullptr){
					myLinkedList->insertNode(node);

					cout << "\n\t\t\tNode Successfully Added! " << endl;
				}
			}
			fp.close();		

		}
		else if(choice==2){ //add
			cout<<"Enter new Name:  ";
			cin>>name;
			cout<<"Enter new Price: ";
			cin>>price;
			cout<<"Enter new Quantity: ";
			cin>>quant;
			node=createNode(name,price,quant);
			if(node != nullptr){
				myLinkedList->insertNode(node);

				cout << "\n\t\t\tNode Successfully Added! " << endl;
			}

		}
		else if(choice==3){ //delete item
			while(response=="Y")
			{
				cout << "\n\t\t\tEnter Name of Item to Delete: ";
				cin >>key;
				found = myLinkedList->deleteItem(key);
				cout<<"Continue(Y/N): ";
				cin>>response;
			
				if(!found)
					cout << "\n\n\t\t\tRecord Not Found For: " << key <<endl;

			}
		}
		else if(choice==4){ //edit
			cout << "\n\t\t\tEnter Name of Item to Edit: ";
			cin >>key;
			name=key;
			found=myLinkedList->deleteItem(key);
			if(!found)
				cout << "\n\n\t\t\tRecord Not Found For: " << key <<endl;
			if(found){
				cout<<"Enter new price: ";
				cin>>price;
				cout<<"Enter new quantity: ";
				cin>>quant;
				node=createNode(name,price,quant);
				if(node != nullptr)
					myLinkedList->insertNode(node);
			}
			

		}
		else if(choice==5){ //search
			cout << "\n\t\t\tEnter Search Name: ";
			cin >>key;
			node = myLinkedList->searchNode(key);

			if(node == nullptr)
				cout << "\n\n\t\t\tRecord Not Found For: " << key <<endl;

		}
		else if(choice==6){ //list
			node=myLinkedList->getHead();
			i=0;
			while(i<myLinkedList->getSizeList()){
				node->printInfo();
				node=node->getNext();
				i++;
			}
		}
		else if(choice==7){ //exit
			cout<<"Goodbye!"<<endl;
			break;
		}
	}

	return 0;
}

