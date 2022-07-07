# Fract-ol
a simple project where i create 3 fractals with some proprities (zoom, change colors ...), in order to be familiare with graphics stuff and GUI system
, by coding.
## You Should know :##

-to compile: gcc -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit prjt.c
-<mlx.h> : the MiniLibX library's header to access all GUI the functions.
-mlx_init() : to establish a connection to the correct graphical system, return a
void* which holds the location of our current MLX instance.
-mlx_new_window(mlx_init, width, hight, "title!"): to initializing a window with a hight
an width nd title, return a pointer to the window we have just created.
-mlx_loop(mlx_init) : to keep the window appears and open forever.
-mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xcolor)): pushing pixels to the window, but we
won't use it cause very very slow, it tries to push the pixel instantly to the window.

			** MLX Images**
-we use images for better performance(why would you use hundreds of printf
 functions when you could call it one time)so "printing" all the pixels in the memory,
 and then on the screen all at once.
-images are char*, 1 image = char pointer,your image's pixels are placed one after the
other to the right in the char pointer, Each pixel is represented by 4 chars.
-to find the pixel you want use the formula: X position * 4 + 4 * Line size * Y position.
-4 chars for one pixel: The 3 first chars are representing the color of the pixel(RGB)
the 4th pixel is the alpha.

			** How to use it **
-1 create an image: with image_pointer = mlx_new_image(mlx_pointer, width, height);
-2 get the image's char pointer : my_image_data = mlx_get_data_addr(image_pointer,
&bpp, &size_line, &endian); where &bpp(number of bits per pixels), &size_line(size
of a line/width times 4), &endian(0 or 1), you don't need to initialize them,
the function will do it for you.
-3 Fill the image: use the formula(X position * 4 + 4 * Line size * Y position)to
calculate the postition of the pixel you want on the char* then change the 3 first chars.
-4 Display the image: use mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y).

		** Mandelbrot **
-The Mandelbrot set is a fractal which is defined as the set of points c of
the complex plane for which the recurrent sequence defined by : Zn+1=Zn2 + c and
the condition Zo=0, does not tend to infinity(en module |z|).
-Mandelbrot est toujours compris entre -2.1 et 0.6 sur l’axe des abscisse et
entre -1.2 et 1.2 sur l’axe des ordonnées.
- we choose the domain 2, -2 because the suite of mandelbrot converge at 2.
-...
		** **
-events : we use it to write interactive applications in MiniLibX, There are a number of
events to which you may describe, we interest' bout those:(...).
-hook : function that gets called whenever a event is triggered, It allows you to register to any
of the aforementioned events with the call of a simple hook registration function.

-mlx_hook(): fonction in mlx.h waiting for extern events to call fonction and excute some actions.



                                                      (c) Youssef Ait Ouchaour
