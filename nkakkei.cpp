#include <stdlib.h>
#include <math.h>
#include <windows.h>


extern BOOL GetIntParams1(char *szQuestion, int *param1);
extern void LineSet(int, int, int, int);

void nkakkei(void)
{
	int x0, y0, x1, y1;
	int r, n;
	double dp;

		GetIntParams1("外接円の半径", &r);/* 変数rに外接円の半径 */
		GetIntParams1("ｎ角形", &n);      /* 変数nに多角形の頂点の数 */

		dp = 3.141592 / 180.0;  /* 角度を度からラジアンへ */
		x0=0; y0=0; x1=0; y1=0;

		// 以下にfor文を使ってi番目の頂点座標x0,y0と(i+1)番目の頂点座標x1,y1を計算する
		// また、LineSet(x0, y0, x1, y1);を使って点（x0,y0）から点（x1,y1）へ線を引く 
		// 注意for文内で使う変数iは　int i;　と宣言すること
		int i;
		for (i = 0; i < n; i++) {
			x0 = (int)(r * cos(360.0 / n * i * dp) + 320);
			y0 = (int)(r * sin(360.0 / n * i * dp) + 240);
			x1 = (int)(r * cos(360.0 / n * (i + 1) * dp) + 320);
			y1 = (int)(r * sin(360.0 / n * (i + 1) * dp) + 240);
			LineSet(x0, y0, x1, y1);
		}

}