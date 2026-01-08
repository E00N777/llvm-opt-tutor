//====================================================================
// FILE: ToyMem2Reg.h
//====================================================================


#ifndef LLVM_OPT_TUTOR_TOYMEM2REG_H
#define LLVM_OPT_TUTOR_TOYMEM2REG_H

#include "llvm/IR/PassManager.h"
#include "llvm/IR/Function.h"

//------------------------------------------------------------------------------
// New PM interface
//------------------------------------------------------------------------------

struct ToyMem2Reg : public llvm::PassInfoMixin<ToyMem2Reg>
{
    llvm::PreservedAnalyses run(llvm::Function &F,
                                llvm::FunctionAnalysisManager &FAM);
    

    bool runOnFunction(llvm::Function &F);
};



#endif