#include <iostream>
#include <variant>

#include "tree.h"
#include "unittest.h"

BEGIN_TEST(CheckTreeNodes, BigInt)
{
  bigint num(1234);
  tree node(num);
  EXPECT_EQ(node.getinteger(), num)
}END_TEST

BEGIN_TEST(CheckTreeNodes, BigInt2)
{
  bigint num(1234), num2(1234);
  tree node(num);
  EXPECT_EQ(node.getinteger(), num2)
}END_TEST

BEGIN_TEST(CheckTreeNodes, Double)
{
  double d(12.0);
  tree node(d);
  EXPECT_EQ(node.getdouble(), d)
}END_TEST

BEGIN_TEST(CheckTreeNodes, String)
{
  std::string str = "Hello World";
  tree node(str);
  EXPECT_EQ(node.getstring(), str)
}END_TEST

BEGIN_TEST(CheckTreeNodes, String2)
{
  std::string str  = "Hello World";
  std::string str2 = "Hello World";
  tree node(str);
  EXPECT_EQ(node.getstring(), str2)
}END_TEST

BEGIN_TEST(TreeBuilding, Size1)
{
  std::string str  = "Hello World";
  tree node(str);
  EXPECT_EQ(node.size(), 1)

}END_TEST

BEGIN_TEST(TreeBuilding, Size2)
{
  std::string str  = "Hello World";
  std::string str2 = "Hello World";
  tree node2(str2);

  util::shared_ptr< std::vector< tree >> sub(new std::vector< tree >);
  sub -> push_back(str2);
  tree node(str, sub);
  EXPECT_EQ(node.size(), 2)

}END_TEST

BEGIN_TEST(TreeBuilding, NrSubtrees1)
{
  std::string str  = "Hello World";
  tree node(str);
  EXPECT_EQ(node.nrsubtrees(), 0)

}END_TEST

BEGIN_TEST(TreeBuilding, NrSubtrees2)
{
  std::string parstr = "Parent";
  std::string str    = "Hello World";
  bigint i(23);
  double d(12.0);

  tree node1(str);
  tree node2(i);
  tree node3(d);

  util::shared_ptr< std::vector< tree >> ptr (new std::vector< tree >);

  ptr -> push_back(node1);
  ptr -> push_back(node2);
  ptr -> push_back(node3);

  tree node(parstr, ptr);

  EXPECT_EQ(node.nrsubtrees(), 3)

}END_TEST

BEGIN_TEST(TreeBuilding, BracketsOp1)
{
  std::string parstr = "Parent";
  std::string str    = "Hello World";
  bigint i(23);
  double d(12.0);

  tree node1(str);
  tree node2(i);
  tree node3(d);

  util::shared_ptr< std::vector< tree >> ptr (new std::vector< tree >);

  ptr -> push_back(node1);
  ptr -> push_back(node2);
  ptr -> push_back(node3);

  tree node(parstr, ptr);

  bigint test_value(23);
  const tree test_node(test_value);

  EXPECT_EQ(node[1], test_node )

}END_TEST

BEGIN_TEST(TreeBuilding, BracketsOp2)
{
  std::string parstr = "Parent";
  std::string str    = "Hello World";
  bigint i(23);
  double d(12.0);

  tree node1(str);
  tree node2(i);
  tree node3(d);

  util::shared_ptr< std::vector< tree >> ptr (new std::vector< tree >);

  ptr -> push_back(node1);
  ptr -> push_back(node2);
  ptr -> push_back(node3);

  tree node(parstr, ptr);

  std::string test_value("Hello World");
  const tree test_node(test_value);

  EXPECT_EQ(node[0], test_node )

}END_TEST

BEGIN_TEST(TreeBuilding, BracketsOp3)
{
  std::string parstr = "Parent";
  std::string str    = "Hello World";
  bigint i(23);
  double d(12.0);

  tree node1(str);
  tree node2(i);
  tree node3(d);

  util::shared_ptr< std::vector< tree >> ptr (new std::vector< tree >);

  ptr -> push_back(node1);
  ptr -> push_back(node2);
  ptr -> push_back(node3);

  tree node(parstr, ptr);

  double test_value(12.0);
  const tree test_node(test_value);

  EXPECT_EQ(node[2], test_node )

}END_TEST

BEGIN_TEST(TreeBuilding, ConversionTest1)
{
  bigint i(23);
  tree node(i);

  bigint test_value(23);

  EXPECT_EQ((bigint)node, test_value )

}END_TEST

BEGIN_TEST(TreeBuilding, ConversionTest2)
{
  std::string str    = "Hello World";
  tree node(str);

  std::string test_value(str);

  EXPECT_EQ((std::string)node, test_value )

}END_TEST

BEGIN_TEST(TreeBuilding, ConversionTest3)
{
  double d(12.0);
  tree node(d);

  double test_value(12.0);

  EXPECT_EQ((double)node, test_value )

}END_TEST

void run_tests(){
  RUN_TEST(CheckTreeNodes, BigInt)
  RUN_TEST(CheckTreeNodes, BigInt2)
  RUN_TEST(CheckTreeNodes, Double)
  RUN_TEST(CheckTreeNodes, String)
  RUN_TEST(CheckTreeNodes, String2)

  RUN_TEST(TreeBuilding, Size1)
  RUN_TEST(TreeBuilding, Size2)
  RUN_TEST(TreeBuilding, NrSubtrees1)
  RUN_TEST(TreeBuilding, NrSubtrees2)

  RUN_TEST(TreeBuilding, BracketsOp1)
  RUN_TEST(TreeBuilding, BracketsOp2)
  RUN_TEST(TreeBuilding, BracketsOp3)

  RUN_TEST(TreeBuilding, ConversionTest1)
  RUN_TEST(TreeBuilding, ConversionTest2)
  RUN_TEST(TreeBuilding, ConversionTest3)
}

int main(){
  run_tests();
  return 0;
}
