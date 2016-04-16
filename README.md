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

##Sprint 1:  
![End of sprint 1 board](https://raw.githubusercontent.com/MaddieK19/comp140-api-hacking/master/Trello%20boards%20and%20cards/End%20of%20sprint%20one.PNG)

