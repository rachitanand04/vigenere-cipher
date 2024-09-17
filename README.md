# Vigenere Cipher

### Aim
To create a program to cipher and decipher messages encrypted using Vigenere Cipher. Also to run Kasiski test and frequency analysis to figure out the key using ciphertext.

### Components
- `textinit.py`: To preprocess text before encrypting it.
- `kasiski.c`: To run the Kasiski test to figure out the key length.
- `freq_anal.c`: To confrm key length using *Index of Coincidence* and to work out the key.
- `vigenere.c`: To encrypt and decrypt messages.
### How to Run the Code
1. Run `textinit.py`, paste your ciphertext and it will give you the processed output that can be directly used for the rest of the program.
2. Run the `kasiski.c` file, paste your ciphertext and it will return all the repeated sub-strings as well as the most probable key length.
3. Run `freq_anal.c`, paste the ciphertext and enter the key length, it will split the string into different strings based on the key length giving *Index of Coincidence* for each step. It will also give the probable key.
### Step by Step Output
##### Ciphertext: 1342 Characters
```
CVJTNAFENMCDMKBXFSTKLHGSOJWHOFUISFYFBEXEINFIMAYSSDYYIJNPWTOKFRHWVWTZFXHLUYUMSGVDURBWBIVXFAFMYFYXPIGBHWIFHHOJBEXAUNFIYLJWDKNHGAOVBHHGVINAULZFOFUQCVFBYNFTYGMMSVGXCFZFOKQATUIFUFERQTEWZFOKMWOJYLNZBKSHOEBPNAYTFKNXLBVUAXCXUYYKYTFRHRCFUYCLUKTVGUFQBESWYSSWLBYFEFZVUWTRLLNGIZGBMSZKBTNTSLNNMDPMYMIUBVMTLOBJHHFWTJNAUFIZMBZLIVHMBSUWLBYFEUYFUFENBRVJVKOLLGTVUZUAOJNVUWTRLMBATZMFSSOJQXLFPKNAULJCIOYVDRYLUJMVMLVMUKBTNAMFPXXJPDYFIJFYUWSGVIUMBWSTUXMSSNYKYDJMCGASOUXBYSMCMEUNFJNAUFUYUMWSFJUKQWSVXXUVUFFBPWBCFYLWFDYGUKDRYLUJMFPXXEFZQXYHGFLACEBJBXQSTWIKNMORNXCJFAIBWWBKCMUKIVQTMNBCCTHLJYIGIMSYCFVMURMAYOBJUFVAUZINMATCYPBANKBXLWJJNXUJTWIKBATCIOYBPPZHLZJJZHLLVEYAIFPLLYIJIZMOUDPLLTHVEVUMBXPIBBMSNSCMCGONBHCKIVLXMGCRMXNZBKQHODESYTVGOUGTHAGRHRMHFREYIJIZGAUNFZIYZWOUYWQZPZMAYJFJIKOVFKBTNOPLFWHGUSYTLGNRHBZSOPMIYSLWIKBANYUOYAPWZXHVFUQAIATYYKYKPMCEYLIRNPCDMEIMFGWVBBMUPLHMLQJWUGSKQVUDZGSYCFBSWVCHZXFEXXXAQROLYXPIUKYHMPNAYFOFHXBSWVCHZXFEXXXAIRPXXGOVHHGGSVNHWSFJUKNZBESHOKIRFEXGUFVKOLVJNAYIVVMMCGOFZACKEVUMBATVHKIDMVXBHLIVWTJAUFFACKHCIKSFPKYQNWOLUMYVXYYKYAOYYPUKXFLMBQOFLACKPWZXHUFJYGZGSTYWZGSNBBWZIVMNZXFIYWXWBKBAYJFTIFYKIZMUIVZDINLFFUVRGSSBUGNGOPQAILIFOZBZFYUWHGIRHWCFIZMWYSUYMAUDMIYVYAWVNAYTFEYYCLPWBBMVZZHZUHMRWXCFUYYVIENFHPYSMKBTMOIZWAIXZFOLBSMCHHNOJKBMBATZXXJSSKNAULBJCLFWXDSUYKUCIOYJGFLMBWHFIWIXSFGXCZBMYMBWTRGXXSHXYKZGSDSLYDGNBXHAUJBTFDQCYTMWNPWHOFUISMIFFVXFSVFRNA
```
#### textinit.py
```
cvjtnafenmcdmkbxfstklhgsojwhofuisfyfbexeinfimayssdyyijnpwtokfrhwvwtzfxhluyumsgvdurbwbivxfafmyfyxpigbhwifhhojbexaunfiyljwdknhgaovbhhgvinaulzfofuqcvfbynftygmmsvgxcfzfokqatuifuferqtewzfokmwojylnzbkshoebpnaytfknxlbvuaxcxuyykytfrhrcfuycluktvgufqbeswysswlbyfefzvuwtrllngizgbmszkbtntslnnmdpmymiubvmtlobjhhfwtjnaufizmbzlivhmbsuwlbyfeuyfufenbrvjvkollgtvuzuaojnvuwtrlmbatzmfssojqxlfpknauljcioyvdrylujmvmlvmukbtnamfpxxjpdyfijfyuwsgviumbwstuxmssnykydjmcgasouxbysmcmeunfjnaufuyumwsfjukqwsvxxuvuffbpwbcfylwfdygukdrylujmfpxxefzqxyhgflacebjbxqstwiknmornxcjfaibwwbkcmukivqtmnbccthljyigimsycfvmurmayobjufvauzinmatcypbankbxlwjjnxujtwikbatcioybppzhlzjjzhllveyaifpllyijizmoudpllthvevumbxpibbmsnscmcgonbhckivlxmgcrmxnzbkqhodesytvgougthagrhrmhfreyijizgaunfziyzwouywqzpzmayjfjikovfkbtnoplfwhgusytlgnrhbzsopmiyslwikbanyuoyapwzxhvfuqaiatyykykpmceylirnpcdmeimfgwvbbmuplhmlqjwugskqvudzgsycfbswvchzxfexxxaqrolyxpiukyhmpnayfofhxbswvchzxfexxxairpxxgovhhggsvnhwsfjuknzbeshokirfexgufvkolvjnayivvmmcgofzackevumbatvhkidmvxbhlivwtjauffackhciksfpkyqnwolumyvxyykyaoyypukxflmbqoflackpwzxhufjygzgstywzgsnbbwzivmnzxfiywxwbkbayjftifykizmuivzdinlffuvrgssbugngopqailifozbzfyuwhgirhwcfizmwysuymaudmiyvyawvnaytfeyyclpwbbmvzzhzuhmrwxcfuyyvienfhpysmkbtmoizwaixzfolbsmchhnojkbmbatzxxjssknaulbjclfwxdsuykucioyjgflmbwhfiwixsfgxczbmymbwtrgxxshxykzgsdslydgnbxhaujbtfdqcytmwnpwhofuismiffvxfsvfrna
```
#### `kasiski.c`
```
Sub-Sequence: tna at index 3 and 399, distance: 396
Sub-Sequence: fen at index 6 and 329, distance: 323
Sub-Sequence: cdm at index 10 and 826, distance: 816
Sub-Sequence: mkb at index 12 and 1200, distance: 1188
Sub-Sequence: kbx at index 13 and 601, distance: 588
Sub-Sequence: soj at index 23 and 365, distance: 342
Sub-Sequence: who at index 26 and 1322, distance: 1296
Sub-Sequence: hof at index 27 and 1323, distance: 1296
Sub-Sequence: ofu at index 28 and 140, distance: 112
Sub-Sequence: ofu at index 28 and 1324, distance: 1296
Sub-Sequence: fui at index 29 and 1325, distance: 1296
Sub-Sequence: uis at index 30 and 1326, distance: 1296
Sub-Sequence: bex at index 36 and 108, distance: 72
Sub-Sequence: nfi at index 41 and 113, distance: 72
Sub-Sequence: may at index 44 and 578, distance: 534
Sub-Sequence: may at index 44 and 746, distance: 702
Sub-Sequence: yss at index 46 and 244, distance: 198
Sub-Sequence: yij at index 51 and 645, distance: 594
Sub-Sequence: yij at index 51 and 723, distance: 672
Sub-Sequence: npw at index 54 and 1320, distance: 1266
Sub-Sequence: frh at index 60 and 222, distance: 162
Sub-Sequence: rhw at index 61 and 1135, distance: 1074
Sub-Sequence: vwt at index 64 and 991, distance: 927
Sub-Sequence: uyu at index 72 and 462, distance: 390
Sub-Sequence: yum at index 73 and 463, distance: 390
Sub-Sequence: sgv at index 76 and 418, distance: 342
Sub-Sequence: vxf at index 86 and 1333, distance: 1247
Sub-Sequence: yxp at index 94 and 880, distance: 786
Sub-Sequence: xpi at index 95 and 665, distance: 570
Sub-Sequence: xpi at index 95 and 881, distance: 786
Sub-Sequence: aun at index 111 and 729, distance: 618
Sub-Sequence: unf at index 112 and 454, distance: 342
Sub-Sequence: unf at index 112 and 730, distance: 618
Sub-Sequence: fiy at index 114 and 1074, distance: 960
Sub-Sequence: hhg at index 129 and 920, distance: 791
Sub-Sequence: gvi at index 131 and 419, distance: 288
Sub-Sequence: nau at index 134 and 302, distance: 168
Sub-Sequence: nau at index 134 and 374, distance: 240
Sub-Sequence: nau at index 134 and 458, distance: 324
Sub-Sequence: nau at index 134 and 1238, distance: 1104
Sub-Sequence: aul at index 135 and 375, distance: 240
Sub-Sequence: aul at index 135 and 1239, distance: 1104
Sub-Sequence: zfo at index 138 and 162, distance: 24
Sub-Sequence: zfo at index 138 and 180, distance: 42
Sub-Sequence: zfo at index 138 and 1212, distance: 1074
Sub-Sequence: fof at index 139 and 893, distance: 754
Sub-Sequence: ofu at index 140 and 1324, distance: 1184
Sub-Sequence: fuq at index 141 and 804, distance: 663
Sub-Sequence: gxc at index 158 and 1274, distance: 1116
Sub-Sequence: xcf at index 159 and 1185, distance: 1026
Sub-Sequence: zfo at index 162 and 180, distance: 18
Sub-Sequence: zfo at index 162 and 1212, distance: 1050
Sub-Sequence: fok at index 163 and 181, distance: 18
Sub-Sequence: fuf at index 171 and 327, distance: 156
Sub-Sequence: ufe at index 172 and 328, distance: 156
Sub-Sequence: zfo at index 180 and 1212, distance: 1032
Sub-Sequence: nzb at index 190 and 694, distance: 504
Sub-Sequence: nzb at index 190 and 934, distance: 744
Sub-Sequence: zbk at index 191 and 695, distance: 504
Sub-Sequence: sho at index 194 and 938, distance: 744
Sub-Sequence: pna at index 199 and 889, distance: 690
Sub-Sequence: nay at index 200 and 890, distance: 690
Sub-Sequence: nay at index 200 and 956, distance: 756
Sub-Sequence: nay at index 200 and 1160, distance: 960
Sub-Sequence: ayt at index 201 and 1161, distance: 960
Sub-Sequence: ytf at index 202 and 220, distance: 18
Sub-Sequence: ytf at index 202 and 1162, distance: 960
Sub-Sequence: uyy at index 216 and 1188, distance: 972
Sub-Sequence: yyk at index 217 and 811, distance: 594
Sub-Sequence: yyk at index 217 and 1021, distance: 804
Sub-Sequence: yky at index 218 and 434, distance: 216
Sub-Sequence: yky at index 218 and 812, distance: 594
Sub-Sequence: yky at index 218 and 1022, distance: 804
Sub-Sequence: ytf at index 220 and 1162, distance: 942
Sub-Sequence: rhr at index 223 and 715, distance: 492
Sub-Sequence: cfu at index 226 and 1186, distance: 960
Sub-Sequence: fuy at index 227 and 461, distance: 234
Sub-Sequence: fuy at index 227 and 1187, distance: 960
Sub-Sequence: ycl at index 229 and 1167, distance: 938
Sub-Sequence: tvg at index 234 and 705, distance: 471
Sub-Sequence: guf at index 236 and 947, distance: 711
Sub-Sequence: bes at index 240 and 936, distance: 696
Sub-Sequence: wys at index 243 and 1143, distance: 900
Sub-Sequence: wlb at index 247 and 319, distance: 72
Sub-Sequence: lby at index 248 and 320, distance: 72
Sub-Sequence: byf at index 249 and 321, distance: 72
Sub-Sequence: yfe at index 250 and 322, distance: 72
Sub-Sequence: vuw at index 255 and 351, distance: 96
Sub-Sequence: uwt at index 256 and 352, distance: 96
Sub-Sequence: wtr at index 257 and 353, distance: 96
Sub-Sequence: wtr at index 257 and 1283, distance: 1026
Sub-Sequence: trl at index 258 and 354, distance: 96
Sub-Sequence: izg at index 264 and 726, distance: 462
Sub-Sequence: bms at index 267 and 669, distance: 402
Sub-Sequence: kbt at index 271 and 397, distance: 126
Sub-Sequence: kbt at index 271 and 757, distance: 486
Sub-Sequence: kbt at index 271 and 1201, distance: 930
Sub-Sequence: btn at index 272 and 398, distance: 126
Sub-Sequence: btn at index 272 and 758, distance: 486
Sub-Sequence: mym at index 283 and 1279, distance: 996
Sub-Sequence: obj at index 293 and 581, distance: 288
Sub-Sequence: wtj at index 299 and 992, distance: 693
Sub-Sequence: jna at index 301 and 457, distance: 156
Sub-Sequence: jna at index 301 and 955, distance: 654
Sub-Sequence: nau at index 302 and 374, distance: 72
Sub-Sequence: nau at index 302 and 458, distance: 156
Sub-Sequence: nau at index 302 and 1238, distance: 936
Sub-Sequence: auf at index 303 and 459, distance: 156
Sub-Sequence: auf at index 303 and 995, distance: 692
Sub-Sequence: fiz at index 305 and 1139, distance: 834
Sub-Sequence: izm at index 306 and 648, distance: 342
Sub-Sequence: izm at index 306 and 1092, distance: 786
Sub-Sequence: izm at index 306 and 1140, distance: 834
Sub-Sequence: liv at index 311 and 989, distance: 678
Sub-Sequence: vko at index 336 and 950, distance: 614
Sub-Sequence: kol at index 337 and 951, distance: 614
Sub-Sequence: wtr at index 353 and 1283, distance: 930
Sub-Sequence: lmb at index 356 and 1034, distance: 678
Sub-Sequence: lmb at index 356 and 1262, distance: 906
Sub-Sequence: mba at index 357 and 975, distance: 618
Sub-Sequence: mba at index 357 and 1227, distance: 870
Sub-Sequence: bat at index 358 and 616, distance: 258
Sub-Sequence: bat at index 358 and 976, distance: 618
Sub-Sequence: bat at index 358 and 1228, distance: 870
Sub-Sequence: atz at index 359 and 1229, distance: 870
Sub-Sequence: fpk at index 371 and 1007, distance: 636
Sub-Sequence: kna at index 373 and 1237, distance: 864
Sub-Sequence: nau at index 374 and 458, distance: 84
Sub-Sequence: nau at index 374 and 1238, distance: 864
Sub-Sequence: aul at index 375 and 1239, distance: 864
Sub-Sequence: cio at index 379 and 619, distance: 240
Sub-Sequence: cio at index 379 and 1255, distance: 876
Sub-Sequence: ioy at index 380 and 620, distance: 240
Sub-Sequence: ioy at index 380 and 1256, distance: 876
Sub-Sequence: dry at index 384 and 498, distance: 114
Sub-Sequence: ryl at index 385 and 499, distance: 114
Sub-Sequence: ylu at index 386 and 500, distance: 114
Sub-Sequence: luj at index 387 and 501, distance: 114
Sub-Sequence: ujm at index 388 and 502, distance: 114
Sub-Sequence: vmu at index 394 and 574, distance: 180
Sub-Sequence: muk at index 395 and 549, distance: 154
Sub-Sequence: kbt at index 397 and 757, distance: 360
Sub-Sequence: kbt at index 397 and 1201, distance: 804
Sub-Sequence: btn at index 398 and 758, distance: 360
Sub-Sequence: mfp at index 402 and 504, distance: 102
Sub-Sequence: fpx at index 403 and 505, distance: 102
Sub-Sequence: pxx at index 404 and 506, distance: 102
Sub-Sequence: pxx at index 404 and 914, distance: 510
Sub-Sequence: fyu at index 414 and 1128, distance: 714
Sub-Sequence: yuw at index 415 and 1129, distance: 714
Sub-Sequence: umb at index 422 and 662, distance: 240
Sub-Sequence: umb at index 422 and 974, distance: 552
Sub-Sequence: mbw at index 423 and 1263, distance: 840
Sub-Sequence: mbw at index 423 and 1281, distance: 858
Sub-Sequence: yky at index 434 and 812, distance: 378
Sub-Sequence: yky at index 434 and 1022, distance: 588
Sub-Sequence: mcg at index 439 and 675, distance: 236
Sub-Sequence: mcg at index 439 and 963, distance: 524
Sub-Sequence: ysm at index 448 and 1198, distance: 750
Sub-Sequence: smc at index 449 and 1217, distance: 768
Sub-Sequence: unf at index 454 and 730, distance: 276
Sub-Sequence: jna at index 457 and 955, distance: 498
Sub-Sequence: nau at index 458 and 1238, distance: 780
Sub-Sequence: auf at index 459 and 995, distance: 536
Sub-Sequence: fuy at index 461 and 1187, distance: 726
Sub-Sequence: wsf at index 466 and 928, distance: 462
Sub-Sequence: sfj at index 467 and 929, distance: 462
Sub-Sequence: fju at index 468 and 930, distance: 462
Sub-Sequence: juk at index 469 and 931, distance: 462
Sub-Sequence: uff at index 480 and 996, distance: 516
Sub-Sequence: pwb at index 484 and 1170, distance: 686
Sub-Sequence: pxx at index 506 and 914, distance: 408
Sub-Sequence: gfl at index 516 and 1260, distance: 744
Sub-Sequence: fla at index 517 and 1039, distance: 522
Sub-Sequence: lac at index 518 and 1040, distance: 522
Sub-Sequence: twi at index 528 and 612, distance: 84
Sub-Sequence: wik at index 529 and 613, distance: 84
Sub-Sequence: wik at index 529 and 787, distance: 258
Sub-Sequence: wbk at index 545 and 1079, distance: 534
Sub-Sequence: kiv at index 551 and 683, distance: 132
Sub-Sequence: syc at index 570 and 858, distance: 288
Sub-Sequence: ycf at index 571 and 859, distance: 288
Sub-Sequence: may at index 578 and 746, distance: 168
Sub-Sequence: ufv at index 584 and 948, distance: 364
Sub-Sequence: atc at index 593 and 617, distance: 24
Sub-Sequence: ban at index 598 and 790, distance: 192
Sub-Sequence: wik at index 613 and 787, distance: 174
Sub-Sequence: ikb at index 614 and 788, distance: 174
Sub-Sequence: kba at index 615 and 789, distance: 174
Sub-Sequence: kba at index 615 and 1081, distance: 466
Sub-Sequence: bat at index 616 and 976, distance: 360
Sub-Sequence: bat at index 616 and 1228, distance: 612
Sub-Sequence: cio at index 619 and 1255, distance: 636
Sub-Sequence: ioy at index 620 and 1256, distance: 636
Sub-Sequence: zhl at index 626 and 632, distance: 6
Sub-Sequence: pll at index 642 and 654, distance: 12
Sub-Sequence: yij at index 645 and 723, distance: 78
Sub-Sequence: iji at index 646 and 724, distance: 78
Sub-Sequence: jiz at index 647 and 725, distance: 78
Sub-Sequence: izm at index 648 and 1092, distance: 444
Sub-Sequence: izm at index 648 and 1140, distance: 492
Sub-Sequence: evu at index 660 and 972, distance: 312
Sub-Sequence: vum at index 661 and 973, distance: 312
Sub-Sequence: umb at index 662 and 974, distance: 312
Sub-Sequence: xpi at index 665 and 881, distance: 216
Sub-Sequence: bbm at index 668 and 836, distance: 168
Sub-Sequence: bbm at index 668 and 1172, distance: 504
Sub-Sequence: mcg at index 675 and 963, distance: 288
Sub-Sequence: cgo at index 676 and 964, distance: 288
Sub-Sequence: nzb at index 694 and 934, distance: 240
Sub-Sequence: syt at index 703 and 769, distance: 66
Sub-Sequence: ayj at index 747 and 1083, distance: 336
Sub-Sequence: yjf at index 748 and 1084, distance: 336
Sub-Sequence: kbt at index 757 and 1201, distance: 444
Sub-Sequence: lfw at index 763 and 1245, distance: 482
Sub-Sequence: whg at index 765 and 1131, distance: 366
Sub-Sequence: miy at index 782 and 1152, distance: 370
Sub-Sequence: kba at index 789 and 1081, distance: 292
Sub-Sequence: pwz at index 798 and 1044, distance: 246
Sub-Sequence: wzx at index 799 and 1045, distance: 246
Sub-Sequence: zxh at index 800 and 1046, distance: 246
Sub-Sequence: qai at index 806 and 1118, distance: 312
Sub-Sequence: yyk at index 811 and 1021, distance: 210
Sub-Sequence: yky at index 812 and 1022, distance: 210
Sub-Sequence: bbm at index 836 and 1172, distance: 336
Sub-Sequence: zgs at index 856 and 1054, distance: 198
Sub-Sequence: zgs at index 856 and 1060, distance: 204
Sub-Sequence: zgs at index 856 and 1294, distance: 438
Sub-Sequence: bsw at index 862 and 898, distance: 36
Sub-Sequence: swv at index 863 and 899, distance: 36
Sub-Sequence: wvc at index 864 and 900, distance: 36
Sub-Sequence: vch at index 865 and 901, distance: 36
Sub-Sequence: chz at index 866 and 902, distance: 36
Sub-Sequence: hzx at index 867 and 903, distance: 36
Sub-Sequence: zxf at index 868 and 904, distance: 36
Sub-Sequence: zxf at index 868 and 1072, distance: 204
Sub-Sequence: xfe at index 869 and 905, distance: 36
Sub-Sequence: fex at index 870 and 906, distance: 36
Sub-Sequence: fex at index 870 and 944, distance: 74
Sub-Sequence: exx at index 871 and 907, distance: 36
Sub-Sequence: xxx at index 872 and 908, distance: 36
Sub-Sequence: xxa at index 873 and 909, distance: 36
Sub-Sequence: nay at index 890 and 956, distance: 66
Sub-Sequence: nay at index 890 and 1160, distance: 270
Sub-Sequence: zxf at index 904 and 1072, distance: 168
Sub-Sequence: fex at index 906 and 944, distance: 38
Sub-Sequence: nay at index 956 and 1160, distance: 204
Sub-Sequence: ack at index 969 and 999, distance: 30
Sub-Sequence: ack at index 969 and 1041, distance: 72
Sub-Sequence: mba at index 975 and 1227, distance: 252
Sub-Sequence: bat at index 976 and 1228, distance: 252
Sub-Sequence: ack at index 999 and 1041, distance: 42
Sub-Sequence: flm at index 1033 and 1261, distance: 228
Sub-Sequence: lmb at index 1034 and 1262, distance: 228
Sub-Sequence: zgs at index 1054 and 1060, distance: 6
Sub-Sequence: zgs at index 1054 and 1294, distance: 240
Sub-Sequence: zgs at index 1060 and 1294, distance: 234
Sub-Sequence: izm at index 1092 and 1140, distance: 48
Sub-Sequence: suy at index 1145 and 1250, distance: 105
Sub-Sequence: mbw at index 1263 and 1281, distance: 18
Length of Key: 6
```
#### `freq_anal.c`
```
Enter string: 
cvjtnafenmcdmkbxfstklhgsojwhofuisfyfbexeinfimayssdyyijnpwtokfrhwvwtzfxhluyumsgvdurbwbivxfafmyfyxpigbhwifhhojbexaunfiyljwdknhgaovbhhgvinaulzfofuqcvfbynftygmmsvgxcfzfokqatuifuferqtewzfokmwojylnzbkshoebpnaytfknxlbvuaxcxuyykytfrhrcfuycluktvgufqbeswysswlbyfefzvuwtrllngizgbmszkbtntslnnmdpmymiubvmtlobjhhfwtjnaufizmbzlivhmbsuwlbyfeuyfufenbrvjvkollgtvuzuaojnvuwtrlmbatzmfssojqxlfpknauljcioyvdrylujmvmlvmukbtnamfpxxjpdyfijfyuwsgviumbwstuxmssnykydjmcgasouxbysmcmeunfjnaufuyumwsfjukqwsvxxuvuffbpwbcfylwfdygukdrylujmfpxxefzqxyhgflacebjbxqstwiknmornxcjfaibwwbkcmukivqtmnbccthljyigimsycfvmurmayobjufvauzinmatcypbankbxlwjjnxujtwikbatcioybppzhlzjjzhllveyaifpllyijizmoudpllthvevumbxpibbmsnscmcgonbhckivlxmgcrmxnzbkqhodesytvgougthagrhrmhfreyijizgaunfziyzwouywqzpzmayjfjikovfkbtnoplfwhgusytlgnrhbzsopmiyslwikbanyuoyapwzxhvfuqaiatyykykpmceylirnpcdmeimfgwvbbmuplhmlqjwugskqvudzgsycfbswvchzxfexxxaqrolyxpiukyhmpnayfofhxbswvchzxfexxxairpxxgovhhggsvnhwsfjuknzbeshokirfexgufvkolvjnayivvmmcgofzackevumbatvhkidmvxbhlivwtjauffackhciksfpkyqnwolumyvxyykyaoyypukxflmbqoflackpwzxhufjygzgstywzgsnbbwzivmnzxfiywxwbkbayjftifykizmuivzdinlffuvrgssbugngopqailifozbzfyuwhgirhwcfizmwysuymaudmiyvyawvnaytfeyyclpwbbmvzzhzuhmrwxcfuyyvienfhpysmkbtmoizwaixzfolbsmchhnojkbmbatzxxjssknaulbjclfwxdsuykucioyjgflmbwhfiwixsfgxczbmymbwtrgxxshxykzgsdslydgnbxhaujbtfdqcytmwnpwhofuismiffvxfsvfrna
Enter key length: 6
String 1
cfmtoubfsnftuvbfpibfdovzcfsztezobbfvufutbsetizspbbtiiueevtottopjdmumpfvssjomfufsubfdmfgbtofbibjsubutnjttpjvpipepnoicbeogfifopffpunolnpftpimwpjqswfqpmowfiosfbiuvvoetmiuhpoxoxopfssifbfizfsoifiiumwfpzmunmizmjtsbxughsbthsguqnuff
Index of Coincidence: 0.065823
String 2
vekkjieidprzydimifeikvifvtvfurfjkpkuyryvewfrzklmvjjzvwunkvjrzjkcrvkfdyitnmucjyjvfcdrfzfjwrakvcyyrjzckjwcpjelzlvisnvrksurrzzuzjklsrpwywuymrevlwvyveripfvervvjerfjvfvvvvfcklyyffwjtnviktzdubpfyrzyivewzryfkzfckzkjdcfffmrxdnjcpivr
Index of Coincidence: 0.063781
String 3
jnblwsxmywhfuuvyghxynbnofygoiqoysnnayhcgslzlgbnymhnmhlybounlmqniymbpyuuuycxmnuuxffyypqlbinicqcicmuiybniizzylmlubcblmqyghegiymibfyhmiuzqycnibhuuccxounhcxphnusfvnmzuhxwfiyuyyllzyybmybimivuqouhmmynybhwyhbwohbxncsiligygysbbywsxn
Index of Coincidence: 0.065102
String 4
tmxhhfeaytwxmrxfbhalhhafbgxkftklhaxxkrluwbvlbtnmthabmbfrlzvmfxaolltxfwmxkgbeamkxbyglxxaxkxbmttgfafnpxxkohhayotmbmhxxhttryaywaktwtbikoxakepmbmgdfhxlkaxhxxhhkhekamamkbtakqmkpmaxgwbnwafunrgazwwwavaybzxvptalhmxaluomwxmxklxtthmfa
Index of Coincidence: 0.068025
String 5
ncfgoyiyiovhsbfyhoujghuuymcquemnoylcycufyyunmnmilfuzbyuvluubsluyuvnxisbmyayuuwqupluuxycqncwumhivyvmblubylliiuhbmccmnovhmiuzqyonhlzybyhiyycfmlszbzxyyybzxxgwnoxoyccbihjcsnyyubchzzwzxyyilgnibhcyuyycmuciymibnbjufyybicbxzyhfmoisa
Index of Coincidence: 0.069947
String 6
adssffnsjkwlgwaxwjnwaglqnmfafwwzetbxtfkqsfwgstduowflsffjgawasflvjmajjgwsdssnfswvwwkjehesmjwknlmmoaaawjabzlfjdvxsgkgzdgahjnwzjvoggssaavakldguqkgsxaxhfsxaggszkgligkadlakfwvakqkuggzxwjkvfsglzgfsdatlvhfesoxsoaslwkjwxzwsgdadwffva
Index of Coincidence: 0.064862
brutqw
```
#### Key Output
`brutqw`
##### Actual Key
`brutus`
##### Decipherd Text
```
bepatienttillthelastromanscountrymenandlovershearmeformycauseandbesilentthatyoumayhearbelievemeforminehonourandhaverespecttominehonourthatyoumaybelievecensuremeinyourwisdomandawakeyoursensesthatyoumaythebetterjudgeiftherebeanyinthisassemblyanydearfriendofcaesarstohimisaythatbrutuslovetocaesarwasnolessthanhisifthenthatfrienddemandwhybrutusroseagainstcaesarthisismyanswernotthatilovedcaesarlessbutthatilovedromemorehadyourathercaesarwerelivinganddieallslavesthanthatcaesarweredeadtoliveallfreemenascaesarlovedmeiweepforhimashewasfortunateirejoiceatitashewasvaliantihonourhimbutashewasambitiousislewhimthereistearsforhislovejoyforhisfortunehonourforhisvalouranddeathforhisambitionwhoisheresobasethatwouldbeabondmanifanyspeakforhimhaveioffendedwhoisheresorudethatwouldnotbearomanifanyspeakforhimhaveioffendedwhoisheresovilethatwillnotlovehiscountryifanyspeakforhimhaveioffendedipauseforareplythennonehaveioffendedihavedonenomoretocaesarthanyoushalldotobrutusthequestionofhisdeathisenrolledinthecapitolhisglorynotextenuatedwhereinhewasworthynorhisoffencesenforcedforwhichhesuffereddeathherecomeshisbodymournedbymarkantonywhothoughhehadnohandinhisdeathshallreceivethebenefitofhisdyingaplaceinthecommonwealthaswhichofyoushallnotwiththisidepartthatasislewmybestloverforthegoodofromeihavethesamedaggerformyselfwhenitshallpleasemycountrytoneedmydeath
```
