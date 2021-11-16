//
//  snappy-stubs-internal.cpp
//  Snappy
//
//  Created by xlk on 2021/10/20.
//

#include "snappy-stubs-internal.hpp"
#include <algorithm>
#include <string>

namespace snappy {

void Varint::Append32(string *s, uint32_t value) {
  char buf[Varint::kMax32];
  const char* p = Varint::Encode32(buf, value);
  s->append(buf, p - buf);
}

}
