
#include"mota.h"

struct gameRole
{
	char name[20];
	int blood;
	int attack;
	int defence;
	int blueKey;
	int yellowKey;
	int redKey;
	int grade;
	int jinbi;
	int experience;
}role;

struct monster
{
	int blood;
	int attack;
	int defence;
	int jinbi;

};
//怪兽初始化
struct monster bianfu = { 35,38,3,30};
struct monster kulou = { 50,42,6,60 };
struct monster fashi = { 60,32,8,50 };
struct monster redslime = { 45,20,2,20 };
struct monster  greenslime= { 35,18,1,10 }; 
struct monster  kulousoldier = { 55,52,12,80 };
struct monster boss= { 6000,320,100,5000000 };
int map[13][13]
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,18,1,6,7,6,1,1,1,1,1,1,0,
	0,0,0,0,0,0,0,0,28,0,0,1,0,
	0,14,1,1,3,1,0,11,2,1,0,1,0,
	0,1,9,1,0,1,0,12,14,1,0,1,0,
	0,0,3,0,0,1,0,0,0,3,0,1,0,
	0,2,1,1,0,1,3,8,10,8,0,1,0,
	0,1,15,1,0,1,0,0,0,0,0,1,0,
	0,0,3,0,0,1,1,1,1,1,1,1,0,
	0,1,1,1,0,0,3,0,0,0,3,0,0,
	0,14,1,2,0,2,1,1,0,1,8,1,0,
	0,14,1,2,0,1,17,1,0,6,13,6,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0
};
int floor = 1;

int map1[13][13] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,18,1,6,7,6,1,1,1,1,1,1,0,
	0,0,0,0,0,0,27,0,28,0,0,1,0,
	0,14,1,1,3,1,0,11,2,1,0,1,0,
	0,1,9,1,0,1,0,12,14,1,0,1,0,
	0,0,3,0,0,1,0,0,0,3,0,1,0,
	0,2,1,1,0,1,3,8,10,8,0,1,0,
	0,1,15,1,0,1,0,0,0,0,0,1,0,
	0,0,3,0,0,1,1,1,1,1,1,1,0,
	0,1,1,1,0,0,3,0,0,0,3,0,0,
	0,14,1,2,0,2,1,1,0,1,8,1,0,
	0,14,1,2,0,1,17,1,0,6,13,6,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0
};
int map2[13][13] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,2,15,1,0,1,1,19,0,1,2,8,0,
	0,2,8,1,27,1,1,17,3,6,1,2,0,
	0,2,6,1,0,15,1,1,0,1,1,14,0,
	0,0,0,0,0,0,1,0,0,0,3,0,0,
	0,7,2,1,0,14,1,1,0,1,15,1,0,
	0,14,1,8,3,1,6,1,0,1,1,1,0,
	0,15,2,1,0,1,1,15,0,8,1,4,0,
	0,0,1,0,0,0,3,0,0,0,3,0,0,
	0,1,7,1,0,8,1,8,0,1,15,1,0,
	0,1,1,1,3,1,1,1,3,1,0,0,0,
	0,7,1,1,0,1,18,1,0,10,1,7,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0

};
int map3[13][13]{
	0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,2,11,0,2,14,2,0,1,0,1,13,0,
	0,1,13,0,14,2,14,0,1,3,8,1,0,
	0,10,1,0,2,4,2,0,1,0,0,0,0,
	0,3,0,0,0,1,0,0,1,0,1,1,0,
	0,1,1,8,1,1,1,6,1,1,1,1,0,
	0,3,0,0,1,1,1,0,1,0,0,0,0,
	0,9,1,0,0,1,0,0,1,0,1,13,0,
	0,1,2,0,1,1,1,0,1,3,10,2,0,
	0,13,12,0,1,1,1,0,1,0,0,0,0,
	0,0,0,0,0,1,0,0,7,0,1,1,0,
	0,19,17,1,1,1,1,0,1,3,1,18,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0
};
int map4[13][13] = { 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 2, 0, 1, 9, 17, 19, 0, 29, 0, 1, 1, 0,
0, 14, 0, 6, 0, 0, 0, 0, 6, 0, 0, 10, 0,
0, 8, 1, 1, 1, 6, 13, 0, 1, 3, 1, 4, 0,
0, 0, 0, 0, 3, 0, 0, 0, 8, 0, 0, 3, 0,
0, 14, 1, 6, 1, 0, 4, 5, 1, 5, 14, 1, 0,
0, 3, 0, 0, 14, 0, 14, 15, 1, 0, 0, 7, 0,
0, 1, 4, 0, 5, 0, 0, 0, 1, 0, 13, 5, 0,
0, 2, 1, 15, 1, 1, 1, 6, 1, 0, 7, 14, 0,
0, 11, 0, 0, 0, 0, 15, 0, 6, 0, 0, 11, 0,
0, 14, 0, 2, 4, 5, 30, 0, 1, 0, 2, 1, 0,
0, 1, 10, 14, 5, 0, 31, 0, 14, 0, 0, 21, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
void m(int map1[13][13], int map[13][13], int map2[13][13]) {
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			map1[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			map[i][j] = map2[i][j];
		}
	}
}
IMAGE img[33],roleinfo;
HWND hwnd;//战斗时显示一个消息框
//输入用户名

bool book = false;
void Book()
{
	if (book)	
	{
		switch (floor)
		{
		case 1:
			MessageBox(hwnd, "怪物名字\t生命\t攻击\t防御\t金钱\n\
卡比\t35\t18\t1\t10\n\
红史莱姆\t45\t20\t2\t20\n\
法师\t60\t32\t8\t50\n\
蝙蝠\t35\t38\t3\t30\n\
骷髅人\t50\t42\t6\t60\n\
骷髅士兵\t55\t52\t12\t80", "怪物手册", MB_OK);
			break;

		case 2:
			MessageBox(hwnd, "怪物名字\t生命\t攻击\t防御\t金钱\n\
卡比\t35\t18\t1\t10\n\
红史莱姆\t45\t20\t2\t20\n\
法师\t60\t32\t8\t50\n\
蝙蝠\t35\t38\t3\t30\n\
骷髅人\t50\t42\t6\t60\n\
骷髅士兵\t55\t52\t12\t80", "", MB_OK);
			break;

		case 3:
			MessageBox(hwnd, "怪物名字\t生命\t攻击\t防御\t金钱\n\
卡比\t35\t18\t1\t10\n\
红史莱姆\t45\t20\t2\t20\n\
法师\t60\t32\t8\t50\n\
蝙蝠\t35\t38\t3\t30\n\
骷髅人\t50\t42\t6\t60\n", "", MB_OK);

			break;

		case 4:
			MessageBox(hwnd, "怪物名字\t生命\t攻击\t防御\t金钱\n\
卡比\t35\t18\t1\t10\n\
红史莱姆\t45\t20\t2\t20\n\
法师\t60\t32\t8\t50\n\
蝙蝠\t35\t38\t3\t30\n\
骷髅人\t50\t42\t6\t60\n\
骷髅士兵\t55\t52\t12\t80\n\
boss\t6000\t320\t100\t5000000", "", MB_OK);
			break;

		}
	}	
}

//加载资源
void loadResource()
{
	loadimage(&roleinfo, "info.png",60*1,60*13);
	for (int i = 0; i < 32; i++)
	{
		char filename[20] = "";
		sprintf(filename, "%d.png",i);
		loadimage(img + i, filename, 60, 60);

	}
}
//PK
	void PK(struct gameRole* role, struct monster* m,int map[13][13], int i, int j)
	{
		// 计算双方攻击力和防御力

		int role_attack = role->attack;
		int role_defence = role->defence;
		int m_attack = m->attack;
		int m_defence = m->defence;

		// 双方交替攻击，直到有一方血量小于等于0
		while (role->blood > 0 && m->blood > 0)
		{
			// 玩家先攻击
			int role_damage = role_attack - m_defence;
			if (role_damage < 0)
			{
				role_damage = 0;
			}
			m->blood -= role_damage;
			if (m->blood <= 0)
			{
				break;
			}

			// 怪物攻击
			int m_damage = m_attack - role_defence;
			if (m_damage < 0)
			{
				m_damage = 0;
			}
			role->blood -= m_damage;
		}
	}
	void up(int floor)
	{
		switch (floor)
		{
			case 2:
				m(map1, map, map2);
				break;
			case 3:
				m(map2, map, map3);
				break;
			case 4:
				m(map3, map, map4);
				break;
		}
	}
	
	void down(int floor)
	{
		switch (floor)
		{
		case 2:
			m(map3, map, map2);
			
			break;
		case 3:
			m(map4, map, map3);
			break;
		case 1:
			m(map2, map, map1);
			break;
		}
	}

//int 转换成string
char str[20] = "";
char* intTOstring(int x)
{
	sprintf(str, "%d", x);
	return str;
}
void drawmap()
{
	int i, j;
	int x, y;
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 13; j++)
		{

			x = 60 * j;
			y = 60 * i;
			putimage(x, y, &img[map[i][j]]);
		}
	}

	putimage(60 * 13, 0, &roleinfo);
	outtextxy(60 * 13 + 12, 100, role.name);
	outtextxy(60 * 13 + 12, 180, intTOstring(role.grade));
	outtextxy(60 * 13 + 12, 235, intTOstring(role.experience));
	outtextxy(60 * 13 + 12, 278, intTOstring(role.jinbi));
	outtextxy(60 * 13 + 12, 362, intTOstring(role.blood));
	outtextxy(60 * 13 + 12, 635, intTOstring(role.yellowKey));
	outtextxy(60 * 13 + 12, 415, intTOstring(role.attack));
	outtextxy(60 * 13 + 12, 467, intTOstring(role.defence));
	outtextxy(60 * 13 + 12, 689, intTOstring(role.redKey));
	outtextxy(60 * 13 + 12, 759, intTOstring(role.blueKey));
}
//开头
void head() {

	void far cleardevice(void);
	outtextxy(60, 180, "在很久很久以前有一个国家，那里的人民歌舞升平，安居乐业");
	Sleep(2000);
	void far cleardevice(void);
	outtextxy(60, 180, "但是有一个邪恶的魔王，盯上了这一片净土，将善良的公主给抓走了");
	Sleep(2000);
	void far cleardevice(void);
	outtextxy(60, 180, "而亲爱的勇者，只有你才能将我们的公主从魔王的魔爪中解救出来");
	Sleep(2000);
	void far cleardevice(void);
	outtextxy(60, 180, "所以请告诉我您的名字，待您归来的时候，我们会将您的事迹载入史册");
	Sleep(2000);
	void far cleardevice(void);
	role.blood = 500;
	role.attack = 50;
	role.defence = 42;
	role.blueKey = 0;
	role.yellowKey = 0;
	role.redKey = 0;
	role.jinbi = 0;
	role.grade = 1;
	role.experience = 0;
	outtextxy(60, 200, "请输入您的名字：");
	outtextxy(60, 220, "（请切换输入法置英文且输入的字不会在屏幕上显示,输入完按下回车确认进入游戏）");
	outtextxy(60, 240, "（国王给了你一本怪物手册，游戏中可以按q键查看怪物手册，里面有怪物的详细信息）");
	outtextxy(60, 260, "（本游戏内含bjm，佩戴耳机游玩更佳，音量可能有点小）");
	scanf("%s", role.name);
}

void chuan(int k)
{
	switch (k)
	{
		case '2':
			m(map4, map, map2);
			break;
		case '3':
			m(map4, map, map3);
			break;
		case '1':
			m(map4, map, map1);
			break;
		default:;
	}
}
	
void keyDown()
{

	char userkey;
	int i = 0, j = 0;
	//在地图中寻找人物
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 13; j++)
		{
			if (map[i][j] == 17)
				break;
		}
		if (map[i][j] == 17)
			break;
	}
	userkey = _getch();//不可见输入
	switch (userkey)
	{
		//左
	case'A':
	case'a':
	case 75:
		//空地
		if (map[i][j - 1] == 1)
		{
			map[i][j] = 1;
			map[i][j - 1] = 17;
		}
		//盾
		else if (map[i][j - 1] == 11)
		{
			map[i][j] = 1;
			map[i][j - 1] = 17;
			role.defence += 20;
		}
		//剑
		else if (map[i][j - 1] == 12)
		{
			map[i][j] = 1;
			map[i][j - 1] = 17;
			role.attack += 16;
		}
		//红钥匙
		else if (map[i][j - 1] == 2)
		{
			map[i][j] = 1;
			map[i][j - 1] = 17;
			role.redKey++;
		}
		//开红门
		else if (map[i][j - 1] == 3 && role.redKey > 0)
		{
			role.redKey--;
			map[i][j - 1] = 17;
			map[i][j] = 1;
		}
		//蓝钥匙
		else if (map[i][j - 1] == 4)
		{
			map[i][j] = 1;
			map[i][j - 1] = 17;
			role.blueKey++;
		}
		//开蓝门
		else if (map[i][j - 1] == 5 && role.blueKey > 0)
		{
			role.blueKey--;
			map[i][j - 1] = 17;
			map[i][j] = 1;
		}
		//黄钥匙
		else if (map[i][j - 1] == 28)
		{
			map[i][j] = 1;
			map[i][j - 1] = 17;
			role.yellowKey++;
		}
		//开黄门
		else if (map[i][j - 1] == 27 && role.yellowKey > 0)
		{
			role.yellowKey--;
			map[i][j - 1] = 17;
			map[i][j] = 1;
		}
		//红瓶
		else if (map[i][j - 1] == 14)
		{
			role.blood += 20;
			map[i][j - 1] = 17;
			map[i][j] = 1;
		}
		// 经验瓶
		else if (map[i][j - 1] == 13)
		{
			role.experience += 21;
			if (role.experience >= 20)
			{
				role.grade++;
				role.experience -= 20;
				role.attack += 20;
				role.defence += 5;
				role.blood += 20;
			}
			map[i][j - 1] = 17;
			map[i][j] = 1;
		}
		//上楼
		else if (map[i][j - 1] == 18)
		{
			floor++;
			up(floor);
		}
		//下楼
		else if (map[i][j - 1] == 19)
		{
			floor--;
			
			down(floor);
		}
		//蝙蝠
		else if (map[i][j - 1] == 8)
		{
			int ID = MessageBox(hwnd, "是否攻击小蝙蝠", "遇到小蝙蝠", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &bianfu;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j -1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDYES)
					role1->blood = role_blood;
					else
							exit(1);
				}
			}
		}
		//骷髅
		else if (map[i][j - 1] == 9)
		{
			int ID = MessageBox(hwnd, "是否攻击骷髅人", "遇到骷髅人", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &kulou;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j - 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//骷髅士兵
		else if (map[i][j - 1] == 15)
		{
			int ID = MessageBox(hwnd, "是否攻击骷髅士兵", "遇到骷髅士兵", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &kulousoldier;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j - 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
			}
		//法师
		else if (map[i][j - 1] == 10)
		{
			int ID = MessageBox(hwnd, "是否攻击法师", "遇到法师", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &fashi;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j - 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
			}
		//卡比
		else if (map[i][j - 1] == 6)
		{
			int ID = MessageBox(hwnd, "是否攻击卡比", "遇到卡比", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &greenslime;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
					// 判断胜负
					if (role1->blood > 0)
					{
						role1->jinbi += m->jinbi;
						map[i][j] = 1;
						map[i][j - 1] = 17;
					}
					else
					{
						int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
						if (ID == IDNO)
							exit(0);
						else
							role1->blood = role_blood;
					}
			}
		}
		//史莱姆
		else if (map[i][j - 1] == 7)
		{
			int ID = MessageBox(hwnd, "是否攻击史莱姆", "遇到史莱姆", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &redslime;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j - 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//boss
		else if (map[i][j - 1] == 30)
		{
			int ID = MessageBox(hwnd, "是否攻击BOSS", "遇到BOSS", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &boss;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j - 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！注意提升战力！", MB_YESNO);
					if (ID == IDYES)
						role1->blood = role_blood;
					else
						exit(0);
				}
			}
			}

		
		break;
		case'Q':
		case'q':
		MessageBox(hwnd, "你有一本怪物手册，上面有你所在楼层所有怪物的属性。\n请按Q键查看。", "", MB_OK);
		book = true;
		Book();
		
		break;
		//右
	case'd':
	case'D':
	case 77:
		if (map[i][j + 1] == 1)
		{
			map[i][j] = 1;
			map[i][j + 1] = 17;
		}
		//剑
		else if (map[i][j + 1] == 12)
		{
			map[i][j] = 1;
			map[i][j + 1] = 17;
			role.attack += 20;

		}
		//盾
		else if (map[i][j + 1] == 11)
		{
			map[i][j] = 1;
			map[i][j + 1] = 17;
			role.defence += 20;

		}
		//红钥匙
		else if (map[i][j + 1] == 2)
		{
			map[i][j] = 1;
			map[i][j + 1] = 17;
			role.redKey++;
		}
		//开红门
		else if (map[i][j + 1] == 3 && role.redKey > 0)
		{
			role.redKey--;
			map[i][j + 1] = 17;
			map[i][j] = 1;
		}
		//蓝
		else if (map[i][j + 1] == 4)
		{
			map[i][j] = 1;
			map[i][j + 1] = 17;
			role.blueKey++;
		}

		else if (map[i][j + 1] == 5 && role.blueKey > 0)
		{
			role.blueKey--;
			map[i][j + 1] = 17;
			map[i][j] = 1;
		}
		//黄
		else if (map[i][j + 1] == 28)
		{
			map[i][j] = 1;
			map[i][j + 1] = 17;
			role.yellowKey++;
		}

		else if (map[i][j + 1] == 27 && role.yellowKey > 0)
		{
			role.yellowKey--;
			map[i][j + 1] = 17;
			map[i][j] = 1;
		}
		//红瓶
		else if (map[i][j + 1] == 14)
		{
			role.blood += 20;
			map[i][j + 1] = 17;
			map[i][j] = 1;
		}
		// 经验瓶
		else if (map[i][j + 1] == 13)
		{
			role.experience += 21;
			if (role.experience >= 20)
			{
				role.grade++;
				role.experience -= 20;
				role.attack += 20;
				role.defence += 5;
				role.blood += 20;
			}
			map[i][j + 1] = 17;
			map[i][j] = 1;
		}
		//boss
		else if (map[i][j+1] == 30)
		{
			int ID = MessageBox(hwnd, "是否攻击BOSS", "遇到BOSS", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &boss;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j+1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！注意提升战力！", MB_YESNO);
					if (ID == IDYES)
						role1->blood = role_blood;
					else
						exit(0);
				}
			}
		}
		//蝙蝠
		else if (map[i][j + 1] == 8)
		{
			int ID = MessageBox(hwnd, "是否攻击小蝙蝠", "遇到小蝙蝠", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &bianfu;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j + 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//法师
		else if (map[i][j + 1] == 10)
		{
			int ID = MessageBox(hwnd, "是否攻击法师", "遇到法师", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &fashi;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j + 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//骷髅
		else if (map[i][j + 1] == 9)
		{
			int ID = MessageBox(hwnd, "是否攻击骷髅", "遇到骷髅", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &kulou;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j + 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//骷髅士兵
		else if (map[i][j + 1] == 15)
		{
			int ID = MessageBox(hwnd, "是否攻击骷髅士兵", "遇到骷髅士兵", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &kulousoldier;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j + 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
			}
			//卡比
		else if (map[i][j + 1] == 6)
		{
			int ID = MessageBox(hwnd, "是否攻击卡比", "遇到卡比", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &greenslime;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j + 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		else if (map[i][j + 1] == 7)
		{
			int ID = MessageBox(hwnd, "是否攻击史莱姆", "遇到史莱姆", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &redslime;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j + 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//上楼
		else if (map[i][j + 1] == 18)
		{
			floor++;
			up(floor);
		}
		//下楼
		else if (map[i][j + 1] == 19)
		{
			floor--;

			down(floor);
		}
			//传送门
		else if (map[i][j + 1] == 29)
		{
			char k;
			while (getchar() != '\n');
			MessageBox(hwnd, "恭喜你！来到了传送门，你可以自由选择传送的楼层（请按下你需要前往的楼层按键）", "", MB_OK);
			k = getchar();
			floor = (int)k - '0';
			chuan(k);
		}

		break;
		//上
	case'w':
	case'W':
	case 72:
		if (map[i - 1][j] == 1)
		{
			map[i][j] = 1;
			map[i - 1][j] = 17;
		}
		//剑
		else  if (map[i - 1][j] == 12)
		{
			map[i][j] = 1;
			map[i - 1][j] = 17;
			role.attack += 20;
		}
		//盾
		else if (map[i - 1][j] == 11)
		{
			map[i][j] = 1;
			map[i - 1][j] = 17;
			role.defence += 20;
		}
		//红钥匙
		else if (map[i - 1][j] == 2)
		{
			map[i][j] = 1;
			map[i - 1][j] = 17;
			role.redKey++;
		}
		//开红门
		else if (map[i - 1][j] == 3 && role.redKey > 0)
		{
			role.redKey--;
			map[i - 1][j] = 17;
			map[i][j] = 1;
		}
		//蓝钥匙
		else if (map[i-1][j] == 4)
		{
			map[i][j] = 1;
			map[i-1][j] = 17;
			role.blueKey++;
		}
		//开蓝门
		else if (map[i-1][j] == 5 && role.blueKey > 0)
		{
			role.blueKey--;
			map[i-1][j] = 17;
			map[i][j] = 1;
		}
		//黄钥匙
		else if (map[i-1][j] == 28)
		{
			map[i][j] = 1;
			map[i-1][j] = 17;
			role.yellowKey++;
		}
		//开黄门
		else if (map[i-1][j] == 27 && role.yellowKey > 0)
		{
			role.yellowKey--;
			map[i-1][j] = 17;
			map[i][j] = 1;
		}
		//上楼
		else if (map[i - 1][j] == 18)
		{
			floor++;
			up(floor);
		}
		//下楼
		else if (map[i - 1][j] == 19)
		{
			floor--;
			down(floor);
		}
		//传送门
		else if (map[i-1][j] == 29)
		{
			char k;
			while (getchar() != '\n');
			MessageBox(hwnd, "恭喜你！来到了传送门，你可以自由选择传送的楼层（请按下你需要前往的楼层按键）", "", MB_OK);
			k = _getch();
			floor = (int)k - '0';
			chuan(k);
		}
		//红瓶
		else if (map[i-1][j] == 14)
		{
			role.blood += 20;
			map[i - 1][j] = 17;
			map[i][j] = 1;
		}
		// 经验瓶
		else if (map[i-1][j ] == 13)
		{
			role.experience += 21;
			if (role.experience >= 20)
			{
				role.grade++;
				role.experience -= 20;
				role.attack += 20;
				role.defence += 5;
				role.blood += 20;
			}
			map[i - 1][j] = 17;
			map[i][j] = 1;
		}
		//蝙蝠
		else if (map[i-1][j ] == 8)
		{
			int ID = MessageBox(hwnd, "是否攻击小蝙蝠", "遇到小蝙蝠", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &bianfu;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i-1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//法师
		else if (map[i - 1][j] == 10)
		{
			int ID = MessageBox(hwnd, "是否攻击法师", "遇到法师", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &fashi;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i - 1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//骷髅
		else if (map[i - 1][j] == 9)
		{
			int ID = MessageBox(hwnd, "是否攻击骷髅", "遇到骷髅", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &kulou;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i - 1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//骷髅士兵
		else if (map[i - 1][j] == 15)
		{
			int ID = MessageBox(hwnd, "是否攻击骷髅士兵", "遇到骷髅士兵", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &kulousoldier;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i - 1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
			}
		//卡比
		else if (map[i-1][j] == 6)
		{
			int ID = MessageBox(hwnd, "是否攻击卡比", "遇到卡比", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &greenslime;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i-1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//史莱姆
		else if (map[i-1][j] == 7)
		{
			int ID = MessageBox(hwnd, "是否攻击史莱姆", "遇到史莱姆", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &redslime;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i-1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		break;
		//下
	case'S':
	case's':
	case 80:
		if (map[i + 1][j] == 1)
		{
			map[i][j] = 1;
			map[i + 1][j] = 17;
		}
		//剑
		if (map[i + 1][j] == 12)
		{
			map[i][j] = 1;
			map[i + 1][j] = 17;
			role.attack += 20;
		}
		//盾
		if (map[i + 1][j] == 11)
		{
			map[i][j] = 1;
			map[i + 1][j] = 17;
			role.defence += 20;
		}
		//红钥匙
		else if (map[i + 1][j] == 2)
		{
			map[i][j] = 1;
			map[i + 1][j] = 17;
			role.redKey++;
		}
		//开红门
		else if (map[i + 1][j] == 3 && role.redKey > 0)
		{
			role.redKey--;
			map[i + 1][j] = 17;
			map[i][j] = 1;
		}
		//蓝钥匙
		else if (map[i + 1][j] == 4)
		{
			map[i][j] = 1;
			map[i + 1][j] = 17;
			role.blueKey++;
		}
		//开蓝门
		else if (map[i + 1][j] == 5 && role.blueKey > 0)
		{
			role.blueKey--;
			map[i + 1][j] = 17;
			map[i][j] = 1;
		}
		//黄钥匙
		else if (map[i + 1][j] == 28)
		{
			map[i][j] = 1;
			map[i + 1][j] = 17;
			role.yellowKey++;
		}
		//开黄门
		else if (map[i + 1][j] == 27 && role.yellowKey > 0)
		{
			role.yellowKey--;
			map[i + 1][j] = 17;
			map[i][j] = 1;
		}
		//红瓶
		else if (map[i + 1][j] == 14)
		{
			role.blood += 20;
			map[i + 1][j] = 17;
			map[i][j] = 1;
		}
		// 经验瓶
		else if (map[i + 1][j] == 13)
		{
			role.experience += 21;
			if (role.experience >= 20)
			{
				role.grade++;
				role.experience -= 20;
				role.attack += 20;
				role.defence += 5;
				role.blood += 20;
			}
			map[i + 1][j] = 17;
			map[i][j] = 1;
		}
		//上楼
		else if (map[i + 1][j] == 18)
		{
			floor++;
			up(floor);
		}
		//下楼
		else if (map[i + 1][j] == 19)
		{
			floor--;
			down(floor);
		}
		//传送门
		else if (map[i+1][j] == 29)
		{
			char k;
			//getchar();
			MessageBox(hwnd, "恭喜你！来到了传送门，你可以自由选择传送的楼层（请按下你需要前往的楼层按键）", "", MB_OK);
			k = _getch();
			if ('0' < k && k < '4')
			{
				floor = (int)k - '0';
				chuan(k);
			}
		}
		//蝙蝠
		else if (map[i+1][j] == 8)
		{
			int ID = MessageBox(hwnd, "是否攻击小蝙蝠", "遇到小蝙蝠", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &bianfu;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i+1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		else if (map[i+1][j] == 30)
		{
			int ID = MessageBox(hwnd, "是否攻击BOSS", "遇到BOSS", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &boss;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i+1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！注意提升战力！", MB_YESNO);
					if (ID == IDYES)
						role1->blood = role_blood;
					else
						exit(0);
				}
				
			}
			}
		else if (map[i+1][j] == 31)
		{
			
			PlaySound(TEXT("bjm2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

			char k;
			MessageBox(hwnd, "恭喜你成功解救公主", "遇到公主", MB_OK);
			int ID1 = MessageBox(hwnd, "需要公主以身相许吗？", "公主很感谢你", MB_YESNO);
			if (ID1 == IDYES)
				MessageBox(hwnd, "想屁吃呢，这又不是童话故事", "", MB_OK);
			else
				MessageBox(hwnd, "这么美丽的公主都不想要，太可惜了（一脸嫌弃：这人以后肯定没什么出息）", "", MB_OK);
			MessageBox(hwnd, "恭喜你完成了游戏，觉得作者做的还行的话，可以赞助一下作者吗", "", MB_OK);
			IMAGE img2;
			loadimage(&img2, "63.png", 13 * 60, 13 * 60);
			putimage(0, 0, &img2);
			k = _getch();
			closegraph();
			exit(0);
			}
		//卡比
		else if (map[i+1][j] == 6)
		{
			int ID = MessageBox(hwnd, "是否攻击卡比", "遇到卡比", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &greenslime;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i+1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//史莱姆
		else if (map[i+1][j] == 7)
		{
			int ID = MessageBox(hwnd, "是否攻击史莱姆", "遇到史莱姆", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &redslime;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i+1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//法师
		else if (map[i + 1][j] == 10)
		{
			int ID = MessageBox(hwnd, "是否攻击法师", "遇到法师", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &fashi;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i + 1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//骷髅
		else if (map[i + 1][j] == 9)
		{
			int ID = MessageBox(hwnd, "是否攻击骷髅", "遇到骷髅", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &kulou;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i + 1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDYES)
						role1->blood = role_blood;
					else
					exit(0);	
				}
			}
			}
			//骷髅士兵
		else if (map[i + 1][j] == 15)
		{
			int ID = MessageBox(hwnd, "是否攻击骷髅士兵", "遇到骷髅士兵", MB_YESNO);
			if (ID == IDYES)
			{
				// 怪物的PK处理
				struct gameRole* role1 = &role;
				struct monster* m = &kulousoldier;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// 判断胜负
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i + 1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "是否复活", "太强啦，打不过！", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
			}
			//商人
		else if (map[i+1][j] == 21)
		{
			char k;
			IMAGE img2;
			if (role.jinbi >= 20)
			{
				loadimage(&img2, "61.png", 13 * 60, 13 * 60);

				putimage(0, 0, &img2);
				k = _getch();
				closegraph();
				switch (k) {
				case '1':
					role.jinbi -= 20;
						role.blood += 100;
					break;
				case '2':
					role.jinbi -= 20;
					role.attack += 20;
					break;
				case'3':
					role.jinbi -= 20;
					role.defence += 20;
					break;
				default:
					break;
				}
			}
			else
			{
				loadimage(&img2, "60.png", 13 * 60, 13 * 60);
				putimage(0, 0, &img2);
				k = _getch();
			}

			hwnd = initgraph(14 * 60, 13 * 60);
			drawmap();
			}
		break;

	}
}



