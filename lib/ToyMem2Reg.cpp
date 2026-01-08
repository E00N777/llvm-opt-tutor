#include "ToyMem2Reg.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Passes/PassBuilder.h"



#define  DEBUG_TYPE "toy-mem2reg"



llvm::PreservedAnalyses ToyMem2Reg::run(llvm::Function &F,
                                        llvm::FunctionAnalysisManager &FAM)
{
    bool Finashed = runOnFunction(F);

    return (Finashed ? llvm::PreservedAnalyses::none()
                     : llvm::PreservedAnalyses::all());
}


//-----------------------------------------------------------------------------
// New PM Registration
//-----------------------------------------------------------------------------
llvm::PassPluginLibraryInfo getToyMem2RegPluginInfo(){
    return {LLVM_PLUGIN_API_VERSION, "toy-mem2reg", LLVM_VERSION_STRING,
            [](llvm::PassBuilder &PB) {
                PB.registerPipelineParsingCallback(
                    [](llvm::StringRef Name, llvm::FunctionPassManager &FPM,
                       llvm::ArrayRef<llvm::PassBuilder::PipelineElement>) {
                        if (Name == "toy-mem2reg") {
                            FPM.addPass(ToyMem2Reg());
                            return true;
                        }
                        return false;
                    });
            }};
}

extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
    return getToyMem2RegPluginInfo();
}