//
// Created by Acer on 2021/06/29.
//

#ifndef STUDYPRO_UNODEREDMAPTEST_H
#define STUDYPRO_UNODEREDMAPTEST_H

#include <unordered_map>
#include <string>
#include <iostream>
#include <boost/functional/hash.hpp>

class Student {
private:
  std::string m_name;
  int m_age;
  std::string m_gender;

public:
  Student(std::string name, int age, std::string gender) : m_name(std::move(name)), m_age(age),
                                                           m_gender(std::move(gender)) {}

  ~Student() = default;

  inline std::string getName() const {
    return m_name;
  }

  inline int getAge() const {
    return m_age;
  }

  inline std::string getGender() const {
    return m_gender;
  }
};

std::ostream &operator<<(std::ostream &os, const Student &stu) {
  return os << stu.getName() << " - " << stu.getAge() << " - " << stu.getGender();
}

class StudentHash {
public:
  std::size_t operator()(const Student &stu) const{
    /*return std::hash<std::string>()(stu.getName()) + std::hash<int>()(stu.getAge()) +
           std::hash<std::string>()(stu.getGender());*/
    std::size_t seed = 0;
    hash_val(seed, stu.getName(), stu.getAge(), stu.getGender());
    return seed;
  }

  template<class T>
  inline void hash_val(std::size_t &seed, const T &val) const{
    boost::hash_combine(seed, val);
  }

  template<class T, class... Type>
  inline void hash_val(std::size_t &seed, const T &val, const Type &... args) const{
    boost::hash_combine(seed, val);
    hash_val(seed, args...);
  }
};

class StudentEqual {
public:
  bool operator()(const Student &stu1, const Student &stu2) const {
    return stu1.getAge() == stu2.getAge();
  }
};


void test6() {
  std::unordered_map<Student, std::string, StudentHash, StudentEqual> stuHash;
  stuHash.insert(std::make_pair(Student("zhangsan", 21, "male"), "aaa"));
  stuHash.insert(std::make_pair(Student("lisi", 23, "famale"), "bbb"));
  stuHash.insert(std::make_pair(Student("wangwu", 27, "male"), "ccc"));


  for (const auto &x : stuHash) {
    std::cout << x.first << " -> " << x.second << std::endl;
  }

  std::cout << StudentHash()(Student("zhangsan", 21, "male")) << std::endl;
  std::cout << StudentHash()(Student("lisi", 23, "famale")) << std::endl;
  std::cout << StudentHash()(Student("wangwu", 27, "male")) << std::endl;
}


#endif //STUDYPRO_UNODEREDMAPTEST_H
