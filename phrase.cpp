#include "phrase.h"
#include <string>
#include <algorithm>
#include <iostream>
#define MAX 100
using namespace std;


string  phrase::wordReverse(string str)
{
	int i = str.size() - 1;
	int start;
	int end = i + 1;
	string result = "";

	while (i >= 0)
	{
		if (str[i] == ' ')
		{
			start = i + 1;
			while (start != end)
				result += str[start++];

			result += ' ';

			end = i;
		}
		i--;
	}
	start = 0;
	while (start != end)
		result += str[start++];

	return result;
}


// Funciton to create map to lookup 
void phrase::create_dict()
{
	for (int i = 1; i < 27; i++)
		find1[char(64 + i)] = i;

	find2[0] = 'Z';

	for (int i = 1; i < 26; i++)
		find2[i] = char(64 + i);

	return;
}

// Function to encrypt the string 
// according to the shift provided 
string phrase::encrypt(string message, int shift)
{
	string cipher = "";
	for (int i = 0; i <message.size(); i++)
	{
		// Checking for namespace 
		if (message[i] != ' ')
		{
			// loooks up the map and 
			// adds the shift to the index 
			int num = (find1[message[i]] + shift) % 26;

			// looks up the second map for the 
			// shifted alphabets and adds them 
			cipher += find2[num];
		}
		else
		{
			// adds space 
			cipher += " ";
		}
	}
	return cipher;
}

// Function to decrypt the string 
// according to the shift provided 
string phrase::decrypt(string message, int shift)
{
	string decipher = "";
	for (int i = 0; i<message.size(); i++)
	{
		// checks for space 
		if (message[i] != ' ')
		{
			// looks up the map and 
			// subtracts the shift to the index 
			int num = (find1[message[i]] - shift + 26) % 26;
			// looks up the second map for the 
			// shifted alphabets and adds them 
			decipher += find2[num];
		}
		else
		{
			// adds space 
			decipher += " ";
		}
	}
	return decipher;
}

// changing word to upper case letter
string phrase::ToUppercase(string sentence) 
{
	transform(sentence.begin(), sentence.end(), sentence.begin(), ::toupper);
	return sentence;
 }

// To sort out the words
void phrase::sortSentence(string sentences) {
	// Add space to the end of the original message
	sentences = sentences + " ";
	//declare varaibles to store word
	string words[MAX];
	int numberOfWords = 0;
	 //loop till the end of the parameter
	for (int i = 0; i<sentences.size(); i++) { 
		// checks if the chracter is space or aphabet
		if (sentences.at(i) != ' ')
			//add character to storeword
			storeWord += sentences.at(i);
		else
		{
			words[numberOfWords++] = storeWord;
		storeWord = "";
	}
	}
//Loops till number of words
	for (int p=0;p< numberOfWords;p++)
		{
			// Loops till number of words minus outer loop variable value minus one
			// Minus outer loop value because after each iteration one word is sorted
			for (int z = 0; z < numberOfWords - p - 1; z++)
			{
				// Checks if word at z index position is greater than the word at (z + 1) index position
				if (words[z] > words[z + 1])
				{
					// Swap the word
					storeWord = words[z];
					words[z] = words[z + 1];
					words[z + 1] = storeWord;
				}
			}
		}

		// Loops till number of words
	for (int r = 0; r < numberOfWords; r++)
		// Displays each word
		cout << words[r] << " ";
}// End of sort function

// menu 
int phrase::menu() {
	cout << "\nEnter 1 to decrypt the phrase using Rot 13 (New Phrase)" << endl;
	cout << "Enter 2 to reverse the words in a phrase" << endl;
	cout << "Enter 3 to sort the words within the phrase in ascending order" << endl;
	cout << "Enter 4 to encrypt the phrse using Rot 13" << endl;
	cout << "Enter 5 to Exit\n";
	cout << "choice: ";
	cin >> number;
	return number;
}




