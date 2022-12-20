# fractol

Fractol project at 42 Quebec.

This project consisted of an introduction to graphical projects. It's requires the use of the MINILIBX, 
a visual library developed in house.

## Instructions

Clone, make and run ./fractol

Available arguments = Julia or Mandelbrot

## COMMANDS

$
WASD and ARROW KEYS - move image
MOUSE WHEEL - zoom in/out
ESC - Quits the program
LEFT SHIFT - Alternate color patterns
LEFT ALT - Alternate beween resolutions (MAX_ITERATIONS). 
$
    The higher the resolution, the more complex and accurate the set at the cost of 
    greatly increased number of operations per pixels.
    
## JULIA SET CONTROLS

MOUSE RIGHT CLICK
Sets the parameters for the set using the current (x, y) position of the mouse cursor.

## Recomendations

As this is program can run quite slow due to the sheer number of calculations needed to render
the image, here's a few things that can be adjusted in order to make it run smoother.

- Adjust windows size in fractal.h
  The larger the number of pixels, the exponentially larger the number of operations. Default is set at 1250 / 1250.
  Changing the aspect ratio should not deform the fractal but it will make it initallize decentralized.

 - Pick a spot on low resolution, zoom in and then change iterations as needed. 
  Navigating while in the lowest setting (25 Iterations) is a lot smoother, but the image really only comes alive once you
  pump those numbers up. 
  
  

