# String identification (SID) - Work in progress 
String identification is a debugging tool that is commonly used in game development to look up game assets. The objects in any virtual game world needs to be uniquely identified in some way. The unique object identifiers allow Game Designers to keep track of object count to make up their game worlds. The Unreal Engine employs a similar technique  to wrap the string id and a pointer to the corresponding C-style character array in a tiny class, in the Unreal Engine this class is called FName.
## Advantages of using SIDs over string
* SIDs take up smaller amount of memory compared to strings.
* SID comparisons are compiled time, vastly improving performance time.  
* The SID macro can be applied on switch cases.


## Example usage

```cpp
//expand macro to generate a StringID
#define SID(str) StringID(str)
#define SID_VAL(str) ToStringId64(str)

 switch (SID("player-seen").GetValue()) {

        case SID_VAL("player-seen"):
            playerSeen();
            break;

        case SID_VAL("player-not-seen"):
            keepLooking();
            break;

        default:
            printf("default");
            break;
//...
}
//...
```
