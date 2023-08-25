#include "objet.h"

texData texMur;
texData texSol;

void mur()
{
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0, 0.0);     glVertex3f(-.5, -.5, 0.);
    glTexCoord2f(1.0, 0.0);     glVertex3f(.5, -.5, 0.);
    glTexCoord2f(1.0, 1.0);     glVertex3f(.5, .5, 0.);
    glTexCoord2f(0.0, 1.0);     glVertex3f(-.5, .5, 0.);

    glEnd();
    glFlush();
}

void piece()
{
    if ( !texMur.texImage ) 
        texMur.texImage = initTex((char *) "./textures/mur.ppm", &texMur.texName, &texMur.texImageWidth, &texMur.texImageHeight);
    if ( !texSol.texImage ) 
        texSol.texImage = initTex((char *) "./textures/moquette.ppm", &texSol.texName, &texSol.texImageWidth, &texSol.texImageHeight);

    glPushMatrix();
        //glColor3f(0.9, 0.5, 0.5);
        texObjet(texMur.texImage, texMur.texName, texMur.texImageWidth, texMur.texImageHeight, GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
        glTranslatef(20., 0., 0.);
        glRotatef(-90, 0., 1., 0.);
        glScalef(40., 40., 40.);
        mur();
        disableTex();
    glPopMatrix();

    /*glPushMatrix();
    glTranslatef(-20., 0., 0.);
    glRotatef(90, 0., 1., 0.);
    glScalef(4., 4., 4.);
    mur();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., 0., 20.);
    glScalef(4., 4., 4.);
    mur();
    glPopMatrix();*/

    glPushMatrix();
        //glColor3f(0.5, 0.5, 0.9);
        texObjet(texMur.texImage, texMur.texName, texMur.texImageWidth, texMur.texImageHeight, GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
        glTranslatef(0., 0., -20.);
        glScalef(40., 40., 40.);
        mur();
        disableTex();
    glPopMatrix();

    /*glPushMatrix();
    glTranslatef(0., 20., 0.);
    glRotatef(90, 1., 0., 0.);
    glScalef(4., 4., 4.);
    mur();
    glPopMatrix();*/

    glPushMatrix();
        //glColor3f(0.5, 0.9, 0.5);
        texObjet(texSol.texImage, texSol.texName, texSol.texImageWidth, texSol.texImageHeight, GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
        glTranslatef(0., -20., 0.);
        glRotatef(-90, 1., 0., 0.);
        glScalef(40., 40., 40.);
        mur();
        disableTex();
    glPopMatrix();
}
