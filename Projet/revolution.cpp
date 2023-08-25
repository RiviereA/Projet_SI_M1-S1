#include "objet.h"

void tracerRevolution(Point tab[], int N)
{

    float theta = 0, precision = 0.1;
    int tmp = 0, nbPointsPrecision = (int)1 / precision, NP = 50;
    Point3D tabPoints[N][nbPointsPrecision];

    float s = 1. / 2.;
    mat matT = mat(1, 4, fill::zeros);
    mat matCat;
    mat matPX = mat(4, 1, fill::zeros);
    mat matPY = mat(4, 1, fill::zeros);

    matCat << -s << 2 - s << s - 2 << s << endr
           << 2 * s << s - 3 << 3 - 2 * s << -s << endr
           << -s << 0 << s << 0 << endr
           << 0 << 1 << 0 << 0 << endr;

    for (int i = 1; i < N - 2; i++)
    {
        matPX << tab[i - 1].x << endr
              << tab[i].x << endr
              << tab[i + 1].x << endr
              << tab[i + 2].x << endr;

        matPY << tab[i - 1].y << endr
              << tab[i].y << endr
              << tab[i + 1].y << endr
              << tab[i + 2].y << endr;

        for (int u = 0; u <= 10; u++)
        {
            float t = u / 10.;
            tmp = u;
            matT << t * t * t << t * t << t << 1 << endr;
            tabPoints[i][tmp].x = (matT * matCat * matPX).eval()(0, 0);
            tabPoints[i][tmp].y = (matT * matCat * matPY).eval()(0, 0);
            tabPoints[i][tmp].z = (matT * matCat * matPX).eval()(0, 0);
        }
    }

    //Affichage des points
    glBegin(GL_QUAD_STRIP);
    for (int i = 1; i < N - 2; i++)
    {
        for (int u = 0; u < 10; u++)
        {
            //float t = u/10.;
            theta = 0;
            tmp = u;
            for (int j = 0; j < NP; j++)
            {
                float theta1 = (theta + 2 * PI / NP);

				glNormal3f(0.,1.,0.);
                glVertex3f(tabPoints[i][tmp].x * sin(theta), tabPoints[i][tmp].y, tabPoints[i][tmp].z * cos(theta));
                glVertex3f(tabPoints[i][tmp + 1].x * sin(theta), tabPoints[i][tmp + 1].y, tabPoints[i][tmp + 1].z * cos(theta));
                glVertex3f(tabPoints[i][tmp].x * sin(theta1), tabPoints[i][tmp].y, tabPoints[i][tmp].z * cos(theta1));
                glVertex3f(tabPoints[i][tmp + 1].x * sin(theta1), tabPoints[i][tmp + 1].y, tabPoints[i][tmp + 1].z * cos(theta1));

	
                theta += 2 * PI / NP;
            }
        }
    }
    glEnd();
}


void anse(int numc, int numt)
{
    int i, j, k;
    double s, t, x, y, z, twopi;

    twopi = 2 * PI;
    for (i = 0; i < numc; i++)
    {
        glBegin(GL_QUAD_STRIP);
        for (j = 1; j <= (numt / 2) - 1; j++)
        {
            for (k = 1; k >= 0; k--)
            {
                s = (i + k) % numc + 0.5;
                t = j % numt;

                x = (1 + .1 * cos(s * twopi / numc)) * cos(t * twopi / numt);
                y = (1 + .1 * cos(s * twopi / numc)) * sin(t * twopi / numt);
                z = .1 * sin(s * twopi / numc);
                glVertex3f(x, y, z);
            }
        }
        glEnd();
    }
}
