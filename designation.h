#ifndef DESIGNATION_H
#define DESIGNATION_H
#include <QDebug>
#include <iostream>
#include <cmath>
#include <vector>
#include <qdynamicbutton.h>

#define COEFFICIENT_DOP_RASHOD 1.05
#define PRICE_TG_430_S1 380.0
#define PRICE_URSA_M25 460.0
#define PRICE_LENTA_REMENNAYA 2.88
#define PRICE_TEXTIL_PETLYA 23.0
#define PRICE_TEXTIL_CRUCHOK 23.0
#define PRICE_SHPIL 15.0
#define PRICE_NITKI_STEEL 3.2
#define PRICE_NITKI_ARAMID 1.0
#define PRICE_D_RING 17.0
#define PRICE_ETICKET 10.0
#define PRICE_D_RING_ECONOM 5.0
#define PRICE_PROVOLOKA 12.0
#define PRICE_CONSTRUCTOR 254.14
#define PRICE_TECHNOLOG 224.38
#define PRICE_SHVEYA 300
#define PRICE_PRINT 40
#define PRICE_M2 0
#define PRICE_ARENDA_M2 400
#define PRICE_WORK_PLACE 8
#define PRICE_WORK_PLACE_AUP 2.5
#define PRICE_WORK_MONTH 20.5
#define PRICE_WORK_DURATION 8
#define PRICE_SQUARE_SHVEI 280
#define PRICE_SQUARE_OFFICE 0
#define PRICE_KWT_HOUR 0.160875
#define PRICE_KWT_PRICE 5.5

enum ProductType {
  PT_STANDART = 1,
  PT_MATRAS = 0,
  PT_OTHER = 2,
};

enum BodyType {
  BT_0 = 0,
  BT_1 = 1,
  BT_2 = 2,
  BT_3 = 3,
  BT_4 = 4,
  BT_5 = 5,
  BT_6 = 6,
  BT_7 = 7,
  BT_8 = 8,
  BT_9 = 9,
  BT_10 = 10,
  BT_11 = 11,
};

enum FireGroup {
  FG_NG = 1,
  FG_G1 = 0,
};

enum NitType {
  NT_STEEL = 0,
  NT_ARAMID = 1,
};

enum Placement {
  PL_STREET = 1,
  PL_HOUSE = 0,
};

enum Triangle {
  TR_WIDE = 0,
  TR_UZKAYA = 1,
  TR_NONE = 2,
};

enum DRingsType {
  DRT_STEEL = 0,
  DRT_NIKEL = 1,
};

enum AdditionHolder {
  AH_YES = 1,
  AH_NO = 0,
};

enum P_N_ {
  PN_1_10 = 0,
  PN_10 = 100,
  PN_16 = 1,
  PN_25 = 2,
  PN_40 = 3,
  PN_63 = 4,
  PN_100 = 5,
  PN_160 = 6,
};

enum D_Y_ {
  DY_10 = 0,
  DY_15 = 1,
  DY_20 = 2,
  DY_25 = 3,
  DY_32 = 4,
  DY_40 = 5,
  DY_50 = 6,
  DY_65 = 7,
  DY_80 = 8,
  DY_100 = 9,
  DY_125 = 10,
  DY_150 = 11,
  DY_175 = 12,
  DY_200 = 13,
  DY_225 = 14,
  DY_250 = 15,
  DY_300 = 16,
  DY_350 = 17,
  DY_400 = 18,
  DY_450 = 19,
  DY_500 = 20,
  DY_600 = 21,
  DY_700 = 22,
  DY_800 = 23,
  DY_900 = 24,
  DY_1000 = 25,
  DY_1200 = 26,
};

enum T_M_ {
  TM_MINUS_60 = 0,
  TM_MINUS_30 = 1,
  TM_50 = 2,
  TM_100 = 3,
  TM_150 = 4,
  TM_200 = 5,
  TM_250 = 6,
  TM_300 = 7,
  TM_350 = 8,
  TM_400 = 9,
  TM_450 = 10,
  TM_500 = 11,
  TM_600 = 12,
  TM_700 = 13,
  TM_800 = 14,
  TM_900 = 15,
  TM_1000 = 16,
};

enum PriceWarm {
  PW_URSA_M11 = 0,
  PW_URSA_M25 = 1,
  PW_WIRED_MAT = 2,
  PW_TEX_MAT = 3,
  PW_URSA_M25_M11 = 4,
};

struct My {
  uint CurrentPosition;
  std::vector<uint> Position;
  std::vector<uint> ProductCount;
  std::vector<uint> ProductType;
  std::vector<uint> BodyType;
  std::vector<uint> Dy;
  std::vector<uint> Temperature;
  std::vector<bool> FireGroup;
  std::vector<bool> Placement;
  std::vector<uint> Triangle;
  std::vector<uint> TriangleCount;
  std::vector<bool> DRingsType;
  std::vector<bool> AdditionHolder;
  std::vector<uint> PN;
  std::vector<double> PriceOne;
  std::vector<double> PriceAll;
  std::vector<double> Vvv;
  std::vector<double> Weight;
};

struct MyAdd {
  double CoeffObrez;
  uint DFlanz;
  uint L;
  uint HOtv;
  uint DOtv;
  uint WarmValue;
  uint LShpil;
  uint SFlanz;
  uint LTriangle;
  double DTriangle;
  uint LChehla;
  uint DTriangleHalfCount;
  double TimeConstructor;
  double TimeShveya;
  double TimeTechnolog;
  uint PriceWarm;
  uint WarmWidth;
  uint WarmType;

};

void PushData(My& data, uint pos, uint pcount, uint ptype, uint btype, uint dy,
              uint pn, uint t, bool fgroup, bool place, uint tri, uint tricount,
              bool drtype, bool addh) {
  data.CurrentPosition = pos - 1;
  data.Position.push_back(pos);
  data.ProductCount.push_back(pcount);
  data.ProductType.push_back(ptype);
  data.BodyType.push_back(btype);
  data.Dy.push_back(dy);
  data.Temperature.push_back(t);
  data.FireGroup.push_back(fgroup);
  data.Placement.push_back(place);
  data.Triangle.push_back(tri);
  data.TriangleCount.push_back(tricount);
  data.DRingsType.push_back(drtype);
  data.AdditionHolder.push_back(addh);
  data.PN.push_back(pn);
  data.PriceOne.push_back(0);
  data.PriceAll.push_back(0);
  data.Vvv.push_back(0);
  data.Weight.push_back(0);
}

double Out(My& data, MyAdd& dataAdd) {
  double out;
  if (data.BodyType[data.CurrentPosition] == BT_11) {
    out = 0;
  } else {
    double A = (((((dataAdd.DFlanz + (dataAdd.WarmValue * 2.0 * 1.2) +
                    (dataAdd.DFlanz * 0.15) + 10.0) *
                   3.14 / 1000.0)) *
                 dataAdd.LChehla) +
                ((3.14 * dataAdd.DFlanz * dataAdd.DFlanz / 4.0 + 10.0) * 1.0 /
                 1000.0)) *
               dataAdd.CoeffObrez / 1000.0;
    double B =
        (((((dataAdd.DOtv + (dataAdd.WarmValue * 2.0) + (dataAdd.DOtv * 0.15) +
             10.0) *
            3.14 / 1000.0)) *
          dataAdd.HOtv) +
         (((3.14 * dataAdd.DOtv * dataAdd.DOtv / 4.0) + 10.0) * 1.0 / 1000.0)) *
        dataAdd.CoeffObrez / 1000.0;
    double C;
    if (data.ProductType[data.CurrentPosition] == PT_OTHER) {
      C = (((dataAdd.LTriangle * 3.14 / 1000.0) * (dataAdd.DTriangle + 50.0) *
            data.TriangleCount[data.CurrentPosition])) /
          1000.0 * 1.2;
    } else {
      C = 0;
    }
    out = A + B + C;
  }
  double result = out;
  return result;
}

double In(My& data, MyAdd& dataAdd) {
  double in = 0;
  if (data.BodyType[data.CurrentPosition] == BT_11) {
    in = 0;
  } else {
    double A =
        ((((dataAdd.DOtv + dataAdd.DOtv * 0.15 + 10) * 3.14 / 1000.0) *
          dataAdd.HOtv) +
         (3.14 * dataAdd.DOtv * dataAdd.DOtv / 4.0 + 10) * 1.0 / 1000.0) *
        dataAdd.CoeffObrez / 1000.0;
    double B = (((((dataAdd.DFlanz + (dataAdd.DFlanz * 0.15) + 10.0) * 3.14 /
                   1000.0)) *
                 dataAdd.LChehla) +
                (((3.14 * dataAdd.DFlanz * dataAdd.DFlanz / 4.0) + 10.0) * 1.0 /
                 1000.0)) *
               dataAdd.CoeffObrez / 1000.0;
    double C = 0;
    if (data.ProductType[data.CurrentPosition] == PT_OTHER) {
      C = 0;
    } else {
      C = ((((dataAdd.DFlanz + (dataAdd.WarmValue * 2.0) +
              (dataAdd.DFlanz * 0.15) + 10.0) *
             3.14 / 1000.0) *
            (dataAdd.LTriangle * 1.0 + 30.0) *
            data.TriangleCount[data.CurrentPosition])) /
          1000.0 * 1.2;
    }
    in = A + B + C;
  }
  double result = in;
  return result;
}

double Warm(My& data, MyAdd& dataAdd) {
  double warm;
  if (data.BodyType[data.CurrentPosition] == BT_11) {
    warm = 0;
  } else {
    warm = ((((((dataAdd.DFlanz + (dataAdd.WarmValue * 2.0) +
                 (dataAdd.DFlanz * 0.15) + 10.0) *
                3.14 / 1000.0) *
               dataAdd.LChehla) +
              (((3.14 * dataAdd.DFlanz * dataAdd.DFlanz / 4.0) + 10.0) * 2.0 /
               1000))) +
            ((((dataAdd.DOtv + (dataAdd.WarmValue * 2.0) +
                (dataAdd.DOtv * 0.15) + 10.0) *
               3.14 / 1000.0) *
              dataAdd.HOtv) +
             (((3.14 * dataAdd.DOtv * dataAdd.DOtv / 4.0) + 10.0) * 2.0 /
              1000.0))) *
           dataAdd.CoeffObrez / 1000.0;
  }
  double result = dataAdd.PriceWarm * warm;
  return result;
}

double Furniture(My& data, MyAdd& dataAdd) {
  double textil_petlya;
  if (data.AdditionHolder[data.CurrentPosition] == AH_NO) {
    textil_petlya = 0;
  } else {
    textil_petlya = std::ceil(dataAdd.LChehla / 100.0) / 10.0 +
                    std::ceil((0 * 4 + 0 * 4 + 0 * 4) / 100.0) / 10.0;
  }
  double shpil;
  if (Out(data, dataAdd) > 2) {
    shpil = std::ceil(Out(data, dataAdd) / 0.5);
  } else {
    shpil = 0;
  }
  bool NitType;
  bool NitMatrix[17] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  NitType = NitMatrix[data.Temperature[data.CurrentPosition]];
  double PriceNit;
  if (data.BodyType[data.CurrentPosition] == BT_11) {
    PriceNit =
        ((((0 + 0 + 0) * 2.0) +
          (((0 + dataAdd.WarmValue) + (0 + dataAdd.WarmValue) +
            (0 + dataAdd.WarmValue)) *
           2.0 * 1.3 * 1.3) +
          (dataAdd.DFlanz * 3.14 * data.TriangleCount[data.CurrentPosition])) *
         4.0 * 5.0 / 1000.0);
  } else {
    PriceNit =
        (((((dataAdd.LChehla * 2.0 +
             dataAdd.LTriangle * data.TriangleCount[data.CurrentPosition]) /
            1000.0) +
           (((dataAdd.DFlanz + (dataAdd.WarmValue * 2.0) +
              (dataAdd.DFlanz * 0.15)) *
             3.14 / 1000.0) *
            data.TriangleCount[data.CurrentPosition]) +
           ((dataAdd.DOtv + (dataAdd.DOtv * 0.15)) * 3.14 / 1000.0) +
           ((dataAdd.DOtv + (dataAdd.WarmValue * 2.0) + (dataAdd.DOtv * 0.15)) *
            3.14 / 1000.0) +
           (((dataAdd.DFlanz + (dataAdd.DFlanz * 0.15)) * 3.14 / 1000.0) +
            ((dataAdd.DFlanz + (dataAdd.WarmValue * 2.0) +
              (dataAdd.DFlanz * 0.15)) *
             3.14 / 1000.0))) *
          4.0 * 5.0));
  }
  if (NitType == NT_STEEL) {
    PriceNit = std::ceil(PriceNit * PRICE_NITKI_STEEL);
  } else {
    PriceNit = std::ceil(PriceNit * PRICE_NITKI_ARAMID);
  }
  double PriceDRing;
  uint DRingCount = 0;
  if (data.BodyType[data.CurrentPosition] == BT_11) {
    DRingCount = 2 * data.TriangleCount[data.CurrentPosition];
  } else {
    if (data.Triangle[data.CurrentPosition] == TR_WIDE) {
      DRingCount = dataAdd.DTriangleHalfCount;
    } else {
      DRingCount = dataAdd.DTriangleHalfCount - 4;
    }
  }
  if (data.DRingsType[data.CurrentPosition] == DRT_STEEL) {
    PriceDRing = DRingCount * PRICE_D_RING;
  } else {
    PriceDRing = DRingCount * PRICE_D_RING_ECONOM;
  }
  double Provoloka;
  if (data.Triangle[data.CurrentPosition] == TR_UZKAYA) {
    Provoloka = ((dataAdd.DFlanz + dataAdd.WarmValue * 2.0) * 3.14 + 200) *
                data.TriangleCount[data.CurrentPosition] / 1000.0 *
                PRICE_PROVOLOKA;
  } else {
    Provoloka = 0;
  }
  double result = PRICE_LENTA_REMENNAYA * 0 +
                  textil_petlya * PRICE_TEXTIL_PETLYA +
                  textil_petlya * PRICE_TEXTIL_CRUCHOK + shpil * PRICE_SHPIL +
                  PriceNit + PriceDRing + Provoloka + PRICE_ETICKET;
  return result;
}

double Work(My& data, MyAdd& dataAdd) {
  double E;
  E = (dataAdd.TimeConstructor * PRICE_CONSTRUCTOR +
       dataAdd.TimeTechnolog * PRICE_TECHNOLOG +
       (Out(data, dataAdd) + In(data, dataAdd)) /
           ((dataAdd.CoeffObrez + 0.001) * 2) * PRICE_PRINT) /
          data.ProductCount[data.CurrentPosition] +
      dataAdd.TimeShveya * PRICE_SHVEYA;
  double J;
  J = PRICE_SQUARE_SHVEI * PRICE_ARENDA_M2 * dataAdd.TimeShveya /
          (PRICE_WORK_MONTH * PRICE_WORK_DURATION * PRICE_WORK_PLACE) +
      PRICE_SQUARE_OFFICE * PRICE_ARENDA_M2 *
          ((dataAdd.TimeConstructor + dataAdd.TimeTechnolog) /
           data.ProductCount[data.CurrentPosition]) /
          (PRICE_WORK_MONTH * PRICE_WORK_DURATION * PRICE_WORK_PLACE_AUP) +
      0.3 * PRICE_KWT_PRICE *
          (dataAdd.TimeShveya +
           (dataAdd.TimeConstructor + dataAdd.TimeTechnolog) /
               data.ProductCount[data.CurrentPosition]);
  double L;
  L = dataAdd.TimeShveya * (353355.0 * 0.15 / 21.0 / 8.0) / 4.0;
  double result = E + J + L;
  return result;
}

MyAdd CalcAdd(My& data) {
  MyAdd result;
  // 2   PN    dy    DFlanz
  uint DFlanzMatrix[8][27] = {
      {75,  80,  90,  100, 120, 130, 140, 160, 185, 205, 235,  260,  290, 315,
       340, 370, 435, 485, 535, 590, 640, 755, 860, 975, 1075, 1175, 1400},
      {90,  95,  105, 115, 135, 145, 160, 180, 195, 215,  245,  280,  310, 335,
       365, 390, 440, 500, 565, 615, 670, 780, 895, 1010, 1110, 1220, 1455},
      {90,  95,  105, 115, 135, 145, 160, 180, 195, 215,  245,  280,  310, 335,
       365, 405, 460, 520, 580, 640, 710, 840, 910, 1020, 1120, 1255, 1485},
      {90,  95,  105, 115, 135, 145, 160, 180, 195, 215,  245,  280,  310, 335,
       365, 405, 460, 520, 580, 640, 710, 840, 910, 1020, 1120, 1255, 1525},
      {90,  95,  105, 115, 135, 145, 160, 180, 195, 230,  270,  300,  350, 375,
       415, 445, 510, 570, 655, 680, 755, 890, 995, 1135, 1250, 1360, 1575},
      {100, 105, 125, 135,  150,  165,  175,  200,  210,
       250, 295, 340, 370,  405,  430,  470,  530,  595,
       670, 800, 925, 1045, 1165, 1285, 1415, 1360, 0},
      {100, 105, 125, 135, 150, 165, 195, 220, 230, 265, 310, 350, 380, 430,
       470, 500, 585, 655, 715, 0,   0,   0,   0,   0,   0,   0,   0},
      {0,   105, 125, 135, 150, 165, 195, 220, 230, 265, 310, 350, 380, 430,
       470, 500, 585, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0}};
  result.DFlanz = DFlanzMatrix[data.PN[data.CurrentPosition]]
                              [data.Dy[data.CurrentPosition]];
  // 3 4 5  BodyType  Dy  L H D
  uint LHD[9][27][3] = {
      {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
       {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
       {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
       {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
       {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
      {{180, 0, 0},        {180, 0, 0},        {180, 0, 0},
       {180, 0, 0},        {180, 0, 0},        {180, 220, 160},
       {180, 240, 180},    {195, 270, 200},    {210, 295, 215},
       {230, 325, 240},    {255, 370, 270},    {280, 420, 310},
       {300, 465, 345},    {330, 505, 370},    {380, 550, 405},
       {450, 610, 450},    {500, 690, 510},    {550, 780, 575},
       {600, 870, 640},    {650, 960, 705},    {700, 1065, 785},
       {800, 1260, 925},   {900, 1365, 1005},  {1000, 1530, 1125},
       {1100, 1680, 1235}, {1200, 1885, 1385}, {1400, 2230, 1635}},
      {{200, 0, 0},  {200, 0, 0},  {200, 0, 0}, {200, 0, 0}, {200, 0, 0},
       {200, 0, 0},  {230, 0, 0},  {270, 0, 0}, {280, 0, 0}, {300, 0, 0},
       {325, 0, 0},  {350, 0, 0},  {380, 0, 0}, {400, 0, 0}, {580, 0, 0},
       {650, 0, 0},  {750, 0, 0},  {850, 0, 0}, {960, 0, 0}, {1000, 0, 0},
       {1000, 0, 0}, {1130, 0, 0}, {0, 0, 0},   {0, 0, 0},   {0, 0, 0},
       {0, 0, 0},    {0, 0, 0}},
      {{0, 0, 0},   {0, 0, 0},   {0, 0, 0},   {32, 0, 0},  {32, 0, 0},
       {34, 0, 0},  {42, 0, 0},  {46, 0, 0},  {46, 0, 0},  {52, 0, 0},
       {56, 0, 0},  {56, 0, 0},  {60, 0, 0},  {60, 0, 0},  {68, 0, 0},
       {68, 0, 0},  {78, 0, 0},  {92, 0, 0},  {102, 0, 0}, {114, 0, 0},
       {130, 0, 0}, {154, 0, 0}, {165, 0, 0}, {190, 0, 0}, {203, 0, 0},
       {410, 0, 0}, {470, 0, 0}},
      {{0, 0, 0},        {130, 0, 0},       {150, 0, 0},      {160, 0, 0},
       {180, 0, 0},      {200, 190, 160},   {230, 210, 180},  {290, 235, 200},
       {310, 255, 215},  {350, 280, 240},   {400, 320, 270},  {480, 365, 310},
       {550, 405, 345},  {600, 440, 370},   {680, 475, 405},  {730, 530, 450},
       {850, 600, 510},  {980, 680, 575},   {1100, 755, 640}, {1200, 835, 705},
       {1250, 925, 785}, {1450, 1095, 925}, {0, 0, 0},        {0, 0, 0},
       {0, 0, 0},        {0, 0, 0},         {0, 0, 0}},
      {{120, 0, 0},  {130, 0, 0},  {150, 0, 0}, {160, 0, 0},  {180, 0, 0},
       {200, 0, 0},  {230, 0, 0},  {290, 0, 0}, {310, 0, 0},  {350, 0, 0},
       {400, 0, 0},  {480, 0, 0},  {550, 0, 0}, {600, 0, 0},  {680, 0, 0},
       {730, 0, 0},  {850, 0, 0},  {980, 0, 0}, {1100, 0, 0}, {1200, 0, 0},
       {1250, 0, 0}, {1450, 0, 0}, {0, 0, 0},   {0, 0, 0},    {0, 0, 0},
       {0, 0, 0},    {0, 0, 0}},
      {{120, 0, 0},      {130, 0, 0},       {150, 0, 0},      {160, 0, 0},
       {180, 0, 0},      {200, 190, 160},   {230, 210, 180},  {290, 235, 200},
       {310, 255, 215},  {350, 280, 240},   {400, 320, 270},  {480, 365, 310},
       {550, 405, 345},  {600, 440, 370},   {680, 475, 405},  {730, 530, 450},
       {850, 600, 510},  {980, 680, 575},   {1100, 755, 640}, {1200, 835, 705},
       {1250, 925, 785}, {1450, 1095, 925}, {0, 0, 0},        {0, 0, 0},
       {0, 0, 0},        {0, 0, 0},         {0, 0, 0}},
      {{120, 0, 0},      {130, 0, 0},       {150, 0, 0},      {160, 0, 0},
       {180, 0, 0},      {200, 190, 160},   {230, 210, 180},  {290, 235, 200},
       {310, 255, 215},  {350, 280, 240},   {400, 320, 270},  {480, 365, 310},
       {550, 405, 345},  {600, 440, 370},   {680, 475, 405},  {730, 530, 450},
       {850, 600, 510},  {980, 680, 575},   {1100, 755, 640}, {1200, 835, 705},
       {1250, 925, 785}, {1450, 1095, 925}, {0, 0, 0},        {0, 0, 0},
       {0, 0, 0},        {0, 0, 0},         {0, 0, 0}},
      {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
       {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
       {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
       {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
       {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
  result.L = LHD[data.BodyType[data.CurrentPosition]]
                [data.Dy[data.CurrentPosition]][0];
  result.HOtv = LHD[data.BodyType[data.CurrentPosition]]
                   [data.Dy[data.CurrentPosition]][1];
  result.DOtv = LHD[data.BodyType[data.CurrentPosition]]
                   [data.Dy[data.CurrentPosition]][2];
  // 6  t  dy  Warm
  uint WarmValue[17][27] = {
      {30, 30, 30, 40, 40, 40, 40, 40, 50, 50, 50, 50, 60, 60,
       60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 70, 70},
      {40, 40, 40, 40, 50, 50, 50, 50, 50, 50, 50, 50, 60, 60,
       60, 60, 60, 70, 70, 70, 70, 80, 80, 80, 90, 90, 90},
      {30, 30, 30, 40, 40, 40, 40, 40, 50, 50, 50, 50, 60, 60,
       60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 70, 70},
      {40, 40, 40, 40, 50, 50, 50, 50, 50, 50, 50, 50, 60, 60,
       60, 60, 60, 70, 70, 70, 70, 80, 80, 80, 90, 90, 90},
      {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 60, 60, 60, 60,
       60, 60, 70, 70, 80, 80, 90, 90, 90, 90, 90, 90, 90},
      {50, 50, 50, 50, 50,  50,  50,  50,  50,  60,  70,  70,  70, 70,
       80, 80, 80, 90, 100, 100, 100, 120, 120, 120, 150, 150, 150},
      {50, 50, 50,  50,  50,  50,  60,  60,  60,  70,  70,  70,  80, 80,
       80, 80, 100, 100, 100, 120, 120, 120, 150, 150, 150, 150, 150},
      {50, 50, 50, 50, 50,  50,  50,  60,  60,  60,  60,  60,  60, 80,
       80, 80, 80, 80, 100, 100, 100, 100, 100, 100, 100, 120, 120},
      {50, 50, 50, 50, 50,  50,  50,  60,  60,  60,  80,  80,  80, 80,
       80, 80, 90, 90, 100, 100, 100, 100, 120, 120, 120, 120, 120},
      {50,  50,  50,  50,  50,  50,  60,  60,  60,  60,  80,  80,  90, 90,
       100, 100, 120, 120, 120, 120, 120, 120, 150, 150, 150, 150, 150},
      {50,  50,  50,  50,  60,  60,  60,  60,  80,  80,  80,  80,  100, 100,
       100, 100, 100, 100, 100, 100, 100, 120, 120, 120, 120, 120, 120},
      {50,  50,  50,  50,  60,  60,  60,  60,  80,  80,  80,  80,  100, 100,
       100, 100, 100, 100, 100, 100, 100, 120, 120, 120, 120, 120, 120},
      {50,  50,  50,  50,  60,  60,  60,  60,  80,  80,  80,  80,  100, 100,
       100, 100, 100, 100, 100, 100, 100, 120, 120, 120, 120, 120, 120},
      {50,  50,  50,  50,  60,  60,  60,  60,  80,  80,  80,  80,  100, 100,
       100, 100, 100, 100, 100, 100, 100, 120, 120, 120, 120, 120, 120},
      {50,  50,  50,  50,  60,  60,  60,  60,  80,  80,  80,  80,  100, 100,
       100, 100, 100, 100, 100, 100, 100, 120, 120, 120, 120, 120, 120},
      {50,  50,  50,  50,  60,  60,  60,  60,  80,  80,  80,  80,  100, 100,
       100, 100, 100, 100, 100, 100, 100, 120, 120, 120, 120, 120, 120},
      {50,  50,  50,  50,  60,  60,  60,  60,  80,  80,  80,  80,  100, 100,
       100, 100, 100, 100, 100, 100, 100, 120, 120, 120, 120, 120, 120}};
  uint WarmWidth[17][27] = {
      {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
       100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100},
      {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
       100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100},
      {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
       100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100},
      {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
       100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100},
      {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
       100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100},
      {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
       100, 100, 100, 100, 200, 200, 200, 200, 200, 200, 200, 200, 200},
      {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
       100, 100, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200},
      {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
       100, 100, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200},
      {50,  50,  50,  50,  50,  50,  50,  60,  60,  60,  100, 100, 100, 100,
       100, 100, 100, 100, 120, 120, 120, 120, 120, 120, 120, 120, 120},
      {50,  50,  50,  50,  50,  50,  60,  60,  60,  60,  100, 100, 100, 100,
       120, 120, 120, 120, 120, 120, 120, 120, 150, 150, 150, 150, 150},
      {50,  50,  50,  50,  60,  60,  60,  60,  80,  80,  80,  80,  100, 100,
       100, 100, 100, 100, 100, 100, 100, 120, 120, 120, 120, 120, 120},
      {50,  50,  50,  50,  60,  60,  60,  60,  80,  80,  80,  80,  100, 100,
       100, 100, 100, 100, 100, 100, 100, 120, 120, 120, 120, 120, 120},
      {50,  50,  50,  50,  60,  60,  60,  60,  80,  80,  80,  80,  100, 100,
       100, 100, 100, 100, 100, 100, 100, 120, 120, 120, 120, 120, 120},
      {50,  50,  50,  50,  60,  60,  60,  60,  80,  80,  80,  80,  100, 100,
       100, 100, 100, 100, 100, 100, 100, 120, 120, 120, 120, 120, 120},
      {50,  50,  50,  50,  60,  60,  60,  60,  80,  80,  80,  80,  100, 100,
       100, 100, 100, 100, 100, 100, 100, 120, 120, 120, 120, 120, 120},
      {50,  50,  50,  50,  60,  60,  60,  60,  80,  80,  80,  80,  100, 100,
       100, 100, 100, 100, 100, 100, 100, 120, 120, 120, 120, 120, 120},
      {50,  50,  50,  50,  60,  60,  60,  60,  80,  80,  80,  80,  100, 100,
       100, 100, 100, 100, 100, 100, 100, 120, 120, 120, 120, 120, 120}};
  uint WarmType[17][27] = {{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                           {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                           {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                           {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                           {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                           {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 1, 1, 1},
                           {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1},
                           {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1},
                           {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                           {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                           {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                           {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                           {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                           {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                           {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                           {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                           {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}};
  result.WarmValue = WarmValue[data.Temperature[data.CurrentPosition]]
                              [data.Dy[data.CurrentPosition]];
  result.WarmWidth = WarmWidth[data.Temperature[data.CurrentPosition]]
          [data.Dy[data.CurrentPosition]];
  result.WarmType = WarmType[data.Temperature[data.CurrentPosition]]
          [data.Dy[data.CurrentPosition]];
  if (result.WarmType == PW_URSA_M11) {
      result.PriceWarm = 210;
    } else if (result.WarmType == PW_URSA_M25) {
      if (result.WarmWidth == 100) {
        result.PriceWarm = 460;
      } else {
        result.PriceWarm = 920;
      }
    } else if (result.WarmType == PW_WIRED_MAT) {
      switch (result.WarmWidth) {
        case 50:
          result.PriceWarm = 620;
          break;
        case 60:
          result.PriceWarm = 740;
          break;
        case 80:
          result.PriceWarm = 900;
          break;
        case 100:
          result.PriceWarm = 1008;
          break;
        case 150:
          result.PriceWarm = 1860;
          break;
        default:
          break;
      }
    } else if (result.WarmType == PW_TEX_MAT) {
      switch (result.WarmWidth) {
        case 50:
          result.PriceWarm = 330;
          break;
        case 60:
          result.PriceWarm = 400;
          break;
        case 80:
          result.PriceWarm = 528;
          break;
        case 100:
          result.PriceWarm = 660;
          break;
        case 120:
          result.PriceWarm = 800;
          break;
        case 150:
          result.PriceWarm = 990;
          break;
        default:
          break;
      }
    } else {
      result.PriceWarm = 670;
    }
  // 7 8 9  Dy CoeffMatras CoeffSTD LShpil SFlanz LTriangle
  double tkan[27][12] = {{1.6, 2.1, 70, 14, 100, 8, 1.5, 0.8, 1.5, 2, 1.4, 5},
                         {1.6, 2.1, 70, 14, 100, 8, 1.5, 0.8, 1.5, 2, 1.4, 5},
                         {1.6, 2.1, 70, 16, 100, 8, 1.5, 0.9, 1.5, 2, 1.4, 5},
                         {1.6, 2.1, 70, 18, 100, 8, 1.5, 0.9, 1.5, 2, 1.4, 5},
                         {1.6, 2.1, 80, 18, 100, 8, 1.5, 1, 1.5, 2, 1.4, 5},
                         {1.6, 2.1, 90, 20, 100, 8, 2, 1, 1.5, 3, 2.1, 8},
                         {1.6, 2.1, 90, 22, 100, 8, 2, 1, 2, 3, 2.1, 8},
                         {1.6, 2.1, 100, 24, 100, 12, 2, 1.1, 2, 8, 2.9, 8},
                         {1.6, 2.1, 100, 24, 100, 12, 2, 1.1, 2, 8, 2.9, 8},
                         {1.6, 2.1, 100, 26, 120, 12, 2, 1.2, 2, 8, 2.9, 8},
                         {1.6, 2.1, 100, 28, 120, 16, 2, 1.2, 2.5, 8, 2.9, 8},
                         {1.6, 2.1, 110, 28, 150, 20, 2, 1.3, 2.5, 8, 3.3, 10},
                         {1.6, 2.1, 110, 28, 150, 20, 2.5, 1.5, 3, 8, 3.6, 12},
                         {1.5, 2, 120, 30, 150, 26, 2.5, 1.7, 4, 8, 3.6, 12},
                         {1.5, 2, 120, 30, 150, 26, 2.5, 1.7, 4.5, 10, 4.3, 14},
                         {1.4, 1.9, 130, 31, 200, 30, 2.5, 1.9, 5, 10, 4.6, 16},
                         {1.4, 1.9, 130, 32, 200, 40, 3, 1.9, 5, 12, 4.9, 16},
                         {1.3, 1.8, 140, 34, 200, 50, 3, 1.9, 6, 12, 4.9, 16},
                         {1.3, 1.8, 150, 38, 200, 60, 3, 2.3, 6, 14, 5.9, 20},
                         {1.3, 1.8, 150, 42, 200, 60, 4, 2.3, 7, 14, 5.9, 20},
                         {1.3, 1.8, 180, 48, 200, 60, 4, 2.5, 8, 16, 6.3, 20},
                         {1.3, 1.8, 200, 50, 200, 70, 4.5, 2.5, 8, 16, 6.3, 20},
                         {1.3, 1.8, 200, 52, 200, 70, 4.5, 2.8, 9, 16, 6.9, 24},
                         {1.3, 1.8, 210, 54, 200, 80, 5, 2.8, 9, 16, 6.9, 24},
                         {1.3, 1.8, 210, 59, 200, 80, 5, 3, 10, 16, 6.9, 24},
                         {1.3, 1.8, 240, 63, 200, 80, 6, 3.3, 10, 16, 6.9, 24},
                         {1.3, 1.8, 290, 76, 200, 80, 6, 3.3, 10, 16, 6.9, 24}};
  result.LShpil = tkan[data.Dy[data.CurrentPosition]][2];
  result.SFlanz = tkan[data.Dy[data.CurrentPosition]][3];
  result.LTriangle = tkan[data.Dy[data.CurrentPosition]][4];
  result.DTriangleHalfCount = tkan[data.Dy[data.CurrentPosition]][5];
  if (data.ProductType[data.CurrentPosition] == PT_STANDART) {
    result.TimeConstructor = tkan[data.Dy[data.CurrentPosition]][9];
    result.TimeTechnolog = tkan[data.Dy[data.CurrentPosition]][10];
    result.TimeShveya = tkan[data.Dy[data.CurrentPosition]][11];
  } else {
    result.TimeConstructor = tkan[data.Dy[data.CurrentPosition]][6];
    result.TimeTechnolog = tkan[data.Dy[data.CurrentPosition]][7];
    result.TimeShveya = tkan[data.Dy[data.CurrentPosition]][8];
  }
  // 10
  if (data.BodyType[data.CurrentPosition] == BT_11) {
    result.LChehla = 0;
  } else {
    result.LChehla = result.LShpil * 2.0 + result.SFlanz * 2.0 + result.L;
  }
  // 1
  double CoeffObrez;
  if (data.ProductType[data.CurrentPosition] == PT_STANDART) {
    CoeffObrez = tkan[data.Dy[data.CurrentPosition]][1];
  } else {
    CoeffObrez = tkan[data.Dy[data.CurrentPosition]][0];
  }
  if (data.Triangle[data.CurrentPosition] != TR_WIDE) CoeffObrez -= 0.05;
  result.CoeffObrez = CoeffObrez;
  // 11
  double Dtri;
  if (data.Triangle[data.CurrentPosition] == TR_UZKAYA ||
      data.Triangle[data.CurrentPosition] == TR_WIDE) {
    Dtri = result.DFlanz + ((result.DFlanz / 100) * 15) + result.WarmValue +
           result.WarmValue;
  } else {
    Dtri = 0;
  }
  result.DTriangle = Dtri;
  return result;
}

QString makeName(QDynamicButton *line){
    QString fire ("KM1-");
    if (line->comboF->currentText() == "НГ"){fire = "KM0-";}
    QString equipment ("ZS ");
    if (line->comboE->currentText() == "Задвижка"){equipment = "ZZ ";
    }else if (line->comboE->currentText() == "Кран"){equipment = "ZK ";
    }else if (line->comboE->currentText() == "Затвор дисковый"){equipment = "ZD ";
    }else if (line->comboE->currentText() == "Клапан запорный"){equipment = "ZV ";
    }else if (line->comboE->currentText() == "Клапан обратный"){equipment = "ZO ";
    }else if (line->comboE->currentText() == "Регулятор"){equipment = "ZR ";
    }else if (line->comboE->currentText() == "Фильтр"){equipment = "ZF ";
    }else if (line->comboE->currentText() == "Другое"){equipment = "ZX ";
    }
    QString diam ("D10");
    diam = line->comboD->currentText();
    diam.remove(1,1);

    QString insulation ("C");
    QString material (" C");
    if (line->spinT->value() > 350){insulation = " M"; material = " P";}
    QString width ("50");
    // Здесь создаём и заполняем матрицу зависимости толщины утеплителя от температуры и диаметра
    int matrix[19][8];
    for (int i = 0; i < 3; i++) { matrix[i][0] = 30;}
    for (int i = 3; i < 8; i++) { matrix[i][0] = 40;}
    for (int i = 8; i < 12; i++) { matrix[i][0] = 50;}
    for (int i = 12; i < 19; i++) { matrix[i][0] = 60;}

    for (int i = 0; i < 4; i++) { matrix[i][1] = 40;}
    for (int i = 4; i < 12; i++) { matrix[i][1] = 50;}
    for (int i = 12; i < 17; i++) { matrix[i][1] = 60;}
    for (int i = 17; i < 19; i++) { matrix[i][1] = 70;}

    for (int i = 0; i < 10; i++) { matrix[i][2] = 50;}
    for (int i = 10; i < 16; i++) { matrix[i][2] = 60;}
    for (int i = 16; i < 18; i++) { matrix[i][2] = 70;}
    for (int i = 18; i < 19; i++) { matrix[i][2] = 80;}

    for (int i = 0; i < 9; i++) { matrix[i][3] = 50;}
    for (int i = 9; i < 10; i++) { matrix[i][3] = 60;}
    for (int i = 10; i < 14; i++) { matrix[i][3] = 70;}
    for (int i = 14; i < 17; i++) { matrix[i][3] = 80;}
    for (int i = 17; i < 18; i++) { matrix[i][3] = 90;}
    for (int i = 18; i < 19; i++) { matrix[i][3] = 100;}

    for (int i = 0; i < 6; i++) { matrix[i][4] = 50;}
    for (int i = 6; i < 9; i++) { matrix[i][4] = 60;}
    for (int i = 9; i < 12; i++) { matrix[i][4] = 70;}
    for (int i = 12; i < 16; i++) { matrix[i][4] = 80;}
    for (int i = 16; i < 19; i++) { matrix[i][4] = 100;}

    for (int i = 0; i < 6; i++) { matrix[i][5] = 50;}
    for (int i = 6; i < 9; i++) { matrix[i][5] = 60;}
    for (int i = 9; i < 12; i++) { matrix[i][5] = 70;}
    for (int i = 12; i < 16; i++) { matrix[i][5] = 80;}
    for (int i = 16; i < 19; i++) { matrix[i][5] = 100;}

    for (int i = 0; i < 7; i++) { matrix[i][6] = 50;}
    for (int i = 7; i < 10; i++) { matrix[i][6] = 60;}
    for (int i = 10; i < 16; i++) { matrix[i][6] = 80;}
    for (int i = 16; i < 18; i++) { matrix[i][6] = 90;}
    for (int i = 18; i < 19; i++) { matrix[i][6] = 100;}

    for (int i = 0; i < 6; i++) { matrix[i][7] = 50;}
    for (int i = 6; i < 10; i++) { matrix[i][7] = 60;}
    for (int i = 10; i < 12; i++) { matrix[i][7] = 80;}
    for (int i = 12; i < 14; i++) { matrix[i][7] = 90;}
    for (int i = 14; i < 16; i++) { matrix[i][7] = 100;}
    for (int i = 16; i < 19; i++) { matrix[i][7] = 120;}
    // Закончили заполнять матрицу
    int i = 0; int j = 3;
    if(line->comboD->currentText() == "DN10") {i = 0;
    } else if(line->comboD->currentText() == "DN15") {i = 1;
    } else if(line->comboD->currentText() == "DN20") {i = 2;
    } else if(line->comboD->currentText() == "DN25") {i = 3;
    } else if(line->comboD->currentText() == "DN32") {i = 4;
    } else if(line->comboD->currentText() == "DN40") {i = 5;
    } else if(line->comboD->currentText() == "DN50") {i = 6;
    } else if(line->comboD->currentText() == "DN65") {i = 7;
    } else if(line->comboD->currentText() == "DN80") {i = 8;
    } else if(line->comboD->currentText() == "DN100") {i = 9;
    } else if(line->comboD->currentText() == "DN125") {i = 10;
    } else if(line->comboD->currentText() == "DN150") {i = 11;
    } else if(line->comboD->currentText() == "DN175") {i = 12;
    } else if(line->comboD->currentText() == "DN200") {i = 13;
    } else if(line->comboD->currentText() == "DN225") {i = 14;
    } else if(line->comboD->currentText() == "DN250") {i = 15;
    } else if(line->comboD->currentText() == "DN300") {i = 16;
    } else if(line->comboD->currentText() == "DN350") {i = 17;
    } else if(line->comboD->currentText() == "DN400") {i = 18;
    }
    if(line->spinT->value() <=50) {j = 0;
    } else if(line->spinT->value() >50 && line->spinT->value() <= 100) {j = 1;
    } else if(line->spinT->value() >100 && line->spinT->value() <= 150) {j = 2;
    } else if(line->spinT->value() >150 && line->spinT->value() <= 200) {j = 3;
    } else if(line->spinT->value() >200 && line->spinT->value() <= 250) {j = 4;
    } else if(line->spinT->value() >250 && line->spinT->value() <= 300) {j = 5;
    } else if(line->spinT->value() >300 && line->spinT->value() <= 350) {j = 6;
    } else if(line->spinT->value() >350 && line->spinT->value() <= 400) {j = 7;
    }
    width = QString::number(matrix[i][j]);
    QString type ("-M");
    if (line->comboT->currentText() == "Стандарт"){type = "-S";
    }else if (line->comboT->currentText() == "Другое"){type = "-K";
    }
    QString name = "Термочехол FORPRO " + fire + equipment + diam + "-C " + \
            insulation + width + material + type + "-00000-" + line->label->text();
    return name;
}

QString makePrice(QDynamicButton *line) {
    uint pos = 1U;
//            line->label->text().toUInt();
    uint pcount = (unsigned)line->spinN->value();
    uint ptype = (unsigned)line->comboT->currentIndex();
    uint btype = (unsigned)line->comboE->currentIndex();
    uint dy = (unsigned)line->comboD->currentIndex();
    uint pn = (unsigned)line->comboP->currentIndex();
    int t = line->spinT->value();
    if (t < -30) {
        t = 0;
    } else if (t < 50) {
        t = 1;
    } else if (t < 100) {
        t = 2;
    } else if (t < 150) {
        t = 3;
    } else if (t < 200) {
        t = 4;
    } else if (t < 250) {
        t = 5;
    } else if (t < 300) {
        t = 6;
    } else if (t < 350) {
        t = 7;
    } else if (t < 400) {
        t = 8;
    } else {
        t = 9;
    }
    bool fgroup = (bool)line->comboF->currentIndex();
    bool place = (bool)line->comboA->currentIndex();
    uint tri = (unsigned)line->comboB->currentIndex();
    uint tricount = 2;
    bool drtype = (bool)line->comboR->currentIndex();
    bool addh = line->check->isChecked();
    My data;
    PushData(data, pos, pcount, ptype, btype, dy,
             pn, t, fgroup, place, tri, tricount,
             drtype, addh);
    MyAdd data_add = CalcAdd(data);
    double result;
//    qDebug() << Work(data, data_add);
    result =
        std::ceil((PRICE_TG_430_S1 * (Out(data, data_add) + In(data, data_add)) +
                   Warm(data, data_add) + Furniture(data, data_add) +
                   Work(data, data_add)) *
                  COEFFICIENT_DOP_RASHOD);
    data.PriceOne[data.CurrentPosition] = result;
    data.PriceAll[data.CurrentPosition] = result * pcount;
    return QString::number(result*1.5);
}
#endif // DESIGNATION_H
