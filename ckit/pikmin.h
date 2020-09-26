
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

#define LEFT 50
#define TOP 50
#define BOTTOM 400
#define RIGHT 550

#define true 1;
#define false 0;

#define SDA2 0x806754e0
#define SDA 0x80672800
#define MAXEN -0x7c38
#define CRRHEAP -0x77d4 /*becomeCurrentHeap destination*/
#define JFWSRHP -0x7638 /*JFWSystem::init root Heap*/
#define JFWSHP -0x7634 /*JFWSystem::init heap (1st heap)*/
#define FONT -0x7628
#define JASPCRHP -0x75b8 /*JASWaveBank optional preferred current heap*/
#define JASCRHP -0x7548 /*JASWaveBank default current heap*/
#define JASRTHP -0x7540 /*JASKernel::setupRootHeap*/
#define GRAPHICS -0x6d70
#define LIFEGAUGEMGR -0x6df8
#define NAVIMGR -0x6d20
#define NAVI -0x64AC
#define VIEWPORT -0x6960
#define SHADOW -0x6980
#define PIKIMGR -0x6d0c
#define GENENMGR -0x6e20 /* Game::GeneralEnemyMgr */
#define WATER -0x5038 /*waterbox pointer*/
#define PLAYDATA -0x6b70
#define SYSTEM -0x6514
#define EFX2D -0x65F8
#define PEOTMGR -0xffff
#define REG3 -0x7990
#define EFX -0x65E8
#define SFX -0x67a8 //used for playSystemSE
#define UNKHP -0x6428 /*Unknown current heap of messageMgr / P2JME::Mgr*/
#define RESMGR 0x6450 /*Resource::Mgr contains (3rd) heap at off 0x4*/
#define PIKIMGR -0x6d0c
#define PCRCMGR -0x6ce0
#define GAMESYS -0x6c18
#define ROOMMGR -0x6cf8
#define PEOTMGR -0x6ae0
#define CORPSEMGR -0x6b00
#define NUMPELTMGR -0x6b08
#define PEITMGR -0x6ad8
#define ONYONMGR -0x6cd0

#define GAMEFLOW *(uint32_t*)(*(uint32_t*)(SDA + SYSTEM) + 0x3C)
#define MENUSECT *(uint32_t*)(GAMEFLOW + 4)
#define GAMESECT *(uint32_t*)(MENUSECT + 0x5c)
#define GMSTMACH *(uint32_t*)(GAMESECT + 0x270)
#define GAMSTATE *(uint32_t*)(GAMESECT + 0x274) /*FSM state*/

#define PRESS_START	0x1000
#define PRESS_B		0x0200
#define PRESS_A		0x0100
#define PRESS_Z		0x0010
#define PRESS_X		0x0400
#define PRESS_Y		0x0800
#define PRESS_DU	0x0008
#define PRESS_DD	0x0004
#define PRESS_DL	0x0001
#define PRESS_DR	0x0002

#define ANALOG_UP       0x0800
#define ANALOG_DOWN     0x0400
#define ANALOG_LEFT     0x0100 
#define ANALOG_RIGHT    0x0200

typedef struct{
	uint16_t buttons;
	int8_t lanalogx;
	int8_t lanalogy;
	int8_t ranalogx;
	int8_t ranalogy;
	uint16_t u1;
	uint8_t status;
	uint8_t u2;
	uint8_t u3;
	uint8_t u4;
} __attribute__((packed)) Controller;

typedef unsigned int uint32;
typedef unsigned char byte;
typedef uint32 J2DPane;
typedef unsigned char bool;
typedef uint32 BaseGameSection;
//typedef uint32 JKRExpandSwitch;
typedef uint32 JKRHeap;
typedef uint32 JKRArchive;
typedef uint32 J2DScreen;
typedef uint32 NaviMgr;
typedef int enumState;
typedef uint32 JKRDisposer;
typedef uint32 Viewport;
typedef byte ResTIMG;
typedef uint32 CNode;
typedef uint32 Mgr;
typedef uint32 BgmSeq;
typedef uint32 SceneInfo;
typedef uint32 Mgr_tuning;
typedef char SysIF;

uint32*** JUTPadList = (uint32***)0x80506dc0; 

//typedef uint32 JKRDvdRipper__EAllocDirection;
void enemyMgr_case3();
int * Game__Pelplant__Mgr__ct(uint32_t this, uint32_t, uint32_t);

void LAB_80126728();

int onyon(uint32*, uint32, uint32);

void * Game__PelPlant__Generator__ct(int);

void * memcpy(uint32_t dest, uint32_t src, uint32_t n);
void __flush_cache(uint32_t addr, uint32_t size);
void* new(unsigned int val1, void* jkrheap, int val2);
void* __nwa(unsigned long);
void newViewport__setRect(uint32* graphics, float x1, float y1, float x2, float y2);
uint32* JSystem__operator_new(uint32 size); 

//void Radar__Mgr__calcNearestTreasure(int this, float* r4In, float* r5Out, float* r6Out, float unk);

typedef int(*FunctionFunc)();
FunctionFunc getTekiId;


struct Rect {
	float x1;
	float y1;
	float x2;
	float y2;
};

struct PerspArg {
	int viewport;
	int unk4;
	int PSMStuff;
	int unkC;
	float fontsize;
	uint32 RGBA1;
	uint32 RGBA2;
};

struct WPSearchArg {
	float xpos;
	float ypos;
	float zpos;
	int unk1;
	char unk2;
	float unk;
};

struct Color {
	float R;
	float G;
	float B;
	float A;
};

struct Vector3 
{
	float z;
	float y;
	float x;
};

void * memmove(void*, const void*, size_t);
void __dla(void*);

uint32* JKRDvdRipper__loadToMainRAM(char const * filepath, 
                                unsigned char * param1, 
                                uint32 param2, //JKRExpandSwitch param2, 
                                unsigned long param3, 
                                JKRHeap * heap, 
                                uint32 param4, //JKRDvdRipper__EAllocDirection param4, 
                                unsigned long param5, 
                                int * param6, 
                                unsigned long * param7);
                                
void JUTTexture__storeTIMG(uint32* this, ResTIMG* imgdata, byte fmt);
uint32* J2DPictureEx____ct(uint32* this, ResTIMG* imgdata, uint32 fmt);
void J2DPictureEx__draw(uint32* this, float x, float y, bool param1, bool param2, bool param3);

int OnOnyonBirth(uint32 *r3, uint32 type, uint32 colorID);

void P2DScreenMgrUpdate(uint32* this);
void CallBack_CatchPiki__setPikiIcon(uint32* this, uint32 param);

double JUTResFont__drawChar_scale(double, double, double, double, int, char, bool);
void JUTResFont__setGX(int *, int *, int *);
void JUTResFont__getWidthEntry(int *, char, char *);
void JUTFont__setGradColor(int *, int *, int *);
void JMessage__TProcessor__reset_(int* p1, int p2);
int JKRExpHeap__do_getTotalFreeSize(int);
int JKRSolidHeap__do_getTotalFreeSize(int);
int AABBWaterBox__getSeaHeightPtr(int);

void J2DPane__resize(J2DPane *this, float width, float height);
void J2DPane__move(J2DPane *this, float x, float y);
void J2DPane__rotate(J2DPane *this, float angle);
void JUTException__panic_f(char *param_1, int param_2, char *param_3,...);
uint32* J2DPrint____ct_FTT(uint32* this, uint32* font, uint32* tcolor1, uint32* tcolor2); 
uint32* J2DPrint____ct_FF(uint32* this, uint32* font, float val);
uint32* J2DPrint____ct_FFF_TTTT(uint32* this, uint32* font, float hspace, float vspace, uint32* color1, uint32* color2, uint32* color3, uint32* color4);
void J2DPrint__print(uint32* this, float x, float y, char * bla, ...);
void J2DPrint__print_alpha(uint32* this, float x, float y, unsigned char alpha, char * bla, ...);
void J2DPrint__setFontSize(uint32* this, float val);

uint32_t* MonoObjectMgr_Otakara__getNext(uint32_t this, int i);
uint32_t* MonoObjectMgr_Otakara__getStart(uint32_t this);
uint32_t* MonoObjectMgr_Otakara__getEnd(uint32_t this);
uint32_t* MonoObjectMgr_Otakara__get(uint32_t this, int id);
int getCavePikis(int* r3, int r4);

uint32_t* MonoObjectMgr_Carcass__getNext(uint32_t this, int i);
uint32_t* MonoObjectMgr_Carcass__getStart(uint32_t this);
uint32_t* MonoObjectMgr_Carcass__getEnd(uint32_t this);
uint32_t* MonoObjectMgr_Carcass__get(uint32_t this, int id);

// Order of setting up a game section:
// First setupFloatMemory when first starting a section 
// After that when changing game sections clearHeap runs first before 
// setting up floatMemory for next gamesection 

// Runs e.g. when going from overworld back to level select 
// or from overworld to cave, or from cave to cave 
uint32 Game__BaseGameSection__clearHeap(uint32* this);

// Runs when going from level select to overworld 
// or from overworld to cave, or from cave to deeper caves 
void Game__SingleGameSection__onSetupFloatMemory(uint32* this);


uint32* MonoObjectMgr_GameNavi__getAt(uint32* mgr, int index);

void Game__Navi__getPosition( float* out, uint32* navi);
//uint32* JPAEmitterManager__createSimpleEmitterID(uint32* this, float[] tvec3, unsigned short param, unsigned char param2, unsigned char param3, 
//                uint32* JPAEmitterCallBack, uint32* JPAParticleCallBack);
uint32* ParticleMgr__create(uint32* this, unsigned short param1, float* tvec3, unsigned char param2);
void ParticleMgr__forceKill(uint32* this, uint32* JPABaseEmitter);
void ParticleMgr__killAll(uint32* this);
/*
J2DTextBox_SetString
J2DGrafContext_Setup2D
J2DScreen_Draw
JUTRect_Set
J2DTextBox_Create*/

struct EnemyInfo {
	char ** ppEnemyName;
	char ID;
	char baseID; // inheritance base ID -1 for base, non -1 for derived
	char memberID; // usually 1, 2 for ElecHiba
	char unk7;
	short unk8;
	char gap_0xA[0x28 - 0xA]; // padding not important for us yet
	int childID; // recursive, -1 for no child
	int maxChildren; // 0 usually, but non-zero when childID not -1
	char gap_0x30[0x34 - 0x30]; // more unkown padding
};

// 100 element array
struct EnemyInfo * enemiInfo = 0x804ac478;

void * Game__EnemyInfoFunc__getEnemyInfo(int, int);
char Game__GeneralEnemyMgr__getEnemyNum(int, int, int);
void Game__MoviePlayer__skip(int);

void J3DModelData__newSharedDisplayList(int, int);
void J3DModelData__makeSharedDL(int);

void newViewport_ct(uint32* this, uint32* graphics);

double p2sin(double dontcare);
double p2cos(double dontcare);