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

	""" with open("pikmin.c","r") as f:
		for line in f:
			if "//bl" in line:
				line = line.replace("//bl","").strip()
				linea = line.split(" ")
				if len(linea) >= 2:
					p.branchlink(int(linea[0].replace("0x",""), 16), linea[1].replace('"',""))
					#print("added bl " + str(linea))
			elif "//b" in line:
				line = line.replace("//b","").strip()
				linea = line.split(" ")
				if len(linea) == 2:
					p.branch(int(linea[0].replace("0x",""), 16), linea[1].replace('"',"")) """


	#p.branchlink(0x802dd520, "makeBigTreasureParticle")
	#p.branchlink(0x80438644, "P2JME__Mgr__setupFont")
	#p.branchlink(0x8014bd14, "onDraw2D")
	#p.branchlink(0x8014bca0, "onDraw3D")
	#p.branchlink(0x8013f204, "gethellpos")
	#p.branchlink(0x8013f1e0, "hellfix")
	#p.branch(0x801074ac, "demoactor")
	#p.branchlink(0x80437750, "startkantei")
	#p.branchlink(0x80437770, "startkantei")
	#p.branchlink(0x80245d80, "OnOnyonBirth")
	#p.branchlink(0x8018f554, "purplenerf")
	#p.branchlink(0x8018f4c0, "purplenerf")

	#p.apply_gecko("geckopatches.txt")

	p.add_linker_file("pikminSymbols.txt")
	
	#p.build_gecko("gecko_out.txt", 0x80474200)

	p.build("..\\root\\sys\\main.dol")
	# input()
	print("done!")