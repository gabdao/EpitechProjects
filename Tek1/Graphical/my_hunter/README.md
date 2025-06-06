# my_hunter

## Description
Duck Hunt-inspired shooting game developed in C using the CSFML library. Players control a hunter who must shoot moving ducks that appear and traverse the screen using mouse click interactions.

## Objective
Create a `my_hunter` game that must:
- Display animated ducks moving across the screen
- Handle mouse click events to shoot ducks
- Implement sprite-based animations using sprite sheets
- Manage window events and user inputs
- Provide smooth, frame-rate independent gameplay

### Core Game Mechanics
- **Hunter**: Player controls a hunter character
- **Ducks**: Animated sprites that move from one side of screen to another
- **Shooting**: Mouse click interaction to shoot ducks
- **Movement**: Ducks must move with rotation, translation, or scaling effects

### Technical Requirements

**MUST Have:**
- Window closure via events
- Mouse click input management
- Animated sprites from sprite sheets
- Moving elements (rotation/translation/scaling)
- Help option (-h) with program description and controls

**SHOULD Have:**
- Frame-rate independent animations using sfClock
- Window size between 800x600 and 1920x1080 pixels
- Limited frame rate to prevent lag

**COULD Have:**
- Multiple difficulty levels
- Score display system
- High score storage
- Mouse cursor target indicator

## Constraints
- Language: C
- Graphics: CSFML library
- Compilation via Makefile with `re`, `clean`, `fclean` rules
- Error code 84 on error, 0 otherwise
- Repository size limit: ~15MB (including assets)
