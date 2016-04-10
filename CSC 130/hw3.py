"""
Sean Straus
Straus21
2/25/2014
Homework 3 - CSC 131
This Program simulates a memory matching game
"""

import random

class Card(object):
	def __init__(self,value):
		self._face = 0
		self._value = value
	
	def __str__(self):
		if self._face == True:
			output = str(self._value)
		else:
			output = "*"
		return output
		
	def __eq__(self,other):
		if type(self)!=type(other):
			output = False
		elif self._value == other._value:
			output = True
		else:
			output = False
		return output
			
	
class Deck(object):
	def __init__(self,cards):
		self._pairs = cards/2
		self._cards = []
		for i in range(self._pairs):
			self._cards.append(Card(i))
			self._cards.append(Card(i))
		
	def shuffle(self):
		random.shuffle(self._cards)
		
	def deal(self,index):
		 return self._cards[index]
		 
	def cardsleft(self):
		return len(self._cards)

class Game(object):
	def __init__(self,rows,columns):
		self._rows = rows
		self._columns = columns
		self._cards = rows*columns
		self._deck = Deck(self._cards)
		self._quit = False
		self._turns = 0
	
	#deals the cards into a 2D list
	def populateBoard(self):
		k = 0
		self._board = []
		self._deck.shuffle()
		for i in range(self._rows):
			self._board.append([])
			for j in range(self._columns):
				self._board[i].append(self._deck.deal(k))
				k+=1
				
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
		
	#iterates through the cards to see if any are face down. if all pairs have been found, gameover
	def isGameOver(self):
		victory = True
		for i in range(self._rows):
			for j in range(self._columns):
				if self._board[i][j]._face == False:
					victory = False
					break
		if victory == True:
			print "You Win."
		return victory
		
	#prompts the user to select a card
	def guess(self):
		print "Enter the x coordinate of a card"
		self._xcoord = int(raw_input(">"))
		print "Enter the y coordinate of a card"
		self._ycoord = int(raw_input(">"))
		if (self._xcoord <= self._columns) and (self._ycoord <= self._rows) and (self._xcoord >= 0) and (self._ycoord >= 0):
			output = self._board[self._ycoord][self._xcoord]
		else:
			output = "error"
		return output
			
	def play(self):
		self.populateBoard()
		while self._quit == False:
			self.displayBoard()
			self._card1 = self.guess()
			while self._card1 == "error":
				print "Coordinates outside gameboard. Please give coordinates on the board"
				self._card1 = self.guess()
			self._card1._face = 1
			self.displayBoard()
			self._card2 = self.guess()
			while self._card2 == "error" or self._card2._face == 1:
				if self._card2 == "error":
					print "Coordinates outside gameboard. Please give coordinates on the board"
				else:
					print "you have already selected that card. give coordinates for a facedown card"
				self._card2 = self.guess()
			self._card2._face = 1
			self.displayBoard()
			if self._card1 == self._card2:
				if self.isGameOver():
					self._quit = True
			else:
				self._card1._face = 0
				self._card2._face = 0
			
	
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

    game = Game(rows, columns)
    game.play()
	
main()
