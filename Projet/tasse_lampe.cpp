#include "objet.h"

texData texAbatJour;
texData texPlastique;
texData texPiedLampe;
texData texTasse;
texData texSoucoupe;
texData texSucre;

void lampe()
{
    if (!texAbatJour.texImage)
        texAbatJour.texImage = initTex((char *)"./textures/abatjour.ppm", &texAbatJour.texName, &texAbatJour.texImageWidth, &texAbatJour.texImageHeight);
    if (!texPlastique.texImage)
        texPlastique.texImage = initTex((char *)"./textures/plastique.ppm", &texPlastique.texName, &texPlastique.texImageWidth, &texPlastique.texImageHeight);
    if (!texPiedLampe.texImage)
        texPiedLampe.texImage = initTex((char *)"./textures/piedlampe.ppm", &texPiedLampe.texName, &texPiedLampe.texImageWidth, &texPiedLampe.texImageHeight);
    glPushMatrix();
    //glTranslatef(5., 0., 0.);
    glColor3f(0.3, 1.0, 0.0);

    int nb_points_socle = 5, nb_points_tube = 6, nb_points_abajour = 4;

    Point socle[nb_points_socle];
    socle[0].x = 3;
    socle[0].y = -1;
    socle[1].x = 3;
    socle[1].y = 0;
    socle[2].x = 3;
    socle[2].y = 1;
    socle[3].x = 1;
    socle[3].y = 1;
    socle[4].x = 1;
    socle[4].y = 2;

    Point tube[nb_points_tube];
    tube[0].x = 1;
    tube[0].y = 0;
    tube[1].x = 1;
    tube[1].y = 1;
    tube[2].x = 1;
    tube[2].y = 9;
    tube[3].x = 1;
    tube[3].y = 8;
    tube[4].x = 0;
    tube[4].y = 8;
    tube[5].x = 0;
    tube[5].y = 9;

    Point abajour[nb_points_abajour];
    abajour[0].x = 5;
    abajour[0].y = 6;
    abajour[1].x = 4;
    abajour[1].y = 7;
    abajour[2].x = 3;
    abajour[2].y = 11;
    abajour[3].x = 2;
    abajour[3].y = 12;

    glPushMatrix();
    glTranslatef(0., 9., 0.);
    glRotatef(-45., 0., 1., 0.);
    glutSolidCylinder(0.1, 3.4, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., 9., 0.);
    glRotatef(120., 0., 1., 0.);
    glRotatef(-45., 0., 1., 0.);
    glutSolidCylinder(0.1, 3.4, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., 9., 0.);
    glRotatef(240., 0., 1., 0.);
    glRotatef(-45., 0., 1., 0.);
    glutSolidCylinder(0.1, 3.4, 10, 10);
    glPopMatrix();

    texObjet(texPiedLampe.texImage, texPiedLampe.texName, texPiedLampe.texImageWidth, texPiedLampe.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    tracerRevolution(socle, nb_points_socle);
    disableTex();

    texObjet(texPlastique.texImage, texPlastique.texName, texPlastique.texImageWidth, texPlastique.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    tracerRevolution(tube, nb_points_tube);
    disableTex();

    texObjet(texAbatJour.texImage, texAbatJour.texName, texAbatJour.texImageWidth, texAbatJour.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    tracerRevolution(abajour, nb_points_abajour);
    disableTex();

    glPopMatrix();
}

void tasse()
{
    if (!texTasse.texImage)
        texTasse.texImage = initTex((char *)"./textures/tasse.ppm", &texTasse.texName, &texTasse.texImageWidth, &texTasse.texImageHeight);
    if (!texSoucoupe.texImage)
        texSoucoupe.texImage = initTex((char *)"./textures/ceramique.ppm", &texSoucoupe.texName, &texSoucoupe.texImageWidth, &texSoucoupe.texImageHeight);

    glPushMatrix();
    glTranslatef(-5., 0., 0.);
    glColor3f(0.0, 1.0, 0.3);

    int nb_points_tasse = 8, nb_points_soucoupe = 4;

    Point tasse[nb_points_tasse];
    tasse[0].x = 0;
    tasse[0].y = -1;
    tasse[1].x = 0;
    tasse[1].y = 0.1;
    tasse[2].x = 1;
    tasse[2].y = 0.1;
    tasse[3].x = 1;
    tasse[3].y = 0.2;
    tasse[4].x = 1.3;
    tasse[4].y = 1;
    tasse[5].x = 1.6;
    tasse[5].y = 2;
    tasse[6].x = 2;
    tasse[6].y = 3;
    tasse[7].x = 2.4;
    tasse[7].y = 4;

    texObjet(texTasse.texImage, texTasse.texName, texTasse.texImageWidth, texTasse.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    tracerRevolution(tasse, nb_points_tasse);

    glPushMatrix();
    glTranslatef(1.5, 2., 0.);
    glRotatef(-110, 0., 0., 1.);
    glScalef(0.7, 0.7, 0.7);
    anse(50, 50);
    glPopMatrix();

    disableTex();

    glColor3f(0.5, 0.7, 0.3);
    Point soucoupe[nb_points_soucoupe];
    soucoupe[0].x = 0;
    soucoupe[0].y = 2;
    soucoupe[1].x = 0;
    soucoupe[1].y = 0;
    soucoupe[2].x = 3;
    soucoupe[2].y = 0.5;
    soucoupe[3].x = 5;
    soucoupe[3].y = 1;

    texObjet(texSoucoupe.texImage, texSoucoupe.texName, texSoucoupe.texImageWidth, texSoucoupe.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    tracerRevolution(soucoupe, nb_points_soucoupe);
    disableTex();

    glPopMatrix();
}

void bol()
{
    int nb_points_bol = 4;
    Point bol[nb_points_bol];
    bol[0].x = 0;
    bol[0].y = 2;
    bol[1].x = 0;
    bol[1].y = 0;
    bol[2].x = 3;
    bol[2].y = 0.5;
    bol[3].x = 5;
    bol[3].y = 1;

    texObjet(texSoucoupe.texImage, texSoucoupe.texName, texSoucoupe.texImageWidth, texSoucoupe.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    tracerRevolution(bol, nb_points_bol);
    disableTex();

}

void sucre()
{

    if (!texSucre.texImage)
        texSucre.texImage = initTex((char *)"./textures/tasse.ppm", &texSucre.texName, &texSucre.texImageWidth, &texSucre.texImageHeight);

    glutSolidCube(1);
    
    texObjet(texSucre.texImage, texSucre.texName, texSucre.texImageWidth, texSucre.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    disableTex();
}
