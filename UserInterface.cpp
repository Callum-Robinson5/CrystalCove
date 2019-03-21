#include "UserInterface.h"
#include "Map.h"
#include "Worldspace.h"



using namespace HAPI_UI_SPACE;
using namespace HAPISPACE;

UserInterface::UserInterface()
{
	Map_Pointer = new Map;
	world = new Worldspace;
	//tower_AI = new TowerAI;
	//UI_AddWindowToListenTo(UI.GetDefaultWindowName());
}

UserInterface::~UserInterface()
{
	delete Map_Pointer;
	delete world;
	//delete tower_AI;
}




void UserInterface::MainMenuUI()
{
	
	if (loadMenu == true)
	{
		UI.MainWindow()->AddButton("Start", "Start", EButtonType::eRadio);
		HAPISPACE::VectorI ButtonPos(world->GetScreenSize() / 2);
		UI.MainWindow()->SetScreenPosition(ButtonPos);

		UI.MainWindow()->AddButton("Options", "Options", EButtonType::eRadio);
		UI.MainWindow()->PositionRelativeTo("Options", "Start", EDirection::eSouth);

		UI.MainWindow()->AddButton("Exit", "Exit", EButtonType::eRadio);
		UI.MainWindow()->PositionRelativeTo("Exit", "Options", EDirection::eSouth);

	}
	else
	{
		UI.MainWindow()->DeleteObject("Start");
		UI.MainWindow()->DeleteObject("Options");
		UI.MainWindow()->DeleteObject("Exit");
	}

}

void UserInterface::GameUI()
{

	if (loadgameUi == true)
	{
		
		UI.MainWindow()->AddButton("Tower1", "Tower1", EButtonType::eRadio);
		//UI.MainWindow()->PositionObjectAgainstWindowEdge("Tower 1", EDirection::eNorthEast);
		HAPISPACE::VectorI Test(world->GetScreenSize().x -100, 100);
		UI.MainWindow()->SetScreenPosition(Test);

		UI.MainWindow()->AddButton("Tower2", "Tower2", EButtonType::eRadio);
		UI.MainWindow()->PositionRelativeTo("Tower2", "Tower1", EDirection::eSouth);

		UI.MainWindow()->AddButton("Tower3", "Tower3", EButtonType::eRadio);
		UI.MainWindow()->PositionRelativeTo("Tower3", "Tower2", EDirection::eSouth);

		UI.MainWindow()->AddButton("Tower4", "Tower4", EButtonType::eRadio);
		UI.MainWindow()->PositionRelativeTo("Tower4", "Tower3", EDirection::eSouth);

		UI.MainWindow()->AddButton("Tower5", "Tower5", EButtonType::eRadio);
		UI.MainWindow()->PositionRelativeTo("Tower5", "Tower4", EDirection::eSouth);

		UI.MainWindow()->AddButton("Tower6", "Tower6", EButtonType::eRadio);
		UI.MainWindow()->PositionRelativeTo("Tower6", "Tower5", EDirection::eSouth);

		UI.MainWindow()->AddButton("Tower7", "Tower7", EButtonType::eRadio);
		UI.MainWindow()->PositionRelativeTo("Tower7", "Tower6", EDirection::eSouth);

		UI.MainWindow()->AddButton("Tower8", "Tower8", EButtonType::eRadio);
		UI.MainWindow()->PositionRelativeTo("Tower8", "Tower7", EDirection::eSouth);

		UI.MainWindow()->AddButton("Tower9", "Tower9", EButtonType::eRadio);
		UI.MainWindow()->PositionRelativeTo("Tower9", "Tower8", EDirection::eSouth);

		UI.MainWindow()->AddButton("Tower10", "Tower10", EButtonType::eRadio);
		UI.MainWindow()->PositionRelativeTo("Tower10", "Tower9", EDirection::eSouth);
	}
	else
	{
		UI.MainWindow()->DeleteObject("Tower1");
		UI.MainWindow()->DeleteObject("Tower2");
		UI.MainWindow()->DeleteObject("Tower3");
		UI.MainWindow()->DeleteObject("Tower4");
		UI.MainWindow()->DeleteObject("Tower5");
		UI.MainWindow()->DeleteObject("Tower6");
		UI.MainWindow()->DeleteObject("Tower7");
		UI.MainWindow()->DeleteObject("Tower8");
		UI.MainWindow()->DeleteObject("Tower9");
		UI.MainWindow()->DeleteObject("Tower10");
	}

}

void UserInterface::UI_RadioButtonChangeState(UIWindow& window, const std::string& buttonName, bool pressed, int* userId)
{
	//Main Menu
	
	if (buttonName == "Start")
	{
		std::cout << "Starting Game" << std::endl;
		// run the game code from worldspace
		Map_Pointer->GeneratePath(1);
		loadMenu = false;
		loadgameUi = true;
		
	}

	if (buttonName == "Options")
	{
		std::cout << "Loading Options" << std::endl;
		// make optional buttons appear (for example; music volume)
		loadMenu = false;
		UI.MainWindow()->AddButton("Test", "Test", EButtonType::eRadio);
		UI.MainWindow()->PositionRelativeTo("Test", "Start", EDirection::eSouth);
		//add music volume button
		//fullscreen / resolution
		//credits
		world->ResetFile();

	}

	if (buttonName == "Exit")
	{
		std::cout << "Exiting Game" << std::endl;
		loadMenu = false;
		HAPI_Sprites.Close(); //exits HAPI
	}

	//In game UI

	if (buttonName == "Tower1")
	{
		std::cout << "Tower 1 successfully placed" << std::endl;
		tower1 = true;
	}

	if (buttonName == "Tower2")
	{
		std::cout << "Tower 2 successfully placed" << std::endl;
	}

	if (buttonName == "Tower3")
	{
		std::cout << "Tower 3 successfully placed" << std::endl;
	}

	if (buttonName == "Tower 4")
	{
		std::cout << "Tower 4 successfully placed" << std::endl;
	}

	if (buttonName == "Tower 5")
	{
		std::cout << "Tower 5 successfully placed" << std::endl;
	}

	if (buttonName == "Tower 6")
	{
		std::cout << "Tower 6 successfully placed" << std::endl;
	}

	if (buttonName == "Tower 7")
	{
		std::cout << "Tower 7 successfully placed" << std::endl;
	}

	if (buttonName == "Tower 8")
	{
		std::cout << "Tower 8 successfully placed" << std::endl;
	}

	if (buttonName == "Tower 9")
	{
		std::cout << "Tower 9 successfully placed" << std::endl;
	}

	if (buttonName == "Tower 10")
	{
		std::cout << "Tower 10 successfully placed" << std::endl;
	}
}


