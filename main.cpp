#include <iostream>
#include "Person.h"
#include "Teacher.h"
#include "Date.h"
#include "Exceptions.h"

int main() {
  try {
    // Test 1: Valid teacher
    std::string lastname = "Ivanov";
    std::string firstname = "Ivan";
    Date* birthdate = new Date(15, 5, 1980);
    std::string faculty = "Mathematics";

    Teacher teacher(lastname, firstname, birthdate, Person::SEX::M, faculty);
    teacher.addSubject("Algebra");
    teacher.addSubject("Calculus");

    std::cout << "Teacher: " << teacher.getFullName() << std::endl;
    std::cout << "Faculty: " << teacher.getFaculty() << std::endl;

    // Test 2: Empty name
    std::string empty = "";
    Date* date2 = new Date(10, 3, 1990);
    Person person(lastname, empty, date2, Person::SEX::M);

  }
  catch (const errors::NameError& e) {
    std::cerr << "Name error: " << e.what() << std::endl;
  }
  catch (const errors::SurnameError& e) {
    std::cerr << "Surname error: " << e.what() << std::endl;
  }
  catch (const errors::MonthError& e) {
    std::cerr << "Month error: " << e.what() << std::endl;
  }
  catch (const errors::DayError& e) {
    std::cerr << "Day error: " << e.what() << std::endl;
  }
  catch (const errors::NullPointerError& e) {
    std::cerr << "Null pointer error: " << e.what() << std::endl;
  }
  catch (const errors::ProgaramError& e) {
    std::cerr << "Program error: " << e.what() << std::endl;
  }
  catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
