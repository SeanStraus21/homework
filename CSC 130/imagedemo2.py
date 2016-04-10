"""
File: imagedemo.py

Displays an image in a window.
"""

from Tkinter import *

class ImageDemo(Frame):

    def __init__(self):
        """Sets up the window and widgets."""
        Frame.__init__(self, bg = "blue")
        self.master.title("Image Demo")
        self.master["relief"] = GROOVE
        self.master["borderwidth"] = 5
        self["relief"] = RAISED
        self["borderwidth"] = 5
        self.master.rowconfigure(0, weight = 1)
        self.master.columnconfigure(0, weight = 1)

        self.grid(sticky= E + W +N+S)
        self._image = PhotoImage(file = "smokey.gif")
        self._imageLabel = Label(self, image = self._image, bg = "purple")
        self._imageLabel.grid(sticky= E + W +N+S)
        self._textLabel = Label(self, background = "green",
                                fg = "pink", relief= GROOVE, borderwidth = 5,
                                text = "Smokey the cat")
        self._textLabel.grid(pady = 10, ipady = 10, ipadx = 50,
                             sticky= E + W +N+S)
        self.rowconfigure(0, weight = 1)
        self.rowconfigure(1, weight = 1)
        self.columnconfigure(0, weight = 1)


        

def main():
    """Instantiate and pop up the window."""
    ImageDemo().mainloop()

main()
