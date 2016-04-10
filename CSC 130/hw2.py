"""
Sean Straus
Straus21
1/28/2014
Homework 2 - CSC 131
Definition of a python class Circle2D
"""


import math

class Circle2D(object):
	#initialize variables x, y, and radius
	def __init__(self, x = 0, y = 0, rad = 0):
		self._x = x
		self._y = y
		self._rad = rad
	#return a string representation of the circle
	
	def __str__(self):
		return "circle at (%g,%g) and radius %g" %(self._x, self._y, self._rad)
		
	#returns the x coordinate of the circle
	def getX(self):
		return self._x
		
	#returns the y coordinate of the circle
	def getY(self):
		return self._y
		
	#returns the area of the circle
	def getArea(self):
		area = math.pi*self._rad**2
		return area
		
	#returns the perimeter of the circle
	def getPerimeter(self):
		perimeter = 2*math.pi*self._rad
		return perimeter
		
	#checks if a point is within the circle
	def containsPoint(self,x,y):
		inpnt = False
		#check if the distance from the point to the center of the circle is less or equal to the radius
		if math.sqrt((x - self._x)**2+(y - self._y)**2) <= self._rad:
			inpnt = True
		return inpnt
		
	#checks if circle is within the circle
	def contains(self,other):
		incir = False
		dist = math.sqrt((other._x - self._x)**2+(other._y - self._y)**2)
		#check if the distance from the point to the center of the circle is less or equal to the radius
		if (dist + other._rad) <= self._rad:
			incir = True
		return incir
		
	def overlaps(self,other):
		ovcir = False
		dist = math.sqrt((other._x - self._x)**2+(other._y - self._y)**2)
		#check if the distance + the radius of the other circle exceeds the boundaries of the first circle, but the distance is less than the sum of the two radii
		if (dist + other._rad) > self._rad and dist < (other._rad + self._rad):
			ovcir = True
		return ovcir		
	#checks if circle is within the circle (called with the keyword "in")
	def __contains__(self,other):
		incir = False
		dist = math.sqrt((other._x - self._x)**2+(other._y - self._y)**2)
		#check if the distance from the point to the center of the circle is less or equal to the radius
		if (dist + other._rad) <= self._rad:
			incir = True
		return incir
	
	#compares 
	def __cmp__(self,other):
		if self._rad == other._rad:
			output = 0
		elif self._rad > other._rad:
			output = 1
		elif self._rad < other._rad:
			output = -1
		return output
	#checks to see if the radius of two circles are the same
	def __eq__(self,other):
		eq = True
		if type(self) != type(other):
			eq = False
		elif self._rad != other._rad:
			eq = False
		return eq
		
	#checks to see if the radius of two circles are different
	def __ne__(self,other):
		ne = True
		if type(self) == type(other):
			if self._rad == other._rad:
				ne = False
		return ne