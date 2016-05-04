# API Hacking
This is the base repository for the COMP140 API Hacking assignment.

NB: this repository current does not contain a `.gitignore` file. I recommend you use https://www.gitignore.io to generate an appropriate `.gitignore` file for your choice of implementation language and development environment.

## Proposal

Skyrim is a game where you can procrastinate about doing quests, ending up with a backlog hundreds of quests in your journal... This plugin will give the player an extra incentive to get those quests done!  
(Essentially, gamifying a game mechanic of a game using an app that gamifies real life...?! o.O)  

I intend to create a plugin for Skyrim that uses the [Habitica API](https://habitica.com/static/api) to add any outstanding named Skyrim quests to the Habitica To-do list. I will do this by creating a [Skyrim Script Extender](http://skse.silverlock.org/) plugin using C++ to connect to the Habitica API. To connect to the Habitica API using C++, I will perform POST/GET requests using the [C++ REST SDK (Casablanca)](https://casablanca.codeplex.com/). I will then make a script in Papyrus (the language Skyrim Creation Kit uses) to access the quests in the game and call my custom SKSE plugin function.

A description of Habitica is found on [their website](https://habitica.com).

Perhaps as a stretch goal, the custom rewards on habitica could correspond to in-game Skyrim items, so that they appear in the inventory when bought using Habitica's reward system...  


##Sources used

The template for the Visual Studio project and main.cpp of my SKSE plugin that I used can be found [here](https://github.com/xanderdunn/skaar/releases/tag/plugin3). I used [this](https://github.com/xanderdunn/skaar/wiki/SKSE%3A-Getting-Started) tutorial and that Visual Studio solution to get started.



## Trello Board
Things in the 'Review' column are what was completed in the named sprint, things in the 'To do' column are things for the next sprint. I broke the two sprints down into smaller sections, for purposes of time management.
### Label Key
![Labels]()

### Sprint 1
![Sprint 1](https://github.com/NecroReindeer/comp140-api-hacking/blob/master/Trello/Sprint%201.png)

### Sprint 1.5
![Sprint 1.5](https://github.com/NecroReindeer/comp140-api-hacking/blob/master/Trello/Sprint%201.5.png)


### Sprint 2
![Sprint 2](https://github.com/NecroReindeer/comp140-api-hacking/blob/master/Trello/Sprint%202.png)
