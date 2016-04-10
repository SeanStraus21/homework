"""
Sean Straus
Straus21
1/28/2014
Homework 1 - CSC 131
Program that uses 2D lists to verify whether or not a Sudoku solution is valid
"""

def checkLst(lst):
	"""returns True if lst (may represent row, column or a block) has the values 1 to 9"""
	chk = [1,2,3,4,5,6,7,8,9]
	output = True
	for i in range(len(lst)):
		if lst[i] in chk:
			chk.remove(lst[i])
		else:
			output = False
	if len(chk) > 0:
		output = False
	return output
		
		
		

def isValid(grid):
	"""returns True if solution is valid and False otherwise"""
	valid = True
	#verify that every row has the numbers from 1 to 9
	for i in range(0,9):
		if checkLst(grid[i]) == False:
			return False
	#verify that every column has the numbers from 1 to 9
	
	for i in range(0,9):
		column = []
		#generate column lists
		for j in range(0,9):
			column.append(grid[i][j])
		if checkLst(column) == False:
			return False
			
	#verify that every column has the numbers from 1 to 9
	#your code goes here

	#verify that every 3-by-3 box has the numbers from 1 to 9
	#Boxes will be processed in a left to right, top to bottom order
	startRow = 0 #row coordinate of starting cell in a 3-by-3 box
	startColumn = 0 #column coordinate of starting cell in a 3-by-3 box
	for boxNumber in range(0, 9): 
		currentBox = []
		for row in range(startRow, startRow + 3):
			for column in range(startColumn, startColumn + 3):
				currentBox.append(grid[row][column])
		#display(currentBox)
		if checkLst(currentBox) == False:
			return False
		startColumn += 3 #time to move to the next box
		if startColumn == 9: #time to move to the next row of boxes
			startColumn = 0
			startRow += 3
			
	#if here, then solution must have passed all verification
	return True 


def main():
	file_names_list = ["sudoku1.txt", "sudoku2.txt", "sudoku3.txt", "sudoku1b.txt", "sudoku2b.txt", "sudoku3b.txt"]
	
	for file_name in file_names_list:
		grid = [] #to store solution read from file
		f = open(file_name)
		for line in f:
			line = line.split()
			line = map(int, line) # convert strings to integres
			grid.append(line)

		if isValid(grid):
			print "valid solution"
		else:
			print "invalid solution"
        

main()   

