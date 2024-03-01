#include "User.h"
#include <string>
#include <list>
using namespace std;

void Chat::insertMessage(Message message) {
	chat.push(message);
}

void Chat::removeMessage(Message message) {
	chat.pop();
}

void Group::addContact(Contact gContact) {
	if (groupContacts.empty() == 1) {
		groupContacts.push_back(gContact);
	}
	else {
		list<Contact>::iterator it = groupContacts.begin();
		while (gContact.nameC < it->nameC) {
			it++;
		}
		groupContacts.insert(it, gContact);
	}
}

void Group::removeContact(Contact gContact) {
	list<Contact>::iterator it = groupContacts.begin();
	while (gContact.nameC != it->nameC) {
		it++;
	}
	groupContacts.erase(it);
}

User::User()
{
}

void User::insertContact(Contact inUser) {
	if (userContacts.empty() == 1) {
		userContacts.push_back(inUser);
	}
	else {
		list<Contact>::iterator it = userContacts.begin();
		while (inUser.nameC < it->nameC) {
			it++;
		}
		userContacts.insert(it, inUser);

	}
}

bool User::searchContact(string name) {
	bool isExist = false;
	list<Contact>::iterator it = userContacts.begin();
	while (it != userContacts.end()) {
		if (name == it->nameC)
			isExist= true;
		it++;
	}
	return isExist;
}

Contact User::searchForContact(string name) {
	list<Contact>::iterator it = userContacts.begin();
	while (name != it->nameC) {
		it++;
	}
	return *it;
}

void User::removeContact(Contact inUser) {
	list<Contact>::iterator it = userContacts.begin();
	while (inUser.nameC != it->nameC) {
		it++;
	}
	userContacts.erase(it);
}

void User::addGroup(Group userGroup) {
	if (groups.empty() == 1) {
		groups.push_back(userGroup);
	}
	else {
		list<Group>::iterator it = groups.begin();
		while (userGroup.gName != it->gName) {
			it++;
		}
		groups.insert(it, userGroup);
	}
}

bool User::searchGroup(string name) {
	bool isExist = false;
	list<Group>::iterator it = groups.begin();
	while (it != groups.end()) {
		if (name == it->gName)
			isExist = true;
		it++;
	}
	return isExist;
}

Group User::searchForGroup(string name) {
	list<Group>::iterator it = groups.begin();
	while (name != it->gName) {
		it++;
	}
	return *it;
}

void User::removeGroup(Group userGroup) {

	list<Group>::iterator it = groups.begin();
	while (userGroup.gName != it->gName) {
		it++;
	}
	groups.erase(it);
}

User::~User()
{
}
