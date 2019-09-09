//const int N = 5;
const int N = 4;

//densities
Float_t dens[213][3]; //start depth. end depth. density
dens[0][0] = 0; dens[0][1] = 8.05; dens[0][2] = 2.4;
dens[1][0] = 8.05; dens[1][1] = 9; dens[1][2] = 2.4;
dens[2][0] = 9; dens[2][1] = 9.5; dens[2][2] = 2.1;
dens[3][0] = 9.5; dens[3][1] = 10.5; dens[3][2] = 2.4;
dens[4][0] = 10.5; dens[4][1] = 11.7; dens[4][2] = 2.1;
dens[5][0] = 11.7; dens[5][1] = 22.8; dens[5][2] = 2.4;
dens[6][0] = 22.8; dens[6][1] = 23.8; dens[6][2] = 2.55;
dens[7][0] = 23.8; dens[7][1] = 33.3; dens[7][2] = 1.5;
dens[8][0] = 33.3; dens[8][1] = 38.1; dens[8][2] = 1.3;
dens[9][0] = 38.1; dens[9][1] = 41.2; dens[9][2] = 1.6;
dens[10][0] = 41.2; dens[10][1] = 55.5; dens[10][2] = 1.7;
dens[11][0] = 55.5; dens[11][1] = 74.5; dens[11][2] = 1.6;
dens[12][0] = 74.5; dens[12][1] = 79.5; dens[12][2] = 1.8;
dens[13][0] = 79.5; dens[13][1] = 82.7; dens[13][2] = 1.9;
dens[14][0] = 82.7; dens[14][1] = 83.9; dens[14][2] = 1.8;
dens[15][0] = 83.9; dens[15][1] = 84.4; dens[15][2] = 2.43;
dens[16][0] = 84.4; dens[16][1] = 104.2; dens[16][2] = 2.44;
dens[17][0] = 104.2; dens[17][1] = 110; dens[17][2] = 1.4;
dens[18][0] = 110; dens[18][1] = 115.8; dens[18][2] = 1.3;
dens[19][0] = 115.8; dens[19][1] = 126.8; dens[19][2] = 1.25;
dens[20][0] = 126.8; dens[20][1] = 132.55; dens[20][2] = 1.5;
dens[21][0] = 132.55; dens[21][1] = 137.6; dens[21][2] = 1.7;
dens[22][0] = 137.6; dens[22][1] = 141.6; dens[22][2] = 2.5;
dens[23][0] = 141.6; dens[23][1] = 150; dens[23][2] = 2.2;
dens[24][0] = 150; dens[24][1] = 154; dens[24][2] = 2;
dens[25][0] = 154; dens[25][1] = 159.9; dens[25][2] = 1.5;
dens[26][0] = 159.9; dens[26][1] = 173; dens[26][2] = 2;
dens[27][0] = 173; dens[27][1] = 180.6; dens[27][2] = 1.75;
dens[28][0] = 180.6; dens[28][1] = 182; dens[28][2] = 1.6;
dens[29][0] = 182; dens[29][1] = 183.65; dens[29][2] = 1.4;
dens[30][0] = 183.65; dens[30][1] = 185.2; dens[30][2] = 1.65;
dens[31][0] = 185.2; dens[31][1] = 186.1; dens[31][2] = 2.4;
dens[32][0] = 186.1; dens[32][1] = 186.4; dens[32][2] = 2.2; 
dens[33][0] = 186.4; dens[33][1] = 196.6; dens[33][2] = 2.4;
dens[34][0] = 196.6; dens[34][1] = 197.7; dens[34][2] = 2.2;
dens[35][0] = 197.7; dens[35][1] = 199.1; dens[35][2] = 2.5;
dens[36][0] = 199.1; dens[36][1] = 199.6; dens[36][2] = 2.1;
dens[37][0] = 199.6; dens[37][1] = 203.4; dens[37][2] = 2.4;
dens[38][0] = 203.4; dens[38][1] = 204.48; dens[38][2] = 2.65; 
dens[39][0] = 204.48; dens[39][1] = 223; dens[39][2] = 2.35;
dens[40][0] = 223; dens[40][1] = 226.1; dens[40][2] = 2.7;
dens[41][0] = 226.1; dens[41][1] = 230.25; dens[41][2] = 2.65;
dens[42][0] = 230.25; dens[42][1] = 232.4; dens[42][2] = 2.5;
dens[43][0] = 232.4; dens[43][1] = 238.5; dens[43][2] = 2.3;
dens[44][0] = 238.5; dens[44][1] = 240.65; dens[44][2] = 2.1;
dens[45][0] = 240.65; dens[45][1] = 243.7; dens[45][2] = 2.6;
dens[46][0] = 243.7; dens[46][1] = 244.7; dens[46][2] = 2.3;
dens[47][0] = 244.7; dens[47][1] = 247.3; dens[47][2] = 2;
dens[48][0] = 247.3; dens[48][1] = 250; dens[48][2] = 2.2;
dens[49][0] = 250; dens[49][1] = 251; dens[49][2] = 2.6;
dens[50][0] = 251; dens[50][1] = 253; dens[50][2] = 2.6;
dens[51][0] = 253; dens[51][1] = 254; dens[51][2] = 2.6;
dens[52][0] = 254; dens[52][1] = 256.8; dens[52][2] = 2.4;
dens[53][0] = 256.8; dens[53][1] = 258.1; dens[53][2] = 2.6;
dens[54][0] = 258.1; dens[54][1] = 260.3; dens[54][2] = 2.4;
dens[55][0] = 260.3; dens[55][1] = 261.7; dens[55][2] = 2.6;
dens[56][0] = 261.7; dens[56][1] = 264.4; dens[56][2] = 2.6;
dens[57][0] = 264.4; dens[57][1] = 268.1; dens[57][2] = 2.5;
dens[58][0] = 268.1 ; dens[58][1] = 269.45; dens[58][2] = 2.6;
dens[59][0] = 269.45; dens[59][1] = 271.55; dens[59][2] = 2.5;
dens[60][0] = 271.55; dens[60][1] = 274.9; dens[60][2] = 2.2;
dens[61][0] = 274.9; dens[61][1] = 278.15; dens[61][2] = 2.6;
dens[62][0] = 278.15; dens[62][1] = 280.7; dens[62][2] = 2.5;
dens[63][0] = 280.7; dens[63][1] = 288.75; dens[63][2] = 2.6;
dens[64][0] = 288.75; dens[64][1] = 292.1; dens[64][2] = 2.5;
dens[65][0] = 292.1; dens[65][1] = 294.5; dens[65][2] = 2.6;
dens[66][0] = 294.5; dens[66][1] = 300; dens[66][2] = 2.5;
dens[67][0] = 300; dens[67][1] = 301.25; dens[67][2] = 2.6;
dens[68][0] = 301.25; dens[68][1] = 302.15; dens[68][2] = 2.4;
dens[69][0] = 302.15; dens[69][1] = 303.45; dens[69][2] = 2.65;
dens[70][0] = 303.45; dens[70][1] = 304; dens[70][2] = 2.50;
dens[71][0] = 304; dens[71][1] =307.6; dens[71][2] = 2.65;
dens[72][0] = 307.6; dens[72][1] = 308.75; dens[72][2] = 2.4;
dens[73][0] = 308.75; dens[73][1] = 316.3; dens[73][2] = 2.55;
dens[74][0] = 316.3; dens[74][1] = 317.6; dens[74][2] = 2.45;
dens[75][0] = 317.6; dens[75][1] = 322.75; dens[75][2] = 2.65;
dens[76][0] = 322.75; dens[76][1] = 323.35; dens[76][2] = 2.6;
dens[77][0] = 323.35; dens[77][1] = 330; dens[77][2] = 2.65;
dens[78][0] = 330; dens[78][1] = 330.5; dens[78][2] = 2.6;
dens[79][0] = 330.5; dens[79][1] = 337.9; dens[79][2] = 2.65;
dens[80][0] = 337.9; dens[80][1] = 338.3; dens[80][2] = 2.6;
dens[81][0] = 338.3; dens[81][1] = 340.8; dens[81][2] = 2.65;
dens[82][0] = 340.8; dens[82][1] = 341.3; dens[82][2] = 2.6;
dens[83][0] = 341.3; dens[83][1] = 345; dens[83][2] = 2.65;
dens[84][0] = 345; dens[84][1] = 346; dens[84][2] = 1.4;
dens[85][0] = 346; dens[85][1] = 360.45; dens[85][2] = 2.65;
dens[86][0] = 360.45; dens[86][1] = 364.7; dens[86][2] = 2.6;
dens[87][0] = 364.7; dens[87][1] = 365.6; dens[87][2] = 2.3;
dens[88][0] = 365.6; dens[88][1] = 366.35; dens[88][2] = 2.6;
dens[89][0] = 366.35; dens[89][1] = 367.1; dens[89][2] = 1.8;
dens[90][0] = 367.1; dens[90][1] = 370.05; dens[90][2] = 2.35;
dens[91][0] = 370.05; dens[91][1] = 370.4; dens[91][2] = 2;
dens[92][0] = 370.4; dens[92][1] = 371.05; dens[92][2] = 2.6;
dens[93][0] = 371.05; dens[93][1] = 375.5; dens[93][2] = 2.65;
dens[94][0] = 375.5; dens[94][1] = 377.65; dens[94][2] = 2.65;
dens[95][0] = 377.65; dens[95][1] = 379.8; dens[95][2] = 2.55;
dens[96][0] = 379.8; dens[96][1] = 381.05; dens[96][2] = 2.2;
dens[97][0] = 381.05; dens[97][1] = 382.45; dens[97][2] = 2.5;
dens[98][0] = 382.45; dens[98][1] = 383.4; dens[98][2] = 2.1;
dens[99][0] = 383.4; dens[99][1] = 385.1; dens[99][2] = 2.6;
dens[100][0] = 385.1; dens[100][1] = 385.5; dens[100][2] = 2.7;
dens[101][0] = 385.5; dens[101][1] = 386.15; dens[101][2] = 2.6;
dens[102][0] = 386.15; dens[102][1] = 387; dens[102][2] = 2.7;
dens[103][0] = 387; dens[103][1] =389; dens[103][2] = 2.6;
dens[104][0] = 389; dens[104][1] = 393.85; dens[104][2] = 2.7;
dens[105][0] = 393.85; dens[105][1] = 394.7; dens[105][2] = 2.6;
dens[106][0] = 394.7; dens[106][1] = 398; dens[106][2] = 2.1;
dens[107][0] = 398; dens[107][1] = 398.7; dens[107][2] = 2.7;
dens[108][0] = 398.7; dens[108][1] = 401.2; dens[108][2] = 2.2;
dens[109][0] = 401.2; dens[109][1] = 402.55; dens[109][2] = 2.6;
dens[110][0] = 402.55; dens[110][1] = 402.75; dens[110][2] = 1.3;
dens[111][0] = 402.75; dens[111][1] = 407.6; dens[111][2] = 2;
dens[112][0] = 407.6; dens[112][1] = 415.7; dens[112][2] = 2.1;
dens[113][0] = 415.7; dens[113][1] = 416.8; dens[113][2] = 2.6;
dens[114][0] = 416.8; dens[114][1] = 417.8; dens[114][2] = 2;
dens[115][0] = 417.8; dens[115][1] =420.1; dens[115][2] = 2.6;
dens[116][0] = 420.1; dens[116][1] = 422.9; dens[116][2] = 2.2;
dens[117][0] = 422.9; dens[117][1] = 425.3; dens[117][2] = 2.6;
dens[118][0] = 425.3; dens[118][1] = 429; dens[118][2] = 2.2;
dens[119][0] = 429; dens[119][1] = 429.8; dens[119][2] = 2.65;
dens[120][0] = 429.8; dens[120][1] = 433.75; dens[120][2] = 2.2;
dens[121][0] = 433.75; dens[121][1] = 434.15; dens[121][2] = 2.65;
dens[122][0] = 434.15; dens[122][1] = 434.4; dens[122][2] = 2.2;
dens[123][0] = 434.4; dens[123][1] = 437.15; dens[123][2] = 2.2;
dens[124][0] = 437.15; dens[124][1] = 437.5; dens[124][2] = 2.6;
dens[125][0] = 437.5; dens[125][1] = 441.2; dens[125][2] = 2.2;
dens[126][0] = 441.2; dens[126][1] = 446.25; dens[126][2] = 2.6;
dens[127][0] = 446.25; dens[127][1] = 448.05; dens[127][2] = 2.3;
dens[128][0] = 448.05; dens[128][1] = 451; dens[128][2] = 2;
dens[129][0] = 451; dens[129][1] = 451.6; dens[129][2] = 2.6;
dens[130][0] = 451.6; dens[130][1] = 451.9; dens[130][2] = 2;
dens[131][0] = 451.9; dens[131][1] = 453.95; dens[131][2] = 2.2;
dens[132][0] = 453.95; dens[132][1] = 454.25; dens[132][2] = 2.6;
dens[133][0] = 454.25; dens[133][1] = 455; dens[133][2] = 2.2;
dens[134][0] = 455; dens[134][1] = 459.5; dens[134][2] = 2;
dens[135][0] = 459.5; dens[135][1] = 459.8; dens[135][2] = 2;
dens[136][0] = 459.8; dens[136][1] = 460.2; dens[136][2] = 1.5;
dens[137][0] = 460.2; dens[137][1] = 461.5; dens[137][2] = 2.6;
dens[138][0] = 461.5; dens[138][1] = 463.1; dens[138][2] = 2;
dens[139][0] = 463.1; dens[139][1] = 463.4; dens[139][2] = 1.5;
dens[140][0] = 463.4; dens[140][1] = 464.3; dens[140][2] = 2;
dens[141][0] = 464.3; dens[141][1] = 465; dens[141][2] = 2.4;
dens[142][0] = 465; dens[142][1] =466.2; dens[142][2] = 2.1;
dens[143][0] = 466.2; dens[143][1] = 466.45; dens[143][2] = 2.6;
dens[144][0] = 466.45; dens[144][1] = 467.6; dens[144][2] = 2.1;
dens[145][0] = 467.6; dens[145][1] = 468.45; dens[145][2] = 2.6;
dens[146][0] = 468.45; dens[146][1] = 470.8; dens[146][2] = 2.1;
dens[147][0] = 470.8; dens[147][1] = 471.8; dens[147][2] = 2.6;
dens[148][0] = 471.8; dens[148][1] = 474; dens[148][2] = 2.1;
dens[149][0] = 474; dens[149][1] = 475.1; dens[149][2] = 2;
dens[150][0] = 475.1; dens[150][1] = 478.9; dens[150][2] =2.1;
dens[151][0] = 478.9; dens[151][1] = 479.1; dens[151][2] = 1.4;
dens[152][0] = 479.1; dens[152][1] = 479.2; dens[152][2] = 2.1;
dens[153][0] = 479.2; dens[153][1] = 479.3; dens[153][2] = 1.4;
dens[154][0] = 479.3; dens[154][1] = 479.55; dens[154][2] = 2.1;
dens[155][0] = 479.55; dens[155][1] = 479.65; dens[155][2] = 1.4;
dens[156][0] = 479.65; dens[156][1] = 479.85; dens[156][2] = 2.1;
dens[157][0] = 479.85; dens[157][1] = 480.3; dens[157][2] = 1.4;
dens[158][0] = 480.3; dens[158][1] = 480.55; dens[158][2] = 2.1;
dens[159][0] = 480.55; dens[159][1] = 481.65; dens[159][2] = 1.35;
dens[160][0] = 481.65; dens[160][1] = 482.4; dens[160][2] = 2.1;
dens[161][0] = 482.4; dens[161][1] = 482.6; dens[161][2] = 1.35;
dens[162][0] = 482.6; dens[162][1] = 483.05; dens[162][2] = 2.15;
dens[163][0] = 483.05; dens[163][1] = 483.5; dens[163][2] = 1.7;
dens[164][0] = 483.5; dens[164][1] = 485.45; dens[164][2] = 2.35;
dens[165][0] = 485.45; dens[165][1] = 485.65; dens[165][2] = 1.3;
dens[166][0] = 485.65; dens[166][1] = 486.25; dens[166][2] = 2.7;
dens[167][0] = 486.25; dens[167][1] = 487.45; dens[167][2] = 2.1;
dens[168][0] = 487.45; dens[168][1] = 487.8; dens[168][2] = 1.35;
dens[169][0] = 487.8; dens[169][1] = 488.5; dens[169][2] = 2.7;
dens[170][0] = 488.5; dens[170][1] = 488.65; dens[170][2] = 1.4;
dens[171][0] = 488.65; dens[171][1] = 488.8; dens[171][2] = 2.6;
dens[172][0] = 488.8; dens[172][1] = 488.95; dens[172][2] = 1.4;
dens[173][0] = 488.95; dens[173][1] = 489.15; dens[173][2] = 2.7;
dens[174][0] = 489.15; dens[174][1] = 489.65; dens[174][2] = 2;
dens[175][0] = 489.65; dens[175][1] = 489.85; dens[174][2] = 2.6;
dens[176][0] = 489.85; dens[176][1] = 490.65; dens[176][2] = 2;
dens[177][0] = 490.65; dens[177][1] = 492.65; dens[177][2] = 1.35;
dens[178][0] = 492.65; dens[178][1] = 493.05; dens[178][2] = 2.5;
dens[179][0] = 493.05; dens[179][1] = 493.25; dens[179][2] = 1.35;
dens[180][0] = 493.25; dens[180][1] = 494.35; dens[180][2] = 2.2;
dens[181][0] = 494.35; dens[181][1] = 494.75; dens[181][2] = 1.35;
dens[182][0] = 494.75; dens[182][1] = 495.15; dens[182][2] = 2.6;
dens[183][0] = 495.15; dens[183][1] = 498; dens[183][2] = 1.3;
dens[184][0] = 498; dens[184][1] = 498.25; dens[184][2] = 2;
dens[185][0] = 498.25; dens[185][1] = 499.25; dens[185][2] = 1.35;
dens[186][0] = 499.25; dens[186][1] = 499.65; dens[186][2] = 2.4;
dens[187][0] = 499.65; dens[187][1] = 500.5; dens[187][2] = 1.5;
dens[188][0] = 500.5; dens[188][1] = 501.1; dens[188][2] = 2;
dens[189][0] = 501.1; dens[189][1] = 501.4; dens[189][2] = 1.5;
dens[190][0] = 501.4; dens[190][1] = 502.65; dens[190][2] = 2;
dens[191][0] = 502.65; dens[191][1] = 503.4; dens[191][2] = 1.4;
dens[192][0] = 503.4; dens[192][1] = 503.7; dens[192][2] = 2.4;
dens[193][0] = 503.7; dens[193][1] = 504.3; dens[193][2] = 1.4;
dens[194][0] = 504.3; dens[194][1] = 504.65; dens[194][2] = 2;
dens[195][0] = 504.65; dens[195][1] = 504.75; dens[195][2] = 1.4;
dens[196][0] = 504.75; dens[196][1] = 505.05; dens[196][2] = 2;
dens[197][0] = 505.05; dens[197][1] = 505.8; dens[197][2] = 1.4;
dens[198][0] = 505.8; dens[198][1] = 506.1; dens[198][2] = 2;
dens[199][0] = 506.1; dens[199][1] = 506.95; dens[199][2] = 1.4;
dens[200][0] = 506.95; dens[200][1] = 507.6; dens[200][2] = 2;
dens[201][0] = 507.6; dens[201][1] = 508.6; dens[201][2] = 2.4;
dens[202][0] = 508.6; dens[202][1] = 509.75; dens[202][2] = 2.4;
dens[203][0] = 509.75; dens[203][1] = 511.3; dens[203][2] = 1.5;
dens[204][0] = 511.3; dens[204][1] = 512.15; dens[204][2] = 1.35;
dens[205][0] = 512.15; dens[205][1] = 513.2; dens[205][2] = 2.6;
dens[206][0] = 513.2; dens[206][1] = 513.95; dens[206][2] = 1.5;
dens[207][0] = 513.95; dens[207][1] = 515.25; dens[207][2] = 2;
dens[208][0] = 515.25; dens[208][1] = 517.25; dens[208][2] = 1.5;
dens[209][0] = 517.25; dens[209][1] = 518.2; dens[209][2] = 2.2;
dens[210][0] = 518.2; dens[210][1] = 518.95; dens[210][2] = 2.3;
dens[211][0] = 518.95; dens[211][1] = 520.05; dens[211][2] = 2.6;
dens[212][0] = 520.05; dens[212][1] = 524.2; dens[212][2] = 2.3;


/*Float_t dens[100][3]; //start depth, end depth, density
dens[0][0] = 0; dens[0][1] = 24.8; dens[0][2] = 1.45;
dens[1][0] = 24.8; dens[1][1] = 83.8; dens[1][2] = 2.2;
dens[2][0] = 83.8; dens[2][1] = 104.2; dens[2][2] = 2.45;
dens[3][0] = 104.2; dens[3][1] = 137.6; dens[3][2] = 2.3;
dens[4][0] = 137.6; dens[4][1] = 141.6; dens[4][2] = 2.5;
dens[5][0] = 141.6; dens[5][1] = 154; dens[5][2] = 2.1;
dens[6][0] = 154; dens[6][1] = 159.9; dens[6][2] = 2.3;
dens[7][0] = 159.9; dens[7][1] = 182; dens[7][2] = 2.5;
dens[8][0] = 182; dens[8][1] = 185.2; dens[8][2] = 2.3;
dens[9][0] = 185.2; dens[9][1] = 186.4; dens[9][2] = 2.2;
dens[10][0] = 186.4; dens[10][1] = 197.7; dens[10][2] = 2.1;
dens[11][0] = 197.7; dens[11][1] = 232.4; dens[11][2] = 2.3;
dens[12][0] = 232.4; dens[12][1] = 238.5; dens[12][2] = 2.2;
dens[13][0] = 238.5; dens[13][1] = 244.7; dens[13][2] = 2.3;
dens[14][0] = 244.7; dens[14][1] = 250; dens[14][2] = 2.2;
dens[15][0] = 250; dens[15][1] = 271.55; dens[15][2] = 2.3;
dens[16][0] = 271.55; dens[16][1] = 274.9; dens[16][2] = 2.5;
dens[17][0] = 274.9; dens[17][1] = 394.7; dens[17][2] = 2.4;
dens[18][0] = 394.7; dens[18][1] = 1000; dens[18][2] = 1.56;
*/
//
/*dens[18][0] = 394.7; dens[18][1] = 402.55; dens[18][2] = 0; //argilla grigio scura da tenera a leggermente dura, passaggi carboniosi più soffici e sfatti
dens[19][0] = 402.55; dens[19][1] = 402.75; dens[19][2] = 0; //livelletto di carbone
dens[20][0] = 402.75; dens[20][1] = 407.6; dens[20][2] = 0; //argilla nera molto carboniosa, soffice e sfatta
dens[21][0] = 407.6; dens[21][1] = 415.7; dens[21][2] = 0; //argilla grigia generalmente sfatta con passaggi leggermente più duri. La roccia è debolmente carbonatica
dens[22][0] = 415.7; dens[22][1] = 420.1; dens[22][2] = 0; //siltite grigia abbastanza dura e scheggiosa a componente carbonatica. Fratture riempite da calcite a 30 - 45 deg dall'asse. Argilla drigia da 416.8 - 417.8
dens[23][0] = 420.1; dens[23][1] = 422.9; dens[23][2] = 0; //argilla da grigio a grigio scura, leggermente calcarea e discretamente fratturata (frattura a riempimento calcitico)
dens[24][0] = 422.9; dens[24][1] = 425.3; dens[24][2] = 0; //slitite grigia, passante ad arenaria a grana fine e cemento carbonatico, dura e con frattura variamente orientate e riempite da calcite
dens[25][0] = 425.3; dens[25][1] = 434.4; dens[25][2] = 0; //argilla grigia, grigio scura a tratti completamente sfatta, altri abbastanza omogenei, livelletti siltitici e arenacei da mt. 429 - 429.8 / 433.75 - 434.15
dens[26][0] = 434.4; dens[26][1] = 441.2; dens[26][2] = 0; // argille variegate, abbastanza soffici e plastiche con passaggi ad argilla grigia abbastanza calcarea. Siltite compatta da mt. 437.15 - 437.5.
dens[27][0] = 441.2; dens[27][1] = 446.25; dens[27][2] = 0; //arenaria grigia a grana medio fine a cemento carbonatico. Numerose fratture sub-parallela all'asse, riempite da calcite. Roccia sana e compatta
dens[28][0] = 446.25; dens[28][1] = 448.05; dens[28][2] = 0; //conglomerato poligemico ad elementi minuti nella parte iniziale, poi più grossi nella parte bassa. Fratture a 10 - 20 deg dall'asse.
dens[29][0] = 448.05; dens[29][1] = 451.9; dens[29][2] = 0; // argilla grigia a componente calcarea abbastanza fratturata, con passaggi più scuri, carbonosi molto fratturati. Arenaria fine da mt, 451 - 456.6
dens[30][0] = 451.9; dens[30][1] = 455; dens[30][2] = 0; //arglla nera molto soffice e frantumata con livelletto di siltite da mt 453.95 - 454.25. Passaggi leggermente più chiari; calcare.
dens[31][0] = 455; dens[31][1] = 459.5; dens[31][2] = 0; //argilla grigia, soffice e frantumata, con brevi passaggi più duri. Presente la componente carbonatica
dens[32][0] = 459.5; dens[32][1] = 460.2; dens[32][2] = 0; //argilla carboniosa con livelletto di carbone impuro da MT 459.8 - 460.2
dens[33][0] = 460.2; dens[33][1] = 461.5; dens[33][2] = 0; //arenaria fine talvolta siltite a cemento carbonatico. Grossa frattura a 45 deg riempita da argilla sfatta a mt 460.5.
dens[34][0] = 461.5; dens[34][1] = 464.3; dens[34][2] = 0; //argilla grigia completamente frantumata nei primi 70 cm, poi sana, coarboniosa, livelletto di carbone a mt. 463.10 - 463.40
dens[35][0] = 464.3; dens[35][1] = 477.85; dens[35][2] = 0; //argilla grigia completamente fratturata con passaggi più scuri. Livelletti siltitici da mt 466.20 - 466.45 / 467.7 - 468.45 / 470.8 - 471.8
dens[36][0] = 477.85; dens[36][1] = 482.5; dens[36][2] = 0; //argilla nera, molto soffice frantumata con livelletti di carbone da mt 478.9 - 479.1 / 479.2 - 479.3 / 479.55 - 479.65 / 479.85 - 480.3 / 480.55 - 481.65 / 482.4 - 482.5 e livelletto di calcare da mt 480.3 - 480.55
dens[37][0] = 482.5; dens[37][1] = 483.05; dens[37][2] = 0; //calcare beige abbastanza duro e compatto con sottilissime venature carboniose e calcitiche variamente orientate. Da mt 482.4 - 482.55 carbone.
dens[38][0] = 483.05; dens[38][1] = 483.5; dens[38][2] = 0; //carbone con livelletto di argilla nera carb. da 483.8 - 483.4
dens[39][0] = 483.5; dens[39][1] = 485.45; dens[39][2] = 0; //Siltite duro e compatto con sottilissime venature carboniose e calcitiche variamente orientate. Da mt 482.4 - 482.55 carbone
dens[40][0] = 485.45; dens[40][1] = 485.65; dens[40][2] = 0; //carbone
dens[41][0] = 485.65; dens[41][1] = 486.25; dens[41][2] = 0; //calcare beige abbastanza duro con venature di calcite variamente orientate
dens[42][0] = 486.25; dens[42][1] = 487.45; dens[42][2] = 0; //argilla grigia - grigio scura abbastanza tenera con qualche passaggio marmoso più duro
dens[43][0] = 487.45; dens[43][1] = 487.8; dens[43][2] = 0; //carbone
dens[44][0] = 487.8; dens[44][1] = 488.5; dens[44][2] = 0; //calcare beige mediamente duro a tratti fratturato
dens[45][0] = 488.5; dens[45][1] = 488.65; dens[45][2] = 0; //carbone
dens[46][0] = 488.65; dens[46][1] = 489.15; dens[46][2] = 0; //siltite grigia, dura, con livelletto di carbone da mt. 488.8 - 488.95
dens[47][0] = 489.15; dens[47][1] = 490.65; dens[47][2] = 0; //argilla grigia - grigio scura, tenera e plastica sfogliettata, con qualche passaggio ad argilla lera corboniosa, livelletto di calcare arenaceo a mt. 489.65 - 489.85
dens[48][0] = 490.65; dens[48][1] = 492.65; dens[48][2] = 0; //carbone
dens[49][0] = 492.65; dens[49][1] = 493.05; dens[49][2] = 0; //calcare beige
dens[50][0] = 493.05; dens[50][1] = 493.25; dens[50][2] = 0; //carbone
dens[51][0] = 493.25; dens[51][1] = 494.35; dens[51][2] = 0; //argilla grigio-scura da leggermente dura a tenera con piani di frattura a 20-30 deg dall'asse talora a riempimento calcitico. Numerosi inclusi siltitici
dens[52][0] = 494.35; dens[52][1] = 494.75; dens[52][2] = 0; //carbone
dens[53][0] = 494.75; dens[53][1] = 495.15; dens[53][2] = 0; //misto di calcare beige e liltite a cemento carbonatico
dens[54][0] = 495.15; dens[54][1] = 498.0; dens[54][2] = 0; //carbone
dens[55][0] = 498.0; dens[55][1] = 495.25; dens[55][2] = 0; //breccia intraformazionale con elemento di arenaria fine. Calcare beige
dens[56][0] = 498.25; dens[56][1] = 499.25; dens[56][2] = 0; //carbone
dens[57][0] = 499.25; dens[57][1] = 499.65; dens[57][2] = 0; //calcare beige molto frattura con inclusi carboniosi di grosse dimensioni
dens[58][0] = 499.65; dens[58][1] = 501.4; dens[58][2] = 0; //carbone con livello di argilla grigio nerastra da mt 500.5 - 501.1
dens[59][0] = 501.4; dens[59][1] = 502.65; dens[59][2] = 0; //argilla nera carboniosa
dens[60][0] = 502.65; dens[60][1] = 503.4; dens[60][2] = 0; //carbone
dens[61][0] = 503.4; dens[61][1] = 503.7; dens[61][2] = 0; //calcare beige con grossi inclusi carboniosi abbastanza duro
dens[62][0] = 503.7; dens[62][1] = 506.95; dens[62][2] = 0; //carbone con livelletti di argilla nera carboniosa da mt. 504.3 - 504.65 / 504.75 - 505.05 / 505.8 - 506.1
dens[63][0] = 506.95; dens[63][1] = 507.6; dens[63][2] = 0; //argilla grigio-scura talvolta nerastra completamente frantumata e soffice
dens[64][0] = 507.6; dens[64][1] = 508.6; dens[64][2] = 0; //calcare beige con numerose venature calcitiche, molto fratturato
dens[65][0] = 508.6; dens[65][1] = 509.75; dens[65][2] = 0; //carbone talora argilloso
dens[66][0] = 509.75; dens[66][1] = 511.3; dens[66][2] = 0; //calcare beige abbastanza compatto con regolari fratture trasversali all'asse del sondaggio
dens[67][0] = 511.3; dens[67][1] = 512.5; dens[67][2] = 0; //carbone
dens[68][0] = 512.5; dens[68][1] = 513.2; dens[68][2] = 0; //calcare beige con grosse fratture sub-parallele all'asse generalmente riempite da calcite
dens[69][0] = 513.2; dens[69][1] = 513.95; dens[69][2] = 0; //carbone con livelletto di argilla nera da mt. 513.25 - 513.45
dens[70][0] = 513.95; dens[60][1] = 515.25; dens[70][2] = 0; //argilla nera carboniosa con livelletto di carbone da mt. 514.85 - 515.15
*/


Float_t calc_density(Float_t depth);
  
void rate_depth()
{
  //Float_t depth[N] = {0, 174, 250, 339, 512};
  Float_t depth[N] = {0, 174, 339, 512};
  //Float_t rate[N] = {3.80, 0.0055, 0.0011006, 0.00078351228367}; //from n/T
  Float_t rate[N] = {3.831, 0.00542, 0.001131, 0.0007783}; //from fit
  Float_t rate_err[N] = {0.04, 0.0001, 0.00004,  0.000012};
  Float_t depth_err[N] = {0, 5, 5, 5};
  Float_t density[N];// = {1, 2.2126, 2.0619, 1.8923};//2.00825}; //density on 339->512 1.67 or 1.56
  Float_t depth_mwe[N];
  
  Float_t Astro_rate[N] = {8.618, 0.01257, 0.002556, 0.001835};
  Float_t Astro_err[N] = {.007, .00013, 0.00003, 0.00002};

  Float_t rate_suppr[N];
  Float_t rate_suppr_err[N];
  Float_t rate_norm[N];
  Float_t rate_norm_err[N];
  Float_t Astro_rate_suppr[N];
  Float_t Astro_rate_norm[N];
  Float_t Astro_norm_err[N];
  Float_t Astro_suppr_err[N];

  cout << endl << endl ;
  for(int i = 0; i < N; i++)
    {
      if(depth[i] > 0) density[i] = calc_density(depth[i]);
      else density[i] = 1;
      //cout << endl << endl << density[i] << endl << endl;
      
      depth_mwe[i] = depth[i]*density[i];
      
      rate_suppr[i] = rate[0]/rate[i];
      rate_suppr_err[i] = pow(pow(rate[0]*rate_err[i], 2) + pow(rate[i]*rate_err[0], 2), 0.5) / rate[i];
      rate_norm[i] = rate[i]/rate[0];
      rate_norm_err[i] = pow(pow(rate[0]*rate_err[i], 2) + pow(rate[i]*rate_err[0], 2), 0.5) / rate[0];

      Astro_rate_suppr[i] = Astro_rate[0]/Astro_rate[i];
      Astro_suppr_err[i] = pow(pow(Astro_rate[0]*Astro_err[i], 2) + pow(Astro_rate[i]*Astro_err[0], 2), 0.5) / Astro_rate[i];
      Astro_rate_norm[i] = Astro_rate[i]/Astro_rate[0];
      Astro_norm_err[i] = pow(pow(Astro_rate[0]*Astro_err[i], 2) + pow(Astro_rate[i]*Astro_err[0], 2), 0.5) / Astro_rate[0];

      //cout << std::setprecision(10) << depth_mwe[i] << "  " << rate_norm[i] << "   " << rate_norm_err[i] << "  -  " << Astro_rate_norm[i] << "   " << Astro_rate_norm[i] - rate_norm[i] << endl;

      cout << depth[i] << "   " << depth_mwe[i] << "   " << rate_norm[i] << " +/- " << rate_norm_err[i] << "   " << Astro_rate_norm[i] << " +/- " << Astro_norm_err[i] << endl;
    }
  cout << endl << endl;
  
  TGraphErrors *rate_depth = new TGraphErrors(N, depth, rate, depth_err, rate_err);
  TGraphErrors *rate_depth_suppr = new TGraphErrors(N, depth, rate_suppr, depth_err, rate_suppr_err);
  TGraphErrors *rate_depth_norm = new TGraphErrors(N, depth, rate_norm, depth_err, rate_norm_err);

  TGraphErrors *Astro_rate_depth = new TGraphErrors(N, depth, Astro_rate, depth_err, Astro_err);
  TGraphErrors *Astro_rate_depth_suppr = new TGraphErrors(N, depth, Astro_rate_suppr, depth_err, Astro_suppr_err);
  TGraphErrors *Astro_rate_depth_norm = new TGraphErrors(N, depth, Astro_rate_norm, depth_err, Astro_norm_err);
  
  rate_depth->SetMarkerStyle(21);
  rate_depth_suppr->SetMarkerStyle(21);
  rate_depth_norm->SetMarkerStyle(21);

  Astro_rate_depth->SetMarkerColor(kRed);
  Astro_rate_depth_suppr->SetMarkerColor(kRed);
  Astro_rate_depth_norm->SetMarkerColor(kRed);
  
  rate_depth->SetTitle("Measured rate w.r.t. rock overburden;Rock overburden [m];Measured rate [Hz]");
  rate_depth_suppr->SetTitle("Rate suppression w.r.t. rock overburden;Rock overburden [m];Rate suppression #(){#frac{R(ground level)}{R(rock overburden)}}");
  rate_depth_norm->SetTitle("Measured rate normalized to the ground level w.r.t. rock overburden;Rock overburden [m];Normalized rate");  

  
  TLatex *pre = new TLatex(0.6,0.85,"Preliminary");
  pre->SetTextSize(0.05*1.2);
  pre->SetTextFont(42);
  pre->SetTextColor(kRed);
  pre->SetNDC(1);
  pre->SetTextAlign(13);

  TLegend *leg = new TLegend(0.6,0.6,0.85,0.4);
  leg->AddEntry(rate_depth,"Cosmic Box", "p");
  leg->AddEntry(Astro_rate_depth,"Astro", "p");  
  
  
  TCanvas *c1 = new TCanvas();
  c1->SetLogy();
  c1->SetGridx();
  c1->SetGridy();
  rate_depth->Draw("AP");
  rate_depth->GetHistogram()->SetMaximum(10);
  rate_depth->GetHistogram()->SetMinimum(1e-4);
  rate_depth->GetXaxis()->SetLimits(-50,600);
  //pre->Draw("SAME");
  Astro_rate_depth->Draw("P*SAME");
  leg->Draw("SAME");
  c1->Update();

  TCanvas *c2 = new TCanvas();
  rate_depth_suppr->Draw("AP");
  c2->SetLogy();
  c2->SetGridx();
  c2->SetGridy();
  rate_depth_suppr->GetHistogram()->SetMaximum(1e5);
  rate_depth_suppr->GetHistogram()->SetMinimum(1e-1);
  rate_depth_suppr->GetYaxis()->SetTitleOffset(1.28);
  rate_depth_suppr->GetXaxis()->SetLimits(-50,600);
  //pre->Draw("SAME");
  Astro_rate_depth_suppr->Draw("P*SAME");
  leg->Draw("SAME");
  c2->Update();

  TCanvas *c3 = new TCanvas();
  rate_depth_norm->Draw("AP");
  c3->SetLogy();
  c3->SetGridx();
  c3->SetGridy();
  rate_depth_norm->GetHistogram()->SetMaximum(5);
  rate_depth_norm->GetHistogram()->SetMinimum(1e-5);
  rate_depth_norm->GetXaxis()->SetLimits(-50,600);
  //pre->Draw("SAME");
  Astro_rate_depth_norm->Draw("P*SAME");
  leg->Draw("SAME");
  c3->Update();

  TF1 *flux = new TF1("flux", "[0] * (([1]/x)**[2]) * exp(-x/[1])", 0, 5000);


  //correzione dell'accettanza a varie profondità profondità

  /*Double_t correction[N];
  correction[0] = 1.;
  correction[1] = .81/.79;
  correction[2] = 1.;
  correction[3] = .73/.79;
  */
  //for(int i = 0; i < N; i++)  rate_norm_err[i] *= 3.;//*= correction[i];
  
  

  TCanvas *c4 = new TCanvas();
  c4->SetLogy();
  c4->SetGridx();
  c4->SetGridy();
  TGraphErrors *norm_mwe = new TGraphErrors(N, depth_mwe, rate_norm, 0, rate_norm_err);
  norm_mwe->SetMarkerStyle(8);
  norm_mwe->SetTitle("Normalized rate w.r.t. depth (m.w.e.);Depth (m.w.e.);Normalized rate");
  norm_mwe->GetHistogram()->SetMaximum(5);
  norm_mwe->GetHistogram()->SetMinimum(1e-5);
  norm_mwe->GetXaxis()->SetLimits(-50, 1200);
  norm_mwe->Draw("AP");

  TF1 *flux = new TF1("flux", "[0] * (([1]/x)**[2]) * exp(-x/[1])", 100, 5000);
  flux->SetParameters(0.025/180, 1330, 2.18);
  flux->Draw("SAME");
  pre->Draw("SAME");

  TLegend *leg2 = new TLegend(0.6,0.6,0.85,0.4);
  leg2->AddEntry(norm_mwe,"Cosmic Box", "p");
  leg2->AddEntry(flux,"Pyhasalmi mine data", "l");  
  leg2->Draw("SAME");
  
  c1->SaveAs("./graphs/rate.png");
  c2->SaveAs("./graphs/rate_suppr.png");
  c3->SaveAs("./graphs/rate_norm.png");
}


Float_t calc_density(Float_t depth)
{
  Float_t density = 0;
  int i = 0;
  
  while(depth >= dens[i][1])
    {
      //if(i > 16) break;
      density += dens[i][2] * (dens[i][1] - dens[i][0]);
      i++;
    }
  density += dens[i][2] * (depth - dens[i][0]);
  density /= depth;

  
  return density;
}
