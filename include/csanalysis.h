#include "utils.h"

namespace {
	class CallSiteAnalysisPass : public ModulePass {
	public:
		static char ID; // Pass identification, replacement for typeid
		CallSiteAnalysisPass() : ModulePass(ID) {}

		bool runOnModule(Module &M) override;

	private:
	};
}

char CallSiteAnalysisPass::ID=0;
static RegisterPass<CallSiteAnalysisPass> X("csanalysis","function pointer call-site analysis");

static void registerCallSiteAnalysisPass(const PassManagerBuilder &,
                     legacy::PassManagerBase &PM) {
        PM.add(new CallSiteAnalysisPass());
}

static RegisterStandardPasses
        RegisterMyPass(PassManagerBuilder::EP_ModuleOptimizerEarly, registerCallSiteAnalysisPass);

static RegisterStandardPasses
        RegisterMyPass0(PassManagerBuilder::EP_EnabledOnOptLevel0, registerCallSiteAnalysisPass);
