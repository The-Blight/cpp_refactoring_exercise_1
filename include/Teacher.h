#pragma once

#include <string>
#include <vector>

#include "Person.h"
#include "Date.h"


class Teacher : public Person {
public:
  explicit Teacher(std::string& last_name, std::string& first_name, Date* date_of_birth,
                   const SEX sex,
                   std::string& faculty)
    : Person(last_name, first_name, date_of_birth, sex),
      subjects_(std::make_unique<std::vector<std::string> >()),
      faculty_(std::move(faculty)) {
  }

  void addSubject(const std::string& subject) {
    subjects_->push_back(subject);
  }

  [[nodiscard]] std::vector<std::string> getSubjects() const {
    return *subjects_;
  }

  [[nodiscard]] std::string getFaculty() const {
    return faculty_;
  }

  ~Teacher() = default;

private:
  std::unique_ptr<std::vector<std::string> > subjects_;
  std::string faculty_;
};