# API Hacking
This is the base repository for the COMP140 API Hacking assignment.

NB: this repository current does not contain a `.gitignore` file. I recommend you use https://www.gitignore.io to generate an appropriate `.gitignore` file for your choice of implementation language and development environment.

## Proposal

The component I intend to make will be for the COMP150 game. It will let the player log into Facebook and then get their friend list and name the in game characters after there friends. A stretch goal will be to post the player's score to Facebook.  

####User stories: 
![Trello board](https://raw.githubusercontent.com/MaddieK19/comp140-api-hacking/master/Trello%20board.PNG)

####Identify and justify which technologies you will use:
Facebook have their own API, [Facebook Graph API](https://developers.facebook.com/docs/graph-api), that can get a user's friend list if the friend is using the app as well however it doesn't appear to be compatiable with C++. There are a few open source libraries such as [Windows SDK for Facebook](https://github.com/Microsoft/winsdkfb) and [C++ REST](http://casablanca.codeplex.com/) that I may be able to use with the Graph API.
