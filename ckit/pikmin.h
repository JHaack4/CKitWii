
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
//#define MAXEN -0x7c38
//#define CRRHEAP -0x77d4 /*becomeCurrentHeap destination*/
//#define JFWSRHP -0x7638 /*JFWSystem::init root Heap*/
//#define JFWSHP -0x7634 /*JFWSystem::init heap (1st heap)*/
//#define FONT -0x7628
//#define JASPCRHP -0x75b8 /*JASWaveBank optional preferred current heap*/
//#define JASCRHP -0x7548 /*JASWaveBank default current heap*/
//#define JASRTHP -0x7540 /*JASKernel::setupRootHeap*/
//#define GRAPHICS -0x6d70
//#define LIFEGAUGEMGR -0x6df8
//#define PLATMGR -0x6be0
#define NAVIMGR *(int*)(SDA - 0x5f18)
//#define CARRYINFOMGR -0x6d20
//#define CAMERAMGR -0x6960
//#define RUMBLEMGR -0x6958
//#define SHADOW -0x6980
#define ARAM *(int*)(SDA - 0x54b0)
#define PIKIMGR *(int*)(SDA - 0x5f04)
//#define GENENMGR -0x6e20 /* Game::GeneralEnemyMgr */
//#define FARMMGR -0x6e28
//#define BOSSBGMFADE -0x6e50
//#define WATER -0x5038 /*waterbox pointer*/
#define PLAYDATA *(int*)(SDA - 0x5d68)
//#define ITEMMGR -0x6bc8
//#define SYSTEM -0x6514
//#define EFX2D -0x65F8
//#define PEOTMGR -0xffff
//#define REG3 -0x7990
//#define EFX -0x65E8
#define SFX  *(int*)(SDA - 0x5990)
#define P2JMEMgr *(int*)(SDA - 0x5558)
//#define RESMGR 0x6450 /*Resource::Mgr contains (3rd) heap at off 0x4*/
//#define PIKIMGR -0x6d0c
//#define CELLPYRAMID -0x6d34
//#define PATHFINDER -0x6c80
//#define PCRCMGR -0x6ce0
//#define MOVIE -0x64ac
#define GAMESYS *(int*)(SDA - 0x5e10)
#define SEED *(int*)(SDA - 0x7D60)
//#define ROOMMAPMGR -0x6cf8
//#define PEOTMGR -0x6ae0
//#define PEITMGR -0x6ad8
#define GAME2DMGR *(int*)(SDA - 0x56B0)
#define MOVIE *(int*)(SDA - 0x55d4)
//#define CAMERAMGR *(int*)(SDA - 0x6960)

#define GAMEFLOW *(uint32_t*)(*(uint32_t*)(SDA + SYSTEM) + 0x3C)
#define MENUSECT *(uint32_t*)(GAMEFLOW + 4)
#define GAMESECT *(uint32_t*)(MENUSECT + 0x5c)
#define GMSTMACH *(uint32_t*)(GAMESECT + 0x270)
#define GAMSTATE *(uint32_t*)(GAMESECT + 0x274) /*FSM state*/

#define PRESS_2		0x0004//wii
#define PRESS_1		0x0008//wii
#define PRESS_DU	0x0010//wii
#define PRESS_DL	0x0020//wii
#define PRESS_Z		0x0040//wii
#define PRESS_A		0x0100//wii
#define PRESS_B		0x0200//wii
#define PRESS_C		0x0400//wii
#define PRESS_MINUS	0x0800//wii
#define PRESS_PLUS	0x1000//wii

#define PRESS_DR	0x0002
#define PRESS_DD	0x0002

#define ANALOG_UP       0x08000000
#define ANALOG_RIGHT    0x02000000
#define ANALOG_LEFT     0x01000000
#define ANALOG_DOWN	    0x04000000

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
