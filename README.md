# COMP140 - API Hacking

When you open the Journal menu in Skyrim, the mod will send HTTP requests to Habitica to add/complete Todos on Habitica corresponding to your active and complete quests. A message reporting the result of the HTTP request will appear on screen 10 seconds (not in a menu) later.

The quests that will be updated on Habitica are the primary questlines of [Main Quest](http://www.uesp.net/wiki/Skyrim:Main_Quest), [Daedric Quests](http://www.uesp.net/wiki/Skyrim:Daedric_Quests), [Dark Brotherhood Quests](http://www.uesp.net/wiki/Skyrim:Dark_Brotherhood#Quests), [Thieves Guild Quests](http://www.uesp.net/wiki/Skyrim:Thieves_Guild_(faction)#Quests), [Companions Quests](http://www.uesp.net/wiki/Skyrim:Companions#Quests) and [College of Winterhold Quests](http://www.uesp.net/wiki/Skyrim:College_of_Winterhold_(faction)#Quests).

## Installation Instructions
To add the mod to Skyrim, simply copy the "Data" folder in this repository into your Skyrim folder. All the correct files should end up in the right places.
Then activate the mod with a mod manager for Skyrim.

##Structure
There are two main areas of code - the SKSE plugin written in C++, and the Skyrim Creation Kit script written in Papyrus.  
The SKSE plugin code can be found in the [Skybitica Visual Studio Project Folder](https://github.com/NecroReindeer/comp140-api-hacking/tree/master/skybitica/skybitica/skybitica).  
The Papyrus script can be found in [Data/scripts/source/zQuestLooper.psc](https://github.com/NecroReindeer/comp140-api-hacking/blob/master/Data/scripts/source/zQuestLooper.psc).  
All code in zQuestLooper.psc is written by me, and all code for the SKSE plugin is written by me, EXCEPT for the code in main.cpp, tools.cpp and the the function RegisterFuncs in skybitica.cpp. Sources noted below and in the code.

The relevant things in the Creation Kit Project can be seen in the screenshot below:
![Creation Kit](https://github.com/NecroReindeer/comp140-api-hacking/blob/master/Screenshots/Creation%20Kit.png)

##Sources used

The template for the Visual Studio project, including everything in main.cpp of my SKSE plugin that I used is from [here](https://github.com/xanderdunn/skaar/releases/tag/plugin3). I used [this](https://github.com/xanderdunn/skaar/wiki/SKSE%3A-Getting-Started) tutorial and that Visual Studio solution to get started.

## Proposal

Skyrim is a game where you can procrastinate about doing quests, ending up with a backlog hundreds of quests in your journal... This plugin will give the player an extra incentive to get those quests done! Essentially, gamifying a game mechanic of a game using an app that gamifies real life...! o.O  

I intend to create a plugin for Skyrim that uses the [Habitica API](https://habitica.com/static/api) to add any outstanding named Skyrim quests to the Habitica To-do list. I will do this by creating a [Skyrim Script Extender](http://skse.silverlock.org/) plugin using C++ that connects to the Habitica API. To connect to the Habitica API using C++, I will perform HTTP requests using the [C++ REST SDK (Casablanca)](https://casablanca.codeplex.com/). I will then make a script in the Papyrus scripting language (the language Skyrim Creation Kit uses for scripting) to access the quests in the game and call my custom SKSE plugin function.

[Habitica](https://habitica.com) is a productivity app that gamifies real life.  
[Skyrim](http://www.elderscrolls.com/skyrim/) is an open world RPG by Bethesda.

Perhaps as a stretch goal, the custom rewards on habitica could correspond to in-game Skyrim items, so that they appear in the inventory when bought using Habitica's reward system...  

###Justification for technologies used

####APIs
#####C++ REST SDK
I chose C++ REST SDK as it is made by Microsoft especially for C++, is fully featured, easy to add to Visual Studio and has comprehensive documentation. Alternatives such as [cURLpp](http://www.curlpp.org/) were an option, but on further research it became evident that a long and complicated process is involved in getting it to work with Visual Studio.

#####Skyrim Script Extender (SKSE)
Skyrim has a robust modding community and well established modding tools. Skyrim script extender is widely used by the modding community to access additional functions in Papyrus, as well as adding their own custom functions to Papyrus. It makes sense to use SKSE to create my plugin that makes HTTP requests to Habitica, otherwise it would involve disassembling the Skyrim code myself or using less established tools.
One disadvantage is that there is not much documentation about how to use SKSE and make plugins for it. I managed to find one tutorial, however. That, combined with lots of googling and looking on forums, allowed me to see how to get started. This made me see that it's actually very easy to get a SKSE plugin to work with Papyrus and into the game.

#####Habitica API
I chose Habitica as the API to use as the Habitica app is a core part of my design. The Habitica API is well documented and easily accessible. One downside is that it does not support OAuth, so all requests need to include an API-user and API-token, making things created using it less flexible and user-friendly.

####Programming Languages
#####C++
C++ is the language used to create SKSE plugins. There is also a tutorial that provides a template Visusal Studio project, which provides a starting point for making a SKSE plugin in C++.

#####Papyrus and Skyrim Creation Kit
The easiest way to make a plugin for Skyrim is to use the Skyrim Creation Kit. Papyrus is the language used for scripting in Skyrim Creation Kit. If I am to use Skyrim Creation Kit to create a Skyrim plugin, I will have to use Papyrus. An huge advantage of using Papyrus alongside the Skyrim Creation Kit, is that it provides functions for interacting with objects in the game and retrieving data from the game. The use of the Creation Kit and Skyrim-specific Papyrus functions (include SKSE functions) are very well documented on the [Creation Kit wiki](http://www.creationkit.com/index.php?title=Main_Page).

## Trello Board
Things in the 'Review' column are what was completed in the named sprint, things in the 'To do' column are things for the next sprint. I broke the two sprints down into smaller sections, for purposes of time management.

#### Sprint 1
![Sprint 1](https://github.com/NecroReindeer/comp140-api-hacking/blob/master/Trello/Sprint%201.png)

#### Sprint 1.5
![Sprint 1.5](https://github.com/NecroReindeer/comp140-api-hacking/blob/master/Trello/Sprint%201.5.png)


#### Sprint 2
![Sprint 2](https://github.com/NecroReindeer/comp140-api-hacking/blob/master/Trello/Sprint%202.png)

#### Sprint 2.5
![Sprint 2](https://github.com/NecroReindeer/comp140-api-hacking/blob/master/Trello/Sprint%202.5.png)
