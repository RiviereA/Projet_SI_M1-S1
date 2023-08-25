#include "objet.h"

texData texBois;
texData texChaise;
texData texLivre;
texData texCarton;
texData texPage;

void table()
{
    if ( !texBois.texImage )
      texBois.texImage = initTex((char *) "./textures/table.ppm", &texBois.texName, &texBois.texImageWidth, &texBois.texImageHeight);

    float TableX = 2.5;      //Table's X size
    float TableY = 4.0;      //Table's Y size
    float TableHeight = 1.5; //Table's Height
    float diametreCyl = 0.15;
    int stack = 32;
    int slices = 32;

    glPushMatrix();
    glTranslatef(0.0, 0.0, 1.0);
    //glColor3f(0.5, 0.25, 0.0);
    glRotatef(-90, 1.0, 0.0, 0.0);

    // Pieds de table
    texObjet(texBois.texImage, texBois.texName, texBois.texImageWidth, texBois.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCylinder(diametreCyl, TableHeight, slices, stack);
    disableTex();
    glPushMatrix();
    glTranslatef(TableX, 0.0, 0.0);
    texObjet(texBois.texImage, texBois.texName, texBois.texImageWidth, texBois.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCylinder(diametreCyl, TableHeight, slices, stack);
    disableTex();

    glPushMatrix();
    glTranslatef(0.0, TableY, 0.0);
    texObjet(texBois.texImage, texBois.texName, texBois.texImageWidth, texBois.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCylinder(diametreCyl, TableHeight, slices, stack);
    disableTex();

    glPushMatrix();
    glTranslatef(-TableX, 0.0, 0.0);
    texObjet(texBois.texImage, texBois.texName, texBois.texImageWidth, texBois.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCylinder(diametreCyl, TableHeight, slices, stack);
    disableTex();

    //    Table rectangle
    // glPushMatrix();
    // glTranslatef(TableX/2.0, -TableY/2, TableHeight);
    // glScalef(TableX+0.5, TableY+0.5, 0.25);
    // glutSolidCube(1);                           //Board of Table
    // glPopMatrix();

    //    Table
    glPushMatrix();
    glTranslatef(TableX / 2, -TableY / 2, TableHeight);
    glScalef(TableX - 0.5, TableY - 0.5, 0.25);
    texObjet(texBois.texImage, texBois.texName, texBois.texImageWidth, texBois.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCylinder(1, TableHeight, slices, stack);
    disableTex();

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void piedChaise()
{
    int nb_points_socle = 7;

    Point socle[nb_points_socle];
    socle[0].x = 0;
    socle[0].y = -0.36;
    socle[1].x = 0.;
    socle[1].y = 0.;
    socle[2].x = 0.54;
    socle[2].y = 0.;
    socle[3].x = 0.44;
    socle[3].y = 0.58;
    socle[4].x = 0.32;
    socle[4].y = 0.9;
    socle[5].x = 0.;
    socle[5].y = 1.26;
    socle[6].x = 0.;
    socle[6].y = 1.7;

    texObjet(texBois.texImage, texBois.texName, texBois.texImageWidth, texBois.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    tracerRevolution(socle, nb_points_socle);

}

void formeChaise()
{

    int nb_points_socle = 12;

    Point socle[nb_points_socle];
    socle[0].x = 0;
    socle[0].y = 3.;
    socle[1].x = 0.;
    socle[1].y = 2.8;
    socle[2].x = 0.27;
    socle[2].y = 2.33;
    socle[3].x = 0.29;
    socle[3].y = 1.97;
    socle[4].x = 0.38;
    socle[4].y = 1.58;
    socle[5].x = 0.8;
    socle[5].y = 1.26;
    socle[6].x = 1.13;
    socle[6].y = 0.84;
    socle[7].x = 1.13;
    socle[7].y = 0.84;
    socle[8].x = 0.96;
    socle[8].y = 0.31;
    socle[9].x = 0.75;
    socle[9].y = 0.;
    socle[10].x = 0.;
    socle[10].y = 0.;
    socle[11].x = 0.;
    socle[11].y = -1.;

    texObjet(texBois.texImage, texBois.texName, texBois.texImageWidth, texBois.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    tracerRevolution(socle, nb_points_socle);

}

void chaise()
{
    if ( !texBois.texImage )
        texBois.texImage = initTex((char *) "./textures/dossierchaise.ppm", &texBois.texName, &texBois.texImageWidth, &texBois.texImageHeight);
    if ( !texChaise.texImage )
        texChaise.texImage = initTex((char *) "./textures/piedchaise.ppm", &texChaise.texName, &texChaise.texImageWidth, &texChaise.texImageHeight);

    float chaiseX = 1.5;
    float chaiseHeight = 1.5;
    float diametreCyl = 0.125;
    int stack = 32;
    int slices = 32;

    glPushMatrix();
    glTranslatef(0.0, 0.0, 1.0);
    //glColor3f(0.5, 0.25, 0.0);
    glRotatef(-90, 1.0, 0.0, 0.0);

    // Pieds et adossoir de table
    texObjet(texBois.texImage, texBois.texName, texBois.texImageWidth, texBois.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCylinder(diametreCyl, chaiseHeight, slices, stack);
    disableTex();

    glPushMatrix();
    glScalef(0.32,0.32,0.32);
    glRotatef(90,1.0,0.,0.);

    //piedChaise();
    glPopMatrix();
    disableTex();

    glPushMatrix();
    glTranslatef(chaiseX, 0.0, 0.0);
    texObjet(texBois.texImage, texBois.texName, texBois.texImageWidth, texBois.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCylinder(diametreCyl, chaiseHeight, slices, stack);
    disableTex();

    glPushMatrix();
    glScalef(0.32,0.32,0.32);
    glRotatef(90,1.0,0.,0.);
    //piedChaise();
    glPopMatrix();
    disableTex();

    glPushMatrix();
    glTranslatef(0.0, chaiseX, 0.0);
    texObjet(texBois.texImage, texBois.texName, texBois.texImageWidth, texBois.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCylinder(diametreCyl, chaiseHeight, slices, stack);
    disableTex();

    glPushMatrix();
    glScalef(0.32,0.32,0.32);
    glRotatef(90,1.0,0.,0.);
    //piedChaise();
    glPopMatrix();
    disableTex();

    glPushMatrix();
    glTranslatef(-chaiseX, 0.0, 0.0);
    texObjet(texBois.texImage, texBois.texName, texBois.texImageWidth, texBois.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCylinder(diametreCyl, chaiseHeight, slices, stack);
    disableTex();

    glPushMatrix();
    glScalef(0.32,0.32,0.32);
    glRotatef(90,1.0,0.,0.);
    //piedChaise();
    glPopMatrix();
    disableTex();

    //    support
    glPushMatrix();
    glTranslatef(chaiseX / 2.0, -chaiseX / 2, chaiseHeight);
    glScalef(chaiseX + 0.25, chaiseX + 0.25, 0.25);
    texObjet(texChaise.texImage, texChaise.texName, texChaise.texImageWidth, texChaise.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCube(1); //Board of Table
    glPopMatrix();
    disableTex();

    glPushMatrix();
    glTranslatef(0., 0.0, chaiseX);
    texObjet(texBois.texImage, texBois.texName, texBois.texImageWidth, texBois.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCylinder(diametreCyl, chaiseHeight + 0.5, slices, stack);
    disableTex();

    glPushMatrix();
    glRotatef(90,1.0,0.,0.);
    glTranslatef(0.,chaiseHeight+0.5,0.);
    glScalef(0.18,0.18,0.18);
    texObjet(texBois.texImage, texBois.texName, texBois.texImageWidth, texBois.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidSphere(1,20,20);
    //formeChaise();
    glPopMatrix();
    disableTex();

    glPushMatrix();
    glTranslatef(chaiseX, 0.0, 0.0);
    texObjet(texBois.texImage, texBois.texName, texBois.texImageWidth, texBois.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCylinder(diametreCyl, chaiseHeight + 0.5, slices, stack);
    disableTex();

    glPushMatrix();
    glRotatef(90,1.0,0.,0.);
    glTranslatef(0.,chaiseHeight+0.5,0.);
    glScalef(0.18,0.18,0.18);
    texObjet(texBois.texImage, texBois.texName, texBois.texImageWidth, texBois.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidSphere(1,20,20);
    //formeChaise();
    glPopMatrix();
    disableTex();


    glPushMatrix();
    glTranslatef(-chaiseX / 2, 0.0, chaiseHeight);
    glScalef(chaiseX, 0.25, 0.5);
    texObjet(texChaise.texImage, texChaise.texName, texChaise.texImageWidth, texChaise.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCube(1);
    disableTex();

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void livre()
{
    if ( !texLivre.texImage )
        texLivre.texImage = initTex((char *) "./textures/carton.ppm", &texLivre.texName, &texLivre.texImageWidth, &texLivre.texImageHeight);
        
    if ( !texPage.texImage )
        texPage.texImage = initTex((char *) "./textures/ceramique.ppm", &texPage.texName, &texPage.texImageWidth, &texPage.texImageHeight);

    float cartonX = 1.5;
    float cartonY = 1.;
    float cartonHeight = 0.5;
    float cartonEpais = 0.1;

    glPushMatrix();
    glScalef(cartonX, cartonEpais, cartonY);
    texObjet(texLivre.texImage, texLivre.texName, texLivre.texImageWidth, texLivre.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCube(1);
    disableTex();
    glPopMatrix();

    glPushMatrix();
    // glColor3f(0.4,0.,0.8);
    glTranslatef(0., cartonHeight, 0.);
    glScalef(cartonX, cartonEpais, cartonY);
    texObjet(texLivre.texImage, texLivre.texName, texLivre.texImageWidth, texLivre.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCube(1);
    disableTex();
    glPopMatrix();

    glPushMatrix();
    // glColor3f(0.4,0.,0.8);
    glRotatef(90., 1., 0., 0.);
    glTranslatef(0., -cartonHeight, -cartonHeight / 2);
    glScalef(cartonX, cartonEpais, cartonHeight);
    texObjet(texLivre.texImage, texLivre.texName, texLivre.texImageWidth, texLivre.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCube(1);
    disableTex();
    glPopMatrix();

    glPushMatrix();
    //glColor3f(1., 1., 1.);
    glTranslatef(0, 2 * cartonEpais + (cartonEpais / 2), -cartonEpais / 2);
    glScalef(cartonX - cartonEpais * 2, cartonHeight - cartonEpais, cartonY - cartonEpais);
    texObjet(texPage.texImage, texPage.texName, texPage.texImageWidth, texPage.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    glutSolidCube(1);
    disableTex();
    glPopMatrix();
}

void carton()
{
	if ( !texCarton.texImage ) texCarton.texImage = initTex((char *) "./textures/carton.ppm", &texCarton.texName, &texCarton.texImageWidth, &texCarton.texImageHeight);

	texObjet(texCarton.texImage, texCarton.texName, texCarton.texImageWidth, texCarton.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_SPHERE_MAP, GL_SPHERE_MAP);
	glPushMatrix();

		glScalef(1.5,1.0,1.0);
		glBegin(GL_QUADS);


		glColor3ub(255,255,255);
		glVertex3d(1,-1,1);
		glVertex3d(1,-1,-1);
		glVertex3d(1,1,-1);
		glVertex3d(1,1,1);


		glVertex3d(-1,1,1);
		glVertex3d(-1,1,-1);
		glVertex3d(-1,-1,-1);
		glVertex3d(-1,-1,1);

		glVertex3d(1,1,-1);
		glVertex3d(1,-1,-1);
		glVertex3d(-1,-1,-1);
		glVertex3d(-1,1,-1);

		glVertex3d(1,-1,1);
		glVertex3d(1,1,1);
		glVertex3d(-1,1,1);
		glVertex3d(-1,-1,1);

		glPushMatrix();
			glColor3f(1.,0.,0.);
			glVertex3d(-1,1,1);
			glVertex3d(-1,0,2);
			glVertex3d(1,0,2);
			glVertex3d(1,1,1);

		glPopMatrix();

		glPushMatrix();
			glColor3f(1.,0.,0.);
			glVertex3d(-1,1,-1);
			glVertex3d(-1,0,-2);
			glVertex3d(1,0,-2);
			glVertex3d(1,1,-1);
		glPopMatrix();

		glPushMatrix();
			glColor3f(1.0,0.,0.);
			glVertex3d(1,1,-1);
			glVertex3d(1,1,1);
			glVertex3d(1.5,0,1);
			glVertex3d(1.5,0,-1);
		glPopMatrix();

		glPushMatrix();
			glColor3f(1.0,0.,0.);
			glVertex3d(-1,1,-1);
			glVertex3d(-1,1,1);
			glVertex3d(-1.5,0,1);
			glVertex3d(-1.5,0,-1);
		glPopMatrix();


		glColor3ub(0,0,255); //face bleue
		glVertex3d(-1,-1,1);
		glVertex3d(-1,-1,-1);
		glVertex3d(1,-1,-1);
		glVertex3d(1,-1,1);

		glEnd();

	glPopMatrix();

	disableTex();
}

/*void dessin()
{
    glutSolidTeapot(1.);

    glPushMatrix();
    chaise();
    glPopMatrix();

    table();
    glPushMatrix();
    glColor3f(0.4, 0., 0.8);
    carton();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8, 0., 0.8);
    glTranslatef(0., 0.6, 0.3);
    carton();
    glPopMatrix();
}*/
