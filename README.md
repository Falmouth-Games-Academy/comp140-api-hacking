# API Hacking
This is the base repository for the COMP140 API Hacking assignment.


####Requires C++ REST SDK to run which can be [installed through NuGet in Visual Studio](https://github.com/Microsoft/cpprestsdk/wiki/Getting-Started-Tutorial)

C++ REST SDK sometimes needs to be unintalled in NuGet and reinstalled on first use.

The API Hacking Code folder contains a console application that can request the data from Open Notify and store it in variables. 
  
API Code in COMP150 is the code from the console application integrated into the COMP150 game. The relevant classes are ISSLocation and SpaceGame. 
  
Neither will run without the C++ REST SDK package installed. 



## Proposal
The component I intend to make will be for the COMP150 game. It will move the background in the game depending on the location of the International Space Station.  

####User stories: 
![Trello board](https://raw.githubusercontent.com/MaddieK19/comp140-api-hacking/master/Trello%20boards%20and%20cards/Trello%20board.PNG)

####Identify and justify which technologies you will use:
The API I intend to use is [Open Notify](http://open-notify.org/). This API can get the current location of the ISS and who is on it. NASA have their own API but that requires authentication and API keys and as I only need the location of the ISS, Open Notify seemed like the more suitable and simpler option.

I've chosen to use [C++ REST SDK](http://casablanca.codeplex.com/) to request data from the API. The data will be in a JSON object. There were many JSON libraries for C++ such as JSON Spirit but C++ REST SDK was simpler to install in Visual Studio using NuGet and had a lot of relevant documentation related to my project.

##Resources used:
* [Microsoft tutorial on JSON and get requests using C++ REST SDK](https://msdn.microsoft.com/en-us/library/jj950082.aspx)
* [drdobbs tutorial on extracting and printing information from a JSON object](http://www.drdobbs.com/tools/json-and-the-microsoft-c-rest-sdk/240164821)
* [Background images from NASA's royalty free galleries](http://www.nasa.gov/connect/artspace/participate/royalty_free_resources.html)

##Sprint 1:  
![End of sprint 1 board](https://raw.githubusercontent.com/MaddieK19/comp140-api-hacking/master/Trello%20boards%20and%20cards/End%20of%20sprint%20one.PNG)  
At the end of this sprint the code can connect to the Open Notify API and request the location of the ISS, it then saves that information to a html file. In the next sprint I intend to change it to extract the JSON information instead of having to save a file and then go through an external file.

##Sprint 2:
![End of sprint 2](https://raw.githubusercontent.com/MaddieK19/comp140-api-hacking/master/Trello%20boards%20and%20cards/End%20of%20sprint%20two.PNG)  
The code now makes a request to the API and receives the JSON, it then extracts that data and saves it to a series of variables. I've also integrated the code into my COMP150 group game. It updates every second and shifts the game background image depending on the location of the ISS. 


