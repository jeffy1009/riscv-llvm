#include "llvm/Analysis/CallGraph.h"
#include "llvm/Transforms/Instrumentation.h"
#include "llvm/IR/InstVisitor.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/MDBuilder.h"
#include "llvm/Transforms/Utils/Local.h"
#include "llvm/Transforms/Utils/ModuleUtils.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Type.h"
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/Constants.h"
#include "llvm/Analysis/ConstantFolding.h"
#include "llvm/Analysis/MemoryBuiltins.h"
#include "llvm/mte/TypeSanUtil.h"
#include "llvm/mte/TypeSanPass.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE 1000
#define MAX_PNUM 50
#define MAX_NAME 500

#define FDEBUG_LOG // print debugging information into the file

cl::opt<bool>
ENABLE_RISCV
("enable_riscv",
 cl::desc("enable riscv"),
 cl::init(false)); // jsshin

//register pass
char TypeSan::ID = 0;

INITIALIZE_PASS_BEGIN(TypeSan, "TypeSan",
                "TypeUtilPass: fast type safety for C++ programs.",
                false, false)
INITIALIZE_PASS_DEPENDENCY(CallGraphWrapperPass)
INITIALIZE_PASS_END(TypeSan, "TypeSan",
                "TypeSanPass: fast type safety for C++ programs.",
                false, false)

ModulePass *llvm::createTypeSanPass() {
  return new TypeSan();
}

