#include <stdlib.h>
#include <math.h>
#include <windows.h>  

extern BOOL GetIntParams1(char *szQuestion, int *param1);
extern void LineSet(int, int, int, int);

void draw_kaiten(int n, int x[], int y[]);

void kaiten(void)
{

    // 必要な変数を定義する

	int xo = 320;
	int yo = 240;
	// 図形の原点になるxとyの座標を設定

	int x[5] = {370, 270, 270, 370, 370};
	int	y[5] = {190, 190, 290, 290, 190};
		   /*(320,240)を中心に１辺100の正方形*/
	int n = 4; /* 頂点の数 */
	double dp = 3.141592 / 180.0; /* 角度をラジアンへ*/
	int deg;  /* 回転角　*/ 
	
	// 回転後の座標を入れる配列を定義する
	int xout[5], yout[5];

	GetIntParams1("回転角（度）", &deg); /* 回転角度の入力　*/
	
	int i;

	// ステップ１　回転中心を原点へ平行移動する
	for (i = 0; i < 5; i++) {
		//xとyの値から図形の原点の座標を差し引くことで、原点からの相対座標に変換する。
		xout[i] = x[i] - xo;
		yout[i] = y[i] - yo;
	}
	
	// ステップ２　各頂点を原点を中心に回転角度分、回転する
	for (i = 0; i < 5; i++) {
		int xi = xout[i];
		int yi = yout[i];
		xout[i] = xi * cos(deg * dp) - yi * sin(deg * dp);
		yout[i] = xi * sin(deg * dp) + yi * cos(deg * dp);
	}

	// ステップ３　回転中心を320、240に平行移動する
	for (i = 0; i < 5; i++) {
		//xとyの値に図形の原点の座標を足すことで、スクリーン上の絶対座標にする。
		xout[i] += xo;
		yout[i] += yo;
	}

	// ステップ４　draw_kaiten関数の呼び出し、描画する
	draw_kaiten(n,x,y);
	draw_kaiten(n, xout, yout);
		
}

void draw_kaiten(int n, int x[], int y[])
{
	int i;

	for(i = 0; i < n; i++){
		LineSet(x[i], y[i], x[i+1], y[i+1]);  /*x[i]y[i]とx[i+1]y[i+1]を結ぶ*/
	}
}