////////////////////////////////////////////////////////////////////////////////
//
// ListAtomsCmd.h:
//
////////////////////////////////////////////////////////////////////////////////
// $Id: ListAtomsCmd.h,v 1.2 2003-03-27 22:05:59 fgygi Exp $

#ifndef LISTATOMSCMD_H
#define LISTATOMSCMD_H

#include <iostream>
#include "UserInterface.h"
#include "Sample.h"
#include <cstdlib>

class ListAtomsCmd : public Cmd
{
  public:

  Sample *s;

  ListAtomsCmd(Sample *sample) : s(sample) {};

  char *name(void) const { return "list_atoms"; }
  char *help_msg(void) const
  {
    return 
    "\n list_atoms\n\n"
    " syntax: list_atoms\n\n"
    "   The list_atoms command prints a list of all defined atoms.\n\n";
  }

  int action(int argc, char **argv)
  {
    if ( argc != 1 )
    {
      if ( ui->onpe0() )
      {
        cout << " use: list_atoms" << endl;
      }
      return 1;
    }
    s->atoms.listAtoms();
    return 0;
  }
};
#endif
