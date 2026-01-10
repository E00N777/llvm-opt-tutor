//====================================================================
// FILE: ToyMem2Reg.h
//====================================================================


#ifndef LLVM_OPT_TUTOR_TOYMEM2REG_H
#define LLVM_OPT_TUTOR_TOYMEM2REG_H

#include "llvm/IR/PassManager.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Dominators.h"
#include "llvm/Analysis/AssumptionCache.h"
#include "llvm/IR/Instructions.h"
#include <vector>

//------------------------------------------------------------------------------
// New PM interface
//------------------------------------------------------------------------------

struct ToyMem2Reg : public llvm::PassInfoMixin<ToyMem2Reg>
{
    llvm::PreservedAnalyses run(llvm::Function &F,
                                llvm::FunctionAnalysisManager &FAM);
    

    static bool runOnFunction(llvm::Function &F, llvm::DominatorTree &DT,
                      llvm::AssumptionCache &AC);
                      
    static bool ifAllocacanPromote(llvm::AllocaInst *AI);

    static void TranslateMemToReg(std::vector<llvm::AllocaInst*> &AllocaList,
                                  llvm::Function &F);
};



#endif