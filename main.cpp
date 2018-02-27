#include "sdk/operate_file.h"

int main()
{
  //1.序列化
  string path = "test.txt";  
  Json::Value root;  
  vector<float> vec;
  //<1>.准备数据
  for(int i = 0; i < 7; i++)
    vec.push_back(0.7);

  //<2>.将数据保存在pinfo.ID[7]结构体
  for(int i = 0; i < vec.size(); i ++)
    pinfo.ID[i] = vec[i];
  
  cout << "vec.size = " << vec.size() << endl;
  pinfo.name = "json-cpp";
  writeJson(path, pinfo);//二进制写入文件

  cout << "fea1: ";
  for(auto fea1 : vec)
    cout << fea1 << " ";
  cout << endl << endl;

#if 1
  //2.反序列化
  readJson(path, root);
  Value arrayObj = root["array"];
  cout << "array.size = " << arrayObj.size() << endl;
  cout <<"ID.size = " << arrayObj[0]["ID"].size() << endl;

  for(unsigned int i = 0; i < arrayObj.size(); i++){
    cout << "name = " << arrayObj[i]["name"].asString() << endl;

    cout << "ID: ";
    for(int j = 0; j < (int)arrayObj[i]["ID"].size(); j++){
      cout << arrayObj[i]["ID"][j].asFloat() << " ";
    }
    cout << endl;
  }
#endif  
}
