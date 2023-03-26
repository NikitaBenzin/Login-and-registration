#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;


// ----------------- MAIN ---------------- //
int main()
{
	string path = "Users.txt";

	fstream fs;

	fs.open(path, fstream::in | fstream::out | fstream::app);

	string userName, password, buffUserName, buffPassword;
	int value = 0;
	bool validation = false;

	if (!fs.is_open())
	{
		cout << "Failed connection" << endl;
	}
	else
	{
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

				while (!fs.eof())
				{
					buffUserName = "";
					fs >> buffUserName;

					buffPassword = "";
					fs >> buffPassword;

					if (buffUserName == userName && buffPassword == password)
					{
						cout << "Success!" << endl;
						validation = true;
					}
				}

				if (validation == false)
				{
					cout << "Login failed" << endl;
					value = 0;
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

		} while (validation == false);

	}

	fs.close();

	return 0;
}