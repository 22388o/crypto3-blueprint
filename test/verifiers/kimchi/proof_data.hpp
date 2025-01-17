//---------------------------------------------------------------------------//
// Copyright (c) 2021-2022 Mikhail Komarov <nemo@nil.foundation>
// Copyright (c) 2021-2022 Nikita Kaskov <nbering@nil.foundation>
// Copyright (c) 2022 Ilia Shirobokov <i.shirobokov@nil.foundation>
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

#ifndef CRYPTO3_ZK_BLUEPRINT_PLONK_PICKLES_VERIFIER_PROOF_TEST_DATA_HPP
#define CRYPTO3_ZK_BLUEPRINT_PLONK_PICKLES_VERIFIER_PROOF_TEST_DATA_HPP

#include <nil/crypto3/algebra/curves/vesta.hpp>
#include <nil/crypto3/algebra/fields/arithmetic_params/vesta.hpp>
#include <nil/crypto3/algebra/random_element.hpp>

#include <nil/crypto3/hash/algorithm/hash.hpp>
#include <nil/crypto3/hash/sha2.hpp>
#include <nil/crypto3/hash/keccak.hpp>

#include <nil/crypto3/zk/snark/arithmetization/plonk/params.hpp>
#include <nil/crypto3/zk/snark/systems/plonk/pickles/proof.hpp>

#include <nil/crypto3/zk/blueprint/plonk.hpp>
#include <nil/crypto3/zk/assignment/plonk.hpp>
#include <nil/crypto3/zk/components/systems/snark/plonk/kimchi/verifier_base_field.hpp>

using namespace nil::crypto3;

nil::crypto3::zk::snark::pickles_proof<algebra::curves::vesta> test_proof() {

  using curve_type = algebra::curves::vesta;
  nil::crypto3::zk::snark::pickles_proof<curve_type> proof;

  std::vector<std::vector<nil::crypto3::algebra::curves::vesta::g1_type<>::value_type>> w_comm_unshifted = {
  {{0x29C11510848CF79EA9D58C2E7B2F9EABDE5470AB0C7D8051DB68B6A597844291_cppui256,
    0x29A084D99207EE0ADE9471C2101682E8DB5E470231B1FEB7CDEC1A515447E762_cppui256, 0x1}},
  {{0x2347E650C19A43EA430EB8EF103F42A98B8BBAB41693BA604E762015C90F6B15_cppui256,
    0x2D5E94480F83FBE47282CBD39A46022B90842A442FBA79002AE6811BAE48ADD7_cppui256, 0x1}},
  {{0x3A38CC8840CBC1C0E9CB2BE5AEA65569391B35932C4F632208FFB76683FD559D_cppui256,
    0x0F6124FC989DFAAACD41531AB7A75E9F68150C1EC659338FF4E2340DC46591DA_cppui256, 0x1}},
  {{0x1E86CC275E88EE0EE3384B5D6641A9A6D4E3CF08DCE181D7FF9E2934B6406086_cppui256,
    0x06CF0E315DC60DF5551A872E6C6531706506DB19A6425E1A4803BBDD1074A0C4_cppui256, 0x1}},
  {{0x0F695898DA469CF121E1E704B4B717AA6BC12EFCEF4F1418B42FE7A5437082B6_cppui256,
    0x3BA7967BE5E834EAD6C4B2D8B7FC9533B1B830DDDCA7305B4EF1F7D1CE6F0EE8_cppui256, 0x1}},
  {{0x1F15E1FAA6E5A22F3B2DA293E52386FE81792BC7D956F797BEDFB11CD3A1A3D4_cppui256,
    0x184919D8F8AE9E1A81CDF386C65454296917E5A26B5FB0040137AF77D4D6AE14_cppui256, 0x1}},
  {{0x29844A1A0AA89F411287AD425C3B4B84E1A78F04F888056E4C986242E0289EBB_cppui256,
    0x08A4673C07F4E5F5EEAF76708589B110EAF49B76FB37EDAC5BDE5C29433B9188_cppui256, 0x1}},
  {{0x364ECE69E21835EAE10B1AA9CCBD74305E29C369ED250C0EE49CCD8F24795D03_cppui256,
    0x1C5A4242982EB6E6D1BA1D5E118C46D758DC2AB6AC3E1ECBFD136B1BF5C7270E_cppui256, 0x1}},
  {{0x38934EBFC2667F0925DDBF006FBC361FE152FD2CDA59D8E2D9F3CBEDD9F6DC42_cppui256,
    0x0583B9CA4362B661B2A4E78D811690B752564B5B60BB4C7F710D16BD098E5481_cppui256, 0x1}},
  {{0x3232CC46F6A60E0217926D058728DE33D8331CF44E9D589E8AAFFFEBB2FACDED_cppui256,
    0x1DA9F1A0E3F493F5D873469CCD4A860A8564A3776EFC4C00E80916B5A6663CD7_cppui256, 0x1}},
  {{0x2F96277B56B8779865BB9CB646D9F2F45EAFFDD32F146B957354922B76944F61_cppui256,
    0x2F49E80702D36688FF505B4E2CD848D461EEDCD7B6DE610A72392E05AE889010_cppui256, 0x1}},
  {{0x09F20586641CC98E68CF252A59480CE50A8C6C6AECE986A676221CD1E8613BC3_cppui256,
    0x2DCC43E7FE9F1CBE4C2FAF0969D7A788C3636FF65466A2A8E8CAD429CB47BA28_cppui256, 0x1}},
  {{0x25147529907262C1F67F1C8C62B3136C9FF495727F59A5E534A3E257E9A06DE3_cppui256,
    0x30B8453232FF14019691D8A749BD88D0E2FD1D39FE9A66A01165E71EDBA46411_cppui256, 0x1}},
  {{0x35B38418B473A631CC399723113765268A1F953D8ED9D41D5DD615026E636421_cppui256,
    0x2BEEDE237F3D3ED3942323AA402318C8866BE8DFA31FE9506580846C284DB4D2_cppui256, 0x1}},
  {{0x3FFD762B06C4DFB4FD8FED560C84F9E9DE699620B6FB4D0ED3089042FE8127E9_cppui256,
    0x2A7B651BE02C61AF87651107F8F43BE53DD2541CDDBD17BA7B316C939109598E_cppui256, 0x1}}};

  std::vector<nil::crypto3::algebra::curves::vesta::g1_type<>::value_type> w_comm_shifted = {
      {0x0, 0x0, 0x1}, {0x0, 0x0, 0x1}, {0x0, 0x0, 0x1}, {0x0, 0x0, 0x1}, {0x0, 0x0, 0x1},
      {0x0, 0x0, 0x1}, {0x0, 0x0, 0x1}, {0x0, 0x0, 0x1}, {0x0, 0x0, 0x1}, {0x0, 0x0, 0x1},
      {0x0, 0x0, 0x1}, {0x0, 0x0, 0x1}, {0x0, 0x0, 0x1}, {0x0, 0x0, 0x1}, {0x0, 0x0, 0x1},
  };

  // w_comm
  for (size_t i = 0; i < w_comm_unshifted.size(); ++i) {
      proof.commitments.w_comm[i].unshifted.assign(w_comm_unshifted[i].begin(), w_comm_unshifted[i].end());
      proof.commitments.w_comm[0].shifted = w_comm_shifted[i];
  }
  // z_comm
  proof.commitments.z_comm.unshifted.emplace_back(
      0x0208422D68D15EBB4DAE8A791B23D93DFB93AC143C7463C0ABB9926E29C5EE9C_cppui256,
      0x1A3706AAC63B05B15DB008736ABABA3A4F91DE35E48CA744AEA5E91C1E2288AA_cppui256, 0x1);
  proof.commitments.z_comm.shifted = {0x0, 0x0, 0x1};

  // t_comm
  proof.commitments.t_comm.unshifted.emplace_back(
      0x38BF25A7BB7EAEBFB14C570BF554072C2066143E57DAF281D69CE7240B510785_cppui256,
      0x0847BFCDDC69B2EDDA8B03574FF0191B0316202347E19796C313B7E1C20C4363_cppui256, 0x1);
  proof.commitments.t_comm.unshifted.emplace_back(
      0x2387EEC5D9F7CEE30CD2B0F2E3F73193B4124F6ACC3D1A19D6FED7B9AAA26563_cppui256,
      0x1EE1F50EF640E86771E56D128A868DC02A5DBF285BA413E7C0FA476CBDC18AEB_cppui256, 0x1);
  proof.commitments.t_comm.unshifted.emplace_back(
      0x050A5A157A04D8BE29892D3ABD96FFA1265D6CC6DBEF289F25B30CE51279F5C4_cppui256,
      0x1873C5460334C7A6F8A9C6355BF9A560553A3B373A2887E06C1E4F52F3D76089_cppui256, 0x1);
  proof.commitments.t_comm.unshifted.emplace_back(
      0x2DA2C4E34A74D6CA7A008F3179CAD50DED36A6DC811ACB3CAABCF68BD73FBB64_cppui256,
      0x0D9F8F90FB6AF2A482FD45D9881959F4AD070FC8E41AD684FA558FA55FA9F9A1_cppui256, 0x1);
  proof.commitments.t_comm.unshifted.emplace_back(
      0x0ACA51C54419CC979C802B466126FF526A17C5DA9463DD0BC76F48903DD7716F_cppui256,
      0x3D0BFEA83E10FAC856AEEA3B04D9F70D25C15F91CE58F9AD6677CAA5BC572CC7_cppui256, 0x1);
  proof.commitments.t_comm.unshifted.emplace_back(
      0x32EB3EB9641965E96ADFD72E5D4376DE1B62F604ADEC733ADA3EC5E1BD23A6EB_cppui256,
      0x2C5664C919361E47BC5A8327950045489D0C8552B45510FC04EB7A1AA90505A2_cppui256, 0x1);
  proof.commitments.t_comm.unshifted.emplace_back(
      0x3932E79F8E1725C875E4766F71BCA1EF8A0D70709EC997CEDBAF31E205966F2C_cppui256,
      0x3C0A7DC230E8E2B2DD47211540CA4CB77536566548E55A7C9B49244E23CF1900_cppui256, 0x1);
  proof.commitments.t_comm.shifted = {0x0, 0x0, 0x1};
  //
  // proof
  // lr
  proof.proof.lr.push_back({{0x0FD7D4257B544F7C5F43DEC6DEBD5CA8D075787F00271414948D53B0B62FCD16_cppui256,
                              0x232F23AECE45995840357A96FF6F8B0DA1B5F104DC68423D851D91E397140A11_cppui256, 0x1},
                            {0x13D5900730BA64BF3D7F01C2CB5216AEE18ADC465739E99C4CA250A4F5C151A0_cppui256,
                              0x1F85E3CFEA859928DED3E452AD5B6DC6C82962AEE319789E4BD3DD8433226F96_cppui256, 0x1}});
  proof.proof.lr.push_back({{0x0CBF8FC044499ED163BB848EF4D5A221E480437F74641EB8C336D8E80804FC1E_cppui256,
                              0x1B993999EBB897518E05D15968355C903FDC7B4F7B31E75B141C8382331462AB_cppui256, 0x1},
                            {0x1C98454CF118690E92591D466AE1E831BE802F2A15AE9E312FA66CE6A7D7C881_cppui256,
                              0x2BA05C71334D1ECA8CD03A9D625A0D266A4FD7FF83821F2BB2ACB7E9BE07F741_cppui256, 0x1}});
  proof.proof.lr.push_back({{0x3B6F4107FF516B58601B7565625C9DF90F6A18C7D7B01EDEBA39A8E0B81BDB24_cppui256,
                              0x2E9F1C998E26D4C3144595CD3CC2BCFA26599F2EA6D8B479BB47C85CF2646F80_cppui256, 0x1},
                            {0x1E262782BBABE4624EAD784EDF3D9EC6339FC21037FB3A04938DC84BB5AD0353_cppui256,
                              0x223645C7225F920F646CC168E440EC1BE8A3D3BC1218C10A3B631873A4354E9F_cppui256, 0x1}});
  proof.proof.lr.push_back({{0x3C440D20F4566BAF87213FE86998484496F84833A834548AF0A6E4AC82AA6232_cppui256,
                              0x1E43B23D50E6E8B985BC06DD7509928727B1988228F6F1D892B73C07E0BC2B00_cppui256, 0x1},
                            {0x1F0D55EA5526B5EF4F3C7DD207928236462EA45B70272882295E045EDB317220_cppui256,
                              0x1FAA58A0B3363A7C3701F1BD08FF173BC4610DAE80CEA3604DD3585D67B61152_cppui256, 0x1}});
  proof.proof.lr.push_back({{0x10065955B7F214914E735E5BEF85730C7D59F6ECD6B174B896BCF3947EE0FC5D_cppui256,
                              0x085932CEFA790133ABBA7ABBAF1CCCB578AA2FE48B6E283C26766B2887485B5E_cppui256, 0x1},
                            {0x1A3CBDC7BC523210BF7F0DF87FF0620DF262056C5256297E5A512058BC73762F_cppui256,
                              0x0AE1581243C5974613218668AB43AD0E397BFBF8AEA90D0B3ED70E12EC004C9D_cppui256, 0x1}});
  proof.proof.lr.push_back({{0x2710EAB6C40BDCB97F436494248A75F472DB617328FC2EE84C1F3EF9DCBD3BFF_cppui256,
                              0x38D7AB437DEE337F2D66F00A406AF75782F95E8E74C783CAE2DEF94E19D16EB6_cppui256, 0x1},
                            {0x1AC4B9F9CB2C53139485BFD4F57B9A64E19F63C688BB665E6037B0C98F0270B5_cppui256,
                              0x32315C63F461374A7B8ECA540A11A0CF30343F55545F17B7FD82C66DFA81C39C_cppui256, 0x1}});
  proof.proof.lr.push_back({{0x303836C38F745463E56F8047E984FCAE16AD25BFF13C2287E1C2E0D05E1C2EE7_cppui256,
                              0x2D3E3F3F6E8BCF6BDBFFD548800C6AB0DC89338563E7FF6E36AD2CBADB922966_cppui256, 0x1},
                            {0x0243D538765D68B37F752A2CB56A85CAA781306602058AEA2BC0E4AF03FECDBD_cppui256,
                              0x190734088DC7F59473F453B08954D296DB532C4E2A1B62F0C59015D88CE69C9F_cppui256, 0x1}});
  proof.proof.lr.push_back({{0x1EEFAF71B70C0BC39F37B70ABEC7E7BE4328B7D9F98C1488F8C85F5073CD5E9D_cppui256,
                              0x182BFFE23FB4AD0C0F80BB129F87DDE0D26B822E2E4BFEDE7906D7FDE1D0E57A_cppui256, 0x1},
                            {0x08CFA49FB087FC96627C1893C062DB06A9D8B4E5D628B26C349CCBE899B4FCA5_cppui256,
                              0x195D98E7527E30C5E2490196ECC11A22A14D80337D056CFA16C1E3B8AF29904D_cppui256, 0x1}});
  proof.proof.lr.push_back({{0x0531094297992B258C51092A991390F1BC63D6079D3AEB315614DD5C9826E47D_cppui256,
                              0x2C37CF446FB6539F8399357695E1D0C1B18AD72450A606773085A283182D5A5F_cppui256, 0x1},
                            {0x1B8AB439CDCABF1D690F61782FE5E16352BC72FFA16AEE61760264725A9993FF_cppui256,
                              0x1F2C0382E06A42AB35ADC93AE4BE4C4612E411626E5A3888B9B885C2DA0A5D0C_cppui256, 0x1}});

  proof.proof.delta = {0x33529C3F6390EB405641B8C12031B64948A6CE7B3B42E7B1168A6E7333D02352_cppui256,
                        0x1F7D511DE191BE5F67984802C6EBA85E5CD04CDC2C766A8B76F8F07F69A900BE_cppui256, 0x1};
  proof.proof.z1 = 0x3CD53D56E5BA440ABA3A534790D47BEDD633E272D3D66E30B66E4AD8ABE01409_cppui256;
  proof.proof.z2 = 0x272E221C5F8DAA39D027AA027DD221C25B0492E8E873F351328B3665138A2F7F_cppui256;
  proof.proof.sg = {0x03ECC373C543EBC3AFBABBEF616E72A2992866D77307246ABD51DCFCAC2B92CE_cppui256,
                    0x069DD6CE0DDF9FA50137922EC11D1E0724AABA5BAB5F6732A37555FF86FC7B50_cppui256, 0x1};

  proof.evals[0].w[0] = 0x3375BD8BF491164C3EDB9F74C2B92395F55E0D629FD93F9C905E8B58BCCBE39A_cppui256;
  proof.evals[0].w[1] = 0x2BD1D3B3C432B9CBDD09E5A0172AA2AE24142AF767BC535CCA2A27EBE0426E0B_cppui256;
  proof.evals[0].w[2] = 0x15AC5253AD0BCC5CCC4BB7A7E8377DB80BF3985E9CF2402758A81A30B9CB541A_cppui256;
  proof.evals[0].w[3] = 0x04AE3A51AEC255989C561457BCE8463E411320DEF64C1B0C44538F07F95765A6_cppui256;
  proof.evals[0].w[4] = 0x0BD0DD424D799B2EBAA51FB4CDEB01918FA9500DAA956A185006FC573B202F04_cppui256;
  proof.evals[0].w[5] = 0x129A8A8695E1754002A044F6075C02015ADC959D2A4AE9D532289603119D17DA_cppui256;
  proof.evals[0].w[6] = 0x2BF8320D10669353F296A8A85874860D44D94F96489EEC6579A04FB7AD9D6D15_cppui256;
  proof.evals[0].w[7] = 0x124A08D137BFE974AD73E237CAA22380A7B33628360B8F4B57877B4AADA52A9B_cppui256;
  proof.evals[0].w[8] = 0x1CB0D03FFCECAB9D2F81E21D059EF259102B217A68AC005C9076925651E05406_cppui256;
  proof.evals[0].w[9] = 0x0C881E6295E1E2E62C1A82B7AFC779E78D2E43D539CDE83DDB02816E3D2ADF3C_cppui256;
  proof.evals[0].w[10] = 0x31F1380BACBA2EF03E272D3E2967207747A52659840465DD8276B387012760E2_cppui256;
  proof.evals[0].w[11] = 0x336DB80B6D3D700A1121AA7FCA04D47D676ECD3609D14B85B817BDE7B09DF27F_cppui256;
  proof.evals[0].w[12] = 0x286305CD450E4EB8C60B72B6AF22478C0603E7D950C5C3AA0736900BEC066D66_cppui256;
  proof.evals[0].w[13] = 0x122B3903D51228D827A81BB89D73E3AA136A184A35FF90818489087AA9CA18F7_cppui256;
  proof.evals[0].w[14] = 0x3A12FABFE97E6F4B54C66AA63020D296E6F43996C424B3C0893EE9DE9627D3C8_cppui256;
  proof.evals[0].z = 0x01C2A7D4001B6A1701F2AA2B14C5BF907DF393AD3D8F060DBAE7EEC522A9DBC9_cppui256;
  proof.evals[0].s[0] = 0x2469EE646AF7675016F4482081F0D3EE02FCE6BD31AE72BD479CA5F986FEA20A_cppui256;
  proof.evals[0].s[1] = 0x35B16444BC168780C67399ADA9813DDF7216AB7E927AA3BF7B71F9FF7DFC4BCF_cppui256;
  proof.evals[0].s[2] = 0x3BC85E0DAD2E9B5B8908D280F82E1C269FDEA22A415F7AE7BA5A93A090524BCC_cppui256;
  proof.evals[0].s[3] = 0x27039ABC0CDAA83905AAEFE71E26EE10FF971324AA7523AE35BF75E1979F0126_cppui256;
  proof.evals[0].s[4] = 0x1FA7277A70731CBA8D28C45F00B6A47C7F89BD4EB1FE5AE509F2A44CB74D76B4_cppui256;
  proof.evals[0].s[5] = 0x290E1A5B249C50CDB3DD98415F1AB4EE8C610A4F6B03F3EA5D87E2FD4D3B0BB9_cppui256;

  proof.evals[1].w[0] = 0x14C0EF696971778663B575B2D89B0F4E8967CCE67E95C0C3376C606E18FECB2D_cppui256;
  proof.evals[1].w[1] = 0x0A2BA37B20948C9DE8B3F565EB6FB212296B2493B16B4E7236909E1D8D41E053_cppui256;
  proof.evals[1].w[2] = 0x2812ADB1DEA9B5B093AD88F080BBDCB40B210F7685C571A20F8EC625220FC931_cppui256;
  proof.evals[1].w[3] = 0x3FD84E9DA07AE934596DE0508D9E05CD170AA7767ECC489D4C8FB9F706DF4A4B_cppui256;
  proof.evals[1].w[4] = 0x2B3BECF9AAD01BE20D3E26D0A64C0C0D16CB8167E0E63DB8BE918B46CC32F605_cppui256;
  proof.evals[1].w[5] = 0x18A9B1F0794F2694A4B1E5664A8ECD8E06497D0CFB27BD6B9267D5A29764087B_cppui256;
  proof.evals[1].w[6] = 0x3104BD2759DBC3FF0BFFA3F1C20FED7D231988B29A9246F59868CE01B4F5992B_cppui256;
  proof.evals[1].w[7] = 0x1C3CAFA7CBBAC188094016B942092D0B3B72AB519064BFD36CED6C905B480391_cppui256;
  proof.evals[1].w[8] = 0x0D17F4FE8B1B2FAA783FC8357B4DF7B7A6C53FC12511C0E16838776875D49446_cppui256;
  proof.evals[1].w[9] = 0x2E0C3419383B9D61EF841A78D1606D876B3F88AA8E29E489C8C34F3A07AB2E98_cppui256;
  proof.evals[1].w[10] = 0x083AAF8C9AB47A3F89F1CF2A8EDF671F73832182E99C0BCAFB1450AF472CA880_cppui256;
  proof.evals[1].w[11] = 0x3FE4A9C99461154DA13BA3433A01E529B14795EC08B8A36F30EE9BD439F2937D_cppui256;
  proof.evals[1].w[12] = 0x22958B98F859D135929C88E6258400B5B392AF65D1D6B38C0C36D8D22CF2B7A7_cppui256;
  proof.evals[1].w[13] = 0x37EACF6E463248F21442AD54066298F5C3F4247E8E14E7FD6F6D7F58DA4EECC8_cppui256;
  proof.evals[1].w[14] = 0x091108301FB7BEB05DF4D8699F6491D1D9FE26E58C16760F980B583F497E49E2_cppui256;
  proof.evals[1].z = 0x0913AD25F3BFC7E0505F59EE1123ACC6200ED374E3AA388E1E9674554131283F_cppui256;
  proof.evals[1].s[0] = 0x3319BDF89C3E104CACB2BDB7D1355994837001BCF5363930337D9CA9909C813A_cppui256;
  proof.evals[1].s[1] = 0x19E60BCD31F3A0866FE4D49B30530DF3F900DB00DD6EF65A62E5A8E9F271EE20_cppui256;
  proof.evals[1].s[2] = 0x3BC0548D33BD4DE9C00F269A87AAE4956C061D41B21D56072EA24B9BD8B29A2D_cppui256;
  proof.evals[1].s[3] = 0x09044E158A924A1FE7FB4403A4F05AE4A53219123A36FD36345C50250ED25A57_cppui256;
  proof.evals[1].s[4] = 0x06FAE70DEF399DE03151CC0FA946AFD1927BFF046A76809C2DE9E729FA18B9FC_cppui256;
  proof.evals[1].s[5] = 0x2B849A7D46AED37CE27A68A88F3282A80FF24DBFDDCC3B8590BA54D569837215_cppui256;

  proof.ft_eval1 = 0x14439298A43516169BA9E802FB3EA1145827D2214158298C302022C7C42A14A8_cppui256;

  return proof;
}

#endif    // CRYPTO3_ZK_BLUEPRINT_PLONK_PICKLES_VERIFIER_PROOF_TEST_DATA_HPP