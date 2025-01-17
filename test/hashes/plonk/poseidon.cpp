//---------------------------------------------------------------------------//
// Copyright (c) 2021-2022 Mikhail Komarov <nemo@nil.foundation>
// Copyright (c) 2021-2022 Nikita Kaskov <nbering@nil.foundation>
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

#define BOOST_TEST_MODULE plonk_poseidon_test

#include <boost/test/unit_test.hpp>

#include <nil/crypto3/algebra/curves/pallas.hpp>
#include <nil/crypto3/algebra/fields/arithmetic_params/pallas.hpp>
#include <nil/crypto3/algebra/random_element.hpp>

#include <nil/crypto3/hash/algorithm/hash.hpp>
#include <nil/crypto3/hash/sha2.hpp>
#include <nil/crypto3/hash/keccak.hpp>

#include <nil/crypto3/zk/snark/arithmetization/plonk/params.hpp>

#include <nil/crypto3/zk/blueprint/plonk.hpp>
#include <nil/crypto3/zk/assignment/plonk.hpp>
#include <nil/crypto3/zk/components/hashes/poseidon/plonk/poseidon_15_wires.hpp>

#include "../../test_plonk_component.hpp"

using namespace nil::crypto3;

BOOST_AUTO_TEST_SUITE(blueprint_plonk_test_suite)

BOOST_AUTO_TEST_CASE(blueprint_plonk_poseidon) {

    using curve_type = algebra::curves::pallas;
    using BlueprintFieldType = typename curve_type::base_field_type;
    using FieldType = typename curve_type::base_field_type;
    constexpr std::size_t WitnessColumns = 15;
    constexpr std::size_t PublicInputColumns = 1;
    constexpr std::size_t ConstantColumns = 3;
    constexpr std::size_t SelectorColumns = 11;

    using ArithmetizationParams = zk::snark::plonk_arithmetization_params<WitnessColumns,
        PublicInputColumns, ConstantColumns, SelectorColumns>;
    using ArithmetizationType = zk::snark::plonk_constraint_system<BlueprintFieldType,
                ArithmetizationParams>;

    using component_type = zk::components::poseidon<ArithmetizationType, FieldType,
                                                            0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14>;

    typename component_type::public_params_type public_params = {};
    std::array<typename ArithmetizationType::field_type::value_type, 3> input_state = {0, 1, 1};
    typename component_type::private_params_type private_params = {input_state};
    std::array<typename ArithmetizationType::field_type::value_type, 3> output_state = {0x294B71F8CF2C775369A3B0B8912E508790B0C64BDBE6A5C26F2C6B53767A47CB_cppui255,
     0x244E5FA0EE801AB3FCCAB47ED7F6EAB38126318F7BD2C414ADDBF62FCC30316A_cppui255, 0x273C6EE50F9A2970162F5D4503596175C6D3FB4C0BF6C269BCD1DFEFB4F50D47_cppui255};
    std::cout<<"Expected result: "<<output_state[0].data<<" "<< output_state[1].data<<" " <<output_state[2].data<<std::endl;
    test_component<component_type, BlueprintFieldType, ArithmetizationParams> (public_params, private_params);
}

BOOST_AUTO_TEST_SUITE_END()