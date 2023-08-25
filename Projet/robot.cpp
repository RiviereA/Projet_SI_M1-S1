#include "objet.h"
double Rtot;
double RAxeX;
double RAxeY;
double aspirateurAnim;
double heli;
double trans_robX = -0.5, trans_robZ = 0;

texData texMetal;
texData texPlastiqueRobot;
texData texCaoutchouc;

void rotation(){
    heli += 9;
    if(heli==360) heli=0;
    glutPostRedisplay();
}

void helicoide(int n ,double H ,double r)//nombre de points, Hauteur d'une face, rayon, pas
{
double cylindreXp[n];
double cylindreYp[n];
double cylindreZp[n];

double cylindreXg[n];
double cylindreYg[n];
double cylindreZg[n];


int i;


    for(i=0; i<n ;i++)//petit
    {
        cylindreXp[i] = double(r * cos(i*0.5));
        cylindreYp[i] = double(r * sin(i*0.5));
        cylindreZp[i] = double(H * i);

        cylindreXg[i] = 0;
        cylindreYg[i] = 0;
        cylindreZg[i] = H * i;
    }

    for(i = 0; i<n-1 ; i++){
        glBegin(GL_POLYGON);
            glColor3f(0,1,0);
            glVertex3f(cylindreXp[i], cylindreYp[i], cylindreZp[i]);
            glVertex3f(cylindreXg[i], cylindreYg[i], cylindreZg[i]);
            glVertex3f(cylindreXg[i+1], cylindreYg[i+1], cylindreZg[i+1]);
            glVertex3f(cylindreXp[i+1], cylindreYp[i+1], cylindreZp[i+1]);
        glEnd();
        }
}
void robot()
{
    if ( !texMetal.texImage )
        texMetal.texImage = initTex((char *) "./textures/metal.ppm", &texMetal.texName, &texMetal.texImageWidth, &texMetal.texImageHeight);
    if ( !texPlastiqueRobot.texImage )
        texPlastiqueRobot.texImage = initTex((char *) "./textures/plastique.ppm", &texPlastiqueRobot.texName, &texPlastiqueRobot.texImageWidth, &texPlastiqueRobot.texImageHeight);
    if ( !texCaoutchouc.texImage )
        texCaoutchouc.texImage = initTex((char *) "./textures/caoutchoucgris.ppm", &texCaoutchouc.texName, &texCaoutchouc.texImageWidth, &texCaoutchouc.texImageHeight);

    int n=4;
    Point aspirateur[n];
    aspirateur[0].x = 1;
    aspirateur[0].y = 0;
    aspirateur[1].x = 1;
    aspirateur[1].y = 0;
    aspirateur[2].x = 0.75;
    aspirateur[2].y = 1;
    aspirateur[3].x = 0.75;
    aspirateur[3].y = 1;

        glTranslatef(trans_robX, -12, trans_robZ);
        glScalef(0.4, 0.4, 0.4);

        // animation rota totale
        glPushMatrix();
        glRotatef(Rtot, 0, 1, 0);
        //coussin ->  axe
            glPushMatrix();
            glColor3f(0, 1, 0);
            glScalef(1, 0.25, 1);
            texObjet(texPlastiqueRobot.texImage, texPlastiqueRobot.texName, texPlastiqueRobot.texImageWidth, texPlastiqueRobot.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
            glutSolidSphere(2, 10, 10);
            disableTex();
            glPopMatrix();

            glPushMatrix();
            glColor3f(0.5, 0, 0);
            glTranslatef(0.0, 0.125, 0.0);
            glRotatef(-90, 1, 0, 0);
            texObjet(texMetal.texImage, texMetal.texName, texMetal.texImageWidth, texMetal.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
            glutSolidCylinder(1.75, 0.75, 20, 20);
            disableTex();
            glPopMatrix();

            glPushMatrix();
            glColor3f(0.5, 0, 1);
            glTranslatef(0.0, 0.875, 0.0);
            glRotatef(-90, 1, 0, 0);
            texObjet(texMetal.texImage, texMetal.texName, texMetal.texImageWidth, texMetal.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
            glutSolidCylinder(0.75, 2, 20, 20);
            disableTex();
            glPopMatrix();

            glPushMatrix();
            glColor3f(0.7, 0, 0);
            glTranslatef(0.0, 3.8, 0.0);
            glScalef(0.5, 2, 0.75);
            texObjet(texMetal.texImage, texMetal.texName, texMetal.texImageWidth, texMetal.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
            glutSolidCube(1);
            disableTex();
            glPopMatrix();

        // FIN coussin ->  axe
        // animation  axe

            glPushMatrix();
            glTranslatef(0, 5, 0);
            glRotatef(RAxeX, 1, 0, 0);
            glRotatef(RAxeY, 0, 1, 0);
            glTranslatef(0, -5, 0);
            // axe
                glPushMatrix();
                glColor3f(0.9, 0, 0);
                glTranslatef(0, 5, 0);
                texObjet(texCaoutchouc.texImage, texCaoutchouc.texName, texCaoutchouc.texImageWidth, texCaoutchouc.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
                glutSolidSphere(0.6, 15, 15);
                disableTex();
                glPopMatrix();

                glPushMatrix();
                glColor3f(0.9, 0, 1);
                glTranslatef(0, 5, 0);
                glRotatef(-90, 1, 0, 0);
                texObjet(texMetal.texImage, texMetal.texName, texMetal.texImageWidth, texMetal.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
                glutSolidCylinder(0.35, 3, 5, 5);
                disableTex();
                glPopMatrix();

                glPushMatrix();
                glColor3f(0.9, 0, 1);
                glTranslatef(0, 8, 0);
                glRotatef(90, 1, 0, 0);
                texObjet(texMetal.texImage, texMetal.texName, texMetal.texImageWidth, texMetal.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
                glutSolidCylinder(0.35, 3, 5, 5);
                disableTex();
                glPopMatrix();

                glPushMatrix();
                glColor3f(0.9, 0.5, 0);
                glTranslatef(0, 8, 0);
                glScalef(1, 1.5, 1.5);
                texObjet(texPlastiqueRobot.texImage, texPlastiqueRobot.texName, texPlastiqueRobot.texImageWidth, texPlastiqueRobot.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
                glutSolidCube(1.5);
                disableTex();
                glPopMatrix();

                glPushMatrix(); // louloucoupter
                glTranslatef(-0.75, 8, 0);
                glRotatef(-90, 0, 1, 0);
                glRotatef(heli,0,0,1);//Idle Rotation
                helicoide(25,0.025,1);
                glPopMatrix();

                glPushMatrix(); //antenne -> tige
                glColor3f(0.9, 0, 0.5);
                glTranslatef(-0.5, 10, 0.5);
                glRotatef(90, 1, 0, 0);
                texObjet(texMetal.texImage, texMetal.texName, texMetal.texImageWidth, texMetal.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
                glutSolidCylinder(0.10, 1, 5, 5);
                disableTex();
                glPopMatrix();

                glPushMatrix(); //antenne -> boule
                glColor3f(0.9, 0.6, 0);
                glTranslatef(-0.5, 10.15, 0.5);
                texObjet(texCaoutchouc.texImage, texCaoutchouc.texName, texCaoutchouc.texImageWidth, texCaoutchouc.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
                glutSolidSphere(0.2, 15, 15);
                disableTex();
                glPopMatrix();

                glPushMatrix(); //tube aspiratatouille
                glColor3f(0.9, 0, 1);
                glTranslatef(0.8, 7.5, 0);
                glRotatef(-90, 0, 0, 1);
                glScalef(0.5, aspirateurAnim, 0.5);
                texObjet(texPlastiqueRobot.texImage, texPlastiqueRobot.texName, texPlastiqueRobot.texImageWidth, texPlastiqueRobot.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
                tracerRevolution(aspirateur, n);
                disableTex();
                glPopMatrix();

                glPushMatrix(); //bouche
                glColor3f(0.9, 0, 0);
                glTranslatef(0.8, 7.5, 0);
                glRotatef(90, 0, 1, 0);
                texObjet(texCaoutchouc.texImage, texCaoutchouc.texName, texCaoutchouc.texImageWidth, texCaoutchouc.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
                glutSolidTorus(0.2, 0.6, 20, 20);
                disableTex();
                glPopMatrix();


            glPopMatrix(); // FIN animation

        glPopMatrix(); ///FIN animation rota totale

}
