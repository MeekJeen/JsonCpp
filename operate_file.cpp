#include "operate_file.h"

struct Person pinfo;

void parseFile(string &path, Value &root, struct Person info){
  ifstream ifs;
  Reader reader;
  ifs.open(path, ios::in | ios::binary);
  if(reader.parse(ifs, root,false) != true){
    cout <<"line: " << __LINE__ <<  " parse error..." << " root.size = " << root.size() << endl;
    ifs.close();
  }
  if(ifs.is_open())
    ifs.close();
}

void writeJson(string &path, struct Person info)
{
  ofstream fout;
  Value root;
  Reader reader;
  ifstream ifs;
  int fea_len = sizeof(pinfo.ID) / sizeof(pinfo.ID[0]);

  parseFile(path, root, info);
  Value array = root["array"];

  Value item;
  item["name"] = info.name;

  for(int i = 0; i < fea_len; i++){
    item["ID"].append(info.ID[i]);
  }
  array.append(item);
  root["array"] = array;

  fout.open(path, ios::binary);
  fout.write(root.toStyledString().c_str(), root.toStyledString().size());
  fout.close();
}

void readJson(string &path, Value &root)
{
  Reader reader;
  ifstream ifs(path, ios::in | ios::binary);
  if(ifs && ifs.is_open()){
    cout << "The file is exist..." << endl;
    if(reader.parse(ifs, root,false) != true){
      cout << "Can't parse root data..." << endl;
    }
    ifs.close();
  }else{
    ifs.close();
    cout << "The file is not exist..." << endl;
  }
}

