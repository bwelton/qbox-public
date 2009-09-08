#-------------------------------------------------------------------------------
#
# Copyright (c) 2008 The Regents of the University of California
#
# This file is part of Qbox
#
# Qbox is distributed under the terms of the GNU General Public License
# as published by the Free Software Foundation, either version 2 of
# the License, or (at your option) any later version.
# See the file COPYING in the root directory of this distribution
# or <http://www.gnu.org/licenses/>.
#
#-------------------------------------------------------------------------------
#
#  x8664_gcc.mk
#
#-------------------------------------------------------------------------------
# $Id: pavane.mk,v 1.10 2009-09-08 05:38:06 fgygi Exp $
#
 PLT=Linux_x8664
#-------------------------------------------------------------------------------
 GCCDIR=/usr/lib/gcc/x86_64-redhat-linux/3.4.3
#MPIDIR=$(HOME)/software/mpich/mpich-1.2.6
 MPIDIR=/opt/mpich-1.2.7p1
 XERCESCDIR=$(HOME)/software/xerces/Linux_x8664/xerces-c-src_2_7_0
 PLTOBJECTS = readTSC.o

#CXX=/usr/bin/g++
 CXX=mpicxx
 LD=$(CXX)

 PLTFLAGS += -DIA32 -DUSE_FFTW -D_LARGEFILE_SOURCE \
             -D_FILE_OFFSET_BITS=64 -DUSE_MPI -DSCALAPACK -DADD_ \
             -DAPP_NO_THREADS -DXML_USE_NO_THREADS -DUSE_XERCES

 FFTWDIR=$(HOME)/software/fftw/Linux_x8664/fftw-2.1.5/fftw
 BLASDIR=$(HOME)/software/atlas/x86_64/lib
 LAPACKDIR=$(HOME)/software/lapack/LAPACK
#BLASDIR=/usr/lib64
#LAPACKDIR=/usr/lib64

 INCLUDE = -I$(MPIDIR)/include -I$(FFTWDIR) -I$(XERCESCDIR)/include

 CXXFLAGS= -O4 -Wunused -D$(PLT) $(INCLUDE) $(PLTFLAGS) $(DFLAGS)

 LIBPATH = -L$(FFTWDIR)/.libs -L/usr/X11R6/lib \
           -L$(MPIDIR)/lib -L$(BLASDIR) \
           -L$(XERCESCDIR)/lib -L$(HOME)/lib

#LIBS =  $(PLIBS) -lpthread -lfftw \
#        -lmpich -lxerces-c \
#        $(LAPACKDIR)/liblapack.a \
#        -lf77blas -latlas -lgfortran 
 LIBS =  $(PLIBS) -lpthread -lfftw \
         -lm -Xlinker -Bstatic \
          -lc -static-libgcc -lmpich -lxerces-c \
         $(LAPACKDIR)/liblapack.a \
         -lf77blas -latlas -lgfortran \
         -Xlinker -Bdynamic
#LIBS =  $(PLIBS) -lfftw -llapack -lblas -lm -lmpich \
#        $(XERCESCDIR)/lib/libxerces-c.a

 LDFLAGS = $(LIBPATH) $(LIBS)

 PLAT=Linux_x8664
 # Blacs libraries
 BLACSDBGLVL   = 0
 BLACSdir      = $(HOME)/software/blacs/Linux_x8664/BLACS/LIB
 BLACSFINIT    = $(BLACSdir)/blacsF77init_MPI-$(PLAT)-$(BLACSDBGLVL).a
 BLACSCINIT    = $(BLACSdir)/blacsCinit_MPI-$(PLAT)-$(BLACSDBGLVL).a
 BLACSLIB      = $(BLACSdir)/blacs_MPI-$(PLAT)-$(BLACSDBGLVL).a

 CBLACSLIB     = $(BLACSCINIT) $(BLACSLIB) $(BLACSCINIT)
 FBLACSLIB     = $(BLACSFINIT) $(BLACSLIB) $(BLACSFINIT)

 # Scalapack libraries
#SCALAPACK_DIR = $(HOME)/software/scalapack/Linux_x8664/SCALAPACK
 SCALAPACK_DIR = $(HOME)/software/scalapack/Linux_x8664/scalapack-1.8.0
#PBLASLIB      = $(SCALAPACK_DIR)/pblas_$(PLAT).a
 SCALAPACKLIB  = $(SCALAPACK_DIR)/libscalapack.a
#TOOLSLIB      = $(SCALAPACK_DIR)/tools_$(PLAT).a
#REDISTLIB     = $(SCALAPACK_DIR)/redist_$(PLAT).a

 LAPACKLIB = -llapack
 BLASLIB = -lf77blasf -latlas

# Parallel libraries
#PLIBS = $(SCALAPACKLIB) $(PBLASLIB) $(TOOLSLIB) $(REDISTLIB) $(CBLACSLIB)
 PLIBS = $(SCALAPACKLIB) $(CBLACSLIB)

#-------------------------------------------------------------------------------
