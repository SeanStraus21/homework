"""
File: AnimationDemo.py

"""
from Tkinter import *

class AnimationDemo: 
    def __init__(self):
        window = Tk() # Create a window
        window.title("Animation Demo") # Set a title
        
        width = 250 # Width of the canvas
        canvas = Canvas(window, bg = "white", width = 250, height = 50)
        canvas.grid()
        
        x = 0 # Starting x position
        canvas.create_text(x, 30, text = "Message moving?", tags = "text", anchor = W)
        
        dx = 1
        while True:
            canvas.move("text", dx, 0) # Move text dx unit
            canvas.after(15) # Sleep for 15 milliseconds
            canvas.update() # Update canvas
            if x < width:
                x += dx  # Get the current position for string
            else:
                x = 0 # Reset string position to the beginning
                canvas.delete("text") 
                # Redraw text at the beginning
                canvas.create_text(x, 30, text = "Message moving?", 
                    tags = "text", anchor = W)
                

def main():
    """Instantiate and pop up the window."""
    AnimationDemo().mainloop()  # Create an event loop

main()

