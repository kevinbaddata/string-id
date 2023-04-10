# String identification (SID) - Work in progress 
String identification is a debugging tool that is commonly used in game development to look up game assets. A game contains a very large number of assets. Meshes, textures, animations, skeletons, scripts, sounds, effects, triggers, events, NPCs, and various other miscellaneous resources, objects and entities. These objects in any virtual game world needs to be uniquely identified in some way. The unique object identifiers allow Game Designers to keep track of object count to make up their game worlds. The Unreal Engine employs a similar technique  to wrap the string id and a pointer to the corresponding C-style character array in a tiny class, in the Unreal Engine this class is called FName.



## Advantages of using SIDs over string
* SIDs take up smaller amount of memory compared to strings.
* SID comparisons are compiled time constants, vastly improving performance time.  
* The SID macro can be applied on switch cases, which is not possible with strings.


## Example usage

```cpp
// This macro generates a 32-bit hash value from a string literal
#define SID(x) hash::fnv1a<uint32_t>::hash(x)

// Declare a constant char pointer and initialize it with a string literal
const char* game_state = "player-seen";

// Generate a hash value from the string literal using the SID macro
uint32_t event = SID(game_state);
    
// Use the generated hash value in a switch statement
switch (event) {
    case SID("player-seen"):
        // If the hash value matches the hash value generated from "player-seen",
        // play a line of dialogue from a file called "dialogue1.wav"
        PlayDialogue("dialogue1.wav");
        break;
    // Other cases...
}

//...
    
``` 




