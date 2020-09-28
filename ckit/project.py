from devkit_tools import Project 
from doltools import write_lis, write_ori


def patch_osarena_low(dol, size):
    #800eb370
    dol.seek(0x8012c0cc)
    size = size + 0x40
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
	p.branchlink(0x801df6f0, "onDraw2D")
	#p.branch(0x804ceb68, "onNintendoLogo")
	#p.branchlink(0x801c2278, "addTekiBirthCount")
	#p.branchlink(0x80101f0c, "subTekiBirthCount") 
	#p.branch(0x80200f90,"onOtakaraborn")
	#p.branch(0x80204bbc, "onOtakaraborn")
	#p.branchlink(0x801e7940, "onOtakaraCollected")
	#p.branchlink(0x801e7a04 , "onOtakaraCollected")
	#p.branch(0x80270628, "onKill_Hiba")
	#p.branch(0x8026df98, "onKill_Hiba")
	#p.branchlink(0x80154f10, "getCavePikis")
	#p.branch(0x8026c5d8, "onKill_Hiba")
	p.branchlink(0x804cd968, "onCaveinit")
	#p.branch(0x8031b9b8, "onCaveLoading")
	#p.branchlink(0x8021f6fc, "OnyonCutscene")
	#p.branchlink(0x80155b90, "onP2TreasureRadar")
	#p.branchlink(0x80217b44, "unlockMenuMapParts")
	#p.branch(0x801e7b74, "incGroundOtakara")
	#p.branch(0x8042cb9c, "onMoviePlay")
	#p.branchlink(0x8014bbb4, "Game__MoviePlayer__updateHook")
	#p.branchlink(0x8014ef30, "gbgsdmd")
	#p.branchlink(0x80151298, "NewinitViewports")
	#p.branchlink(0x801b8074, "initUnitlist")
	#p.branchlink(0x80336cdc, "changeCaveSong")
	#p.branch(0x8031cb0c, "enableCounter")
	#p.branch(0x8031cb98, "disableCounter")
	#p.branchlink(0x80217914, "checkcavescene")
	#p.branchlink(0x8031b274, "endObjFloor")
	#p.branchlink(0x8014d280, "NaviHealth")#olimar
	#p.branchlink(0x8014d478, "NaviHealth")#loozy
	#p.branchlink(0x803fa1dc, "drawCredits")
	#p.branchlink(0x8024c118, "storeCaveSeed")
	#p.branchlink(0x8015aa34, "createModel")
	#p.branchlink(0x8015089c, "loadNaviModel")
	#p.branchlink(0x8015ae50, "loadNaviModelOlimar")
	#p.branchlink(0x803b81bc, "setBeacon")
	#p.branchlink(0x8014d430, "giveNavisControllers")
	#p.branchlink(0x8014d50c, "birthMoreNavis")
	#p.branchlink(0x80463f20, "onDemostart")
	#p.branchlink(0x80466da8, "onDemoend")
	#p.branch(0x80316664, "onPauseMenu")
	#p.branchlink(0x801461e4, "getPikiCount")
	#p.branchlink(0x801e60e8, "getFirstGlobe")
	#p.branchlink(0x801e60f8, "getSecondGlobe")
	#p.branchlink(0x801e6074, "getfist")
	#p.branch(0x80321ba0, "openOnion")
	#p.branch(0x8032452c, "openOnion")
	#p.branch(0x80321bac, "closeOnion")
	#p.branch(0x80324558, "closeOnion")
	#p.branch(0x803fd4c0, "kanteiDone")
	#p.branch(0x8023e2ac, "shadowCylinder")
	#p.branchlink(0x80239ca8, "setShadowDraw")
	#p.branchlink(0x80306c8c, "showNaviLife")
	#p.branchlink(0x8021f6e0, "onyondemo")
	#p.branchlink(0x801e8414, "spraycount")
	#p.branchlink(0x800b8a54, "streamfilename")
	#p.branch(0x8021ae18, "setinresult")
	#p.branch(0x80448220, "onbootfixastflag")
	#p.branch(0x80307978, "makePikiTex")
	#p.branchlink(0x80218c54, "ongiveup");
	#p.branchlink(0x802ddbb4, "bigtreasuredead")
	#p.branch(0x80156320, "setCNDtype")
	#p.branchlink(0x80152fec, "mainBGM")
	#p.branchlink(0x80152eb4, "isoverworld")
	#p.branchlink(0x801c8874, "gatecolor")
	#p.branchlink(0x8041a4b0, "widescreen1")
	#p.branchlink(0x803bb8a8, "widescreen2")
	#p.branchlink(0x8041ae14, "widescreen3")
	#p.branchlink(0x8043502c, "widescreen4")
	#p.branchlink(0x8032c6ac, "update_totalPokoScreen_Redirect")
	#p.branchlink(0x80176c9c, "actOnyon_InteractSuckDone_Redirect")
	#p.branchlink(0x80288a6c, "empressRollForceStop")
	#p.branch(0x80230e28, "getdead")
	#p.branch(0x801d1010, "getalive")

	p.branchlink(0x80245d80, "OnOnyonBirth")

	p.apply_gecko("geckopatches.txt")

	p.add_linker_file("pikminSymbols.txt")
	
	#p.build_gecko("gecko_out.txt", 0x80474200)

	p.build("..\\root\\sys\\main.dol")
	#input()