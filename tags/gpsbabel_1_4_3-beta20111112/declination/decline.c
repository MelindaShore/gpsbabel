
/*
    Declination function

    Copyright (C) 2002 Robert Lipe, robertlipe@usa.net

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111 USA

 */
#include <stdio.h>
#include <math.h>
#include "defs.h"

static double gh[];

#define STANDALONE

        
/*
These comments are from the original Fortran code from IGRF

  subroutine igrf9syn (isv,date,itype,alt,colat,elong,x,y,z,f)
  c
  c     This is a synthesis routine for the 9th generation IGRF as agreed 
  c     in July 2003 by IAGA Working Group V-8. It is valid 1900.0 to 2005.0 
  c     inclusive. Values for dates from 1945.0 to 2000.0 inclusive are 
  c     definitve, otherwise they are non-definitive.
  c   INPUT
  c     isv   = 0 if main-field values are required
  c     isv   = 1 if secular variation values are required
  c     date  = year A.D. Must be greater than or equal to 1900.0 and 
  c             less than or equal to 2010.0. Warning message is given 
  c             for dates greater than 2005.0. Must be double precision.
  c     itype = 1 if geodetic (spheroid)
  c     itype = 2 if geocentric (sphere)
  c     alt   = height in km above sea level if itype = 1
  c           = distance from centre of Earth in km if itype = 2 (>3485 km)
  c     colat = colatitude (0-180)
  c     elong = east-longitude (0-360)
  c     alt, colat and elong must be double precision.
  c   OUTPUT
  c     x     = north component (nT) if isv = 0, nT/year if isv = 1
  c     y     = east component (nT) if isv = 0, nT/year if isv = 1
  c     z     = vertical component (nT) if isv = 0, nT/year if isv = 1
  c     f     = total intensity (nT) if isv = 0, rubbish if isv = 1
  c
  c     To get the other geomagnetic elements (D, I, H and secular
  c     variations dD, dH, dI and dF) use routines ptoc and ptocsv.
  c
  c     Adapted from 8th generation version to include new maximum degree for
  c     main-field models for 2000.0 and onwards and use WGS84 spheroid instead
  c     of International Astronomical Union 1966 spheroid as recommended by IAGA
  c     in July 2003. Reference radius remains as 6371.2 km - it is NOT the mean
  c     radius (= 6371.0 km) but 6371.2 km is what is used in determining the
  c     coefficients. Adaptation by Susan Macmillan, August 2003.
  */
  
  double declination( double date, double alt, double lat, double lon ) {
      
      double cl[14];
      double sl[14];
      double p[106];
      double q[106];
      
      double x = 0;
      double y = 0;
      double z = 0;
      double f = 0;
      
      double colat = 90 - lat;
      double elong = lon;
      
      double t;
      double ll;
      double one;
      double two;
      double three;
      double rho;
      double tc;
      
      double r;
      double ct;
      double st;
      double cd;
      double sd;
      
      double a2;
      double b2;
      double ratio;
      double rr;
      
      double fn;
      double gn;
      double fm;
      double gmm;
     
      int i;
      int j;
      int k; 
      int kmx;
      int l;
      int lm;
      int m;
      int n;
      int nc;
      int nmx;
      
      /*
      c     set initial values
      */ 
      x     = 0.0;
      y     = 0.0;
      z     = 0.0;
      if ( date >= 1900 && date <= 2010 ) {
      /*
      if (date.gt.2005.0) write (6,960) date
      960 format (/' This version of the IGRF is intended for use up',
      1        ' to 2005.0.'/' values for',f9.3,' will be computed',
      2        ' but may be of reduced accuracy'/)
          */
          if (date < 2000.0) { 
              t     = 0.2*(date - 1900.0);
              ll    = t;
              one   = ll;
              t     = t - one;
              if (date <= 1995.0) {
                  nmx   = 10;
                  nc    = nmx*(nmx+2);
                  ll    = nc*ll;
                  kmx   = (nmx+1)*(nmx+2)/2;
              }
              else {
                  nmx   = 13;
                  nc    = nmx*(nmx+2);
                  ll    = 0.2*(date - 1995.0);
                  ll    = 120*19 + nc*ll;
                  kmx   = (nmx+1)*(nmx+2)/2;
              }
              tc    = 1.0 - t;
          }
          else {
              t     = date - 2000.0;
              tc    = 1.0;
              ll    = 2475;
              nmx   = 13;
              nc    = nmx*(nmx+2);
              kmx   = (nmx+1)*(nmx+2)/2;
          }
          
          r     = alt;
          one   = colat*M_PI/180;
          ct    = cos(one);
          st    = sin(one);
          one   = elong*M_PI/180;
          cl[1] = cos(one);
          sl[1] = sin(one);
          cd    = 1.0;
          sd    = 0.0;
          l     = 1;
          m     = 1;
          n     = 0;
          /*
          c     conversion from geodetic to geocentric coordinates 
          c     (using the WGS84 spheroid)
          */
          a2    = 40680631.6;
          b2    = 40408296.0;
          one   = a2*st*st;
          two   = b2*ct*ct;
          three = one + two;
          rho   = sqrt(three);
          r     = sqrt(alt*(alt + 2.0*rho) + (a2*one + b2*two)/three);
          cd    = (alt + rho)/r;
          sd    = (a2 - b2)/rho*ct*st/r;
          one   = ct;
          ct    = ct*cd -  st*sd;
          st    = st*cd + one*sd;
          
          ratio = 6371.2/r;
          rr    = ratio*ratio;
          /*
          c     computation of Schmidt quasi-normal coefficients p and x(=q)
          */
          p[1]  = 1.0;
          p[3]  = st;
          q[1]  = 0.0;
          q[3]  =  ct;
          for ( k = 2; k <= kmx; k++ ) {
              if (n < m) {
                  m     = 0;
                  n     = n + 1;
                  rr    = rr*ratio;
                  fn    = n;
                  gn    = n - 1;
              }
              fm    = m;
              if (m == n) {
                  if (k != 3) {
                      one   = sqrt(1.0 - 0.5/fm);
                      j     = k - n - 1;
                      p[k]  = one*st*p[j];
                      q[k]  = one*(st*q[j] + ct*p[j]);
                      cl[m] = cl[m-1]*cl[1] - sl[m-1]*sl[1];
                      sl[m] = sl[m-1]*cl[1] + cl[m-1]*sl[1];
                  }
              }
              else {
                  gmm    = m*m;
                  one   = sqrt(fn*fn - gmm);
                  two   = sqrt(gn*gn - gmm)/one;
                  three = (fn + gn)/one;
                  i     = k - n;
                  j     = i - n + 1;
                  p[k]  = three*ct*p[i] - two*p[j];
                  q[k]  = three*(ct*q[i] - st*p[i]) - two*q[j];
              }
              /*
              c     synthesis of x, y and z in geocentric coordinates
              */
              lm    = ll + l;
              one   = (tc*gh[lm] + t*gh[lm+nc])*rr;
              if (m != 0) {
                  two   = (tc*gh[lm+1] + t*gh[lm+nc+1])*rr;
                  three = one*cl[m] + two*sl[m];
                  x     = x + three*q[k];
                  z     = z - (fn + 1.0)*three*p[k];
                  if (st != 0.0) {
                      y     = y + (one*sl[m] - two*cl[m])*fm*p[k]/st;
                  }
                  else {
                      y     = y + (one*sl[m] - two*cl[m])*q[k]*ct;
                  }
                  l     = l + 2;
              }
              else {
                  x     = x + one*q[k];
                  z     = z - (fn + 1.0)*one*p[k];
                  l     = l + 1;
              }
              m     = m + 1;
          }
          /*
          c     conversion to coordinate system specified by itype
          */
          one   = x;
          x     = x*cd +   z*sd;
              
          return 180/M_PI*atan2(y,x);
      }
      /*
      c     error return if date out of bounds
      */
      /*
      fatal ( "Can't compute declination for dates outside of 1900-2010\n" );
      */
      return 999;
}


#ifdef STANDALONE
  int main(int c, char **v) {
	  double lat = atof(v[1]);
	  double lon = atof(v[2]);
	  double date = atof(v[3]);
	  double dec = declination( date, 0, lat, lon );
	  printf( "declination is %f at %f,%f on %f\n\n", dec, lat, lon, date );
	  return 0;
  }
#endif


static double gh[] = {
    0,
        /* 1900 */ 
        -31543.,-2298., 5922., -677., 2905.,-1061.,  924., 1121.,
        1022.,-1469., -330., 1256.,    3.,  572.,  523.,  876.,
        628.,  195.,  660.,  -69., -361., -210.,  134.,  -75.,
        -184.,  328., -210.,  264.,   53.,    5.,  -33.,  -86.,
        -124.,  -16.,    3.,   63.,   61.,   -9.,  -11.,   83.,
        -217.,    2.,  -58.,  -35.,   59.,   36.,  -90.,  -69.,
        70.,  -55.,  -45.,    0.,  -13.,   34.,  -10.,  -41.,
        -1.,  -21.,   28.,   18.,  -12.,    6.,  -22.,   11.,
        8.,    8.,   -4.,  -14.,   -9.,    7.,    1.,  -13.,
        2.,    5.,   -9.,   16.,    5.,   -5.,    8.,  -18.,
        8.,   10.,  -20.,    1.,   14.,  -11.,    5.,   12.,
        -3.,    1.,   -2.,   -2.,    8.,    2.,   10.,   -1.,
        -2.,   -1.,    2.,   -3.,   -4.,    2.,    2.,    1.,
        -5.,    2.,   -2.,    6.,    6.,   -4.,    4.,    0.,
        0.,   -2.,    2.,    4.,    2.,    0.,    0.,   -6.,
        /* 1905 */
        -31464.,-2298., 5909., -728., 2928.,-1086., 1041., 1065.,
        1037.,-1494., -357., 1239.,   34.,  635.,  480.,  880.,
        643.,  203.,  653.,  -77., -380., -201.,  146.,  -65.,
        -192.,  328., -193.,  259.,   56.,   -1.,  -32.,  -93.,
        -125.,  -26.,   11.,   62.,   60.,   -7.,  -11.,   86.,
        -221.,    4.,  -57.,  -32.,   57.,   32.,  -92.,  -67.,
        70.,  -54.,  -46.,    0.,  -14.,   33.,  -11.,  -41.,
        0.,  -20.,   28.,   18.,  -12.,    6.,  -22.,   11.,
        8.,    8.,   -4.,  -15.,   -9.,    7.,    1.,  -13.,
        2.,    5.,   -8.,   16.,    5.,   -5.,    8.,  -18.,
        8.,   10.,  -20.,    1.,   14.,  -11.,    5.,   12.,
        -3.,    1.,   -2.,   -2.,    8.,    2.,   10.,    0.,
        -2.,   -1.,    2.,   -3.,   -4.,    2.,    2.,    1.,
        -5.,    2.,   -2.,    6.,    6.,   -4.,    4.,    0.,
        0.,   -2.,    2.,    4.,    2.,    0.,    0.,   -6.,
        /* 1910 */
        -31354.,-2297., 5898., -769., 2948.,-1128., 1176., 1000.,
        1058.,-1524., -389., 1223.,   62.,  705.,  425.,  884.,
        660.,  211.,  644.,  -90., -400., -189.,  160.,  -55.,
        -201.,  327., -172.,  253.,   57.,   -9.,  -33., -102.,
        -126.,  -38.,   21.,   62.,   58.,   -5.,  -11.,   89.,
        -224.,    5.,  -54.,  -29.,   54.,   28.,  -95.,  -65.,
        71.,  -54.,  -47.,    1.,  -14.,   32.,  -12.,  -40.,
        1.,  -19.,   28.,   18.,  -13.,    6.,  -22.,   11.,
        8.,    8.,   -4.,  -15.,   -9.,    6.,    1.,  -13.,
        2.,    5.,   -8.,   16.,    5.,   -5.,    8.,  -18.,
        8.,   10.,  -20.,    1.,   14.,  -11.,    5.,   12.,
        -3.,    1.,   -2.,   -2.,    8.,    2.,   10.,    0.,
        -2.,   -1.,    2.,   -3.,   -4.,    2.,    2.,    1.,
        -5.,    2.,   -2.,    6.,    6.,   -4.,    4.,    0.,
        0.,   -2.,    2.,    4.,    2.,    0.,    0.,   -6.,
        /* 1915 */
        -31212.,-2306., 5875., -802., 2956.,-1191., 1309.,  917.,
        1084.,-1559., -421., 1212.,   84.,  778.,  360.,  887.,
        678.,  218.,  631., -109., -416., -173.,  178.,  -51.,
        -211.,  327., -148.,  245.,   58.,  -16.,  -34., -111.,
        -126.,  -51.,   32.,   61.,   57.,   -2.,  -10.,   93.,
        -228.,    8.,  -51.,  -26.,   49.,   23.,  -98.,  -62.,
        72.,  -54.,  -48.,    2.,  -14.,   31.,  -12.,  -38.,
        2.,  -18.,   28.,   19.,  -15.,    6.,  -22.,   11.,
        8.,    8.,   -4.,  -15.,   -9.,    6.,    2.,  -13.,
        3.,    5.,   -8.,   16.,    6.,   -5.,    8.,  -18.,
        8.,   10.,  -20.,    1.,   14.,  -11.,    5.,   12.,
        -3.,    1.,   -2.,   -2.,    8.,    2.,   10.,    0.,
        -2.,   -1.,    2.,   -3.,   -4.,    2.,    2.,    1.,
        -5.,    2.,   -2.,    6.,    6.,   -4.,    4.,    0.,
        0.,   -2.,    1.,    4.,    2.,    0.,    0.,   -6.,
        /* 1920 */
        -31060.,-2317., 5845., -839., 2959.,-1259., 1407.,  823.,
        1111.,-1600., -445., 1205.,  103.,  839.,  293.,  889.,
        695.,  220.,  616., -134., -424., -153.,  199.,  -57.,
        -221.,  326., -122.,  236.,   58.,  -23.,  -38., -119.,
        -125.,  -62.,   43.,   61.,   55.,    0.,  -10.,   96.,
        -233.,   11.,  -46.,  -22.,   44.,   18., -101.,  -57.,
        73.,  -54.,  -49.,    2.,  -14.,   29.,  -13.,  -37.,
        4.,  -16.,   28.,   19.,  -16.,    6.,  -22.,   11.,
        7.,    8.,   -3.,  -15.,   -9.,    6.,    2.,  -14.,
        4.,    5.,   -7.,   17.,    6.,   -5.,    8.,  -19.,
        8.,   10.,  -20.,    1.,   14.,  -11.,    5.,   12.,
        -3.,    1.,   -2.,   -2.,    9.,    2.,   10.,    0.,
        -2.,   -1.,    2.,   -3.,   -4.,    2.,    2.,    1.,
        -5.,    2.,   -2.,    6.,    6.,   -4.,    4.,    0.,
        0.,   -2.,    1.,    4.,    3.,    0.,    0.,   -6.,
        /* 1925 */
        -30926.,-2318., 5817., -893., 2969.,-1334., 1471.,  728.,
        1140.,-1645., -462., 1202.,  119.,  881.,  229.,  891.,
        711.,  216.,  601., -163., -426., -130.,  217.,  -70.,
        -230.,  326.,  -96.,  226.,   58.,  -28.,  -44., -125.,
        -122.,  -69.,   51.,   61.,   54.,    3.,   -9.,   99.,
        -238.,   14.,  -40.,  -18.,   39.,   13., -103.,  -52.,
        73.,  -54.,  -50.,    3.,  -14.,   27.,  -14.,  -35.,
        5.,  -14.,   29.,   19.,  -17.,    6.,  -21.,   11.,
        7.,    8.,   -3.,  -15.,   -9.,    6.,    2.,  -14.,
        4.,    5.,   -7.,   17.,    7.,   -5.,    8.,  -19.,
        8.,   10.,  -20.,    1.,   14.,  -11.,    5.,   12.,
        -3.,    1.,   -2.,   -2.,    9.,    2.,   10.,    0.,
        -2.,   -1.,    2.,   -3.,   -4.,    2.,    2.,    1.,
        -5.,    2.,   -2.,    6.,    6.,   -4.,    4.,    0.,
        0.,   -2.,    1.,    4.,    3.,    0.,    0.,   -6.,
        /* 1930 */
        -30805.,-2316., 5808., -951., 2980.,-1424., 1517.,  644.,
        1172.,-1692., -480., 1205.,  133.,  907.,  166.,  896.,
        727.,  205.,  584., -195., -422., -109.,  234.,  -90.,
        -237.,  327.,  -72.,  218.,   60.,  -32.,  -53., -131.,
        -118.,  -74.,   58.,   60.,   53.,    4.,   -9.,  102.,
        -242.,   19.,  -32.,  -16.,   32.,    8., -104.,  -46.,
        74.,  -54.,  -51.,    4.,  -15.,   25.,  -14.,  -34.,
        6.,  -12.,   29.,   18.,  -18.,    6.,  -20.,   11.,
        7.,    8.,   -3.,  -15.,   -9.,    5.,    2.,  -14.,
        5.,    5.,   -6.,   18.,    8.,   -5.,    8.,  -19.,
        8.,   10.,  -20.,    1.,   14.,  -12.,    5.,   12.,
        -3.,    1.,   -2.,   -2.,    9.,    3.,   10.,    0.,
        -2.,   -2.,    2.,   -3.,   -4.,    2.,    2.,    1.,
        -5.,    2.,   -2.,    6.,    6.,   -4.,    4.,    0.,
        0.,   -2.,    1.,    4.,    3.,    0.,    0.,   -6.,
        /* 1935 */
        -30715.,-2306., 5812.,-1018., 2984.,-1520., 1550.,  586.,
        1206.,-1740., -494., 1215.,  146.,  918.,  101.,  903.,
        744.,  188.,  565., -226., -415.,  -90.,  249., -114.,
        -241.,  329.,  -51.,  211.,   64.,  -33.,  -64., -136.,
        -115.,  -76.,   64.,   59.,   53.,    4.,   -8.,  104.,
        -246.,   25.,  -25.,  -15.,   25.,    4., -106.,  -40.,
        74.,  -53.,  -52.,    4.,  -17.,   23.,  -14.,  -33.,
        7.,  -11.,   29.,   18.,  -19.,    6.,  -19.,   11.,
        7.,    8.,   -3.,  -15.,   -9.,    5.,    1.,  -15.,
        6.,    5.,   -6.,   18.,    8.,   -5.,    7.,  -19.,
        8.,   10.,  -20.,    1.,   15.,  -12.,    5.,   11.,
        -3.,    1.,   -3.,   -2.,    9.,    3.,   11.,    0.,
        -2.,   -2.,    2.,   -3.,   -4.,    2.,    2.,    1.,
        -5.,    2.,   -2.,    6.,    6.,   -4.,    4.,    0.,
        0.,   -1.,    2.,    4.,    3.,    0.,    0.,   -6.,
        /* 1940 */
        -30654.,-2292., 5821.,-1106., 2981.,-1614., 1566.,  528.,
        1240.,-1790., -499., 1232.,  163.,  916.,   43.,  914.,
        762.,  169.,  550., -252., -405.,  -72.,  265., -141.,
        -241.,  334.,  -33.,  208.,   71.,  -33.,  -75., -141.,
        -113.,  -76.,   69.,   57.,   54.,    4.,   -7.,  105.,
        -249.,   33.,  -18.,  -15.,   18.,    0., -107.,  -33.,
        74.,  -53.,  -52.,    4.,  -18.,   20.,  -14.,  -31.,
        7.,   -9.,   29.,   17.,  -20.,    5.,  -19.,   11.,
        7.,    8.,   -3.,  -14.,  -10.,    5.,    1.,  -15.,
        6.,    5.,   -5.,   19.,    9.,   -5.,    7.,  -19.,
        8.,   10.,  -21.,    1.,   15.,  -12.,    5.,   11.,
        -3.,    1.,   -3.,   -2.,    9.,    3.,   11.,    1.,
        -2.,   -2.,    2.,   -3.,   -4.,    2.,    2.,    1.,
        -5.,    2.,   -2.,    6.,    6.,   -4.,    4.,    0.,
        0.,   -1.,    2.,    4.,    3.,    0.,    0.,   -6.,
        /* 1945 */
        -30594.,-2285., 5810.,-1244., 2990.,-1702., 1578.,  477.,
        1282.,-1834., -499., 1255.,  186.,  913.,  -11.,  944.,
        776.,  144.,  544., -276., -421.,  -55.,  304., -178.,
        -253.,  346.,  -12.,  194.,   95.,  -20.,  -67., -142.,
        -119.,  -82.,   82.,   59.,   57.,    6.,    6.,  100.,
        -246.,   16.,  -25.,   -9.,   21.,  -16., -104.,  -39.,
        70.,  -40.,  -45.,    0.,  -18.,    0.,    2.,  -29.,
        6.,  -10.,   28.,   15.,  -17.,   29.,  -22.,   13.,
        7.,   12.,   -8.,  -21.,   -5.,  -12.,    9.,   -7.,
        7.,    2.,  -10.,   18.,    7.,    3.,    2.,  -11.,
        5.,  -21.,  -27.,    1.,   17.,  -11.,   29.,    3.,
        -9.,   16.,    4.,   -3.,    9.,   -4.,    6.,   -3.,
        1.,   -4.,    8.,   -3.,   11.,    5.,    1.,    1.,
        2.,  -20.,   -5.,   -1.,   -1.,   -6.,    8.,    6.,
        -1.,   -4.,   -3.,   -2.,    5.,    0.,   -2.,   -2.,
        /* 1950 */
        -30554.,-2250., 5815.,-1341., 2998.,-1810., 1576.,  381.,
        1297.,-1889., -476., 1274.,  206.,  896.,  -46.,  954.,
        792.,  136.,  528., -278., -408.,  -37.,  303., -210.,
        -240.,  349.,    3.,  211.,  103.,  -20.,  -87., -147.,
        -122.,  -76.,   80.,   54.,   57.,   -1.,    4.,   99.,
        -247.,   33.,  -16.,  -12.,   12.,  -12., -105.,  -30.,
        65.,  -55.,  -35.,    2.,  -17.,    1.,    0.,  -40.,
        10.,   -7.,   36.,    5.,  -18.,   19.,  -16.,   22.,
        15.,    5.,   -4.,  -22.,   -1.,    0.,   11.,  -21.,
        15.,   -8.,  -13.,   17.,    5.,   -4.,   -1.,  -17.,
        3.,   -7.,  -24.,   -1.,   19.,  -25.,   12.,   10.,
        2.,    5.,    2.,   -5.,    8.,   -2.,    8.,    3.,
        -11.,    8.,   -7.,   -8.,    4.,   13.,   -1.,   -2.,
        13.,  -10.,   -4.,    2.,    4.,   -3.,   12.,    6.,
        3.,   -3.,    2.,    6.,   10.,   11.,    3.,    8.,
        /* 1955 */
        -30500.,-2215., 5820.,-1440., 3003.,-1898., 1581.,  291.,
        1302.,-1944., -462., 1288.,  216.,  882.,  -83.,  958.,
        796.,  133.,  510., -274., -397.,  -23.,  290., -230.,
        -229.,  360.,   15.,  230.,  110.,  -23.,  -98., -152.,
        -121.,  -69.,   78.,   47.,   57.,   -9.,    3.,   96.,
        -247.,   48.,   -8.,  -16.,    7.,  -12., -107.,  -24.,
        65.,  -56.,  -50.,    2.,  -24.,   10.,   -4.,  -32.,
        8.,  -11.,   28.,    9.,  -20.,   18.,  -18.,   11.,
        9.,   10.,   -6.,  -15.,  -14.,    5.,    6.,  -23.,
        10.,    3.,   -7.,   23.,    6.,   -4.,    9.,  -13.,
        4.,    9.,  -11.,   -4.,   12.,   -5.,    7.,    2.,
        6.,    4.,   -2.,    1.,   10.,    2.,    7.,    2.,
        -6.,    5.,    5.,   -3.,   -5.,   -4.,   -1.,    0.,
        2.,   -8.,   -3.,   -2.,    7.,   -4.,    4.,    1.,
        -2.,   -3.,    6.,    7.,   -2.,   -1.,    0.,   -3.,
        /* 1960 */
        -30421.,-2169., 5791.,-1555., 3002.,-1967., 1590.,  206.,
        1302.,-1992., -414., 1289.,  224.,  878., -130.,  957.,
        800.,  135.,  504., -278., -394.,    3.,  269., -255.,
        -222.,  362.,   16.,  242.,  125.,  -26., -117., -156.,
        -114.,  -63.,   81.,   46.,   58.,  -10.,    1.,   99.,
        -237.,   60.,   -1.,  -20.,   -2.,  -11., -113.,  -17.,
        67.,  -56.,  -55.,    5.,  -28.,   15.,   -6.,  -32.,
        7.,   -7.,   23.,   17.,  -18.,    8.,  -17.,   15.,
        6.,   11.,   -4.,  -14.,  -11.,    7.,    2.,  -18.,
        10.,    4.,   -5.,   23.,   10.,    1.,    8.,  -20.,
        4.,    6.,  -18.,    0.,   12.,   -9.,    2.,    1.,
        0.,    4.,   -3.,   -1.,    9.,   -2.,    8.,    3.,
        0.,   -1.,    5.,    1.,   -3.,    4.,    4.,    1.,
        0.,    0.,   -1.,    2.,    4.,   -5.,    6.,    1.,
        1.,   -1.,   -1.,    6.,    2.,    0.,    0.,   -7.,
        /* 1965 */
        -30334.,-2119., 5776.,-1662., 2997.,-2016., 1594.,  114.,
        1297.,-2038., -404., 1292.,  240.,  856., -165.,  957.,
        804.,  148.,  479., -269., -390.,   13.,  252., -269.,
        -219.,  358.,   19.,  254.,  128.,  -31., -126., -157.,
        -97.,  -62.,   81.,   45.,   61.,  -11.,    8.,  100.,
        -228.,   68.,    4.,  -32.,    1.,   -8., -111.,   -7.,
        75.,  -57.,  -61.,    4.,  -27.,   13.,   -2.,  -26.,
        6.,   -6.,   26.,   13.,  -23.,    1.,  -12.,   13.,
        5.,    7.,   -4.,  -12.,  -14.,    9.,    0.,  -16.,
        8.,    4.,   -1.,   24.,   11.,   -3.,    4.,  -17.,
        8.,   10.,  -22.,    2.,   15.,  -13.,    7.,   10.,
        -4.,   -1.,   -5.,   -1.,   10.,    5.,   10.,    1.,
        -4.,   -2.,    1.,   -2.,   -3.,    2.,    2.,    1.,
        -5.,    2.,   -2.,    6.,    4.,   -4.,    4.,    0.,
        0.,   -2.,    2.,    3.,    2.,    0.,    0.,   -6.,
        /* 1970 */
        -30220.,-2068., 5737.,-1781., 3000.,-2047., 1611.,   25.,
        1287.,-2091., -366., 1278.,  251.,  838., -196.,  952.,
        800.,  167.,  461., -266., -395.,   26.,  234., -279.,
        -216.,  359.,   26.,  262.,  139.,  -42., -139., -160.,
        -91.,  -56.,   83.,   43.,   64.,  -12.,   15.,  100.,
        -212.,   72.,    2.,  -37.,    3.,   -6., -112.,    1.,
        72.,  -57.,  -70.,    1.,  -27.,   14.,   -4.,  -22.,
        8.,   -2.,   23.,   13.,  -23.,   -2.,  -11.,   14.,
        6.,    7.,   -2.,  -15.,  -13.,    6.,   -3.,  -17.,
        5.,    6.,    0.,   21.,   11.,   -6.,    3.,  -16.,
        8.,   10.,  -21.,    2.,   16.,  -12.,    6.,   10.,
        -4.,   -1.,   -5.,    0.,   10.,    3.,   11.,    1.,
        -2.,   -1.,    1.,   -3.,   -3.,    1.,    2.,    1.,
        -5.,    3.,   -1.,    4.,    6.,   -4.,    4.,    0.,
        1.,   -1.,    0.,    3.,    3.,    1.,   -1.,   -4.,
        /* 1975 */
        -30100.,-2013., 5675.,-1902., 3010.,-2067., 1632.,  -68.,
        1276.,-2144., -333., 1260.,  262.,  830., -223.,  946.,
        791.,  191.,  438., -265., -405.,   39.,  216., -288.,
        -218.,  356.,   31.,  264.,  148.,  -59., -152., -159.,
        -83.,  -49.,   88.,   45.,   66.,  -13.,   28.,   99.,
        -198.,   75.,    1.,  -41.,    6.,   -4., -111.,   11.,
        71.,  -56.,  -77.,    1.,  -26.,   16.,   -5.,  -14.,
        10.,    0.,   22.,   12.,  -23.,   -5.,  -12.,   14.,
        6.,    6.,   -1.,  -16.,  -12.,    4.,   -8.,  -19.,
        4.,    6.,    0.,   18.,   10.,  -10.,    1.,  -17.,
        7.,   10.,  -21.,    2.,   16.,  -12.,    7.,   10.,
        -4.,   -1.,   -5.,   -1.,   10.,    4.,   11.,    1.,
        -3.,   -2.,    1.,   -3.,   -3.,    1.,    2.,    1.,
        -5.,    3.,   -2.,    4.,    5.,   -4.,    4.,   -1.,
        1.,   -1.,    0.,    3.,    3.,    1.,   -1.,   -5.,
        /* 1980 */
        -29992.,-1956., 5604.,-1997., 3027.,-2129., 1663., -200.,
        1281.,-2180., -336., 1251.,  271.,  833., -252.,  938.,
        782.,  212.,  398., -257., -419.,   53.,  199., -297.,
        -218.,  357.,   46.,  261.,  150.,  -74., -151., -162.,
        -78.,  -48.,   92.,   48.,   66.,  -15.,   42.,   93.,
        -192.,   71.,    4.,  -43.,   14.,   -2., -108.,   17.,
        72.,  -59.,  -82.,    2.,  -27.,   21.,   -5.,  -12.,
        16.,    1.,   18.,   11.,  -23.,   -2.,  -10.,   18.,
        6.,    7.,    0.,  -18.,  -11.,    4.,   -7.,  -22.,
        4.,    9.,    3.,   16.,    6.,  -13.,   -1.,  -15.,
        5.,   10.,  -21.,    1.,   16.,  -12.,    9.,    9.,
        -5.,   -3.,   -6.,   -1.,    9.,    7.,   10.,    2.,
        -6.,   -5.,    2.,   -4.,   -4.,    1.,    2.,    0.,
        -5.,    3.,   -2.,    6.,    5.,   -4.,    3.,    0.,
        1.,   -1.,    2.,    4.,    3.,    0.,    0.,   -6.,
        /* 1985 */
        -29873.,-1905., 5500.,-2072., 3044.,-2197., 1687., -306.,
        1296.,-2208., -310., 1247.,  284.,  829., -297.,  936.,
        780.,  232.,  361., -249., -424.,   69.,  170., -297.,
        -214.,  355.,   47.,  253.,  150.,  -93., -154., -164.,
        -75.,  -46.,   95.,   53.,   65.,  -16.,   51.,   88.,
        -185.,   69.,    4.,  -48.,   16.,   -1., -102.,   21.,
        74.,  -62.,  -83.,    3.,  -27.,   24.,   -2.,   -6.,
        20.,    4.,   17.,   10.,  -23.,    0.,   -7.,   21.,
        6.,    8.,    0.,  -19.,  -11.,    5.,   -9.,  -23.,
        4.,   11.,    4.,   14.,    4.,  -15.,   -4.,  -11.,
        5.,   10.,  -21.,    1.,   15.,  -12.,    9.,    9.,
        -6.,   -3.,   -6.,   -1.,    9.,    7.,    9.,    1.,
        -7.,   -5.,    2.,   -4.,   -4.,    1.,    3.,    0.,
        -5.,    3.,   -2.,    6.,    5.,   -4.,    3.,    0.,
        1.,   -1.,    2.,    4.,    3.,    0.,    0.,   -6.,
        /* 1990 */
        -29775.,-1848., 5406.,-2131., 3059.,-2279., 1686., -373.,
        1314.,-2239., -284., 1248.,  293.,  802., -352.,  939.,
        780.,  247.,  325., -240., -423.,   84.,  141., -299.,
        -214.,  353.,   46.,  245.,  154., -109., -153., -165.,
        -69.,  -36.,   97.,   61.,   65.,  -16.,   59.,   82.,
        -178.,   69.,    3.,  -52.,   18.,    1.,  -96.,   24.,
        77.,  -64.,  -80.,    2.,  -26.,   26.,    0.,   -1.,
        21.,    5.,   17.,    9.,  -23.,    0.,   -4.,   23.,
        5.,   10.,   -1.,  -19.,  -10.,    6.,  -12.,  -22.,
        3.,   12.,    4.,   12.,    2.,  -16.,   -6.,  -10.,
        4.,    9.,  -20.,    1.,   15.,  -12.,   11.,    9.,
        -7.,   -4.,   -7.,   -2.,    9.,    7.,    8.,    1.,
        -7.,   -6.,    2.,   -3.,   -4.,    2.,    2.,    1.,
        -5.,    3.,   -2.,    6.,    4.,   -4.,    3.,    0.,
        1.,   -2.,    3.,    3.,    3.,   -1.,    0.,   -6.,
        /* 1995 */
        -29692.,-1784., 5306.,-2200., 3070.,-2366., 1681., -412.,
        1335.,-2266., -262., 1248.,  302.,  758., -427.,  940.,
        780.,  262.,  290., -236., -418.,   97.,  122., -306.,
        -214.,  352.,   46.,  235.,  165., -118., -142., -166.,
        -55.,  -17.,  107.,   68.,   67.,  -17.,   68.,   72.,
        -170.,   67.,    0.,  -58.,   18.,    1.,  -93.,   36.,
        77.,  -72.,  -69.,    0.,  -25.,   28.,    4.,    5.,
        24.,    4.,   17.,    8.,  -24.,   -2.,   -6.,   25.,
        6.,   11.,   -6.,  -21.,   -9.,    8.,  -14.,  -23.,
        9.,   14.,    6.,   11.,   -4.,  -16.,   -7.,   -4.,
        4.,    9.,  -20.,    2.,   15.,  -10.,   12.,    8.,
        -6.,   -8.,   -8.,   -1.,    8.,   10.,    5.,   -2.,
        -8.,   -8.,    3.,   -3.,   -6.,    1.,    2.,    0.,
        -4.,    4.,   -1.,    5.,    4.,   -5.,    2.,   -1.,
        2.,   -2.,    5.,    1.,    1.,   -2.,    0.,   -7.,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        /* 2000 */
        -29619.4,-1728.2, 5186.1,-2267.7, 3068.4,-2481.6, 1670.9,
        -458.0, 1339.6,-2288.0, -227.6, 1252.1,  293.4,  714.5,
        -491.1,  932.3,  786.8,  272.6,  250.0, -231.9, -403.0,
        119.8,  111.3, -303.8, -218.8,  351.4,   43.8,  222.3,
        171.9, -130.4, -133.1, -168.6,  -39.3,  -12.9,  106.3,
        72.3,   68.2,  -17.4,   74.2,   63.7, -160.9,   65.1,
        -5.9,  -61.2,   16.9,    0.7,  -90.4,   43.8,   79.0,
        -74.0,  -64.6,    0.0,  -24.2,   33.3,    6.2,    9.1,
        24.0,    6.9,   14.8,    7.3,  -25.4,   -1.2,   -5.8,
        24.4,    6.6,   11.9,   -9.2,  -21.5,   -7.9,    8.5,
        -16.6,  -21.5,    9.1,   15.5,    7.0,    8.9,   -7.9,
        -14.9,   -7.0,   -2.1,    5.0,    9.4,  -19.7,    3.0,
        13.4,   -8.4,   12.5,    6.3,   -6.2,   -8.9,   -8.4,
        -1.5,    8.4,    9.3,    3.8,   -4.3,   -8.2,   -8.2,
        4.8,   -2.6,   -6.0,    1.7,    1.7,    0.0,   -3.1,
        4.0,   -0.5,    4.9,    3.7,   -5.9,    1.0,   -1.2,
        2.0,   -2.9,    4.2,    0.2,    0.3,   -2.2,   -1.1,
        -7.4,    2.7,   -1.7,    0.1,   -1.9,    1.3,    1.5,
        -0.9,   -0.1,   -2.6,    0.1,    0.9,   -0.7,   -0.7,
        0.7,   -2.8,    1.7,   -0.9,    0.1,   -1.2,    1.2,
        -1.9,    4.0,   -0.9,   -2.2,   -0.3,   -0.4,    0.2,
        0.3,    0.9,    2.5,   -0.2,   -2.6,    0.9,    0.7,
        -0.5,    0.3,    0.3,    0.0,   -0.3,    0.0,   -0.4,
        0.3,   -0.1,   -0.9,   -0.2,   -0.4,   -0.4,    0.8,
        -0.2,   -0.9,   -0.9,    0.3,    0.2,    0.1,    1.8,
        -0.4,   -0.4,    1.3,   -1.0,   -0.4,   -0.1,    0.7,
        0.7,   -0.4,    0.3,    0.3,    0.6,   -0.1,    0.3,
        0.4,   -0.2,    0.0,   -0.5,    0.1,   -0.9,
        /* 2002 */
        13.3,  11.6, -21.2, -14.4,  -3.7, -22.7,  -3.6, -11.1,
        -1.1,  -3.5,   5.6,  -1.2,  -4.5,  -8.5,  -8.0,  -2.7,
        2.2,   1.7,  -8.0,   1.0,   4.5,   5.1,  -1.9,  -0.3,
        -1.4,   0.7,  -0.3,  -2.6,   1.5,  -1.2,   2.0,   0.0,
        3.8,  -0.2,  -0.5,   0.4,   0.3,  -0.7,   0.7,  -1.8,
        1.9,  -0.2,  -1.7,  -0.4,  -0.5,  -0.2,   0.7,   1.5,
        0.2,  -0.1,   0.7,  -0.3,   0.3,   1.1,   0.1,   0.7,
        0.3,   0.5,  -0.8,  -0.3,  -0.1,   0.5,   0.2,   0.1,
        0.2,  -0.2,  -0.5,   0.1,   0.2,   0.3,  -0.4,   0.4,
        0.2,   0.1,   0.5,  -0.3,  -0.7,   0.4,   0.4,   0.4,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        };