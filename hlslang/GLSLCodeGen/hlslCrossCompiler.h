// Copyright (c) The HLSL2GLSLFork Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE.txt file.


#ifndef HLSL_CROSS_COMPILER_H
#define HLSL_CROSS_COMPILER_H


#include "../Include/Common.h"

#include "glslFunction.h"
#include "glslStruct.h"

class HlslLinker;

class HlslCrossCompiler
{
public:   
   HlslCrossCompiler(EShLanguage l);
   ~HlslCrossCompiler();

   EShLanguage getLanguage() const { return language; }
   TInfoSink& getInfoSink() { return infoSink; }

   void TransformAST (TIntermNode* root);
   void ProduceGLSL (TIntermNode* root, bool usePrecision, bool outputLines);
   bool IsASTTransformed() const { return m_ASTTransformed; }
   bool IsGlslProduced() const { return m_GlslProduced; }

   HlslLinker* GetLinker() { return linker; }

private:
	EShLanguage language;
	bool m_ASTTransformed;
	bool m_GlslProduced;

public:
	HlslLinker* linker;
   TInfoSink infoSink;
   std::vector<GlslFunction*> functionList;
   std::vector<GlslStruct*> structList;
};

#endif //HLSL_CROSS_COMPILER_H
