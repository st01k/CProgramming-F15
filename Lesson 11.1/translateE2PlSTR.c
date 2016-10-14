#include <iomanip>
#include <iostream>
#include <cstring>

//Since those are used in ALL function of program, it wont hurt to set it to global
//Else it is considered EVIL to declare global variables
const int maxLine = 100;
char phraseLine [maxLine] = {'\0'};

void pigLatinString ();

using namespace std;


void main ()
{
	// Displayed heading of program
	cout << "*********************************************" << endl;
	cout << "* You will be prompted to enter a string of *" << endl;
	cout << "* words. The string will be converted into  *" << endl;
	cout << "* Pig Latin and the results displayed.      *" << endl;
	cout << "* Enter as many strings as you would like.  *" << endl;
	cout << "*********************************************" << endl;

	//prompt the user for a group of words or press enter to quit
	cout << "Please enter a word or group of words. (Press enter to quit)\n";
	cin.getline(phraseLine, 100, '\n');
	cout <<endl;

	// This is the main loop. Continue executing until the user hits 'enter' to quit.
	while (phraseLine[0] !='\0')
	{

			// Display the word (s) entered by the user
			cout << "You entered the following: " << phraseLine << endl;

			// Display the word (s) in Pig Latin
			cout << "The same phrase in Pig latin is: ";
                        pigLatinString();
			cout << endl;

			//prompt the user for a group of words or press enter to quit
			cout << "Please enter a word or group of words. (Press enter to quit)\n";
			cin.getline(phraseLine, 100, '\n');
	}
	return;
}


void pigLatinString () //phraseLine is a cstring for the word,  maxline is max length of line
{ //variable declarations
	char tempConsonant [10];
	tempConsonant [0] = '\0';
	int numberOfConsonants = 0;
	char previousCharacter = ' ';
	char currentCharacter = ' ';
	bool isInWord = 0;

	// for loop checking each index to the end of whatever is typed in
	for (int i = 0 ; i < maxLine ; i++)
	{

		//checking for the end of the phraseline
		if ( phraseLine[i] == '\0')
		{//checking to see if it's in the word
			if (isInWord)
			{//checking to see that there wasn't a space ahead of the word and then sending the cstring + ay to the console
				if (previousCharacter != ' ')
					cout << tempConsonant << "ay" << endl;
			}

			return ;
		}

		// this covers the end of the word condition
		if (isInWord)
		{// covers the condition of index [i] being the space at the end of the word
			if (phraseLine [i] == ' ')
			{
				// spits out pig latin word, gets you out of the word, flushes the temp consonants array and resets the # of consonants to 0
				cout << tempConsonant << "ay";
				isInWord = 0;
				tempConsonant [0] = '\0';
				numberOfConsonants = 0;
			}
			cout << phraseLine [i];

		}
		else
		{//this covers for the first vowel that makes the switch
			if (phraseLine[i] != ' ')
			{// sets the c string to what is in the phraseline at the time and makes it capitalized
				char currentCharacter = phraseLine [i];
				currentCharacter = toupper( currentCharacter);

				// this takes care of the condition that currentCharacter is not a vowel
				if ((currentCharacter != 'A') && (currentCharacter != 'E') &&
					(currentCharacter != 'I') && (currentCharacter != 'O') && (currentCharacter != 'U'))
				//this sets the array to temporarily hold the consonants for display before the 'ay'
				{//this sets the null operator at the end of the c string and looks for the next consonant
					tempConsonant [numberOfConsonants] = phraseLine [i];
					tempConsonant [numberOfConsonants + 1] = '\0';
					numberOfConsonants++;
				}
				else
				{// this sets the boolean isInWord to true and displays the phraseline
					isInWord = 1;
					cout << phraseLine[i];
				}
			}
			else
			{
				cout << phraseLine [i];
			}
		}

		previousCharacter = phraseLine[i];
	}
	return ;
}
