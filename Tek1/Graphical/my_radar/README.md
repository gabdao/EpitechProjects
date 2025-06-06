# my_radar

## Description
Air traffic control simulation panel developed in C using CSFML. The program renders a 2D visualization of aircraft movements and control tower management, simulating real air traffic control scenarios with collision detection and safe zones.

## Objective
Create a `my_radar` simulation that must:
- Load aircraft and control tower data from script files
- Display real-time aircraft movement with collision detection
- Manage control tower safe zones where aircraft can overlap
- Provide interactive visualization controls
- Handle aircraft takeoff delays and landing sequences

### Simulation Entities

**Aircraft:**
- Fly from departure to arrival coordinates in straight lines
- Move at constant speeds (pixels per second)
- Have 20x20 pixel square hitboxes
- Appear when taking off, disappear when landing
- Destroyed when colliding outside control areas
- Can be delayed before takeoff

**Control Towers:**
- Static entities with circular control areas
- Allow aircraft to pass through without collision
- Visible throughout simulation
- Defined by position and radius

## Technical Requirements

**MUST Have:**
- Single script file parameter
- 1920x1080 pixel window
- Event-based window closure
- Display hitboxes and control areas
- Handle multiple entities simultaneously
- Axis-aligned aircraft sprites and hitboxes

**SHOULD Have:**
- Timer display (top-right corner)
- Automatic simulation end when all aircraft landed/destroyed
- Sprite-based entity rendering
- Help option (-h)
- Toggle hitbox visibility (L key)
- Toggle sprite visibility (S key)

**COULD Have:**
- 3D space calculations
- Screen wrapping for aircraft
- Rotational sprites based on direction
- Boundary-following hitboxes
- Variable hitbox sizes
- Cross-screen control areas

## Constraints
- Language: C
- Graphics: CSFML library (specific functions only)
- Compilation via Makefile with `re`, `clean`, `fclean` rules
- Error code 84 on error, 0 otherwise
- Requires .legend file for script format description
