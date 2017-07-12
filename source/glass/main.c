#include <stdio.h>

#define TRUE 1
#define FALSE 0

int gcd (int a, int b);           // 最大公約数を求める
int coprime (int a, int b);       // 互いに素であるか
int check (int a, int b, int c);  // 半分になるかチェックする

int main () {
  int result = 0;
  int a, b, c;
  int i, j;
  for (i = 10; i <= 100; i+=2) {
  	a = i;
    for (j = 1; j < i / 2; ++j) {
      c = j;
      b = a - c;
      if ( coprime (a , b) ) {
        // printf ("%d %d %d--------\n", a, b, c);  // グラスの設定値
        if ( check (a, b, c) ) {
          result++;
        }
      }
    }
  }
  printf("%d\n", result);
}

/**
 * 最大公約数を求める関数
 */
int gcd (int a, int b) {
  return b ? gcd(b, a%b) : a;
}

/**
 * 互いに素であるかどうかを判別
 */
int coprime (int a, int b) {
  if ( 1 == gcd(a, b) ) {
    return TRUE;
  }
  return FALSE;
}


int check (int a, int b, int c) {
  int waterA = a, waterB = 0, waterC = 0;

  while (1) {
    if ( 0 == waterB ) {
      while ( 0 < waterA && b > waterB ) {
        waterA--; waterB++;
      }
    } else {
      if ( c == waterC ) {
        while ( 0 < waterC ) {
          waterC--; waterA++;
        }
      } else {
        while ( 0 < waterB && c > waterC ) {
          waterB--; waterC++;
        }
      }
    }
    // printf("  %d %d %d\n", waterA, waterB, waterC);  // 各操作時の水量推移
    if (waterA == a / 2) {
      return TRUE;
    }
    if (waterA == a) {
      return FALSE;
    }
  }
}
