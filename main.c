//INFO
/********************************
*   #1 BiblioStats              *
*   #2 .txt file input          *
*   #3 ')' Player               *
*   #4 '#' Wall                 *
********************************/
//BIBLIOSTATS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


/*********NAMESPACE********/
//*/using namespace std;/**/
/**************************/

//FUNCTIONS

#define width 80
#define height 25

//HIDECURSOUR

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

//MAP

struct {
	char map[height][width+1];
	POINT sz;
} loc;

//LOAD MAP FROM FILE

void loc_LoadFromFile(char *fileName)
{
	memset(&loc.map, ' ', sizeof(loc));
	for (int i = 0; i < height; i++)
		loc.map[i][width] = '\0';
		
	FILE *f = fopen(fileName, "r");
	char c[80];
	int line = 0;
	loc.sz.x = 0;
	loc.sz.y = 0;
	while (!feof(f))
	{
		fgets(c, width, f);
		int cnt = strlen(c);
		if (c[cnt-1] == '\n') cnt--;
		strncpy(loc.map[line], c, cnt);
		line++;
		if (cnt > loc.sz.x) loc.sz.x = cnt;
	}
	loc.sz.y = line;
	fclose(f);
	
	loc.map[height-1][width-1] = '\0';
}

char map[height][width+1];

//CURSOUR ON BEGINING

void SetCurPos()
{
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), coord );
}

//"DRAW" MAP ON BEGENING

void map_Show()
{
	SetCurPos();
	for (int i = 0; i < height; i++)
		printf("%s", map[i]);
}

//LOCATION FROM FILE TO MAP

void loc_PutOnMap()
{
	memcpy(map, loc.map, sizeof(map));
}

struct {
	char name[20];
	POINT pos;
	POINT LocPos;
} player;

//OBJECT FROM FILE TO MAP

typedef struct {
	char name[20];
	char oType;
	POINT pos;
} TObj;

TObj *obj = NULL;
int objCnt = 0;

TObj *obj_Add()
{
	objCnt++;
	obj = realloc( obj, sizeof(*obj) * objCnt);
	return obj + objCnt - 1;
}

//OBJECT LOAD FROM FILE

void obj_LoadFromFile(char *name)
{
	objCnt = 0;
	obj = realloc( obj, 0);
	
	TObj *tmp;
	
	FILE *f = fopen(name, "rt");
	if (f)
		while (!feof(f))
		{
			tmp = obj_Add();
			fgets(tmp->name, 1000, f);
			fscanf(f, "%c", &tmp->oType);
			fscanf(f, "%d", &tmp->pos.x);
			fscanf(f, "%d\n", &tmp->pos.y);
		}
	fclose(f);
}

//OBJECT PUT ON MAP

void obj_PutOnMap()
{
	for (int i = 0; i < objCnt; i++)
		map[obj[i].pos.y][obj[i].pos.x] = obj[i].oType;
}

//TALK WHIS OBJECT

TObj *obj_GetByXY(int x, int y)
{
	for (int i = 0; i < objCnt; i++)
		if ((obj[i].pos.x == x) && (obj[i].pos.y == y))
			return obj + i;
	return NULL;
}

//DIALOG

void obj_StartDialog(TObj *obj)
{
	if (obj == NULL) return;
	char ans;
	do
	{
		system("cls");
		printf("%s\n", obj->name);
		//T
		if (obj->oType == 'T')
		{
			printf("\n Where I am ...? And what am I doing here ...?");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//@
		if (obj->oType == '@')
		{
			printf("\n IT'S NOSING HERE(");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//Y
		if (obj->oType == 'Y')
		{
			printf("\n It's so dark in here ...");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//U
		if (obj->oType == 'U')
		{
			printf("\n Story 2");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//L
		if (obj->oType == 'L')
		{
			printf("\n Why is everything so black and white !?");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//+
		if (obj->oType == '+')
		{
			printf("\n RIP");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//Q
		if (obj->oType == 'Q')
		{
			printf("\n Story 4");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//P
		if (obj->oType == 'P')
		{
			printf("\n Story 5");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//B
		if (obj->oType == 'B')
		{
			printf("\n Story 9");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//J
		if (obj->oType == 'J')
		{
			printf("\n Story 10");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//O
		if (obj->oType == 'O')
		{
			printf("\n Story 7");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//K
		if (obj->oType == 'K')
		{
			printf("\n Story 6");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//F
		if (obj->oType == 'F')
		{
			printf("\n Story 8");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//H
		if (obj->oType == 'H')
		{
			printf("\n Story 11");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//S (SECRET) secret is the longest text (which was a cipher)
		if (obj->oType == 'S')
		{
			printf("\n 1000001010110001000010100001111101000001000100100010000111\n 0001000100010010001000000100000100001110101000011111010001\n 0000101000011111010001000000100010101101000011100110000010\n 0001111011000100001110000110110100001111011000011111010000\n 0100010000001000011000010000110111100001100111000011000010\n 000110100100001100001000100001010001001100100001");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//N
		if (obj->oType == 'N')
		{
			printf("\n Throne room of the king!");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//Z
		if (obj->oType == 'Z')
		{
			printf("\n I'm stuck here !!!");
			printf("\n Help me !!!");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//W
		if (obj->oType == 'W')
		{
			printf("\n This is the throne of our former king");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//D
		if (obj->oType == 'D')
		{
			printf("\n This is a coffin");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//X
		if (obj->oType == 'X')
		{
			printf("\n I am siting on the chair");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//C
		if (obj->oType == 'C')
		{
			printf("\n Nice pull");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
		//V
		if (obj->oType == 'V')
		{
			printf("\n I am fish!");
			printf("\n");
			printf("\n     0 - Quit");
			ans = getch();
			if (ans == '0')
			{
				ans = '0';
			}
		}
	}
	while (ans !='0');
}

//PLAYER

void player_Init(int xLoc, int yLoc, int x, int y, char *name)
{
	player.pos.x = x;
	player.pos.y = y;
	sprintf(player.name, name);
	player.LocPos.x = xLoc;
	player.LocPos.y = yLoc;
}

//PLAYER ON MAP

void player_PutOnMap()
{
	map[player.pos.y][player.pos.x] = ')';
}

//PLAYER LOAD

void player_LoadLocation()
{
	char c[100];
	sprintf (c, "map_%d_%d.txt", player.LocPos.x, player.LocPos.y);
	loc_LoadFromFile(c);
	sprintf (c, "obj_%d_%d.txt", player.LocPos.x, player.LocPos.y);
	obj_LoadFromFile(c);
}

//PLAYER CONTROLL
//PLAYER WHIS WALLS AND OBJECTS

void player_Control()
{
	POINT old = player.pos;
	if (GetKeyState('W') < 0) player.pos.y--;
	if (GetKeyState('S') < 0) player.pos.y++;
	if (GetKeyState('A') < 0) player.pos.x--;
	if (GetKeyState('D') < 0) player.pos.x++;
	if (map[player.pos.y][player.pos.x] != ' ' /*AIR*/&& map[player.pos.y][player.pos.x] != '%' /*SECRET*/&& map[player.pos.y][player.pos.x] != '=' /*STAIRS*/&& map[player.pos.y][player.pos.x] != '/' /*CARPET*/&& map[player.pos.y][player.pos.x] != '-' /*CARPET*/&& map[player.pos.y][player.pos.x] != '~' /*Watter*/&& map[player.pos.y][player.pos.x] != '^'/*Watter*/)
	{
		TObj *obj = obj_GetByXY(player.pos.x, player.pos.y);
		player.pos = old;
		obj_StartDialog(obj);
	}
	
	if (player.pos.x > loc.sz.x - 2)
	{
		player.LocPos.x++;
		player_LoadLocation();
		player.pos.x = 1;
	}
	if (player.pos.x < 1)
	{
		player.LocPos.x--;
		player_LoadLocation();
		player.pos.x = loc.sz.x - 2;
	}
	if (player.pos.y > loc.sz.y - 2)
	{
		player.LocPos.y++;
		player_LoadLocation();
		player.pos.y = 1;
	}
	if (player.pos.y < 1)
	{
		player.LocPos.y--;
		player_LoadLocation();
		player.pos.y = loc.sz.y - 2;
	}
}

//SAVE

void player_Save()
{
	FILE *f = fopen(player.name, "wb");
		fwrite(&player, 1, sizeof(player), f);
	fclose(f);
}

//PLAYER LOAD

void player_Load(char *name)
{
	FILE *f = fopen(name, "rb");
	if ( f == NULL)
		player_Init(0,0, 7,6, name);
	else
		fread(&player, 1, sizeof(player), f);
	fclose(f);
}

//GAMESTART

void game_Start()
{
		hidecursor();
	
	player_Load("Skobochka");
	player_LoadLocation();
	do
	{
		player_Control();
		loc_PutOnMap();
		obj_PutOnMap();
		player_PutOnMap();
		map_Show();
		Sleep (50);
	}
	
	while (GetKeyState(VK_ESCAPE) >= 0);
	
	//player_Save();
}

//GAMESTORY

void game_Story()
{
	printf("\n\n      STORY:");
	printf("\n    That storry is about Skobochka. The Skobochka was hit by a car\n    and found herself in a strange and unknown world from which she\n    would have to get back. So what is next...\n\n    You must find all the lost letters that will tell you the history\n    of this world.");
}


/*************************/
/**INTMAININTMAININTMAIN**/
/*************************/

int main()
{
	
	/****************************/
	/**MENUMENUMENUMENUMENUMENU**/
	/****************************/
	char a;
	char b;
	do
	{
		hidecursor();
		printf("\n        _     _     _     _     _     _     _     _     _  ");
		printf("\n       / \    / \    / \    / \    / \    / \    / \    / \    / \ ");
		printf("\n      ( N ) ( E ) ( V ) ( E ) ( R ) ( M ) ( O ) ( R ) ( E )");
		printf("\n        \_/    \_/    \_/    \_/    \_/    \_/    \_/    \_/    \_/ ");
		
		printf("\n");
		printf("\n");
		printf("\n             PRESS ANY BUTTN TO START ");
		printf("\n");
		printf("\n             0 - Quit");
		a = getch();
		if (a == '0')
		{
			a = '0';
		}
		else{
			game_Story();
			b = getch();
			if (b == b){
			game_Start();
		}
	}
	while (b != b);	
}
while (a !='0');

	
	
	return 0;
}
