
# Table of Contents

1.  [2D C++ Engine](#orgfd0fbc8)
    1.  [Compiles on <code>[4/4]</code>](#orgc323204)
    2.  [Feature list <code>[12/20]</code>](#org98e8c4b)
    3.  [Box2D](#orgf5f4f7d)
    4.  [Dependencies](#org77f8f46)
    5.  [Compilation](#org69a22fc)
        1.  [Android](#org69ea1e9)
    6.  [Demo](#org931324b)


<a id="orgfd0fbc8"></a>

# 2D C++ Engine

I'm working on a cross platform 2D game engine (I hope a 3D version is possible as well). The project uses features from **c++17** so if you decide to clone it, you'll need a compiler that 
supports it. I've succesfully compiled the project on the following operating systems:


<a id="orgc323204"></a>

## Compiles on <code>[4/4]</code>

-   [X] Linux
-   [X] Windows
-   [X] MacOS
-   [X] Android (**master-android** branch)

I wish to eventually compile it for the Nintendo Switch but&#x2026; just like Jon Snow&#x2026; I know nothing&#x2026;about consoles. I haven't compiled the code for MacOS or Android lately, do let me know if you try and fails.


<a id="org98e8c4b"></a>

## Feature list <code>[12/20]</code>

-   [X] Simple platfomer physics (AABB collision resolution)
-   [X] Constant delta update with variable frame time (@gafferongames)
-   [X] Naive automated movement (for enemies)
-   [X] Angle resolution between two vectors
-   [X] Directional movement (projectiles)
-   [-] Debugger window with limited output options
    -   [X] Draws and scrolls acting as a queue
    -   [ ] Scroll position with mouse wheel or arrow keys
    -   [ ] Colour output (atleast for keywords such as fail, info, etc)
    -   [X] Init based on config file
    -   [X] Hide/Show with key press
    -   [X] Update based on config file
-   [X] Info window for displaying FPS or entity attributes
    -   [X] Hide/Show with key press
-   [X] Read from file to dynamically load platforms and enemies
-   [X] Objects read from file are bound to scenes
-   [ ] HUD (WIP)
-   [X] Projectiles (linear and directed)
-   [X] Centralized entity list manipulation
-   [ ] Tile Editor
-   [X] Timers
-   [ ] Particle simulation
-   [ ] Proper rotation collision
-   [ ] Sprite animation
-   [ ] Controllers (WIP)
-   [ ] Touch events (WIP)
-   [X] Release bundle binary


<a id="orgf5f4f7d"></a>

## Box2D

I've integrated Box2D in a separate branch but a full blown physics engine is not needed for what I have in mind.


<a id="org77f8f46"></a>

## Dependencies

-   I'm currently testing with **gcc**, I've tried **clang** but there are a few errors such as implicit int/float casting (in gcc that gets truncated by default) that I didn't want to focus on at the moment.
-   SDL2 (image, mixer, ttf)


<a id="org69a22fc"></a>

## Compilation

There is a debug and release builds in place, run **make** or **make release** depending on what you want.


<a id="org69ea1e9"></a>

### Android

There is an android project which can be run with **Android studio**, from there that's being managed automatically.


<a id="org931324b"></a>

## Demo

**<https://www.youtube.com/watch?v=xyKakwKVgzU>**

