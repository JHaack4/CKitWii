	.file	"pikmin.c"
	.section	".text"
	.align 2
	.globl OnOnyonBirth
	.type	OnOnyonBirth, @function
OnOnyonBirth:
.LFB0:
	.cfi_startproc
	stwu 1,-264(1)
	.cfi_def_cfa_offset 264
	mflr 0
	stw 0,268(1)
	stw 28,200(1)
	stw 29,204(1)
	stw 30,208(1)
	.cfi_offset 65, 4
	.cfi_offset 28, -64
	.cfi_offset 29, -60
	.cfi_offset 30, -56
	mr 28,3
	lis 9,0x8066
	ori 9,9,0xcca8
	lwz 9,0(9)
	lwz 29,52(9)
	lwz 9,0(29)
	lwz 9,40(9)
	lwz 30,16(9)
	cmpwi 7,30,0
	beq- 7,.L2
	stw 26,192(1)
	.cfi_offset 26, -72
	stw 27,196(1)
	.cfi_offset 27, -68
	stw 31,212(1)
	.cfi_offset 31, -52
	mr 27,5
	li 31,0
	b .L7
.L4:
	addi 31,31,1
.L3:
	lwz 30,4(30)
	cmpwi 7,30,0
	beq- 7,.L21
.L7:
	lwz 3,24(30)
	crxor 6,6,6
	bl Game__Cave__UnitInfo__getUnitKind
	cmpwi 7,3,1
	bne+ 7,.L3
	lwz 3,24(30)
	crxor 6,6,6
	bl Game__Cave__UnitInfo__getBaseGen
	cmpwi 0,3,0
	beq+ 0,.L3
	lwz 9,16(3)
	cmpwi 7,9,0
	beq- 7,.L3
	lwz 10,24(9)
	cmpwi 7,10,7
	beq- 7,.L4
.L5:
	lwz 9,4(9)
	cmpwi 7,9,0
	beq- 7,.L3
	lwz 10,24(9)
	cmpwi 7,10,7
	bne+ 7,.L5
	b .L4
.L21:
	lis 26,0x5555
	ori 26,26,0x5556
	mulhw 26,31,26
	srawi 31,31,31
	subf. 26,31,26
	beq- 0,.L22
.L8:
	lwz 9,0(29)
	lwz 9,40(9)
	lwz 31,16(9)
	cmpwi 7,31,0
	beq- 7,.L19
	stw 19,164(1)
	.cfi_remember_state
	.cfi_offset 19, -100
	stw 20,168(1)
	.cfi_offset 20, -96
	stw 21,172(1)
	.cfi_offset 21, -92
	stw 22,176(1)
	.cfi_offset 22, -88
	stw 23,180(1)
	.cfi_offset 23, -84
	stw 24,184(1)
	.cfi_offset 24, -80
	stw 25,188(1)
	.cfi_offset 25, -76
	mr 25,30
	lis 19,0x8020
	ori 19,19,0xaf78
	lis 24,0x4330
	lis 20,.LC1@ha
	lis 21,.LC3@ha
	lis 22,.LC5@ha
	lis 23,.LC6@ha
	b .L12
.L22:
	.cfi_restore_state
	li 26,1
	b .L8
.L10:
	.cfi_offset 19, -100
	.cfi_offset 20, -96
	.cfi_offset 21, -92
	.cfi_offset 22, -88
	.cfi_offset 23, -84
	.cfi_offset 24, -80
	.cfi_offset 25, -76
	lwz 9,4(9)
	cmpwi 7,9,0
	beq- 7,.L23
.L11:
	lwz 10,24(9)
	cmpwi 7,10,7
	bne+ 7,.L10
	stw 9,0(8)
	addi 7,7,1
	addi 8,8,4
	b .L10
.L23:
	cmpwi 7,7,0
	beq- 7,.L9
	cmplwi 7,27,2
	bgt- 7,.L9
	stw 18,160(1)
	.cfi_offset 18, -104
	addi 25,25,1
	addi 18,27,1
	mullw 9,26,18
	cmpw 7,25,9
	beq- 7,.L24
	lwz 18,160(1)
	.cfi_restore 18
.L9:
	lwz 31,4(31)
	cmpwi 7,31,0
	beq- 7,.L25
.L12:
	addi 29,31,24
	lwz 3,24(31)
	crxor 6,6,6
	bl Game__Cave__UnitInfo__getUnitKind
	cmpwi 7,3,1
	bne+ 7,.L9
	lwz 3,24(31)
	crxor 6,6,6
	bl Game__Cave__UnitInfo__getBaseGen
	cmpwi 0,3,0
	beq+ 0,.L9
	lwz 9,16(3)
	cmpwi 7,9,0
	beq- 7,.L9
	mr 7,30
	addi 8,1,20
	b .L11
.L24:
	.cfi_offset 18, -104
	stfd 26,216(1)
	.cfi_offset 58, -48
	stfd 27,224(1)
	.cfi_offset 59, -40
	stfd 28,232(1)
	.cfi_offset 60, -32
	stfd 29,240(1)
	.cfi_offset 61, -24
	stfd 30,248(1)
	.cfi_offset 62, -16
	stfd 31,256(1)
	.cfi_offset 63, -8
	subfic 5,27,2
	li 4,0
	mr 3,28
	mtctr 19
	bctrl
	mr 27,3
	li 4,0
	crxor 6,6,6
	bl Game__Creature__init
	lwz 9,0(29)
	lwz 10,16(9)
	lfs 12,.LC1@l(20)
	xoris 10,10,0x8000
	stw 10,124(1)
	stw 24,120(1)
	lfd 0,120(1)
	fsub 0,0,12
	lfs 10,.LC3@l(21)
	fmul 0,0,10
	lwz 10,44(31)
	xoris 10,10,0x8000
	stw 10,132(1)
	stw 24,128(1)
	lfd 11,128(1)
	fsub 11,11,12
	fadd 0,0,11
	lfs 11,.LC5@l(22)
	fmul 0,0,11
	frsp 27,0
	lwz 10,20(9)
	xoris 10,10,0x8000
	stw 10,140(1)
	stw 24,136(1)
	lfd 0,136(1)
	fsub 31,0,12
	fmul 31,31,10
	lwz 10,48(31)
	xoris 10,10,0x8000
	stw 10,148(1)
	stw 24,144(1)
	lfd 0,144(1)
	fsub 0,0,12
	fadd 31,31,0
	fmul 31,31,11
	frsp 31,31
	lwz 9,12(9)
	xoris 9,9,0x8000
	stw 9,156(1)
	stw 24,152(1)
	lfd 0,152(1)
	fsub 0,0,12
	lfd 12,.LC6@l(23)
	fmul 0,0,12
	frsp 26,0
	lwz 9,20(1)
	lfs 30,36(9)
	lfs 0,32(9)
	stfs 0,12(1)
	lfs 28,28(9)
	fmr 1,26
	bl p2cos
	fmul 29,28,1
	fmr 1,26
	bl p2sin
	fmul 0,30,1
	fsub 0,29,0
	fadd 0,0,27
	frsp 0,0
	stfs 0,8(1)
	fmr 1,26
	bl p2sin
	fmul 28,28,1
	fmr 1,26
	bl p2cos
	fmul 0,30,1
	fadd 0,0,28
	fadd 0,0,31
	frsp 0,0
	stfs 0,16(1)
	li 5,0
	addi 4,1,8
	mr 3,27
	crxor 6,6,6
	bl Game__Creature__setPosition
	mr 27,18
	lfd 26,216(1)
	.cfi_restore 58
	lfd 27,224(1)
	.cfi_restore 59
	lfd 28,232(1)
	.cfi_restore 60
	lfd 29,240(1)
	.cfi_restore 61
	lfd 30,248(1)
	.cfi_restore 62
	lfd 31,256(1)
	.cfi_restore 63
	lwz 18,160(1)
	.cfi_restore 18
	b .L9
.L25:
	lwz 19,164(1)
	.cfi_restore 19
	lwz 20,168(1)
	.cfi_restore 20
	lwz 21,172(1)
	.cfi_restore 21
	lwz 22,176(1)
	.cfi_restore 22
	lwz 23,180(1)
	.cfi_restore 23
	lwz 24,184(1)
	.cfi_restore 24
	lwz 25,188(1)
	.cfi_restore 25
	lwz 26,192(1)
	.cfi_restore 26
	lwz 27,196(1)
	.cfi_restore 27
	lwz 31,212(1)
	.cfi_restore 31
.L2:
	li 5,0
	li 4,1
	mr 3,28
	lis 9,0x8020
	ori 9,9,0xaf78
	mtctr 9
	bctrl
	lwz 0,268(1)
	mtlr 0
	.cfi_restore 65
	lwz 28,200(1)
	lwz 29,204(1)
	lwz 30,208(1)
	addi 1,1,264
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 28
	.cfi_def_cfa_offset 0
	blr
.L19:
	.cfi_def_cfa_offset 264
	.cfi_offset 26, -72
	.cfi_offset 27, -68
	.cfi_offset 28, -64
	.cfi_offset 29, -60
	.cfi_offset 30, -56
	.cfi_offset 31, -52
	.cfi_offset 65, 4
	lwz 26,192(1)
	.cfi_restore 26
	lwz 27,196(1)
	.cfi_restore 27
	lwz 31,212(1)
	.cfi_restore 31
	b .L2
	.cfi_endproc
.LFE0:
	.size	OnOnyonBirth, .-OnOnyonBirth
	.globl enemiInfo
	.comm	getTekiId,4,4
	.globl JUTPadList
	.section	.rodata.cst4,"aM",@progbits,4
	.align 2
.LC1:
	.long	1501560836
.LC3:
	.long	1056964608
.LC5:
	.long	1126825984
	.section	.rodata.cst8,"aM",@progbits,8
	.align 3
.LC6:
	.long	1073290936
	.long	1374389535
	.section	.sdata,"aw"
	.align 2
	.type	enemiInfo, @object
	.size	enemiInfo, 4
enemiInfo:
	.long	-2142583688
	.type	JUTPadList, @object
	.size	JUTPadList, 4
JUTPadList:
	.long	-2142212672
	.ident	"GCC: (devkitPPC release 35) 8.3.0"
	.gnu_attribute 4, 9
