/*
 * CustomInliner.cpp
 *
 *  Created on: Nov 10, 2015
 *      Author: haller
 */

#include <llvm/Transforms/IPO/InlinerPass.h>
#include <llvm/Analysis/InlineCost.h>

#include <llvm/mte/metadata.h>
#include <llvm/mte/CustomInliner.h>

using namespace llvm;


char CustomInliner::ID = 0;
static RegisterPass<CustomInliner> X("custominline", "Custom Inliner Pass", true, false);




