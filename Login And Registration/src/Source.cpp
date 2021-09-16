#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#define CONSOLE(x) std::cout << x << std::endl
#define LOG(x) std::cout << x

class application 
{
	std::string name, password, text;
	void saving_registration() {
		// open file
		std::ofstream file("res/database.txt", std::ios::app);
		text = name + "," + password + "\n";
		file << text;
		file.close();
	}
	bool credential_validator() {
		 std::string checks = name + "," + password;
		 std::ifstream file("res/database.txt", std::ios::in);
		 while (std::getline(file, text))
		 {
		 	if (text == checks)
		 	{
		 		return true;
		 	}
		 }
		 return false;
	}
public:

	void clear()
	{
		system("cls");
	}
	int menu() 
	{
		int choices;
		CONSOLE("1. Registration");
		CONSOLE("2. Login");
		CONSOLE("Enter any value other than these to exit");
		std::cin >> choices;
		clear();
		return choices;
	}
	void registration()
	{
		std::cin.ignore();
		LOG("Your name: ");
		std::getline(std::cin, name);
		LOG("Your password: ");
		std::getline(std::cin, password);
		saving_registration();
	}
	void login_menu()
	{
		std::cin.ignore();
		LOG("Name: ");
		std::getline(std::cin, name);
		LOG("Password: ");
		std::getline(std::cin, password);
		if (credential_validator())
		{
			CONSOLE("You logged in");
			std::cin.get();
		}
		else {
			std::string answer;
			clear();
			CONSOLE("We can't find oyu in our database");
			CONSOLE("Would you like to create your account? (y/n)");
			std::cin >> answer;
			if (answer == "y")
			{
				clear();
				registration();
			}
		}
	}
};

int main() 
{
	application mainProgram;
starting:
	mainProgram.clear();
	switch (mainProgram.menu())
	{
	case 1:
		mainProgram.registration();
		goto starting;
		break;
	case 2:
		mainProgram.login_menu();
		goto starting;
		break;
	default:
		break;
	}
}