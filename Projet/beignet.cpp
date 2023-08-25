#include "objet.h"

texData texBeignet;

void beignet() {
    if ( !texBeignet.texImage ) 
        texBeignet.texImage = initTex((char *) "./textures/amande.ppm", &texBeignet.texName, &texBeignet.texImageWidth, &texBeignet.texImageHeight);
    
    glPushMatrix();
        texObjet(texBeignet.texImage, texBeignet.texName, texBeignet.texImageWidth, texBeignet.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_SPHERE_MAP, GL_SPHERE_MAP);
        glRotatef(90,1.0,0.,0.);
        glutSolidTorus(0.5,1.,20,50);
        disableTex();
    glPopMatrix();
}