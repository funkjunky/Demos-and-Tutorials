/* A Bison parser, made from vrmlpars.y
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

#define yyparse Vrmlparse
#define yylex Vrmllex
#define yyerror Vrmlerror
#define yylval Vrmllval
#define yychar Vrmlchar
#define yydebug Vrmldebug
#define yynerrs Vrmlnerrs
# define	TRUEFALSE	257
# define	NUMBER	258
# define	AFLOAT	259
# define	STRING	260
# define	NAME	261
# define	ANCHOR	262
# define	APPEARANCE	263
# define	AUDIOCLIP	264
# define	BACKGROUND	265
# define	BILLBOARD	266
# define	BOX	267
# define	COLLISION	268
# define	COLOR	269
# define	COLOR_INTERP	270
# define	COORDINATE	271
# define	COORDINATE_INTERP	272
# define	CYLINDER_SENSOR	273
# define	NULL_STRING	274
# define	CONE	275
# define	CUBE	276
# define	CYLINDER	277
# define	DIRECTIONALLIGHT	278
# define	FONTSTYLE	279
# define	AERROR	280
# define	EXTRUSION	281
# define	ELEVATION_GRID	282
# define	FOG	283
# define	INLINE	284
# define	MOVIE_TEXTURE	285
# define	NAVIGATION_INFO	286
# define	PIXEL_TEXTURE	287
# define	GROUP	288
# define	INDEXEDFACESET	289
# define	INDEXEDLINESET	290
# define	S_INFO	291
# define	LOD	292
# define	MATERIAL	293
# define	NORMAL	294
# define	POSITION_INTERP	295
# define	PROXIMITY_SENSOR	296
# define	SCALAR_INTERP	297
# define	SCRIPT	298
# define	SHAPE	299
# define	SOUND	300
# define	SPOTLIGHT	301
# define	SPHERE_SENSOR	302
# define	ATEXT	303
# define	TEXTURE_COORDINATE	304
# define	TEXTURE_TRANSFORM	305
# define	TIME_SENSOR	306
# define	SWITCH	307
# define	TOUCH_SENSOR	308
# define	VIEWPOINT	309
# define	VISIBILITY_SENSOR	310
# define	WORLD_INFO	311
# define	NORMAL_INTERP	312
# define	ORIENTATION_INTERP	313
# define	POINTLIGHT	314
# define	POINTSET	315
# define	SPHERE	316
# define	PLANE_SENSOR	317
# define	TRANSFORM	318
# define	DEF	319
# define	USE	320
# define	PROTO	321
# define	ROUTE	322
# define	S_CHILDREN	323
# define	S_PARAMETER	324
# define	S_URL	325
# define	S_MATERIAL	326
# define	S_TEXTURETRANSFORM	327
# define	S_TEXTURE	328
# define	S_LOOP	329
# define	S_STARTTIME	330
# define	S_STOPTIME	331
# define	S_GROUNDANGLE	332
# define	S_GROUNDCOLOR	333
# define	S_SPEED	334
# define	S_AVATAR_SIZE	335
# define	S_BACKURL	336
# define	S_BOTTOMURL	337
# define	S_FRONTURL	338
# define	S_LEFTURL	339
# define	S_RIGHTURL	340
# define	S_TOPURL	341
# define	S_SKYANGLE	342
# define	S_SKYCOLOR	343
# define	S_AXIS_OF_ROTATION	344
# define	S_COLLIDE	345
# define	S_COLLIDETIME	346
# define	S_PROXY	347
# define	S_SIDE	348
# define	S_AUTO_OFFSET	349
# define	S_DISK_ANGLE	350
# define	S_ENABLED	351
# define	S_MAX_ANGLE	352
# define	S_MIN_ANGLE	353
# define	S_OFFSET	354
# define	S_BBOXSIZE	355
# define	S_BBOXCENTER	356
# define	S_VISIBILITY_LIMIT	357
# define	S_AMBIENT_INTENSITY	358
# define	AS_NORMAL	359
# define	S_TEXCOORD	360
# define	S_CCW	361
# define	S_COLOR_PER_VERTEX	362
# define	S_CREASE_ANGLE	363
# define	S_NORMAL_PER_VERTEX	364
# define	S_XDIMENSION	365
# define	S_XSPACING	366
# define	S_ZDIMENSION	367
# define	S_ZSPACING	368
# define	S_BEGIN_CAP	369
# define	S_CROSS_SECTION	370
# define	S_END_CAP	371
# define	S_SPINE	372
# define	S_FOG_TYPE	373
# define	S_VISIBILITY_RANGE	374
# define	S_HORIZONTAL	375
# define	S_JUSTIFY	376
# define	S_LANGUAGE	377
# define	S_LEFT2RIGHT	378
# define	S_TOP2BOTTOM	379
# define	IMAGE_TEXTURE	380
# define	S_SOLID	381
# define	S_KEY	382
# define	S_KEYVALUE	383
# define	S_REPEAT_S	384
# define	S_REPEAT_T	385
# define	S_CONVEX	386
# define	S_BOTTOM	387
# define	S_PICTH	388
# define	S_COORD	389
# define	S_COLOR_INDEX	390
# define	S_COORD_INDEX	391
# define	S_NORMAL_INDEX	392
# define	S_MAX_POSITION	393
# define	S_MIN_POSITION	394
# define	S_ATTENUATION	395
# define	S_APPEARANCE	396
# define	S_GEOMETRY	397
# define	S_DIRECT_OUTPUT	398
# define	S_MUST_EVALUATE	399
# define	S_MAX_BACK	400
# define	S_MIN_BACK	401
# define	S_MAX_FRONT	402
# define	S_MIN_FRONT	403
# define	S_PRIORITY	404
# define	S_SOURCE	405
# define	S_SPATIALIZE	406
# define	S_BERM_WIDTH	407
# define	S_CHOICE	408
# define	S_WHICHCHOICE	409
# define	S_FONTSTYLE	410
# define	S_LENGTH	411
# define	S_MAX_EXTENT	412
# define	S_ROTATION	413
# define	S_SCALE	414
# define	S_CYCLE_INTERVAL	415
# define	S_FIELD_OF_VIEW	416
# define	S_JUMP	417
# define	S_TITLE	418
# define	S_TEXCOORD_INDEX	419
# define	S_HEADLIGHT	420
# define	S_TOP	421
# define	S_BOTTOMRADIUS	422
# define	S_HEIGHT	423
# define	S_POINT	424
# define	S_STRING	425
# define	S_SPACING	426
# define	S_TYPE	427
# define	S_RADIUS	428
# define	S_ON	429
# define	S_INTENSITY	430
# define	S_COLOR	431
# define	S_DIRECTION	432
# define	S_SIZE	433
# define	S_FAMILY	434
# define	S_STYLE	435
# define	S_RANGE	436
# define	S_CENTER	437
# define	S_TRANSLATION	438
# define	S_LEVEL	439
# define	S_DIFFUSECOLOR	440
# define	S_SPECULARCOLOR	441
# define	S_EMISSIVECOLOR	442
# define	S_SHININESS	443
# define	S_TRANSPARENCY	444
# define	S_VECTOR	445
# define	S_POSITION	446
# define	S_ORIENTATION	447
# define	S_LOCATION	448
# define	S_CUTOFFANGLE	449
# define	S_WHICHCHILD	450
# define	S_IMAGE	451
# define	S_SCALEORIENTATION	452
# define	S_DESCRIPTION	453


#ifndef YYSTYPE
typedef union {
bool     bval;
int		 ival;
float	 fval;
char	 *sval;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif


#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

#include <mesh/mesh.h>
#include <mesh/vrml.h>
#include <math/vector3.h>
#include <math/point.h>

#include <glt/color.h>

#ifndef alloca
#define alloca	malloc
#endif

typedef char 	*VrmlSFString;
typedef float	VrmlSFFloat;
typedef float	VrmlSFFloat2[2];
typedef float	VrmlSFFloat3[3];
typedef float	VrmlSFFloat4[4];
typedef int		VrmlSFInt32;
typedef float	VrmlSFVec2f[2];		
typedef float	VrmlSFVec4f[4];		
typedef bool	VrmlSFBool;
typedef float	VrmlSFRotation[4];		
typedef double	VrmlSFTime;		
typedef float	VrmlSFMatrix[4][4];		

VrmlSFVec2f		gVec2f;
Vector			gVec3f;
VrmlSFRotation	gRotation;
int				gWidth;
int				gHeight;
int				gComponents;

static MFInt32 _vectorInt32;
static MFVec3f _vectorVector;

//

static GltColor          _color;
static MaterialPtr       _material;
static IndexedFaceSetPtr _faceSet;

//

void (*VrmlParseMaterial)      (MaterialPtr       &material) = NULL;
void (*VrmlParseIndexedFaceSet)(IndexedFaceSetPtr &faceSet)  = NULL;
void (*VrmlParseShape)         (GltShapePtr           &shape)    = NULL;

//

int yyerror(char *s);
int yyparseVrml(void);
int Vrmllex(void);

Mesh *yyVrmlMesh = 0;

#ifndef YYDEBUG
# define YYDEBUG 0
#endif



#define	YYFINAL		1085
#define	YYFLAG		-32768
#define	YYNTBASE	205

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 453 ? yytranslate[x] : 508)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const short yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   202,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   200,     2,   201,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   203,     2,   204,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     2,     4,     6,     9,    10,    12,    14,    16,
      18,    20,    22,    24,    26,    28,    30,    32,    34,    36,
      38,    40,    42,    44,    46,    48,    50,    52,    54,    56,
      58,    60,    62,    64,    66,    68,    70,    72,    74,    76,
      78,    80,    82,    84,    86,    88,    90,    92,    94,    96,
      98,   100,   102,   104,   106,   108,   110,   112,   114,   116,
     118,   120,   122,   124,   126,   128,   130,   132,   134,   136,
     140,   145,   149,   152,   155,   159,   161,   165,   166,   167,
     170,   175,   178,   183,   185,   189,   191,   195,   197,   201,
     203,   206,   210,   213,   215,   218,   222,   225,   227,   230,
     234,   237,   239,   242,   246,   249,   251,   254,   258,   261,
     263,   266,   270,   273,   275,   278,   282,   285,   287,   290,
     294,   296,   300,   303,   304,   306,   308,   311,   314,   316,
     319,   322,   325,   327,   329,   331,   336,   339,   340,   343,
     346,   349,   352,   355,   358,   361,   364,   366,   371,   374,
     375,   377,   380,   383,   386,   389,   392,   395,   397,   402,
     405,   406,   408,   410,   412,   414,   416,   418,   420,   422,
     424,   426,   429,   432,   435,   438,   441,   444,   447,   450,
     453,   456,   458,   463,   466,   467,   469,   472,   474,   476,
     478,   483,   486,   487,   490,   492,   497,   498,   500,   503,
     507,   509,   514,   517,   520,   521,   523,   525,   528,   530,
     532,   535,   537,   542,   545,   546,   549,   551,   556,   559,
     560,   562,   564,   567,   570,   572,   577,   580,   581,   584,
     587,   590,   593,   595,   600,   603,   604,   607,   608,   611,
     616,   619,   622,   623,   626,   629,   631,   636,   639,   640,
     643,   646,   649,   652,   655,   657,   662,   665,   666,   669,
     672,   675,   678,   681,   684,   686,   691,   694,   695,   698,
     701,   704,   707,   710,   712,   717,   720,   721,   723,   726,
     729,   732,   735,   738,   741,   744,   747,   750,   753,   756,
     759,   762,   765,   768,   771,   773,   778,   781,   782,   784,
     786,   788,   790,   793,   796,   799,   802,   805,   808,   811,
     814,   817,   820,   822,   827,   830,   831,   834,   837,   840,
     842,   847,   850,   851,   853,   856,   859,   862,   865,   868,
     871,   874,   877,   880,   883,   887,   890,   891,   893,   895,
     897,   900,   901,   904,   909,   912,   915,   916,   918,   921,
     924,   927,   929,   934,   937,   938,   941,   944,   947,   950,
     952,   953,   959,   962,   963,   966,   969,   972,   975,   978,
     981,   984,   985,   988,   989,   995,   998,  1000,  1002,  1004,
    1006,  1009,  1010,  1013,  1016,  1019,  1022,  1025,  1028,  1031,
    1034,  1037,  1040,  1043,  1046,  1049,  1052,  1055,  1056,  1059,
    1060,  1066,  1069,  1072,  1073,  1076,  1079,  1082,  1085,  1088,
    1091,  1095,  1098,  1099,  1101,  1104,  1106,  1108,  1110,  1115,
    1118,  1119,  1121,  1123,  1126,  1129,  1132,  1137,  1139,  1144,
    1147,  1148,  1150,  1153,  1156,  1159,  1162,  1165,  1168,  1171,
    1173,  1178,  1181,  1182,  1184,  1186,  1189,  1192,  1195,  1198,
    1201,  1203,  1208,  1211,  1212,  1215,  1217,  1222,  1225,  1226,
    1229,  1232,  1234,  1239,  1242,  1243,  1246,  1249,  1251,  1256,
    1259,  1260,  1265,  1268,  1271,  1274,  1276,  1281,  1284,  1285,
    1288,  1291,  1294,  1297,  1300,  1302,  1307,  1310,  1311,  1314,
    1317,  1320,  1323,  1326,  1329,  1332,  1334,  1339,  1342,  1343,
    1346,  1349,  1352,  1355,  1357,  1362,  1365,  1366,  1369,  1372,
    1374,  1379,  1382,  1383,  1386,  1389,  1392,  1394,  1399,  1402,
    1403,  1406,  1409,  1411,  1416,  1419,  1420,  1422,  1425,  1428,
    1431,  1433,  1438,  1441,  1442,  1445,  1448,  1451,  1454,  1457,
    1460,  1463,  1466,  1469,  1472,  1475,  1478,  1480,  1485,  1488,
    1489,  1492,  1494,  1499,  1502,  1503,  1506,  1509,  1512,  1514,
    1519,  1522,  1523,  1526,  1529,  1532,  1535,  1538,  1541,  1544,
    1547,  1550,  1553,  1555,  1560,  1563,  1564,  1566,  1569,  1574,
    1577,  1580,  1581,  1584,  1589,  1592,  1595,  1596,  1598,  1600,
    1603,  1606,  1609,  1612,  1614,  1619,  1622,  1623,  1626,  1628,
    1633,  1636,  1637,  1640,  1643,  1646,  1649,  1651,  1656,  1659,
    1660,  1663,  1666,  1669,  1672,  1675,  1678,  1679,  1682,  1687,
    1690,  1693,  1694,  1697,  1699,  1704,  1707,  1708,  1710,  1713,
    1716,  1719,  1722,  1725,  1727,  1729,  1731,  1734,  1735,  1738,
    1743,  1746,  1749,  1750,  1753,  1756,  1759,  1762,  1765,  1768,
    1769,  1772,  1777,  1780,  1783,  1784,  1787,  1790,  1793,  1795,
    1800,  1803,  1804,  1806,  1809,  1812,  1814
};
static const short yyrhs[] =
{
     206,     0,     1,     0,    26,     0,   213,   206,     0,     0,
     247,     0,   273,     0,   285,     0,   346,     0,   381,     0,
     387,     0,   466,     0,   494,     0,   295,     0,   307,     0,
     406,     0,   410,     0,   431,     0,   439,     0,   315,     0,
     419,     0,   456,     0,   435,     0,   485,     0,   489,     0,
     501,     0,   250,     0,   341,     0,   351,     0,   362,     0,
     392,     0,   415,     0,   480,     0,   277,     0,   299,     0,
     311,     0,   324,     0,   332,     0,   372,     0,   376,     0,
     427,     0,   452,     0,   472,     0,   319,     0,   460,     0,
     423,     0,   255,     0,   269,     0,   336,     0,   341,     0,
     507,     0,   398,     0,   499,     0,   507,     0,   444,     0,
     356,     0,   448,     0,   208,     0,   212,     0,   209,     0,
     207,     0,     4,     0,     3,     0,     6,     0,     5,     0,
       4,     0,     5,     0,     4,     0,   217,   217,   217,     0,
     217,   217,   217,   217,     0,     4,     4,     4,     0,   508,
     237,     0,   217,   217,     0,   217,   217,   217,     0,   219,
       0,   200,   234,   201,     0,     0,     0,   224,   214,     0,
     224,   200,   231,   201,     0,   225,   222,     0,   225,   200,
     236,   201,     0,   217,     0,   200,   232,   201,     0,   216,
       0,   200,   233,   201,     0,   221,     0,   200,   235,   201,
       0,   214,     0,   231,   214,     0,   231,   202,   214,     0,
     231,   202,     0,   217,     0,   232,   217,     0,   232,   202,
     217,     0,   232,   202,     0,   216,     0,   233,   216,     0,
     233,   202,   216,     0,   233,   202,     0,   219,     0,   234,
     219,     0,   234,   202,   219,     0,   234,   202,     0,   221,
       0,   235,   221,     0,   235,   202,   221,     0,   235,   202,
       0,   222,     0,   236,   222,     0,   236,   202,   222,     0,
     236,   202,     0,   214,     0,   237,   214,     0,   237,   202,
     214,     0,   237,   202,     0,   220,     0,   220,   202,     0,
     220,   202,   238,     0,   220,     0,   200,   238,   201,     0,
     245,   240,     0,     0,    70,     0,    71,     0,   102,   222,
       0,   101,   222,     0,   280,     0,   199,   216,     0,   241,
     229,     0,   242,   229,     0,   243,     0,   244,     0,     8,
       0,   246,   203,   240,   204,     0,   210,   248,     0,     0,
      72,    20,     0,    72,   362,     0,    74,    20,     0,    74,
     351,     0,    74,   392,     0,    74,   415,     0,    73,    20,
       0,    73,   480,     0,     9,     0,   249,   203,   248,   204,
       0,   253,   251,     0,     0,    71,     0,   199,   216,     0,
      75,   215,     0,   134,   217,     0,    76,   218,     0,    77,
     218,     0,   252,   229,     0,    10,     0,   254,   203,   251,
     204,     0,   267,   256,     0,     0,    82,     0,    83,     0,
      84,     0,    85,     0,    86,     0,    87,     0,    78,     0,
      79,     0,    88,     0,    89,     0,   263,   228,     0,   264,
     223,     0,   257,   229,     0,   258,   229,     0,   259,   229,
       0,   260,   229,     0,   261,   229,     0,   262,   229,     0,
     265,   228,     0,   266,   223,     0,    11,     0,   268,   203,
     256,   204,     0,   271,   270,     0,     0,   280,     0,    90,
     222,     0,   243,     0,   244,     0,    12,     0,   272,   203,
     270,   204,     0,   275,   274,     0,     0,   179,   222,     0,
      13,     0,   276,   203,   274,   204,     0,     0,   279,     0,
     278,   279,     0,   278,   202,   279,     0,   213,     0,    69,
     200,   278,   201,     0,    69,   278,     0,   283,   281,     0,
       0,    93,     0,   280,     0,    91,   215,     0,   243,     0,
     244,     0,   282,   213,     0,    14,     0,   284,   203,   281,
     204,     0,   287,   286,     0,     0,   177,   223,     0,    15,
       0,   288,   203,   286,   204,     0,   293,   290,     0,     0,
     128,     0,   129,     0,   291,   228,     0,   292,   223,     0,
      16,     0,   294,   203,   290,   204,     0,   297,   296,     0,
       0,    94,   215,     0,   133,   215,     0,   168,   217,     0,
     169,   217,     0,    21,     0,   298,   203,   296,   204,     0,
     170,   227,     0,     0,    65,     7,     0,     0,   301,    17,
       0,   302,   203,   300,   204,     0,    66,     7,     0,   305,
     304,     0,     0,   291,   228,     0,   292,   227,     0,    18,
       0,   306,   203,   304,   204,     0,   309,   308,     0,     0,
      94,   215,     0,   133,   215,     0,   167,   215,     0,   174,
     217,     0,   169,   217,     0,    23,     0,   310,   203,   308,
     204,     0,   313,   312,     0,     0,    95,   215,     0,    96,
     217,     0,    97,   215,     0,    98,   217,     0,    99,   217,
       0,   100,   217,     0,    19,     0,   314,   203,   312,   204,
       0,   317,   316,     0,     0,   175,   215,     0,   176,   217,
       0,   177,   219,     0,   178,   222,     0,   104,   217,     0,
      24,     0,   318,   203,   316,   204,     0,   322,   320,     0,
       0,   169,     0,   177,    20,     0,   177,   289,     0,   105,
      20,     0,   105,   402,     0,   106,    20,     0,   106,   476,
       0,   321,   228,     0,   107,   215,     0,   109,   217,     0,
     127,   215,     0,   108,   215,     0,   110,   215,     0,   111,
     214,     0,   112,   217,     0,   113,   214,     0,   114,   217,
       0,    28,     0,   323,   203,   320,   204,     0,   330,   325,
       0,     0,   116,     0,   193,     0,   160,     0,   118,     0,
     115,   215,     0,   107,   215,     0,   132,   215,     0,   109,
     217,     0,   127,   215,     0,   326,   230,     0,   117,   215,
       0,   327,   239,     0,   328,   230,     0,   329,   227,     0,
      27,     0,   331,   203,   325,   204,     0,   334,   333,     0,
       0,   177,   219,     0,   119,   216,     0,   120,   217,     0,
      29,     0,   335,   203,   333,   204,     0,   339,   337,     0,
       0,   122,     0,   180,   216,     0,   121,   215,     0,   338,
     229,     0,   123,   216,     0,   124,   215,     0,   179,   217,
       0,   172,   217,     0,   181,   216,     0,   125,   215,     0,
      25,   203,     0,   340,   337,   204,     0,   343,   342,     0,
       0,   280,     0,   243,     0,   244,     0,    65,     7,     0,
       0,   344,    34,     0,   345,   203,   342,   204,     0,    66,
       7,     0,   349,   347,     0,     0,    71,     0,   348,   229,
       0,   130,   215,     0,   131,   215,     0,   126,     0,   350,
     203,   347,   204,     0,   352,   353,     0,     0,   142,    20,
       0,   142,   210,     0,   143,    20,     0,   143,   211,     0,
      45,     0,     0,   354,   203,   352,   204,   355,     0,   358,
     357,     0,     0,   104,   217,     0,   186,   219,     0,   188,
     219,     0,   189,   217,     0,   187,   219,     0,   190,   217,
       0,    65,     7,     0,     0,   359,    39,     0,     0,   360,
     203,   357,   204,   361,     0,    66,     7,     0,   136,     0,
     137,     0,   138,     0,   165,     0,   368,   367,     0,     0,
     177,   289,     0,   135,   303,     0,   105,   402,     0,   106,
     476,     0,   107,   215,     0,   132,   215,     0,   127,   215,
       0,   109,   217,     0,   108,   215,     0,   110,   215,     0,
     364,   226,     0,   365,   226,     0,   363,   226,     0,   366,
     226,     0,    65,     7,     0,     0,   369,    35,     0,     0,
     370,   203,   367,   204,   371,     0,    66,     7,     0,   374,
     373,     0,     0,   177,   289,     0,   135,   303,     0,   108,
     215,     0,   363,   226,     0,   364,   226,     0,    36,   203,
       0,   375,   373,   204,     0,   379,   377,     0,     0,    71,
       0,   378,   229,     0,   243,     0,   244,     0,    30,     0,
     380,   203,   377,   204,     0,   385,   382,     0,     0,   182,
       0,   185,     0,   383,   228,     0,   183,   222,     0,   384,
     213,     0,   384,   200,   206,   201,     0,    38,     0,   386,
     203,   382,   204,     0,   390,   388,     0,     0,    71,     0,
      75,   215,     0,    80,   217,     0,    76,   218,     0,    77,
     218,     0,   389,   229,     0,   130,   215,     0,   131,   215,
       0,    31,     0,   391,   203,   388,   204,     0,   396,   393,
       0,     0,    81,     0,   173,     0,   394,   228,     0,   166,
     215,     0,    80,   217,     0,   395,   229,     0,   103,   217,
       0,    32,     0,   397,   203,   393,   204,     0,   400,   399,
       0,     0,   191,   227,     0,    40,     0,   401,   203,   399,
     204,     0,   404,   403,     0,     0,   291,   228,     0,   292,
     227,     0,    58,     0,   405,   203,   403,   204,     0,   408,
     407,     0,     0,   291,   228,     0,   292,   239,     0,    59,
       0,   409,   203,   407,   204,     0,   413,   411,     0,     0,
     197,     4,     4,     4,     0,   412,   237,     0,   130,   215,
       0,   131,   215,     0,    33,     0,   414,   203,   411,   204,
       0,   417,   416,     0,     0,    95,   215,     0,    97,   215,
       0,   139,   221,     0,   140,   221,     0,   100,   222,     0,
      63,     0,   418,   203,   416,   204,     0,   421,   420,     0,
       0,   104,   217,     0,   141,   222,     0,   177,   219,     0,
     176,   217,     0,   194,   222,     0,   175,   215,     0,   174,
     217,     0,    60,     0,   422,   203,   420,   204,     0,   425,
     424,     0,     0,   177,    20,     0,   177,   289,     0,   135,
      20,     0,   135,   303,     0,    61,     0,   426,   203,   424,
     204,     0,   429,   428,     0,     0,   291,   228,     0,   292,
     227,     0,    41,     0,   430,   203,   428,   204,     0,   433,
     432,     0,     0,   183,   222,     0,   179,   222,     0,    97,
     215,     0,    42,     0,   434,   203,   432,   204,     0,   437,
     436,     0,     0,   291,   228,     0,   292,   228,     0,    43,
       0,   438,   203,   436,   204,     0,   442,   440,     0,     0,
      71,     0,   441,   229,     0,   144,   215,     0,   145,   215,
       0,    44,     0,   443,   203,   440,   204,     0,   446,   445,
       0,     0,   178,   222,     0,   176,   217,     0,   194,   222,
       0,   146,   217,     0,   148,   217,     0,   147,   217,     0,
     149,   217,     0,   150,   217,     0,   151,    20,     0,   151,
     255,     0,   151,   392,     0,   152,   215,     0,    46,     0,
     447,   203,   445,   204,     0,   450,   449,     0,     0,   174,
     217,     0,    62,     0,   451,   203,   449,   204,     0,   454,
     453,     0,     0,    95,   215,     0,    97,   215,     0,   100,
     220,     0,    48,     0,   455,   203,   453,   204,     0,   458,
     457,     0,     0,   104,   217,     0,   141,   222,     0,   153,
     217,     0,   177,   219,     0,   195,   217,     0,   178,   222,
       0,   176,   217,     0,   194,   222,     0,   175,   215,     0,
     174,   217,     0,    47,     0,   459,   203,   457,   204,     0,
     463,   461,     0,     0,   154,     0,   462,   213,     0,   462,
     200,   206,   201,     0,   155,   214,     0,    65,     7,     0,
       0,   464,    53,     0,   465,   203,   461,   204,     0,    66,
       7,     0,   470,   467,     0,     0,   171,     0,   157,     0,
     468,   229,     0,   156,   341,     0,   469,   228,     0,   158,
     217,     0,    49,     0,   471,   203,   467,   204,     0,   474,
     473,     0,     0,   170,   230,     0,    50,     0,   475,   203,
     473,   204,     0,   478,   477,     0,     0,   183,   221,     0,
     159,   217,     0,   160,   221,     0,   184,   221,     0,    51,
       0,   479,   203,   477,   204,     0,   482,   481,     0,     0,
     161,   218,     0,    97,   215,     0,    75,   215,     0,    76,
     218,     0,    77,   218,     0,    65,     7,     0,     0,   483,
      52,     0,   484,   203,   481,   204,     0,    66,     7,     0,
     487,   486,     0,     0,    97,   215,     0,    54,     0,   488,
     203,   486,   204,     0,   491,   490,     0,     0,   280,     0,
     183,   222,     0,   159,   220,     0,   160,   222,     0,   198,
     220,     0,   184,   222,     0,   243,     0,   244,     0,   494,
       0,    65,     7,     0,     0,   492,    64,     0,   493,   203,
     490,   204,     0,    66,     7,     0,   496,   495,     0,     0,
     162,   217,     0,   163,   215,     0,   193,   220,     0,   192,
     222,     0,   199,   216,     0,    65,     7,     0,     0,   497,
      55,     0,   498,   203,   495,   204,     0,    66,     7,     0,
     501,   500,     0,     0,   183,   222,     0,    97,   215,     0,
     179,   222,     0,    56,     0,   502,   203,   500,   204,     0,
     505,   503,     0,     0,    37,     0,   504,   229,     0,   164,
     216,     0,    57,     0,   506,   203,   503,   204,     0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,   128,   129,   130,   134,   135,   139,   140,   141,   142,
     143,   144,   145,   146,   150,   151,   152,   153,   154,   155,
     159,   160,   161,   162,   163,   164,   165,   169,   170,   171,
     172,   173,   174,   175,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   192,   193,   194,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   215,   218,   221,   224,   227,   233,   234,   237,
     245,   254,   262,   266,   273,   276,   277,   281,   282,   285,
     286,   289,   290,   293,   294,   297,   298,   301,   302,   313,
     314,   315,   316,   319,   320,   321,   322,   325,   326,   327,
     328,   331,   332,   333,   334,   337,   338,   339,   340,   343,
     344,   345,   346,   349,   350,   351,   352,   357,   358,   359,
     363,   364,   374,   375,   379,   385,   391,   397,   403,   404,
     408,   411,   414,   415,   419,   425,   437,   438,   442,   443,
     444,   445,   446,   447,   448,   449,   453,   459,   471,   472,
     476,   482,   485,   488,   491,   494,   497,   503,   509,   521,
     522,   526,   532,   538,   544,   550,   556,   562,   568,   574,
     580,   586,   589,   592,   595,   598,   601,   604,   607,   610,
     613,   619,   625,   637,   638,   642,   643,   646,   647,   651,
     657,   669,   670,   674,   680,   686,   698,   699,   700,   701,
     704,   707,   708,   718,   719,   723,   729,   730,   733,   734,
     735,   741,   747,   759,   760,   764,   768,   774,   786,   787,
     791,   797,   803,   806,   812,   818,   830,   831,   835,   838,
     841,   844,   850,   856,   868,   869,   873,   874,   877,   883,
     884,   893,   894,   898,   901,   907,   913,   925,   926,   930,
     933,   936,   939,   942,   948,   954,   966,   967,   971,   974,
     977,   980,   983,   986,   993,   999,  1011,  1012,  1016,  1019,
    1022,  1025,  1028,  1034,  1040,  1052,  1053,  1057,  1064,  1065,
    1066,  1067,  1068,  1069,  1070,  1073,  1076,  1079,  1082,  1085,
    1088,  1091,  1094,  1097,  1103,  1109,  1121,  1122,  1126,  1132,
    1138,  1144,  1150,  1153,  1156,  1159,  1162,  1165,  1168,  1171,
    1174,  1177,  1183,  1189,  1201,  1202,  1206,  1209,  1212,  1218,
    1224,  1236,  1237,  1241,  1247,  1250,  1253,  1256,  1259,  1262,
    1265,  1268,  1271,  1277,  1283,  1295,  1296,  1300,  1301,  1302,
    1306,  1307,  1310,  1313,  1314,  1323,  1324,  1328,  1334,  1337,
    1340,  1346,  1352,  1364,  1365,  1368,  1369,  1370,  1371,  1375,
    1386,  1399,  1411,  1412,  1415,  1416,  1417,  1418,  1419,  1420,
    1423,  1424,  1427,  1437,  1444,  1445,  1455,  1458,  1461,  1464,
    1467,  1468,  1471,  1472,  1473,  1474,  1475,  1476,  1477,  1478,
    1479,  1480,  1481,  1482,  1483,  1484,  1487,  1488,  1491,  1501,
    1516,  1517,  1526,  1527,  1531,  1532,  1533,  1536,  1539,  1545,
    1551,  1563,  1564,  1568,  1574,  1577,  1578,  1582,  1588,  1600,
    1601,  1605,  1612,  1618,  1621,  1624,  1627,  1633,  1639,  1651,
    1652,  1656,  1662,  1665,  1668,  1671,  1674,  1677,  1680,  1686,
    1692,  1704,  1705,  1709,  1715,  1721,  1724,  1727,  1730,  1733,
    1739,  1745,  1757,  1758,  1762,  1766,  1772,  1787,  1788,  1792,
    1795,  1801,  1807,  1819,  1820,  1824,  1827,  1833,  1839,  1851,
    1852,  1856,  1862,  1865,  1868,  1874,  1880,  1892,  1893,  1897,
    1900,  1903,  1906,  1909,  1915,  1921,  1934,  1935,  1939,  1942,
    1945,  1948,  1951,  1954,  1957,  1963,  1969,  1981,  1982,  1986,
    1987,  1988,  1989,  1994,  1999,  2010,  2011,  2015,  2018,  2024,
    2030,  2042,  2043,  2047,  2050,  2053,  2059,  2065,  2077,  2078,
    2082,  2085,  2091,  2097,  2109,  2110,  2114,  2120,  2123,  2126,
    2132,  2138,  2150,  2151,  2155,  2158,  2161,  2164,  2167,  2170,
    2173,  2176,  2179,  2180,  2181,  2182,  2188,  2194,  2206,  2207,
    2211,  2217,  2223,  2235,  2236,  2240,  2243,  2246,  2252,  2258,
    2270,  2271,  2275,  2278,  2281,  2284,  2287,  2290,  2293,  2296,
    2299,  2302,  2308,  2314,  2326,  2327,  2331,  2337,  2340,  2343,
    2349,  2350,  2353,  2356,  2357,  2366,  2367,  2371,  2377,  2383,
    2386,  2387,  2388,  2395,  2401,  2413,  2414,  2418,  2423,  2429,
    2441,  2442,  2446,  2449,  2452,  2455,  2462,  2468,  2480,  2481,
    2485,  2488,  2491,  2494,  2497,  2503,  2504,  2507,  2510,  2511,
    2520,  2521,  2525,  2531,  2537,  2549,  2550,  2554,  2555,  2558,
    2561,  2564,  2567,  2570,  2571,  2572,  2576,  2577,  2580,  2583,
    2584,  2593,  2594,  2598,  2599,  2600,  2601,  2602,  2605,  2606,
    2609,  2612,  2613,  2622,  2623,  2627,  2630,  2633,  2639,  2645,
    2657,  2658,  2662,  2668,  2671,  2677,  2683
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "TRUEFALSE", "NUMBER", "AFLOAT", "STRING", 
  "NAME", "ANCHOR", "APPEARANCE", "AUDIOCLIP", "BACKGROUND", "BILLBOARD", 
  "BOX", "COLLISION", "COLOR", "COLOR_INTERP", "COORDINATE", 
  "COORDINATE_INTERP", "CYLINDER_SENSOR", "NULL_STRING", "CONE", "CUBE", 
  "CYLINDER", "DIRECTIONALLIGHT", "FONTSTYLE", "AERROR", "EXTRUSION", 
  "ELEVATION_GRID", "FOG", "INLINE", "MOVIE_TEXTURE", "NAVIGATION_INFO", 
  "PIXEL_TEXTURE", "GROUP", "INDEXEDFACESET", "INDEXEDLINESET", "S_INFO", 
  "LOD", "MATERIAL", "NORMAL", "POSITION_INTERP", "PROXIMITY_SENSOR", 
  "SCALAR_INTERP", "SCRIPT", "SHAPE", "SOUND", "SPOTLIGHT", 
  "SPHERE_SENSOR", "ATEXT", "TEXTURE_COORDINATE", "TEXTURE_TRANSFORM", 
  "TIME_SENSOR", "SWITCH", "TOUCH_SENSOR", "VIEWPOINT", 
  "VISIBILITY_SENSOR", "WORLD_INFO", "NORMAL_INTERP", 
  "ORIENTATION_INTERP", "POINTLIGHT", "POINTSET", "SPHERE", 
  "PLANE_SENSOR", "TRANSFORM", "DEF", "USE", "PROTO", "ROUTE", 
  "S_CHILDREN", "S_PARAMETER", "S_URL", "S_MATERIAL", 
  "S_TEXTURETRANSFORM", "S_TEXTURE", "S_LOOP", "S_STARTTIME", 
  "S_STOPTIME", "S_GROUNDANGLE", "S_GROUNDCOLOR", "S_SPEED", 
  "S_AVATAR_SIZE", "S_BACKURL", "S_BOTTOMURL", "S_FRONTURL", "S_LEFTURL", 
  "S_RIGHTURL", "S_TOPURL", "S_SKYANGLE", "S_SKYCOLOR", 
  "S_AXIS_OF_ROTATION", "S_COLLIDE", "S_COLLIDETIME", "S_PROXY", "S_SIDE", 
  "S_AUTO_OFFSET", "S_DISK_ANGLE", "S_ENABLED", "S_MAX_ANGLE", 
  "S_MIN_ANGLE", "S_OFFSET", "S_BBOXSIZE", "S_BBOXCENTER", 
  "S_VISIBILITY_LIMIT", "S_AMBIENT_INTENSITY", "AS_NORMAL", "S_TEXCOORD", 
  "S_CCW", "S_COLOR_PER_VERTEX", "S_CREASE_ANGLE", "S_NORMAL_PER_VERTEX", 
  "S_XDIMENSION", "S_XSPACING", "S_ZDIMENSION", "S_ZSPACING", 
  "S_BEGIN_CAP", "S_CROSS_SECTION", "S_END_CAP", "S_SPINE", "S_FOG_TYPE", 
  "S_VISIBILITY_RANGE", "S_HORIZONTAL", "S_JUSTIFY", "S_LANGUAGE", 
  "S_LEFT2RIGHT", "S_TOP2BOTTOM", "IMAGE_TEXTURE", "S_SOLID", "S_KEY", 
  "S_KEYVALUE", "S_REPEAT_S", "S_REPEAT_T", "S_CONVEX", "S_BOTTOM", 
  "S_PICTH", "S_COORD", "S_COLOR_INDEX", "S_COORD_INDEX", 
  "S_NORMAL_INDEX", "S_MAX_POSITION", "S_MIN_POSITION", "S_ATTENUATION", 
  "S_APPEARANCE", "S_GEOMETRY", "S_DIRECT_OUTPUT", "S_MUST_EVALUATE", 
  "S_MAX_BACK", "S_MIN_BACK", "S_MAX_FRONT", "S_MIN_FRONT", "S_PRIORITY", 
  "S_SOURCE", "S_SPATIALIZE", "S_BERM_WIDTH", "S_CHOICE", "S_WHICHCHOICE", 
  "S_FONTSTYLE", "S_LENGTH", "S_MAX_EXTENT", "S_ROTATION", "S_SCALE", 
  "S_CYCLE_INTERVAL", "S_FIELD_OF_VIEW", "S_JUMP", "S_TITLE", 
  "S_TEXCOORD_INDEX", "S_HEADLIGHT", "S_TOP", "S_BOTTOMRADIUS", 
  "S_HEIGHT", "S_POINT", "S_STRING", "S_SPACING", "S_TYPE", "S_RADIUS", 
  "S_ON", "S_INTENSITY", "S_COLOR", "S_DIRECTION", "S_SIZE", "S_FAMILY", 
  "S_STYLE", "S_RANGE", "S_CENTER", "S_TRANSLATION", "S_LEVEL", 
  "S_DIFFUSECOLOR", "S_SPECULARCOLOR", "S_EMISSIVECOLOR", "S_SHININESS", 
  "S_TRANSPARENCY", "S_VECTOR", "S_POSITION", "S_ORIENTATION", 
  "S_LOCATION", "S_CUTOFFANGLE", "S_WHICHCHILD", "S_IMAGE", 
  "S_SCALEORIENTATION", "S_DESCRIPTION", "'['", "']'", "','", "'{'", 
  "'}'", "Vrml", "VrmlNodes", "GroupingNode", "InterpolationNode", 
  "SensorElement", "AppearanceNode", "GeometryNode", "LightNode", 
  "SFNode", "SFInt32", "SFBool", "SFString", "SFFloat", "SFTime", 
  "SFColor", "SFRotation", "SFVec2f", "SFVec3f", "MFColor", 
  "clearIntList", "clearVec3fList", "MFInt32", "MFVec3f", "MFFloat", 
  "MFString", "MFVec2f", "SFInt32List", "SFFloatList", "SFStringList", 
  "SFColorList", "SFVec2fList", "SFVec3fList", "SFImageList", 
  "SFRotationList", "MFRotation", "AnchorElements", 
  "AnchorElementParameterBegin", "AnchorElementURLBegin", "bboxCenter", 
  "bboxSize", "AnchorElement", "AnchorBegin", "Anchor", "AppearanceNodes", 
  "AppearanceBegin", "Appearance", "AudioClipElements", "AudioClipURL", 
  "AudioClipElement", "AudioClipBegin", "AudioClip", "BackGroundElements", 
  "BackGroundBackURL", "BackGroundBottomURL", "BackGroundFrontURL", 
  "BackGroundLeftURL", "BackGroundRightURL", "BackGroundTopURL", 
  "BackGroundGroundAngle", "BackGroundGroundColor", "BackGroundSkyAngle", 
  "BackGroundSkyColor", "BackGroundElement", "BackgroundBegin", 
  "Background", "BillboardElements", "BillboardElement", "BillboardBegin", 
  "Billboard", "BoxElements", "BoxElement", "BoxBegin", "Box", 
  "childrenElements", "childrenElement", "children", "CollisionElements", 
  "CollisionElementProxyBegin", "CollisionElement", "CollisionBegin", 
  "Collision", "ColorElements", "ColorElement", "ColorBegin", "Color", 
  "ColorInterpElements", "InterpolateKey", "InterporlateKeyValue", 
  "ColorInterpElement", "ColorInterpBegin", "ColorInterp", "ConeElements", 
  "ConeElement", "ConeBegin", "Cone", "CoordinateElements", 
  "CoordinateDef", "CoordinateBegin", "Coordinate", 
  "CoordinateInterpElements", "CoordinateInterpElement", 
  "CoordinateInterpBegin", "CoordinateInterp", "CylinderElements", 
  "CylinderElement", "CylinderBegin", "Cylinder", 
  "CylinderSensorElements", "CylinderSensorElement", 
  "CylinderSensorBegin", "CylinderSensor", "DirLightElements", 
  "DirLightElement", "DirLightBegin", "DirLight", "ElevationGridElements", 
  "ElevationGridHeight", "ElevationGridElement", "ElevationGridBegin", 
  "ElevationGrid", "ExtrusionElements", "ExtrusionCrossSection", 
  "ExtrusionOrientation", "ExtrusionScale", "ExtrusionSpine", 
  "ExtrusionElement", "ExtrusionBegin", "Extrusion", "FogElements", 
  "FogElement", "FogBegin", "Fog", "FontStyleElements", 
  "FontStyleJustify", "FontStyleElement", "FontStyleBegin", "FontStyle", 
  "GroupElements", "GroupElement", "GroupDef", "GroupBegin", "Group", 
  "ImgTexElements", "ImgTexURL", "ImgTexElement", "ImageTextureBegin", 
  "ImageTexture", "ShapeElements", "ShapeElement", "ShapeBegin", 
  "ShapeEnd", "Shape", "MaterialElements", "MaterialElement", 
  "MaterialDef", "MaterialBegin", "MaterialEnd", "Material", "ColorIndex", 
  "CoordIndex", "NormalIndex", "TextureIndex", "IdxFaceSetElements", 
  "IdxFaceSetElement", "IdxFaceSetDef", "IdxFaceSetBegin", 
  "IdxFaceSetEnd", "IdxFaceSet", "IdxLineSetElements", 
  "IdxLineSetElement", "IdxLineSetBegin", "IdxLineSet", "InlineElements", 
  "InlineURL", "InlineElement", "InlineBegin", "Inline", "LodElements", 
  "LodRange", "LodLevel", "LodElement", "LodBegin", "Lod", 
  "MovieTextureElements", "MovieTextureURL", "MovieTextureElement", 
  "MovieTextureBegin", "MovieTexture", "NavigationInfoElements", 
  "NavigationInfoAvatarSize", "NavigationInfoType", 
  "NavigationInfoElement", "NavigationInfoBegin", "NavigationInfo", 
  "NormalElements", "NormalElement", "NormalBegin", "Normal", 
  "NormalInterpElements", "NormalInterpElement", "NormalInterpBegin", 
  "NormalInterp", "OrientationInterpElements", "OrientationInterpElement", 
  "OrientationInterpBegin", "OrientationInterp", "PixelTextureElements", 
  "PixelTextureImage", "PixelTextureElement", "PixelTextureBegin", 
  "PixelTexture", "PlaneSensorElements", "PlaneSensorElement", 
  "PlaneSensorBegin", "PlaneSensor", "PointLightNodes", "PointLightNode", 
  "PointLightBegin", "PointLight", "PointSetElements", "PointSetElement", 
  "PointSetBegin", "PointSet", "PositionInterpElements", 
  "PositionInterpElement", "PositionInterpBegin", "PositionInterp", 
  "ProximitySensorElements", "ProximitySensorElement", 
  "ProximitySensorBegin", "ProximitySensor", "ScalarInterpElements", 
  "ScalarInterpElement", "ScalarInterpBegin", "ScalarInterp", 
  "ScriptElements", "ScriptURL", "ScriptElement", "ScriptBegin", "Script", 
  "SoundElements", "SoundElement", "SoundBegin", "Sound", 
  "SphereElements", "SphereElement", "SphereBegin", "Sphere", 
  "SphereSensorElements", "SphereSensorElement", "SphereSensorBegin", 
  "SphereSensor", "SpotLightElements", "SpotLightElement", 
  "SpotLightBegin", "SpotLight", "SwitchElements", "SwitchChoice", 
  "SwitchElement", "SwitchDef", "SwitchBegin", "Switch", "TextElements", 
  "TextString", "TextLength", "TextElement", "TextBegin", "Text", 
  "TexCoordElements", "TexCoordElement", "TexCoordBegin", "TexCoordinate", 
  "TextureTransformElements", "TextureTransformElement", 
  "TexTransformBegin", "TexTransform", "TimeSensorElements", 
  "TimeSensorElement", "TimeSensorDef", "TimeSensorBegin", "TimeSensor", 
  "TouchSensorElements", "TouchSensorElement", "TouchSensorBegin", 
  "TouchSensor", "TransformElements", "TransformElement", "TransformDef", 
  "TransformBegin", "Transform", "ViewpointElements", "ViewpointElement", 
  "ViewpointDef", "ViewpointBegin", "Viewpoint", "VisibilitySensors", 
  "VisibilitySensor", "VisibilitySensorBegine", "WorldInfoElements", 
  "WorldInfoInfo", "WorldInfoElement", "WorldInfoBegin", "WorldInfo", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,   205,   205,   205,   206,   206,   207,   207,   207,   207,
     207,   207,   207,   207,   208,   208,   208,   208,   208,   208,
     209,   209,   209,   209,   209,   209,   209,   210,   210,   210,
     210,   210,   210,   210,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   212,   212,   212,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   214,   215,   216,   217,   217,   218,   218,   219,
     220,   508,   509,   221,   222,   223,   223,   224,   225,   226,
     226,   227,   227,   228,   228,   229,   229,   230,   230,   231,
     231,   231,   231,   232,   232,   232,   232,   233,   233,   233,
     233,   234,   234,   234,   234,   235,   235,   235,   235,   236,
     236,   236,   236,   237,   237,   237,   237,   238,   238,   238,
     239,   239,   240,   240,   241,   242,   243,   244,   245,   245,
     245,   245,   245,   245,   246,   247,   248,   248,   210,   210,
     210,   210,   210,   210,   210,   210,   249,   250,   251,   251,
     252,   253,   253,   253,   253,   253,   253,   254,   255,   256,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   268,   269,   270,   270,   271,   271,   271,   271,   272,
     273,   274,   274,   275,   276,   277,   278,   278,   278,   278,
     279,   280,   280,   281,   281,   282,   283,   283,   283,   283,
     283,   284,   285,   286,   286,   287,   288,   289,   290,   290,
     291,   292,   293,   293,   294,   295,   296,   296,   297,   297,
     297,   297,   298,   299,   300,   300,   301,   301,   302,   303,
     303,   304,   304,   305,   305,   306,   307,   308,   308,   309,
     309,   309,   309,   309,   310,   311,   312,   312,   313,   313,
     313,   313,   313,   313,   314,   315,   316,   316,   317,   317,
     317,   317,   317,   318,   319,   320,   320,   321,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   323,   324,   325,   325,   326,   327,
     328,   329,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   331,   332,   333,   333,   334,   334,   334,   335,
     336,   337,   337,   338,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   340,   341,   342,   342,   343,   343,   343,
     344,   344,   345,   346,   346,   347,   347,   348,   349,   349,
     349,   350,   351,   352,   352,   353,   353,   353,   353,   354,
     355,   356,   357,   357,   358,   358,   358,   358,   358,   358,
     359,   359,   360,   361,   362,   362,   363,   364,   365,   366,
     367,   367,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   369,   369,   370,   371,
     372,   372,   373,   373,   374,   374,   374,   374,   374,   375,
     376,   377,   377,   378,   379,   379,   379,   380,   381,   382,
     382,   383,   384,   385,   385,   385,   385,   386,   387,   388,
     388,   389,   390,   390,   390,   390,   390,   390,   390,   391,
     392,   393,   393,   394,   395,   396,   396,   396,   396,   396,
     397,   398,   399,   399,   400,   401,   402,   403,   403,   404,
     404,   405,   406,   407,   407,   408,   408,   409,   410,   411,
     411,   412,   413,   413,   413,   414,   415,   416,   416,   417,
     417,   417,   417,   417,   418,   419,   420,   420,   421,   421,
     421,   421,   421,   421,   421,   422,   423,   424,   424,   425,
     425,   425,   425,   426,   427,   428,   428,   429,   429,   430,
     431,   432,   432,   433,   433,   433,   434,   435,   436,   436,
     437,   437,   438,   439,   440,   440,   441,   442,   442,   442,
     443,   444,   445,   445,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   447,   448,   449,   449,
     450,   451,   452,   453,   453,   454,   454,   454,   455,   456,
     457,   457,   458,   458,   458,   458,   458,   458,   458,   458,
     458,   458,   459,   460,   461,   461,   462,   463,   463,   463,
     464,   464,   465,   466,   466,   467,   467,   468,   469,   470,
     470,   470,   470,   471,   472,   473,   473,   474,   475,   476,
     477,   477,   478,   478,   478,   478,   479,   480,   481,   481,
     482,   482,   482,   482,   482,   483,   483,   484,   485,   485,
     486,   486,   487,   488,   489,   490,   490,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   492,   492,   493,   494,
     494,   495,   495,   496,   496,   496,   496,   496,   497,   497,
     498,   499,   499,   500,   500,   501,   501,   501,   502,   501,
     503,   503,   504,   505,   505,   506,   507
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     1,     1,     1,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     2,     3,     1,     3,     0,     0,     2,
       4,     2,     4,     1,     3,     1,     3,     1,     3,     1,
       2,     3,     2,     1,     2,     3,     2,     1,     2,     3,
       2,     1,     2,     3,     2,     1,     2,     3,     2,     1,
       2,     3,     2,     1,     2,     3,     2,     1,     2,     3,
       1,     3,     2,     0,     1,     1,     2,     2,     1,     2,
       2,     2,     1,     1,     1,     4,     2,     0,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     4,     2,     0,
       1,     2,     2,     2,     2,     2,     2,     1,     4,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     4,     2,     0,     1,     2,     1,     1,     1,
       4,     2,     0,     2,     1,     4,     0,     1,     2,     3,
       1,     4,     2,     2,     0,     1,     1,     2,     1,     1,
       2,     1,     4,     2,     0,     2,     1,     4,     2,     0,
       1,     1,     2,     2,     1,     4,     2,     0,     2,     2,
       2,     2,     1,     4,     2,     0,     2,     0,     2,     4,
       2,     2,     0,     2,     2,     1,     4,     2,     0,     2,
       2,     2,     2,     2,     1,     4,     2,     0,     2,     2,
       2,     2,     2,     2,     1,     4,     2,     0,     2,     2,
       2,     2,     2,     1,     4,     2,     0,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     4,     2,     0,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     4,     2,     0,     2,     2,     2,     1,
       4,     2,     0,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     2,     0,     1,     1,     1,
       2,     0,     2,     4,     2,     2,     0,     1,     2,     2,
       2,     1,     4,     2,     0,     2,     2,     2,     2,     1,
       0,     5,     2,     0,     2,     2,     2,     2,     2,     2,
       2,     0,     2,     0,     5,     2,     1,     1,     1,     1,
       2,     0,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     0,     2,     0,
       5,     2,     2,     0,     2,     2,     2,     2,     2,     2,
       3,     2,     0,     1,     2,     1,     1,     1,     4,     2,
       0,     1,     1,     2,     2,     2,     4,     1,     4,     2,
       0,     1,     2,     2,     2,     2,     2,     2,     2,     1,
       4,     2,     0,     1,     1,     2,     2,     2,     2,     2,
       1,     4,     2,     0,     2,     1,     4,     2,     0,     2,
       2,     1,     4,     2,     0,     2,     2,     1,     4,     2,
       0,     4,     2,     2,     2,     1,     4,     2,     0,     2,
       2,     2,     2,     2,     1,     4,     2,     0,     2,     2,
       2,     2,     2,     2,     2,     1,     4,     2,     0,     2,
       2,     2,     2,     1,     4,     2,     0,     2,     2,     1,
       4,     2,     0,     2,     2,     2,     1,     4,     2,     0,
       2,     2,     1,     4,     2,     0,     1,     2,     2,     2,
       1,     4,     2,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     4,     2,     0,
       2,     1,     4,     2,     0,     2,     2,     2,     1,     4,
       2,     0,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     4,     2,     0,     1,     2,     4,     2,
       2,     0,     2,     4,     2,     2,     0,     1,     1,     2,
       2,     2,     2,     1,     4,     2,     0,     2,     1,     4,
       2,     0,     2,     2,     2,     2,     1,     4,     2,     0,
       2,     2,     2,     2,     2,     2,     0,     2,     4,     2,
       2,     0,     2,     1,     4,     2,     0,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     2,     0,     2,     4,
       2,     2,     0,     2,     2,     2,     2,     2,     2,     0,
       2,     4,     2,     2,     0,     2,     2,     2,     1,     4,
       2,     0,     1,     2,     2,     1,     4
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
       0,     2,   134,   157,   181,   189,   211,   224,   245,   264,
     273,     0,     3,   319,   417,   450,   427,   509,   516,   522,
     530,   359,   546,   572,   558,   623,   658,   665,   461,   467,
     495,   484,     0,     0,     0,     0,     0,     1,    61,    58,
      60,    59,     5,     0,     6,     0,    47,     0,    48,     0,
       7,     0,     8,     0,    14,     0,    15,     0,    20,     0,
      44,     0,    49,   322,    50,     0,     0,     9,     0,    56,
       0,    10,     0,    11,     0,    52,     0,    16,     0,    17,
       0,    21,     0,    46,     0,    18,     0,    23,     0,    19,
       0,    55,     0,    57,     0,    22,     0,    45,     0,     0,
      12,     0,     0,    24,     0,    25,     0,     0,    13,     0,
       0,    53,    26,     0,     0,    51,   333,   340,   344,    63,
     656,    66,    65,     0,   657,   655,     4,   123,   149,   160,
     184,   204,   219,   242,   257,   267,   315,     0,   323,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   322,   342,
     336,   354,   412,   420,   442,   458,   464,   478,   487,   506,
     512,   519,   525,   533,   554,   561,   582,   575,   617,   609,
     621,   638,   626,   650,   642,   654,   661,     0,   196,   124,
     125,     0,     0,     0,     0,     0,     0,   132,   133,   123,
     128,   150,     0,     0,     0,     0,     0,     0,     0,   149,
     167,   168,   161,   162,   163,   164,   165,   166,   169,   170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   160,     0,   187,   188,     0,   184,   185,     0,   205,
     208,   209,   206,     0,   341,   204,   220,   221,     0,     0,
       0,   219,     0,    78,     0,   242,     0,     0,     0,     0,
       0,     0,     0,   257,     0,     0,     0,     0,     0,     0,
     267,     0,     0,     0,     0,   315,   325,    64,   327,   328,
     332,   330,   329,   324,   331,   334,     0,    85,   326,   321,
     338,   339,   337,     0,   336,     0,   413,   415,   416,     0,
       0,   412,   421,     0,   422,     0,     0,   341,   420,     0,
     443,     0,     0,   444,     0,     0,     0,   442,     0,    78,
       0,   458,     0,     0,     0,   464,     0,     0,     0,     0,
       0,     0,   478,     0,     0,     0,     0,     0,     0,     0,
       0,   487,     0,    78,     0,   506,     0,     0,     0,     0,
     512,     0,     0,     0,   519,   526,     0,     0,     0,     0,
     525,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   533,     0,     0,     0,     0,   554,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   561,
     576,     0,     0,   341,   575,     0,     0,     0,     0,     0,
       0,   609,     0,     0,   621,     0,     0,     0,     0,     0,
       0,     0,   633,   634,   627,     0,   626,   635,     0,     0,
       0,     0,     0,     0,   642,     0,   654,   662,     0,     0,
       0,   661,    74,   196,   200,   202,   197,   127,   126,   129,
     135,   130,   131,   122,   152,    68,    67,   154,   155,   153,
     151,   158,   156,   148,   182,   173,   174,   175,   176,   177,
     178,     0,    83,   171,     0,     0,    75,   172,   179,   180,
     159,   186,   190,   183,   207,   212,   210,   203,   225,   222,
     223,   218,   243,     0,   244,   246,   241,   258,   259,   260,
     261,   262,   263,   265,   256,   272,   268,   269,   270,   271,
     274,   266,   317,   318,   316,   320,   314,    97,     0,   343,
     335,   371,   397,   360,   353,   418,   414,   411,   424,   428,
     423,     5,   425,   419,   447,   449,   446,   451,   445,   448,
     441,   459,   460,   462,   457,   465,     0,     0,   120,   466,
     468,   463,   479,   480,   483,     0,   481,   482,   485,   477,
     488,   489,   494,   493,   491,   490,   492,   496,   486,   507,
     508,   510,   505,   515,   514,   513,   517,   511,   520,   521,
     523,   518,   528,   529,   531,   527,   524,   537,   539,   538,
     540,   541,   542,   439,   543,     0,   544,   545,   535,   534,
     536,   547,   532,   555,   556,   557,   559,   553,   562,   563,
     564,   571,   570,   568,   565,   567,   569,   566,   573,   560,
      62,   579,   583,     5,   577,   574,   612,   613,   614,   611,
     610,   618,   608,   622,   624,   620,   636,   640,   629,   630,
     628,   632,   631,   639,   625,   643,   644,   646,   645,   647,
     651,   641,   659,   653,   664,   666,   663,   660,   341,   341,
     198,    93,     0,   101,     0,     0,     0,    81,    86,   100,
      98,   146,   355,   475,   606,     0,     0,   371,     0,     0,
     351,   356,     0,    27,    28,     0,    29,     0,     0,    30,
      31,     0,    32,     0,    33,   194,   357,   232,   254,   312,
     294,     0,   593,   503,   551,     0,     0,   358,     0,    34,
       0,    35,     0,    36,     0,    37,     0,    38,     0,     0,
      39,   403,    40,     0,    41,     0,    42,     0,    43,   361,
       0,   117,     0,     0,    73,   430,     0,   201,   199,    84,
      96,    94,    76,   104,   102,    69,   109,     0,    99,   370,
     375,   138,   139,   144,   145,   140,   141,   142,   143,   137,
     346,   372,   363,   470,   601,   409,   396,   401,   192,   227,
     248,   276,   297,   398,   381,     0,   237,   376,   377,     0,
      77,    77,     0,   403,   498,   549,   586,   426,   118,   121,
       0,   431,     0,     0,     0,     0,     0,     0,     0,     0,
     430,   578,    95,   103,    82,   112,   110,   137,     0,   347,
       0,     0,     0,     0,   346,     0,     0,     0,     0,     0,
       0,     0,   363,     0,     0,     0,     0,     0,   470,     0,
       0,     0,     0,     0,   601,     0,     0,   192,     0,     0,
       0,     0,     0,   227,     0,     0,     0,     0,     0,     0,
     248,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   277,     0,     0,     0,   276,     0,     0,     0,
     298,     0,   301,     0,     0,   300,   299,     0,     0,     0,
       0,    78,   297,     0,     0,     0,     0,     0,     0,     0,
       0,   237,   378,   379,     0,    77,    77,    77,    77,     0,
     381,   406,     0,     0,     0,     0,   405,   216,     0,   404,
       0,   407,   408,   410,   402,   237,     0,     0,   498,     0,
       0,   549,     0,   588,     0,   587,     0,     0,     0,   586,
     119,    70,   432,   434,   435,   433,   437,   438,   440,   436,
     429,   111,   136,   147,   349,   350,   352,   348,   345,   364,
     365,   368,   366,   367,   369,   373,   362,   473,   474,     0,
     476,   113,   472,   469,   603,   604,   602,   605,   607,   600,
     193,   195,   191,   228,   229,   230,   231,   233,   226,   249,
     250,   251,   253,   252,   255,   247,   280,   455,     0,   281,
     282,   598,     0,   283,   285,   288,   286,   289,   290,   291,
     292,   293,   287,   278,   279,   295,   284,   275,   303,   305,
     302,   308,   306,   304,   313,     0,    87,   307,   309,   310,
     311,   296,   384,   385,   386,   390,   389,   391,   388,   387,
     383,   382,   394,   392,   393,   395,   399,   380,   236,   240,
     238,   235,   214,     0,    79,   501,   502,   499,   500,   504,
     497,   550,   552,   548,   590,   592,   594,   589,   591,   585,
     374,     0,   116,   114,   453,   596,   105,     0,   400,    78,
       0,     0,     0,   214,    89,     0,   471,   115,    78,     0,
     453,     0,     0,   596,    88,   108,   106,   234,   239,   215,
     217,   213,    80,    92,    90,   454,   456,   452,   597,   599,
     595,   107,    91,     0,     0,     0
};

static const short yydefgoto[] =
{
    1083,    37,    38,    39,    40,   787,   687,    41,   424,   601,
     120,   277,   123,   437,   456,   528,   996,   124,   457,   890,
     473,   891,   474,   453,   278,   997,  1055,   642,   498,   644,
    1047,   727,   942,   712,   529,   184,   185,   186,   187,   188,
     189,    43,    44,   788,   662,   663,   197,   198,   199,    45,
      46,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    47,    48,   225,   226,    49,    50,   816,
     817,   688,   689,   425,   426,   190,   233,   234,   235,    51,
      52,  1052,  1053,   888,   889,   238,   239,   240,   241,    53,
      54,   822,   823,   690,   691,  1050,   884,   885,   886,   244,
     245,    55,    56,   829,   830,   692,   693,   252,   253,    57,
      58,   259,   260,    59,    60,   844,   845,   846,   694,   695,
     857,   858,   859,   860,   861,   862,   696,   697,   264,   265,
      61,    62,   146,   147,   148,    63,    64,   283,   284,    65,
      66,    67,   792,   793,   794,   665,   666,   285,   504,    68,
     709,    69,   801,   802,   667,   668,  1040,   669,   760,   761,
     877,   878,   879,   880,   698,   699,  1048,   700,   762,   763,
     701,   702,   289,   290,   291,    70,    71,   295,   296,   297,
     298,    72,    73,   778,   779,   780,   575,   670,   304,   305,
     306,   307,    74,    75,  1059,  1060,   968,   969,   310,   311,
      76,    77,   314,   315,    78,    79,   806,   807,   808,   671,
     672,   321,   322,    80,    81,   330,   331,    82,    83,   897,
     898,   703,   704,   334,   335,    84,    85,   339,   340,    86,
      87,   343,   344,    88,    89,   348,   349,   350,    90,    91,
     361,   362,    92,    93,   900,   901,   705,   706,   366,   367,
      94,    95,   378,   379,    96,    97,   382,   383,   384,    98,
      99,   100,   906,   907,   908,   909,   707,   708,  1062,  1063,
     972,   973,   813,   814,   673,   674,   390,   391,   101,   102,
     103,   393,   394,   104,   105,   405,   406,   106,   107,   108,
     413,   414,   109,   110,   111,   415,   112,   113,   419,   420,
     421,   114,   115
};

static const short yypact[] =
{
    1304,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,  -190,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,    24,    68,   117,   170,   170,-32768,-32768,-32768,
  -32768,-32768,  1374,  -120,-32768,   -62,-32768,   -47,-32768,   -39,
  -32768,     0,-32768,     3,-32768,    56,-32768,    61,-32768,    93,
  -32768,   134,-32768,   440,-32768,   191,   138,-32768,   147,-32768,
     156,-32768,   182,-32768,   188,-32768,   190,-32768,   198,-32768,
     203,-32768,   224,-32768,   234,-32768,   245,-32768,   248,-32768,
     253,-32768,   272,-32768,   276,-32768,   280,-32768,   196,   284,
  -32768,   241,   305,-32768,   307,-32768,   202,   312,-32768,   274,
     314,-32768,-32768,   321,   323,-32768,-32768,   409,-32768,-32768,
  -32768,-32768,-32768,   170,-32768,-32768,-32768,    41,    90,   725,
     217,   491,    87,    87,   669,    -6,   171,   117,-32768,   365,
     117,   117,   170,   170,   365,   365,   169,    53,   440,-32768,
     315,-32768,    -2,   316,   236,    87,    87,   230,   -71,    87,
     247,    87,   -30,   514,   215,   291,-32768,   225,-32768,   343,
     428,-32768,   369,-32768,   388,     4,    -1,   170,  1197,-32768,
  -32768,   170,   170,   365,   327,    53,    53,-32768,-32768,    41,
  -32768,-32768,   117,   437,   437,   170,   365,   330,    53,    90,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
     332,    53,    53,    53,    53,    53,    53,    33,    46,    33,
      46,   725,   170,-32768,-32768,   335,   217,-32768,   117,-32768,
  -32768,-32768,-32768,   337,  1448,   491,-32768,-32768,   344,    33,
      46,    87,    33,-32768,   351,    87,   117,   170,   117,   170,
     170,   170,   352,   669,   170,   117,   170,   170,   170,   366,
      -6,   365,   170,   170,   367,   171,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,   365,-32768,-32768,-32768,
  -32768,-32768,-32768,   368,   315,    52,-32768,-32768,-32768,   379,
      53,    -2,-32768,   170,-32768,   381,    33,  1067,   316,   170,
  -32768,   170,   117,-32768,   382,    33,    53,   236,    33,-32768,
     384,    87,    33,    63,   385,    87,   117,   117,   170,   170,
     170,   387,   230,   170,   170,   170,   117,   170,   170,   170,
     398,   -71,    33,-32768,   399,    87,   117,   170,   170,   404,
     247,    33,    33,   405,    87,-32768,   117,   117,   410,    53,
     -30,   170,   170,   170,   170,   170,    82,   117,   170,   170,
     170,   414,   514,   117,   117,   170,   420,   215,   170,   170,
     170,   170,   117,   170,   170,   170,   170,   170,   426,   291,
  -32768,   523,   427,  1127,   225,   117,   437,   437,   117,   437,
     429,   343,   117,   444,   428,   526,   540,   170,   170,   170,
     170,   170,-32768,-32768,-32768,   445,   369,-32768,   170,   117,
     170,   170,   365,   446,   388,   447,     4,-32768,   365,   449,
      53,    -1,-32768,  1517,-32768,   975,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,   170,-32768,-32768,   170,   170,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,    76,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   101,-32768,
  -32768,   380,   735,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,  1374,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,   170,   170,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,   170,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,   370,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,  1374,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   915,  1448,
  -32768,-32768,    35,-32768,    60,   170,   170,-32768,-32768,   365,
  -32768,-32768,-32768,-32768,-32768,   562,   606,    70,   126,    58,
  -32768,-32768,   423,-32768,-32768,   451,-32768,   616,   453,-32768,
  -32768,   456,-32768,   464,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,   465,-32768,-32768,-32768,   662,   663,-32768,   468,-32768,
     475,-32768,   477,-32768,   478,-32768,   481,-32768,   650,   488,
  -32768,   422,-32768,   490,-32768,   492,-32768,   493,-32768,-32768,
     499,   500,   505,   170,-32768,   552,   508,-32768,-32768,-32768,
     170,-32768,-32768,   170,-32768,-32768,-32768,    69,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   472,
      22,-32768,   168,   -68,   329,-32768,-32768,-32768,   515,   214,
     255,   530,   375,-32768,   469,   117,   412,-32768,-32768,   686,
  -32768,-32768,   506,   422,  -100,   537,   301,-32768,   170,-32768,
     170,-32768,   117,   437,   437,   170,   117,   117,   509,    53,
     552,-32768,-32768,-32768,-32768,   170,-32768,   472,   510,-32768,
     117,   117,   512,    53,    22,   170,   170,   170,   170,   170,
     170,   516,   168,   117,   117,   714,   519,   523,   -68,   170,
     170,   170,   170,   520,   329,   170,   522,   515,   117,   117,
     170,   170,   524,   214,   117,   117,   117,   170,   170,   525,
     255,   322,    36,   117,   117,   170,   117,   523,   170,   523,
     170,   117,-32768,    38,   528,    33,   530,   117,   170,   117,
  -32768,   117,-32768,   117,   117,-32768,-32768,   529,    83,    63,
      83,-32768,   375,   679,   677,   117,   117,   170,   117,   117,
     117,   412,-32768,-32768,   686,-32768,-32768,-32768,-32768,   534,
     469,-32768,   723,   727,   724,   542,-32768,-32768,   543,-32768,
      20,-32768,-32768,-32768,-32768,   257,   197,   536,  -100,   170,
     539,   537,   722,-32768,   170,-32768,   546,    53,    33,   301,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   748,
  -32768,-32768,    12,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   550,-32768,
  -32768,-32768,   551,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,   170,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,   587,   582,   523,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,   756,   523,-32768,   579,   602,-32768,    80,-32768,-32768,
     569,    46,   570,   582,-32768,    25,-32768,-32768,-32768,   571,
     579,    83,   573,   602,-32768,   170,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,   523,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,   778,   779,-32768
};

static const short yypgoto[] =
{
  -32768,   -37,-32768,-32768,-32768,   279,-32768,-32768,     7,  -677,
      51,  -117,  -123,  -179,  -181,  -340,  -316,   -24,  -219,-32768,
  -32768,  -727,  -307,  -187,  -168,  -850,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,    14,   -76,   597,-32768,-32768,    49,   108,
  -32768,-32768,-32768,     1,-32768,-32768,   588,-32768,-32768,-32768,
     433,   572,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,   564,-32768,-32768,-32768,   -25,
  -32768,-32768,-32768,   371,  -416,   137,   560,-32768,-32768,-32768,
  -32768,  -255,-32768,-32768,  -449,   558,   165,   205,-32768,-32768,
  -32768,   -21,-32768,-32768,-32768,-32768,-32768,-32768,  -763,   574,
  -32768,-32768,-32768,   -15,-32768,-32768,-32768,   563,-32768,-32768,
  -32768,   545,-32768,-32768,-32768,   -29,-32768,-32768,-32768,-32768,
     -44,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   555,-32768,
  -32768,-32768,   673,-32768,-32768,-32768,  -495,   538,-32768,-32768,
  -32768,-32768,    30,-32768,-32768,-32768,   166,-32768,-32768,-32768,
  -32768,-32768,    27,-32768,-32768,-32768,-32768,   173,  -743,  -712,
  -32768,-32768,   -54,-32768,-32768,-32768,-32768,-32768,    71,-32768,
  -32768,-32768,   544,-32768,-32768,-32768,-32768,   533,-32768,-32768,
  -32768,-32768,-32768,    57,-32768,-32768,-32768,  -348,   531,-32768,
  -32768,-32768,-32768,-32768,  -227,-32768,-32768,   -27,   532,-32768,
  -32768,-32768,   535,-32768,-32768,-32768,    31,-32768,-32768,-32768,
     181,   527,-32768,-32768,-32768,   513,-32768,-32768,-32768,   -53,
  -32768,-32768,-32768,   511,-32768,-32768,-32768,   507,-32768,-32768,
  -32768,   504,-32768,-32768,-32768,   501,-32768,-32768,-32768,-32768,
     494,-32768,-32768,-32768,   -49,-32768,-32768,-32768,   486,-32768,
  -32768,-32768,   479,-32768,-32768,-32768,   473,-32768,-32768,-32768,
  -32768,-32768,   -50,-32768,-32768,-32768,-32768,-32768,  -203,-32768,
  -32768,    -3,    48,-32768,-32768,   206,   474,-32768,-32768,-32768,
  -32768,   480,-32768,-32768,-32768,   457,-32768,-32768,-32768,  -149,
     452,-32768,-32768,-32768,-32768,   455,  -161,-32768,   458,-32768,
  -32768,-32768,-32768
};


#define	YYLAST		1700


static const short yytable[] =
{
     177,   459,   522,   536,   537,   126,   664,    42,   576,   640,
     999,   875,   125,   116,   416,   438,   600,   431,   432,   271,
     272,   470,   268,   407,   600,   585,   550,   273,   274,   600,
     442,   117,   458,   323,   892,   895,   417,   121,   122,   121,
     122,   345,   876,   445,   446,   447,   448,   449,   450,    42,
     121,   122,   469,   887,   422,   472,   970,   618,   983,   267,
      26,   622,   803,   804,   121,   122,   429,   121,   122,   286,
     324,   628,   439,   121,   122,   118,   488,   896,   735,   440,
     121,   122,   494,   127,   121,   122,   971,   121,   122,   573,
     731,   653,     3,   789,   452,   455,   452,   455,   254,   181,
     182,    34,   572,   325,   326,   327,   328,   267,  1010,   510,
     178,   179,   180,   573,   346,   347,   452,   455,   518,   452,
     119,   521,   506,   329,   478,   525,   480,   481,   482,   805,
     941,   485,  1026,   487,   455,   655,   656,   875,   519,   493,
     455,   128,   181,   182,   492,   549,   733,   545,  1012,  1013,
    1014,  1015,   790,   791,   558,   559,   129,   427,   428,   497,
     978,   191,   980,   418,   130,   192,   193,   194,   876,   255,
     256,   257,   258,   452,   121,   122,   514,   654,   515,   223,
     230,   565,   452,    35,   660,   452,   711,    36,   266,   452,
     527,   269,   270,   594,   501,   502,   535,   535,   461,   280,
     540,   287,   542,   131,   544,   455,   132,   607,   608,   452,
     610,  1078,   887,  1024,  1042,   236,   237,  1027,   452,   452,
    1023,   402,   640,   718,   195,   149,  1072,  1073,   567,   568,
     569,   570,   571,   451,   489,   578,   719,   720,   224,   231,
     183,   466,   527,   434,   664,   588,   454,   590,   591,   166,
     593,   455,   636,   276,   597,   416,   503,   407,   281,   133,
     288,   722,   723,   526,   134,  1043,   171,   227,   232,   508,
     784,   785,   795,   643,   527,   223,   646,  1025,   527,   464,
     403,  1064,  1065,   995,   230,   625,   178,   282,   527,   196,
     261,   262,   664,   168,   534,   629,   135,   477,   242,   479,
     541,   634,   648,   649,   512,   546,   486,   222,   818,   404,
     363,   737,   364,   554,   555,   365,   299,   300,   181,   182,
     308,   312,   882,   883,   332,   316,   341,   317,   641,   173,
     318,   455,   645,   280,   224,   579,   580,   136,   243,   301,
     287,   150,   966,   231,   336,   589,  1054,   819,   263,   824,
     151,   595,   596,   516,   796,   797,   798,   799,   800,   152,
     309,   313,   967,   227,   333,  1057,   342,   532,   533,   319,
     320,   267,   232,   275,   619,   620,   621,   543,  1074,   380,
     381,   650,   820,   821,   178,   153,   627,   553,   825,   651,
     604,   154,   281,   155,   984,   368,  1082,   562,   563,   288,
     652,   156,   302,   527,   713,    11,   157,  1034,   577,   303,
     242,   573,   714,   653,   583,   584,   181,   182,   385,   386,
     387,   282,   826,   592,   827,  1011,   337,   158,   711,   828,
     338,   654,   369,  -637,   395,   396,   606,   159,   178,   609,
     388,   435,   436,   613,   370,   655,   656,  1028,   160,   647,
     243,   161,   657,   658,   659,   402,   162,   902,   903,   904,
     626,  -615,  -580,   724,  -648,   371,   372,   373,   374,   375,
     181,   182,   905,  -636,   710,   163,   308,   882,   883,   164,
     312,   651,   847,   165,   848,   376,   377,   167,   809,   810,
     849,   850,   851,   852,   945,   946,   947,    11,   292,   293,
     332,   294,   853,   573,   389,   653,   660,   854,   169,   341,
     170,  -371,   811,   812,   403,   172,   309,   174,    42,   721,
     313,   455,   725,   654,   175,   392,   176,   600,   397,   398,
     755,   430,   728,   616,   441,   855,   444,   655,   656,   462,
     333,   465,   783,   404,   657,   658,   659,   617,   468,   342,
     408,   409,   399,   400,  1000,   475,   483,   756,   757,   758,
     178,   137,   138,   139,   140,   141,   716,   401,   856,   729,
     490,   495,   499,   715,   863,   864,   865,   866,   867,   868,
     410,   411,   228,   505,   229,   509,   517,   412,   523,   530,
     770,   538,   181,   182,   913,   914,   869,   782,   660,   759,
     455,   870,   547,   551,   871,   757,   758,   872,   556,   560,
      42,   919,   142,   730,   564,   930,   931,   932,   581,   143,
     144,   145,   726,   771,   586,   927,   739,   772,   773,   774,
     598,   602,   775,   611,   873,   831,   832,   833,   834,   835,
     836,   837,   838,   839,   840,   527,   874,   911,   614,   623,
     630,   632,   915,   635,   740,   741,   742,   841,   986,   743,
     351,   352,   353,   354,   355,   356,   357,   744,   745,   746,
     747,   748,   929,   455,   455,   455,   933,   934,   749,  1046,
     750,   751,   776,   777,   752,   753,   944,   535,   535,   535,
     358,   754,   359,   764,   815,   765,   766,   955,   956,   842,
     767,   887,   768,   786,   962,   963,   769,   843,   360,   781,
     893,   899,   976,   918,   923,   979,   926,   981,   939,   967,
     935,  1038,   452,   940,   948,   989,   951,   971,   957,   964,
    1018,  1066,   985,   994,  1019,   535,   527,   535,  1016,  1037,
    1029,  1020,  1067,  1032,  1006,  1021,  1022,    11,   675,  1081,
    1036,  1075,  1041,  1044,  1045,   676,   677,  1049,   678,  1051,
    1056,   921,   679,   680,   246,   247,   248,   249,   250,   251,
    1058,   681,  1061,  1068,  1070,  1076,  1031,  1079,  1084,  1085,
     661,  1035,   910,   998,   682,   452,   433,   443,   922,   574,
     463,   950,   952,   460,   638,   467,   683,   684,  1071,   471,
     685,   686,   958,   200,   201,   491,   881,   202,   203,   204,
     205,   206,   207,   208,   209,   965,   484,   987,  1001,   476,
     496,   279,   500,   912,   928,   736,  1017,   916,   917,   936,
     732,   513,  1069,  1077,   894,   507,  1002,   920,   520,   943,
     738,   924,   925,   524,   548,  1030,   552,   557,   561,   539,
     531,   566,  1033,   587,   937,   938,   582,   605,   599,  1039,
    1080,  1003,   949,   624,   734,   612,   631,     0,     0,   953,
     954,   633,   535,     0,   615,   959,   960,   961,     0,   637,
       0,     0,     0,     0,   974,   975,     0,   977,     0,     0,
       0,     0,   982,     0,     0,     0,     0,     0,   988,     0,
     990,     0,   991,     0,   992,   993,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1004,  1005,     0,  1007,
    1008,  1009,     0,     2,   535,     3,     4,     5,   455,     6,
       0,     7,     0,     8,     9,     0,     0,     0,   535,    10,
      11,     0,   535,     0,    13,    14,     0,    15,     0,     0,
       0,     0,     0,    16,     0,     0,    17,    18,    19,    20,
      21,    22,    23,    24,     0,     0,     0,  -616,  -581,    25,
    -649,    26,    27,    28,    29,    30,     0,     0,    31,  -637,
      32,    33,     0,     2,     0,     3,     4,     5,     0,     6,
       0,     7,     0,     8,     9,     0,     0,     0,     0,    10,
      11,     0,     0,     0,    13,    14,     0,    15,     0,  -341,
       0,     0,    34,    16,     0,     0,    17,    18,    19,    20,
      21,    22,    23,    24,     0,     0,     0,  -616,  -581,    25,
    -649,    26,    27,    28,    29,    30,     0,     0,    31,     0,
      32,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     2,     0,     3,     4,     5,
       0,     6,     0,     7,     0,     8,     9,     0,     0,     0,
       0,    10,    11,     0,    35,     0,    13,    14,    36,    15,
       0,     0,     0,     0,     0,    16,     0,     0,    17,    18,
      19,    20,    21,    22,    23,    24,   717,   639,     0,  -616,
    -581,    25,  -649,    26,    27,    28,    29,    30,     0,     0,
      31,  -637,    32,    33,     0,     2,     0,     3,     4,     5,
       0,     6,     0,     7,     0,     8,     9,     0,     0,     0,
       0,    10,    11,     0,    35,     0,    13,    14,    36,    15,
       0,     0,     0,     0,    34,    16,     0,     0,    17,    18,
      19,    20,    21,    22,    23,    24,     0,   639,     0,  -616,
    -581,    25,  -649,    26,    27,    28,    29,    30,     0,     0,
      31,  -637,    32,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     3,     4,     5,
       0,     6,     0,     7,     0,     8,     9,     0,     0,     0,
       0,    10,    11,     0,    34,     0,    13,    14,     0,    15,
       0,     0,     0,     0,     0,    16,     0,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    35,     0,     0,     0,
      36,    25,     0,    26,    27,    28,    29,    30,     0,     0,
      31,     0,    32,    33,     0,     0,     0,   511,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    -5,     1,    35,     0,     0,     0,
      36,     0,     2,     0,     3,     4,     5,     0,     6,     0,
       7,     0,     8,     9,     0,     0,     0,   603,    10,    11,
      12,     0,     0,    13,    14,     0,    15,     0,  -341,     0,
       0,     0,    16,     0,     0,    17,    18,    19,    20,    21,
      22,    23,    24,     0,     0,     0,  -616,  -581,    25,  -649,
      26,    27,    28,    29,    30,     0,     0,    31,  -637,    32,
      33,     0,     0,     0,     0,     0,    35,     0,     0,     0,
      36,     0,     2,     0,     3,     4,     5,     0,     6,     0,
       7,     0,     8,     9,     0,     0,     0,   423,    10,    11,
       0,    34,     0,    13,    14,     0,    15,     0,  -341,     0,
       0,     0,    16,     0,     0,    17,    18,    19,    20,    21,
      22,    23,    24,     0,     0,     0,  -616,  -581,    25,  -649,
      26,    27,    28,    29,    30,     0,     0,    31,  -637,    32,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     3,     4,
       5,     0,     6,     0,     7,     0,     8,     9,     0,     0,
       0,    34,    10,    11,     0,     0,     0,    13,    14,     0,
      15,     0,     0,    35,     0,     0,    16,    36,     0,    17,
      18,    19,    20,    21,    22,    23,    24,     0,     0,     0,
    -616,  -581,    25,  -649,    26,    27,    28,    29,    30,     0,
       0,    31,  -637,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     3,     4,     5,
       0,     6,     0,     7,     0,     8,     9,     0,     0,     0,
       0,    10,    11,     0,     0,    34,    13,    14,     0,    15,
       0,     0,     0,    35,     0,    16,     0,    36,    17,    18,
      19,    20,    21,    22,    23,    24,     0,     0,     0,     0,
       0,    25,     0,    26,    27,    28,    29,    30,     0,     0,
      31,     0,    32,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    35,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,     0,     0,     0,
      36
};

static const short yycheck[] =
{
     123,   220,   309,   319,   320,    42,   501,     0,   356,   425,
     860,   754,    36,   203,   175,   194,     4,   185,   186,   142,
     143,   240,   139,   172,     4,   365,   333,   144,   145,     4,
     198,     7,   219,   104,   761,   135,    37,     4,     5,     4,
       5,    71,   754,   211,   212,   213,   214,   215,   216,    42,
       4,     5,   239,    15,   177,   242,    20,   397,    20,     6,
      56,   401,   130,   131,     4,     5,   183,     4,     5,    71,
     141,   411,   195,     4,     5,     7,   257,   177,    20,   196,
       4,     5,   263,   203,     4,     5,    50,     4,     5,    31,
      20,    33,    10,    71,   217,   218,   219,   220,   104,   101,
     102,    97,    20,   174,   175,   176,   177,     6,   871,   296,
      69,    70,    71,    31,   144,   145,   239,   240,   305,   242,
       3,   308,   290,   194,   247,   312,   249,   250,   251,   197,
     807,   254,   895,   256,   257,    65,    66,   880,   306,   262,
     263,   203,   101,   102,   261,   332,    20,   328,   875,   876,
     877,   878,   130,   131,   341,   342,   203,   181,   182,   276,
     837,    71,   839,   164,   203,    75,    76,    77,   880,   175,
     176,   177,   178,   296,     4,     5,   299,    51,   301,   130,
     131,   349,   305,   179,   126,   308,   526,   183,   137,   312,
     313,   140,   141,   374,   142,   143,   319,   320,   222,   150,
     323,   152,   325,   203,   327,   328,   203,   386,   387,   332,
     389,  1061,    15,   890,   202,   128,   129,    20,   341,   342,
     200,   172,   638,   639,   134,    34,   201,   202,   351,   352,
     353,   354,   355,   200,   258,   358,   201,   202,   130,   131,
     199,   234,   365,   192,   739,   368,   200,   370,   371,    53,
     373,   374,   420,   200,   377,   416,   204,   406,   150,   203,
     152,   201,   202,   200,   203,   942,    64,   130,   131,   293,
     201,   202,   104,   454,   397,   226,   200,    20,   401,   228,
     172,   201,   202,   200,   235,   408,    69,   150,   411,   199,
     119,   120,   787,    52,   318,   412,   203,   246,   133,   248,
     324,   418,   201,   202,   297,   329,   255,    90,    94,   172,
      95,   659,    97,   337,   338,   100,    80,    81,   101,   102,
     155,   156,    65,    66,   159,    95,   161,    97,   451,    55,
     100,   454,   455,   284,   226,   359,   360,   203,   133,   103,
     291,   203,    20,   235,    97,   369,  1023,   133,   177,    94,
     203,   375,   376,   302,   186,   187,   188,   189,   190,   203,
     155,   156,    40,   226,   159,  1042,   161,   316,   317,   139,
     140,     6,   235,   204,   398,   399,   400,   326,  1055,   154,
     155,   498,   168,   169,    69,   203,   410,   336,   133,     9,
     383,   203,   284,   203,   843,   104,  1073,   346,   347,   291,
      20,   203,   166,   526,   527,    25,   203,   902,   357,   173,
     245,    31,   535,    33,   363,   364,   101,   102,    75,    76,
      77,   284,   167,   372,   169,   874,   179,   203,   768,   174,
     183,    51,   141,    64,    65,    66,   385,   203,    69,   388,
      97,     4,     5,   392,   153,    65,    66,   896,   203,   473,
     245,   203,    72,    73,    74,   406,   203,   156,   157,   158,
     409,    52,    53,   644,    55,   174,   175,   176,   177,   178,
     101,   102,   171,    64,   511,   203,   311,    65,    66,   203,
     315,     9,   107,   203,   109,   194,   195,   203,   159,   160,
     115,   116,   117,   118,   810,   811,   812,    25,   182,   183,
     335,   185,   127,    31,   161,    33,   126,   132,   203,   344,
     203,    39,   183,   184,   406,   203,   311,   203,   511,   642,
     315,   644,   645,    51,   203,    97,   203,     4,   159,   160,
     108,   204,   649,     7,   204,   160,   204,    65,    66,   204,
     335,   204,   723,   406,    72,    73,    74,     7,   204,   344,
     162,   163,   183,   184,   861,   204,   204,   135,   136,   137,
      69,   121,   122,   123,   124,   125,   603,   198,   193,     7,
     204,   204,   204,   203,   105,   106,   107,   108,   109,   110,
     192,   193,    91,   204,    93,   204,   204,   199,   204,   204,
     713,   204,   101,   102,   773,   774,   127,   720,   126,   177,
     723,   132,   204,   204,   135,   136,   137,   138,   204,   204,
     603,   779,   172,     7,   204,   796,   797,   798,   204,   179,
     180,   181,   646,    71,   204,   793,   203,    75,    76,    77,
     204,   204,    80,   204,   165,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   768,   177,   770,   204,   204,
     204,   204,   775,   204,   203,    39,   203,   127,   845,   203,
     146,   147,   148,   149,   150,   151,   152,   203,   203,     7,
       7,   203,   795,   796,   797,   798,   799,   800,   203,   995,
     203,   203,   130,   131,   203,    35,   809,   810,   811,   812,
     176,   203,   178,   203,   179,   203,   203,   820,   821,   169,
     201,    15,   202,   727,   827,   828,   201,   177,   194,   201,
     204,   174,   835,   204,   204,   838,   204,   840,     4,    40,
     204,   908,   845,   204,   204,   848,   204,    50,   204,   204,
       7,  1047,   204,   204,     7,   858,   859,   860,   204,   907,
     204,    17,  1049,   204,   867,   203,   203,    25,    13,  1065,
     204,  1058,     4,   203,   203,    20,    21,   170,    23,   177,
       4,   785,    27,    28,    95,    96,    97,    98,    99,   100,
     191,    36,   170,   204,   204,   204,   899,   204,     0,     0,
     501,   904,   768,   859,    49,   908,   189,   199,   787,   356,
     226,   815,   817,   221,   423,   235,    61,    62,  1053,   241,
      65,    66,   823,    78,    79,   260,   755,    82,    83,    84,
      85,    86,    87,    88,    89,   830,   253,   846,   862,   245,
     265,   148,   284,   772,   794,   659,   880,   776,   777,   802,
     657,   298,  1051,  1060,   763,   291,   863,   780,   307,   808,
     659,   790,   791,   311,   331,   898,   335,   340,   344,   322,
     315,   350,   901,   367,   803,   804,   362,   384,   379,   909,
    1063,   864,   814,   406,   658,   391,   414,    -1,    -1,   818,
     819,   416,   995,    -1,   394,   824,   825,   826,    -1,   421,
      -1,    -1,    -1,    -1,   833,   834,    -1,   836,    -1,    -1,
      -1,    -1,   841,    -1,    -1,    -1,    -1,    -1,   847,    -1,
     849,    -1,   851,    -1,   853,   854,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   865,   866,    -1,   868,
     869,   870,    -1,     8,  1047,    10,    11,    12,  1051,    14,
      -1,    16,    -1,    18,    19,    -1,    -1,    -1,  1061,    24,
      25,    -1,  1065,    -1,    29,    30,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    63,    64,
      65,    66,    -1,     8,    -1,    10,    11,    12,    -1,    14,
      -1,    16,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    -1,    -1,    -1,    29,    30,    -1,    32,    -1,    34,
      -1,    -1,    97,    38,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    63,    -1,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    -1,    -1,     8,    -1,    10,    11,    12,
      -1,    14,    -1,    16,    -1,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    -1,   179,    -1,    29,    30,   183,    32,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,   201,   202,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      63,    64,    65,    66,    -1,     8,    -1,    10,    11,    12,
      -1,    14,    -1,    16,    -1,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    -1,   179,    -1,    29,    30,   183,    32,
      -1,    -1,    -1,    -1,    97,    38,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,   202,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      63,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    10,    11,    12,
      -1,    14,    -1,    16,    -1,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    -1,    97,    -1,    29,    30,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,   179,    -1,    -1,    -1,
     183,    54,    -1,    56,    57,    58,    59,    60,    -1,    -1,
      63,    -1,    65,    66,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     0,     1,   179,    -1,    -1,    -1,
     183,    -1,     8,    -1,    10,    11,    12,    -1,    14,    -1,
      16,    -1,    18,    19,    -1,    -1,    -1,   200,    24,    25,
      26,    -1,    -1,    29,    30,    -1,    32,    -1,    34,    -1,
      -1,    -1,    38,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
     183,    -1,     8,    -1,    10,    11,    12,    -1,    14,    -1,
      16,    -1,    18,    19,    -1,    -1,    -1,   200,    24,    25,
      -1,    97,    -1,    29,    30,    -1,    32,    -1,    34,    -1,
      -1,    -1,    38,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    10,    11,
      12,    -1,    14,    -1,    16,    -1,    18,    19,    -1,    -1,
      -1,    97,    24,    25,    -1,    -1,    -1,    29,    30,    -1,
      32,    -1,    -1,   179,    -1,    -1,    38,   183,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    10,    11,    12,
      -1,    14,    -1,    16,    -1,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    -1,    -1,    97,    29,    30,    -1,    32,
      -1,    -1,    -1,   179,    -1,    38,    -1,   183,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    56,    57,    58,    59,    60,    -1,    -1,
      63,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,    -1,
      -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
     183
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */

/* Skeleton output parser for bison,

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
   Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser when
   the %semantic_parser declaration is not specified in the grammar.
   It was written by Richard Stallman by simplifying the hairy parser
   used when %semantic_parser is specified.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
# if YYLSP_NEEDED
  YYLTYPE yyls;
# endif
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# if YYLSP_NEEDED
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAX)
# else
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)
# endif

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif


#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).

   When YYLLOC_DEFAULT is run, CURRENT is set the location of the
   first token.  By default, to implement support for ranges, extend
   its range to the last symbol.  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)       	\
   Current.last_line   = Rhs[N].last_line;	\
   Current.last_column = Rhs[N].last_column;
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#if YYPURE
# if YYLSP_NEEDED
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, &yylloc, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval, &yylloc)
#  endif
# else /* !YYLSP_NEEDED */
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval)
#  endif
# endif /* !YYLSP_NEEDED */
#else /* !YYPURE */
# define YYLEX			yylex ()
#endif /* !YYPURE */


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

#ifdef YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif
#endif



/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif

/* YY_DECL_VARIABLES -- depending whether we use a pure parser,
   variables are global, or local to YYPARSE.  */

#define YY_DECL_NON_LSP_VARIABLES			\
/* The lookahead symbol.  */				\
int yychar;						\
							\
/* The semantic value of the lookahead symbol. */	\
YYSTYPE yylval;						\
							\
/* Number of parse errors so far.  */			\
int yynerrs;

#if YYLSP_NEEDED
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES			\
						\
/* Location data for the lookahead symbol.  */	\
YYLTYPE yylloc;
#else
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES
#endif


/* If nonreentrant, generate the variables here. */

#if !YYPURE
YY_DECL_VARIABLES
#endif  /* !YYPURE */

int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  /* If reentrant, generate the variables here. */
#if YYPURE
  YY_DECL_VARIABLES
#endif  /* !YYPURE */

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack. */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

#if YYLSP_NEEDED
  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
#endif

#if YYLSP_NEEDED
# define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
# define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  YYSIZE_T yystacksize = YYINITDEPTH;


  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
#if YYLSP_NEEDED
  YYLTYPE yyloc;
#endif

  /* When reducing, the number of symbols on the RHS of the reduced
     rule. */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
#if YYLSP_NEEDED
  yylsp = yyls;
#endif
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  */
# if YYLSP_NEEDED
	YYLTYPE *yyls1 = yyls;
	/* This used to be a conditional around just the two extra args,
	   but that might be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
# else
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);
# endif
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
# if YYLSP_NEEDED
	YYSTACK_RELOCATE (yyls);
# endif
# undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
#if YYLSP_NEEDED
      yylsp = yyls + yysize - 1;
#endif

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

#if YYDEBUG
     /* We have to keep this `#if YYDEBUG', since we use variables
	which are defined only if `YYDEBUG' is set.  */
      if (yydebug)
	{
	  YYFPRINTF (stderr, "Next token is %d (%s",
		     yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise
	     meaning of a token, for further debugging info.  */
# ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
# endif
	  YYFPRINTF (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to the semantic value of
     the lookahead token.  This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

#if YYLSP_NEEDED
  /* Similarly for the default location.  Let the user run additional
     commands if for instance locations are ranges.  */
  yyloc = yylsp[1-yylen];
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
#endif

#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif

  switch (yyn) {

case 2:
{YYABORT;;
    break;}
case 3:
{YYABORT;;
    break;}
case 62:
{ _vectorInt32.push_back(yyvsp[0].ival); ;
    break;}
case 63:
{ yyval.bval = yyvsp[0].bval; ;
    break;}
case 64:
{;
    break;}
case 65:
{
		;
    break;}
case 66:
{
			yyval.fval = (float)yyvsp[0].ival;
		;
    break;}
case 68:
{yyval.fval = (float)yyvsp[0].ival;;
    break;}
case 69:
{
			_color[0] = yyvsp[-2].fval;
			_color[1] = yyvsp[-1].fval;
			_color[2] = yyvsp[0].fval;
	    ;
    break;}
case 70:
{
			gRotation[0] = yyvsp[-3].fval;
			gRotation[1] = yyvsp[-2].fval;
			gRotation[2] = yyvsp[-1].fval;
			gRotation[3] = yyvsp[0].fval;
		;
    break;}
case 71:
{
			gWidth = yyvsp[-2].ival;
			gHeight = yyvsp[-1].ival;
			gComponents = yyvsp[0].ival;
	    ;
    break;}
case 73:
{
			gVec2f[0] = yyvsp[-1].fval;
			gVec2f[1] = yyvsp[0].fval;
		;
    break;}
case 74:
{ _vectorVector.push_back(Vector(yyvsp[-2].fval,yyvsp[-1].fval,yyvsp[0].fval)); ;
    break;}
case 75:
{;
    break;}
case 76:
{;
    break;}
case 77:
{ _vectorInt32.clear(); ;
    break;}
case 78:
{ _vectorVector.clear(); ;
    break;}
case 79:
{;
    break;}
case 80:
{;
    break;}
case 83:
{;
    break;}
case 84:
{;
    break;}
case 85:
{;
    break;}
case 86:
{;
    break;}
case 87:
{;
    break;}
case 88:
{;
    break;}
case 89:
{;
    break;}
case 90:
{;
    break;}
case 91:
{;
    break;}
case 92:
{;
    break;}
case 93:
{;
    break;}
case 94:
{;
    break;}
case 95:
{;
    break;}
case 96:
{;
    break;}
case 97:
{;
    break;}
case 98:
{;
    break;}
case 99:
{;
    break;}
case 100:
{;
    break;}
case 101:
{;
    break;}
case 102:
{;
    break;}
case 103:
{;
    break;}
case 104:
{;
    break;}
case 105:
{;
    break;}
case 106:
{;
    break;}
case 107:
{;
    break;}
case 108:
{;
    break;}
case 109:
{;
    break;}
case 110:
{;
    break;}
case 111:
{;
    break;}
case 112:
{;
    break;}
case 113:
{;
    break;}
case 114:
{;
    break;}
case 115:
{;
    break;}
case 116:
{;
    break;}
case 124:
{
		;
    break;}
case 125:
{
		;
    break;}
case 126:
{
		;
    break;}
case 127:
{
		;
    break;}
case 129:
{
		;
    break;}
case 130:
{
		;
    break;}
case 131:
{
		;
    break;}
case 134:
{   
		;
    break;}
case 135:
{
		;
    break;}
case 146:
{
		;
    break;}
case 147:
{
		;
    break;}
case 150:
{
		;
    break;}
case 151:
{
		;
    break;}
case 152:
{
		;
    break;}
case 153:
{
		;
    break;}
case 154:
{
		;
    break;}
case 155:
{
		;
    break;}
case 156:
{
		;
    break;}
case 157:
{
		;
    break;}
case 158:
{
		;
    break;}
case 161:
{
		;
    break;}
case 162:
{
		;
    break;}
case 163:
{
		;
    break;}
case 164:
{
		;
    break;}
case 165:
{
		;
    break;}
case 166:
{
		;
    break;}
case 167:
{
		;
    break;}
case 168:
{
		;
    break;}
case 169:
{
		;
    break;}
case 170:
{
		;
    break;}
case 171:
{
		;
    break;}
case 172:
{
		;
    break;}
case 173:
{
		;
    break;}
case 174:
{
		;
    break;}
case 175:
{
		;
    break;}
case 176:
{
		;
    break;}
case 177:
{
		;
    break;}
case 178:
{
		;
    break;}
case 179:
{
		;
    break;}
case 180:
{
		;
    break;}
case 181:
{
		;
    break;}
case 182:
{
		;
    break;}
case 186:
{
		;
    break;}
case 189:
{   
		;
    break;}
case 190:
{
		;
    break;}
case 193:
{
		;
    break;}
case 194:
{
		;
    break;}
case 195:
{
		;
    break;}
case 196:
{;
    break;}
case 197:
{;
    break;}
case 198:
{;
    break;}
case 199:
{;
    break;}
case 200:
{;
    break;}
case 205:
{
		;
    break;}
case 207:
{
		;
    break;}
case 210:
{
		;
    break;}
case 211:
{   
		;
    break;}
case 212:
{
		;
    break;}
case 216:
{
		;
    break;}
case 217:
{
		;
    break;}
case 220:
{
		;
    break;}
case 221:
{
		;
    break;}
case 222:
{
		;
    break;}
case 223:
{
		;
    break;}
case 224:
{
		;
    break;}
case 225:
{
		;
    break;}
case 228:
{
		;
    break;}
case 229:
{
		;
    break;}
case 230:
{
		;
    break;}
case 231:
{
		;
    break;}
case 232:
{
		;
    break;}
case 233:
{
		;
    break;}
case 236:
{;
    break;}
case 237:
{;
    break;}
case 238:
{
		;
    break;}
case 239:
{;
    break;}
case 240:
{;
    break;}
case 243:
{
		;
    break;}
case 244:
{
		;
    break;}
case 245:
{
		;
    break;}
case 246:
{
		;
    break;}
case 249:
{
		;
    break;}
case 250:
{
		;
    break;}
case 251:
{
		;
    break;}
case 252:
{
		;
    break;}
case 253:
{
		;
    break;}
case 254:
{
		;
    break;}
case 255:
{
		;
    break;}
case 258:
{
		;
    break;}
case 259:
{
		;
    break;}
case 260:
{
		;
    break;}
case 261:
{
		;
    break;}
case 262:
{
		;
    break;}
case 263:
{
		;
    break;}
case 264:
{
		;
    break;}
case 265:
{
		;
    break;}
case 268:
{
		;
    break;}
case 269:
{
		;
    break;}
case 270:
{
		;
    break;}
case 271:
{
		;
    break;}
case 272:
{
		;
    break;}
case 273:
{
		;
    break;}
case 274:
{
		;
    break;}
case 277:
{
		;
    break;}
case 284:
{
		;
    break;}
case 285:
{
		;
    break;}
case 286:
{
		;
    break;}
case 287:
{
		;
    break;}
case 288:
{
		;
    break;}
case 289:
{
		;
    break;}
case 290:
{
		;
    break;}
case 291:
{
		;
    break;}
case 292:
{
		;
    break;}
case 293:
{
		;
    break;}
case 294:
{
		;
    break;}
case 295:
{
		;
    break;}
case 298:
{
		;
    break;}
case 299:
{
		;
    break;}
case 300:
{
		;
    break;}
case 301:
{
		;
    break;}
case 302:
{
		;
    break;}
case 303:
{
		;
    break;}
case 304:
{
		;
    break;}
case 305:
{
		;
    break;}
case 306:
{
		;
    break;}
case 307:
{
		;
    break;}
case 308:
{
		;
    break;}
case 309:
{
		;
    break;}
case 310:
{
		;
    break;}
case 311:
{
		;
    break;}
case 312:
{
		;
    break;}
case 313:
{
		;
    break;}
case 316:
{
		;
    break;}
case 317:
{
		;
    break;}
case 318:
{
		;
    break;}
case 319:
{
		;
    break;}
case 320:
{
		;
    break;}
case 323:
{
		;
    break;}
case 324:
{
		;
    break;}
case 325:
{
		;
    break;}
case 326:
{
		;
    break;}
case 327:
{
		;
    break;}
case 328:
{
		;
    break;}
case 329:
{
		;
    break;}
case 330:
{
		;
    break;}
case 331:
{
		;
    break;}
case 332:
{
		;
    break;}
case 333:
{
		;
    break;}
case 334:
{
		;
    break;}
case 340:
{;
    break;}
case 341:
{;
    break;}
case 342:
{;
    break;}
case 343:
{;
    break;}
case 344:
{;
    break;}
case 347:
{
		;
    break;}
case 348:
{
		;
    break;}
case 349:
{
		;
    break;}
case 350:
{
		;
    break;}
case 351:
{
		;
    break;}
case 352:
{
		;
    break;}
case 353:
{;
    break;}
case 354:
{;
    break;}
case 359:
{
			#ifdef YYDEBUG
			cout << "Shape" << endl;
			#endif

			_faceSet.clear();
			_material.clear();
		;
    break;}
case 360:
{
			if (VrmlParseShape)
			{
				Shape *shape = new Shape();
				shape->faces    = _faceSet;
				shape->material = _material;
				GltShapePtr ptr(shape);
				VrmlParseShape(ptr);
			}
		;
    break;}
case 361:
{
		;
    break;}
case 362:
{;
    break;}
case 363:
{;
    break;}
case 364:
{ assert(_material.get()); _material->ambientIntensity = yyvsp[0].fval;     ;
    break;}
case 365:
{ assert(_material.get()); _material->diffuseColor     = _color; ;
    break;}
case 366:
{ assert(_material.get()); _material->emissiveColor    = _color; ;
    break;}
case 367:
{ assert(_material.get()); _material->shininess        = yyvsp[0].fval;     ;
    break;}
case 368:
{ assert(_material.get()); _material->specularColor    = _color; ;
    break;}
case 369:
{ assert(_material.get()); _material->transparency     = yyvsp[0].fval;     ;
    break;}
case 370:
{;
    break;}
case 371:
{;
    break;}
case 372:
{
			#ifdef YYDEBUG
			cout << "Material" << endl;
			#endif

			_material = new Material();
		;
    break;}
case 373:
{
			if (VrmlParseMaterial)
				VrmlParseMaterial(_material);
		;
    break;}
case 374:
{;
    break;}
case 375:
{;
    break;}
case 376:
{;
    break;}
case 377:
{;
    break;}
case 378:
{;
    break;}
case 379:
{;
    break;}
case 380:
{;
    break;}
case 381:
{;
    break;}
case 382:
{;
    break;}
case 383:
{ assert(_faceSet.get()); _faceSet->coord  = _vectorVector; ;
    break;}
case 384:
{ assert(_faceSet.get()); _faceSet->normal = _vectorVector; ;
    break;}
case 385:
{;
    break;}
case 386:
{ assert(_faceSet.get()); _faceSet->ccw             = yyvsp[0].bval; ;
    break;}
case 387:
{ assert(_faceSet.get()); _faceSet->convex          = yyvsp[0].bval; ;
    break;}
case 388:
{ assert(_faceSet.get()); _faceSet->solid           = yyvsp[0].bval; ;
    break;}
case 389:
{ assert(_faceSet.get()); _faceSet->creaseAngle     = yyvsp[0].fval; ;
    break;}
case 390:
{ assert(_faceSet.get()); _faceSet->colorPerVertex  = yyvsp[0].bval; ;
    break;}
case 391:
{ assert(_faceSet.get()); _faceSet->normalPerVertex = yyvsp[0].bval; ;
    break;}
case 392:
{ assert(_faceSet.get()); _faceSet->coordIndex    = _vectorInt32; ;
    break;}
case 393:
{ assert(_faceSet.get()); _faceSet->normalIndex   = _vectorInt32; ;
    break;}
case 394:
{ assert(_faceSet.get()); _faceSet->colorIndex    = _vectorInt32; ;
    break;}
case 395:
{ assert(_faceSet.get()); _faceSet->texCoordIndex = _vectorInt32; ;
    break;}
case 396:
{;
    break;}
case 397:
{;
    break;}
case 398:
{
			#ifdef YYDEBUG
			cout << "Indexed Face Set" << endl;
			#endif

			_faceSet = new IndexedFaceSet();
		;
    break;}
case 399:
{
			assert(_faceSet.get());

			#ifdef YYDEBUG
			cout << _faceSet->coord.size()      << " points."       << endl;
			cout << _faceSet->normal.size()     << " normals."      << endl;
			cout << _faceSet->coordIndex.size() << " face entries." << endl;
			#endif

			if (VrmlParseIndexedFaceSet)
				VrmlParseIndexedFaceSet(_faceSet);
		;
    break;}
case 400:
{;
    break;}
case 401:
{;
    break;}
case 406:
{
		;
    break;}
case 407:
{
		;
    break;}
case 408:
{
		;
    break;}
case 409:
{
		;
    break;}
case 410:
{
		;
    break;}
case 413:
{
		;
    break;}
case 414:
{
		;
    break;}
case 417:
{   
		;
    break;}
case 418:
{
		;
    break;}
case 421:
{
		;
    break;}
case 422:
{
		;
    break;}
case 423:
{
		;
    break;}
case 424:
{
		;
    break;}
case 425:
{
		;
    break;}
case 426:
{
		;
    break;}
case 427:
{   
		;
    break;}
case 428:
{
		;
    break;}
case 431:
{
		;
    break;}
case 432:
{
		;
    break;}
case 433:
{
		;
    break;}
case 434:
{
		;
    break;}
case 435:
{
		;
    break;}
case 436:
{
		;
    break;}
case 437:
{
		;
    break;}
case 438:
{
		;
    break;}
case 439:
{
		;
    break;}
case 440:
{
		;
    break;}
case 443:
{
		;
    break;}
case 444:
{
		;
    break;}
case 445:
{
		;
    break;}
case 446:
{
		;
    break;}
case 447:
{
		;
    break;}
case 448:
{
		;
    break;}
case 449:
{
		;
    break;}
case 450:
{
		;
    break;}
case 451:
{
		;
    break;}
case 455:
{
		;
    break;}
case 456:
{
			#ifdef YYDEBUG
			cout << _vectorVector.size() << " normals." << endl;
			#endif
		;
    break;}
case 459:
{
		;
    break;}
case 460:
{
		;
    break;}
case 461:
{
		;
    break;}
case 462:
{
		;
    break;}
case 465:
{
		;
    break;}
case 466:
{
		;
    break;}
case 467:
{
		;
    break;}
case 468:
{
		;
    break;}
case 471:
{
		;
    break;}
case 472:
{
		;
    break;}
case 473:
{
		;
    break;}
case 474:
{
		;
    break;}
case 475:
{
		;
    break;}
case 476:
{
		;
    break;}
case 479:
{
		;
    break;}
case 480:
{
		;
    break;}
case 481:
{
		;
    break;}
case 482:
{
		;
    break;}
case 483:
{
		;
    break;}
case 484:
{
		;
    break;}
case 485:
{
		;
    break;}
case 488:
{
		;
    break;}
case 489:
{
		;
    break;}
case 490:
{
		;
    break;}
case 491:
{
		;
    break;}
case 492:
{
		;
    break;}
case 493:
{
		;
    break;}
case 494:
{
		;
    break;}
case 495:
{
		;
    break;}
case 496:
{
		;
    break;}
case 503:
{
		;
    break;}
case 504:
{
		;
    break;}
case 507:
{
		;
    break;}
case 508:
{
		;
    break;}
case 509:
{
		;
    break;}
case 510:
{
		;
    break;}
case 513:
{
		;
    break;}
case 514:
{
		;
    break;}
case 515:
{
		;
    break;}
case 516:
{
		;
    break;}
case 517:
{
		;
    break;}
case 520:
{
		;
    break;}
case 521:
{
		;
    break;}
case 522:
{
		;
    break;}
case 523:
{
		;
    break;}
case 526:
{
		;
    break;}
case 527:
{
		;
    break;}
case 528:
{
		;
    break;}
case 529:
{
		;
    break;}
case 530:
{
		;
    break;}
case 531:
{
		;
    break;}
case 534:
{
		;
    break;}
case 535:
{
		;
    break;}
case 536:
{
		;
    break;}
case 537:
{
		;
    break;}
case 538:
{
		;
    break;}
case 539:
{
		;
    break;}
case 540:
{
		;
    break;}
case 541:
{
		;
    break;}
case 545:
{
		;
    break;}
case 546:
{
		;
    break;}
case 547:
{
		;
    break;}
case 550:
{
		;
    break;}
case 551:
{
		;
    break;}
case 552:
{
		;
    break;}
case 555:
{
		;
    break;}
case 556:
{
		;
    break;}
case 557:
{
		;
    break;}
case 558:
{
		;
    break;}
case 559:
{
		;
    break;}
case 562:
{
		;
    break;}
case 563:
{
		;
    break;}
case 564:
{
		;
    break;}
case 565:
{
		;
    break;}
case 566:
{
		;
    break;}
case 567:
{
		;
    break;}
case 568:
{
		;
    break;}
case 569:
{
		;
    break;}
case 570:
{
		;
    break;}
case 571:
{
		;
    break;}
case 572:
{
		;
    break;}
case 573:
{
		;
    break;}
case 576:
{
		;
    break;}
case 577:
{
		;
    break;}
case 578:
{
		;
    break;}
case 579:
{
		;
    break;}
case 580:
{;
    break;}
case 581:
{;
    break;}
case 582:
{;
    break;}
case 583:
{;
    break;}
case 584:
{;
    break;}
case 587:
{
		;
    break;}
case 588:
{
		;
    break;}
case 589:
{
		;
    break;}
case 592:
{
		;
    break;}
case 593:
{
		;
    break;}
case 594:
{
		;
    break;}
case 598:
{
		;
    break;}
case 599:
{
		;
    break;}
case 602:
{
		;
    break;}
case 603:
{
		;
    break;}
case 604:
{
		;
    break;}
case 605:
{
		;
    break;}
case 606:
{
		;
    break;}
case 607:
{
		;
    break;}
case 610:
{
		;
    break;}
case 611:
{
		;
    break;}
case 612:
{
		;
    break;}
case 613:
{
		;
    break;}
case 614:
{
		;
    break;}
case 615:
{;
    break;}
case 616:
{;
    break;}
case 617:
{;
    break;}
case 618:
{;
    break;}
case 619:
{;
    break;}
case 622:
{
		;
    break;}
case 623:
{
		;
    break;}
case 624:
{
		;
    break;}
case 628:
{
		;
    break;}
case 629:
{
		;
    break;}
case 630:
{
		;
    break;}
case 631:
{
		;
    break;}
case 632:
{
		;
    break;}
case 636:
{;
    break;}
case 637:
{;
    break;}
case 638:
{;
    break;}
case 639:
{;
    break;}
case 640:
{;
    break;}
case 643:
{;
    break;}
case 644:
{;
    break;}
case 645:
{;
    break;}
case 646:
{;
    break;}
case 647:
{;
    break;}
case 648:
{;
    break;}
case 649:
{;
    break;}
case 650:
{;
    break;}
case 651:
{;
    break;}
case 652:
{;
    break;}
case 655:
{
		;
    break;}
case 656:
{
		;
    break;}
case 657:
{
		;
    break;}
case 658:
{
		;
    break;}
case 659:
{
		;
    break;}
case 662:
{
		;
    break;}
case 663:
{
		;
    break;}
case 664:
{
		;
    break;}
case 665:
{
		;
    break;}
case 666:
{
		;
    break;}
}



  yyvsp -= yylen;
  yyssp -= yylen;
#if YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;
#if YYLSP_NEEDED
  *++yylsp = yyloc;
#endif

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[YYTRANSLATE (yychar)]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[YYTRANSLATE (yychar)]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* defined (YYERROR_VERBOSE) */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*--------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action |
`--------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;
      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;


/*-------------------------------------------------------------------.
| yyerrdefault -- current state does not do anything special for the |
| error token.                                                       |
`-------------------------------------------------------------------*/
yyerrdefault:
#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */

  /* If its default is to accept any token, ok.  Otherwise pop it.  */
  yyn = yydefact[yystate];
  if (yyn)
    goto yydefault;
#endif


/*---------------------------------------------------------------.
| yyerrpop -- pop the current state because it cannot handle the |
| error token                                                    |
`---------------------------------------------------------------*/
yyerrpop:
  if (yyssp == yyss)
    YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#if YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "Error: state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

/*--------------.
| yyerrhandle.  |
`--------------*/
yyerrhandle:
  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

/*---------------------------------------------.
| yyoverflowab -- parser overflow comes here.  |
`---------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#include <iostream>
using namespace std;

extern  char    *Vrmltext;
extern  int      VrmlCurrentLine;

int yyerror(char *s) 
{ 
	cerr << "VRML " << s << " in line " << VrmlCurrentLine << " near " << Vrmltext << endl;
	return 0;
}
