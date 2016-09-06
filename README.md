# API Hacking
This is the base repository for the COMP140 API Hacking assignment.

NB: this repository currently does not contain a `.gitignore` file. I recommend you use https://www.gitignore.io to generate an appropriate `.gitignore` file for your choice of implementation language and development environment.

## Proposal

###The Game
There are several possibilities for my API:-

StarCraft

Age of Empires

Battle for Middle Earth

###The component

An RTS themed API, I want to try to make an external executable that can be used for a basic gameplay interface for most of these games. This will control the camera and use basic mouse and keyboard input to execute some basic commands. This should allow the user to play simple games against the computer.

###The Tech

I will be utilising the capabilities of the Myo gesture control system. This uses a standard C++ coding language with a Myo library for gesture recognition, or possible Lua scripting as this is the language that the Myo developers decided to use for their SDK.

There is already a mouse and keyboard input software available, but through my research I have not found a combination of the two. This is a good opportunity to combine them to create a basic RTS control system.

###Issues

I have already run into some issues:

1. The MYo when used as a mouse can be clunky inaccurate.

2. The Myo needs resyncing every now and then to keep it accurately sensing gestures.

###Solutions

1. I seems that with a bigger screen and standing further back you can more accurately control the mouse.

2. Re-sync the Mto.
