#include <iostream>
#include "Customer.h"
#include "Prescription.h"
#include "GameNameSpace.h"
#include <conio.h>

using namespace std;

#define KEY_A 97
#define KEY_D 100

int main() {

	bool appRunning = true;
	while (appRunning) 
	{
		loadGame();
		gameRunning = true;
		while (gameRunning) 
		{
			switch (_getch())
			{
			case KEY_A:
				system("CLS");
				initGame();
				break;
			case KEY_D:
				system("CLS");
				exit(1);
			default:
				break;
			}
		}
	}
	
	return 0;
}