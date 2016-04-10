"""
Sean Straus
Straus21
3/18/2014
Lab 7 - CSC 131
This Program creates a canvas
"""

from Tkinter import *

class Window(Frame):
	
	def __init__(self):
		Frame.__init__(self)
		self.master.title("GUIs drawing geometric shapes")
		self.grid()
		self.pane1 = Frame(self)
		self.pane1.grid()
		self.pane2 = Frame(self)
		self.pane2.grid()
	
		# Create and add the widgets to the frame.
		# Data containers for entry fields
		self.fill = IntVar(value = 0)
		self.shape = IntVar(value = 0)
		
		# Create Widgets
		self.canvas = Canvas(self.pane1, width = 300, height = 300,bg = "white")
		self.canvas.grid(row = 0, column = 0)
		self.fill_btn = Checkbutton(self.pane2, text = "Fill", variable = self.fill, onvalue = 1, offvalue = 0)
		self.rect_btn = Radiobutton(self.pane2, text = "Rectangle",variable = self.shape, value = 1, command = self.draw_shape)
		self.oval_btn = Radiobutton(self.pane2, text = "Oval", variable = self.shape, value = 2, command = self.draw_shape)
		self.clear_btn = Button(self.pane2, text = "Clear", command = self.clear_canvas)
		self.rect_btn.grid(row = 1, column = 0)
		self.oval_btn.grid(row = 1, column = 1)
		self.fill_btn.grid(row = 1, column = 2)
		self.clear_btn.grid(row = 1, column = 3)
		
	
	def draw_shape(self):
		if self.shape.get() == 1:
			self.canvas.create_rectangle(50,50,250,250,fill = ("red" if self.fill.get() == 1 else None),tags = "rectangle")
		if self.shape.get() == 2:
			self.canvas.create_oval(50,100,250,200,fill = ("yellow" if self.fill.get() == 1 else None), tags = "oval")


	# Clear canvas
	def clear_canvas(self):
		self.canvas.delete("rectangle", "oval")
		self.shape.set(0)

def main():
	Window().mainloop()
	
main()
