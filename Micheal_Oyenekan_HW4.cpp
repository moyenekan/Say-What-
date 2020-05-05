#include<iostream>
#include "phrase.h"



using namespace std;


// Driver code 
int main()
{
	phrase Phrase;


	Phrase.create_dict();

	// store sentences
	string messages;
	// store encrypted sentences
	string encryptString;

	//prompt theuser to enter  a string
	cout << "\n Enter a phrase: ";
	getline(cin, messages);
	
	
	// Caliing the function to convert to upper case
	messages = Phrase.ToUppercase(messages);
	// calling the function to encrypt 
	int shift=13;
encryptString = Phrase.encrypt(messages, shift);
	// loop until the user enter 5 to end the program
	do
	{
		// Calls the function menu() to accept user choice
		switch (Phrase.menu())
		{	
		case 1:
			// Calling the function to decrypt the message and displays it
			cout << "\n New Phrase: " <<Phrase.decrypt(encryptString, shift);
			break;
		case 2:
			// Calling the function to reverse each word in the phrase
			cout << "\n Original message: " << messages;
			cout << "\n Reverse Words:   "<< Phrase.wordReverse(messages);
			break;

		  case 3:
			 
			cout << "\n Original message: " << messages;
			cout << "\n Sorted message: ";
				 // Calling the function to sort words in phrase
			Phrase.sortSentence(messages);
			
			break;
		case 4:
			// Calling the function to encrypt the message and stores the encrypted message
			
			cout << "\n Original message: " << messages;
			cout << "\n Encrypted message: " << encryptString;
			break;
	
		case 5:
			cout << "\n Bye!";
			exit(0);
		default:
			cout << "\n Invalid choice! Re-Enter";
		}
	} while (1);
	return 0;
}
// I got some tutoring and code from a website called Greek Greek