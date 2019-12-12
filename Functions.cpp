#include "Functions.h"
#include "Includes.h"


void Introduction()
{
	char user_name[100];
	cout << " Welcome, " << endl;
	sleep(2);
	cout << " Enter player name\n" << endl;
	cin.getline(user_name, sizeof(user_name));
	cout << "\n Come " << user_name << ",\n The pleasure is yours to have met me" << endl;
}

void Instructions()
{
	cout << " Want to play a Game" << endl;
	cout <<	" I will think of a word and you must guess the letters that make up said word"<< endl;
	cout << " Are you ready to begin?" << endl;
	string ReadyToPlay;
	cin >> ReadyToPlay;
	if (ReadyToPlay == "y")
	{
		PlayGame();
	}
	if (ReadyToPlay == "Y")
	{
		PlayGame();
	}
	else if (ReadyToPlay == "yes")
	{
		PlayGame();
	}
	else if (ReadyToPlay == "YES")
	{
		PlayGame();
	}
	else if (ReadyToPlay == "n")
	{
		cout << "Well too bad, Your going to anyway" << endl;
		PlayGame();
	}
	else if (ReadyToPlay == "N")
	{
		cout << "Well too bad, Your going to anyway" << endl;
		PlayGame();
	}
	else if (ReadyToPlay == "no")
	{
		cout << "Well too bad, Your going to anyway" << endl;
		PlayGame();
	}
	else if (ReadyToPlay == "NO")
	{
		cout << "Well too bad, Your going to anyway" << endl;
		PlayGame();
	}
	else
	{
		cout << "Input Y or N... Its not that hard" << endl;
		cin >> ReadyToPlay;
	}
}


void PlayGame()
{
	const int MAX_WRONG = 6;

	// Collection of words
	vector<string> words;
	words.emplace_back("college");
	words.emplace_back("university");
	words.emplace_back("coding");
	words.emplace_back("school");
	words.emplace_back("final");
	words.emplace_back("project");
	words.emplace_back("bachelor");
	words.emplace_back("networking");
	words.emplace_back("degree");
	words.emplace_back("graduate");

	int wrong = 0; // number of incorrect guesses
	for (int i = 0; i < 6; ++i)
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		random_shuffle(words.begin(), words.end());
		const string THE_WORD = words[0]; // word to guess

		string soFar(THE_WORD.size(), '-'); // word guessed so far
		string used = ""; // letters already guessed

		// While the player hasn't made too many incorrect guesses and hasn't guessed the secret word
		while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
		{
			//     Tell player how many incorrect guesses he or she has left	
			cout << "\nYou have " << (MAX_WRONG - wrong);
			cout << " incorrect guesses left.\n";

			//     Show player the letters he or she has guessed
			cout << "\nYou've used the following letters:\n" << used << endl;

			//     Show player how much of the secret word he or she has guessed
			cout << "\nSo far, the word is:\n" << soFar << endl;

			//     Get player's next guess
			char guess;
			cout << "\n\nPlease guess a letter: ";
			cin >> guess;
			guess = tolower(guess); //make lowercase since secret word is lowercase


			//     While player has entered a letter that he or she has already guessed
			while (used.find(guess) != string::npos)
			{
				cout << "\nYou've already guessed " << guess << endl;

				//          Get player's guess
				cout << "\nPlease guess a letter: ";
				cin >> guess;
				guess = tolower(guess);
			}

			//     Add the new guess to the group of used letters
			used += guess;

			//     If the guess is in the secret word
			if (THE_WORD.find(guess) != string::npos)
			{
				//          Tell the player the guess is correct
				cout << "\nThat's right! " << guess << " is in the word.\n";

				//          Update the word guessed so far with the new letter
				for (unsigned int i = 0; i < THE_WORD.length(); ++i)
				{
					if (THE_WORD[i] == guess)
					{
						soFar[i] = guess;
					}
				}
			}

			//     Otherwise
			else
			{
				//          Tell the player the guess is incorrect
				cout << "\nSorry, " << guess << " isn't in the word.\n";

				//          Increment the number of incorrect guesses the player has made
				++wrong;
			}
			// If the player has made too many incorrect guesses
			if (wrong == MAX_WRONG)

			//     Tell the player GAME OVER
			cout << "\nGAME OVER!";
			cout << "\nThe word was " << THE_WORD << endl;
		}

		
		// Ask the player if they would like to play again
		string playAgain;
		cout << "Would you like to play again? Y/N" << endl;
		cin >> playAgain;

		// If the player wants to play again
		while (true) {
			if (playAgain == "y")
			{
				PlayGame();
			}
			if (playAgain == "Y")
			{
				PlayGame();
			}
			else if (playAgain == "yes")
			{
				PlayGame();
			}
			else if (playAgain == "YES")
			{
				PlayGame();
			}
			else if (playAgain == "n")
			{
				cout << "Thanks for playing!" << endl;
				sleep(2);
				exit(0);
			}
			else if (playAgain == "N")
			{
				cout << "Thanks for playing!" << endl;
				sleep(2000);
				exit(0);
			}
			else if (playAgain == "no")
			{
				cout << "Thanks for playing!" << endl;
				sleep(2000);
				exit(0);
			}
			else if (playAgain == "NO")
			{
				cout << "Thanks for playing!" << endl;
				sleep(2000);
				exit(0);
			}
			else
			{
				cout << "Please input Y or N..." << endl;
				cin >> playAgain;
			}
		}
	}
}

	


/*
………………….._,,-~’’’¯¯¯’’~-,,
………………..,-‘’ ; ; ;_,,---,,_ ; ;’’-,…………………………….._,,,---,,_
……………….,’ ; ; ;,-‘ , , , , , ‘-, ; ;’-,,,,---~~’’’’’’~--,,,_…..,,-~’’ ; ; ; ;__;’-,
……………….| ; ; ;,’ , , , _,,-~’’ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ¯’’~’-,,_ ,,-~’’ , , ‘, ;’,
……………….’, ; ; ‘-, ,-~’’ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;’’-, , , , , ,’ ; |
…………………’, ; ;,’’ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;’-, , ,-‘ ;,-‘
………………….,’-‘ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;’’-‘ ;,,-‘
………………..,’ ; ; ; ; ; ; ; ; ; ; ; ;__ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ‘-,’
………………,-‘ ; ; ; ; ; ; ; ; ; ;,-‘’¯: : ’’-, ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; _ ; ; ; ; ;’,
……………..,’ ; ; ; ; ; ; ; ; ; ; ;| : : : : : :| ; ; ; ; ; ; ; ; ; ; ; ; ,-‘’¯: ¯’’-, ; ; ;’,
…………….,’ ; ; ; ; ; ; ; ; ; ; ; ‘-,_: : _,-‘ ; ; ; ; ; ; ; ; ; ; ; ; | : : : : : :| ; ; ; |
……………,’ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ¯¯ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;’-,,_ : :,-‘ ; ; ; ;|
…………..,-‘ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ,,-~’’ , , , , ,,,-~~-, , , , _ ; ; ;¯¯ ; ; ; ; ;|
..…………,-‘ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;,’ , , , , , , ,( : : : : :) , , , ,’’-, ; ; ; ; ; ; ; ;|
……….,-‘ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;’, , , , , , , , ,’~---~’’ , , , , , ,’ ; ; ; ; ; ; ; ;’,
…….,-‘’ ; _, ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ‘’~-,,,,--~~’’’¯’’’~-,,_ , ,_,-‘ ; ; ; ; ; ; ; ; ; ‘,
….,-‘’-~’’,-‘ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; | ; ; | . . . . . . ,’; ,’’¯ ; ; ; ; ; ; ; ; ; ,_ ; ‘-,
……….,’ ; ;,-, ; ;, ; ; ;, ; ; ; ; ; ; ; ; ; ; ‘, ; ;’, . . . . .,’ ;,’ ; ; ; ;, ; ; ;,’-, ; ;,’ ‘’~--‘’’
………,’-~’ ,-‘-~’’ ‘, ,-‘ ‘, ,,- ; ; ; ; ; ; ; ; ‘, ; ; ‘~-,,,-‘’ ; ,’ ; ; ; ; ‘, ;,-‘’ ; ‘, ,-‘,
……….,-‘’ ; ; ; ; ; ‘’ ; ; ;’’ ; ; ; ; ; ; ; ; ; ; ‘’-,,_ ; ; ; _,-‘ ; ; ; ; ; ;’-‘’ ; ; ; ‘’ ; ;’-,
……..,-‘ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;¯¯’’¯ ; ; ; ; ; ; ; ; , ; ; ; ; ; ; ; ; ;’’-,
……,-‘ ; ; ; ; ; ; ; ,, ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; |, ; ; ; ; ; ; ; ; ; ; ‘-,
…..,’ ; ; ; ; ; ; ; ;,’ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;|..’-,_ ; ; ; , ; ; ; ; ; ‘,
….,’ ; ; ; ; ; ; ; ; | ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;,’…….’’’,-~’ ; ; ; ; ; ,’
…,’ ; ; ; ; ; ; ; ; ;’~-,,,,,--~~’’’’’’~-,, ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;,’…..,-~’’ ; ; ; ; ; ; ,-
…| ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ‘, ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;,’…,-‘ ; ; ; ; ; ; ; ;,-‘
…’, ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ,-‘ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ,’….’, ; ; ; ; _,,-‘’
….’, ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ,-‘’ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;,’…….’’~~’’¯
…..’’-, ; ; ; ; ; ; ; ; ; ; ; ; ; ;_,,-‘’ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ,-‘
………’’~-,,_ ; ; ; ; _,,,-~’’ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;,-‘
………..| ; ; ;¯¯’’’’¯ ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;,,-‘
………..’, ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;,-‘
…………| ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;|
…………’, ; ; ; ; ; ; ; ; ; ~-,,___ ; ; ; ; ; ; ; ; ; ; ; ; ; ;’,
………….’, ; ; ; ; ; ; ; ; ; ; ;,-‘….’’-, ; ; ; ; ; ; ; ; ; ; ; ; ‘,
………..,’ ‘- ; ; ; ; ; ; ; ; ;,-‘’……….’-, ; ; ; ; ; ; ; ; ; ; ; ‘,
……….,’ ; ;’ ; ; ; ; ; ; ,,-‘…………….’, ; ; ; ; ; ; ; ; ; ; ;’,
………,’ ; ; ; ; ; ; ; ;,-‘’…………………’’-, ; ; ; ; ; ; ; ; ; |
……..,’ ; ; ; ; ; ; ;,,-‘………………………’’, ; ; ; ; ; ; ; ; |
……..| ; ; ; ; ; ; ;,’…………………………,’ ; ; ; ; ; ; ; ;,’
……..| ; ; ; ; ; ; ,’………………………..,-‘ ; ; ; ; ; ; ; ,’’
……..| ; ; ; ; ; ;,’……………………….,-‘ ; ; ; ; ; ; ; ,-‘
……..’,_ , ; , ;,’……………………….,’ ; ; ; ; ; ; ; ,-‘
………’,,’,¯,’,’’|……………………….| ; ; ; ; ; ; ; ; ‘--,,
………….¯…’’………………………..’-, ; ; ; ; ; ; ; ; ; ;’’~,,
……………………………………………’’-,, ; ; ; ; ; ; ; ; ; ;’’~-,,
………………………………………………..’’-, ; ; ; ; ; ,,_ ; ;’-,’’-,
…………………………………………………..’, ; ; ; ; ; ; ‘-,__,\\--\\.
……………………………………………………’-, ; ; ;,,-~’’’ \\ , ,|, |
………………………………………………………’’~-‘’_ , , ,,’,_/--‘

. . . .. . . . . . . . . . . ,.-‘”. . . . . . . . . .``~.,
. . . . . . . .. . . . . .,.-”. . . . . . . . . . . . . . . . . .“-.,
. . . . .. . . . . . ..,/. . . . . . . . . . . . . . . . . . . . . . . ”:,
. . . . . . . .. .,?. . . . . . . . . . . . . . . . . . . . . . . . . . .\,
. . . . . . . . . /. . . . . . . . . . . . . . . . . . . . . . . . . . . . ,}
. . . . . . . . ./. . . . . . . . . . . . . . . . . . . . . . . . . . ,:`^`.}
. . . . . . . ./. . . . . . . . . . . . . . . . . . . . . . . . . ,:”. . . ./
. . . . . . .?. . . __. . . . . . . . . . . . . . . . . . . . :`. . . ./
. . . . . . . /__.(. . .“~-,_. . . . . . . . . . . . . . ,:`. . . .. ./
. . . . . . /(_. . ”~,_. . . ..“~,_. . . . . . . . . .,:`. . . . _/
. . . .. .{.._$;_. . .”=,_. . . .“-,_. . . ,.-~-,}, .~”; /. .. .}
. . .. . .((. . .*~_. . . .”=-._. . .“;,,./`. . /” . . . ./. .. ../
. . . .. . .\`~,. . ..“~.,. . . . . . . . . ..`. . .}. . . . . . ../
. . . . . .(. ..`=-,,. . . .`. . . . . . . . . . . ..(. . . ;_,,-”
. . . . . ../.`~,. . ..`-.. . . . . . . . . . . . . . ..\. . /\
. . . . . . \`~.*-,. . . . . . . . . . . . . . . . . ..|,./.....\,__
,,_. . . . . }.>-._\. . . . . . . . . . . . . . . . . .|. . . . . . ..`=~-,
. .. `=~-,_\_. . . `\,. . . . . . . . . . . . . . . . .\
. . . . . . . . . .`=~-,,.\,. . . . . . . . . . . . . . . .\
. . . . . . . . . . . . . . . . `:,, . . . . . . . . . . . . . `\. . . . . . ..__
. . . . . . . . . . . . . . . . . . .`=-,. . . . . . . . . .,%`>--==``
. . . . . . . . . . . . . . . . . . . . _
*/