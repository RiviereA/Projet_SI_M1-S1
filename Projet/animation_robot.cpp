#include "objet.h"
#define N 12
#define N2 16
#define U 10

const int taille = N*U, taille2 = N2*U;
Point3D point_anim[taille];
Point3D point_anim2[taille2];

void anim_robot()
{

    int tmp = 0;
    Point P[N];

    P[0].set(0.25, -1);
    P[1].set(-0.75, 0);
    P[2].set(-1.5, 5);
    P[3].set(2.25, 9);
    P[4].set(9.0, 8.5);
    P[5].set(11.75, 2);
    P[6].set(11, -5);
    P[7].set(9, -10);
    P[8].set(5, -13);
    P[9].set(0, -11);
    P[10].set(0, -6.);
    P[11].set(-0.75, -1.5);

    //s: allure de la courbe, matT: matrice des T, matCat: matrice de CatMullrom du cours, matPX/Y: coordonnées des points
    float s = 1. / 2.;
    mat matT = mat(1, 4, fill::zeros);
    mat matCat;
    mat matPX = mat(4, 1, fill::zeros);
    mat matPZ = mat(4, 1, fill::zeros);

    matCat << -s << 2 - s << s - 2 << s << endr
           << 2 * s << s - 3 << 3 - 2 * s << -s << endr
           << -s << 0 << s << 0 << endr
           << 0 << 1 << 0 << 0 << endr;

    for (int i = 1; i < N - 2; i++)
    {
        matPX << P[i - 1].x << endr
              << P[i].x << endr
              << P[i + 1].x << endr
              << P[i + 2].x << endr;

        matPZ << P[i - 1].y << endr
              << P[i].y << endr
              << P[i + 1].y << endr
              << P[i + 2].y << endr;

        //Calcul et affichage des points pour chaque t
        for (int u = 0; u <= U; u++)
        {
            float t = u / 10.;

            matT << t * t * t << t * t << t << 1 << endr;
            point_anim[tmp].x = (matT * matCat * matPX).eval()(0, 0);
            point_anim[tmp].y = 0;
            point_anim[tmp].z = (matT * matCat * matPZ).eval()(0, 0);

            tmp++;
        }
    }
}


void anim_robot2()
{
    int tmp = 0;
    Point P[N2];

    P[0].set(-0.5, -6);
    P[1].set(0, -6);
    P[2].set(1.25, -5.75);
    P[3].set(2.75, -5.75);
    P[4].set(4.25, -5.75);
    P[5].set(6.25, -5.75);
    P[6].set(7.25, -4.75);
    P[7].set(7.25, -3.25);
    P[8].set(6, -2.5);
    P[9].set(4.75, -2.5);
    P[10].set(3.75, -3.5);
    P[11].set(2.75, -3.75);
    P[12].set(2.25, -2.75);
    P[13].set(2, -1.5);
    P[14].set(0.75, -0.75);
    P[15].set(-0.5, -0.75);

    //s: allure de la courbe, matT: matrice des T, matCat: matrice de CatMullrom du cours, matPX/Y: coordonnées des points
    float s = 1. / 2.;
    mat matT = mat(1, 4, fill::zeros);
    mat matCat;
    mat matPX = mat(4, 1, fill::zeros);
    mat matPZ = mat(4, 1, fill::zeros);

    matCat << -s << 2 - s << s - 2 << s << endr
           << 2 * s << s - 3 << 3 - 2 * s << -s << endr
           << -s << 0 << s << 0 << endr
           << 0 << 1 << 0 << 0 << endr;

    for (int i = 1; i < N2 - 2; i++)
    {
        matPX << P[i - 1].x << endr
              << P[i].x << endr
              << P[i + 1].x << endr
              << P[i + 2].x << endr;

        matPZ << P[i - 1].y << endr
              << P[i].y << endr
              << P[i + 1].y << endr
              << P[i + 2].y << endr;

        //Calcul et affichage des points pour chaque t
        for (int u = 0; u <= U; u++)
        {
            float t = u / 10.;

            matT << t * t * t << t * t << t << 1 << endr;
            point_anim2[tmp].x = (matT * matCat * matPX).eval()(0, 0);
            point_anim2[tmp].y = 0;
            point_anim2[tmp].z = (matT * matCat * matPZ).eval()(0, 0);

            tmp++;
        }
    }
}
