//---------------------------------------------------------------------------//
// Copyright (c) 2018-2020 Mikhail Komarov <nemo@nil.foundation>
// Copyright (c) 2020 Nikita Kaskov <nbering@nil.foundation>
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
// @file Declaration of interfaces for final exponentiation components.
//
// The components verify final exponentiation for Weiersrass curves with embedding
// degrees 4 and 6.
//---------------------------------------------------------------------------//

#ifndef CRYPTO3_ZK_WEIERSTRASS_FINAL_EXPONENTIATION_HPP
#define CRYPTO3_ZK_WEIERSTRASS_FINAL_EXPONENTIATION_HPP

#include <memory>

#include <nil/crypto3/zk/snark/components/fields/exponentiation_component.hpp>
#include <nil/crypto3/zk/snark/components/pairing/mnt_pairing_params.hpp>

namespace nil {
    namespace crypto3 {
        namespace zk {
            namespace snark {
                namespace components {

                    /**
                     * Gadget for final exponentiation with embedding degree 4.
                     */
                    template<typename CurveType>
                    struct mnt4_final_exp_component : public component<typename CurveType::scalar_field_type> {

                        typedef typename CurveType::scalar_field_type field_type;

                        Fqk_variable<CurveType> el;
                        std::shared_ptr<Fqk_variable<CurveType>> one;
                        std::shared_ptr<Fqk_variable<CurveType>> el_inv;
                        std::shared_ptr<Fqk_variable<CurveType>> el_q_3;
                        std::shared_ptr<Fqk_variable<CurveType>> el_q_3_minus_1;
                        std::shared_ptr<Fqk_variable<CurveType>> alpha;
                        std::shared_ptr<Fqk_variable<CurveType>> beta;
                        std::shared_ptr<Fqk_variable<CurveType>> beta_q;
                        std::shared_ptr<Fqk_variable<CurveType>> el_inv_q_3;
                        std::shared_ptr<Fqk_variable<CurveType>> el_inv_q_3_minus_1;
                        std::shared_ptr<Fqk_variable<CurveType>> inv_alpha;
                        std::shared_ptr<Fqk_variable<CurveType>> inv_beta;
                        std::shared_ptr<Fqk_variable<CurveType>> w1;
                        std::shared_ptr<Fqk_variable<CurveType>> w0;
                        std::shared_ptr<Fqk_variable<CurveType>> result;

                        std::shared_ptr<Fqk_mul_component<CurveType>> compute_el_inv;
                        std::shared_ptr<Fqk_mul_component<CurveType>> compute_el_q_3_minus_1;
                        std::shared_ptr<Fqk_mul_component<CurveType>> compute_beta;
                        std::shared_ptr<Fqk_mul_component<CurveType>> compute_el_inv_q_3_minus_1;
                        std::shared_ptr<Fqk_mul_component<CurveType>> compute_inv_beta;

                        std::shared_ptr<exponentiation_component<CurveType>::pairing_policy::Fqk_type,
                                        Fp6_2over3_variable,
                                        Fp6_2over3_mul_component,
                                        Fp6_2over3_cyclotomic_sqr_component,
                                        algebra::mnt6_q_limbs> > compute_w1;
                        std::shared_ptr<exponentiation_component<CurveType>::pairing_policy::Fqk_type,
                                        Fp6_2over3_variable,
                                        Fp6_2over3_mul_component,
                                        Fp6_2over3_cyclotomic_sqr_component,
                                        algebra::mnt6_q_limbs> > compute_w0;
                        std::shared_ptr<Fqk_mul_component<CurveType>> compute_result;

                        variable<field_type> result_is_one;

                        mnt4_final_exp_component(blueprint<field_type> &bp,
                                                 const Fqk_variable<CurveType> &el,
                                                 const variable<field_type> &result_is_one) :
                            component<field_type>(bp),
                            el(el), result_is_one(result_is_one) {
                            one.reset(new Fqk_variable<CurveType>(bp));
                            el_inv.reset(new Fqk_variable<CurveType>(bp));
                            el_q_3.reset(new Fqk_variable<CurveType>(el.Frobenius_map(3)));
                            el_q_3_minus_1.reset(new Fqk_variable<CurveType>(bp));
                            alpha.reset(new Fqk_variable<CurveType>(el_q_3_minus_1->Frobenius_map(1)));
                            beta.reset(new Fqk_variable<CurveType>(bp));
                            beta_q.reset(new Fqk_variable<CurveType>(beta->Frobenius_map(1)));

                            el_inv_q_3.reset(new Fqk_variable<CurveType>(el_inv->Frobenius_map(3)));
                            el_inv_q_3_minus_1.reset(new Fqk_variable<CurveType>(bp));
                            inv_alpha.reset(new Fqk_variable<CurveType>(el_inv_q_3_minus_1->Frobenius_map(1)));
                            inv_beta.reset(new Fqk_variable<CurveType>(bp));
                            w1.reset(new Fqk_variable<CurveType>(bp));
                            w0.reset(new Fqk_variable<CurveType>(bp));
                            result.reset(new Fqk_variable<CurveType>(bp));

                            compute_el_inv.reset(new Fqk_mul_component<CurveType>(bp, el, *el_inv, *one));
                            compute_el_q_3_minus_1.reset(
                                new Fqk_mul_component<CurveType>(bp, *el_q_3, *el_inv, *el_q_3_minus_1));
                            compute_beta.reset(new Fqk_mul_component<CurveType>(bp, *alpha, *el_q_3_minus_1, *beta));

                            compute_el_inv_q_3_minus_1.reset(
                                new Fqk_mul_component<CurveType>(bp, *el_inv_q_3, el, *el_inv_q_3_minus_1));
                            compute_inv_beta.reset(
                                new Fqk_mul_component<CurveType>(bp, *inv_alpha, *el_inv_q_3_minus_1, *inv_beta));

                            compute_w1.reset(new exponentiation_component<CurveType>::pairing_policy::Fqk_type,
                                             Fp6_2over3_variable,
                                             Fp6_2over3_mul_component,
                                             Fp6_2over3_cyclotomic_sqr_component,
                                             algebra::mnt6_q_limbs >
                                                 (bp, *beta_q, algebra::mnt6_final_exponent_last_chunk_w1, *w1));

                            compute_w0.reset(new exponentiation_component<CurveType>::pairing_policy::Fqk_type,
                                             Fp6_2over3_variable,
                                             Fp6_2over3_mul_component,
                                             Fp6_2over3_cyclotomic_sqr_component,
                                             algebra::mnt6_q_limbs >
                                                 (bp,
                                                  (algebra::mnt6_final_exponent_last_chunk_is_w0_neg ? *inv_beta : *beta),
                                                  algebra::mnt6_final_exponent_last_chunk_abs_of_w0,
                                                  *w0));

                            compute_result.reset(new Fqk_mul_component<CurveType>(bp, *w1, *w0, *result));
                        }

                        void generate_r1cs_constraints() {
                            one->generate_r1cs_equals_const_constraints(
                                other_curve<CurveType>::pairing_policy::Fqk_type::value_type::one());

                            compute_el_inv->generate_r1cs_constraints();
                            compute_el_q_3_minus_1->generate_r1cs_constraints();
                            compute_beta->generate_r1cs_constraints();

                            compute_el_inv_q_3_minus_1->generate_r1cs_constraints();
                            compute_inv_beta->generate_r1cs_constraints();

                            compute_w0->generate_r1cs_constraints();
                            compute_w1->generate_r1cs_constraints();
                            compute_result->generate_r1cs_constraints();

                            generate_boolean_r1cs_constraint<field_type>(this->bp, result_is_one);
                            this->bp.add_r1cs_constraint(r1cs_constraint<field_type>(result_is_one, 1 - result->c0.c0, 0));
                            this->bp.add_r1cs_constraint(r1cs_constraint<field_type>(result_is_one, result->c0.c1, 0));
                            this->bp.add_r1cs_constraint(r1cs_constraint<field_type>(result_is_one, result->c0.c2, 0));
                            this->bp.add_r1cs_constraint(r1cs_constraint<field_type>(result_is_one, result->c1.c0, 0));
                            this->bp.add_r1cs_constraint(r1cs_constraint<field_type>(result_is_one, result->c1.c1, 0));
                            this->bp.add_r1cs_constraint(r1cs_constraint<field_type>(result_is_one, result->c1.c2, 0));
                        }

                        void generate_r1cs_witness() {
                            one->generate_r1cs_witness(other_curve<CurveType>::pairing_policy::Fqk_type::value_type::one());
                            el_inv->generate_r1cs_witness(el.get_element().inversed());

                            compute_el_inv->generate_r1cs_witness();
                            el_q_3->evaluate();
                            compute_el_q_3_minus_1->generate_r1cs_witness();
                            alpha->evaluate();
                            compute_beta->generate_r1cs_witness();
                            beta_q->evaluate();

                            el_inv_q_3->evaluate();
                            compute_el_inv_q_3_minus_1->generate_r1cs_witness();
                            inv_alpha->evaluate();
                            compute_inv_beta->generate_r1cs_witness();

                            compute_w0->generate_r1cs_witness();
                            compute_w1->generate_r1cs_witness();
                            compute_result->generate_r1cs_witness();

                            this->bp.val(result_is_one) =
                                (result->get_element() == one->get_element() ? field_type::value_type::one() :
                                                                               field_type::value_type::zero());
                        }
                    };

                    /**
                     * Gadget for final exponentiation with embedding degree 6.
                     */
                    template<typename CurveType>
                    struct mnt6_final_exp_component : public component<typename CurveType::scalar_field_type> {

                        typedef typename CurveType::scalar_field_type field_type;

                        Fqk_variable<CurveType> el;
                        std::shared_ptr<Fqk_variable<CurveType>> one;
                        std::shared_ptr<Fqk_variable<CurveType>> el_inv;
                        std::shared_ptr<Fqk_variable<CurveType>> el_q_2;
                        std::shared_ptr<Fqk_variable<CurveType>> el_q_2_minus_1;
                        std::shared_ptr<Fqk_variable<CurveType>> el_q_3_minus_q;
                        std::shared_ptr<Fqk_variable<CurveType>> el_inv_q_2;
                        std::shared_ptr<Fqk_variable<CurveType>> el_inv_q_2_minus_1;
                        std::shared_ptr<Fqk_variable<CurveType>> w1;
                        std::shared_ptr<Fqk_variable<CurveType>> w0;
                        std::shared_ptr<Fqk_variable<CurveType>> result;

                        std::shared_ptr<Fqk_mul_component<CurveType>> compute_el_inv;
                        std::shared_ptr<Fqk_mul_component<CurveType>> compute_el_q_2_minus_1;
                        std::shared_ptr<Fqk_mul_component<CurveType>> compute_el_inv_q_2_minus_1;

                        std::shared_ptr<exponentiation_component<CurveType>::pairing_policy::Fqk_type,
                                        Fp4_variable,
                                        Fp4_mul_component,
                                        Fp4_cyclotomic_sqr_component,
                                        algebra::mnt4_q_limbs> > compute_w1;
                        std::shared_ptr<exponentiation_component<CurveType>::pairing_policy::Fqk_type,
                                        Fp4_variable,
                                        Fp4_mul_component,
                                        Fp4_cyclotomic_sqr_component,
                                        algebra::mnt4_q_limbs> > compute_w0;
                        std::shared_ptr<Fqk_mul_component<CurveType>> compute_result;

                        variable<field_type> result_is_one;

                        mnt6_final_exp_component(blueprint<field_type> &bp,
                                                 const Fqk_variable<CurveType> &el,
                                                 const variable<field_type> &result_is_one) :
                            component<field_type>(bp),
                            el(el), result_is_one(result_is_one) {
                            one.reset(new Fqk_variable<CurveType>(bp));
                            el_inv.reset(new Fqk_variable<CurveType>(bp));
                            el_q_2.reset(new Fqk_variable<CurveType>(el.Frobenius_map(2)));
                            el_q_2_minus_1.reset(new Fqk_variable<CurveType>(bp));
                            el_q_3_minus_q.reset(new Fqk_variable<CurveType>(el_q_2_minus_1->Frobenius_map(1)));
                            el_inv_q_2.reset(new Fqk_variable<CurveType>(el_inv->Frobenius_map(2)));
                            el_inv_q_2_minus_1.reset(new Fqk_variable<CurveType>(bp));
                            w1.reset(new Fqk_variable<CurveType>(bp));
                            w0.reset(new Fqk_variable<CurveType>(bp));
                            result.reset(new Fqk_variable<CurveType>(bp));

                            compute_el_inv.reset(new Fqk_mul_component<CurveType>(bp, el, *el_inv, *one));
                            compute_el_q_2_minus_1.reset(
                                new Fqk_mul_component<CurveType>(bp, *el_q_2, *el_inv, *el_q_2_minus_1));
                            compute_el_inv_q_2_minus_1.reset(
                                new Fqk_mul_component<CurveType>(bp, *el_inv_q_2, el, *el_inv_q_2_minus_1));

                            compute_w1.reset(new exponentiation_component<CurveType>::pairing_policy::Fqk_type,
                                             Fp4_variable,
                                             Fp4_mul_component,
                                             Fp4_cyclotomic_sqr_component,
                                             algebra::mnt4_q_limbs >
                                                 (bp, *el_q_3_minus_q, algebra::mnt4_final_exponent_last_chunk_w1, *w1));
                            compute_w0.reset(new exponentiation_component<CurveType>::pairing_policy::Fqk_type,
                                             Fp4_variable,
                                             Fp4_mul_component,
                                             Fp4_cyclotomic_sqr_component,
                                             algebra::mnt4_q_limbs >
                                                 (bp,
                                                  (algebra::mnt4_final_exponent_last_chunk_is_w0_neg ? *el_inv_q_2_minus_1 :
                                                                                                       *el_q_2_minus_1),
                                                  algebra::mnt4_final_exponent_last_chunk_abs_of_w0,
                                                  *w0));
                            compute_result.reset(new Fqk_mul_component<CurveType>(bp, *w1, *w0, *result));
                        }

                        void generate_r1cs_constraints() {
                            one->generate_r1cs_equals_const_constraints(
                                other_curve<CurveType>::pairing_policy::Fqk_type::value_type::one());

                            compute_el_inv->generate_r1cs_constraints();
                            compute_el_q_2_minus_1->generate_r1cs_constraints();
                            compute_el_inv_q_2_minus_1->generate_r1cs_constraints();
                            compute_w1->generate_r1cs_constraints();
                            compute_w0->generate_r1cs_constraints();
                            compute_result->generate_r1cs_constraints();

                            generate_boolean_r1cs_constraint<field_type>(this->bp, result_is_one);
                            this->bp.add_r1cs_constraint(r1cs_constraint<field_type>(result_is_one, 1 - result->c0.c0, 0));
                            this->bp.add_r1cs_constraint(r1cs_constraint<field_type>(result_is_one, result->c0.c1, 0));
                            this->bp.add_r1cs_constraint(r1cs_constraint<field_type>(result_is_one, result->c1.c0, 0));
                            this->bp.add_r1cs_constraint(r1cs_constraint<field_type>(result_is_one, result->c1.c1, 0));
                        }

                        void generate_r1cs_witness() {
                            one->generate_r1cs_witness(other_curve<CurveType>::pairing_policy::Fqk_type::value_type::one());
                            el_inv->generate_r1cs_witness(el.get_element().inversed());

                            compute_el_inv->generate_r1cs_witness();
                            el_q_2->evaluate();
                            compute_el_q_2_minus_1->generate_r1cs_witness();
                            el_q_3_minus_q->evaluate();
                            el_inv_q_2->evaluate();
                            compute_el_inv_q_2_minus_1->generate_r1cs_witness();
                            compute_w1->generate_r1cs_witness();
                            compute_w0->generate_r1cs_witness();
                            compute_result->generate_r1cs_witness();

                            this->bp.val(result_is_one) =
                                (result->get_element() == one->get_element() ? field_type::value_type::one() :
                                                                               field_type::value_type::zero());
                        }
                    };

                }    // namespace components
            }    // namespace snark
        }        // namespace zk
    }            // namespace crypto3
}    // namespace nil

#endif    // CRYPTO3_ZK_WEIERSTRASS_FINAL_EXPONENTIATION_HPP