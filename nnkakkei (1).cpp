#include <stdlib.h>
#include <math.h>
#include <windows.h>

void npoly(int n, int rv, int xc, int yc);
extern BOOL GetIntParams1(char *szQuestion, int *param1);
extern void LineSet(int, int, int, int);

double dp = 3.141592 / 180.0;

void nnkakkei(void)
{
	int i, x0, y0, x1, y1;
	int r, n, rv;

	int xo = 320;
	int yo = 240;
	// 図形の原点になるxとyの座標を設定

	double dp = 3.141592 / 180.0;
	//角度を度からラジアンへ

	GetIntParams1("外接円の半径", &r);
	GetIntParams1("ｎ角形", &n);
	GetIntParams1("頂点の外接円", &rv); /* 頂点のｎ角形の外接円 */

	//for文を使い、頂点の座標x0,y0,x1,y1を計算し、x0,y0を関数npolyに渡す
	for (i = 0; i < n; i++) {
		x0 = (int)(r * cos(360.0 / n * i * dp) + xo);
		y0 = (int)(r * sin(360.0 / n * i * dp) + yo);
		x1 = (int)(r * cos(360.0 / n * (i + 1) * dp) + xo);
		y1 = (int)(r * sin(360.0 / n * (i + 1) * dp) + yo);
		// 関数npolyを呼び出す。n:多角形の頂点数、rv:外接円の半径、x0,y0:中心の座標 
		npoly(n, rv, x0, y0);
		// LineSetを使って頂点間を結ぶ
		LineSet(x0, y0, x1, y1);
	}
}

void npoly(int n, int rv, int xc, int yc)
{
	
    // 関数内で使う変数の宣言　
	int i,x0, y0, x1, y1;
	
	double dp = 3.141592 / 180.0;
	//角度を度からラジアンへ
	
	//(xc,yc)を中心に外接円の半径rv、ｎ角形の頂点を計算。for文を使う
	//   LineSet(x0,y0, x1,y1)を使って頂点間を結ぶ　
	for (i = 0; i < n; i++) {
		x0 = (int)(rv * cos(360.0 / n * i * dp) + xc);
		y0 = (int)(rv * sin(360.0 / n * i * dp) + yc);
		x1 = (int)(rv * cos(360.0 / n * (i + 1) * dp) + xc);
		y1 = (int)(rv * sin(360.0 / n * (i + 1) * dp) + yc);
		LineSet(x0, y0, x1, y1);
	}
}