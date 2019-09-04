#include"perlinNoise1D.h"

int main()
{
	while (1)
	{
		color c = { (float)(rand() % 255) / 255, (float)(rand() % 255) / 255, (float)(rand() % 255) / 255 };
		perlinNoise1D p(rand() % 400 + 160, rand() % 5 + 2, 0);
		p.plotArray(rand() % 3 + 2, c);
	}
	return 0;
}