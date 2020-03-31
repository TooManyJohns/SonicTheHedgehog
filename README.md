# Sonic The Hedgehog, written in C++ 🦔💎
Sonic the Hedgehog, made with C++ using SFML

**Please note this was a tech-demo of how much I could do in a week's time for a final project for a programming course of mine, not a finished product. So please keep this in mind!**

*If you are asked to "Attach something to the process" when starting the game cancel and re-run the game will run fine.*

🥚 (That means no eggman....yet!) 🥚

I used Visual Studio 2015 for this project.

**FEATURES**
- SCORE
- ENEMIES
- LIVES
- REAL TIME CLOCK
- GAME WON
- GAME OVER

# How can I play?

**1.) Clone the repo!**

Inside your github/git folder, run:

`$ git clone https://github.com/TooManyJohns/SonicTheHedgehog.git`

**2.) Download SFML**
**Visual C++ 14 (2015) - 32-bit**
https://www.sfml-dev.org/download/sfml/2.5.1/
Open the ZIP and inside should be a SFML-version#, **rename** the folder to just 'SFML'

**3.) Create a folder in your directory**
Name is External Depencies. **place SFML folder in here**

Should look like this in your overhead directory after doing this, inside :
![](https://i.imgur.com/oyM0D1t.png)

**4.) Make sure your Visual Studio Enviroment is Set up Properly**

- Make sure target machine is type 'X86'

Should look like this on Visual Studio:
![](https://i.imgur.com/qK5gnGw.png)


- Include all your dependencies
Right click on your Solution file,

-> Right Click on the Project (NOT THE SOLUTION!) - > Properties, 

-> C/C++ -> "General",

In "Additional Include Directories" copy and paste: $(SolutionDir)/../External Libraries/SFML/include;%(AdditionalIncludeDirectories)

$(SolutionDir)/../External Libraries/SFML/include;%(AdditionalIncludeDirectories)

-> Linker -> Input
In "Additional Depencies" -> Edit & Copy and paste these:

`sfml-main-d.lib`

`sfml-graphics-d.lib`

`sfml-window-d.lib`

`sfml-system-d.lib`

`sfml-audio-d.lib`

`sfml-network-d.lib`

-> Linker -> General
In "Additional Library Directories" - > Edit & Copy and paste this to be able to access the SFML Library:
$(SolutionDir)/../External Libraries/SFML/lib

**5.) Run using Local Windows Debugger, and you too can play Sonic! ➡️**

The controls are:
A - > left
D - > right
SPACE - > Jump, you can kill enemies by being in ball form jumping and getting ontop of them.
Run into rings to earn them, jump over obstacles and defeat enemies by jumping on them. Screenshots are in the Wiki page : https://github.com/TooManyJohns/SonicTheHedgehog/wiki
There you can find out more technical aspects about how the game works, along with some pictures of gameplay and all involved assets.

# What is the objective?

To collect the 8 rings in the game without dying, game mechanics may seem a bit stuffy, but it was a week only I had to do this entire project by myself.

Once you win, you will get a victory screen congratulating you, but if you somehow get hit by the ladybug robots 3 times, you will have a special surprise from Dr.Eggman. (Remember to press SPACE after you lose!)

# NOTE/DISCLAIMER:
`All of the ASSETS in this game (Characters, sprites, music, etc) Are owned by the Sonic Team and SEGA, this project's purpose was to not only get a great grade, but to also see how much of an old beloved game of mine I could code and develop myself within a week's time-span. Although the sprites aren't owned by me, I did re-adjust their frames/along with creating my own victory screen, and game over screen as well. Enjoy!`
