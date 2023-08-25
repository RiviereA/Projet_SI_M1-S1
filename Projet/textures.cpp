#include "objet.h"

GLubyte* glmReadPPM(char* filename, int* width, int* height)
//----------------------------------------
{
    FILE* fp;
    int i, w, h, d;
    unsigned char* image;
    char head[70];          /* max line <= 70 in PPM (per spec). */
    

    fp = fopen(filename, "rb");
    if (!fp) {
        perror(filename);
        return NULL;
    }
    
    /* grab first two chars of the file and make sure that it has the
       correct magic cookie for a raw PPM file. */
    fgets(head, 70, fp);
    if (strncmp(head, "P6", 2)) {
        fprintf(stderr, "%s: Not a raw PPM file\n", filename);
        return NULL;
    }
    
    /* grab the three elements in the header (width, height, maxval). */
    i = 0;
    while(i < 3) {
        fgets(head, 70, fp);
        if (head[0] == '#')     /* skip comments. */
            continue;
        if (i == 0)
            i += sscanf(head, "%d %d %d", &w, &h, &d);
        else if (i == 1)
            i += sscanf(head, "%d %d", &h, &d);
        else if (i == 2)
            i += sscanf(head, "%d", &d);
    }
    
    /* grab all the image data in one fell swoop. */
    image = new unsigned char[w*h*3];
    fread(image, sizeof(unsigned char), w*h*3, fp);
    fclose(fp);
    
    *width = w;
    *height = h;
    return image;
}

GLubyte *initTex(char *loadfile, GLuint* texName, int* width, int* height) {

    //glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, texName);
    GLubyte *texImage = glmReadPPM( (char *) loadfile, width, height);

    if ( !texImage ) {
        printf("\nError reading %s \n", loadfile );
        return NULL;
    }
    return texImage;
}

void texObjet(GLubyte *texImage, GLuint texName, int width, int height, GLint wrapS, GLint wrapT, GLint minF, GLint magF, GLint texGenS, GLint texGenT) {
    
    glBindTexture(GL_TEXTURE_2D, texName);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minF);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magF);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB,GL_UNSIGNED_BYTE,texImage);

    //delete texImage;

    //automatic texture coordinates generation
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, texGenS);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, texGenT);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glEnable(GL_TEXTURE_2D);
}

void disableTex()
{
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);
}