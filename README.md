# API Hacking
This is the base repository for the COMP140 API Hacking assignment.

NB: this repository currently does not contain a `.gitignore` file. I recommend you use https://www.gitignore.io to generate an appropriate `.gitignore` file for your choice of implementation language and development environment.

## Proposal
##Game
I am going to be implementing this componenet for our Comp150 game.

##Component
The component I want to include into this game would be to use weather databases to affect the weather and colour hue of the game. If the area is cloudy then the colours look grey, if there is rain then rain particles appear on the screen, etc.

##Language
For this I'll be using C++ for the colour and weather change and JSON / XML API as this is required to use the API. To use this API with C++, I'll be using C++ REST SDK (casablanca) to allow for the information to be taken from the http request and JSON.
https://github.com/Microsoft/cpprestsdk 
https://social.msdn.microsoft.com/Forums/vstudio/en-US/df7e4b67-e6ed-42c8-85f4-25424276ad70/c-rest-sdk-work-with-json-data?forum=vcgeneral

##API
The API I'll be using is Open Weather Map which provides free weather data and forecast API suitable for any cartographic services like web and smartphones applications.

##Functionality
I think this would improve the game as it would make for more immersion into the world, and allow our target audience to experience different weather conditions around the world.
