
#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string username;
	string password;
	bool success;

	cout << "\tGame Designer's Network\n";
	do
	{
		cout << "\nUsername: ";
		cin >> username; 

		cout << "Password: ";
		cin >> password; 

		if (username == "Nikita" && password == "civilization")
		{
			cout << "\nHey, Nik.";
			success = true;
		}
		else if (username == "guest" || password == "guest")
		{
			cout << "\nWelcome, guest.";
			success = true;
		}
		else
		{
			cout << "\nYour login failed.";
			success = false;
		}
	} while (!success);

    return 0;
}
