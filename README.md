# RPGEngine

## *A small RPG Engine built for fun*

  

A free, open source, engine for building games.
This, is a project I want to create and build for my own personal learning purposes, however, if you think you can contribute to this, make a better version, feel free to send pull requests, suggestions or make your own fork!

You can make whatever you want with it, it's open source and free, *and it comes with zero guarantees whatsoever*, but feel free to use it for whatever, do you have to credit the engine? Yes... I mean come on, don't I deserve at the very least a little bit of praise? A tiny bit??

Things that this engine does (if this is on github, all of those are already implemented):
 - Levels, create your own maps!
 - Scripts, create meaninful events! (will most likely change, a lot)
 - Camera, your world goes beyond you window! Literally!
 - Animations, don't make your game a static boring thing!
 - Audio, you hear the footsteps? Yeah, audio is magical.

Essentially, basic things to create a game, nothing fancy, but doable.

Things I want to add
 - Engine UI: the first version of the engine is not necessarily supposed to have a UI and level editor, because it's hard to do. However, it will at some point, because even though it's not technically necessary, it is if you really plan to make a game with this.
 - ONLINE! You can achieve online on your own, however, I want to make the engine take care of it.
 - Dynamic music! Meaning that part of the music can stard or end basing on in game events, for example, vocals might be turned on or off depending on the position of the player, or the soundtrack might be switching from type A to type B depending on what's going on. For example, let's assume the game has a sort of battle thing, when the battle starts instead of having a completely different theme, it would be an alternate version of the same, that instead of starting from the beginning, would transition to the new theme seamlessly. Essentially, check out Nier Automata and Nier Replicant, that.

And more stuff I simply can't come up with at the time of writing.

# Will this use SFML forever?
No. Not because SFML is bad or anything, but I want to build this thing from scratch... sort of.
I am at this very moment unable to write an engine able to do take care of most of the things that need to be done for an engine, I cannot write the most efficient and proper modern C++ code, multithreaded code, not even a shader in OpenGL let alone stuff like Vulkan!
And this means that before I end up seeing a map and a sprite on screen I'd already be too bored and done with this to keep it going, but you know what is exciting? Visible progress! And this is when SFML comes in.

I used it in the past for playing around, it's really simple and gets the job done, for what this engine will do, it's more than enough. Once the engine will be mature enough and will be at an usable state I will begin to add more features, utilities, optimisation and I will substitute SFML for my own code. Bit by bit, not all of a sudden. And probably, it will still be there as fallback for some platforms, because while SFML is cross platform and easy, DirectX is not, and while Vulkan is cross platform, it is not easy, and no, even OpenGL is not easy for me! For now.

Regardless, taking something cross platform and making it not cross platform seems stupid, so I will substitute SFML components, I will at some point make some build not use SFML at all, however it might remain there to allow deployment on some platforms.

## Engine principles

So, I kind of have no clue how and engine is structures to be honest, so this might be how everyone does it, how nobody does it anymore, how people will do it in the future, or the most dumb idea ever.

The engine itself is no more than a runtime that takes all your assets and scripts and simple makes uses them to compose a scene in the game.
Now this works, but it's limiting, it's limiting in the sense that this means all you can use are the APIs provided by the engine, even thought the engine is made in C++, all you can do as a user is provide assets, scripts and map files to describe how a scene should be composed, that's it, you want to add your custom component? You cannot.

Which means that this approach is not foolproof, I'm still thinking about how this can be fixed, and the "how" might require to rewrite a lot of code. But hey, it is the way it is.

Anyway, this would mean that all the UI would do in the end is simply opening the runtime and make it work, while providing a toolkit to edit maps, scripts and all of the likes. Which would make the creation of relatively easy (as far as UI easyness goes).