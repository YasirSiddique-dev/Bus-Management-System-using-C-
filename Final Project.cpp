#include<iostream>
#include<conio.h>
using namespace std;

struct node{
	int seat_num;
	string name;
	int id;
	int phone;
	float fare;
	string location_from;
	string location_to;
	node *left;
	node *right;
};
class tree
{
	private:
		node *root;
		int count;
	public:
		tree()
		{
			root=NULL;
			count=0;	
		}
		void reserve_seat(int seat_num,int id, int phone,string location_from,string location_to,float fare, string name);
		void reserving(int seat_num ,int id,int phone,string location_from,string location_to,float fare,string name,node *leaf);
		void check(int seat_num,int id,int phone,string location_from,string location_to,float fare,string name,node *leaf);
		void status();
		void pre_order(node *leaf);	
		node* FindMin(node* leaf);
		void cancel_res(int seat_num);
		node* Delete(struct node *leaf, int seat_num);
	
};
//Roor-seat reserving
void tree::reserve_seat(int seat_num,int id,int phone,string location_from,string location_to,float fare,string name)
	{
		if(root==NULL)
		{
			root=new node;
			root->seat_num=seat_num;
			root->name=name;
			root->id=id;
			root->phone=phone;
			root->location_from=location_from;
			root->location_to=location_to;
			root->fare=fare;
			root->left=NULL;
			root->right=NULL;
			count++;
			cout<<"Seat "<<seat_num<<" Reserved";	
		}
		else
		{
			check(seat_num,id,phone,location_from,location_to,fare,name,root);
		}
	}
//checking function
void tree::check(int seat_num,int id,int phone,string location_from,string location_to,float fare,string name,node *leaf)
	{	//searching function for previous reserving
		node *temp = new node;
		temp = root;

		while (temp != NULL)
		{
			
			if (temp->seat_num == seat_num)
			{
				cout <<"Seat already Reserved";
				return;
			}

			else if (temp->seat_num > seat_num)
				temp = temp->left;

			else
				temp = temp->right;
		}

		reserving(seat_num,id,phone,location_from,location_to,fare,name,root);
		return;
	}
//child-seats reserving
void tree::reserving(int seat_num,int id,int phone, string location_from,string location_to,float fare,string name, node *leaf)
	{
	if(count<36)
	{	
	//if number is leas than root
	if(seat_num < leaf->seat_num)
		{	
			if(leaf->left==NULL)
			{
				leaf->left=new node;
				leaf->left->seat_num=seat_num;
				leaf->left->id=id;
				leaf->left->phone=phone;
				leaf->left->name=name;
				leaf->left->location_from=location_from;
				leaf->left->location_to=location_to;
				leaf->left->fare=fare;
				leaf->left->left=NULL;
				leaf->left->right=NULL;
				count++;
				cout<<"Seat "<<seat_num<<" Reserved";
			}
			else
			{
				reserving(seat_num,id,phone,location_from,location_to,fare,name,leaf->left);
			}
		}
	//if num is greater than root
	else if(seat_num >= leaf->seat_num)
	{
		if(leaf->right==NULL)
		{
			leaf->right=new node;
			leaf->right->seat_num=seat_num;
			leaf->right->id=id;
			leaf->right->phone=phone;
			leaf->right->location_from=location_from;
			leaf->right->location_to=location_to;
			leaf->right->fare=fare;
			leaf->right->name=name;
			leaf->right->left=NULL;
			leaf->right->right=NULL;
			count++;
			cout<<"Seat "<<seat_num<<" Reserved";
		}
		else
		{
			reserving(seat_num,id,phone,location_from,location_to,fare,name,leaf->right);
		}
		}
	}
	else
	{
		cout<<"\nBus is full\n";
	}
	}
void tree::status()
	{
		if(root == NULL)
		{
			cout<<"\n No seat is reserved yet...";
		}
		else if(root !=NULL)
		{
			pre_order(root);
			cout<<"\n";
		}
	}
void tree::pre_order(node *leaf)
	{	

		if(leaf!= NULL)
		{
			cout<<"Seat Number "<<leaf->seat_num<<" Reserved "<<" \n";
			pre_order(leaf->left);
			pre_order(leaf->right);
		}
		
		
	}
//finding min value
node* tree::FindMin(node *leaf)
{
	leaf=root;
	
	while(leaf->left != NULL)
	{
		leaf=leaf->left;
	}
	return leaf;
}
//cancel reservation
void tree::cancel_res(int seat_num)
{
	Delete(root,seat_num);
}
//Deletion of node
node* tree::Delete(node *leaf,int seat_num)
{
	if(leaf==NULL)
	{
		return leaf;
	}
	else if(seat_num < leaf->seat_num)
	{
		leaf->left = Delete(leaf->left,seat_num);
	}
	else if(seat_num > leaf->seat_num)
	{
		leaf->right = Delete(leaf->right,seat_num);
	}
	else
	{	
		
		//case 1 one child (left)
		 if(leaf->left == NULL )
		{
			node *temp=leaf->right;
			delete leaf;
			return temp;
		}
		//case 2 one child (right)
		else if(leaf->right==NULL)
		{
			node *temp=leaf->left;
			delete leaf;
			return temp;
		}
		//case 3  two child
		else
		{
			node *temp=FindMin(leaf->right);
			leaf->seat_num=temp->seat_num;
			leaf->right= Delete(leaf->right,temp->seat_num);
		}	
	}
	
	
	return leaf;
}

int main()
{
	tree t1;
	int choice,seat,id,clas,contact,cancel;
	string from;
	string to;
	string name;
	float fare;

	cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                      WELCOME TO DAEWOO BUS MANAGEMENT SYSTEM                                        |\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                                                                                                     |\n";
	cout<<"|                                                                                         Press any key to continue.. |\n";
	cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
	getch();
	system("CLS");
	do{
	
	cout<<"\n\t--------------------------------------------------\n";
	cout<<"\t|                                                |\n";
	cout<<"\t|                                                |\n";
	cout<<"\t|                                                |\n";
	cout<<"\t|                                                |\n";
	cout<<"\t|          1.Press 1 to Reserve Seat             |\n";
	cout<<"\t|                                                |\n";
	cout<<"\t|                                                |\n";
	cout<<"\t|                                                |\n";
	cout<<"\t|                                                |\n";
	cout<<"\t--------------------------------------------------\n";
	cout<<"\n\t--------------------------------------------------\n";
	cout<<"\t|                                                |\n";
	cout<<"\t|                                                |\n";
	cout<<"\t|                                                |\n";
	cout<<"\t|                                                |\n";
	cout<<"\t|          2.Press 2 to cancel Reservation       |\n";
	cout<<"\t|                                                |\n";
	cout<<"\t|                                                |\n";
	cout<<"\t|                                                |\n";
	cout<<"\t|                                                |\n";
	cout<<"\t--------------------------------------------------\n";
	cout<<"\n\nOr Press 0 exit\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
				cout<<"Enter Departue Location : ";
				cin.ignore();
				getline(cin,from);
				system("CLS");
				cout<<"Departure Location : "<<from;
				cout<<"\n-----------------------------------------------------------------------------------------------------------------\n";
				cout<<"Enter Arrival Location : ";
		
				getline(cin,to);
				system("CLS");
				cout<<"Departure Location : "<<from;
				cout<<"\t\t Arrival Location : "<<to;
				cout<<"\n-----------------------------------------------------------------------------------------------------------------\n";
				cout<<"----------------------------------\n";
				cout<<"|                                |\n";
				cout<<"|                                |\n";
				cout<<"|                                |\n";
				cout<<"|   1.Press 1 for Economy class  |\n";
				cout<<"|           Fare=1000            |\n";
				cout<<"|                                |\n";
				cout<<"|                                |\n";
				cout<<"----------------------------------\n";
				cout<<"----------------------------------\n";
				cout<<"|                                |\n";
				cout<<"|                                |\n";
				cout<<"|                                |\n";
				cout<<"|   2.Press 2 for Business class |\n";
				cout<<"|           Fare=1500            |\n";
				cout<<"|                                |\n";
				cout<<"|                                |\n";
				cout<<"----------------------------------\n";
				cout<<"----------------------------------\n";
				cout<<"|                                |\n";
				cout<<"|                                |\n";
				cout<<"|                                |\n";
				cout<<"|   3.Press 3 for Luxury class   |\n";
				cout<<"|           Fare=2000            |\n";
				cout<<"|                                |\n";
				cout<<"|                                |\n";
				cout<<"----------------------------------\n";
				cin>>clas;
				if(clas==1)
				{
					fare=1000;
				}
				else if(clas==2)
				{
					fare=1500;
				}
				else if(clas==3)
				{
					fare=2000;
				}
				system("CLS");
				cout<<"Departure Location : "<<from;
				cout<<"\t\t Arrival Location : "<<to;
				cout<<"\t\t\t Bus type : ";
				if(clas==1)
				{
					cout<<"Economy Class";
				}
				else if(clas==2)
				{
					cout<<"Business Class";
				}
				else if(clas==3)
				{
					cout<<"Luxury Class";
				}
			cout<<"\n-----------------------------------------------------------------------------------------------------------------\n";
			cout<<"Enter your Name : ";
			cin.ignore();
			getline(cin,name);
				system("CLS");
				cout<<"Departure Location : "<<from;
				cout<<"\t\t Arrival Location : "<<to;
				cout<<"\t\t\t Bus type : ";
				if(clas==1)
				{
					cout<<"Economy Class";
				}
				else if(clas==2)
				{
					cout<<"Business Class";
				}
				else if(clas==3)
				{
					cout<<"Luxury Class";
				}
				cout<<"\nName : "<<name;
			cout<<"\n-----------------------------------------------------------------------------------------------------------------\n";
			cout<<"Enter Your Id : ";
			cin>>id;
							system("CLS");
				cout<<"Departure Location : "<<from;
				cout<<"\t\t Arrival Location : "<<to;
				cout<<"\t\t\t Bus type : ";
				if(clas==1)
				{
					cout<<"Economy Class";
				}
				else if(clas==2)
				{
					cout<<"Business Class";
				}
				else if(clas==3)
				{
					cout<<"Luxury Class";
				}
				cout<<"\nName : "<<name;
				cout<<"\t\t\tID = "<<id;
			cout<<"\n-----------------------------------------------------------------------------------------------------------------\n";
			cout<<"Enter Your phone Number : ";
			cin>>contact;
			system("CLS");
				cout<<"Departure Location : "<<from;
				cout<<"\t\t Arrival Location : "<<to;
				cout<<"\t\t\t Bus type : ";
				if(clas==1)
				{
					cout<<"Economy Class";
				}
				else if(clas==2)
				{
					cout<<"Business Class";
				}
				else if(clas==3)
				{
					cout<<"Luxury Class";
				}
				cout<<"\nName : "<<name;
				cout<<"\t\t\tID = "<<id;
				cout<<"\t\t\t\t\tPhone Number : "<<contact;
			cout<<"\n-----------------------------------------------------------------------------------------------------------------\n";				
			cout<<"SEAT RESERVING SECTION\n";
			cout<<"-------------------------\n";
			cout<<"Already reserverd seats : \n";
			t1.status();
			cout<<"\nEnter Seat Number to Reserve(1-36) : ";
			cin>>seat;
			t1.reserve_seat(seat,id,contact,from,to,fare,name);
			cout<<"\nPress any key to continue again...";
			getch();
			system("CLS");
			}
		break;
		case 2:
			{
				cout<<"CANCEL RESERVING SECTION\n";
				cout<<"-------------------------\n";
				cout<<"Already reserverd seats : \n";
				t1.status();
				cout<<"\nEnter Reserved Seat Number to cancel reservation : ";
				cin>>cancel;
				t1.cancel_res(cancel);
				cout<<"Seat "<<cancel<<" Reservation cancelled.";
					cout<<"\nPress any key to continue again...";
			getch();
			system("CLS");
			}	
		break;	
	}
	}while(choice!=0);
	
}	
