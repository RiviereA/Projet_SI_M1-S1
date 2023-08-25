#include "objet.h"

mat matT = mat(1,4, fill::zeros);
mat matS = mat(4,1, fill::zeros);

mat matBezier = mat(4,4, fill::zeros);

texData texAmande;

              


void TraceBezier(Point3D P[][4]){

    mat matPX = mat(4,1,fill::zeros);
    mat matPY = mat(4,1,fill::zeros);
    mat matPZ = mat(4,1,fill::zeros);
    
    matBezier << -1. << 3. << -3. << 1. << endr
              << 3. << -6. << 3. << 0. << endr
              << -3. << 3. << 0. << 0. << endr
              << 1. << 0. << 0. << 0. << endr;
    
    float precision = 0.02;
	float nbPoints = 1. / precision;
    
	Point3D tabRes[(int)nbPoints+1][(int)nbPoints+1];
    
    glColor3f(1.0,1.0,0.0);
    
    matPX << P[0][0].x << P[0][1].x << P[0][2].x << P[0][3].x << endr
          << P[1][0].x << P[1][1].x << P[1][2].x << P[1][3].x << endr
          << P[2][0].x << P[2][1].x << P[2][2].x << P[2][3].x << endr
          << P[3][0].x << P[3][1].x << P[3][2].x << P[3][3].x << endr; 

    matPY << P[0][0].y << P[0][1].y << P[0][2].y << P[0][3].y << endr
          << P[1][0].y << P[1][1].y << P[1][2].y << P[1][3].y << endr
          << P[2][0].y << P[2][1].y << P[2][2].y << P[2][3].y << endr
          << P[3][0].y << P[3][1].y << P[3][2].y << P[3][3].y << endr; 
          
    matPZ << P[0][0].z << P[0][1].z << P[0][2].z << P[0][3].z << endr
          << P[1][0].z << P[1][1].z << P[1][2].z << P[1][3].z << endr
          << P[2][0].z << P[2][1].z << P[2][2].z << P[2][3].z << endr
          << P[3][0].z << P[3][1].z << P[3][2].z << P[3][3].z << endr; 
          
	for(int u = 0; u <= nbPoints; u++){
		float t = (float) u / nbPoints;
		matT << t*t*t << t*t << t << 1. << endr;
		
		for(int v = 0; v <= nbPoints; v++){
			float s = (float) v / nbPoints;
			matS << s*s*s << endr
			     << s*s << endr
			     << s << endr
			     << 1. << endr;
			     
			tabRes[u][v].x = (matT * matBezier * matPX * trans(matBezier) * matS).eval()(0,0);
			tabRes[u][v].y = (matT * matBezier * matPY * trans(matBezier) * matS).eval()(0,0);
			tabRes[u][v].z = (matT * matBezier * matPZ * trans(matBezier) * matS).eval()(0,0);
			
		}
	}

	//Affichage de la tuile
	
	for(int u = 0; u < nbPoints; u++){
		for(int v = 0; v < nbPoints; v++){
			glBegin(GL_QUADS);
			glVertex3f(tabRes[u][v].x,tabRes[u][v].y,tabRes[u][v].z);
			glVertex3f(tabRes[u][v+1].x,tabRes[u][v+1].y,tabRes[u][v+1].z);
			glVertex3f(tabRes[u+1][v+1].x,tabRes[u+1][v+1].y,tabRes[u+1][v+1].z);
			glVertex3f(tabRes[u+1][v].x,tabRes[u+1][v].y,tabRes[u+1][v].z);
			glEnd();
		}
	}
}

void tuile(){

	if ( !texAmande.texImage ) 
        texAmande.texImage = initTex((char *) "./textures/amande.ppm", &texAmande.texName, &texAmande.texImageWidth, &texAmande.texImageHeight);


	Point3D tab[4][4];
	
	tab[0][0].set(-2.,0.,-2.);
	tab[1][0].set(-2.,0.5,-1.);
	tab[2][0].set(-2.,0.5,1.);
	tab[3][0].set(-2.,0.,2.);
	
	tab[0][1].set(-1.,0.5,-2.);
	tab[1][1].set(-1.,1.,-1.);
	tab[2][1].set(-1.,1.,1.);
	tab[3][1].set(-1.,0.5,2.);
	
	tab[0][2].set(1.,-0.5,-2.);
	tab[1][2].set(1.,-0.5,-1.);
	tab[2][2].set(1.,-0.5,1.);
	tab[3][2].set(1.,-0.5,2.);
	
	tab[0][3].set(2.,0.,-2.);
	tab[1][3].set(2.,0.5,-1.);
	tab[2][3].set(2.,0.5,1.);
	tab[3][3].set(2.,0.,2.);
	
    texObjet(texAmande.texImage, texAmande.texName, texAmande.texImageWidth, texAmande.texImageHeight, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, GL_OBJECT_LINEAR, GL_OBJECT_LINEAR);
	TraceBezier(tab);
}

