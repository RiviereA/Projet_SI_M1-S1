#include "objet.h"

char presse;
int anglex, angley, x, y, xold, yold, a = 0, i = 0, j = 0, aspirage = 0, penchage = 0, deposage = 0, lancement=0;
GLfloat angle = 0;
float direction = 1;
double zoom;
int cam = 1;

texData texTeapot;

void idle()
{
	rotation();
	if(lancement)
	{
		if(!aspirage)
		{
			if (i < 99)
			{
				trans_robX = point_anim[i].x;
				trans_robZ = point_anim[i].z;
				i++;
			}
			else
			{
				if(RAxeY > -90)RAxeY = RAxeY - 2;
				else if(RAxeX < 46) RAxeX = RAxeX + 2;
				else if(aspirateurAnim < 7) aspirateurAnim = aspirateurAnim + 0.3;
				else
				{
					sleep(1);
					aspirage = 1;
				}
			}
		}
		else if (!penchage)
		{
			if (aspirateurAnim > 0) aspirateurAnim = aspirateurAnim - 0.3;
			else if(RAxeX > 0) RAxeX = RAxeX - 2;
			else if(RAxeY < 0) RAxeY = RAxeY + 2;
			else if(j < 142)
			{
				trans_robX = point_anim2[j].x;
				trans_robZ = point_anim2[j].z;
				j++;
			}
			else
			{
				penchage = 1;
			}
		}
		else if(penchage && !deposage)
		{
			if(RAxeY > -90)RAxeY = RAxeY - 2;
			else if(RAxeX < 35) RAxeX = RAxeX + 2;
			else if(aspirateurAnim < 7) aspirateurAnim = aspirateurAnim + 0.3;
			else
			{
				deposage = 1;
			}
		}
		else
		{
			if (aspirateurAnim > 0) aspirateurAnim = aspirateurAnim - 0.3;
			else if(RAxeX > 0) RAxeX = RAxeX - 2;
			else if(RAxeY < 0) RAxeY = RAxeY + 2;
		}
	}
}

void display()
{
	anim_robot();
	anim_robot2();

	//
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    switch(cam){
		case 1 :
			gluLookAt(-20.0,20.,40.0,    0.0f, -2.0f, 4.0f,    0,1,0);
			break;
		case 2 :
			gluLookAt(0.0,30.,3.0,    0.0f, 0.0f, 0.0f,    0,1,0);
			break;
		case 3 :
			gluLookAt(18.0,35.,-18.0,    5.0f, -5.0f, 0.0f,    0,1,0);
			break;
		case 4 :
			gluLookAt(9.2f, -1.0f, 3.75f,    0, -11.9, -2.75,    0,1,0);
			break;
		}

	glRotatef(angley, 1.0, 0.0, 0.0);
	glRotatef(anglex, 0.0, 1.0, 0.0);



    GLfloat ambientColor[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    //Light0
    GLfloat lightColor0[] = {.9f, .9f, .9f, 1.f};
	GLfloat lightPos0[] = {5.0f, -3.f, 0.0f, 1};

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 2.);
	//
	//
	//
  //   //Light1
     GLfloat lightColor1[] = {1.f, 1.f, 1.f, 1.0f};
	 GLfloat lightPos1[] = {9.2f, -6.0f, 3.75f, 1};
     glLightfv(GL_LIGHT1, GL_SPECULAR, lightColor1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	//
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 75.0);
     GLfloat spot_direction1[] = { 0., -1.0, 0.0 };
     glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction1);
     glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);
     glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.5);
	//
	//
	// //Light2
     GLfloat lightColor2[] = {.9f, .9f, .9f, 1.f};
	GLfloat lightPos2[] = {5.0f, -18.f, 0.0f, 1};
	//
  glLightfv(GL_LIGHT2, GL_AMBIENT, lightColor2);
     glLightfv(GL_LIGHT2, GL_POSITION, lightPos2);
     glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 2.);



	glNormal3f(0.,1.,0.);

		piece();

		glPushMatrix();
		glTranslatef(-4., -18.45, 12.);
		// glRotatef(90, 0., 1., 0.);
		glScalef(1.5, 1.5, 1.5);
		carton();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-12., -17.95, -10.);
		// glRotatef(90, 0., 1., 0.);
		glScalef(2., 2., 2.);
		carton();
		glPopMatrix();

	glPushMatrix();
	glTranslatef(-4., -20., 5.);
	glRotatef(90, 0., 1., 0.);
	glScalef(3., 3., 3.);
	chaise();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4., -20., -2);
	glRotatef(90, 0., 1., 0.);
	glScalef(3., 3., 3.);
	chaise();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(14., -20., -6);
	glRotatef(-90, 0., 1., 0.);
	glScalef(3., 3., 3.);
	chaise();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(14., -20., 0.);
	glRotatef(-90, 0., 1., 0.);
	glScalef(3., 3., 3.);
	chaise();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0., -20., 3.);
	glScalef(4., 4., 4.);
	table();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3., -12.45, 2.);
	glScalef(0.4, 0.4, 0.4);
	tasse();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7., -12.75, -8.);
	glScalef(0.18, 0.18, 0.18);
	pomme();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5., -12.3, 3.);
	glScalef(0.6, 0.6, 0.6);
	glColor3f(1., 1., 1.);
	beignet();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5., -12.3, 5.);
	glScalef(0.6, 0.6, 0.6);
	glColor3f(1., 1., 1.);
	beignet();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, -12.3, 4.);
	glScalef(0.6, 0.6, 0.6);
	glColor3f(1., 1., 1.);
	beignet();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.25, -11.7, 4);
	glScalef(0.6, 0.6, 0.6);
	glColor3f(1., 1., 1.);
	beignet();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.2, -12.45, 3.75);
	glScalef(0.4, 0.4, 0.4);
	lampe();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.,  -12.4, -9.);
	glRotatef(15,0,1,0);
	livre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3., -11.8, -9.4);
	livre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8., -12.4, 6.);
	glScalef(0.3, 0.3, 0.3);
	tuile();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7., -12.2, 6.);
	glScalef(0.3, 0.3, 0.3);
	tuile();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7.5, -12.4, 7.);
	glRotatef(15,0,1,0);
	glScalef(0.3, 0.3, 0.3);
	tuile();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8., -12.3, 7.);
	glScalef(0.3, 0.3, 0.3);
	tuile();
	glPopMatrix();


	glPushMatrix();
	if ( !texTeapot.texImage )
		texTeapot.texImage = initTex((char *) "./textures/caoutchouc.ppm", &texTeapot.texName, &texTeapot.texImageWidth, &texTeapot.texImageHeight);
	glTranslatef(6, -12.3, 0.);
	texObjet(texTeapot.texImage, texTeapot.texName, texTeapot.texImageWidth, texTeapot.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_SPHERE_MAP, GL_SPHERE_MAP);
	glutSolidTeapot(1);
	disableTex();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8, -12.3, 1.);
	glScalef(0.7, 0.7, 0.7);
	glColor3f(1., 1., 1.);
	beignet();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.15, -12.4, -3.);
	livre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.15, -12.4, -5.);
	livre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8.5, -12.4, -6.5);
	glRotatef(60,0,1,0);
	livre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0., -12.3, -3.);
	glScalef(0.4, 0.4, 0.4);
	bol();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.15, -12.65, -4.5);
	glScalef(0.15, 0.15, 0.15);
	pomme();
	glPopMatrix();

	if(!aspirage){
		glPushMatrix();
		glTranslatef(0, -11.9, -3.);
		glScalef(0.2, 0.2, 0.2);
		sucre();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -11.9, -2.75);
		glScalef(0.2, 0.2, 0.2);
		sucre();
		glPopMatrix();
	}

	if(deposage){
		glPushMatrix();
		glTranslatef(0.75, -11.9, 2.);
		glScalef(0.2, 0.2, 0.2);
		sucre();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.75, -11.9, 2.25);
		glScalef(0.2, 0.2, 0.2);
		sucre();
		glPopMatrix();
	}

	glPushMatrix();
	glTranslatef(0, -11.9, -3.25);
	glScalef(0.2, 0.2, 0.2);
	sucre();
	glPopMatrix();

	/**/

	glPushMatrix();
	glTranslatef(0.26, -11.64, -3.);
	glScalef(0.2, 0.2, 0.2);
	sucre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, -11.9, -3.);
	glScalef(0.2, 0.2, 0.2);
	sucre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, -11.9, -2.75);
	glScalef(0.2, 0.2, 0.2);
	sucre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-0.3,0);
	robot();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
	/* si on appuie sur le bouton gauche */
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		presse = 1; /* le booleen presse passe a 1 (vrai) */
		xold = x;   /* on sauvegarde la position de la souris */
		yold = y;
	}
	/* si on relache le bouton gauche */
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		presse = 0; /* le booleen presse passe a 0 (faux) */
}

void mousemotion(int x, int y)
{
	if (presse) /* si le bouton gauche est presse */
	{
		/* on modifie les angles de rotation de l'objet
	 en fonction de la position actuelle de la souris et de la derniere
	 position sauvegardee */
		anglex = anglex + (x - xold);
		angley = angley + (y - yold);
		glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
	}

	xold = x; /* sauvegarde des valeurs courante de le position de la souris */
	yold = y;
}

void keyboard(unsigned char touche, int x, int y)
{
	switch (touche)
	{
	case '0' :
		anglex = 0;
		angley = 0;
		break;
	case '1' :
		cam = 1;
		break;
	case '2' :
		cam = 2;
		break;
	case '3' :
		cam = 3;
		break;
	case '4' :
		cam = 4;
		break;
	case 'a':
		Rtot += 2;
		if (Rtot > 360)
			Rtot = 0;
		glutPostRedisplay();
		break;
	case 'A':
		Rtot -= 2;
		if (Rtot < -360)
			Rtot = 0;
		glutPostRedisplay();
		break;

	case 'z':
		RAxeX = RAxeX + 2;
		if (RAxeX > 110)
			RAxeX = 110;
		glutPostRedisplay();
		break;
	case 'Z':
		RAxeX = RAxeX - 2;
		if (RAxeX < -110)
			RAxeX = -110;
		glutPostRedisplay();
		break;

	case 'e':
		RAxeY = RAxeY + 2;
		if (RAxeY > 360)
			RAxeY = 0;
		glutPostRedisplay();
		break;
	case 'E':
		RAxeY = RAxeY - 2;
		if (RAxeY < -360)
			RAxeY = 0;
		glutPostRedisplay();
		break;

	case 'r':
		aspirateurAnim = aspirateurAnim + 0.3;
		if (aspirateurAnim > 6)
			aspirateurAnim = 6;
		glutPostRedisplay();
		break;
	case 'R':
		aspirateurAnim = aspirateurAnim - 0.3;
		if (aspirateurAnim < 0)
			aspirateurAnim = 0;
		glutPostRedisplay();
		break;

	case 'p': /* affichage du carre plein */
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glutPostRedisplay();
		break;
	case 'f': /* affichage en mode fil de fer */
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glutPostRedisplay();
		break;
	case 's': /* Affichage en mode sommets seuls */
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		glutPostRedisplay();
		break;
	case 'd':
		glEnable(GL_DEPTH_TEST);
		glutPostRedisplay();
		break;
	case 'D':
		glDisable(GL_DEPTH_TEST);
		glutPostRedisplay();
		break;
	case '-':
		zoom += 1;
		glutPostRedisplay();
		break;
	case '+':
		zoom -= 1;
		if (zoom < -6)
			zoom = -6;

		glutPostRedisplay();
		break;
	case '&':
		zoom -= 1;
		glutPostRedisplay();
	break;
	case 'g':
		lancement= 1;
		glutPostRedisplay();
		break;

	case 'q': /*la touche 'q' permet de quitter le programme */
		exit(0);
	}
}

int main(int argc, char **argv)
{
	/* initialisation de glut et creation
    de la fenetre */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Projet");

	/* Initialisation d'OpenGL */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
    glDisable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);

	/* enregistrement des fonctions de rappel */
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	//glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(mousemotion);
	glutIdleFunc(idle);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 1, 1000.0);

	glutMainLoop();
	return 0;
}
