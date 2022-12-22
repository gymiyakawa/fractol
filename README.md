# fractol
![Mandelbrot Set](https://github.com/gymiyakawa/fractol/blob/master/Screenshots/Capture%20d%E2%80%99%C3%A9cran,%20le%202022-12-20%20%C3%A0%2016.48.51.png?raw=true)
Fractol project at 42 Quebec. (115/100)

This project consisted of an introduction to graphical projects. It's requires the use of the MINILIBX, 
a visual library developed by 42.

## Instructions

Clone, make and run ./fractol

Available arguments = Julia or Mandelbrot

## COMMANDS

    WASD and ARROW KEYS - move image

    MOUSE WHEEL - zoom in/out

    ESC - Quits the program

    LEFT SHIFT - Alternate color patterns

    LEFT ALT - Alternate beween resolutions (MAX_ITERATIONS)

The higher the resolution, the more complex and accurate the set at the cost of greatly increased number of operations per pixels.

## JULIA SET CONTROLS

MOUSE RIGHT CLICK
Sets the parameters for the set using the current (x, y) position of the mouse cursor.

The default parameter is the center of the screen (HEIGHT /2, LENGTH / 2) and will produce a perfect black circle. 

The program will print the current parameters, these are the current position of the mouse cursor on the screen. MINILIBX window management determines that position (0,0) is the top left corner and bottom right is (HEIGHT, LENGTH).

That can be used to record a position or a pattern you may want to reproduce in the future.

## Recomendations

As this is program can run quite slow due to the sheer number of calculations needed to render
the image, here's a few things that can be adjusted in order to make it run smoother.

- Adjust windows size in fractal.h
  The larger the number of pixels, the exponentially larger the number of operations. Default is set at 1250 / 1250.
  Changing the aspect ratio should not deform the fractal but it will make it initallize decentralized.

-  Find the pattern you want to explore and only then up the res.
    Navigating and zooming in lower resolution will be drastically faster than doing so in higher res.

- For the Julia Set, most of the coolest patterns appear just at the border of when the set is turning from a solid single block to the fragmented recursing spirals. 
 

## Notes
Useful reading / tutorials for this project:

#### MINILIBIX
[MINILIBX Tutorial, by Aurelien Brabant](https://aurelienbrabant.fr/blog)

[MINILIBX @42Docs](https://harm-smits.github.io/42docs/libs/minilibx)

[MINILIBX Tutorial, by Gontjarow](https://gontjarow.github.io/MiniLibX/)

#### Fractal Sets

[Fractals in C/C++](https://www.geeksforgeeks.org/fractals-in-cc/)

[Mandelbrot Set Explained](http://xahlee.info/cmaci/fractal/mandelbrot.html)

Wikipedia for both sets.

## Screenshots

![1](https://github.com/gymiyakawa/fractol/blob/master/Screenshots/Capture%20d%E2%80%99%C3%A9cran,%20le%202022-12-14%20%C3%A0%2017.47.07.png?raw=true)

![2](https://github.com/gymiyakawa/fractol/blob/master/Screenshots/Capture%20d%E2%80%99%C3%A9cran,%20le%202022-12-20%20%C3%A0%2016.53.58.png?raw=true)

![3](https://github.com/gymiyakawa/fractol/blob/master/Screenshots/Capture%20d%E2%80%99%C3%A9cran,%20le%202022-12-14%20%C3%A0%2017.49.15.png?raw=true)

![4](https://github.com/gymiyakawa/fractol/blob/master/Screenshots/Capture%20d%E2%80%99%C3%A9cran,%20le%202022-12-20%20%C3%A0%2016.50.48.png?raw=true)

![5](https://github.com/gymiyakawa/fractol/blob/master/Screenshots/Capture%20d%E2%80%99%C3%A9cran,%20le%202022-12-21%20%C3%A0%2011.03.01.png?raw=true)