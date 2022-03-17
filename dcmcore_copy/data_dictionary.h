#pragma once

// Data dictionary singleton.

#include "data_entry.h"
#include "tag.h"

namespace dcmcore {

class DataDictionary {
  public:
  static DataDictionary& Get();

  ~DataDictionary() = default;

  const DataEntry* FindEntry(Tag tag) const;

  private:
  DataDictionary() = default;
};

} // namespace dcmcore