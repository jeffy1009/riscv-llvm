/*
 * ArgvTracker.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: Erik van der Kouwe
 */

#include <llvm/Pass.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IntrinsicInst.h>
#include <llvm/IR/Intrinsics.h>
#include <llvm/IR/Constant.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/Debug.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Target/TargetLowering.h>
#include <llvm/Target/TargetSubtargetInfo.h>
#include <llvm/Transforms/Utils/Local.h>
#include <llvm/Transforms/Utils/ModuleUtils.h>

#include <string>
#include <list>
#include <set>
#include <vector>

#include <llvm/mte/Utils.h>
#include <llvm/mte/ArgvTracker.h>

#define DEBUG_TYPE "ArgvTracker"

using namespace llvm;


char ArgvTracker::ID = 0;
static RegisterPass<ArgvTracker> X("argvtracker", "Argv Tracker Pass", true, false);




