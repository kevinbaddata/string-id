# String identification (SID)
String identification is a debugging tool that is commonly used in game development to look up game assets. The objects in any virtual game world needs to be uniquely identified in some way. The unique object identifiers allow Game Designers to keep track of object count to make up their game worlds. The Unreal Engine employs a similar technique  to wrap the string id and a pointer to the corresponding C-style character array in a tiny class, in the Unreal Engine this class is called FName.
## Advantages of using SIDs over string
* SIDs take up smaller amount of memory compared to strings
* SID comparisons are compiled time performance improvement 
* The SID macro can be applied on switch cases 
* 

## Example usage

```cpp
switch (SID("player-seen")) {
        case SID("player-seen"):
            std::cout << "Player has been spotted" << std::endl;
            break;
        case SID("player-not-seen"):
            std::cout << "Player has not been spotted" << std::endl;
            break;
        case SID("player-not-found"):
            std::cout << "Player not found" << std::endl;
            break;
        default:
            std::cout << "Unknown string ID" << std::endl;
            break;
}
```
