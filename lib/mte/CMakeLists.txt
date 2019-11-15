add_llvm_library(LLVMmte
  ArgvTracker.cpp
  ByvalHandler.cpp
  CustomInliner.cpp
  DummyPass.cpp
  GlobalTracker.cpp
  MaskPointers.cpp
  MidFatPtrs.cpp
  Utils.cpp
  TypeSanPass.cpp
  TypeSanUtil.cpp
  )

add_dependencies(LLVMmte intrinsics_gen)
