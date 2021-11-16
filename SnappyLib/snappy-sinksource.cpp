//
//  snappy-sinksource.cpp
//  Snappy
//
//  Created by xlk on 2021/10/20.
//

#include "snappy-sinksource.hpp"
#include <string.h>

namespace snappy {

Source::~Source() { }

Sink::~Sink() { }

char* Sink::GetAppendBuffer(size_t length, char* scratch) {
  return scratch;
}

char* Sink::GetAppendBufferVariable(
      size_t min_size, size_t desired_size_hint, char* scratch,
      size_t scratch_size, size_t* allocated_size) {
  *allocated_size = scratch_size;
  return scratch;
}

void Sink::AppendAndTakeOwnership(
    char* bytes, size_t n,
    void (*deleter)(void*, const char*, size_t),
    void *deleter_arg) {
  Append(bytes, n);
  (*deleter)(deleter_arg, bytes, n);
}

ByteArraySource::~ByteArraySource() { }

size_t ByteArraySource::Available() const { return left_; }

const char* ByteArraySource::Peek(size_t* len) {
  *len = left_;
  return ptr_;
}

void ByteArraySource::Skip(size_t n) {
  left_ -= n;
  ptr_ += n;
}

UncheckedByteArraySink::~UncheckedByteArraySink() { }

void UncheckedByteArraySink::Append(const char* data, size_t n) {
  // Do no copying if the caller filled in the result of GetAppendBuffer()
  if (data != dest_) {
    memcpy(dest_, data, n);
  }
  dest_ += n;
}

char* UncheckedByteArraySink::GetAppendBuffer(size_t len, char* scratch) {
  return dest_;
}

void UncheckedByteArraySink::AppendAndTakeOwnership(
    char* data, size_t n,
    void (*deleter)(void*, const char*, size_t),
    void *deleter_arg) {
  if (data != dest_) {
    memcpy(dest_, data, n);
    (*deleter)(deleter_arg, data, n);
  }
  dest_ += n;
}

char* UncheckedByteArraySink::GetAppendBufferVariable(
      size_t min_size, size_t desired_size_hint, char* scratch,
      size_t scratch_size, size_t* allocated_size) {
  *allocated_size = desired_size_hint;
  return dest_;
}

}  // namespace snappy
