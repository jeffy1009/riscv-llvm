add_llvm_library(LLVMsoftboundcets
  FixByValAttributesPass.cpp
  InitializeSoftBoundCETS.cpp
  SoftBoundCETS.cpp
    
  ADDITIONAL_HEADER_DIRS
  ${LLVM_MAIN_INCLUDE_DIR}/llvm/Transforms
  ${LLVM_MAIN_INCLUDE_DIR}/llvm/Transforms/SoftBoundCETS
  )

add_dependencies(LLVMsoftboundcets intrinsics_gen)
