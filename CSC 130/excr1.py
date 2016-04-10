"""
Sean Straus
Straus21
3/27/2014
Extra Credit 1 - CSC 131
This Program runs a memory matching game in a GUI
"""

from Tkinter import *
import tkMessageBox
import random

class Card(object):
	def __init__(self,value):
		self.face = 0
		self.value = value
	
	def __str__(self):
		if self.face == True:
			output = str(self.value)
		else:
			output = "*"
		return output
		
	def __eq__(self,other):
		if type(self)!=type(other):
			output = False
		elif self.value == other.value:
			output = True
		else:
			output = False
		return output
			
	
class Deck(object):
	def __init__(self,cards):
		self.pairs = cards/2
		self.cards = []
		for i in range(self.pairs):
			self.cards.append(Card(i))
			self.cards.append(Card(i))
		
	def shuffle(self):
		random.shuffle(self.cards)
		
	def deal(self,index):
		 return self.cards[index]
		 
	def cardsleft(self):
		return len(self.cards)

class Game(object):
	def __init__(self,rows,columns):
		self.rows = rows
		self.columns = columns
		self.cards = rows*columns
		self.deck = Deck(self.cards)
		self.quit = False
		self.turns = 0
		self.populateBoard()
	
	#deals the cards into a 2D list
	def populateBoard(self):
		k = 0
		self.board = []
		self.deck.shuffle()
		for i in range(self.rows):
			self.board.append([])
			for j in range(self.columns):
				self.board[i].append(self.deck.deal(k))
				k+=1
				
	#iterates through the cards to see if any are face down. if all pairs have been found, gameover
	def isGameOver(self):
		victory = True
		for i in range(self.rows):
			for j in range(self.columns):
				if self._board[i][j].face == False:
					victory = False
					break
		if victory == True:
			print "You Win."
		return victory
		
"""
....................................................................................
GUI CLASSES
The Main GUI Frame
Contains the game class that stores the memory matching game
Stores Images in a list
Stores buttons in a list
.....................................................................................
"""

class Window(Frame):
	def __init__(self,game):
		Frame.__init__(self)
		self.master.title("Memory Matching Game")
		self.grid()
		self.pane1 = Frame(self)
		self.pane1.grid(column = 0, row = 0)
		self.pane2 = Frame(self)
		self.pane2.grid(column = 0,row = 1)
		self.game = game
		
		#create image list
		self.images = []
		suits = ["h","c","s","d"]
		for i in range(3):
			for j in range(9):
				self.images.append(PhotoImage("DECK/"+str(j)+suits[i]+".gif"))
		self.back = PhotoImage("DECK/b.gif")
		
		#create widgets
		self.deal_btn = Button(self.pane1, text = "Deal", command = self.new_game)
		self.deal_btn.grid(column = 0, row = 0)
		self.show_btn = Button(self.pane1, text = "Show All", command = self.show_all)
		self.show_btn.grid(column = 1, row = 0)
		
		#create button list
		self.card_btn = []
		k = 0
		for i in range(self.game.columns):
			for j in range(self.game.rows):
				self.card_btn.append(Button(self.pane2,text = str(k), image = self.back ,command = (lambda: self.guess(int(text)))))
				(self.card_btn[k]).grid(column = i, row = j)
				k+=1
		
	#Run Game Loop
	
	#shows the cards on the board
	def displayBoard(self):
		output = "   "
		for i in range(self._columns):
			output += str(i)+" "
		output += "\n  "
		for j in range(self._columns):
			output += "__"
		output += "\n"
		for i in range(self._rows):
			output += str(i)+"| "
			for j in range(self._columns):
				output += (str(self._board[i][j]) + " ")
			output += "\n"
		print output
		
	def show_all(self):
		for i in range(len(self.game.deck.cards)):
			self.game.deck.cards[i].face = 1
		
	def new_game(self):
		self.game = Game(self.game.rows,self.game.columns)
		self.card_btn = []
		k = 0
		for i in range(self.game.columns):
			for j in range(self.game.rows):
				self.card_btn.append(Button(self.pane2,text = str(self.game.deck.cards[k])))
				self.card_btn[k].grid(column = i, row = j)
				k+=1
				
	def guess(self,i):
		self.game.deck.cards[i].face = 1
"""
...............................................................................................
TOP LEVEL FUNCTIONS
main function, instantiation etc.
...............................................................................................
"""
		
def main():
	while True:
		# Force user to enter valid value for number of rows
		while True:
			rows = raw_input("Enter number of rows ")
			if rows.isdigit() and ( 1 <= int(rows) <= 9):
				rows = int(rows)
				break
			else:
				print "    ***Number of columns must be between 1 and 9! Try again.***"
				# Adding *** an indenting error message makes it easier for the user to see
		
		# Force user to enter valid value for number of columns
		while True:
			columns = raw_input("Enter number of columns ")
			if columns.isdigit() and ( 1 <= int(columns) <= 9):
				columns = int(columns)
				break
			else:
				print "    ***Number of columns must be between 1 and 9! Try again.***"
		
		if rows * columns % 2 == 0:
			break
		else:
			print "    ***The value of rows X columns must be even. Try again.***"
	#Run GUI
	game = Game(rows,columns)
	gui = Window(game)
	gui.mainloop()

	
main()