

#include"mota.h"
int main()
{

	initgraph(14 * 60, 13 * 60);
	loadResource();
	head();
	PlaySound(TEXT("bjm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	while (1)
	{
		drawmap();
		keyDown();
	}

	closegraph();
	return 0;
}
