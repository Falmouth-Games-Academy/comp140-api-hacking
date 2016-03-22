# API Hacking
This is the base repository for the COMP140 API Hacking assignment.

NB: this repository current does not contain a `.gitignore` file. I recommend you use https://www.gitignore.io to generate an appropriate `.gitignore` file for your choice of implementation language and development environment.

## Proposal


(Still not sure)

Skyrim is a game where you can procrastinate about doing quests, ending up with a backlog hundreds of quests in your journal... This plugin will give the player an extra incentive to get those quests done!  (Gamifying a game mechanic of a game using an app that gamifies real life...?! o.O)  

I intend to create a plugin for Skyrim that uses the [Habitica API](https://habitica.com/static/api) to add any outstanding Skyrim quests to the Habitica To-do list. It could also add a positive Habit or Daily to Habitica's list for completing a quest. Perhaps as a stretch goal, the custom rewards on habitica could correspond to in-game Skyrim items, so that they appear in the inventory when bought using Habitica's reward system...  

I will create the plugin using [Skyrim Script Extender](http://skse.silverlock.org/), by defining my own Papyrus functions to interface with the Habitica API using C++, and then doing the scripting that gets the quests and from Skyrim and calls that function using Papyrus.
