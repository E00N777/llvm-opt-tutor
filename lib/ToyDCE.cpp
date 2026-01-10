//====================================================================
// FILE: ToyDCE.cpp
//====================================================================

#include "ToyDCE.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"


using namespace llvm;

#define  DEBUG_TYPE "toy-dce"





PreservedAnalyses ToyDCE::run(Function &F,
                                    llvm::FunctionAnalysisManager &FAM)
{
    bool Changed = runOnFunction(F);
    if (Changed)
        return PreservedAnalyses::none();
    return PreservedAnalyses::all();
}


//-----------------------------------------------------------------------------
// New PM Registration
//-----------------------------------------------------------------------------
llvm::PassPluginLibraryInfo getToyDCEPluginInfo(){
    return {LLVM_PLUGIN_API_VERSION, "toy-dce", LLVM_VERSION_STRING,
            [](llvm::PassBuilder &PB) {
                PB.registerPipelineParsingCallback(
                    [](llvm::StringRef Name, llvm::FunctionPassManager &FPM,
                       llvm::ArrayRef<llvm::PassBuilder::PipelineElement>) {
                        if (Name == "toy-dce") {
                            FPM.addPass(ToyDCE());
                            return true;
                        }
                        return false;
                    });
            }};
}

extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
    return getToyDCEPluginInfo();
}