/* -*- mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
 *  Main authors:
 *     Guido Tack <guido.tack@monash.edu>
 */

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __MINIZINC_CPLEX_SOLVER_INSTANCE_HH__
#define __MINIZINC_CPLEX_SOLVER_INSTANCE_HH__

#include <minizinc/solver_instance_base.hh>
#include <ilcplex/ilocplex.h>

namespace MiniZinc {

  class CPLEXSolver {
  public:
    typedef IloNumVar Variable;
    typedef MiniZinc::Statistics Statistics;
  };
  
  class CPLEXSolverInstance : public SolverInstanceImpl<CPLEXSolver> {
  protected:
    IloEnv _iloenv;
    IloModel* _ilomodel;
    IloCplex* _ilocplex;
    std::vector<VarDecl*> _varsWithOutput;
  public:
    CPLEXSolverInstance(Env& env, const Options& options);

    virtual ~CPLEXSolverInstance(void);
    
    virtual Status next(void);

    virtual Status solve(void);

    virtual void processFlatZinc(void);
    
    virtual void resetSolver(void);
    
    void assignSolutionToOutput(void);

		/// PARAMS
		int nThreads;
		bool fVerbose;
		std::string sExportModel;
		double nTimeout;
    double nWorkMemLimit;
		
    IloModel* getIloModel(void);
    IloNum exprToIloNum(Expression* e);
    IloNumExpr exprToIloExpr(Expression* e);
    IloNumVar exprToIloNumVar(Expression* e);
    IloNumArray exprToIloNumArray(Expression* e);
    IloNumVarArray exprToIloNumVarArray(Expression* e);
    
  protected:
    virtual Expression* getSolutionValue(Id* id);

    void registerConstraints(void);
  };
  
}

#endif