#include <stdio.h>
#include <math.h>

// ax + b + (c/d)
typedef struct {
	double a;
	int b, c, d;
} Num;

int gcd(int a, int b);

void numUpdate(Num *n);
void numPrint(Num n);
void numF(Num *n);
void numG(Num *n);
void numIF(Num *n);
void numIG(Num *n);

int main(int argc, char *argv[]) {
	Num n = { 1, 0, 0, 1 };
	numIF(&n);
	numIF(&n);
	numPrint(n);
	numIG(&n);
	numPrint(n);
	return 0;
}

void numF(Num *n) {
	n->a /= 2;
	n->b /= 2;
	n->d *= 2;
	if((n->b % 2) != 0)
		n->c += (n->d >> 1);
}
void numG(Num *n) {
	n->a *= 3;
	n->b *= 3;
	n->d *= 3;
	n->b++;
	numUpdate(n);
}
void numIF(Num *n) {
	n->a *= 2;
	if(n->c != 0)
		n->b *= 2;
	n->c *= 2;
	numUpdate(n);
}
void numIG(Num *n) {
	n->b--;
	n->a /= 3;
	 n->c += n->b * n->d;
	 n->b = 0;
	n->d *= 3;
	numPrint(*n);
	numUpdate(n);
}

void numUpdate(Num *n) {
	int g = gcd(n->c, n->d);
	if(g != 1) {
		n->c /= g;
		n->d /= g;
	}
up:
	if(n->c >= n->d) {
		n->c -= n->d;
		n->b++;
		goto up;
	}
}

void numPrint(Num n) {
	printf("%lfx + %d(%d/%d)\n", n.a, n.b, n.c, n.d);
}

int gcd(int a, int b) {
	if(a <= 0 || b <= 0)
		return 1;
	int temp;
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

