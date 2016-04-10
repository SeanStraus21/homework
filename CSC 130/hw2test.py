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

def main():
	x = input("Enter x coordinate for the center of circle 1: ")
	y = input("Enter y coordinate for the center of circle 1: ")
	r = input("Enter the radius of circle 1: ")
	c1 = Circle2D(x, y, r)
	print c1
	
	x = input("\nEnter x coordinate for the center of circle 2: ")
	y = input("Enter y coordinate for the center of circle 2: ")
	r = input("Enter the radius of circle 2: ")
	c2 = Circle2D(x, y, r)
	print c2

	#Test the getArea() and getPerimeter() methods
	print "\nArea of a %s is %0.2f" % (c1, c1.getArea())
	print "Perimeter of a %s is %0.2f" % (c1, c1.getPerimeter())

	print "\nArea of a %s is %0.2f" % (c2, c2.getArea())
	print "Perimeter of a %s is %0.2f" % (c2, c2.getPerimeter())
	#-------------------

	#Test containsPoint() method
	print "\nResult of c1.containsPoint(c2.getX( ), c2.getY( )) is",
	print c1.containsPoint(c2.getX( ), c2.getY( ))

	#Test contains() method
	if c1.contains(c2):
		print "\n%s contains %s" % (c1, c2)
	else: 
		print "\n%s does not contain %s" % (c1, c2)
										
	print "\nResult of c2.contains(c1) is",
	print c2.contains(c1)
	#----------------

	#Test overlap() method
	if c1.overlaps(c2):
		print "\n%s overlaps with %s" % (c1,c2)
	else: 
		print "\n%s does not overlap with %s" % (c1,c2)
	#--------------

	#Test overloaded in operator                                     
	print "\nResult of c2 in c1 is", c2 in c1                     

	#Testing overloaded comparison and equality operators
	#Something similar to this
	print "\nTesting overloaded comparison operators..."
	print "c1 == c2?", c1 == c2
	print "c1 != c2?", c1 != c2
	print "c1 < c2?", c1 < c2
	print "c1 <= c2?", c1 <= c2
	print "c1 > c2?", c1 > c2
	print "c1 >= c2?", c1 >= c2
	print 'c1 == "Hello"?', c1 == "Hello"
	print 'c1 != "Hello"?', c1 != "Hello"
	
main()

		