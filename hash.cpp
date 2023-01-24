#include <bits/stdc++.h>
using namespace std;
const int MAX = 200;
class HashNode
{
public:
	int key;
	int value;
	HashNode(int key, int value)
	{
		this->key = key;
		this->value = value;
	}
};
class Dictionary
{
private:
	HashNode **t;

public:
	Dictionary()
	{
		t = new HashNode *[MAX];
		for (int i = 0; i < MAX; i++)
		{
			t[i] = NULL;
		}
	}
	~Dictionary()
	{
		for (int i = 0; i < MAX; i++)
		{
			if (t[i] != NULL)
				delete t[i];
			delete[] t;
		}
	}
	int hashfunc(int key);
	void insertion(int key, int value);
	int search(int key);
	void deletion(int key);
};
int Dictionary::hashfunc(int key)
{
	return key % MAX;
}
void Dictionary::insertion(int key, int value)
{
	int h = hashfunc(key);
	while (t[h] != NULL && t[h]->key != key)
	{
		h = hashfunc(h + 1);
	}
	if (t[h] != NULL)
		delete t[h];
	t[h] = new HashNode(key, value);
}
int Dictionary::search(int key)
{
	int h = hashfunc(key);
	while (t[h] != NULL && t[h]->key != key)
	{
		h = hashfunc(h + 1);
	}

	if (t[h] == NULL)
		return -1;
	else
		return t[h]->value;
}
void Dictionary::deletion(int key)
{
	int h = hashfunc(key);
	while (t[h] != NULL)
	{
		if (t[h]->key == key)
			break;
		h = hashfunc(h + 1);
	}
	if (t[h] == NULL)
	{
		cout << "No element at key " << key << endl;
		return;
	}
	else
	{
		delete t[h];
	}
	cout << "Element has been deleted" << endl;
}
int main()
{
	Dictionary dict;
	int key, value;
	int ch;
	while (1)
	{
		cout << "\nEnter\n1. Insert\n2. Search\n3. Delete\n4.Exit\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\nEnter element to be inserted: ";
			cin >> value;
			cout << "Enter the key at which the element is to be inserted: ";
			cin >> key;
			dict.insertion(key, value);
			break;
		case 2:
			cout << "\nEnter the key of the element to be searched: ";
			cin >> key;
			if (dict.search(key) == -1)
			{
				cout << "No element found at key " << key << endl;
				continue;
			}
			else
			{
				cout << "Element at key " << key << " is: ";
				cout << dict.search(key) << endl;
			}
			break;
		case 3:
			cout << "\nEnter key of the Element to be deleted: ";
			cin >> key;
			dict.deletion(key);
			break;
		case 4:
			exit(1);
		default:
			cout << "\nInvalid Choice!\n";
		}
	}
	return 0;
}
