#pragma once
#include <string>
#include <utility>
#include  <memory>

#include "Date.h"
#include "Exceptions.h"


class Person {
public:
  enum class SEX { M, F };

  explicit Person(std::string& last_name, std::string& first_name, Date* date_of_birth,
                  const SEX sex)
    : last_name_(std::move(checkSurname(last_name))),
      first_name_(std::move(checkName(first_name))),
      date_of_birth_(date_of_birth),
      sex_(sex) {
  }

  [[nodiscard]] std::string getLastname() const {
    return last_name_;
  }

  [[nodiscard]] std::string getFirstName() const {
    return first_name_;
  }

  [[nodiscard]] Date getDateOfBirth() const {
    if (date_of_birth_ != nullptr) {
      return *date_of_birth_;
    }
    throw errors::NullPointerError("Object 'date of birth' points to null pointer");
  }

  [[nodiscard]] SEX getSex() const {
    return sex_;
  }

  [[nodiscard]] std::string getFullName() const {
    return getLastname() + " " + getFirstName();
  }

  ~Person() = default;

private:
  std::string last_name_;
  std::string first_name_;
  std::unique_ptr<Date> date_of_birth_;
  SEX sex_;

  [[nodiscard]] static std::string checkName(const std::string& name) {
    if (!name.empty()) {
      return name;
    }
    throw errors::NameError("Name is empty");
  }

  [[nodiscard]] static std::string checkSurname(const std::string& surname) {
    if (!surname.empty()) {
      return surname;
    }
    throw errors::SurnameError("Surname is empty");
  }
};