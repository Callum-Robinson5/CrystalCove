#include "UserInterface.h"
#include "Map.h"
#include "Worldspace.h"
#include "TowerAI.h"
#include <chrono>
#include <thread>


using namespace HAPI_UI_SPACE;
using namespace HAPISPACE;

UserInterface::UserInterface()
{
	Map_Pointer = new Map;
	World_Pointer = new Worldspace;
	//Tower_Pointer = new TowerAI;
	//UI_AddWindowToListenTo(UI.GetDefaultWindowName());
}

UserInterface::~UserInterface()
{
	delete Map_Pointer;
	delete World_Pointer;
	//delete Tower_Pointer;
}


void UserInterface::MainMenuUI()
{
	
	if (loadMenu == true && test1 == true)
	{
		UI.MainWindow()->AddButton("Start", "Start", EButtonType::eRadio);
		HAPISPACE::VectorI ButtonPos(550,332); //2 pixels make all the difference apparently
		UI.MainWindow()->SetScreenPosition(ButtonPos);

//		UI.MainWindow()->AddButton("Options", "Options", EButtonType::eRadio);
//		UI.MainWindow()->PositionRelativeTo("Options", "Start", EDirection::eSouth);

		UI.MainWindow()->AddButton("Exit", "Exit", EButtonType::eRadio);
		UI.MainWindow()->PositionRelativeTo("Exit", "Start", EDirection::eSouth);
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
	/*
	if (loadgameUi == true && test == true)
	{

		//HAPISPACE::VectorI Test(World_Pointer->GetScreenSize().x - 100, 100);
		//UI.MainWindow()->SetScreenPosition(Test);
		
		UI.MainWindow()->AddButtons({
			{"Tower4", "550"},
			{"Tower2", "250"},
			{"Tower3", "400"},
			{"Tower1", "100" },
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

		UI.MainWindow()->GetObject("Tower1")->SetWindowStyleGroupSettings(UIstyle);
		UIstyle.SetBackgroundShader(ESkinSubStyle::eNormal, "Paint Slinger");

		UI.MainWindow()->GetObject("Tower2")->SetWindowStyleGroupSettings(UIstyle);
		UIstyle.SetBackgroundShader(ESkinSubStyle::eNormal, "Paint Thrower");

		UI.MainWindow()->GetObject("Tower3")->SetWindowStyleGroupSettings(UIstyle);
		UIstyle.SetBackgroundShader(ESkinSubStyle::eNormal, "Paintadier");

		UI.MainWindow()->GetObject("Tower4")->SetWindowStyleGroupSettings(UIstyle);
		UIstyle.SetBackgroundShader(ESkinSubStyle::eNormal, "Painttillary");


		test = false;
		else if(loadgameUi == false)
		{
			UI.MainWindow()->DeleteObject("Tower1");
			UI.MainWindow()->DeleteObject("Tower2");
			UI.MainWindow()->DeleteObject("Tower3");
			UI.MainWindow()->DeleteObject("Tower4");
			test = true;
		}
		*/ 
// inf xp // inf money

		if (loadgameUi == true && test == true)
		{
			UI.MainWindow()->AddButton("Tower1", "Paint Slinger", EButtonType::eRadio);
			HAPISPACE::VectorI ButtonPos(World_Pointer->GetScreenSize().x - 200, 100);
			UI.MainWindow()->SetScreenPosition(ButtonPos);

			UI.MainWindow()->AddButton("Tower2", "Paint Thrower", EButtonType::eRadio);
			UI.MainWindow()->PositionRelativeTo("Tower2", "Tower1", EDirection::eSouth);

			UI.MainWindow()->AddButton("Tower3", "Paintadier", EButtonType::eRadio);
			UI.MainWindow()->PositionRelativeTo("Tower3", "Tower2", EDirection::eSouth);

			UI.MainWindow()->AddButton("Tower4", "Painttillary", EButtonType::eRadio);
			UI.MainWindow()->PositionRelativeTo("Tower4", "Tower3", EDirection::eSouth);

			UI.MainWindow()->AddButton("Tower5", "Unknown tower", EButtonType::eRadio);
			UI.MainWindow()->PositionRelativeTo("Tower5", "Tower4", EDirection::eSouth);

			UI.MainWindow()->AddButton("x2Speed", "x2_WARNING:FAST", EButtonType::eRadio);
			UI.MainWindow()->PositionRelativeTo("x2Speed", "Tower5", EDirection::eSouth);

			UI.MainWindow()->AddButton("NextWave", "Next Wave", EButtonType::eRadio);
			UI.MainWindow()->PositionRelativeTo("NextWave", "x2Speed", EDirection::eSouth);

			UI.MainWindow()->AddButton("Pause", "Pause", EButtonType::eRadio);
			UI.MainWindow()->PositionRelativeTo("Pause", "NextWave", EDirection::eSouth);

			UI.MainWindow()->AddButton("Reset", "Reset", EButtonType::eRadio);
			UI.MainWindow()->PositionRelativeTo("Reset", "Pause", EDirection::eSouth);

			UI.MainWindow()->AddButton("AddMoney", "AddMoney", EButtonType::eRadio);
			UI.MainWindow()->PositionRelativeTo("AddMoney", "Reset", EDirection::eSouth);

			UI.MainWindow()->AddButton("AddExp", "AddExp", EButtonType::eRadio);
			UI.MainWindow()->PositionRelativeTo("AddExp", "AddMoney", EDirection::eSouth);
			
			test = false;
		}
		else if (loadgameUi == false)
		{
			UI.MainWindow()->DeleteObject("Tower1");
			UI.MainWindow()->DeleteObject("Tower2");
			UI.MainWindow()->DeleteObject("Tower3");
			UI.MainWindow()->DeleteObject("Tower4");
			UI.MainWindow()->DeleteObject("Tower5");
			UI.MainWindow()->DeleteObject("x2Speed");
			UI.MainWindow()->DeleteObject("NextWave");
			UI.MainWindow()->DeleteObject("Pause");
			UI.MainWindow()->DeleteObject("Reset");
			UI.MainWindow()->DeleteObject("AddMoney");
			UI.MainWindow()->DeleteObject("AddExp");
			test = true;
		}

	}

	

void UserInterface::UI_RadioButtonChangeState(UIWindow& window, const std::string& buttonName, bool pressed, int* userId)
{
	//Main Menu

	if (buttonName == "Start")//runs the game code from worldspace
	{
		std::cout << "Starting Game" << std::endl;
		enabledGen = true;
		loadMenu = false;
		loadgameUi = true;

	}

	if (buttonName == "Options")
	{
		std::cout << "Loading Options" << std::endl;
		loadMenu = false;
		UI.MainWindow()->AddButton("Test", "Test", EButtonType::eRadio);
		UI.MainWindow()->PositionRelativeTo("Test", "Start", EDirection::eSouth);

	}

	if (buttonName == "Exit")//exits HAPI
	{
		std::cout << "Exiting Game" << std::endl;
		loadMenu = false;
		HAPI_Sprites.Close();
	}

	//In game UI

	if (buttonName == "Tower1")
	{
		std::cout << "Tower 1 successfully placed" << std::endl;
		enabledTower1 = true;
		enabledTower2 = false;
		enabledTower3 = false;
		enabledTower4 = false;
		enabledTower5 = false;
	}

	if (buttonName == "Tower2")
	{
		std::cout << "Tower 2 successfully placed" << std::endl;
		enabledTower1 = false;
		enabledTower2 = true;
		enabledTower3 = false;
		enabledTower4 = false;
		enabledTower5 = false;
	}

	if (buttonName == "Tower3")
	{
		std::cout << "Tower 3 successfully placed" << std::endl;
		enabledTower1 = false;
		enabledTower2 = false;
		enabledTower3 = true;
		enabledTower4 = false;
		enabledTower5 = false;
	}

	if (buttonName == "Tower4")
	{
		std::cout << "Tower 4 successfully placed" << std::endl;
		enabledTower1 = false;
		enabledTower2 = false;
		enabledTower3 = false;
		enabledTower4 = true;
		enabledTower5 = false;
	}

	if (buttonName == "Tower5")
	{
		std::cout << "Tower 5 successfully placed" << std::endl;
		enabledTower1 = false;
		enabledTower2 = false;
		enabledTower3 = false;
		enabledTower4 = false;
		enabledTower5 = true;

	}

		if (buttonName == "NextWave")
		{
			std::cout << "Next Wave Is Spawning" << std::endl;
			nextWave = true;
		}

		if (buttonName == "Pause")
		{
			std::cout << "Pausing Game" << std::endl;
		}

		if (buttonName == "Reset")
		{
			std::cout << "Resetting Game" << std::endl;
			reset = true;
		}

		if (buttonName == "AddMoney")
		{
			std::cout << "Adding Money" << std::endl;
			infMoney = true;
		}

		if (buttonName == "AddExp")
		{
			std::cout << "AddExp" << std::endl;
			infXP = true;
		}

		if (buttonName == "x2Speed")
		{
			std::cout << "FAST BOI" << std::endl;
			x2 = true;
		}
	
}


