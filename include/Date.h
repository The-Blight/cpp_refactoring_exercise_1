#pragma once
#include "Exceptions.h"


class Date {
public:
  enum class MONTH {
    JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNY, JULY, AUGUST, SEPTEMBER,
    OCTOBER, NOVEMBER, DECEMBER
  };

  enum class DAYS {
    BEGIN_DAY = 1, END_DAY_28 = 28, END_DAY_30 = 30, END_DAY_31 = 31
  };


  explicit Date(const int day, const int month, const int year)
    : day_(checkDayForRange(day, month)),
      month_(checkMonthForRange(month)),
      year_(year) {
  }

  [[nodiscard]] unsigned int getDay() const {
    return day_;
  }

  [[nodiscard]] unsigned int getMonth() const {
    return month_;
  }

  [[nodiscard]] int getYear() const {
    return year_;
  }

  ~Date() = default;

private:
  unsigned int day_;
  unsigned int month_;
  int year_;

  static void checkDay(const unsigned int day, const DAYS& end) {
    if (day > static_cast<int>(end) || day < static_cast<int>(DAYS::BEGIN_DAY)) {
      throw errors::DayError("Day wasn't set correctly");
    }
  }

  [[nodiscard]] static unsigned int checkDayForRange(const unsigned int day, const unsigned month) {
    if (month == static_cast<int>(MONTH::FEBRUARY)) {
      checkDay(day, DAYS::END_DAY_28);
    } else if (month == static_cast<int>(MONTH::APRIL) || month == static_cast<int>(MONTH::JUNY)
               || month == static_cast<int>(MONTH::SEPTEMBER) || month == static_cast<int>(
                 MONTH::NOVEMBER)) {
      checkDay(day, DAYS::END_DAY_30);
    } else {
      checkDay(day, DAYS::END_DAY_31);
    }
    return day;
  }

  [[nodiscard]] static unsigned int checkMonthForRange(const unsigned int month) {
    if (month > static_cast<int>(MONTH::DECEMBER) || month < static_cast<int>(MONTH::JANUARY)) {
      throw errors::MonthError("Month wasn't set correctly");
    }
    return month;
  }
};