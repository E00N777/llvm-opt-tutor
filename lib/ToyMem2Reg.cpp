#include "ToyMem2Reg.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/IR/PassManager.h"
#include "llvm/IR/Dominators.h"
#include "llvm/IR/Function.h"
#include "llvm/Analysis/AssumptionCache.h"
#include <vector> 

using namespace llvm;

#define  DEBUG_TYPE "toy-mem2reg"

static bool ifAllocacanPromote(AllocaInst &AI)
{
  
    return true;
}

static void TranslateMemToReg(std::vector<AllocaInst*> &AllocaList,
                             llvm::Function &F)
{
    //TO DO
}

static bool runOnFunction(llvm::Function &F, llvm::DominatorTree &DT,
                            llvm::AssumptionCache &AC){
    bool Changed = false;
    std::vector<llvm::AllocaInst*> Alloca;

    for(auto &BB : F)
    {
        for(auto & Inst : BB)
        {
            if(AllocaInst * AI= dyn_cast<AllocaInst>(&Inst))
            {
                if(ifAllocacanPromote(*AI))
                {
                    Alloca.push_back(AI);
                }
            }
               
        }

        if(Alloca.empty()){break;}

        TranslateMemToReg(Alloca, F);
        Changed = true;
      
    }


    return Changed;
}

PreservedAnalyses ToyMem2Reg::run(Function &F,
                                    llvm::FunctionAnalysisManager &FAM)
{
    auto &DT = FAM.getResult<DominatorTreeAnalysis>(F);
    auto &AC = FAM.getResult<AssumptionAnalysis>(F);

    bool Finished = runOnFunction(F, DT, AC);

    return (Finished ? llvm::PreservedAnalyses::none()
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