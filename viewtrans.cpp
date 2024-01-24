#include <stdlib.h>
#include <math.h>
#include <windows.h>

extern BOOL GetIntParams3(char *szQuestion, char *szQuestion1, char *szQuestion2,
				   char *szQuestion3, int *param1, int *param2, int *param3);
extern void BCGPyramidVect(int, int, int, int[][4], int*);
extern void BCGLineSet2(int [][4], int);

void mtx_cnv(double mtx[4][4], int v[][4], int vout[][4], int nv);



void viewtrans(void)
{
	int i,j;
	
	int v[200][4], vout[200][4], nv;
	
	//v[][]:正10角錐のワールド座標系における頂点座標
	//vout[][]:正10角錐のカメラ座標系における頂点座標

	for(i=0; i<200; i++){
		for(j=0; j<4; j++){
			v[i][j] = 0;
			vout[i][j] = 0;
		}
	}

	double mtx[4][4] = {1.0, 0.0, 0.0, 0.0,
						0.0, 1.0, 0.0, 0.0,
						0.0, 0.0, 1.0, 0.0,
						0.0, 0.0, 0.0, 1.0};

	// mtx[][]:変換行列

	int vx, vy, vz;
	double vgx, vgy, vgz;
	double sinshita, sinfai;
	double cosshita, cosfai;



	GetIntParams3("視点位置", "x", "y", "z", &vx, &vy, &vz);


	vgx = (double)vx;
	vgy = (double)vy;
	vgz = (double)vz;

	// vx, vy, vzは視点の座標

	sinshita = vgy / sqrt(vgx*vgx + vgy*vgy);
	cosshita = vgx / sqrt(vgx*vgx + vgy*vgy);
	sinfai   = vgz / sqrt(vgx*vgx + vgy*vgy + vgz*vgz);
	cosfai   = sqrt(vgx*vgx + vgy*vgy) / sqrt(vgx*vgx + vgy*vgy + vgz*vgz);

	// sinΘ、cosΘ、sinφ、cosφの値



// 以下に変換行列の各要素を計算結果をもとに代入する
    mtx[0][0] = -sinshita;
	mtx[0][1] =  cosshita;

	mtx[1][0] = sinfai * -1 * cosshita;
	mtx[1][1] = sinfai * -1 * sinshita;
	mtx[1][2] = cosfai;
	
	mtx[2][0] = -1 * cosfai * -1 * cosshita;
	mtx[2][1] = -1 * cosfai * -1 * sinshita;
	mtx[2][2] = sinfai;
	
	BCGPyramidVect(10, 100, 100, v, &nv);
	mtx_cnv(mtx, v, vout, nv); 
	BCGLineSet2(vout, nv);
}



void mtx_cnv(double mtx[4][4], int v[][4], int vout[][4], int nv)
{
	// 関数で使用する変数を宣言する
	int i,j,k;

   // for文を用いて各頂点座標と変換行列の演算を行う
	for (i = 0; i < nv * 2; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				vout[i][j] += (int)(v[i][k] * mtx[j][k]);
			}
		}
	}
}