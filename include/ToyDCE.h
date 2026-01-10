//====================================================================
// FILE: ToyDCE.h
//====================================================================

#ifndef LLVM_OPT_TUTOR_TOYDCE_H
#define LLVM_OPT_TUTOR_TOYDCE_H

#include "llvm/IR/PassManager.h"
#include "llvm/IR/Function.h"


struct ToyDCE : public llvm::PassInfoMixin<ToyDCE>
{
    llvm::PreservedAnalyses run(llvm::Function &F,
                                llvm::FunctionAnalysisManager &FAM);
    
    static bool runOnFunction(llvm::Function &F);
};


#endif