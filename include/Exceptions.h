#pragma once
#include <stdexcept>
#include <string>

namespace errors {
class ProgaramError : public std::runtime_error {
public:
  explicit ProgaramError(const std::string& message)
    : std::runtime_error(message) {
  }

  ~ProgaramError() noexcept override = default;
};


class DateError : public ProgaramError {
public:
  explicit DateError(const std::string& message)
    : ProgaramError(message) {
  }

  ~DateError() noexcept override = default;
};


class MonthError : public DateError {
public:
  explicit MonthError(const std::string& message)
    : DateError(message) {
  }

  ~MonthError() noexcept override = default;
};


class DayError : public DateError {
public:
  explicit DayError(const std::string& message)
    : DateError(message) {
  }

  ~DayError() noexcept override = default;
};


class PersonalDataError : public ProgaramError {
public:
  explicit PersonalDataError(const std::string& message)
    : ProgaramError(message) {
  }

  ~PersonalDataError() noexcept override = default;
};

class NameError : public PersonalDataError {
public:
  explicit NameError(const std::string& message)
    : PersonalDataError(message) {
  }

  ~NameError() noexcept override = default;
};


class SurnameError : public PersonalDataError {
public:
  explicit SurnameError(const std::string& message)
    : PersonalDataError(message) {
  }

  ~SurnameError() noexcept override = default;
};

class NullPointerError : public ProgaramError {
public:
  explicit NullPointerError(const std::string& message)
    : ProgaramError(message) {
  }

  ~NullPointerError() noexcept override = default;
};
}