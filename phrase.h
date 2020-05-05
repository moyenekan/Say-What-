#pragma once
#include <string>
#include <map>

using namespace std;

class phrase
{	
private:
	//declare varaibles to store word
	string storeWord;
	// number for menu
	int number;
// Map to lookup the index of alphabets 
	map <char, int> find1;
	// Map to lookup alphabets corresponding 
	// to the index after shift 
	map <int, char> find2;

public:
	// member calling
	string wordReverse(string str);
	string encrypt(string message, int shift);
	string decrypt(string message, int shift);
	string ToUppercase(string sentence);
	void sortSentence(string sentences);
	int menu();
	void create_dict();


};

