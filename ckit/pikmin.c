#include "pikmin.h"

char released = 1;
char time = 0;
char drawpiki = 0;
char play = 0;
char inresult = 0;
int dead;
int alive;
int total_treasures = 0;
int total_enemies = 0;
int enemieskilled = 0;
char movieDie = 0;
char inselect = 0;
int factor = 0x10000000;
char* treasureName = " ";
int* newfont;
int entries = 0;
bool giveup = false;
bool nodemo = false;
uint32 color2 = 0xFFFFFFFF;
uint32 color3 = 0x0000FF00;
uint32 color5 = 0xFFFFFFFF;
uint32 color6 = 0x00990000;
uint32 color7 = 0xFFFFFFFF;
uint32 color8 = 0xFFFFFFFF;

uint32 seed = 0x00000000;
uint32* j2dpic = 0;
uint32* patend = 0;

int BeaconID = 0;
uint32* orimatex;
uint32* orimaicon;
uint32* navitex[60];
uint32* naviicon[60];
uint32* pikiicon[18];
int MEM1;
int MEM2;

double p2sin(double dontcare);
double p2cos(double dontcare);

const char max_option = 10;
const char characters = 60;
const char characters_per_row = 12;

//char* treasures[188] = { [0 ... 187] = 0 };

char* explorerTreasures[13] = { [0 ... 12] = 0 };

char* navitexDispname[60] = { [0 ... 47] = 0 };

char* naviname[] = { "orima", "loozy", "shacho", "wife", "alph", "brittany", "charlie", "pod", "purple", "pikpik", "bulbmin", "bread",
					 "pikmar", "duck", "mario", "luigi", "yoshi2", "toad", "waluigi", "knuckle", "bigcat", "pacman", "chunky", "raymond",
					 "hatkid", "rayman", "peppino", "penguin", "spongebob", "jenkins", "mike", "perry", "strongbad", "kermit", "bart", "stewie",
					 "moyai", "rin", "gumi", "bhacho",  "vaporeon", "spraymar", "nerdu", "quote", "meeo", "pat", "shake", "mandm",
					 "sleepy", "frog", "fiend", "morshu", "jeepers", "raz", "nickolox", "parappa", "wario", "person", "orima", "orima" };

char onionmode = 0;
//char player = 0;
char onyonid = 0;
bool randomstart = 0;
char randomize = 0;
char speedup = 0;
char drawtotals = 0;
char seedset = 0;
char twofiftyone;
char doublepikmin = 0;
char bigmode = 0;
signed char option = 0;
char enteringseed = 0;
signed char cndindex = 0;

char* description[] = { "How many players?",
						"Select your characters!",
						"Play with Onions in the cave!",
						"Double the max pikmin limit!",
						"Cameras are in first-person!",
						"Disable treasure collect cutscene!",
						"Include extra custom cave units!",
						"Extra-randomized layout (Unstable)",
						"Manually enter a layout seed to use!",
						"Choose what song will play!",
						"Enter the Colossal Caverns!" };
char DispEnemy[64];
char DispTreasure[64];
char DispSeed[64];
char DispSong[64];
char DispPlayer[64];
char DispTime[32];

char* cndfile[] = { "caveconc_00_0.cnd", "caveconc_05_0.cnd", "caveconc_10_0.cnd",
					"cavesoil_00_0.cnd", "cavesoil_05_0.cnd", "cavesoil_10_0.cnd",
					"cavemetal_00_0.cnd", "cavemetal_05_0.cnd", "cavemetal_05_1.cnd",
					"cavemetal_05_2.cnd", "cavemetal_05_3.cnd", "cavemetal_05_4.cnd", "cavemetal_10_0.cnd",
					"cavetsumiki_00_0.cnd", "cavetile_00_0.cnd", "caveglass_00_0.cnd",
					"new_00_0.cnd", "new_00_1.cnd", "new_01_0.cnd", "new_02_0.cnd",
					"new_03_0.cnd", "new_04_0.cnd", "new_05_0.cnd", "new_06_0.cnd",
					"new_07_0.cnd", "new_08_0.cnd", "new_08_1.cnd", "caverelax.cnd" };

char* cndname[] = { "Concrete 1", "Concrete 2", "Concrete 3",
					"Soil 1", "Soil 2", "Soil 3",
					"Metal 1", "Metal 2 (2)", "Metal 2 (unused 1)",
					"Metal 2 (unused 2)", "Metal 2 (unused 3)", "Metal 2", "Metal 3",
					"Toybox", "Tile", "Yard",
					"Emergence Cave", "Emergence Cave 2", "Mystic Marsh", "Jellyfloat",
					"Giant Breadbug", "Hot Cave", "Bulblax", "Snow",
					"Snagret", "Railroad", "Ramp Room", "Rest Cave",
					"Valley of Repose", "Awakening Wood", "Perplexing Pool", "Wistful Wild" };

register int * r0 __asm("r0");
register int * r1 __asm("r1");
register int * r2 __asm("r2");
register int * r8 __asm("r8");
register int * r27 __asm("r27");
register int * r28 __asm("r28");
register int * r29 __asm("r29");
register int * r30 __asm("r30");
register int * r31 __asm("r31");
register int * r3 __asm("r3");
register int * r4 __asm("r4");
register int * r5 __asm("r5");
register int * r14 __asm("r14");
register int * r15 __asm("r15");

char moved = 0;
char p1sel = 0;
char p2sel = 1;
int* font;
char paused = 0;
char first = 0;
char secretmode = 0;
char isUnderground = 0;

uint32* pad1;
int treasureCount, birthedTekiCount;
uint32 test;

uint32* j2dprint = 0;

void onCreateRoot1(int* r3) {
	MEM1 = r3;
}

void onCreateRoot2(int* r3) {
	MEM2 = r3;
}

void drawHeapInfo(int inGame) {
	if (inGame) {
		J2DPrint__print(j2dprint, 30.0f, 65.0f, "mem1: %x st: %x end: %x", MEM1, *(int *)(MEM1+0x30), *(int *)(MEM1+0x34)); 
		J2DPrint__print(j2dprint, 30.0f, 85.0f, "sz: %x free: %x", *(int *)(MEM1+0x38), JKRHeap__getTotalFreeSize(MEM1)); 
		J2DPrint__print(j2dprint, 30.0f, 105.0f, "mem2: %x st: %x end: %x", MEM2, *(int *)(MEM2+0x30), *(int *)(MEM2+0x34)); 
		J2DPrint__print(j2dprint, 30.0f, 125.0f, "sz: %x free: %x", *(int *)(MEM2+0x38), JKRHeap__getTotalFreeSize(MEM2)); 
	} else {
		char st11[128];
		char st21[128];
		char st12[128];
		char st22[128];
		sprintf(st11, "mem1: %x st: %x end: %x", MEM1, *(int *)(MEM1+0x30), *(int *)(MEM1+0x34)); 
		sprintf(st21, "sz: %x free: %x", *(int *)(MEM1+0x38), JKRHeap__getTotalFreeSize(MEM1)); 
		sprintf(st12, "mem2: %x st: %x end: %x", MEM2, *(int *)(MEM2+0x30), *(int *)(MEM2+0x34)); 
		sprintf(st22, "sz: %x free: %x", *(int *)(MEM2+0x38), JKRHeap__getTotalFreeSize(MEM2)); 
		JUTFont__print(font, 30.0f, 65.0f, st11, 0);
		JUTFont__print(font, 30.0f, 85.0f, st21, 0);
		JUTFont__print(font, 30.0f, 105.0f, st12, 0);
		JUTFont__print(font, 30.0f, 125.0f, st22, 0);
	}
}

void onDraw2D(uint32* Graphics)
{
	Game__BaseGameSection__draw2D(Graphics);

	draw2D(Graphics);
}

char* strdup(char* mem)
{
	int len = strlen(mem);
	char * result = __nwa(len + 1);
	memcpy(result, mem, len + 1);
	return result;
}

void setupRamStream(uint32* stream, uint32* file)
{
	ct_RamStream(stream, file, -1);
	stream[0xc / 4] = 1;
	stream[0x414 / 4] = 0;
}

void create2D()
{
	uint32 color2 = 0xFFFFFFFF;
	uint32 color3 = 0x00FF00FF;
	uint32 color4 = 0xFFFF00FF;
	uint32 color5 = 0xFF0000FF;
	char path[32];

	j2dprint = (uint32*)__nwa(0x64);
	font = *(int*)(P2JMEMgr + 0x18);
	J2DPrint____ct_FFF_TTTT(j2dprint, font, -0.5, -0.5, &color2, &color2, &color2, &color2);
	*(float*)(j2dprint + 0x50 / 4) = 22.0;
	*(float*)(j2dprint + 0x54 / 4) = 20.0;

	uint32* texdata = JKRDvdRipper__loadToMainRAM("background.bti", (unsigned char*)0x0, 0, 0, (JKRHeap*)0x0, 1, 0, 0, 0);
	if (texdata == 0)
		JUTException__panic_f("load.c", 0x7c, "no bg tex \n");

	j2dpic = (uint32*)__nwa(0x198);
	j2dpic = J2DPictureEx____ct(j2dpic, texdata, 0x0);

	for (int i = 0; i < characters; i++)
	{
		sprintf(path, "player/%s/icon.bti", naviname[i]);
		navitex[i] = JKRDvdRipper__loadToMainRAM(path, (unsigned char*)0x0, 0, 0, (JKRHeap*)0x0, 1, 0, 0, 0);
		if (navitex[i] == 0)
			JUTException__panic_f("load.c", 0x7c, "no icon %s \n", path);
		naviicon[i] = (uint32*)__nwa(0x198);
		naviicon[i] = J2DPictureEx____ct(naviicon[i], navitex[i], 0x0);
	}
	orimatex = JKRDvdRipper__loadToMainRAM("player/orima/icon.bti", (unsigned char*)0x0, 0, 0, (JKRHeap*)0x0, 1, 0, 0, 0);
	orimaicon = (uint32*)__nwa(0x198);
	orimaicon = J2DPictureEx____ct(orimaicon, orimatex, 0x0);

	pad1 = ct_Controller(__nwa(8), 0); // make controller

	//*(float*)0x805182AC = 1.3f;
	//*(float*)0x8051b73c = 400.0f;//empress roll fix
	onionmode = 0;
	//player = 1;
	onyonid = 0;
	randomstart = 0;
	randomize = 0;
	speedup = 0;
	paused = 0;
	play = 0;
	dead = 0;
	alive = 0;
	seed = 0x00000000;
	seedset = 0;
	twofiftyone = 0;
	doublepikmin = 0;
	bigmode = 0;
	treasureCount = 0;
	inresult = 0;
	birthedTekiCount = 0;
	option = 0;
	enteringseed = 0;
	drawtotals = 0;
	isUnderground = 0;
	cndindex = 0;
	test = 0;
	p1sel = 0;
	p2sel = 1;
	time = 0;
	first = 0;
	drawpiki = 0;
	inselect = 0;
	enemieskilled = 0;
	factor = 0x10000000;
	entries = 0;
	giveup = false;
	nodemo = false;

	int file = JKRDvdRipper__loadToMainRAM("player/names.txt", 0, 0, 0, 0, 1, 0, 0, 0);

	if (file == 0)
		JUTException__panic_f("load.c", 0x32f, "no name list file");

	int rstream[0x108];
	RamStream(rstream, file, -1);
	rstream[3] = 1;
	char* tok;

	for (int i = 0; i < characters; i++)
	{
		tok = getNextTok(rstream);
		for (int v = 0; v < strlen(tok); v++)
			if (tok[v] == '_') tok[v] = ' ';

		navitexDispname[i] = strdup(tok);
	}

	file = JKRDvdRipper__loadToMainRAM("treasure_names.txt", 0, 0, 0, 0, 2, 0, 0, 0);

	uint32 stream[0x41c / 4];
	setupRamStream(stream, file);
	for (int i = 0; i < 188; i++)
	{
		char* string = readString_Stream(stream, 0, 0);

		for (int j = 0; j < strlen(string); j++)
		{
			if (string[j] == '_') string[j] = ' ';
		}
		//treasures[i] = string;
	}

	file = JKRDvdRipper__loadToMainRAM("item_names.txt", 0, 0, 0, 0, 2, 0, 0, 0);

	setupRamStream(stream, file);
	for (int i = 0; i < 13; i++)
	{
		char* string;
		string = readString_Stream(stream, 0, 0);

		for (int j = 0; j < strlen(string); j++)
		{
			if (string[j] == '_') string[j] = ' ';
		}
		explorerTreasures[i] = string;
	}

}

void onPauseClose()
{
	paused = 0;
}

void checkcavescene()
{
	isUnderground = 1;
	r5 = 0;
	total_treasures = treasureCount;
	total_enemies = birthedTekiCount;
}

void endObjFloor()
{
	if (isUnderground != 0)
		r30 = 1;
	else
		r30 = 0;
}

int PressLeft(int* pad)
{
	if (checkButton(pad, PRESS_DL) || checkStick(pad, ANALOG_LEFT))
		return 1;
	else
		return 0;
}

int PressRight(int* pad)
{
	if (checkButton(pad, PRESS_DR) || checkStick(pad, ANALOG_RIGHT))
		return 1;
	else
		return 0;
}

int PressUp(int* pad)
{
	if (checkButton(pad, PRESS_DU) || checkStick(pad, ANALOG_UP))
		return 1;
	else
		return 0;
}

int PressDown(int* pad)
{
	if (checkButton(pad, PRESS_DD) || checkStick(pad, ANALOG_DOWN))
		return 1;
	else
		return 0;
}

int PressAnalog(int* pad)
{
	int up = PressUp(pad);
	if (up != 0)
		return 1;

	int down = PressDown(pad);
	if (down != 0)
		return 1;

	int left = PressLeft(pad);
	if (left != 0)
		return 1;

	int right = PressRight(pad);
	if (right != 0)
		return 1;

	return 0;
}

void draw2D(uint32* graphics)
{
	time++;

	

	if (paused == 1)
	{
		if (seedset == 1) test = seed;
		else sprintf(DispSeed, "Seed: 0x%08X", test);
		JUTFont__print(font, 180.0f, 430.0f, DispSeed, 0);
		drawHeapInfo(0);
	}
	else
	{
		drawHeapInfo(1);
	//	J2DPrint__print(j2dprint, 450.0, 18.0, "Enemies: %i", birthedTekiCount);
		//J2DPrint__print(j2dprint, 430.0, 38.0, "cheap: %x", JKRHeap__getTotalFreeSize(CURRENTHEAP));
	}

	
}

void onNintendoLogo(void)
{
	if (checkButton(pad1, PRESS_1) && checkButton(pad1, PRESS_2) && secretmode == 0)
	{
		playSystemSe(SFX, 0x1806, 1);
		secretmode = 1;
		//writeAt(0x8014a5d0, 0x3be00003);
	}
}

int getCavePikis(int *r3, int r4)
{
	r3 = r3[1];

	if (r4 == 0 || r4 == 3 || r4 == 6)
		r3[r4] = 0x19;
	else
		r3[r4] = 0x0;

	return r3;
}

void onCaveinit(int this)
{
	rand();

	if (play == 0)
	{
		play = 1;
		PSStart2DStream(0xc001100f);
	}

	if (*(float*)(this + 0x54) < 1000.0f && inselect == 0)
	{

		JUTFont__print(font, 40.0f, 420.0f, description[option], 0);

		JUTFont__print(font, 140.0f, 20.0f, "Select Game Options", 0);

		JUTFont__print(font, 400.0f, 20.0f, "Wii Version 1.0", 0);
		JUTFont__print(font, 40.0f, 50.0f, "Player Count: Coming Soon", 0);

		JUTFont__print(font, 40.0f, 80.0f, "Select Characters", 0);

		JUTFont__print(font, 40.0f, 110.0f, "Onion Mode", onionmode);

		JUTFont__print(font, 40.0f, 140.0f, "200 Pikmin Limit", doublepikmin);

		JUTFont__print(font, 40.0f, 170.0f, "First Person", bigmode);

		JUTFont__print(font, 40.0f, 200.0f, "No Treasure Cutscene", nodemo);

		JUTFont__print(font, 40.0f, 230.0f, "Use Extra Units", twofiftyone);

		JUTFont__print(font, 40.0f, 260.0f, "Ultra-Randomizer", randomize);


		if (seedset == 1)
		{
			sprintf(DispSeed, "Seed: 0x%08X", seed);
			JUTFont__print(font, 40.0f, 290.0f, DispSeed, 1, 0);
		}
		else
			JUTFont__print(font, 40.0f, 290.0f, "Seed: ", 0, 0);

		sprintf(DispSong, "Song: %s", cndname[cndindex]);
		JUTFont__print(font, 40.0f, 320.0f, DispSong, 0, 0);

		JUTFont__print(font, 40.0f, 350.0f, "Begin!", 0, 0);

		if (!PressAnalog(pad1) && !checkButton(pad1, PRESS_A) && !checkButton(pad1, PRESS_B) && !checkButton(pad1, PRESS_PLUS))
			released = 1;

		if (PressDown(pad1) && released  && enteringseed == 0)
		{
			option++;
			released = 0;
		}

		if (PressUp(pad1) && released  && enteringseed == 0)
		{
			option--;
			released = 0;
		}

		if (option < 0)
			option = max_option;
		if (option > max_option)
			option = 0;

		if (checkButton(pad1, PRESS_A) && released && enteringseed == 0)
		{
			switch (option)
			{
			case 0: // 2p mode
			{
				break;
			}
			case 1://select
			{
				inselect = 1;
				break;
			}
			case 2:// onion mode
			{
				if (onionmode == 0)
					onionmode = 1;
				else
					onionmode = 0;
				break;
			}
			case 3:// 200 pikmin
			{
				if (doublepikmin == 0)
				{
					doublepikmin = 1;
				}
				else
				{
					doublepikmin = 0;
				}
				break;
			}
			case 4://FirstPerson
			{
				if (bigmode == 0)
				{
					bigmode = 1;
				}
				else
				{
					bigmode = 0;
				}
				break;
			}
			case 5://treasure demo
			{
				if (!nodemo)
				{
					nodemo = true;
				}
				else
				{
					nodemo = false;
				}
				break;
			}
			case 6:// 251 caves
			{
				if (twofiftyone == 0)
				{
					twofiftyone = 1;
					randomize = 0;
				}
				else
					twofiftyone = 0;
				break;
			}
			case 7:// randomstart
			{
				if (randomize == 0) {
					randomize = 1;
					twofiftyone = 0;
				}
				else {
					randomize = 0;
				}
				break;
			}
			case 8:// seed set
			{
				seedset = 0;
				enteringseed = 1;
				break;
			}
			case 9:// song select
			{
				cndindex++;
				if (cndindex > 31)
					cndindex = 0;
				break;
			}
			case 10:// begin
			{
				initgame();
				*(float*)(this + 0x54) = 1000.0f;
				break;
			}
			}
			released = 0;
			playSystemSe(SFX, 0x180E, 1);
		}
		if (checkButton(pad1, PRESS_PLUS) && !enteringseed && released)
		{
			initgame();
			*(float*)(this + 0x54) = 1000.0f;
			released = 0;
			playSystemSe(SFX, 0x180E, 1);
		}
		JUTFont__print(font, 10.0f, (float)((option * 30.0) + 50.0), "->", 0, 0);
		//J2DPictureEx__draw(j2dpic, 0.0f, 0.0f, 0, 0, 0);
	}

	if (enteringseed == 1)
		EntersetSeed(this);
	if (option == 9)
		changeCND();
	if (inselect == 1 && *(float*)(this + 0x54) < 1000.0f)
		CharacterSelect(this);

	drawHeapInfo(0);
}

void initgame()
{
	if (randomize == 1)
	{
		writeAt(0x802d0fec, 0x2c195000);//wii createmappartslist
	}
	if (doublepikmin == 1)
	{
		writeAt(0x801f0fb4, 0x38c000c8);//wii piki model
		writeAt(0x801e43c4, 0x388000c8);//wii piki object
		writeAt(0x801d2b08, 0x388000c8);//wii cplate
		writeAt(0x80224c88, 0x2c0000c8);//wii cplate slot
		writeAt(0x80266580, 0x2c0000c8);//wii pikihead birth
		writeAt(0x801f09d4, 0x2c0000c8);//wii pikimgr birth
		writeAt(0x801f0a0c, 0x2c0000c8);//wii pikimgr birth 2
		writeAt(0x8053b004, 0x3a0000c8);//onyon max
	}
	if (nodemo)
	{
		writeAt(0x80234f7c, 0x428000ec);
		writeAt(0x8023508c, 0x42800100);
	}
}

void changeCND()
{
	if (PressRight(pad1) && released)
	{
		released = 0;
		cndindex++;
		playSystemSe(SFX, 0x1806, 1);
	}
	if (PressLeft(pad1) && released)
	{
		released = 0;
		cndindex--;
		playSystemSe(SFX, 0x1806, 1);
	}
	if (cndindex > 31)
		cndindex = 0;
	if (cndindex < 0)
		cndindex = 31;
}

void storeCaveSeed(void)
{
	if (seedset == 1)
	SEED = seed;

	else
	test = SEED;

	__asm("li 27, 0x0");
}

void onCaveLoading()
{
	if (seedset == 1) sprintf(DispSeed, "Seed: 0x%08X", seed);
	else sprintf(DispSeed, "Seed: 0x%08X", test);
	JUTFont__print(font, 10.0f, 40.0f, DispSeed, 0);
	*(int*)(*(int*)(GAMESYS + 0x40) + 0x218) = 2;

	drawHeapInfo(0);
}

void addTekiBirthCount()
{
	int tekiId = r0;

	if ((tekiId < 3 || tekiId > 8) && tekiId != 83 && tekiId != 31 && (tekiId < 46 || tekiId > 52) && (tekiId < 85 || tekiId > 92) && tekiId != 83 && tekiId != 74 && tekiId != 77)
	birthedTekiCount++;

	__asm("cmpwi 0, 0xffffffff");
}

int subTekiBirthCount()
{
	int* enemy = r30;
	int tekiId = ((int(*)()) *(int*)(*enemy + 0x258))(enemy);

	if ((tekiId < 3 || tekiId > 8) && tekiId != 31 && tekiId != 74 && tekiId != 68 && tekiId != 77 && birthedTekiCount > 0)
	{
		birthedTekiCount--;
	}
	return enemy;
}

void onKill_Hiba(void)
{
	birthedTekiCount--;
}

void onPauseMenu()
{
	paused = 1;
}

void onOtakaraborn(void)
{
	treasureCount++;
	__asm("cmpwi 4, 0x0");
}

void getFirstGlobe(void)
{
	float* pikiparms = *(float**)(PIKIMGR + 0x6c);

	pikiparms[0x440] += 0.3;//increase carry speed
	pikiparms[0x44a] += 0.3;
}

void getSecondGlobe(void)
{
	writeAt(0x802ca1a4, 0x428000ac);//wii
}

void getfist()
{
	if(r31 == 0)
	writeAt(0x8020e828, 0x60000000);//wii

	r0 = 1;
}

void onOtakaraCollected(void)
{
	treasureCount--;
	r4 = 0;
}

int strlen(char* b)
{
	int len = 0;
	while (*b++) len++;
	return len;
}

void JUTFont__print(int font, float x, float y, char* s, int set, int digit)
{
	uint32 color5 = 0xFF000000;
	uint32 color2 = 0xFFFFFFFF;
	uint32 color3 = 0x0000FF00;

	float xoff = x;
	unsigned char unk[2];
	for (int i = 0; i < strlen(s); i++)
	{
		JUTResFont__getWidthEntry(font, s[i], &unk);
		if (set == 0)
			JUTResFont__setGX(font, &color3, &color2);
		else
			JUTResFont__setGX(font, &color5, &color2);

		if (set == 2 && digit != i)
			JUTResFont__setGX(font, &color3, &color2);
		else if (set == 2 && digit == i)
			JUTResFont__setGX(font, &color5, &color2);

		JUTResFont__drawChar_scale(xoff, y, 22.0, 20.0, font, s[i], 1);
		xoff += (float)(unk[1] * 0.80);
	}
}

int OnOnyonBirth(uint32 *r3, uint32 type, uint32 colorID)
{
	int maxcolors = 0;
	float pos[3];
	float unk;
	int room, base, roomType, spawns;
	int rooms = 0, roomNum = 0, roomInterval;
	int *pSpawns[23], *pSpawn;

	if (onionmode == 1)
		maxcolors = 3;

	int* rsUnit = (*(int**)(SDA - 0x5b58))[13];
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
	while (room)
	{
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

			if (spawns && colorID < maxcolors &&
				++roomNum == (colorID + 1) * roomInterval) {

				int onyon = ((int(*)(int, int, int))0x8020af78)(r3, 0, 2 - colorID++);
				Game__Creature__init(onyon, 0);
				int unitinfo = *(int*)(room + 0x18);

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
			}
		}
		room = *(int*)(room + 4);
	}
	return ((int(*)(int, int, int))0x8020af78)(r3, 1, 0);
}

void EntersetSeed(void)
{
	uint32 padstat1 = *(pad1 + 6);
	char DispSeed[32];

	int count = (seed >> ((8 - entries - 1) * 4)) % 0x10;
	if (PressUp(pad1) && count < 0xf && released)
	{
		seed += factor;
		released = 0;
	}

	if (PressDown(pad1) && seed > 0 && count > 0 && released)
	{
		seed -= factor;
		released = 0;
	}

	if (PressRight(pad1) && released)
	{
		released = 0;
		factor /= 0x10;
		entries++;
		playSystemSe(SFX, 0x1806, 1);
	}

	if (PressLeft(pad1) && released && entries > 0)
	{
		released = 0;
		factor *= 0x10;
		entries--;
		playSystemSe(SFX, 0x1806, 1);
	}
	if (checkButton(pad1, PRESS_B) && released)
	{
		released = 0;
		entries = 0;
		seed = 0;
		factor = 0x10000000;
		enteringseed = 0;
		seedset = 0;
		playSystemSe(SFX, 0x1807, 1);
	}
	if (checkButton(pad1, PRESS_A) && released)
	{
		released = 0;
		entries = 8;
		playSystemSe(SFX, 0x1806, 1);
	}

	if (entries == 8)
	{
		entries = 0;
		factor = 0x10000000;
		enteringseed = 0;
		seedset = 1;
	}

	sprintf(DispSeed, "0x%08X", seed);
	JUTFont__print(font, 110.0f, 290.0f, DispSeed, 2, 2 + entries);
}

void initUnitlist()
{
	int loaded;
	char* path;

	if (twofiftyone == 0)
		path = "user/Mukki/mapunits/units/all_units.txt";
	else
		path = "user/Mukki/mapunits/units/all_units251.txt";

	loaded = JKRDvdRipper__loadToMainRAM(path, 0, 0, 0, 0, 2, 0, 0, 0);

	if (loaded == 0)
		JUTException__panic_f("load.c", 0x32f, "no %s\n", path);
}

void changeCaveSong()
{
	char* cnd = cndfile[cndindex];
	r4 = cnd;
}

void writeAt(uint32* address, uint32 value)
{
	address[0] = value;
	__flush_cache(address, 4);
}

void CharacterSelect(int this)
{
	uint32 padstat1 = *(pad1 + 6);
	uint32 analogstat = padstat1 >> 16;
	JUTFont__print(font, 150.0f, 20.0f, "Choose Your Fighter!", 1, 0);
	JUTFont__print(font, 10.0f, 20.0f, "<- B", 1, 0);

	if (!PressAnalog(pad1) && !checkButton(pad1, PRESS_A) && !checkButton(pad1, PRESS_B) && !checkButton(pad1, PRESS_PLUS))
		released = 1;

	drawcharactermenu();

	drawp1select();
	drawp2select();

	if (checkButton(pad1, PRESS_B) && released)
	{
		released = 0;
		inselect = 0;
	}
	
	if (checkButton(pad1, PRESS_PLUS) && released)
	{
		initgame();
		*(float*)(this + 0x54) = 1000.0f;
		released = 0;
		playSystemSe(SFX, 0x180E, 1);
	}
}

void drawcharactermenu()
{
	for (int i; i < characters; i++)
	{
		float xpos = (float)(50.0f * (float)i);
		float ypos = 40.0f;
		if (i > (characters_per_row - 1))
		{
			xpos -= 600.0f;
			ypos = 90.0f;
		}
		if (i > (int)(2 * characters_per_row - 1))
		{
			xpos -= 600.0f;
			ypos = 140.0f;
		}
		if (i > (int)(3 * characters_per_row - 1))
		{
			xpos -= 600.0f;
			ypos = 190.0f;
		}
		if (i > (int)(4 * characters_per_row - 1))
		{
			xpos -= 600.0f;
			ypos = 240.0f;
		}
		J2DPictureEx__draw(naviicon[i], xpos, ypos, 0, 0, 0);
	}
}

void drawp1select()
{
	if (!PressAnalog(pad1))
		released = 1;

	if (PressLeft(pad1) && released && p1sel > 0)
	{
		p1sel--;
		playSystemSe(SFX, 0x1806, 1);
		released = 0;
	}

	if (PressUp(pad1) && released && p1sel >= characters_per_row)
	{
		p1sel -= characters_per_row;
		playSystemSe(SFX, 0x1806, 1);
		released = 0;
	}

	if (PressDown(pad1) && released && p1sel < (characters - characters_per_row))
	{
		p1sel += characters_per_row;
		playSystemSe(SFX, 0x1806, 1);
		released = 0;
	}

	if (PressRight(pad1) && released && p1sel < characters - 1)
	{
		p1sel++;
		playSystemSe(SFX, 0x1806, 1);
		released = 0;
	}

	JUTFont__print(font, 10.0f, 320.0f, "Captain 1", 0, 0);

	J2DPictureEx__draw(naviicon[p1sel], 40.0f, 330.0f, 0, 0, 0);
	JUTFont__print(font, 20.0f, 360.0f, "<", 0, 0);
	JUTFont__print(font, 90.0f, 360.0f, ">", 0, 0);
	JUTFont__print(font, 20.0f, 400.0f, navitexDispname[p1sel], 0, 0);
}

void drawp2select()
{
	if (!PressAnalog(pad1))
		released = 1;

	if (PressLeft(pad1) && released && p2sel > 0)
	{
		p2sel--;
		playSystemSe(SFX, 0x1806, 1);
		released = 0;
	}

	if (PressRight(pad1) && released && p2sel < characters - 1)
	{
		p2sel++;
		playSystemSe(SFX, 0x1806, 1);
		released = 0;
	}

	if (PressUp(pad1) && released && p2sel >= characters_per_row)
	{
		p2sel -= characters_per_row;
		playSystemSe(SFX, 0x1806, 1);
		released = 0;
	}

	if (PressDown(pad1) && released && p2sel < (characters - characters_per_row))
	{
		p2sel += characters_per_row;
		playSystemSe(SFX, 0x1806, 1);
		released = 0;
	}

	JUTFont__print(font, 160.0f, 320.0f, "Captain 2", 0, 0);

	J2DPictureEx__draw(naviicon[p2sel], 190.0f, 330.0f, 0, 0, 0);
	JUTFont__print(font, 170.0f, 360.0f, "<", 0, 0);
	JUTFont__print(font, 240.0f, 360.0f, ">", 0, 0);
	JUTFont__print(font, 170.0f, 400.0f, navitexDispname[p2sel], 0, 0);
}


uint32* navi1modeldata;
uint32* navi2modeldata;
uint32* navi3modeldata;
uint32* navi4modeldata;
uint32* createModel(uint32 this, int NaviID)// apply loaded captain models
{
	uint32* load = JSystem__operator_new(0x14);

	if (load && NaviID == 0)
	SysShape__Model__ct(load, navi1modeldata, 0, 2);

	else if (load && NaviID == 1)
	SysShape__Model__ct(load, navi2modeldata, 0, 2);

	return load;
}

void loadNaviModel(uint32* this)//code to load man captain models
{
	uint32 *navi2;
	char path[32];

	sprintf(path, "player/%s/model.bmd", naviname[p2sel]);
	navi2 = JKRDvdRipper__loadToMainRAM(path, (unsigned char*)0x0, 0, 0, (JKRHeap*)0x0, 1, 0, 0, 0);

	if(navi2 == 0)
		JUTException__panic_f("load.c", 0x7c, "no model %s \n", path);

	navi2modeldata = J3DModelLoaderDataBase__load(navi2, 0x20000030);
}

int loadNaviModelOlimar()//olimar loads seperately from the other captains
{
	uint32 *navi1;
	char path[32];

	sprintf(path, "player/%s/model.bmd", naviname[p1sel]);
	navi1 = JKRDvdRipper__loadToMainRAM(path, (unsigned char*)0x0, 0, 0, (JKRHeap*)0x0, 1, 0, 0, 0);

	if (navi1 == 0)
		JUTException__panic_f("load.c", 0x7c, "no model %s \n", path);

	navi1modeldata = J3DModelLoaderDataBase__load(navi1, 0x20000030);
	return navi1modeldata;
}

void NaviHealth(float* this)// set captain life to double normal
{
	this[0xa8] = 150.0f;
}

void drawCredits(void)//draw custom cave results
{
	if (giveup)
		treasureCount = total_treasures;

	static int doDraw = 0;
	static int drawpat = 0;
	char treasures[64];
	char pikicount[32];
	char tekicount[32];
	char deadcount[32];
	char pokocount[32];

	int seconds = (time / 30) % 60;
	int minutes = ((time / 30) / 60) % 60;
	int hours = (((time / 30) / 60) / 60);
	sprintf(DispTime, "Time: %02i:%02i:%02i", hours, minutes, seconds);

	int pokos = *(int*)(PLAYDATA + 0xe8);
	int pikis = alive;

	if (checkButton(pad1, PRESS_A))
	doDraw = 1;
	if (checkButton(pad1, PRESS_B))
	{
		doDraw = 0;
		drawpat = 0;
	}

	naviicon[0] = orimaicon;

	int patmode = checkpatmode(dead);

	if (doDraw == 1)
	{
		J2DPictureEx__draw(j2dpic, 0.0f, 0.0f, 0, 0, 0);
		JUTFont__print(font, 110.0f, 30.0f, "Results", 1,0);
		JUTFont__print(font, 410.0f, 30.0f, DispTime, 0, 0);
		J2DPictureEx__draw(naviicon[p1sel], 550.0f, 50.0f, 0, 0, 0);
		J2DPictureEx__draw(naviicon[p2sel], 550.0f, 100.0f, 0, 0, 0);

		JUTFont__print(font, 10.0f, 60.0f, DispSeed, seedset, 0);

		sprintf(pokocount, "Pokos: %i", pokos);
		JUTFont__print(font, 10.0f, 90.0f, pokocount, pokos >= 10000, 0);

		sprintf(tekicount, "Enemies Killed: %i/%i", total_enemies - birthedTekiCount, total_enemies);
		JUTFont__print(font, 10.0f, 120.0f, tekicount, birthedTekiCount == 0, 0);

		sprintf(treasures, "Treasures Collected: %i/%i", total_treasures - treasureCount, total_treasures);
		JUTFont__print(font, 10.0f, 150.0f, treasures, treasureCount == 0, 0);

		sprintf(deadcount, "Pikmin killed: %i", dead);
		JUTFont__print(font, 10.0f, 180.0f, deadcount, dead == 0, 0);

		sprintf(pikicount, "Pikmin alive: %i", pikis);
		JUTFont__print(font, 10.0f, 210.0f, pikicount, pikis >= 75, 0);

		JUTFont__print(font, 10.0f, 240.0f, "Credits: PikHacker, Yoshifirebird, mr brocoli", 0,0);
		JUTFont__print(font, 10.0f, 270.0f, "Pat277, Quote Balrog, Kai, Minty Meeo", 0, 0);
		JUTFont__print(font, 10.0f, 420.0f, "Thanks for playing!", 0, 0);

		if (treasureCount == 0)// for 100%
		{
			JUTFont__print(font, 20.0f, 300.0f, "You got every treasure!", 1,0);
			JUTFont__print(font, 20.0f, 330.0f, "Press 1 + 2 on the Nintendo Logo,", 1,0);
			JUTFont__print(font, 20.0f, 360.0f, "then again in-game for a surprise!", 1,0);

			if (patmode == 1 && checkButton(pad1, PRESS_1))
			{
				drawpat = 1;
			}
			if(drawpat == 1)
			J2DPictureEx__draw(patend, 0.0f, 0.0f, 0, 0, 0);
		}
	}
	__asm("addi 1, 1, 0x20");
}

int checkFirstPerson()//802d6968
{
	return bigmode != 0;
}

void onMoviePlay()//allows for cutscene skip in treasure get
{
	movieDie = 0;
}

int Game__MoviePlayer__updateHook(int r3, int r4, int r5)//allows for cutscene skip in treasure get
{
	Game__MoviePlayer__update(r3, r4, r5);
	if (movieDie)
	{
		if (*(uint32_t*)(r3 + 0x18) == 6)
			movieDie = 0;
		else if (checkButton(pad1, PRESS_PLUS) && *(uint32_t*)(r3 + 0x18) == 5)
		{
			movieDie = 0;
			Game__MoviePlayer__skip(r3);
		}
	}
	return 1;
}

void incGroundOtakara(void)//allows for cutscene skip in treasure get
{
	movieDie = 1;
}

void spraycount(int this)//set initial spray count
{
	if (first == 0)
	{
		first = 1;//this makes it only apply once, yeah its the lazy way
		*(int*)(this + 0xc0) = 3;//spicy
		*(int*)(this + 0xbc) = 3;//bitter
	}
	else
		__asm("lwz 3, 0xC0(3)");
}

void setinresult()// on opening cave results
{
	inresult = 1;
	int texdata;
	int patmode = checkpatmode(dead);
	if (patmode == 1)
	{
		texdata = JKRDvdRipper__loadToMainRAM("player/pat/patending.bti", (unsigned char*)0x0, 0, 0, (JKRHeap*)0x0, 1, 0, 0, 0);
		patend = (uint32*)__nwa(0x198);
		patend = J2DPictureEx____ct(patend, texdata, 0x0);
	}
}

void onbootfixastflag()//resetting this needs its own function because create2D runs too late
{
	secretmode = 0;
	inresult = 0;
}

void streamfilename(char* name)// used to play character victory theme, if in the results any ast loaded will use player 1s path.
{
	char path[32];
	if(inresult == 0)
	JAInter__StreamMgr__playDirect(name);

	else
	{
		sprintf(path, "player/%s/theme.ast", naviname[p1sel]);
		JAInter__StreamMgr__playDirect(path);
	}
}

int ongiveup()// the giveup variable exists so our own total treasures is accurate
{
	giveup = true;
	return PIKIMGR;
}

int bigtreasuredead(int this)// this function makes TD drop its weapons on death, so they arent deleted
{
	int item = this;

	for (int i = 0; i < 4; i++)
	{
		if ((*(int*)(item + 0x3c4) != 0))
		{
			Game__BigTreasure__Obj__createDropTreasureEffect(this, i);
			Game__BigTreasure__Obj__finishTreasurePinchSmoke(this, i);
			Game__BigTreasure__Obj__dropTreasure(this, i);
		}
		item = (int*)(item + 4);
	}
	return *(int*)(this + 0x3d4);
}

int setCNDtype()
{
	if (cndindex > 27)//is overworld
		return 0;
	else
		return 1;
}

void mainBGM()
{
	if (cndindex > 27)
		r4 = cndindex - 28;//set what bms loads
	else
		__asm("lwz 4, 0x48(3)");
}

void isoverworld()
{
	r0 = (cndindex < 28);// 28+ is the overworld themes
}

int gatecolor()
{
	int gate = r31;

	if (*(float*)(gate + 0x204) >= 1800.0f)// gate max hp
		return 1;//dark
	else
		return 0;//light
}

/*
void unleashsatan()
{
	uint32* orima = MonoObjectMgr_GameNavi__getAt(*(uint32 * *)(SDA + NAVIMGR), 0);
	float foff = 0.0f;
	uint32_t pikiMgr = *(uint32_t*)(SDA + PEOTMGR);
	pikiMgr = (uint32)(pikiMgr + 0x70);
	uint32_t pikiID = MonoObjectMgr_Otakara__getStart(pikiMgr);

	writeAt(0x80167628, 0x38000002);
	char cellItArg[0x20];
	char cellIt[0x54];
	float fIn[4] = { *(float*)(orima + 0x83), *(float*)(orima + 0x84), *(float*)(orima + 0x85), 5000.0 };

	CellIteratorArg__ct(cellItArg, fIn);
	CellIterator__ct(cellIt, cellItArg);
	CellIterator__first(cellIt);
	foff = 0.0f;

	uint32_t pikiEnd = MonoObjectMgr_Otakara__getEnd(pikiMgr);
	while (pikiID < pikiEnd)
	{
		uint32_t piki = MonoObjectMgr_Otakara__get(pikiMgr, pikiID);
		if (*(uint16_t*)(piki + 0x128) != 0x40e)
		{
			foff += 10.0f;
			*(float*)(piki + 0x3aC) = *(float*)(orima + 0x83) + p2sin(0.0174532 * foff) * foff / 8.0f;
			*(float*)(piki + 0x3b0) = *(float*)(orima + 0x84) + foff / 3.0f;
			*(float*)(piki + 0x3b4) = *(float*)(orima + 0x85) + p2cos(0.0174532 * foff) * foff / 8.0f;
			*(float*)(piki + 0x1f4) = 0.0f;
			pikiID = MonoObjectMgr_Otakara__getNext(pikiMgr, pikiID);
		}
	}

	while (!CellIterator__isDone(cellIt)) {
		uint32 ent = CellIterator__operator_(cellIt);
		if (Creature__isTeki(ent))
		{
			foff += 10.0f;
			*(float*)(ent + 0x18c) = *(float*)(orima + 0x83) + p2sin(0.0174532 * foff) * foff / 10.0f;
			*(float*)(ent + 0x190) = *(float*)(orima + 0x84) + foff / 24.0f;
			*(float*)(ent + 0x194) = *(float*)(orima + 0x85) + p2cos(0.0174532 * foff) * foff / 10.0f;
			*(float*)(ent + 0x200) = 0.0f;
		}
		CellIterator__next(cellIt);
	}
}
*/

void InitJ2dPrint(uint32* j2dprint)
{
	newfont = P2JMEMgr;
	if (newfont != 0) {
		newfont = newfont[0x18 / 4];
	}
	J2DPrint____ct_FF(j2dprint, newfont, 0.1);
	J2DPrint__initiate(j2dprint);
}

void update_totalPokoScreen_Redirect(uint32* totalPokoScreen)
{
	P2DScreen__Mgr__update(totalPokoScreen);
	if (nodemo == 0){
		return;
	}
	float* positions = totalPokoScreen[0x15c / 4];
	uint32 broc_j2dprint[0x64 / 4];
	InitJ2dPrint(broc_j2dprint);

	//J2DPrint__print(broc_j2dprint, positions[0xd4 / 4] - ((strlen(treasureName) - 1) * 14), positions[0xd8 / 4] + 30, treasureName);
}

typedef int(*func)(void);

int actOnyon_InteractSuckDone_Redirect(uint32** treasure)
{
	func getKind = treasure[0][0x1f4 / 4];
	int kind = getKind();

	if (kind >= 3)
	{
		// make the treasure gague do shutdown process if all treasures collected
		if (Radar__Mgr__getNumOtakaraItems() == 1) {
			uint32****** t = GAME2DMGR;
			t = t[0x18 / 4];
			t = t[0x1c / 4];
			t = t[0x218 / 4];
			t = t[0x10 / 4];
			t = t[0x3c / 4];
			(*(short*)(t + 0x6c / 4)) = 0;
		}
	}
	treasure = treasure[0x35c / 4];
	int index = (*(short*)(treasure + 0x258 / 4));
	if (kind == 4) {
		// edit this for proper treasure names
		treasureName = explorerTreasures[index];
	}
	else if (kind == 3) {
		// edit this for proper treasure names
		//treasureName = treasures[index];
	}
	else
		treasureName = "";

	return kind;
}

int checkpatmode(int dead)
{
	if (dead != 0)
		return 0;
	if (p1sel != 45 && p1sel != 18 && p1sel != 33 && p1sel != 20)
		return 0;
	if (bigmode == 0)//first person
		return 0;

	return 1;
}

void empressRollForceStop()
{
	static int slams;
	slams++;

	if (slams < 3)
		r0 = 1;
	else
	{
		slams = 0;
		r0 = 0;
	}

	__asm("cmpwi 0, 0x0");
}

void getdead(int count)
{
	dead = count;
}

void getalive(int count)
{
	alive = count;
}

int setEnemyHeap()//bl at 0x801a184c
{
	BecomeCurrentHeap(MEM1);
	return MEM1;
}

void SoundHeap()
{
	BecomeCurrentHeap(MEM1);
}

int loadCaster()
{
	BecomeCurrentHeap(*(int*)(SYSTEM + 0x38));
	return r30;
}