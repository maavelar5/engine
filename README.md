
# Table of Contents

1.  [2D C++ Engine](#orgc57defb)
    1.  [Compiles on <code>[4/4]</code>](#org874a8bf)
    2.  [Features / TODO list <code>[12/20]</code>](#org9b8c3c0)


<a id="orgc57defb"></a>

# 2D C++ Engine

I'm working on a cross platform 2D game engine (I hope a 3D version is possible as well). The project uses features from **c++17** so if you decide to clone it, you'll need a compiler that 
supports it. I've succesfully compiled the project on the following operating systems:


<a id="org874a8bf"></a>

## TODO Compiles on <code>[4/4]</code>

-   [X] Linux
-   [X] Windows
-   [X] MacOS
-   [X] Android (**master-android** branch)
    
    I wish to eventually compile it for the Nintendo Switch but&#x2026; just like Jon Snow&#x2026; I know nothing&#x2026;about consoles. I haven't compiled the code for MacOS or Android lately, do let me know if you try and fails.


<a id="org9b8c3c0"></a>

## Features / TODO list <code>[12/20]</code>

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
    
    I may have missed some stuff.

Marco Avelar

