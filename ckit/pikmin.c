#include "pikmin.h"

char released = 1;
char released2 = 1;
char released3 = 1;
char released4 = 1;
char time = 0;
char drawpiki = 0;
char play = 0;
char inresult = 0;
char widescreen = 0;
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

double p2sin(double dontcare);
double p2cos(double dontcare);

const char max_option = 11;
const char characters = 60;
const char characters_per_row = 12;

char* treasures[188] = { [0 ... 187] = 0 };

char* explorerTreasures[13] = { [0 ... 12] = 0 };

char* navitexDispname[60] = { [0 ... 47] = 0 };

char* naviname[] = { "orima", "loozy", "shacho", "wife", "alph", "brittany", "charlie", "pod", "purple", "pikpik", "bulbmin", "bread",
					 "pikmar", "duck", "mario", "luigi", "yoshi2", "toad", "waluigi", "knuckle", "bigcat", "pacman", "chunky", "raymond",
					 "hatkid", "rayman", "peppino", "penguin", "spongebob", "jenkins", "mike", "perry", "strongbad", "kermit", "bart", "stewie",
					 "moyai", "rin", "gumi", "bhacho",  "vaporeon", "spraymar", "nerdu", "quote", "meeo", "pat", "shake", "mandm",
					 "sleepy", "frog", "fiend", "morshu", "jeepers", "raz", "nickolox", "parappa", "wario", "person", "orima", "orima" };

char onionmode = 0;
char player = 0;
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
						"Play in Widescreen!",
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
char p3sel = 2;
char p4sel = 3;
int* font;
char paused = 0;
char first = 0;
char secretmode = 0;
char isUnderground = 0;

uint32* pad1;
uint32* pad2;
uint32* pad3;
uint32* pad4;
int treasureCount, birthedTekiCount;
uint32 test;

uint32* j2dprint = 0;
uint32* j2dprint_green = 0;
uint32* j2dprint_yellow = 0;
uint32* j2dprint_red = 0;
void P2JME__Mgr__setupFont()
{
	__asm("stw 3, 0x18(29)");
	create2D();
}

void onDraw2D(uint32* Graphics)
{
	Game__BaseGameSection__draw2D(Graphics);

//	draw2D(Graphics);
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

	j2dprint_green = (uint32*)__nwa(0x64);
	J2DPrint____ct_FFF_TTTT(j2dprint_green, font, -0.5, -0.5, &color3, &color2, &color2, &color2);
	*(float*)(j2dprint_green + 0x50 / 4) = 22.0;
	*(float*)(j2dprint_green + 0x54 / 4) = 20.0;

	j2dprint_yellow = (uint32*)__nwa(0x64);
	J2DPrint____ct_FFF_TTTT(j2dprint_yellow, font, -0.5, -0.5, &color4, &color2, &color2, &color2);
	*(float*)(j2dprint_yellow + 0x50 / 4) = 22.0;
	*(float*)(j2dprint_yellow + 0x54 / 4) = 20.0;

	j2dprint_red = (uint32*)__nwa(0x64);
	J2DPrint____ct_FFF_TTTT(j2dprint_red, font, -0.5, -0.5, &color5, &color2, &color2, &color2);
	*(float*)(j2dprint_red + 0x50 / 4) = 22.0;
	*(float*)(j2dprint_red + 0x54 / 4) = 20.0;

	uint32* texdata = JKRDvdRipper__loadToMainRAM("background.bti", (unsigned char*)0x0, 0, 0, (JKRHeap*)0x0, 1, 0, 0, 0);
	if (texdata == 0)
		JUTException__panic_f("load.c", 0x7c, "no bg tex \n");

	j2dpic = (uint32*)__nwa(0x1A8);
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

	pad1 = ct_Controller(__nwa(8), 0); // make controller 3
	//pad2 = ct_Controller((uint32*)__nwa(0xb0), 1); // make controller 3
	//pad3 = ct_Controller((uint32*)__nwa(0xb0), 2); // make controller 3
	//pad4 = ct_Controller((uint32*)__nwa(0xb0), 3); // make controller 3

	//*(float*)0x805182AC = 1.3f;
	//*(float*)0x8051b73c = 400.0f;//empress roll fix
	onionmode = 0;
	player = 1;
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
	p3sel = 2;
	p4sel = 3;
	time = 0;
	first = 0;
	widescreen = 0;
	drawpiki = 0;
	inselect = 0;
	enemieskilled = 0;
	factor = 0x10000000;
	entries = 0;
	giveup = false;
	nodemo = false;

	char cutscene[] = "x18_exp_pellet";
	//strcpy((char*)0x80482c40, cutscene);
	//strcpy((char*)0x80482c28, cutscene);
	//strcpy((char*)0x80482c14, cutscene);

	//*(float*)(0x8051A01c) = 500.0f;// red onyon cutscene

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
		treasures[i] = string;
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

void enableCounter()
{
	drawtotals = 1;
	paused = 0;
}

void disableCounter()
{
	drawtotals = 0;
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

int p3pikis, p4pikis;

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
	if (checkButton(pad, PRESS_DR) || checkStick(pad, ANALOG_RIGHT))
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
/*
void getPikiCount(void)//bl from 0x801461e4
{
	__asm("lwz 4, 0xc8(3)");

	if(r29 == 2)
	p3pikis = r4;
	else if (r29 == 3)
	p4pikis = r4;
}

void draw2D(uint32* graphics)
{
	time++;

	int p2pik, p3pik, p4pik, field, follow;

	if (j2dprint && drawtotals == 1)
	{
		J2DPrint__print(j2dprint, 450.0, 18.0, "Enemies: %i", birthedTekiCount);
		J2DPrint__print(j2dprint, 430.0, 38.0, "Treasures: %i", treasureCount);

		if (player == 2)
		{
			drawPikistat(1, 155.0, 435.0);
			drawPikiIcon(1, 110.0f, 400.0f);
		}
		if (player == 3)
		{
			drawNaviLife(1, 10.0, 435.0);
			drawNaviLife(2, 320.0, 435.0);

			drawPikistat(1, 155.0, 435.0);
			drawPikistat(2, 455.0, 435.0);

			drawPikiIcon(1, 110.0f, 400.0f);
			drawPikiIcon(2, 410.0f, 400.0f);
		}
		if (player == 4)
		{
			drawNaviLife(1, 320.0, 215.0);
			drawNaviLife(2, 10.0, 435.0);
			drawNaviLife(3, 320.0, 435.0);

			drawPikistat(1, 455.0, 218.0);
			drawPikistat(2, 155.0, 435.0);
			drawPikistat(3, 455.0, 435.0);

			drawPikiIcon(1, 400.0f, 180.0f);
			drawPikiIcon(2, 90.0f, 400.0f);
			drawPikiIcon(3, 400.0f, 400.0f);
		}
	}
	if (j2dprint && paused == 1)
	{
		if (seedset == 1) test = seed;
		else sprintf(DispSeed, "Seed: 0x%08X", test);
		JUTFont__print(font, 180.0f, 430.0f, DispSeed, 0);

	}
	if (secretmode == 1 && *(uint16_t*)0x80506f48 & PRESS_L && *(uint16_t*)0x80506f48 & PRESS_R)
	{
		unleashsatan();
	}
}

void drawPikistat(int NaviID, float posX, float posY)//for drawing the number of pikmin following a particular captain
{
	int field = GameStat__getMapPikmins(-1) - GameStat__getZikatuPikmins(-1);
	int pikicount[4] = { 0, opi((int*)(0x8051224c)), p3pikis, p4pikis };

	J2DPrint__print(j2dprint, posX, posY, "%i", pikicount[NaviID]);
	J2DPrint__print(j2dprint, posX + 90.0, posY, "%i", field);
}

void drawPikiIcon(int NaviID, float xpos, float ypos)
{
	int** TIMG = 0x80513af0;

	uint32* navi = MonoObjectMgr_GameNavi__getAt(*(int*)(SDA + NAVIMGR), NaviID);
	int pik = Navi__ogGetNextThrowPiki(navi);
	//OSReport("timg %x icon %x draw %i \n", TIMG[pik], pikiicon[pik], drawpiki);

	if (TIMG[pik] && pikiicon[pik] && drawpiki)//we have a ton of failsafes here because the game crashes very easily if these arent set up right
	{
		J2DPictureEx__draw(pikiicon[pik], xpos, ypos, 0, 0, 0);
	}
}

void drawNaviLife(int NaviID, float xpos, float ypos)
{
	uint32* player = MonoObjectMgr_GameNavi__getAt(*(int*)(SDA + NAVIMGR), NaviID);
	uint32* print;
	float life = *(float*)(player + 0x2a0 / 4);

	if (life > 25.0)
		print = j2dprint_green;
	else if (life > 10.0)
		print = j2dprint_yellow;
	else
		print = j2dprint_red;

	J2DPrint__print(print, xpos, ypos, "%.0f%", life);
}

void makePikiTex(void)// branch from  0x80307978
{
	int** TIMG = 0x80513af0;// table of pikmin texture names
	int* pikitex[0x14];
	drawpiki = 1;

	for (int j = 0; j < 0x13; j++)
	{
		pikitex[j] = TIMG[j];
		pikiicon[j] = J2DPictureEx____ct(pikiicon[j], pikitex[j], 0x0);
	}
}

int onDemostart(int* this)
{
	//if(*(char**)(this + 0x28) != "s22_cv_suck_treasure" && *(char**)(this + 0x28) != "s22_cv_suck_equipment")
	drawtotals = 0;
	BeaconID = player + 9;
	return 0x38;
}

void onDemoend(void)
{
	drawtotals = 1;
}
*/
/*
void onNintendoLogo(void)
{
	//uint32* pad1 = *JUTPadList[0];
	uint32 padstat1 = *(pad1 + 6);
	if (padstat1 & PRESS_L && padstat1 & PRESS_R && secretmode == 0)
	{
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		secretmode = 1;
		writeAt(0x8014a5d0, 0x3be00003);
		OSReport("secret mode\n");
	}
}

void kanteiDone()
{
	drawpiki = 0;
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
*/
void onCaveinit(int this)
{
	uint32 padstat1 = *(pad1 + 6);
	uint32 analogstat = padstat1 >> 16;
	char dispmem1[32];
	int mem1 = *(int*)0x800000f0;
	mem1 /= 0x100000;
	rand();

	if (mem1 == 24 && 1<0)
	{
		if (play == 0)
		{
			play = 1;
			PSStart2DStream(0xc0011006);
		}

		JUTFont__print(font, 80.0f, 70.0f, "Warning!!! Memory is not increased.", 1);

		JUTFont__print(font, 80.0f, 130.0f, "You must increase Dolphins memory", 1);
		JUTFont__print(font, 80.0f, 160.0f, "size in order to play this hack.", 1);

		JUTFont__print(font, 80.0f, 220.0f, "To do this, make sure you are on", 1);
		JUTFont__print(font, 80.0f, 250.0f, "a recent developer build of Dolphin.", 1);
		JUTFont__print(font, 80.0f, 280.0f, "In Config/Advanced/Memory Override", 1);
		JUTFont__print(font, 80.0f, 310.0f, "Increase MEM1 all the way to 64MB.", 1);
	}
	else
	{
		if (play == 0)
		{
			play = 1;
			PSStart2DStream(0xc001100f);
		}
		J2DPictureEx__draw(j2dpic, 0.0f, 0.0f, 0, 0, 0);

		if (*(float*)(this + 0x70) < 1000.0f && inselect == 0)
		{

			JUTFont__print(font, 40.0f, 420.0f, description[option], 0);

			JUTFont__print(font, 140.0f, 20.0f, "Set Game Options", 0);

			sprintf(dispmem1, "Memory: %i MB", mem1);
			JUTFont__print(font, 400.0f, 20.0f, dispmem1, mem1 < 64);
			JUTFont__print(font, 400.0f, 50.0f, "Wii Version 1.0", 0);
			sprintf(DispPlayer, "Player Count: %i", player);
			JUTFont__print(font, 40.0f, 50.0f, DispPlayer, 0);

			JUTFont__print(font, 40.0f, 80.0f, "Select Characters", 0);

			JUTFont__print(font, 40.0f, 110.0f, "Onion Mode", onionmode);

			JUTFont__print(font, 40.0f, 140.0f, "200 Pikmin Limit", doublepikmin);

			JUTFont__print(font, 40.0f, 170.0f, "First Person", bigmode);

			JUTFont__print(font, 40.0f, 200.0f, "No Treasure Cutscene", nodemo);

			JUTFont__print(font, 40.0f, 230.0f, "Use Extra Units", twofiftyone);

			JUTFont__print(font, 40.0f, 260.0f, "Ultra-Randomizer", randomize);

			JUTFont__print(font, 40.0f, 290.0f, "Widescreen", widescreen);

			if (seedset == 1)
			{
				sprintf(DispSeed, "Seed: 0x%08X", seed);
				JUTFont__print(font, 40.0f, 320.0f, DispSeed, 1, 0);
			}
			else
				JUTFont__print(font, 40.0f, 320.0f, "Seed: ", 0, 0);

			sprintf(DispSong, "Song: %s", cndname[cndindex]);
			JUTFont__print(font, 40.0f, 350.0f, DispSong, 0, 0);

			JUTFont__print(font, 40.0f, 380.0f, "Begin!", 0, 0);

			if (!PressAnalog(pad1) && !checkButton(pad1, PRESS_A) && !checkButton(pad1, PRESS_B) && !checkButton(pad1, PRESS_START))
				released = 1;

			if(checkButton(pad1, PRESS_A))
			{
			//if (PressDown(pad1) && released  && enteringseed == 0) {
				option++;
			//	released = 0;
			}

			if (PressUp(pad1) && released  && enteringseed == 0) {
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
					if (player < 4)
						player++;

					else
						player = 1;

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
					//setFirstPerson();
					break;
				}
				case 5://FirstPerson
				{
					//setNoDemo();
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
				case 8:// widescreen
				{
					if (widescreen == 0) {
						widescreen = 1;
					}
					else {
						widescreen = 0;
					}
					break;
				}
				case 9:// seed set
				{
					seedset = 0;
					enteringseed = 1;
					break;
				}
				case 10:// song select
				{
					cndindex++;
					if (cndindex > 31)
						cndindex = 0;
					break;
				}
				case 11:// begin
				{
					//initgame();
					*(float*)(this + 0x70) = 1000.0f;
					break;
				}
				}
				released = 0;
				//	PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x180E, 1);
			}
			if (checkButton(pad1, PRESS_START) && !enteringseed && released)
			{
				//initgame();
				*(float*)(this + 0x70) = 1000.0f;
				released = 0;
				//	PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x180E, 1);
			}
			JUTFont__print(font, 10.0f, (float)((option * 30.0) + 50.0), "->", 0, 0);
		}
	}
	if (enteringseed == 1)
			EntersetSeed(this);
	if (option == 10)
			changeCND();
	if (inselect == 1 && *(float*)(this + 0x70) < 1000.0f)
	CharacterSelect(this);
}
/*
void initgame()
{
	if (randomize == 1)
	{
		OSReport("set random layout \n");
		writeAt(0x8024c1fc, 0x2c185000);
	}
	if (player == 2)
	{
		strcpy((char*)0x8048ec64, "res_cav2.szs");
		waterboxfix();
	}
	else if (player == 3)
	{
		strcpy((char*)0x8048ec64, "res_cav3.szs");
		waterboxfix();
		set3navis();
		fixviewport3p();
	}
	else if (player == 4)
	{
		strcpy((char*)0x8048ec64, "res_cav4.szs");
		waterboxfix();
		fixviewport4p();
		set4navis();
	}
	if (doublepikmin == 1)
	{
		writeAt(0x8015edd4, 0x38c000c8);
		writeAt(0x80150be8, 0x388000c8);
		writeAt(0x8013f864, 0x388000c8);
		writeAt(0x80195720, 0x2c0000c8);
		writeAt(0x801dae08, 0x2c0000c8);
		writeAt(0x8015e7d8, 0x2c0000c8);
		writeAt(0x8015e810, 0x2c0000c8);
		writeAt(0x80476ea0, 0x3a0000c8);
	}
	if (nodemo)
	{
		writeAt(0x801a55b4, 0x428000e0);
		writeAt(0x801a56b0, 0x428000f4);
	}
	Pikmin2ARAM__Mgr__loadenemy(*(int*)0x80516240);
}
*/
void changeCND()
{
	if (PressRight(pad1) && released)
	{
		released = 0;
		cndindex++;
		//PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
	}
	if (PressLeft(pad1) && released)
	{
		released = 0;
		cndindex--;
		//PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
	}
	if (cndindex > 31)
		cndindex = 0;
	if (cndindex < 0)
		cndindex = 31;
}
/*
void storeCaveSeed(void)
{
	if (seedset == 1)
	*(uint32*)(SDA - 0x7DE0) = seed;

	else
	test = *(uint32*)(SDA - 0x7DE0);

	OSReport("Seed: %08X! \n", *(uint32*)(SDA - 0x7DE0));

	__asm("li 26, 0x0");
}
void onCaveLoading()
{
	if (seedset == 1) sprintf(DispSeed, "Seed: 0x%08X", seed);
	else sprintf(DispSeed, "Seed: 0x%08X", test);
	JUTFont__print(font, 10.0f, 40.0f, DispSeed, 0);
	*(int *)(*(int *)(*(int *)(SDA - 0x6c18) + 0x40) + 0x218) = 2;
}

// branch in here from 0x8012f3c0
int addTekiBirthCount(int* unk, int* unk2)
{
	int tekiId = unk2[0x28 / 4];

	if (tekiId == -1)
	return tekiId;

	if ((tekiId < 3 || tekiId > 8) && tekiId != 83 && tekiId != 31 && (tekiId < 46 || tekiId > 52) && (tekiId < 85 || tekiId > 92) && tekiId != 83 && tekiId != 74 && tekiId != 77)
	birthedTekiCount++;
	return tekiId;
}

// branch in here from 0x80101f0c
int subTekiBirthCount(int * unk)
{
	unk = unk[0];
	unk = unk[0x258 / 4];

	getTekiId = unk;
	int tekiId = getTekiId();

	if ((tekiId < 3 || tekiId > 8) && tekiId != 31 && tekiId != 74 && tekiId != 68 && tekiId != 77 && birthedTekiCount > 0)
	{
		birthedTekiCount--;
		OSReport("Teki dead %i\n", birthedTekiCount);
	}
	return 0;
}

void onKill_Hiba(void)
{
	OSReport("Hiba dead %i\n", birthedTekiCount);
	birthedTekiCount--;
}

void onPauseMenu()
{
	paused = 1;
}

void onOtakaraborn(void)
{
	treasureCount++;
}

void getFirstGlobe(void)
{
	float* pikiparms = (*(uint32**)(SDA + PIKIMGR));
	pikiparms += 0x24; // 0x90

	pikiparms[0x440] += 0.3;//increase carry speed
	pikiparms[0x44a] += 0.3;
}

void getSecondGlobe(void)
{
	writeAt(0x8024545c, 0x428000c4);
}

void getfist()
{
	if(r31 == 0)
	writeAt(0x8017eff4, 0x60000000);

	r0 = 1;
}

void onOtakaraCollected(void)
{
	treasureCount--;
	r3 = 0;
}
*/
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

	int* rsUnit = (*(int**)(SDA - 27000))[13];
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

			if (spawns && colorID < maxcolors &&
				++roomNum == (colorID + 1) * roomInterval) {

				int onyon = ((int(*)(int, int, int))0x8017aebc)(r3, 0, 2 - colorID++);
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

				OSReport("Onion spawned at: %.2f %.2f %.2f\n", rx + *(float*)& pSpawns[0][7], *(float*)& pSpawns[0][8], rz + *(float*)& pSpawns[0][9]);
			}
		}
		room = *(int*)(room + 4);
	}
	return ((int(*)(int, int, int))0x8017aebc)(r3, 1, 0);
}
/*
void OnyonCutscene()
{
	onyonid++;
	if (onyonid > 2)
	onyonid = 0;

	r4 = onyonid;
}

#pragma ident --defsym draw3DAll=0x802398b8

void gbgsdmd(int r3, int graphics)
{
	draw3DAll(r3, graphics);
	uint32* viewport;

	if (player > 2)
	{
		//((void(*)())(*(int*)(r3 + 0x148) + 0x14))((int *)(r3 + 0x114), graphics);

		((void(*)()) *(int*)(*(int*)r3 + 0x114))(r3, graphics, 2);//set particles

		viewport = Graphics__getViewport(graphics, 2);

		if (viewport != 0)
		{
			*(int*)(graphics + 0x25c) = viewport;
			BaseGameSection__DirectDrawPost(r3, graphics, viewport);
		}
	}

	if (player > 3)
	{
		//((void(*)())(*(int*)(r3 + 0x148) + 0x14))((int *)(r3 + 0x114), graphics);

		((void(*)()) *(int*)(*(int*)r3 + 0x114))(r3, graphics, 3);//set particles

		viewport = Graphics__getViewport(graphics, 3);

		if (viewport != 0)
		{
			*(int*)(graphics + 0x25c) = viewport;
			BaseGameSection__DirectDrawPost(r3, graphics, viewport);
		}
	}
}

int onP2TreasureRadar(int* this, float* start, float* finish, float* pDist, float radius)
{
	uint32* orima = MonoObjectMgr_GameNavi__getAt(*(int*)(SDA + NAVIMGR), 0);
	uint32* LOOZY = MonoObjectMgr_GameNavi__getAt(*(int*)(SDA + NAVIMGR), 1);
	uint32* fatman = MonoObjectMgr_GameNavi__getAt(*(int*)(SDA + NAVIMGR), 2);
	uint32* wife = MonoObjectMgr_GameNavi__getAt(*(int*)(SDA + NAVIMGR), 3);

	if (player == 1)
		orima = getActiveNavi(*(int*)(SDA + NAVIMGR));
	int res = Radar__Mgr__calcNearestTreasure(this, orima + 0x83, finish, pDist, radius);

	float dist2 = 10000.0f;
	float dist3 = 10000.0f;
	float dist4 = 10000.0f;

	float finish2[3];
	float finish3[3];
	float finish4[3];
	int res2, res3, res4;

	if (LOOZY != 0 && player > 1)
		res2 = Radar__Mgr__calcNearestTreasure(this, LOOZY + 0x83, finish, &dist2, radius);

	if (fatman != 0 && player > 2)
		res3 = Radar__Mgr__calcNearestTreasure(this, fatman + 0x83, finish, &dist3, radius);

	if (wife != 0 && player > 3)
		res4 = Radar__Mgr__calcNearestTreasure(this, wife + 0x83, finish, &dist4, radius);

	if (player > 1 && dist2 < *pDist && res2 == 2)
	{
		*pDist = dist2;
		memcpy(finish, finish2, 3 * 4);
		res = res2;
	}
	if (player > 2 && dist3 < *pDist && dist3 < dist2 && res3 == 2)
	{
		*pDist = dist3;
		memcpy(finish, finish3, 3 * 4);
		res = res3;
	}
	if (player > 3 && dist4 < *pDist && dist4 < dist2 && dist4 < dist3 && res4 == 2)
	{
		*pDist = dist4;
		memcpy(finish, finish4, 3 * 4);
		res = res4;
	}
	return res;
}

void unlockMenuMapParts(uint32* unkSdaValue, uint32* olimarPosition)
{
	radarMapPartsOpen(unkSdaValue, olimarPosition);
	for (int i = 1; i < player; i++)
	{
		uint32* navi = MonoObjectMgr_GameNavi__getAt((*(uint32**)(SDA + NAVIMGR)), i);
		float naviPosition[0xc / 4];
		Game__Navi__getPosition(naviPosition, navi);
		radarMapPartsOpen(unkSdaValue, naviPosition);
	}
}

void NewinitViewports(uint32* this, uint32* graphics)
{
	for (int i = 0; i < 0x13; i++)
	{
		pikiicon[i] = (uint32*)__nwa(0x198);
	}
	drawtotals = 0;

	//clearDeadNavi(*(int*)(SDA + NAVIMGR));
	BeaconID = 0;

	uint32 viewport;
	uint32* viewportalloc;
	uint32* cameraalloc;

	uint32* alloc = __nwa(0x1c);
	if (player > 2)
		MultiPlayer(alloc, graphics);
	else
		HorizonalSplitter_ct(alloc, graphics);
	this[0x4E] = alloc;

	BaseGameSection__setSplitter(this, 0);

	viewport = Graphics__getViewport(graphics, 0);
	*(uint32*)(viewport + 0x44) = this[0x49];
	Viewport__updateCameraAspect(viewport);
	ShadowMgr__setViewport(*(uint32**)(SDA + -0x6980), viewport, 0);
	CameraMgr__setViewport(*(uint32**)(SDA - 0x6960), viewport, 0);

	viewport = Graphics__getViewport(graphics, 1);
	*(uint32*)(viewport + 0x44) = this[0x4A];
	Viewport__updateCameraAspect(viewport);
	ShadowMgr__setViewport(*(uint32**)(SDA + -0x6980), viewport, 1);
	CameraMgr__setViewport(*(uint32**)(SDA - 0x6960), viewport, 1);

	for (int i = 2; i < player; i++)
	{
		viewport = Graphics__getViewport(graphics, i);
		*(uint32*)(viewport + 0x44) = ct_PlayCamera(JSystem__operator_new(0x254), MonoObjectMgr_GameNavi__getAt(*(int*)(SDA + NAVIMGR), i));
		Viewport__updateCameraAspect(viewport);
		CameraMgr__setViewport(*(uint32**)(SDA - 0x6960), viewport, i);
		ShadowMgr__setViewport(*(uint32**)(SDA + -0x6980), viewport, i);
	}

	CameraMgr__init(*(uint32**)(SDA - 0x6960));

	cameraalloc = __nwa(0x1b0);
	LookAtCamera(cameraalloc);
	*cameraalloc = 0x804c15d4;
	this[0x5B] = cameraalloc;

	viewportalloc = __nwa(0x84);// this stuff is all for the treasure get screen
	Viewport_ct(viewportalloc);

	this[0x56] = viewportalloc;
	*((short *)this[0x56] + 0x18 / 2) = 2;

	uint32* viewportObj = this[0x56];
	*(uint32*)(viewportObj + 0x44 / 4) = this[0x5B];
	Viewport__updateCameraAspect(viewportObj);
}

void MultiPlayer(uint32* this, uint32* graphics)
{
	*this = 0x804ebce4;
	this[5] = graphics;
	int rmode = System__getRenderModeObj();
	*(float*)& this[3] = (int) * (short*)(rmode + 4);
	*(float*)& this[4] = (int) * (short*)(rmode + 6);

	Graphics__AllocateViewports(graphics, player);

	if (player == 3)
	{
		newViewport__setRect(graphics, 0.0f, 0.0f, 640.0f, 230.0f);//		p1
		newViewport__setRect(graphics, 0.0f, 225.0f, 300.0f, 445.0f);//		p2
		newViewport__setRect(graphics, 300.0f, 230.0f, 640.0f, 450.0f);//	p3
	}
	if (player == 4)
	{
		newViewport__setRect(graphics, 0.0f, 0.0f, 300.0f, 230.0f);//		p1
		newViewport__setRect(graphics, 300.0f, -20.0f, 640.0f, 224.0f);//	p2
		newViewport__setRect(graphics, 0.0f, 230.0f, 300.0f, 450.0f);//		p3
		newViewport__setRect(graphics, 300.0f, 230.0f, 640.0f, 450.0f);//	p4
	}
}

void newViewport__setRect(uint32* graphics, float x1, float y1, float x2, float y2)
{
	struct Rect rect;
	uint32* vp = (uint32*)operator_new2(0x58);
	Viewport_ct(vp);

	rect.x1 = x1;
	rect.y1 = y1;
	rect.x2 = x2;
	rect.y2 = y2;

	Viewport__setRect(vp, &rect);
	Graphics__addViewport(graphics, vp);
}
*/
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
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
	}

	if (PressLeft(pad1) && released && entries > 0)
	{
		released = 0;
		factor *= 0x10;
		entries--;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
	}
	if (padstat1 & PRESS_B && released)
	{
		released = 0;
		entries = 0;
		seed = 0;
		factor = 0x10000000;
		enteringseed = 0;
		seedset = 0;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1807, 1);
	}
	if ((padstat1 & PRESS_A) && released)
	{
		released = 0;
		entries = 8;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
	}

	if (entries == 8)
	{
		entries = 0;
		factor = 0x10000000;
		enteringseed = 0;
		seedset = 1;
	}

	sprintf(DispSeed, "0x%08X", seed);
	JUTFont__print(font, 110.0f, 320.0f, DispSeed, 2, 2 + entries);
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
/*
void changeCaveSong()
{
	char* cnd = cndfile[cndindex];
	r4 = cnd;
}

void waterboxfix()
{
	OSReport("fix water\n");
	writeAt(0x801af408, 0x38000001);
	writeAt(0x801af488, 0x38000001);
	writeAt(0x801af4ec, 0x38000001);
	writeAt(0x801af578, 0x38000001);
	writeAt(0x801ae870, 0x38000001);
	writeAt(0x801ae890, 0x38000001);
	writeAt(0x801ae854, 0x60000000);
	writeAt(0x801ae860, 0x60000000);
	writeAt(0x801ae868, 0x60000000);
	writeAt(0x801ae874, 0x60000000);
	writeAt(0x801ae8fc, 0x60000000);
	writeAt(0x801ae90c, 0x60000000);

	writeAt(0x80187878, 0x428001a0);
	writeAt(0x8017ed34, 0x428001f0);
	writeAt(0x80184370, 0x4280018c);
	writeAt(0x80385d08, 0x60000000);
	writeAt(0x80385d14, 0x60000000);

	writeAt(0x8014d908, 0x3be00002);

}

void fixviewport3p()
{
	OSReport("fix cam 3p\n");
	writeAt(0x8043e3b8, 0x38c00003);
	writeAt(0x802509cc, 0x3860000c);
	writeAt(0x802509d8, 0x3860000c);
	writeAt(0x802509e4, 0x3860000c);
	writeAt(0x80150958, 0x38800003);
	writeAt(0x80251ff0, 0x2c1d0003);
	writeAt(0x802520fc, 0x2c1d0003);
	writeAt(0x8023f8fc, 0x2c1f0004);

	//writeAt(0x80469e14, 0x4280000c);
}
void fixviewport4p()
{
	OSReport("fix cam 4p\n");
	writeAt(0x8043e3b8, 0x38c00004);
	writeAt(0x802509cc, 0x38600010);
	writeAt(0x802509d8, 0x38600010);
	writeAt(0x802509e4, 0x38600010);
	writeAt(0x80150958, 0x38800004);
	writeAt(0x80251ff0, 0x2c1d0004);
	writeAt(0x802520fc, 0x2c1d0004);
	writeAt(0x8023f8fc, 0x2c1f0005);

	//writeAt(0x80469e14, 0x4280000c); //obj calc2p
	//writeAt(0x8042bd10, 0x4e800020);// disable lightmgr
	//writeAt(0x801d79cc, 0x2c1e0004);
}
*/
void writeAt(uint32* address, uint32 value)
{
	address[0] = value;
	//__flush_cache(address, 4);
}

void CharacterSelect(int this)
{
	uint32 padstat1 = *(pad1 + 6);
	uint32 analogstat = padstat1 >> 16;
	JUTFont__print(font, 150.0f, 20.0f, "Choose Your Fighter!", 1, 0);
	JUTFont__print(font, 10.0f, 20.0f, "<- B", 1, 0);

	if (!PressAnalog(pad1) && !(padstat1 & PRESS_A) && !(padstat1 & PRESS_B) && !(padstat1 & PRESS_START))
		released = 1;

	drawcharactermenu();

	drawp1select();

	if(player > 1)
	drawp2select();

	if (player > 2)
		drawp3select();

	if (player == 4)
		drawp4select();

	if (padstat1 & PRESS_B && released)
	{
		released = 0;
		inselect = 0;
	}
	
	if (padstat1 & PRESS_START && released)
	{
		//initgame();
		*(float*)(this + 0x70) = 1000.0f;
		released = 0;
		//PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x180E, 1);
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
	//if (!PressAnalog(pad1) && !(padstat))
	//	released = 1;
	if (PressLeft(pad1) && released && p1sel > 0)
	{
		p1sel--;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		released = 0;
	}

	if (PressUp(pad1) && released && p1sel >= characters_per_row)
	{
		p1sel -= characters_per_row;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		released = 0;
	}

	if (PressDown(pad1) && released && p1sel < (characters - characters_per_row))
	{
		p1sel += characters_per_row;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		released = 0;
	}

	if (PressRight(pad1) && released && p1sel < characters - 1)
	{
		p1sel++;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		released = 0;
	}

	if (player == 1)
		JUTFont__print(font, 10.0f, 320.0f, "Captain 1", 0, 0);
	else
		JUTFont__print(font, 10.0f, 320.0f, "Player 1", 0, 0);

	J2DPictureEx__draw(naviicon[p1sel], 40.0f, 330.0f, 0, 0, 0);
	JUTFont__print(font, 20.0f, 360.0f, "<", 0, 0);
	JUTFont__print(font, 90.0f, 360.0f, ">", 0, 0);
	JUTFont__print(font, 20.0f, 400.0f, navitexDispname[p1sel], 0, 0);
}

void drawp2select()
{
	if (!PressAnalog(pad2))
		released2 = 1;

	if (PressLeft(pad2) && released2 && p2sel > 0)
	{
		p2sel--;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		released2 = 0;
	}

	if (PressRight(pad2) && released2 && p2sel < characters - 1)
	{
		p2sel++;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		released2 = 0;
	}

	if (PressUp(pad2) && released2 && p2sel >= characters_per_row)
	{
		p2sel -= characters_per_row;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		released2 = 0;
	}

	if (PressDown(pad2) && released2 && p2sel < (characters - characters_per_row))
	{
		p2sel += characters_per_row;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		released2 = 0;
	}

	if (player == 1)
		JUTFont__print(font, 160.0f, 320.0f, "Captain 2", 0, 0);
	else
		JUTFont__print(font, 160.0f, 320.0f, "Player 2", 0, 0);

	J2DPictureEx__draw(naviicon[p2sel], 190.0f, 330.0f, 0, 0, 0);
	JUTFont__print(font, 170.0f, 360.0f, "<", 0, 0);
	JUTFont__print(font, 240.0f, 360.0f, ">", 0, 0);
	JUTFont__print(font, 170.0f, 400.0f, navitexDispname[p2sel], 0, 0);
}

void drawp3select()
{
	if (!PressAnalog(pad3))
		released3 = 1;

	if (PressLeft(pad3) && released3 && p3sel > 0) {
		p3sel--;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		released3 = 0;
	}

	if (PressRight(pad3) && released3 && p3sel < characters - 1) {
		p3sel++;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		released3 = 0;
	}

	if (PressUp(pad3) && released3 && p3sel >= characters_per_row)
	{
		p3sel -= characters_per_row;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		released3 = 0;
	}

	if (PressDown(pad3) && released3 && p3sel < (characters - characters_per_row))
	{
		p3sel += characters_per_row;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		released3 = 0;
	}

	JUTFont__print(font, 310.0f, 320.0f, "Player 3", 0, 0);
	J2DPictureEx__draw(naviicon[p3sel], 340.0f, 330.0f, 0, 0, 0);
	JUTFont__print(font, 320.0f, 360.0f, "<", 0, 0);
	JUTFont__print(font, 390.0f, 360.0f, ">", 0, 0);
	JUTFont__print(font, 320.0f, 400.0f, navitexDispname[p3sel], 0, 0);
}

void drawp4select()
{
	if (!PressAnalog(pad4))
		released4 = 1;

	if (PressLeft(pad4) && released4 && p4sel > 0) {
		p4sel--;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		released4 = 0;
	}

	if (PressRight(pad4) && released4 && p4sel < characters - 1) {
		p4sel++;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		released4 = 0;
	}

	if (PressUp(pad4) && released4 && p4sel >= characters_per_row)
	{
		p4sel -= characters_per_row;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		released4 = 0;
	}

	if (PressDown(pad4) && released4 && p4sel < (characters - characters_per_row))
	{
		p4sel += characters_per_row;
		PSSystem__SysIF__playSystemSe((SysIF *)(SDA + SFX), 0x1806, 1);
		released4 = 0;
	}

	JUTFont__print(font, 460.0f, 320.0f, "Player 4", 0, 0);
	J2DPictureEx__draw(naviicon[p4sel], 490.0f, 330.0f, 0, 0, 0);
	JUTFont__print(font, 470.0f, 360.0f, "<", 0, 0);
	JUTFont__print(font, 540.0f, 360.0f, ">", 0, 0);
	JUTFont__print(font, 470.0f, 400.0f, navitexDispname[p4sel], 0, 0);
}

/*
void set3navis()//fixes various things for captain number
{
	OSReport("set 3 navis \n");
	writeAt(0x80150988, 0x38800003);// init 3 navis
	writeAt(0x8033f5a8, 0x60000000);// fix cstick crash
	writeAt(0x801402cc, 0x3be00000);// material anim
	writeAt(0x801454c0, 0x38800000);// fix disband
	writeAt(0x801454b8, 0x4800006c);// ^
	writeAt(0x801459c4, 0x38800000);// ^
	writeAt(0x8018111c, 0x38800000);// captain punching?
	writeAt(0x8017ed68, 0x38800000);// navi following
	writeAt(0x8022ba80, 0x60000000);// navi die (VSGame?)
	writeAt(0x80143ad8, 0x4e800020);
	writeAt(0x8033fd74, 0x48000020);
	writeAt(0x80219958, 0x2c000003);// naviDown gameend
	writeAt(0x80140958, 0x38800000);// fix plucking
	writeAt(0x8030fd5c, 0x2c1a0004);//radar map icon
	writeAt(0x802417dc, 0x38600001);//shadow type

}

void set4navis()//fixes various things for captain number
{
	OSReport("set 4 navis \n");
	writeAt(0x80150988, 0x38800004);// init 4 navis
	writeAt(0x8033f5a8, 0x60000000);// fix cstick crash
	writeAt(0x801402cc, 0x3be00000);// material anim
	writeAt(0x801454c0, 0x38800000);// fix disband
	writeAt(0x801454b8, 0x4800006c);// ^
	writeAt(0x801459c4, 0x38800000);// ^
	writeAt(0x8018111c, 0x38800000);// captain punching?
	writeAt(0x8017ed68, 0x38800000);// navi following
	writeAt(0x8022ba80, 0x60000000);// navi die (VSGame?)
	writeAt(0x80219958, 0x2c000004);// naviDown gameend
	writeAt(0x80140958, 0x38800000);// fix plucking
	writeAt(0x8030fd5c, 0x2c1a0005);//radar map icon
	writeAt(0x802417dc, 0x38600001);//shadow type
}

void giveNavisControllers(uint32* navi, uint32* createSectionInfo)//gives each navi a controller and camera
{
	int NaviID = (*(short*)(navi + 0x2dc / 4));
	int control, playcam;
	int graphics = (*(int*)(createSectionInfo + 0xb));

	if (NaviID >= 2 && NaviID < 4)
	{
		control = ct_Controller((uint32*)__nwa(0xb0), NaviID);

		int viewport = Graphics__getViewport(graphics, NaviID);
		playcam = *(uint32*)(viewport + 0x44);
	}
	else
	{
		control = createSectionInfo[0x130 / 4];
		playcam = createSectionInfo[0x128 / 4];
	}

	navi[0x278 / 4] = control;
	navi[0x27c / 4] = control;

	navi[0x280 / 4] = playcam;
	navi[0x284 / 4] = playcam;
}

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

uint32* navi1modeldata;
uint32* navi2modeldata;
uint32* navi3modeldata;
uint32* navi4modeldata;
uint32* createModel(uint32 this, int NaviID)// apply loaded captain models
{
	uint32* load = JSystem__operator_new(0x14);

	if (load && NaviID == 0)
	SysShape__Model(load, navi1modeldata, 0, 2);

	else if (load && NaviID == 1)
	SysShape__Model(load, navi2modeldata, 0, 2);

	else if (load && NaviID == 2 && player > 2)
	SysShape__Model(load, navi3modeldata, 0, 2);

	else if (load && NaviID == 3 && player > 3)
	SysShape__Model(load, navi4modeldata, 0, 2);

	//OSReport("loaded navi %i \n", (int)(NaviID + 1));
	return load;
}

void loadNaviModel(uint32* this)//code to load man captain models
{
	uint32 *navi2;
	uint32 *navi3;
	uint32 *navi4;
	char path[32];

	//int* archive = (int *)JKRArchive__mount((char*)0x8047de94, 1, *(char **)(*(int *)(SDA + SYSTEM) + 0x38), 1);

	sprintf(path, "player/%s/model.bmd", naviname[p2sel]);
	navi2 = JKRDvdRipper__loadToMainRAM(path, (unsigned char*)0x0, 0, 0, (JKRHeap*)0x0, 1, 0, 0, 0);

	//navi2 = ((uint32(*)(int*, char*))(*(uint32*)(*archive + 0x14)))(archive, path);
	if(navi2 == 0)
		JUTException__panic_f("load.c", 0x7c, "no model %s \n", path);

	navi2modeldata = J3DModelLoaderDataBase__load(navi2, 0x20000030);

	if (player > 2)
	{
		sprintf(path, "player/%s/model.bmd", naviname[p3sel]);
		navi3 = JKRDvdRipper__loadToMainRAM(path, (unsigned char*)0x0, 0, 0, (JKRHeap*)0x0, 1, 0, 0, 0);

		if (navi3 == 0)
			JUTException__panic_f("load.c", 0x7c, "no model %s \n", path);

		navi3modeldata = J3DModelLoaderDataBase__load(navi3, 0x20000030);
	}

	if (player > 3)
	{
		sprintf(path, "player/%s/model.bmd", naviname[p4sel]);
		navi4 = JKRDvdRipper__loadToMainRAM(path, (unsigned char*)0x0, 0, 0, (JKRHeap*)0x0, 1, 0, 0, 0);

		if (navi4 == 0)
			JUTException__panic_f("load.c", 0x7c, "no model %s \n", path);

		navi4modeldata = J3DModelLoaderDataBase__load(navi4, 0x20000030);
	}
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

void setShadowDraw(int this, int graphics, int vpID)// no idea why this does anything
{
	//OSReport("cylinder id %i \n", *(int*)(this + 0x40));
	*(int*)(this + 0x40) = 1;
	//*(int*)(this + 0x44) = 1;
	ShadowMgr__draw(this, graphics, vpID);
}

void shadowCylinder(int this)//something about fixing shadows for 3/4p
{
	int vp = 0;

	if (player > 2)
	{
		vp = operator_new2(0x20);
		*(int*)(*(int*)(this + 0x58) + 8) = vp;
	}

	if (player > 3)
	{
		vp = operator_new2(0x20);
		*(int*)(*(int*)(this + 0x58) + 0xC) = vp;
	}
}

int showNaviLife(int** this)//disable game showing louies life bar in 3/4p, basically by making it think louie is dead
{
	if (this[0x24] == 1 && player > 2)
	{
		this[7][0] = 0.0f;
	}
	return checkMovieActive(this);
}

void openOnion(int this)//fix other players moving in onion menu
{
	GameSystem__setPause(*(int*)(SDA + GAMESYS), 1, "lol", 3);
}

void closeOnion(int this)//fix other players moving in onion menu
{
	GameSystem__setPause(*(int*)(SDA + GAMESYS), 0, "lol", 3);
}

int PadInput()//which controller to use
{
	if (player == 1)
		return pad1;
	uint32 padstat1 = *(pad1 + 6);
	uint32 padstat2 = *(pad2 + 6);
	uint32 padstat3 = *(pad3 + 6);

	uint32 analogstat1 = padstat1 >> 16;
	uint32 analogstat2 = padstat2 >> 16;
	uint32 analogstat3 = padstat3 >> 16;

	if (CheckPress(padstat1, analogstat1))
		return pad1;
	else if (CheckPress(padstat2, analogstat2))
		return pad2;
	else if (CheckPress(padstat3, analogstat3))
		return pad3;
	else
		return pad4;
}

void PadInput_r4()//which controller to use but sets to r4
{
	uint32 padstat1 = *(pad1 + 6);
	uint32 padstat2 = *(pad2 + 6);
	uint32 padstat3 = *(pad3 + 6);

	uint32 analogstat1 = padstat1 >> 16;
	uint32 analogstat2 = padstat2 >> 16;
	uint32 analogstat3 = padstat3 >> 16;

	if (CheckPress(padstat1, analogstat1))
		r4 = pad1;
	else if (CheckPress(padstat2, analogstat2))
		r4 = pad2;
	else if (CheckPress(padstat3, analogstat3))
		r4 = pad3;
	else
		r4 = pad4;
}

void PadInput_r28()//which controller to use but sets to r28
{
	uint32 padstat1 = *(pad1 + 6);
	uint32 padstat2 = *(pad2 + 6);
	uint32 padstat3 = *(pad3 + 6);

	uint32 analogstat1 = padstat1 >> 16;
	uint32 analogstat2 = padstat2 >> 16;
	uint32 analogstat3 = padstat3 >> 16;

	if (CheckPress(padstat1, analogstat1))
		r28 = pad1;
	else if (CheckPress(padstat2, analogstat2))
		r28 = pad2;
	else if (CheckPress(padstat3, analogstat3))
		r28 = pad3;
	else
		r28 = pad4;
}

void PadInput_r5()//which controller to use but sets to r5 (yeah having to add to compiled code is dumb like this)
{
	uint32 padstat1 = *(pad1 + 6);
	uint32 padstat2 = *(pad2 + 6);
	uint32 padstat3 = *(pad3 + 6);

	uint32 analogstat1 = padstat1 >> 16;
	uint32 analogstat2 = padstat2 >> 16;
	uint32 analogstat3 = padstat3 >> 16;

	if (CheckPress(padstat1, analogstat1))
		r5 = pad1;
	else if (CheckPress(padstat2, analogstat2))
		r5 = pad2;
	else if (CheckPress(padstat3, analogstat3))
		r5 = pad3;
	else
		r5 = pad4;
}

int CheckPress(int padstat, int analogstat)//check if a controller is pressing a button
{
	if ((analogstat & ANALOG_LEFT) || (analogstat & ANALOG_RIGHT) || (analogstat & ANALOG_UP) || (analogstat & ANALOG_DOWN) || (padstat & PRESS_A) || (padstat & PRESS_B) || (padstat & PRESS_START) || (padstat & PRESS_L) || (padstat & PRESS_R))
		return 1;
	else
		return 0;
}

void setBeacon(uint32 this, int* param_1)// set 4 captain beacons, the whole BeaconID int is really stupid but it somehow works
{
	if (player < 3)
		BeaconID = *(int*)(this + 0x2c);

	if (BeaconID == 0)
	{
		*(short *)(this + 0x10) = 0x123;//olimar beacon 1
		*(short *)(this + 0x24) = 0x126;//olimar beacon 2
	}
	else if (BeaconID == 1)
	{
		*(short *)(this + 0x10) = 0xde;//louie beacon 1
		*(short *)(this + 0x24) = 0xe1;//louie beacon 2
	}
	else if (BeaconID == 2)
	{
		*(short *)(this + 0x10) = 0xde;//white beacon
		*(short *)(this + 0x24) = 0x123;
	}
	else if (BeaconID == 3)
	{
		*(short *)(this + 0x10) = 0x126;//purple beacon
		*(short *)(this + 0x24) = 0xe1;
	}
	createBeaconParticle((uint32*)this, param_1);
	if (BeaconID < player)
	BeaconID++;

}

void NaviHealth(double* this)// set captain life to double normal
{
	this[0xa8] = 150.0f;
}

void drawCredits(void)//draw custom cave results
{
	if (giveup)
		treasureCount = total_treasures;

	static int doDraw = 0;
	static int drawpat = 0;
	uint32 padstat1 = *(pad1 + 6);
	uint32 analogstat1 = padstat1 >> 16;
	char treasures[64];
	char pikicount[32];
	char tekicount[32];
	char deadcount[32];
	char pokocount[32];

	int seconds = (time / 30) % 60;
	int minutes = ((time / 30) / 60) % 60;
	int hours = (((time / 30) / 60) / 60);
	sprintf(DispTime, "Time: %02i:%02i:%02i", hours, minutes, seconds);

	int pokos = *(int*)(*(int*)(SDA - 0x6b70) + 0xe8);
	int pikis = alive;

	if (padstat1 & PRESS_A)
	doDraw = 1;
	if (padstat1 & PRESS_B)
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

		if(player > 2)
			J2DPictureEx__draw(naviicon[p3sel], 550.0f, 150.0f, 0, 0, 0);
		if (player > 3)
			J2DPictureEx__draw(naviicon[p4sel], 550.0f, 200.0f, 0, 0, 0);

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
			JUTFont__print(font, 20.0f, 330.0f, "Press L + R on the Nintendo Logo,", 1,0);
			JUTFont__print(font, 20.0f, 360.0f, "then again in-game for a surprise!", 1,0);

			if (patmode == 1 && padstat1 & PRESS_Z)
			{
				drawpat = 1;
			}
			if(drawpat == 1)
			J2DPictureEx__draw(patend, 0.0f, 0.0f, 0, 0, 0);
		}
	}
	__asm("addi 1, 1, 0x10");
}

void setFirstPerson(void)//change what camera config file loads
{
	if (bigmode == 0){
		writeAt(0x80250a94, 0x40820024);
		writeAt(0x80250aa0, 0x40820018);
		bigmode = 1;
	}
	else
	{
		writeAt(0x80250a94, 0x41820024);
		writeAt(0x80250aa0, 0x41820018);
		bigmode = 0;
	}
}

void setNoDemo()//set if treasure cutscenes
{
	if (!nodemo)
	{
		nodemo = true;
	}
	else
	{
		nodemo = false;
	}
}

void onMoviePlay()//allows for cutscene skip in treasure get
{
	movieDie = 0;
}

int Game__MoviePlayer__updateHook(int r3, int r4, int r5)//allows for cutscene skip in treasure get
{
	Game__MoviePlayer__Update(r3, r4, r5);
	if (movieDie)
	{
		if (*(uint32_t*)(r3 + 0x18) == 6)
			movieDie = 0;
		else if (*(uint16_t*)(0x80506f48)& PRESS_START && *(uint32_t*)(r3 + 0x18) == 5)
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

int onyondemo(int this, int flag)//so certain cutscenes can play despite reading their viewed flagged being disabled normally.
{
	return BitFlag__isFlag((int*)(this + 0x30), flag);
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
		patend = (uint32*)__nwa(0x1A8);
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
	StreamMgr__playDirect(name);

	else
	{
		sprintf(path, "player/%s/theme.ast", naviname[p1sel]);
		StreamMgr__playDirect(path);
	}
}

int ongiveup()// the giveup variable exists so our own total treasures is accurate
{
	giveup = true;
	return *(int*)(SDA - 0x6d0c);
}

int bigtreasuredead(int this)// this function makes TD drop its weapons on death, so they arent deleted
{
	int item = this;

	for (int i = 0; i < 4; i++)
	{
		if ((*(int*)(item + 0x3c4) != 0))
		{
			BigTreasure__createDropTreasureEffect(this, i);
			BigTreasure__finishTreasurePinchSmoke(this, i);
			BigTreasure__dropTreasure(this, i);
		//	OSReport("dropped item %i \n", i);
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

void widescreen1()// culling
{
	__asm("lfs 0, 0x2C(31)");
	if (widescreen == 1)
	{
		__asm("lis 14, 0x3FAB");
		__asm("stw 14, 0xC(2)");
		__asm("lfs 17, 0xC(2)");
		__asm("fmuls 0, 17, 0");
	}
}

void widescreen2()// particle draw
{
	__asm("lfs 30, 0x2C(6)");

	if (widescreen == 1)
	{
		__asm("lis 14, 0x3FAB");
		__asm("stw 14, 0xC(2)");
		__asm("lfs 17, 0xC(2)");
		__asm("fmuls 30, 17, 30");
	}
}

void widescreen3()// fov
{
	if (widescreen == 1)
	{
		__asm("lis 14, 0x3F40");
		__asm("stw 14, 0x8(2)");
		__asm("lfs 17, 0x8(2)");
		__asm("lfs 0, 0x0(3)");
		__asm("fmuls 0, 17, 0");
		__asm("stfs 0,0x0(3)");
	}
	r4 = 0;
}

void widescreen4()// screen mgr
{
	if (widescreen == 1)
	{
		__asm("lis 14, 0x3f36");
		__asm("stw 14, 0xcc(28)");
	}
	else
		__asm("stfs 0, 0xcc(28)");

}

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

void InitJ2dPrint(uint32* j2dprint)
{
	newfont = (*(uint32**)(SDA + -0x6428));
	if (newfont != 0) {
		newfont = newfont[0x18 / 4];
	}
	J2DPrint____ct_FF(j2dprint, newfont, 0.1);
	initiate_J2DPrint(j2dprint);
}

void update_totalPokoScreen_Redirect(uint32* totalPokoScreen)
{
	update_P2DScreenMgr(totalPokoScreen);
	if (nodemo == 0 || drawtotals == 0) {
		return;
	}
	float* positions = totalPokoScreen[0x15c / 4];
	uint32 broc_j2dprint[0x64 / 4];
	InitJ2dPrint(broc_j2dprint);

//	OSReport("%s\n", treasureName);
	J2DPrint__print(broc_j2dprint, positions[0xd4 / 4] - ((strlen(treasureName) - 1) * 14), positions[0xd8 / 4] + 30, treasureName);
}


typedef int(*func)(void);

int actOnyon_InteractSuckDone_Redirect(uint32** treasure)
{
	func getKind = treasure[0][0x1f4 / 4];
	int kind = getKind();

	if (kind >= 3)
	{
		// make the treasure gague do shutdown process if all treasures collected
		if (getNumOtakaraItems() == 1) {
			uint32****** t = (*(uint32**)(SDA + -0x6560));
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

		//	OSReport("%x %s %i \n", &explorerTreasures[index], *treasureName, index);
	}
	else if (kind == 3) {
		// edit this for proper treasure names
		treasureName = treasures[index];

		//	OSReport("%x %s %i \n", &treasures[index], *treasureName, index);
	}
	else
		treasureName = "";

	return kind;
}

int checkpatmode(int dead)
{
	//OSReport("p1 %i \n", p1sel);
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

int vibrate2(int this, int* arg, int id)
{
	arg[0] = 0;
	arg[1] = player;
	return 1;
}

int vibrate(int this, int* arg, int id)
{
	if (player == 1)
	{
		arg[0] = 0;
		arg[1] = 1;
		return 1;
	}
	else
	{
		if (id == 0)
		{
			arg[0] = 0;
			arg[1] = 1;
			return 1;
		}
		if (id == 1)
		{
			arg[0] = 1;
			arg[1] = 2;
			return 1;
		}
		if (id == 2)
		{
			arg[0] = 2;
			arg[1] = 3;
			return 1;
		}
		if (id == 3)
		{
			arg[0] = 3;
			arg[1] = 4;
			return 1;
		}
		if (id == 4)
		{
			arg[0] = 0;
			arg[1] = player;
			return 1;
		}
	}
	return 0;
}

void getdead(int count)
{
	dead = count;
}

void getalive(int count)
{
	alive = count;
}
*/