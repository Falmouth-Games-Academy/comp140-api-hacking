# COMP140 - API Hacking

## Proposal

Skyrim is a game where you can procrastinate about doing quests, ending up with a backlog hundreds of quests in your journal... This plugin will give the player an extra incentive to get those quests done! Essentially, gamifying a game mechanic of a game using an app that gamifies real life...! o.O  

I intend to create a plugin for Skyrim that uses the [Habitica API](https://habitica.com/static/api) to add any outstanding named Skyrim quests to the Habitica To-do list. I will do this by creating a [Skyrim Script Extender](http://skse.silverlock.org/) plugin using C++ that connects to the Habitica API. To connect to the Habitica API using C++, I will perform HTTP requests using the [C++ REST SDK (Casablanca)](https://casablanca.codeplex.com/). I will then make a script in the Papyrus scripting language (the language Skyrim Creation Kit uses for scripting) to access the quests in the game and call my custom SKSE plugin function.

[Habitica](https://habitica.com) is a productivity app that gamifies real life.  
[Skyrim](http://www.elderscrolls.com/skyrim/) is an open world RPG by Bethesda.

Perhaps as a stretch goal, the custom rewards on habitica could correspond to in-game Skyrim items, so that they appear in the inventory when bought using Habitica's reward system...  

###Justification for technologies used
####C++ REST SDK
I chose C++ REST SDK as it is made by Microsoft especially for C++, is fully featured, easy to add to Visual Studio and has comprehensive documentation. Alternatives such as [cURLpp](http://www.curlpp.org/) were an option, but on further research it became evident that a long and complicated process is involved in getting it to work with Visual Studio.

####Skyrim Script Extender (SKSE)
Skyrim has a robust modding community and well established modding tools. Skyrim script extender is widely used by the modding community to access additional functions in Papyrus, as well as adding their own custom functions to Papyrus. It makes sense to use SKSE to create my plugin that makes HTTP requests to Habitica, otherwise it would involve disassembling the Skyrim code myself or using less established tools.

####Habitica API
I chose Habitica as the API to use as the Habitica app is a core part of my design. The Habitica API is well documented and easily accessible. One downside is that it does not support OAuth, so all requests need to include an API-user and API-token, making things created using it less user-friendly.


##Sources used

The template for the Visual Studio project, including everything in main.cpp of my SKSE plugin that I used is from [here](https://github.com/xanderdunn/skaar/releases/tag/plugin3). I used [this](https://github.com/xanderdunn/skaar/wiki/SKSE%3A-Getting-Started) tutorial and that Visual Studio solution to get started.




### Trello Board
Things in the 'Review' column are what was completed in the named sprint, things in the 'To do' column are things for the next sprint. I broke the two sprints down into smaller sections, for purposes of time management.
#### Label Key
![Labels]()

#### Sprint 1
![Sprint 1](https://github.com/NecroReindeer/comp140-api-hacking/blob/master/Trello/Sprint%201.png)

#### Sprint 1.5
![Sprint 1.5](https://github.com/NecroReindeer/comp140-api-hacking/blob/master/Trello/Sprint%201.5.png)


#### Sprint 2
![Sprint 2](https://github.com/NecroReindeer/comp140-api-hacking/blob/master/Trello/Sprint%202.png)
