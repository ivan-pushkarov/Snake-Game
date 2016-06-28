### Project desctiption
_________________________________________________________________________________________

This is my implementation of the classical snake game. It has a playground consisting of 200 tiles - (10 x 20)
and a Scoreboard displaying your current score, the highest score so far, your current level and speed.
To control the snake's movement use the UP, DOWN, RIGHT and LEFT arrows or the "W", "S", "A", "D" keys.
The game has 10 levels, on each of which, your snake's move speed increases and you also need to reach a bigger length
in order to complete the level.

### Setting up development environment
_________________________________________________________________________________________

Windows OS:

* Install Microsoft Visual Studio 2015;


### Building
_________________________________________________________________________________________

To build the final solution, you need to:

* Build the solution as x32 Release.
* Copy HiScore, Fonts and Shaders folders into Release folder.
* Copy freetype6.dll, glew32.dll, SDL2.dll and zlib1.dll into Release folder
* Start Snake.exe and enjoy!

### Implementation details
_________________________________________________________________________________________

* `Model` - Abstract base class. Stores model's information - Buffer IDs, Shader IDs,
model's position, rotation, scale and move direction. It leaves the implementation of 
`loadModelToVRAM()` and `InitializeVertices()` methods to `BasicDrawableObject` and `TextureDrawableObject` classes,
based on that if the object has textures or doesn't.

* `ModelManager` - Singleton class resposible for generating buffers on the VRAM for storing the model's vertices.
It is using an unordered_map with strings as keys. Based on an identifier passed to the manager, 
it checks if buffer for such an object already exists (for example "Playground" - representing a playgorund tile).
If such buffer exists it returs the ID of the already generated and loaded with vertex information buffer. 
If it doesn't it generates a new buffer ID (empty buffer) and returns its ID.
This way we store only one buffer for all the tiles ("Quads") of the playground.

* `ShaderManager` - Singleton class resposible for compiling the shaders and providing global access to them.

* `FontsManger` - Singleton class. It provides global access to the freetype library.

* `Snake` - A container class, storing mutiple of models("Quads") and resposible for snake's movement. 