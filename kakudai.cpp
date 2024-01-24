#include <stdlib.h>
#include <math.h>
#include <windows.h>  

extern BOOL GetIntParams1(char *szQuestion, int *param1);
extern void LineSet(int, int, int, int);

void draw_kakudai(int n, int x[], int y[]);

void kakudai(void)
{

    int xo = 320;
    int yo = 240;
    // 図形の原点になるxとyの座標を設定

	int x[5] = {370, 270, 270, 370, 370};
	int	y[5] = {190, 190, 290, 290, 190};
    /*(320,240)を中心に１辺100の正方形の頂点座標*/

	int n = 4; /* 頂点の数 */
	int s;     /* 倍率　*/
	
    int xout[5], yout[5]; /* 拡大後の各頂点座標を格納する */

	GetIntParams1("s倍にする", &s); /* 拡大率（整数）の入力 */
	
    int i;
    /* ステップ１の処理を書くfor文の利用　変数iの定義を忘れずに*/
    for (i = 0; i < 5; i++) {
        //xとyの値から図形の原点の座標を差し引くことで、原点からの相対座標に変換する。
        xout[i] = x[i] - xo;
        yout[i] = y[i] - yo;
    }

    /* ステップ２の処理を書くfor文の利用　*/
    for (i = 0; i < 5; i++) {
        //それぞれの座標の原点からの距離をs倍にする。
        xout[i] *= s;
        yout[i] *= s;
    }

    /* ステップ３の処理を書くfor文の利用　*/
    for (i = 0; i < 5; i++) {
        //xとyの値に図形の原点の座標を足すことで、スクリーン上の絶対座標にする。
        xout[i] += xo;
        yout[i] += yo;
    }

	draw_kakudai(n, x, y);         /* 元の正方形を描く　*/
	draw_kakudai(n, xout, yout);   /* S倍した正方形を描く　*/

}

void draw_kakudai(int n, int x[], int y[])
{
	int i;

	for(i = 0; i < n; i++){
		LineSet(x[i], y[i], x[i+1], y[i+1]);  /*x[i]y[i]とx[i+1]y[i+1]を結ぶ*/
	}
}
	

