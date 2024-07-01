# Light Demo

This Project is inteaded to be a showcase of my MOABE Engine's Light System

Controls:
Left CTRL + Left Arrow   -> Switch to Campfire Scene
Left CTRL + Right Arrow  -> Switch to Light Culling Scene

(Only in Light Culling Scene)
Q & E        -> Switch Cameras
WASD         -> Control Space Frigate
Arrow Keys   -> Control Debug Camera
X & C        -> Tilt Debug Camera Up and Down

**Campfire Scene**
This scene showcases the abilities and a few uses for the LightBehaviour system built into the MOABE Engine. Specifically, two behaviours are being utilized in the scene. 
  - LightDayNight
Mimics a daylight cycle by rotating a MOABEDirectionalLight for a specified amount of time.

  - LightFire
Mimics the color changing of fire by blending the color of a given MOABELight back and forth between two specified colors.

**Light Culling Scene**
This scene showcases the Light Culling settings of MOABE by visualizing the effect. The blue line and point represents the position of the scene camera and pressing Q and E allows you to switch between the scene camera and the debug camera.  

There are three modes:

  1.) Default Mode
Does not run any tests and tries to render every light in the scene. If the light count goes past the limit determined by the Graphics Engine, it will render only the lights closest to the camera.

  2.) Cull By Distance Mode
Tests the distance of every light in the scene to the camera and only renders those within the specified render distance.

  3.) Cull By View & Distance Mode
Tests the distance of every light in the scene to the camera. Then, only if those are within the specified render distance, will test if the light is iIN FRONT of the camera, then only renders those lights that pass both tests.
