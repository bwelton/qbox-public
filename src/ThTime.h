////////////////////////////////////////////////////////////////////////////////
//
// ThTime.h
//
////////////////////////////////////////////////////////////////////////////////
// $Id: ThTime.h,v 1.1 2003-08-28 00:28:51 fgygi Exp $

#ifndef THTIME_H
#define THTIME_H

#include<iostream>
#include<iomanip>
#include<sstream>
#include<stdlib.h>

#include "Sample.h"

class ThTime : public Var
{
  Sample *s;

  public:

  char *name ( void ) const { return "th_time"; };

  int set ( int argc, char **argv )
  {
    if ( argc != 2 )
    {
      if ( ui->onpe0() )
      cout << " th_time takes only one value" << endl;
      return 1;
    }
    
    double v = atof(argv[1]);
    if ( v < 0.0 )
    {
      if ( ui->onpe0() )
        cout << " th_time must be non-negative" << endl;
      return 1;
    }

    s->ctrl.th_time = v;
    return 0;
  }

  string print (void) const
  {
     ostringstream st;
     st.setf(ios::left,ios::adjustfield);
     st << setw(10) << name() << " = ";
     st.setf(ios::right,ios::adjustfield);
     st << setw(10) << s->ctrl.th_time;
     return st.str();
  }

  ThTime(Sample *sample) : s(sample) { s->ctrl.th_time = 5000.0; }
};
#endif
