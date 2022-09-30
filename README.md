# String identification (SID) - Work in progress 
String identification is a debugging tool that is commonly used in game development to look up game assets. A game contains a very large number of assets. Meshes, textures, animations, skeletons, scripts, sounds, effects, triggers, events, NPCs, and various other miscellaneous resources, objects and entities. These objects in any virtual game world needs to be uniquely identified in some way. The unique object identifiers allow Game Designers to keep track of object count to make up their game worlds. The Unreal Engine employs a similar technique  to wrap the string id and a pointer to the corresponding C-style character array in a tiny class, in the Unreal Engine this class is called FName.



## Advantages of using SIDs over string
* SIDs take up smaller amount of memory compared to strings.
* SID comparisons are compiled time constants, vastly improving performance time.  
* The SID macro can be applied on switch cases, which is not possible with strings.


## Example usage

```cpp
// expand macro to generate a StringID
#define SID(str) StringID(str)
#define SID_VAL(str) ToStringId64(str)

// generate a StringID
StringID sid0 = SID("player-spotted");

// check for valid expression using assert()
assert(sid0.GetValue() == "player-spotted")

// print the hash value
printf("sid0: %llu", sid0.GetValue());

switch (sid0.GetValue()) {

        case SID_VAL("player-spotted"):
            alertEnemies();
            break;

        case SID_VAL("player-not-seen"):
            keepSearching()
            break;

        default:
            printf("default");
            break;
}


// asset look up
Texture* pTexture = new Texture();
pTexture->loadTexture(SID("texture.png").GetValue());
``` 




