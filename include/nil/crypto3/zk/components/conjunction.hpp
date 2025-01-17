//---------------------------------------------------------------------------//
// Copyright (c) 2018-2021 Mikhail Komarov <nemo@nil.foundation>
// Copyright (c) 2020-2021 Nikita Kaskov <nbering@nil.foundation>
//
// MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//---------------------------------------------------------------------------//

#ifndef CRYPTO3_ZK_BLUEPRINT_CONJUNCTION_COMPONENT_HPP
#define CRYPTO3_ZK_BLUEPRINT_CONJUNCTION_COMPONENT_HPP

#include <cassert>
#include <memory>

#include <nil/crypto3/zk/component.hpp>

#include <nil/crypto3/multiprecision/number.hpp>
#include <nil/crypto3/zk/snark/arithmetization/constraint_satisfaction_problems/r1cs.hpp>

namespace nil {
    namespace crypto3 {
        namespace zk {
            namespace components {

                /*
                  the components below are Fp specific:
                  I * X = R
                  (1-R) * X = 0

                  if X = 0 then R = 0
                  if X != 0 then R = 1 and I = X^{-1}
                */
                template<typename FieldType>
                class conjunction : public component<FieldType> {
                private:
                    blueprint_variable<FieldType> inv;

                public:
                    const blueprint_variable_vector<FieldType> inputs;
                    const blueprint_variable<FieldType> output;

                    conjunction(blueprint<FieldType> &bp,
                                const blueprint_variable_vector<FieldType> &inputs,
                                const blueprint_variable<FieldType> &output) :
                        component<FieldType>(bp),
                        inputs(inputs), output(output) {
                        assert(inputs.size() >= 1);
                        inv.allocate(bp);
                    }

                    void generate_r1cs_constraints() {
                        /* inv * (n-sum) = 1-output */
                        blueprint_linear_combination<FieldType> a1, b1, c1;
                        a1.add_term(inv);
                        b1.add_term(blueprint_variable<FieldType>(0), inputs.size());
                        for (std::size_t i = 0; i < inputs.size(); ++i) {
                            b1.add_term(inputs[i], -1);
                        }
                        c1.add_term(blueprint_variable<FieldType>(0));
                        c1.add_term(output, -1);

                        this->bp.add_r1cs_constraint(snark::r1cs_constraint<FieldType>(a1, b1, c1));

                        /* output * (n-sum) = 0 */
                        blueprint_linear_combination<FieldType> a2, b2, c2;
                        a2.add_term(output);
                        b2.add_term(blueprint_variable<FieldType>(0), inputs.size());
                        for (std::size_t i = 0; i < inputs.size(); ++i) {
                            b2.add_term(inputs[i], -1);
                        }
                        c2.add_term(blueprint_variable<FieldType>(0), 0);

                        this->bp.add_r1cs_constraint(snark::r1cs_constraint<FieldType>(a2, b2, c2));
                    }
                    void generate_r1cs_witness() {
                        typename FieldType::value_type sum = typename FieldType::value_type(inputs.size());

                        for (std::size_t i = 0; i < inputs.size(); ++i) {
                            sum -= this->bp.val(inputs[i]);
                        }

                        if (sum.is_zero()) {
                            this->bp.val(inv) = FieldType::value_type::zero();
                            this->bp.val(output) = FieldType::value_type::one();
                        } else {
                            this->bp.val(inv) = sum.inversed();
                            this->bp.val(output) = FieldType::value_type::zero();
                        }
                    }
                };

            }    // namespace components
        }        // namespace zk
    }            // namespace crypto3
}    // namespace nil
#endif    // CRYPTO3_ZK_BLUEPRINT_CONJUNCTION_COMPONENT_HPP
