
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
//���޳�ʼ��
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
HWND hwnd;//ս��ʱ��ʾһ����Ϣ��
//�����û���

bool book = false;
void Book()
{
	if (book)	
	{
		switch (floor)
		{
		case 1:
			MessageBox(hwnd, "��������\t����\t����\t����\t��Ǯ\n\
����\t35\t18\t1\t10\n\
��ʷ��ķ\t45\t20\t2\t20\n\
��ʦ\t60\t32\t8\t50\n\
����\t35\t38\t3\t30\n\
������\t50\t42\t6\t60\n\
����ʿ��\t55\t52\t12\t80", "�����ֲ�", MB_OK);
			break;

		case 2:
			MessageBox(hwnd, "��������\t����\t����\t����\t��Ǯ\n\
����\t35\t18\t1\t10\n\
��ʷ��ķ\t45\t20\t2\t20\n\
��ʦ\t60\t32\t8\t50\n\
����\t35\t38\t3\t30\n\
������\t50\t42\t6\t60\n\
����ʿ��\t55\t52\t12\t80", "", MB_OK);
			break;

		case 3:
			MessageBox(hwnd, "��������\t����\t����\t����\t��Ǯ\n\
����\t35\t18\t1\t10\n\
��ʷ��ķ\t45\t20\t2\t20\n\
��ʦ\t60\t32\t8\t50\n\
����\t35\t38\t3\t30\n\
������\t50\t42\t6\t60\n", "", MB_OK);

			break;

		case 4:
			MessageBox(hwnd, "��������\t����\t����\t����\t��Ǯ\n\
����\t35\t18\t1\t10\n\
��ʷ��ķ\t45\t20\t2\t20\n\
��ʦ\t60\t32\t8\t50\n\
����\t35\t38\t3\t30\n\
������\t50\t42\t6\t60\n\
����ʿ��\t55\t52\t12\t80\n\
boss\t6000\t320\t100\t5000000", "", MB_OK);
			break;

		}
	}	
}

//������Դ
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
		// ����˫���������ͷ�����

		int role_attack = role->attack;
		int role_defence = role->defence;
		int m_attack = m->attack;
		int m_defence = m->defence;

		// ˫�����湥����ֱ����һ��Ѫ��С�ڵ���0
		while (role->blood > 0 && m->blood > 0)
		{
			// ����ȹ���
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

			// ���﹥��
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

//int ת����string
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
//��ͷ
void head() {

	void far cleardevice(void);
	outtextxy(60, 180, "�ںܾúܾ���ǰ��һ�����ң���������������ƽ��������ҵ");
	Sleep(2000);
	void far cleardevice(void);
	outtextxy(60, 180, "������һ��а���ħ������������һƬ�������������Ĺ�����ץ����");
	Sleep(2000);
	void far cleardevice(void);
	outtextxy(60, 180, "���װ������ߣ�ֻ������ܽ����ǵĹ�����ħ����ħצ�н�ȳ���");
	Sleep(2000);
	void far cleardevice(void);
	outtextxy(60, 180, "������������������֣�����������ʱ�����ǻὫ�����¼�����ʷ��");
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
	outtextxy(60, 200, "�������������֣�");
	outtextxy(60, 220, "�����л����뷨��Ӣ����������ֲ�������Ļ����ʾ,�����갴�»س�ȷ�Ͻ�����Ϸ��");
	outtextxy(60, 240, "������������һ�������ֲᣬ��Ϸ�п��԰�q���鿴�����ֲᣬ�����й������ϸ��Ϣ��");
	outtextxy(60, 260, "������Ϸ�ں�bjm���������������ѣ����������е�С��");
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
	//�ڵ�ͼ��Ѱ������
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
	userkey = _getch();//���ɼ�����
	switch (userkey)
	{
		//��
	case'A':
	case'a':
	case 75:
		//�յ�
		if (map[i][j - 1] == 1)
		{
			map[i][j] = 1;
			map[i][j - 1] = 17;
		}
		//��
		else if (map[i][j - 1] == 11)
		{
			map[i][j] = 1;
			map[i][j - 1] = 17;
			role.defence += 20;
		}
		//��
		else if (map[i][j - 1] == 12)
		{
			map[i][j] = 1;
			map[i][j - 1] = 17;
			role.attack += 16;
		}
		//��Կ��
		else if (map[i][j - 1] == 2)
		{
			map[i][j] = 1;
			map[i][j - 1] = 17;
			role.redKey++;
		}
		//������
		else if (map[i][j - 1] == 3 && role.redKey > 0)
		{
			role.redKey--;
			map[i][j - 1] = 17;
			map[i][j] = 1;
		}
		//��Կ��
		else if (map[i][j - 1] == 4)
		{
			map[i][j] = 1;
			map[i][j - 1] = 17;
			role.blueKey++;
		}
		//������
		else if (map[i][j - 1] == 5 && role.blueKey > 0)
		{
			role.blueKey--;
			map[i][j - 1] = 17;
			map[i][j] = 1;
		}
		//��Կ��
		else if (map[i][j - 1] == 28)
		{
			map[i][j] = 1;
			map[i][j - 1] = 17;
			role.yellowKey++;
		}
		//������
		else if (map[i][j - 1] == 27 && role.yellowKey > 0)
		{
			role.yellowKey--;
			map[i][j - 1] = 17;
			map[i][j] = 1;
		}
		//��ƿ
		else if (map[i][j - 1] == 14)
		{
			role.blood += 20;
			map[i][j - 1] = 17;
			map[i][j] = 1;
		}
		// ����ƿ
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
		//��¥
		else if (map[i][j - 1] == 18)
		{
			floor++;
			up(floor);
		}
		//��¥
		else if (map[i][j - 1] == 19)
		{
			floor--;
			
			down(floor);
		}
		//����
		else if (map[i][j - 1] == 8)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�С����", "����С����", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &bianfu;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j -1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDYES)
					role1->blood = role_blood;
					else
							exit(1);
				}
			}
		}
		//����
		else if (map[i][j - 1] == 9)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�������", "����������", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &kulou;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j - 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//����ʿ��
		else if (map[i][j - 1] == 15)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�����ʿ��", "��������ʿ��", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &kulousoldier;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j - 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
			}
		//��ʦ
		else if (map[i][j - 1] == 10)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻���ʦ", "������ʦ", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &fashi;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j - 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
			}
		//����
		else if (map[i][j - 1] == 6)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�����", "��������", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &greenslime;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
					// �ж�ʤ��
					if (role1->blood > 0)
					{
						role1->jinbi += m->jinbi;
						map[i][j] = 1;
						map[i][j - 1] = 17;
					}
					else
					{
						int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
						if (ID == IDNO)
							exit(0);
						else
							role1->blood = role_blood;
					}
			}
		}
		//ʷ��ķ
		else if (map[i][j - 1] == 7)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�ʷ��ķ", "����ʷ��ķ", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &redslime;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j - 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
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
			int ID = MessageBox(hwnd, "�Ƿ񹥻�BOSS", "����BOSS", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &boss;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j - 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���ע������ս����", MB_YESNO);
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
		MessageBox(hwnd, "����һ�������ֲᣬ������������¥�����й�������ԡ�\n�밴Q���鿴��", "", MB_OK);
		book = true;
		Book();
		
		break;
		//��
	case'd':
	case'D':
	case 77:
		if (map[i][j + 1] == 1)
		{
			map[i][j] = 1;
			map[i][j + 1] = 17;
		}
		//��
		else if (map[i][j + 1] == 12)
		{
			map[i][j] = 1;
			map[i][j + 1] = 17;
			role.attack += 20;

		}
		//��
		else if (map[i][j + 1] == 11)
		{
			map[i][j] = 1;
			map[i][j + 1] = 17;
			role.defence += 20;

		}
		//��Կ��
		else if (map[i][j + 1] == 2)
		{
			map[i][j] = 1;
			map[i][j + 1] = 17;
			role.redKey++;
		}
		//������
		else if (map[i][j + 1] == 3 && role.redKey > 0)
		{
			role.redKey--;
			map[i][j + 1] = 17;
			map[i][j] = 1;
		}
		//��
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
		//��
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
		//��ƿ
		else if (map[i][j + 1] == 14)
		{
			role.blood += 20;
			map[i][j + 1] = 17;
			map[i][j] = 1;
		}
		// ����ƿ
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
			int ID = MessageBox(hwnd, "�Ƿ񹥻�BOSS", "����BOSS", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &boss;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j+1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���ע������ս����", MB_YESNO);
					if (ID == IDYES)
						role1->blood = role_blood;
					else
						exit(0);
				}
			}
		}
		//����
		else if (map[i][j + 1] == 8)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�С����", "����С����", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &bianfu;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j + 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//��ʦ
		else if (map[i][j + 1] == 10)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻���ʦ", "������ʦ", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &fashi;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j + 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//����
		else if (map[i][j + 1] == 9)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�����", "��������", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &kulou;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j + 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//����ʿ��
		else if (map[i][j + 1] == 15)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�����ʿ��", "��������ʿ��", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &kulousoldier;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j + 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
			}
			//����
		else if (map[i][j + 1] == 6)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�����", "��������", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &greenslime;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j + 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		else if (map[i][j + 1] == 7)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�ʷ��ķ", "����ʷ��ķ", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &redslime;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i][j + 1] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//��¥
		else if (map[i][j + 1] == 18)
		{
			floor++;
			up(floor);
		}
		//��¥
		else if (map[i][j + 1] == 19)
		{
			floor--;

			down(floor);
		}
			//������
		else if (map[i][j + 1] == 29)
		{
			char k;
			while (getchar() != '\n');
			MessageBox(hwnd, "��ϲ�㣡�����˴����ţ����������ѡ���͵�¥�㣨�밴������Ҫǰ����¥�㰴����", "", MB_OK);
			k = getchar();
			floor = (int)k - '0';
			chuan(k);
		}

		break;
		//��
	case'w':
	case'W':
	case 72:
		if (map[i - 1][j] == 1)
		{
			map[i][j] = 1;
			map[i - 1][j] = 17;
		}
		//��
		else  if (map[i - 1][j] == 12)
		{
			map[i][j] = 1;
			map[i - 1][j] = 17;
			role.attack += 20;
		}
		//��
		else if (map[i - 1][j] == 11)
		{
			map[i][j] = 1;
			map[i - 1][j] = 17;
			role.defence += 20;
		}
		//��Կ��
		else if (map[i - 1][j] == 2)
		{
			map[i][j] = 1;
			map[i - 1][j] = 17;
			role.redKey++;
		}
		//������
		else if (map[i - 1][j] == 3 && role.redKey > 0)
		{
			role.redKey--;
			map[i - 1][j] = 17;
			map[i][j] = 1;
		}
		//��Կ��
		else if (map[i-1][j] == 4)
		{
			map[i][j] = 1;
			map[i-1][j] = 17;
			role.blueKey++;
		}
		//������
		else if (map[i-1][j] == 5 && role.blueKey > 0)
		{
			role.blueKey--;
			map[i-1][j] = 17;
			map[i][j] = 1;
		}
		//��Կ��
		else if (map[i-1][j] == 28)
		{
			map[i][j] = 1;
			map[i-1][j] = 17;
			role.yellowKey++;
		}
		//������
		else if (map[i-1][j] == 27 && role.yellowKey > 0)
		{
			role.yellowKey--;
			map[i-1][j] = 17;
			map[i][j] = 1;
		}
		//��¥
		else if (map[i - 1][j] == 18)
		{
			floor++;
			up(floor);
		}
		//��¥
		else if (map[i - 1][j] == 19)
		{
			floor--;
			down(floor);
		}
		//������
		else if (map[i-1][j] == 29)
		{
			char k;
			while (getchar() != '\n');
			MessageBox(hwnd, "��ϲ�㣡�����˴����ţ����������ѡ���͵�¥�㣨�밴������Ҫǰ����¥�㰴����", "", MB_OK);
			k = _getch();
			floor = (int)k - '0';
			chuan(k);
		}
		//��ƿ
		else if (map[i-1][j] == 14)
		{
			role.blood += 20;
			map[i - 1][j] = 17;
			map[i][j] = 1;
		}
		// ����ƿ
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
		//����
		else if (map[i-1][j ] == 8)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�С����", "����С����", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &bianfu;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i-1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//��ʦ
		else if (map[i - 1][j] == 10)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻���ʦ", "������ʦ", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &fashi;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i - 1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//����
		else if (map[i - 1][j] == 9)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�����", "��������", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &kulou;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i - 1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//����ʿ��
		else if (map[i - 1][j] == 15)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�����ʿ��", "��������ʿ��", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &kulousoldier;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i - 1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
			}
		//����
		else if (map[i-1][j] == 6)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�����", "��������", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &greenslime;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i-1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//ʷ��ķ
		else if (map[i-1][j] == 7)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�ʷ��ķ", "����ʷ��ķ", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &redslime;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i-1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		break;
		//��
	case'S':
	case's':
	case 80:
		if (map[i + 1][j] == 1)
		{
			map[i][j] = 1;
			map[i + 1][j] = 17;
		}
		//��
		if (map[i + 1][j] == 12)
		{
			map[i][j] = 1;
			map[i + 1][j] = 17;
			role.attack += 20;
		}
		//��
		if (map[i + 1][j] == 11)
		{
			map[i][j] = 1;
			map[i + 1][j] = 17;
			role.defence += 20;
		}
		//��Կ��
		else if (map[i + 1][j] == 2)
		{
			map[i][j] = 1;
			map[i + 1][j] = 17;
			role.redKey++;
		}
		//������
		else if (map[i + 1][j] == 3 && role.redKey > 0)
		{
			role.redKey--;
			map[i + 1][j] = 17;
			map[i][j] = 1;
		}
		//��Կ��
		else if (map[i + 1][j] == 4)
		{
			map[i][j] = 1;
			map[i + 1][j] = 17;
			role.blueKey++;
		}
		//������
		else if (map[i + 1][j] == 5 && role.blueKey > 0)
		{
			role.blueKey--;
			map[i + 1][j] = 17;
			map[i][j] = 1;
		}
		//��Կ��
		else if (map[i + 1][j] == 28)
		{
			map[i][j] = 1;
			map[i + 1][j] = 17;
			role.yellowKey++;
		}
		//������
		else if (map[i + 1][j] == 27 && role.yellowKey > 0)
		{
			role.yellowKey--;
			map[i + 1][j] = 17;
			map[i][j] = 1;
		}
		//��ƿ
		else if (map[i + 1][j] == 14)
		{
			role.blood += 20;
			map[i + 1][j] = 17;
			map[i][j] = 1;
		}
		// ����ƿ
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
		//��¥
		else if (map[i + 1][j] == 18)
		{
			floor++;
			up(floor);
		}
		//��¥
		else if (map[i + 1][j] == 19)
		{
			floor--;
			down(floor);
		}
		//������
		else if (map[i+1][j] == 29)
		{
			char k;
			//getchar();
			MessageBox(hwnd, "��ϲ�㣡�����˴����ţ����������ѡ���͵�¥�㣨�밴������Ҫǰ����¥�㰴����", "", MB_OK);
			k = _getch();
			if ('0' < k && k < '4')
			{
				floor = (int)k - '0';
				chuan(k);
			}
		}
		//����
		else if (map[i+1][j] == 8)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�С����", "����С����", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &bianfu;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i+1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		else if (map[i+1][j] == 30)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�BOSS", "����BOSS", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &boss;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i+1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���ע������ս����", MB_YESNO);
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
			MessageBox(hwnd, "��ϲ��ɹ���ȹ���", "��������", MB_OK);
			int ID1 = MessageBox(hwnd, "��Ҫ��������������", "�����ܸ�л��", MB_YESNO);
			if (ID1 == IDYES)
				MessageBox(hwnd, "��ƨ���أ����ֲ���ͯ������", "", MB_OK);
			else
				MessageBox(hwnd, "��ô�����Ĺ���������Ҫ��̫��ϧ�ˣ�һ�������������Ժ�϶�ûʲô��Ϣ��", "", MB_OK);
			MessageBox(hwnd, "��ϲ���������Ϸ�������������Ļ��еĻ�����������һ��������", "", MB_OK);
			IMAGE img2;
			loadimage(&img2, "63.png", 13 * 60, 13 * 60);
			putimage(0, 0, &img2);
			k = _getch();
			closegraph();
			exit(0);
			}
		//����
		else if (map[i+1][j] == 6)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�����", "��������", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &greenslime;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i+1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//ʷ��ķ
		else if (map[i+1][j] == 7)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�ʷ��ķ", "����ʷ��ķ", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &redslime;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i+1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//��ʦ
		else if (map[i + 1][j] == 10)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻���ʦ", "������ʦ", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &fashi;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i + 1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
		}
		//����
		else if (map[i + 1][j] == 9)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�����", "��������", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &kulou;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i + 1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDYES)
						role1->blood = role_blood;
					else
					exit(0);	
				}
			}
			}
			//����ʿ��
		else if (map[i + 1][j] == 15)
		{
			int ID = MessageBox(hwnd, "�Ƿ񹥻�����ʿ��", "��������ʿ��", MB_YESNO);
			if (ID == IDYES)
			{
				// �����PK����
				struct gameRole* role1 = &role;
				struct monster* m = &kulousoldier;
				int role_blood = role1->blood;
				PK(role1, m, map, i, j);
				// �ж�ʤ��
				if (role1->blood > 0)
				{
					role1->jinbi += m->jinbi;
					map[i][j] = 1;
					map[i + 1][j] = 17;
				}
				else
				{
					int ID = MessageBox(hwnd, "�Ƿ񸴻�", "̫ǿ�����򲻹���", MB_YESNO);
					if (ID == IDNO)
						exit(0);
					else
						role1->blood = role_blood;
				}
			}
			}
			//����
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



