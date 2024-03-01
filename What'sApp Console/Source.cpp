#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "User.h"
using namespace std;
int chatGroup(User user, Group group) {
	int choice;
	Message message;
	message.sender = user.userName;
	message.reciever = "";
	message.status = 0;
	if (group.groupChat.chat.empty() == 1) {
		cout << "Enter message:";
		getline(cin, message.content);
		cout << "Press 1 to send 2 to back:";
		cin >> choice;
		if (choice == 1) {
			group.groupChat.insertMessage(message);
			cout << "Press 2 to back:";
			cin >> choice;
				return 2;
		}
		else
			return 2;
	}
	else {
		while (group.groupChat.chat.empty() == 0)
			cout << group.groupChat.chat.front().content;
		cout << "Enter message:";
		cin >> message.content;
		cout << "Press 1 to send 2 to back:";
		cin >> choice;
		if (choice == 1) {
			group.groupChat.insertMessage(message);
			cout << "Press 2 to back:";
			cin >> choice;
				return 2;
		}
		else
			return 2;
	}
}
int chatMessage(User user, Contact contact) {
	int choice;
	Message message;
	message.sender = user.userName;
	message.reciever = contact.nameC;
	if (contact.contactChat.chat.empty() == 1) {
		cout << "Enter Massage:";
		cin >> message.content;
		
		cout << "Press 1 to send 2 to back:";
		cin >> choice;
		if (choice == 1) {
			contact.contactChat.insertMessage(message);
			cout << "Press 2 to back:";
			cin >> choice;
			if (choice == 2)
				return 2;
		}
		else {
			return 2;
		}
	}
	else {
		while(contact.contactChat.chat.empty()==0)
		cout << contact.contactChat.chat.front().content;
		cout << "Enter Massage: ";
		cin >> message.content;
		cout << "Press 1 to send 2 to back:";
		cin >> choice;
		if (choice == 1) {
			contact.contactChat.insertMessage(message);
			cout << "Press 2 to back:";
			cin >> choice;
			if (choice == 2)
				return 2;
		}
		else {

			return 2;
		}
	}
	
}
int choose(int choice,User user) {
	while (true) {
		if (choice == 1) {
		int num, nchoice;
		repeat:
		num = 0;
		cout << "Enter 1 to exit 2 to continue:";
		cin >> num;
		if (num == 2) {
			cout << "Enter\n 1- to add contact \n 2- to remove contact \n 3- to add group \n";
			cout << " 4- to remove group \n 5- to chat with specific friend \n 6- chat with specific group" << endl;
			
			cin >> nchoice;
			string name;
			int numOfGroupMember;
			Contact contact;
			Group group;
			switch (nchoice)
			{
			case 1:
				cout << "please, enter the contact name" << endl;
				cin >> contact.nameC;

				cout << "please, enter the contact phone" << endl;
				cin >> contact.phone;
				user.insertContact(contact);
				
				break;

			case 2:
			repeats:
				cout << "please, enter the contact name" << endl;
				cin >> name;

				if (user.searchContact(name)) {
					contact.nameC = name;
					user.removeContact(contact);
				}
				else {
					cout << "Enter correct name:";
					goto repeats;
				}
				break;

			case 3:

				cout << "please enter gruop name" << endl;
				cin >> group.gName;
				group.admin = user.userName;
				cout << "please, enter number of group members: " << endl;
				cin >> numOfGroupMember;
				for (int i = 0; i < numOfGroupMember; i++)
				{
					cout << i++ << "-Enter the contact name: ";
					cin >> contact.nameC;
					cout << "Enter contact phone:";
					cin >> contact.phone;
					group.addContact(contact);
				}
				user.addGroup(group);
				break;

			case 4:
			repeatse:
				cout << "please enter group name" << endl;
				cin >> name;
				if (user.searchGroup(name)) {
					group.gName = name;
					user.removeGroup(group);
				}
				else {
					cout << "Enter correct name:\n";
					goto repeatse;
				}
				break;
			case 5:
				cout << "Enter contact:";
				cin >> name;
				contact = user.searchForContact(name);
				cout << "Enter 1 to write messege 2 to back: ";
				cin >> num;
				if (num == 1) {
					num = chatMessage(user, contact);
				}
				if (num == 2)
					goto repeat;
				break;
			case 6:
				cout << "Enter group name:";
				cin >> name;
				group = user.searchForGroup(name);
				cout << "Enter 1 to write messege 2 to back: ";
				cin >> num;
				if (num == 1) {
					num = chatGroup(user, group);
				}
				cin >> num;
				if (num == 2)
					goto repeat;
				break;
			}
		}
		else
			return 2;
	}
	}
}
int main() {
	vector<User> users;
	string name;
	int phone;
	int isExist = 0;
	while (true) {
		User inUser;
		int number,num;
		repeat:
		cout << "Enter 1 to register and 2 to login:";
		cin >> number;
		if (number == 1) {
			cout << "Enter your name :";
			cin >> inUser.userName;
			cout << "Enter your phone : ";
			cin >> inUser.phone;
			users.push_back(inUser);
		}
		if (number == 2) {
			cout << "Enter your name:";
			cin >> name;
			cout << "Enter your phone:";
			cin >> phone;
			vector<User>::iterator it = users.begin();
			while (it != users.end()) {
				if (name == it->userName&&phone == it->phone) {
					isExist = 1;
					num = choose(isExist, *it);
					if (num == 2) {
						goto repeat;
					}
				}
				it++;
			}
		}
	}

	system("pause");
	return 0;
}
