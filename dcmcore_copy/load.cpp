#include "dcmcore.h"
#include "img_data.h"
#include "data_element.h"
// #include <filesystem>
#include <iostream>
// #include <typeinfo>
using namespace std;


int main(){
  dcmcore::DataSet data_set;
  dcmcore::FullReadHandler read_handler(&data_set);
  dcmcore::DicomReader reader(&read_handler);
  string filePath = "/code/dcmlite/dcmcore_copy/0001.dcm";
  reader.ReadFile(filePath);

  string transfer_syntax_uid;
  if (data_set.GetString(dcmcore::Tag(0x0002, 0x0010), transfer_syntax_uid)) {
    // std::cout << "Transfer Syntax UID: " << transfer_syntax_uid << std::endl;
  }
  
  string patient_name;
  if (data_set.GetString(dcmcore::Tag(0x0010, 0x0010), patient_name)) {
    // patient_name = "Nguyen Van A";
    cout << "Patient Name: " << patient_name << endl;
    //patNVAient_name = "nguyen van a";
    //cout << patient_name << endl;
  }


  string pixelData;
  if (data_set.GetString(dcmcore::Tag(0x7fe0,0x0010),pixelData)){
    // cout << "Pixel data: " << pixelData << endl;
  }

  // cout << *(data_set.GetElement(dcmcore::Tag(0x0010,0x0010))) << endl;;
  string newPatientName = "Nguyen Van A";
  dcmcore::DataElement ptrnewPatientName = *(data_set.GetElement(dcmcore::Tag(0x0010,0x0010)));
  // newPatientName = ptrnewPatientName;
  // cout << ptrnewPatientName << endl;
  // cout << data_set.GetString(dcmcore::Tag(0x0010, 0x0010), patient_name) << endl;
  

  
  



//write file

  dcmcore::BinaryFile file;
  if (!file.Open("/code/dcmlite/dcmcore_copy/output.dcm", dcmcore::BinaryFile::Mode::WRITE)) {
    cerr << "Failed to open output file.\n";
  }

  dcmcore::WriteVisitor visitor(&file);
  data_set.Accept(visitor);


  
return 0;
}