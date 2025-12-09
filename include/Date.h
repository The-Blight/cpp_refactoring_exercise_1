#pragma once
#include "Exceptions.h"


class Date {
public:
  enum class Month {
    JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
    AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
  };

  enum class DAYS {
    BEGIN_DAY = 1, END_DAY_28 = 28, END_DAY_30 = 30, END_DAY_31 = 31
  };

  explicit Date(unsigned int day, unsigned int month, unsigned int year)
    : day_(day),
      month_(month),
      year_(year) {
  }

private:
  unsigned int day_;
  unsigned int month_;
  unsigned int year_;


   void checkDay(int day, int month_end_day) const {
    if (day > month_end_day || day < static_cast<int>(DAYS::BEGIN_DAY)) {
      throw errors::DateError
          ("The day was entered incorrectly",
           errors::DateError::ErrorType::DAY_ERROR);
    }
  }

  void validate(int day, int month, int year) {
    if () {
    }
  }
};