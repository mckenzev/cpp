#include <gtest/gtest.h>

#include <cmath>
#include <limits>
#include <vector>

#include "../controller/controller.h"
#include "../model/model.h"

class CalcTest : public ::testing::Test {
 protected:
  CalcTest() : controller_(s21::Controller(&model_)) {}
  void SetUp() override {}
  s21::Controller controller_;
  s21::Model model_;
};

TEST_F(CalcTest, simple_int_sum) {
  std::string str = "24+12";
  double res = controller_.GetResult(str, 0);
  EXPECT_DOUBLE_EQ(res, 36);
}

TEST_F(CalcTest, simple_int_minus) {
  std::string str = "27-12";
  double res = controller_.GetResult(str, 0);
  EXPECT_DOUBLE_EQ(res, 15);
}

TEST_F(CalcTest, simple_int_div) {
  std::string str = "27/4";
  double res = controller_.GetResult(str, 0);
  EXPECT_NEAR(res, 6.75, 1e-6);
}

TEST_F(CalcTest, simple_int_div_zero) {
  std::string str = "27/0";
  double res = controller_.GetResult(str, 0);
  EXPECT_DOUBLE_EQ(res, std::numeric_limits<double>::infinity());
}

TEST_F(CalcTest, simple_int_mod) {
  std::string str = "27%4";
  double res = controller_.GetResult(str, 0);
  EXPECT_NEAR(res, 3, 1e-6);
}

TEST_F(CalcTest, simple_int_pow) {
  std::string str = "27^4";
  double res = controller_.GetResult(str, 0);
  EXPECT_NEAR(res, 531441, 1e-6);
}

TEST_F(CalcTest, simple_int_with_x) {
  std::string str = "27/x";
  double res = controller_.GetResult(str, 4);
  EXPECT_NEAR(res, 6.75, 1e-6);
}

TEST_F(CalcTest, check_operation_priotity) {
  std::string str = "24+2^3/4";
  double res = controller_.GetResult(str, 0);
  EXPECT_NEAR(res, 26, 1e-6);
}

TEST_F(CalcTest, simple_sqrt) {
  std::string str = "r(16)";
  double res = controller_.GetResult(str, 0);
  EXPECT_NEAR(res, 4, 1e-6);
}

TEST_F(CalcTest, sqrt_with_negativ) {
  std::string str = "r(-3.2)";
  double res = controller_.GetResult(str, 0);
  EXPECT_TRUE(std::isnan(res));
}

TEST_F(CalcTest, multiplication_without_signs) {
  std::string str = "2(35(1/2))";
  double res = controller_.GetResult(str, 0);
  EXPECT_NEAR(res, 35, 1e-6);
}

TEST_F(CalcTest, ln_division) {
  std::string str = "ln(32)/ln(2)";
  double res = controller_.GetResult(str, 0);
  EXPECT_NEAR(res, 5, 1e-6);
}

TEST_F(CalcTest, log_with_zero) {
  std::string str = "log(0)";
  double res = controller_.GetResult(str, 0);
  EXPECT_TRUE(std::isinf(res));
}

TEST_F(CalcTest, log_with_negativ) {
  std::string str = "log(-2)";
  double res = controller_.GetResult(str, 0);
  EXPECT_TRUE(std::isnan(res));
}

TEST_F(CalcTest, test_trigonometric) {
  std::string str = "sin(x)^2+cos(x)^2";
  double res = controller_.GetResult(str, 2.1);
  EXPECT_NEAR(res, 1, 1e-6);
}

TEST_F(CalcTest, very_big_expression) {
  std::string str =
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1";
  double res = controller_.GetResult(str, 0);
  EXPECT_NEAR(res, 288, 1e-6);
}

TEST_F(CalcTest, test_sin) {
  std::string str = "sin(5)";
  double res = controller_.GetResult(str, 2.1);
  EXPECT_NEAR(res, -0.958924, 1e-6);
}

TEST_F(CalcTest, test_asin) {
  std::string str = "asin(0.5)";
  double res = controller_.GetResult(str, 2.1);
  EXPECT_NEAR(res, 0.523599, 1e-6);
}

TEST_F(CalcTest, test_cos) {
  std::string str = "cos(5)";
  double res = controller_.GetResult(str, 2.1);
  EXPECT_NEAR(res, 0.283662, 1e-6);
}

TEST_F(CalcTest, test_acos) {
  std::string str = "acos(0.5)";
  double res = controller_.GetResult(str, 2.1);
  EXPECT_NEAR(res, 1.047198, 1e-6);
}

TEST_F(CalcTest, test_tan) {
  std::string str = "tan(3.1)";
  double res = controller_.GetResult(str, 2.1);
  EXPECT_NEAR(res, -0.041617, 1e-6);
}

TEST_F(CalcTest, test_atan) {
  std::string str = "atan(0.5)";
  double res = controller_.GetResult(str, 2.1);
  EXPECT_NEAR(res, 0.463648, 1e-6);
}

TEST_F(CalcTest, sin_and_asin) {
  std::string str = "sin(asin(0,7))";
  double res = controller_.GetResult(str, 0);
  EXPECT_NEAR(res, 0.7, 1e-6);
}

TEST_F(CalcTest, big_expression_1) {
  std::string str = "2,5^2-9.1*ln(3)";
  double res = controller_.GetResult(str, 0);
  EXPECT_NEAR(res, -3.747371, 1e-6);
}

TEST_F(CalcTest, big_expression_2) {
  std::string str = "2.1*sin(4.5^0.6)";
  double res = controller_.GetResult(str, 0);
  EXPECT_NEAR(res, 1.313866, 1e-6);
}

TEST_F(CalcTest, big_expression_3) {
  std::string str = "sin(cos(tan(ln(3))))";
  double res = controller_.GetResult(str, 0);
  EXPECT_NEAR(res, -0.36872, 1e-6);
}

TEST_F(CalcTest, big_expression_4) {
  std::string str = "r(8)*10^0.5";
  double res = controller_.GetResult(str, 0);
  EXPECT_NEAR(res, 8.944272, 1e-6);
}

TEST_F(CalcTest, big_expression_5) {
  std::string str = "log(ln(55))";
  double res = controller_.GetResult(str, 0);
  EXPECT_NEAR(res, 0.602855, 1e-6);
}

TEST_F(CalcTest, unary_minus) {
  std::string str = "-1*(-1)*(-1)";
  double res = controller_.GetResult(str, 0);
  EXPECT_NEAR(res, -1, 1e-6);
}

TEST_F(CalcTest, negativ_x) {
  std::string str = "x*(-x)";
  double res = controller_.GetResult(str, 1.1);
  EXPECT_NEAR(res, -1.21, 1e-6);
}

TEST_F(CalcTest, minus_minus_1) {
  std::string str = "-(-2)";
  double res = controller_.GetResult(str, 1.1);
  EXPECT_NEAR(res, 2, 1e-6);
}

TEST_F(CalcTest, minus_minus_2) {
  std::string str = "-(-(-(-(-2))))";
  double res = controller_.GetResult(str, 1.1);
  EXPECT_NEAR(res, -2, 1e-6);
}

TEST_F(CalcTest, exponent_1) {
  std::string str = "2e2+2";
  double res = controller_.GetResult(str, 1);
  EXPECT_NEAR(res, 202, 1e-6);
}

TEST_F(CalcTest, exponent_2) {
  std::string str = "2e-2+2";
  double res = controller_.GetResult(str, 1);
  EXPECT_NEAR(res, 2.02, 1e-6);
}

TEST_F(CalcTest, matrix_graph) {
  std::string str = "x+x";
  s21::GraphParams params = {-3, 3, -3, 3, 6, 6, 1};
  std::vector<int> matrix = controller_.GetMatrix(str, params);
  std::vector<int> reference_matrix = {-6, -4, -2, 0, 2, 4};
  auto ref_it = reference_matrix.begin();
  for (auto it : matrix) {
    EXPECT_EQ(*ref_it, it);
    ++ref_it;
  }
}