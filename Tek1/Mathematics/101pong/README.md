# 101pong

## Description

Mathematical simulation program for a 3D version of the classic Pong game. The program calculates ball physics including velocity vectors, future positions, and collision angles with a paddle in 3D space.

## Objective

Implement a `101pong` program that must:
- Calculate the velocity vector of a ball based on two position points
- Predict ball coordinates after a given time shift
- Determine if and at what angle the ball will hit the paddle
- Handle 3D ball motion with the paddle located in the (Oxy) plane (z = 0)

### Calculations Required

- **Velocity Vector**: Calculate from two consecutive ball positions
- **Future Position**: Predict ball coordinates after time shift n
- **Collision Detection**: Determine if ball reaches the paddle (z = 0)
- **Incidence Angle**: Calculate angle between 0 and 90 degrees when collision occurs

### Parameters

- `x0 y0 z0`: Ball coordinates at time t-1
- `x1 y1 z1`: Ball coordinates at time t
- `n`: Time shift (≥ 0, integer)

## Constraints
- Error code 84 on error, 0 otherwise
- Error messages on error output
- Precise float number handling required
