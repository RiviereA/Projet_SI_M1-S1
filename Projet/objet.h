#ifndef __OBJET_H__INCLU
#define __OBJET_H__INCLU

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <armadillo>

using namespace arma;

#define PI 3.14159265358979323846

struct texData
{
    GLuint texName;
    int texImageWidth;
    int texImageHeight;
    GLubyte *texImage;
};

struct Point
{
    float x, y;
    Point(float a = 0, float b = 0) { set(a, b); }
    void set(float a, float b)
    {
        x = a;
        y = b;
    }
};

struct Point3D
{
    float x, y, z;
    Point3D(float a = 0, float b = 0, float c = 0) { set(a, b, c); }
    void set(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
};

extern double aspirateurAnim;
extern double Rtot;
extern double RAxeX;
extern double RAxeY;
extern double heli;
extern double trans_robX, trans_robZ;
extern Point3D point_anim[];
extern Point3D point_anim2[];

//texturage
GLubyte* glmReadPPM(char* filename, int* width, int* height);
GLubyte *initTex(char *loadfile, GLuint* texName, int* width, int* height);
void texObjet(GLubyte *texImage, GLuint texName, int width, int height, GLint wrapS, GLint wrapT, GLint magF, GLint minF, GLint texGenS, GLint texGenT);
void disableTex();

//trace des parties d'objets
void tracerRevolution(Point tab[], int N);
void anse(int numc, int numt);

//trace des objets entiers
void lampe();
void tasse();
void pomme();
void piece();
void carton();
void chaise();
void table();
void livre();
void robot();
void beignet();
void tuile();
void sucre();
void bol();

// idle
void rotation();
void anim_robot();
void anim_robot2();

#endif
