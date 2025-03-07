#include <new>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>

#ifndef WIN32
#include <unistd.h>
#endif

#include <AMReX_CArena.H>
#include <AMReX_REAL.H>
#include <AMReX_Utility.H>
#include <AMReX_IntVect.H>
#include <AMReX_Box.H>
#include <AMReX_ParmParse.H>
#include <AMReX_ParallelDescriptor.H>

#include <time.h>

#include <extern_parameters.H>

#include <fstream>

#include <network.H>
#include <eos.H>
#include <init_1d.H>

std::string inputs_name = "";

int
main (int   argc,
      char* argv[])
{

  //
  // Make sure to catch new failures.
  //
  amrex::Initialize(argc,argv);

  // save the inputs file name for later
  if (argc > 1) {
    if (!strchr(argv[1], '=')) {
      inputs_name = argv[1];
    }
  }


  // initialize the runtime parameters

  init_extern_parameters();

  // initialize C++ Microphysics

  eos_init(problem_rp::small_temp, problem_rp::small_dens);

  init_1d();

  amrex::Finalize();

  return 0;
}
