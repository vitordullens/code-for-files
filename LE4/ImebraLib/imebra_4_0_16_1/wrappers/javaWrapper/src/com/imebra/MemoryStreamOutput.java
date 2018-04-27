/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.10
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.imebra;

public class MemoryStreamOutput extends BaseStreamOutput {
  private transient long swigCPtr;

  protected MemoryStreamOutput(long cPtr, boolean cMemoryOwn) {
    super(imebraJNI.MemoryStreamOutput_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(MemoryStreamOutput obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        imebraJNI.delete_MemoryStreamOutput(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public MemoryStreamOutput(ReadWriteMemory memory) {
    this(imebraJNI.new_MemoryStreamOutput(ReadWriteMemory.getCPtr(memory), memory), true);
  }

}
