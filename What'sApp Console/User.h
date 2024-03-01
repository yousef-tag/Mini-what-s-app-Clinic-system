#pragma once
#include <string>
#include <list>
#include <queue>
using namespace std;
class Message {
public:
	string sender;
	string reciever;
	string content;
	bool status;
};
class Chat {
public:
	queue <Message> chat;
	void insertMessage(Message message);
	void removeMessage(Message message);
};
class  Contact
{
public:
	string nameC;
	int phone;
	Chat contactChat;
};

class Group {
public:
	string gName;
	int groupId;
	string admin;
	Chat groupChat;
	list <Contact> groupContacts;
	void addContact(Contact);
	void removeContact(Contact);
};

class User
{
public:
	string userName;
	int phone;
	list <Contact> userContacts;
	list <Group> groups;
	int IdjGroup;
	User();
	void insertContact(Contact inUser);
	bool searchContact(string);
	Contact searchForContact(string);
	void removeContact(Contact inUser);
	void addGroup(Group userGroup);
	bool searchGroup(string);
	Group searchForGroup(string);
	void removeGroup(Group userGroup);
	~User();
};

