#include "UserInterface.h"
#include "Map.h"
#include "Worldspace.h"

using namespace HAPI_UI_SPACE;
using namespace HAPISPACE;

UserInterface::UserInterface()
{
	Map_Pointer = new Map;
	World_Pointer = new Worldspace;
	//UI_AddWindowToListenTo(UI.GetDefaultWindowName());
}

UserInterface::~UserInterface()
{
	delete Map_Pointer;
	delete World_Pointer;
}


void UserInterface::MainMenuUI()
{
	
	if (loadMenu == true && test1 == true)
	{
		UI.MainWindow()->AddButton("Start", "Start", EButtonType::eRadio);
		HAPISPACE::VectorI ButtonPos(World_Pointer->GetScreenSize() / 2);
		UI.MainWindow()->SetScreenPosition(ButtonPos);

		UI.MainWindow()->AddButton("Options", "Options", EButtonType::eRadio);
		UI.MainWindow()->PositionRelativeTo("Options", "Start", EDirection::eSouth);

		UI.MainWindow()->AddButton("Exit", "Exit", EButtonType::eRadio);
		UI.MainWindow()->PositionRelativeTo("Exit", "Options", EDirection::eSouth);
		test1 = false;
	}
	else if(loadMenu == false)
	{
		UI.MainWindow()->DeleteObject("Start");
		UI.MainWindow()->DeleteObject("Options");
		UI.MainWindow()->DeleteObject("Exit");
		test1 = true;
	}

}

void UserInterface::GameUI()
{

	if (loadgameUi == true && test == true)
	{

		HAPISPACE::VectorI Test(World_Pointer->GetScreenSize().x - 100, 100);
		UI.MainWindow()->SetScreenPosition(Test);

		UI.MainWindow()->AddButtons({
			{"Button 4", "550"},
			{"Button 2", "250"},
			{"Button 3", "400"},
			{"Button 1", "100" },
			}, "Text", EDirection::eSouth, 1, EAlignment::eAlignMidToMid);

		std::shared_ptr<ImageFill> PaintS = std::make_shared<ImageFill>("Data\\Towers\\Paint Slinger.png", EImageFillMode::eScale);
		std::shared_ptr<ImageFill> PaintT = std::make_shared<ImageFill>("Data\\Towers\\Paint Thrower.png", EImageFillMode::eScale);
		std::shared_ptr<ImageFill> PaintAd = std::make_shared<ImageFill>("Data\\Towers\\Paintadier.png", EImageFillMode::eScale);
		std::shared_ptr<ImageFill> PaintTil = std::make_shared<ImageFill>("Data\\Towers\\Painttillary.png", EImageFillMode::eScale);

		UI.MainWindow()->GetSkin().AddShaderToPalette("Paint Slinger", PaintS);
		UI.MainWindow()->GetSkin().AddShaderToPalette("Paint Thrower", PaintT);
		UI.MainWindow()->GetSkin().AddShaderToPalette("Paintadier", PaintAd);
		UI.MainWindow()->GetSkin().AddShaderToPalette("Painttillary", PaintTil);

		UiWindowStyleGroup UIstyle = UI.MainWindow()->GetSkin().GetWindowStyleGroup(ESkinStyle::eButton);

		UIstyle.SetBackgroundShader(ESkinSubStyle::eNormal, "Paint Slinger");
		UIstyle.SetBackgroundShader(ESkinSubStyle::eNormal, "Paint Thrower");
		UIstyle.SetBackgroundShader(ESkinSubStyle::eNormal, "Paintadier");
		UIstyle.SetBackgroundShader(ESkinSubStyle::eNormal, "Painttillary");

		UI.MainWindow()->GetObject("Button 1")->SetWindowStyleGroupSettings(UIstyle);				
		UIstyle.SetBackgroundShader(ESkinSubStyle::eNormal, "Paint Slinger");

		UI.MainWindow()->GetObject("Button 2")->SetWindowStyleGroupSettings(UIstyle);
		UIstyle.SetBackgroundShader(ESkinSubStyle::eNormal, "Paint Thrower");

		UI.MainWindow()->GetObject("Button 3")->SetWindowStyleGroupSettings(UIstyle);
		UIstyle.SetBackgroundShader(ESkinSubStyle::eNormal, "Paintadier");

		UI.MainWindow()->GetObject("Button 4")->SetWindowStyleGroupSettings(UIstyle);
		UIstyle.SetBackgroundShader(ESkinSubStyle::eNormal, "Painttillary");


		test = false;
	} 
	else if(loadgameUi == false)
	{
		UI.MainWindow()->DeleteObject("Tower1");
		UI.MainWindow()->DeleteObject("Tower2");
		UI.MainWindow()->DeleteObject("Tower3");
		UI.MainWindow()->DeleteObject("Tower4");
		test = true;
	}

}

void UserInterface::UI_RadioButtonChangeState(UIWindow& window, const std::string& buttonName, bool pressed, int* userId)
{
	//Main Menu
	
	if (buttonName == "Start")//runs the game code from worldspace
	{
		std::cout << "Starting Game" << std::endl;
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
		World_Pointer->ResetFile();

	}

	if (buttonName == "Exit")//exits HAPI
	{
		std::cout << "Exiting Game" << std::endl;
		loadMenu = false;
		HAPI_Sprites.Close(); 
	}

	//In game UI

	if (buttonName == "Tower 1")
	{
		std::cout << "Tower 1 successfully placed" << std::endl;
	}

	if (buttonName == "Tower 2")
	{
		std::cout << "Tower 2 successfully placed" << std::endl;
	}

	if (buttonName == "Tower 3")
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


