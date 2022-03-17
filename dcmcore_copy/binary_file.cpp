#include "binary_file.h"
#include <iostream>
#include <typeinfo>
using namespace std;

namespace dcmcore {

BinaryFile::BinaryFile()
    : m_mode(Mode::READ)
{
}

bool BinaryFile::Open(std::string filename, Mode mode)
{
  // Close();

  m_mode = mode;

  if (mode == Mode::READ) {
    m_file.open(filename, std::ios::binary | std::ios::in);

  } else {
    m_file.open(filename.data(), std::ios::binary | std::ios::out);

  }

  return IsOk();
}

void BinaryFile::Close()
{
  m_file.close();
}

} // namespace dcmcore
