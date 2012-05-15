// Copyright © 2011, Université catholique de Louvain
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// *  Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// *  Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef __MODNUMBER_H
#define __MODNUMBER_H

#include "../mozartcore.hh"

#ifndef MOZART_GENERATOR

namespace mozart {

namespace builtins {

///////////////////
// Number module //
///////////////////

class Number: public Module {
public:
  Number(): Module("Number") {}

  class Opposite: public Builtin<Opposite> {
  public:
    Opposite(): Builtin("~") {}

    OpResult operator()(VM vm, In operand, Out result) {
      return Numeric(operand).opposite(vm, result);
    }
  };

  class Add: public Builtin<Add>, InlineAs<OpInlineAdd> {
  public:
    Add(): Builtin("+") {}

    OpResult operator()(VM vm, In left, In right, Out result) {
      return Numeric(left).add(vm, right, result);
    }
  };

  class Subtract: public Builtin<Subtract>, InlineAs<OpInlineSubtract> {
  public:
    Subtract(): Builtin("-") {}

    OpResult operator()(VM vm, In left, In right, Out result) {
      return Numeric(left).subtract(vm, right, result);
    }
  };

  class Multiply: public Builtin<Multiply> {
  public:
    Multiply(): Builtin("*") {}

    OpResult operator()(VM vm, In left, In right, Out result) {
      return Numeric(left).multiply(vm, right, result);
    }
  };
};

}

}

#endif // MOZART_GENERATOR

#endif // __MODNUMBER_H
