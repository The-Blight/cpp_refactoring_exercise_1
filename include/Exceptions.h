#pragma once
#include <stdexcept>
#include <string>

namespace errors {
class BaseError : public std::runtime_error {
public:
  explicit BaseError(const std::string& message)
    : std::runtime_error(message) {
  }

  ~BaseError() noexcept override = default;
};


class DateError : public BaseError {
public:
  enum class ErrorType { MONTH_ERROR = -1, DAY_ERROR = 1 };

  explicit DateError(const std::string& message, ErrorType error_type)
    : BaseError(message),
      error_type_(error_type) {
  }

  [[nodiscard]] int getErrorType() const {
    return static_cast<int>(error_type_);
  }


  ~DateError() noexcept override = default;

private:
  ErrorType error_type_;
};
}