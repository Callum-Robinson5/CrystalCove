#include "UserInterface.h"
#include "Map.h"
#include "XP.h"


using namespace HAPI_UI_SPACE;

UserInterface::UserInterface()
{
	Map_Pointer = new Map;
	//UI_AddWindowToListenTo(UI.GetDefaultWindowName());

}

UserInterface::~UserInterface()
{
	delete Map_Pointer; 
}

bool UserInterface::run()
{
	UI.MainWindow()->AddButton("Button1", "Gen Map", EButtonType::eRadio);
	UI.MainWindow()->PositionObjectAgainstWindowEdge("Button1", EDirection::eNorthWest);

	UI.MainWindow()->AddButton("Button2", "Reset", EButtonType::eRadio);
	//UI.MainWindow()->PositionRelativeTo("Button2", "Button1", EDirection::eSouth); // remove the vector and recomment this in for a working version
	HAPISPACE::VectorI test(200, 200);
	UI.MainWindow()->SetScreenPosition(test);
	return true;
}


void UserInterface::UI_RadioButtonChangeState(UIWindow& window, const std::string& buttonName, bool pressed, int* userId)
{
	if (buttonName == "Button1")
	{
		std::cout << "I Work!" << std::endl;
//		m_xp.addXp(100); // won't work, need a pointer from the xp class
	}

	if (buttonName == "Button2")
	{
		std::cout << "I Work too!" << std::endl;
		Map_Pointer->GeneratePath(1);
		// add condition that the player has passed a level
	}

}