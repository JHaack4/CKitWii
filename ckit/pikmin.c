//	p.branchlink(0x8015aa34, "createModel")
//	p.branchlink(0x8015089c, "loadNaviModel")
//	p.branchlink(0x8015ae50, "loadNaviModelOlimar")
//	p.branchlink(0x8014d50c, "birthMoreNavis")



#include "pikmin.h"
/*
char* naviname[] = { "orima", "loozy", "shacho", "wife", "alph", "brittany", "charlie", "pod", "purple", "pikpik", "bulbmin", "bread",
					 "pikmar", "duck", "mario", "luigi", "yoshi2", "toad", "waluigi", "knuckle", "bigcat", "pacman", "chunky", "raymond",
					 "hatkid", "rayman", "peppino", "penguin", "spongebob", "jenkins", "mike", "perry", "strongbad", "kermit", "bart", "stewie",
					 "moyai", "rin", "gumi", "bhacho",  "vaporeon", "spraymar", "nerdu", "quote", "meeo", "pat", "shake", "mandm" };

int* navimodeldata[] = { [0 ... 47] = 0 };

void birthMoreNavis()//brocoli made this
{
	__asm("lwz 3, -0x6d20(13)");
	__asm("lwz 0, 0x20(3)");
	__asm("lwz 3, 0x24(3)");
	__asm("cmpw 0, 3");
	__asm("beq +0x8");
	__asm("b initGenerators_8014d3f8");
	__asm("b initGenerators_8014d6ac");
}

uint32* createModel(uint32 this, int NaviID)// apply loaded captain models
{
	uint32* load = JSystem__operator_new(0x14);

	SysShape__Model(load, navimodeldata[NaviID], 0, 2);
	//OSReport("load %x \n", load);
	return load;
}

void loadNaviModel(void)
{
	char path[32];
	//int sysheap = *(uint32_t*)(*(uint32_t*)(SDA + SYSTEM) + 0x38);
	for (int i = 1; i < 0x30; i++)
	{
		sprintf(path, "player/%s/model.bmd", naviname[i]);
		uint32 *navi = JKRDvdRipper__loadToMainRAM(path, 0, 0, 0, 0, 1, 0, 0, 0);
		navimodeldata[i] = J3DModelLoaderDataBase__load(navi, 0x20000030);
	}
}

int loadNaviModelOlimar()//olimar loads seperately from the other captains
{
	uint32 *navi1 = JKRDvdRipper__loadToMainRAM("player/orima/model.bmd", 0, 0, 0, (JKRHeap*)0x0, 1, 0, 0, 0);

	navimodeldata[0] = J3DModelLoaderDataBase__load(navi1, 0x20000030);
	return navimodeldata[0];
}

*/

//bl 0x80245d80 "OnOnyonBirth"
int OnOnyonBirth(uint32 *r3, uint32 type, uint32 colorID)
{
	int maxcolors = 0;
	float pos[3];
	float unk;
	int room, base, roomType, spawns;
	int rooms = 0, roomNum = 0, roomInterval;
	int *pSpawns[23], *pSpawn;

	//if (onionmode == 1)
		maxcolors = 3;

	int* rsUnit = (*(int**)(0x80672800 - 0x5b58))[13];
	// Game::Cave::MapNode
	room = *(int*)(*(int*)(*rsUnit + 0x28) + 0x10);
	while (room) {
		roomType = Game__Cave__UnitInfo__getUnitKind(*(int*)(room + 0x18));
		if (roomType == 1) {
			base = Game__Cave__UnitInfo__getBaseGen(*(int*)(room + 0x18));
			if (base) {
				base = *(int*)(base + 0x10);
				while (base) {
					if (*(int*)(base + 0x18) == 7) {
						rooms++; break;
					}
					base = *(int*)(base + 4);
				}
			}
		}
		room = *(int*)(room + 4);
	}

	roomInterval = rooms / 3;
	if (!roomInterval) roomInterval++;
	// Game::Cave::MapNode
	room = *(int*)(*(int*)(*rsUnit + 0x28) + 0x10);
	while (room) {
		roomType = Game__Cave__UnitInfo__getUnitKind(*(int*)(room + 0x18));
		if (roomType == 1)// 1 = standard room
		{
			spawns = 0;

			base = Game__Cave__UnitInfo__getBaseGen(*(int*)(room + 0x18));
			if (base)
			{
				base = *(int*)(base + 0x10);
				pSpawn = pSpawns;
				while (base)
				{
					if (*(int*)(base + 0x18) == 7) //spawn point type
					{
						*pSpawn++ = base;
						spawns++;
					}
					base = *(int*)(base + 4);
				}
			}

			if (spawns && colorID < maxcolors && ++roomNum == (colorID + 1) * roomInterval)
			{
				//if (hasBootContainer(*(int*)(0x80672800 + -0x6b70), 2 - colorID))
				//{
					int onyon = ((int(*)(int, int, int))0x8020af78)(r3, 0, 2 - colorID++);
					Game__Creature__init(onyon, 0);
					int unitinfo = *(int*)(room + 0x18);

					//float rx = 170.0f * (*(int*)(room + 0x2c) + *(int*)(unitinfo + 0x10) * 0.5);
					//float rz = 170.0f * (*(int*)(room + 0x30) + *(int*)(unitinfo + 0x14) * 0.5);

						//int irot = *(int*)(unitinfo + 0xc);
						//float rot = *(int*)(unitinfo + 0xc) * 1.57;

					int ui = *(int*)(room + 0x18);
					float rx = 170.0f * (*(int*)(room + 0x2c) + *(int*)(ui + 0x10) * 0.5);
					float rz = 170.0f * (*(int*)(room + 0x30) + *(int*)(ui + 0x14) * 0.5);
					int irot = *(int*)(ui + 0xc);
					float rot = (*(int*)(ui + 0xc) - 0) * 1.57;

					float x = *(float*)&pSpawns[0][7];
					float z = *(float*)&pSpawns[0][9];
					pos[1] = *(float*)&pSpawns[0][8];
					pos[0] = x * p2cos(rot) - z * p2sin(rot) + rx;
					pos[2] = x * p2sin(rot) + z * p2cos(rot) + rz;
					Game__Creature__setPosition(onyon, pos, 0);
				//}

				//OSReport("Onion spawned at: %.2f %.2f %.2f\n", rx + *(float*)& pSpawns[0][7], *(float*)& pSpawns[0][8], rz + *(float*)& pSpawns[0][9]);
			}
		}
		room = *(int*)(room + 4);
	}
	return ((int(*)(int, int, int))0x8020af78)(r3, 1, 0);
}
/*
void purplenerf(int piki, int unk, int dumb)
{
	if (*(char*)(piki + 0x2b8) != 3)
		Creature__startStick(piki, unk, dumb);
}*/