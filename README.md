# API Hacking
This is the base repository for the COMP140 API Hacking assignment.

NB: this repository current does not contain a `.gitignore` file. I recommend you use https://www.gitignore.io to generate an appropriate `.gitignore` file for your choice of implementation language and development environment.

## Proposal
The component I intend to make will be for the COMP150 game. It will change the background in the game depending on the location of the Internation Space Station.  

####User stories: 
![Trello board](https://raw.githubusercontent.com/MaddieK19/comp140-api-hacking/master/Trello%20boards%20and%20cards/Trello%20board.PNG)

####Identify and justify which technologies you will use:
The API I intend to use is [Open Notify](http://open-notify.org/) this API can get the current location of the ISS and who is on it. 

I've chosen to use [C++ REST SDK](http://casablanca.codeplex.com/) to connect to the API and will use JSON to get the data. I've chosen use Open Notify as it uses JSON and gives me all the data I need and I've chosen to use C++ REST SDK over the other libraries as it supported by Microsft and easily installed into Visual Studio.

##Tutorials used:
* [Micorsoft tutorial on JSON and get requests using C++ REST SDK](https://msdn.microsoft.com/en-us/library/jj950082.aspx)
* [drdobbs tutorial on extracting and printing information from a JSON object](http://www.drdobbs.com/tools/json-and-the-microsoft-c-rest-sdk/240164821)


##Sprint 1:  
![End of sprint 1 board](https://raw.githubusercontent.com/MaddieK19/comp140-api-hacking/master/Trello%20boards%20and%20cards/End%20of%20sprint%20one.PNG)  
At the end of this sprint the code can connect to the Open Notify API and request the location of the ISS, it then saves that infomation to a html file. In the next sprint I intend to change it to extract the JSON information instead of having to save a file and then go through an external file.

##Sprint 2:
![End of sprint 2](https://raw.githubusercontent.com/MaddieK19/comp140-api-hacking/master/Trello%20boards%20and%20cards/End%20of%20sprint%20two.PNG)  
The code now makes a request to the API and receives the JSON, it then extracts that data and saves it to a series of variables. I've also intergrated the code into my COMP150 group game and it updates every second and shifts the background depending on the location of the ISS


