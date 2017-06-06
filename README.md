A simple one-button game. A bird is flying towards some obstacles and you have to click the mouse button to maneuver it across. Unfortunately, the program uses "simplecpp", a library developed by IIT-B. You'll have to install it first to make this work.

Features used in the program:

1) Class implementation: Our program contains an "obstruction" class and a "bird" class. The data members of these classes cannot be directly accessed outside (data abstraction). For example, the y-coordinate of a "bird" object cannot be changed directly except by using the member functions "fly" or "jump".

2) Inheritance: An obstruction consists of two rectangles with a 'hole' in the middle. To reflect this class "obstruction" contains two Rectangle-class type data members. This is an example of a has-a type inheritance. 

3) Event handling: Our program checks if the user has clicked the mouse button or not and if he has then it makes the "bird" "jump".

2) Dynamic memory allocation: Members of the "obstruction" class are dynamically allocated. These obstructions progressively move from the right end of the window to the left. Our program deletes an "obstruction" if it has reached the left end of the window-screen. A new "obstruction" is created if the previously created "obstruction" has travelled upto a particular distance from the right edge of the window. Every "obstruction" points to its next "obstruction". Using dynamic memory allocation our program will work fine for any value of "window_width". If the "window_width" is large then more obstacles will be present at a particular moment on the screen. It also makes it easier to track which "obstruction" is nearest to the "bird" and may have a chance of hitting it.

3) Recursive function: If the function setting the position of the 'hole' in an "obstruction" sets the hole outside the window-limits it is called recursively again.

5) Random function of stdlib: The position of the 'hole' in an "obstruction" is randomly set within a particular range of the position of the hole of the previous "obstruction".
