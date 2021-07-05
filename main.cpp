/*#include <AlgorithmTest.h>
#include <BindTest.h>
#include <testJsoncpp.h>
#include <testFileStream.h>
#include <testJsonFile.h>
#include <Logger.h>
#include <stringTest.h>
#include <varParam.h>
#include <overrideTest.h>
#include <regexTest.h>
#include <decltypeTest.h>
#include <lambdasTest.h>
#include <unoderedMapTest.h>
#include <test1.h>*/
#include <threadTest.h>
#include <iostream>
#include <Logger.hpp>

using namespace std;


int main() {
  /**
   * test algorithm
   */
  /*testAlgorithmAll();
  testBind();*/


  /**
   * test jsonCpp
   */
  /*string jsonStr = getJsonStr();
  cout<<jsonStr<<endl;
  bool flag = analyzeJson(getJsonStr());
  cout << flag << endl;*/


  /**
   * test fileIO
   */
  /*testFileWrite();
  testFileRead();
  productJsonFile();
  getJsonFile();*/

  /**
   * test stringStream
   */
  /*testString();
  testStringStream();
  test0();*/

  /*cout<<__cplusplus<<endl;*/

  /**
   * test cpp11
   */
  /*testVarParam();*/
  /*Foo foo;
  Base& base = foo;
  base.test(1.0);*/

  /*Logger log("../log", Logger::log_target::file);
  log.Debug("hello world");*/

  /**
   * test regex
   */
  //test1();

  /**
   * test decltype
   */
  //test2();

  /**
   * test lambda
   */
  /*test3();
  test4();
  test5();*/


  /**
   * test unodered_map
   */
//  test6();


  /**
   * test thread
   */
   test7();




  return 0;
}

