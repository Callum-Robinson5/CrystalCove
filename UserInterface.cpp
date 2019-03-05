#include "UserInterface.h"

using namespace HAPI_UI_SPACE;

UserInterface::UserInterface()
{
	
	//UI_AddWindowToListenTo(UI.GetDefaultWindowName());
}


UserInterface::~UserInterface()
{
}

bool UserInterface::run()
{
	Map map;
	UI.MainWindow()->AddButton("Button1", "Gen Map", EButtonType::eRadio);
	UI.MainWindow()->PositionObjectAgainstWindowEdge("Button1", EDirection::eNorth);

	//UI.MainWindow()->AddButton("Button2", "Reset", EButtonType::eRadio);
	//UI.MainWindow()->PositionRelativeTo("Button2", "Button1", EDirection::eSouth);

	return true;
}


void UserInterface::UI_RadioButtonChangeState(UIWindow& window, const std::string& buttonName, bool pressed, int* userId)
{
	if (buttonName == "Button1")
	{
		std::cout << "Functions dont work lol" << std::endl;
		m_xp.addXp(100);
		map.GeneratePath(1);
	}
}