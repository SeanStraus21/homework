/*=============================================================
	COURSE:	CSC-460, assignment 1
	PROGRAMMERS: 	Sean Straus (straus21), Di Wu
	MODIFIED BY:
	LAST MODIFIED DATE:	02/05/2016
	DESCRIPTION:	Contains the functions for a default polynomial and the trapezoid generation routine for nueric quadrature
	NOTE:
	FILES:	trapezoid.cpp, makefile
	IDE/COMPILER/INTERPRETER:	GNU g++
	INSTRUCTION FOR COMPILATION AND EXECUTION:
	1. to COMPILE, run the following line
		$make
	2. to EXECUTE, run the following
		$ ./trapezoid
=============================================================*/

/**
* Polynomial Function whose integral is to be found
*/
double polynom(double x){
	return x*x + 2*x + 4;
}

/**
* Calculates a trapezoid from a starting point, a width,
*	and a function to evaluate on the resuling interval
*/
double trapezoid(double l,double w,double (f)(double)){
	double triangle,rectangle,taller,shorter;
	//evaluate f at l and l+w to get the vertical sides of the trapezoid
	taller = f(l);
	shorter = f(l+w);
	//swap to make sure taller >= shorter
	if(taller < shorter){
		double temp = taller;
		taller = shorter;
		shorter = temp;
	}
	//a trapezoid consists of up to two parts, a rectangle and a right triangle
	rectangle = shorter*w;//compute the area of the rectangle
	triangle = (taller-shorter)*w*0.5;//compute the area pf the triangle

	return triangle + rectangle;//return the sum of the areas of the rectangle and the triangle
}

/**
* create n trapezoids on the interval (l,r) as defined by polynom
* returns the sum of the areas of these trapezoids
*/
double create_trapezoids(double l,double r,int n){
	double output = 0;
	double w = (r-l)/n;//each trapezoid has a width equal to the total length divided by n
	double (*f)(double) = &polynom;
	for(int i=0;i<n;i++){
		output += trapezoid(l,w,f);
		l += w;
	}
	return output;
}

