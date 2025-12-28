# So_long

## What is this project?
* **Goals** To create a 2D game using the graphical library miniLibx.

## How it works

```bash
git@github.com:antabord1806/so_long.git so_long
cd so_long
tar -xvzf minilibx-linux.tgz
make all
```
```bash
make
```
```bash
./so_long map.ber
```

## Must Know

The evolution of the project is directly dependent on how much one understands the graphical libary being used, that being said these are the most important concepts to understand:

* **Map rendering**
  The project requieres de use of images of the minilibx, this means loading up to the memory all the sprites being used so the execuion is faster then drawing in the screen pixel by pixel, the system already know what to display, you just have to tell it the place.

  **Event Handling**
  It's something that happens in the system that the program might want to respod to, in this case they are:
    - keyboard events;
    - window events;
  In this project the response that the program responds to ends with changing the place of the sprite and re-rendering the map;

## Core Concepts

This project is built around a simple but strict game loop based on rendering and events.

### Map Representation

- The map is read from a `.ber` file and stored in a 2D array.
- Each character in the map represents a game entity:
  - `1` → Wall  
  - `0` → Empty space  
  - `P` → Player  
  - `C` → Collectible  
  - `E` → Exit  

The map array is the **single source of truth** for the game state.  
Every movement updates the map first, then the screen is re-rendered accordingly.

### Win and Lose Conditions

- The player **wins** when:
  - All collectibles are collected
  - The player reaches the exit

- The game **ends** when:
  - The exit is reached successfully
  - The window is closed

All conditions are validated through the map state.

## My Approach

<p align="left">
 <img src="git assets/fell int the void.gif" alt="graph1" width="600">
  <figcaption><em>Game over message</em></figcaption>
</p>

<p align="left">
   <img src="git assets/you win.gif" alt="graph2" width="600">
  <figcaption><em>Game completed message</em></figcaption>
</p>

## Conclusion
This project allowed me to understand the fundamentals of 2D game development using MiniLibX.
