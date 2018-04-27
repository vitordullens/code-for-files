/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.10
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.imebra;

public class Date {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected Date(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(Date obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        imebraJNI.delete_Date(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public Date(long initialYear, long initialMonth, long initialDay, long initialHour, long initialMinutes, long initialSeconds, long initialNanoseconds, int initialOffsetHours, int initialOffsetMinutes) {
    this(imebraJNI.new_Date(initialYear, initialMonth, initialDay, initialHour, initialMinutes, initialSeconds, initialNanoseconds, initialOffsetHours, initialOffsetMinutes), true);
  }

  public void setYear(long value) {
    imebraJNI.Date_year_set(swigCPtr, this, value);
  }

  public long getYear() {
    return imebraJNI.Date_year_get(swigCPtr, this);
  }

  public void setMonth(long value) {
    imebraJNI.Date_month_set(swigCPtr, this, value);
  }

  public long getMonth() {
    return imebraJNI.Date_month_get(swigCPtr, this);
  }

  public void setDay(long value) {
    imebraJNI.Date_day_set(swigCPtr, this, value);
  }

  public long getDay() {
    return imebraJNI.Date_day_get(swigCPtr, this);
  }

  public void setHour(long value) {
    imebraJNI.Date_hour_set(swigCPtr, this, value);
  }

  public long getHour() {
    return imebraJNI.Date_hour_get(swigCPtr, this);
  }

  public void setMinutes(long value) {
    imebraJNI.Date_minutes_set(swigCPtr, this, value);
  }

  public long getMinutes() {
    return imebraJNI.Date_minutes_get(swigCPtr, this);
  }

  public void setSeconds(long value) {
    imebraJNI.Date_seconds_set(swigCPtr, this, value);
  }

  public long getSeconds() {
    return imebraJNI.Date_seconds_get(swigCPtr, this);
  }

  public void setNanoseconds(long value) {
    imebraJNI.Date_nanoseconds_set(swigCPtr, this, value);
  }

  public long getNanoseconds() {
    return imebraJNI.Date_nanoseconds_get(swigCPtr, this);
  }

  public void setOffsetHours(int value) {
    imebraJNI.Date_offsetHours_set(swigCPtr, this, value);
  }

  public int getOffsetHours() {
    return imebraJNI.Date_offsetHours_get(swigCPtr, this);
  }

  public void setOffsetMinutes(int value) {
    imebraJNI.Date_offsetMinutes_set(swigCPtr, this, value);
  }

  public int getOffsetMinutes() {
    return imebraJNI.Date_offsetMinutes_get(swigCPtr, this);
  }

}
