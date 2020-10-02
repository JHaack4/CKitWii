from devkit_tools import Project 
from doltools import write_lis, write_ori


def patch_osarena_low(dol, size):
    dol.seek(0x8012c0cc)
    size = size + 0x3000
    write_lis(dol, 3, size >> 16, signed=False)
    write_ori(dol, 3, 3, size & 0xFFFF)

    dol.seek(0x8012c07c)
    write_lis(dol, 3, size >> 16, signed=False)
    write_ori(dol, 3, 3, size & 0xFFFF)

    print ("NewPC_2 size", hex(size))
    
import sys

if len(sys.argv) > 1 and sys.argv[1] == "load":
	p = Project("pikmin.dol", address=0x80688300)
	p.set_osarena_patcher(patch_osarena_low)

	p.add_file("pikmin.c")

	p.branchlink(0x804bffec, "create2D")
	p.branchlink(0x801df758, "onDraw2D")
	p.branch(0x804ceb68, "onNintendoLogo")
	#p.branchlink(0x801c2278, "addTekiBirthCount")
	#p.branchlink(0x80197374, "subTekiBirthCount") 
	p.branch(0x80285ecc,"onOtakaraborn")
	p.branch(0x80287730, "onOtakaraborn")
	p.branchlink(0x8026f2fc, "onOtakaraCollected")
	p.branchlink(0x8026f384, "onOtakaraCollected")
	p.branchlink(0x801e8074, "getCavePikis")
	p.branch(0x802ef604, "onKill_Hiba")
	p.branch(0x802f0db0, "onKill_Hiba")
	p.branch(0x802f30ec, "onKill_Hiba")
	p.branchlink(0x804cd968, "onCaveinit")
	p.branch(0x80396940, "onCaveLoading")
	p.branch(0x8026f3e8, "incGroundOtakara")
	p.branch(0x804b35f4, "onMoviePlay")
	p.branchlink(0x801df61c, "Game__MoviePlayer__updateHook")
	p.branchlink(0x80246e78, "initUnitlist")
	p.branchlink(0x803b64ac, "changeCaveSong")
	p.branchlink(0x80299208, "checkcavescene")
	p.branchlink(0x80396238, "endObjFloor")
	p.branchlink(0x801e0c74, "NaviHealth")#olimar
	p.branchlink(0x801e0e90, "NaviHealth")#loozy
	p.branchlink(0x80480390, "drawCredits")
	p.branchlink(0x802d0f00, "storeCaveSeed")
	p.branchlink(0x801edc48, "createModel")
	p.branchlink(0x801e4064, "loadNaviModel")
	p.branchlink(0x801ee128, "loadNaviModelOlimar")
	p.branch(0x803911f8, "onPauseMenu")
	p.branchlink(0x80391144, "onPauseClose")
	p.branchlink(0x8026fbc4, "getFirstGlobe")
	p.branchlink(0x8026fbd4, "getSecondGlobe")
	p.branchlink(0x8026fb50, "getfist")
	p.branchlink(0x80271954, "spraycount")
	p.branchlink(0x80069680, "streamfilename")
	p.branch(0x8029c9dc, "setinresult")
	p.branch(0x804cd4d0, "onbootfixastflag")
	p.branchlink(0x8029a7b8, "ongiveup");
	p.branchlink(0x80359ad4, "bigtreasuredead")
	p.branch(0x801e968c, "setCNDtype")
	p.branchlink(0x801e61e8, "mainBGM")
	p.branchlink(0x801e6148, "isoverworld")
	p.branchlink(0x8025667c, "gatecolor")
	p.branchlink(0x803abd84, "update_totalPokoScreen_Redirect")
	p.branchlink(0x80207458, "actOnyon_InteractSuckDone_Redirect")
	p.branchlink(0x8030a2ec, "empressRollForceStop")
	p.branch(0x802b4e38, "getdead")
	p.branch(0x8025de74, "getalive")
	p.branchlink(0x80245d80, "OnOnyonBirth")

	p.apply_gecko("geckopatches.txt")

	p.add_linker_file("pikminSymbols.txt")
	
	#p.build_gecko("gecko_out.txt", 0x80474200)

	p.build("..\\root\\sys\\main.dol")
	#input()