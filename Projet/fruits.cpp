#include "objet.h"

texData texPomme;

void pomme(){
    if ( !texPomme.texImage ) 
        texPomme.texImage = initTex((char *) "./textures/pomme.ppm", &texPomme.texName, &texPomme.texImageWidth, &texPomme.texImageHeight);
    
    glColor3f(1., 0., 0.);
    glScalef(2., 2., 2.);
    int nb_points_pomme = 15;

    Point pomme[nb_points_pomme];
    pomme[0].x = 0.25;
    pomme[0].y = 3.95;
    pomme[1].x = 0.25;
    pomme[1].y = 3.93;
    pomme[2].x = 0.25;
    pomme[2].y = 3.38;
    pomme[3].x = 0.6;
    pomme[3].y = 3.11;
    pomme[4].x = 0.97;
    pomme[4].y = 3.42;
    pomme[5].x = 1.32;
    pomme[5].y = 3.52;
    pomme[6].x = 1.63;
    pomme[6].y = 3.5;
    pomme[7].x = 1.92;
    pomme[7].y = 3.05;
    pomme[8].x = 1.96;
    pomme[8].y = 2.41;
    pomme[9].x = 1.78;
    pomme[9].y = 1.72;
    pomme[10].x = 1.49;
    pomme[10].y = 1.33;
    pomme[11].x = 1.05;
    pomme[11].y = 1.08;
    pomme[12].x = 0.7;
    pomme[12].y = 1;
    pomme[13].x = 0.29;
    pomme[13].y = 0.94;
    pomme[14].x = 0.29;
    pomme[14].y = 0.93;

    texObjet(texPomme.texImage, texPomme.texName, texPomme.texImageWidth, texPomme.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
    tracerRevolution(pomme, nb_points_pomme);
    disableTex();
}