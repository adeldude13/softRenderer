#include "obj.hpp"

Model::Model(std::string filename) {
	std::ifstream file(filename);
	std::string line;
	while(getline(file, line)) {
		if(line[0] == 'v' && line[1] == ' ') {
			Vec3 temp;
			int index = 0;
			std::string number = "";
			for(int i=2;i<(int)line.size();i++) {
				if(line[i] == ' ') {
					temp.raw(index, std::stod(number));
					index++;
					number = "";
				} else {
					number += line[i];
				}
			}
			verts.push_back(temp);
		} else if(line[0] == 'f') {
			std::vector<int> temp(3);
			std::string number = "";
			int i=2;
			while(line[i] != '/') {
				number += line[i];
				i++;
			}
			temp[0] = std::stod(number);
			number = "";
			while(line[i] != ' ') i++;
			i++;
			while(line[i] != '/') {
				number += line[i];
				i++;
			}
			temp[1] = std::stod(number);
			number = "";
			while(line[i] != ' ') i++;
			i++;
			while(line[i] != '/') {
				number += line[i];
				i++;
			}
			temp[2] = std::stod(number);
			inds.push_back(temp);
		}
	}
}
