/*
	HAPI Sprites Start
	------------------
	This solution contains an already set up HAPI Sprites project and this main file with brief example code
	Release and Debug configurations for 64 bit builds are configured for you (32 bit is not supported).
	
	The directory structure and main files are:

	HAPISprites_Start - contains the Visual Studio solution file (HAPI_APP.sln)
		HAPI_APP - contains the Visual Studio HAPI_APP project file (HAPI_APP.vcxproj) and source code
			HAPI_SPRITES - the directory with all the HAPI library files including GLM
			Data - a place to put all your data files

		MakeDistributable.bat - a batch file for populating a Demo folder for stand alone running
		Clean.bat  - a batch file to remove all the Viz temporary files and hence reduce the size of the folder		
		Note: this should be run with Visual Studio closed

	Last updated: Keith Ditchburn 17/01/19
*/

// To use HAPI Sprites you need to include the header
#include <HAPISprites_Lib.h>

// All of the core HAPI Sprites functionality is in the HAPISPACE namespace
using namespace HAPISPACE;

// Every HAPISprites program must have a HAPI_Sprites_Main as an entry point
// When this function exits the program will close down
void HAPI_Sprites_Main()
{
	int width{ 1280 };
	int height{ 800 };

	// We must initialise HAPI Sprites before doing anything with it
	// This call allows us to specify the screen size and optionally the window title text and flags
	if (!HAPI_Sprites.Initialise(width, height, "HAPI Sprites Start Project"))
		return;

	/*
	Main Classes
	============
	HAPI Sprites has three main classes. A sprite class that contains a spritesheet that in turn contains a surface.

	1. Surface - this class represents an image. It can be a loaded texture or it could be one you write to (HW or SW).
	Every spritesheet has a surface but a surface can also be stand alone. The main screen is a hardware surface so
	all writing to it uses hardware acceleration (via OpenGL). Since this is used so often there is a shortcut to it
	via the macro SCREEN_SURFACE. It always exists.

	2. Spritesheet - this class holds information about the make up of a surface i.e. areas that define frames along
	with information about which frames make up an animation (via a named animation set). It can also create collision
	normals from the surface data.

	3. Sprite - this class handles all the rendering of a 2D image as well as maintaining position and collision handling etc.

	In practice
	===========
	Practially you do most of your work via the Sprite class
	A sprite can be created in a number of ways, the main two are:

	1. From scratch. This is created by loading a texture. Frames can be derived from some basic parameters but it does not create
	multiple frames of different sizes or framesets.

	2. From an xml file. The XML file format used is the one created for the Stirling framework. While there is no real standard
	format this one is used by a few sites that provide free 2D spritesheets. You can also use the HAPI Sprites built in editor
	to create one yourself. This supports frames and animation sets etc.
	*/

	/*
	Example of creating a Sprite from scratch

	This call specifies a texture filename and that it has 4 equally sized horizontally laid out frames
	HAPI Sprites returns a unique_ptr to the created sprite. You can keep it unique or convert it to shared (done here)
	*/

	std::shared_ptr<Sprite> sprite = HAPI_Sprites.MakeSprite("Data\\helicopter.png", 4);


	/*
	Example of creating a Sprite from an XML file

	This file was created using the built in editor and has spritesets defined for walking left, right, idle etc.
	*/

	std::shared_ptr<Sprite> sprite2 = HAPI_Sprites.LoadSprite("Data\\Troll2.xml");

	/*
	You must check the returned pointer as the file may not have been found
	*/
	if (!sprite2)
	{
		HAPI_Sprites.UserMessage("Could not load spritesheet", "Error");
		return;
	}

	/*
	Sprite Operations
	There are a number of functions you can apply once a sprite is created

	For example the helicopter above does not have an alpha channel, however the black colour is used for transparency
	so we can convert it to alpha.
	*/

	sprite->GetSurface()->MakeAlphaChannelFromColourKey(Colour255::BLACK);

	/*
	We can set the sprite to automatically animate
	Here I am saying I want the frame to change 100 times a second
	*/
	sprite->SetAutoAnimate(100);

	/*
	The second sprite has a lot more frame and animation information
	So we can use that to specify the exact animation we want
	In this case I want the walking right animation which is labelled "Right"
	I want it to animate at 20 FPS and to loop
	*/
	sprite2->SetAutoAnimate(20, true, "Right");


	/*
	Once loading is complete you can enter the main loop
	Update must be called for each frame
	HAPI Sprites will return true from Update until the user closes the window or you manually call close
	*/
	while (HAPI_Sprites.Update())
	{
		/*
		We need to clear the screen prior to drawing
		We can use the screen surface macro
		*/
		SCREEN_SURFACE->Clear();

		/*
		A sprite holds position, scaling and rotation data in a transform component
		that can be set prior to rendering. Note the first two functions below take a Vector2f
		We can create one in place using C++11 curly brace initialisation
		*/

		sprite->GetTransformComp().SetPosition({ 100, 200 });
		sprite->GetTransformComp().SetScaling({ 2.0f, 2.0f });
		sprite->GetTransformComp().SetRotation(0.3f);

		/*
		We render the sprites to a surface. Normally this is the screen so we pass the screen surface macro.
		*/
		sprite->Render(SCREEN_SURFACE);
		sprite2->Render(SCREEN_SURFACE);

	}
}
