#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;


// ----------------- MAIN ---------------- //
int main()
{
	// Name of file
	string path = "Users.txt";

	fstream fs;
	// We can read and write without clearing information 
	fs.open(path, fstream::in | fstream::out | fstream::app);

	// Variables
	string userName, password, buffUserName, buffPassword;
	int value = 0;
	bool validation = false;

	// Checking if did not open
	if (!fs.is_open())
	{
		cout << "Failed connection" << endl;
	}
	else
	{
		// If open. Main loop
		do
		{
			cout << "Success connection!" << endl;
			cout << "Input 1 if you want to registrate" << endl;
			cout << "Input 2 if you want to login\n\n";
			cout << "Input: "; cin >> value;

			// Registration
			if (value == 1)
			{
				cout << "---------- Registration -----------\n";
				// Username
				cout << "Username:\t";
				cin >> userName;
				fs << userName << "\n";

				// Password
				cout << "\nPassword:\t";
				cin >> password;
				fs << password << "\n";

				Sleep(500);
				cout << "\nSuccess registration!" << endl;
				validation = true;
			}

			// Login
			else if (value == 2)
			{
				cout << "------------- Login --------------\n";
				// Username
				cout << "Username:\t";
				cin >> userName;

				// Password
				cout << "\nPassword:\t";
				cin >> password;

				cout << "\nChecking the data";
				Sleep(500);
				cout << ".";
				Sleep(500);
				cout << ".";
				Sleep(500);
				cout << "." << endl;
				Sleep(500);
				// Reading the file. Reading the current line in file and write it in the buffer variable 
				while (!fs.eof())
				{
					buffUserName = "";
					fs >> buffUserName;

					buffPassword = "";
					fs >> buffPassword;
					// If data in buffer equal inputed data -> Success
					if (buffUserName == userName && buffPassword == password)
					{
						cout << "Success!" << endl;
						validation = true;
					}
				}
				// If data in buffer not equal inputed data -> Fail
				if (validation == false)
				{
					cout << "Login failed" << endl;
					value = 0;
					// Asking about retry
					cout << "Do you want to retry?" << endl;
					cout << "\n1 - Yes\t2 - No" << endl;
					cout << "Input: "; cin >> value;
					
					if (value == 2) validation = true;
				}

			}
			else{
				cout << "Invalid input";
				validation = true;
			}

		// Loop will be run endlessly until user register or logged or not retry
		} while (validation == false);

	}
	// Don't forget to close the file :)
	fs.close();

	return 0;
}
