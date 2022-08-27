# String identification (SID)

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