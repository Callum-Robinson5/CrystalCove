del /s /q Demo\*.*
rd Demo
md Demo
md Demo\Data

copy HAPI_App\HAPI_SPRITES\Libs64 Demo\
copy HAPI_App\Data Demo\Data\
copy x64\Release\HAPI_APP.exe Demo\Demo.exe