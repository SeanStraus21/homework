
//Draws a rock at specified offsets
void draw_rock(GLshort x,GLshort y, GLshort z){
	//x,y,z
	GLshort v0[] = {0+x,0+y,0+z};//front-left
	GLshort v1[] = {100+x,0+y,0+z};//front-right
	GLshort v2[] = {0+x,0+y,100+z};//right-back
	GLshort v3[] = {100+x,0+y,100+z};//left-back
	GLshort v4[] = {50+x,100+y,50+z};//top

	glBegin(GL_TRIANGLES);

	glColor3f(0.5f, 0.5f, 0.5f);//Grey
	//front
	glVertex3sv(v0);
	glVertex3sv(v1);
	glVertex3sv(v4);
	//right
	glVertex3sv(v1);
	glVertex3sv(v3);
	glVertex3sv(v4);
	//back
	glVertex3sv(v2);
	glVertex3sv(v3);
	glVertex3sv(v4);
	//left
	glVertex3sv(v2);
	glVertex3sv(v0);
	glVertex3sv(v4);

	glEnd();
}

void draw_building(GLshort x,GLshort y, GLshort z){
	//top vertices
	GLshort v0[] = {0+x,250+y,0+z};//front-left
	GLshort v1[] = {500+x,250+y,0+z};//front-right
	GLshort v2[] = {500+x,250+y,250+z};//right-back
	GLshort v3[] = {0+x,250+y,250+z};//left-back
	//bottom vertices
	GLshort v4[] = {0+x,0+y,0+z};//front-left
	GLshort v5[] = {500+x,0+y,0+z};//front-right
	GLshort v6[] = {500+x,0+y,250+z};//right-back
	GLshort v7[] = {0+x,0+y,250+z};//left-back

	glBegin(GL_QUADS);

	glColor3f(0.5f, 0.5f, 0.5f);//Grey
	//front
	glVertex3sv(v0);
	glVertex3sv(v1);
	glVertex3sv(v5);
	glVertex3sv(v4);
	//right
	glVertex3sv(v1);
	glVertex3sv(v2);
	glVertex3sv(v6);
	glVertex3sv(v5);
	//back
	glVertex3sv(v2);
	glVertex3sv(v3);
	glVertex3sv(v7);
	glVertex3sv(v6);
	//left
	glVertex3sv(v3);
	glVertex3sv(v0);
	glVertex3sv(v4);
	glVertex3sv(v7);
	//top
	glVertex3sv(v0);
	glVertex3sv(v1);
	glVertex3sv(v2);
	glVertex3sv(v3);
	glEnd();
}

void draw_sign(GLshort x,GLshort y, GLshort z){
//top vertices
	GLshort v0[] = {0+x,50+y,3+z};//front-left
	GLshort v1[] = {100+x,50+y,3+z};//front-right
	GLshort v2[] = {0+x,50+y,0+z};//right-back
	GLshort v3[] = {100+x,50+y,0+z};//left-back
	//bottom vertices
	GLshort v4[] = {0+x,0+y,3+z};//front-left
	GLshort v5[] = {100+x,0+y,3+z};//front-right
	GLshort v6[] = {0+x,0+y,0+z};//right-back
	GLshort v7[] = {100+x,0+y,0+z};//left-back

	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);//Red
	//front
	glVertex3sv(v0);
	glVertex3sv(v1);
	glVertex3sv(v5);
	glVertex3sv(v4);
	//right
	glVertex3sv(v1);
	glVertex3sv(v2);
	glVertex3sv(v6);
	glVertex3sv(v5);
	//back
	glVertex3sv(v2);
	glVertex3sv(v3);
	glVertex3sv(v7);
	glVertex3sv(v6);
	//left
	glVertex3sv(v3);
	glVertex3sv(v0);
	glVertex3sv(v4);
	glVertex3sv(v7);
	//top
	glVertex3sv(v0);
	glVertex3sv(v1);
	glVertex3sv(v2);
	glVertex3sv(v3);
	glEnd();
}

//draws all the doodads
void draw_doodads(GLshort x, GLshort y,GLshort z){
	draw_sign(75-x,0-y,50-z);
	draw_rock(-200-x,0-y,-400-z);
	draw_sign(75-x,0-y,-800-z);
	draw_building(-250-x,0-y,-1500-z);
}
