#include "UserInterface.h"
#include "Map.h"
#include "Worldspace.h"




using namespace HAPI_UI_SPACE;

UserInterface::UserInterface()
{
	Map_Pointer = new Map;
	world = new Worldspace;
	//UI_AddWindowToListenTo(UI.GetDefaultWindowName());
}

UserInterface::~UserInterface()
{
	delete Map_Pointer;
	delete world;
}

bool UserInterface::Run()
{
	

	
	UI.MainWindow()->AddButton("Button1", "Gen Map", EButtonType::eRadio);
	UI.MainWindow()->PositionObjectAgainstWindowEdge("Button1", EDirection::eNorthWest);

	HAPISPACE::VectorI test(world->GetScreenSize()/2);
	UI.MainWindow()->SetScreenPosition(test);

	UI.MainWindow()->AddButton("Button2", "Reset", EButtonType::eRadio);
	UI.MainWindow()->PositionRelativeTo("Button2", "Button1", EDirection::eSouth); // remove the vector and recomment this in for a working version
	
	return true;
}

bool UserInterface::MainMenuUI()
{
	
	UI.MainWindow()->AddButton("Start", "Start", EButtonType::eRadio);
	HAPISPACE::VectorI ButtonPos(world->GetScreenSize() / 2);
	UI.MainWindow()->SetScreenPosition(ButtonPos);

	UI.MainWindow()->AddButton("Options", "Options", EButtonType::eRadio);
	UI.MainWindow()->PositionRelativeTo("Options", "Start", EDirection::eSouth);

	UI.MainWindow()->AddButton("Exit", "Exit", EButtonType::eRadio);
	UI.MainWindow()->PositionRelativeTo("Exit", "Options", EDirection::eSouth);

	return true;
}


void UserInterface::UI_RadioButtonChangeState(UIWindow& window, const std::string& buttonName, bool pressed, int* userId)
{
	//Main Menu
	
	if (buttonName == "Start")
	{
		std::cout << "Starting Game" << std::endl;
		// run the game code from worldspace
	}

	if (buttonName == "Options")
	{
		std::cout << "Loading Options" << std::endl;
		// make optional buttons appear (for example; music volume)
	}

	if (buttonName == "Exit")
	{
		std::cout << "Exiting Game" << std::endl;
		ExitGame(); // doesnt work rn

	}


	//In game UI

	if (buttonName == "Button1")
	{
		std::cout << "I Work!" << std::endl;
	}

	if (buttonName == "Button2")
	{
		std::cout << "I Work too!" << std::endl;
		Map_Pointer->GeneratePath(1);
		// add condition that the player has passed a level
	}

}

int UserInterface::ExitGame()
{
	return 0;
}

